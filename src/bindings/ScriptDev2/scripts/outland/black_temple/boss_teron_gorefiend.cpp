/* Copyright (C) 2006 - 2013 ScriptDev2 <http://www.scriptdev2.com/>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/* ScriptData
SDName: Boss_Teron_Gorefiend
SD%Complete: 60
SDComment: Requires Mind Control support for Ghosts.
SDCategory: Black Temple
EndScriptData */

#include "precompiled.h"
#include "black_temple.h"

enum
{
	// Speech'n'sound
	SAY_INTRO                = -1564037,
	SAY_AGGRO                = -1564038,
	SAY_SLAY1                = -1564039,
	SAY_SLAY2                = -1564040,
	SAY_SPELL1               = -1564041,
	SAY_SPELL2               = -1564042,
	SAY_SPECIAL1             = -1564043,
	SAY_SPECIAL2             = -1564044,
	SAY_ENRAGE               = -1564045,
	SAY_DEATH                = -1564046,

	// Spells - boss spells
	SPELL_INCINERATE            = 40239,
	SPELL_CRUSHING_SHADOWS      = 40243,
	SPELL_SHADOW_OF_DEATH       = 40251,
	SPELL_BERSERK               = 45078,
	SPELL_SUMMON_DOOM_BLOSSOM   = 40188,
	/*SPELL_SUMMON_SKELETON_1     = 40270,
	SPELL_SUMMON_SKELETON_2     = 41948,
	SPELL_SUMMON_SKELETON_3     = 41949,
	SPELL_SUMMON_SKELETON_4     = 41950,
	SPELL_SUMMON_SPIRIT         = 40266,*/
	SPELL_DESTROY_SPIRIT        = 41626,                    // purpose unk
	SPELL_DESTROY_ALL_SPIRITS   = 44659,                    // purpose unk

	// Spells - other
	// SPELL_ATROPHY             = 40327,                   // Shadowy Constructs use this when they get within melee range of a player
	SPELL_SHADOWY_CONSTRUCT     = 40326,
	SPELL_SHADOW_BOLT			= 40185,
	SPELL_PHYSICAL_IMMUNITY		= 34311,

	NPC_DOOM_BLOSSOM			= 23123,
	NPC_DOOM_BLOSSOM_TARGET		= 23124,
	NPC_SHADOWY_CONSTRUCT       = 23111,                   // scripted in eventAI
	//NPC_VENGEFUL_SPIRIT			= 23109,                   // npc controlled by the dead player
};

struct MANGOS_DLL_DECL boss_teron_gorefiendAI : public ScriptedAI
{
	boss_teron_gorefiendAI(Creature* pCreature) : ScriptedAI(pCreature)
	{
		m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
		m_bIntroDone = false;
		Reset();
	}

	ScriptedInstance* m_pInstance;

	uint32 m_uiIncinerateTimer;
	uint32 m_uiSummonDoomBlossomTimer;
	uint32 m_uiBerserkTimer;
	uint32 m_uiCrushingShadowsTimer;
	uint32 m_uiShadowOfDeathTimer;

	ObjectGuid m_doomblossomGuid;

	bool m_bIntroDone;

	void Reset() override
	{
		m_uiIncinerateTimer         = urand(20000, 30000); //urand(20000, 30000);
		m_uiSummonDoomBlossomTimer  = urand(5000, 10000);
		m_uiShadowOfDeathTimer      = 10000;
		m_uiCrushingShadowsTimer    = 22000;
		m_uiBerserkTimer            = 10 * MINUTE * IN_MILLISECONDS;
	}

	void JustReachedHome() override
	{
		if (m_pInstance)
			m_pInstance->SetData(TYPE_GOREFIEND, FAIL);
	}

	void Aggro(Unit* /*pWho*/) override
	{
		DoScriptText(SAY_AGGRO, m_creature);

		if (m_pInstance)
			m_pInstance->SetData(TYPE_GOREFIEND, IN_PROGRESS);
	}

	void MoveInLineOfSight(Unit* pWho) override
	{
		if (!m_bIntroDone && pWho->GetTypeId() == TYPEID_PLAYER && m_creature->IsWithinDistInMap(pWho, 60.0f))
		{
			DoScriptText(SAY_INTRO, m_creature);
			m_bIntroDone = true;
		}

		ScriptedAI::MoveInLineOfSight(pWho);
	}

	void KilledUnit(Unit* pVictim) override
	{
		if (pVictim->GetTypeId() != TYPEID_PLAYER)
			return;

		DoScriptText(urand(0, 1) ? SAY_SLAY1 : SAY_SLAY2, m_creature);
	}

	void JustDied(Unit* /*pKiller*/) override
	{
		if (m_pInstance)
			m_pInstance->SetData(TYPE_GOREFIEND, DONE);

		DoScriptText(SAY_DEATH, m_creature);

		cleanShadowOfDeath();
	}

	// Remove all shadow of death aura when Teron die
	void cleanShadowOfDeath()
	{
		Map::PlayerList const& lPlayers = m_creature->GetMap()->GetPlayers();
		if (!lPlayers.isEmpty())
		{
			for (Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
			{
				if(Player* pPlayer = itr->getSource())
					if(pPlayer->HasAura(SPELL_SHADOW_OF_DEATH))
						pPlayer->RemoveAurasDueToSpell(SPELL_SHADOW_OF_DEATH);
			}
		}
	}

	void JustSummoned(Creature* pSummoned) override
	{
		switch(pSummoned->GetEntry())
		{
		case NPC_SHADOWY_CONSTRUCT:
			pSummoned->CastSpell(pSummoned, SPELL_SHADOWY_CONSTRUCT, true);
			pSummoned->CastSpell(pSummoned, SPELL_PHYSICAL_IMMUNITY, true);
			pSummoned->SetInCombatWithZone();
			break;
		case NPC_DOOM_BLOSSOM:
			pSummoned->setFaction(m_creature->getFaction());
			pSummoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
			m_creature->SummonCreature(NPC_DOOM_BLOSSOM_TARGET, pSummoned->GetPositionX(), pSummoned->GetPositionY(), pSummoned->GetPositionZ() + 10.0f, 0.0f, TEMPSUMMON_DEAD_DESPAWN, 120000);
			break;
		case NPC_DOOM_BLOSSOM_TARGET:
			pSummoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);	
			break;
		}
	}

	void UpdateAI(const uint32 uiDiff) override
	{
		if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
			return;

		if (m_uiSummonDoomBlossomTimer < uiDiff)
		{
			if (DoCastSpellIfCan(m_creature, SPELL_SUMMON_DOOM_BLOSSOM) == CAST_OK)
			{
				if (urand(0, 1))
					DoScriptText(urand(0, 1) ? SAY_SPELL1 : SAY_SPELL2, m_creature);

				m_uiSummonDoomBlossomTimer = 35000;
			}
		}
		else
			m_uiSummonDoomBlossomTimer -= uiDiff;

		if (m_uiIncinerateTimer < uiDiff)
		{
			Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1, SPELL_INCINERATE , SELECT_FLAG_PLAYER);

			if (DoCastSpellIfCan(pTarget ? pTarget : m_creature->getVictim(), SPELL_INCINERATE) == CAST_OK)
				m_uiIncinerateTimer = urand(20000, 50000);
		}
		else
			m_uiIncinerateTimer -= uiDiff;

		if (m_uiCrushingShadowsTimer < uiDiff)
		{
			if (DoCastSpellIfCan(m_creature, SPELL_CRUSHING_SHADOWS) == CAST_OK)
			{
				if (urand(0, 1))
					DoScriptText(urand(0, 1) ? SAY_SPECIAL1 : SAY_SPECIAL2, m_creature);

				m_uiCrushingShadowsTimer = urand(10000, 26000);
			}
		}
		else
			m_uiCrushingShadowsTimer -= uiDiff;

		if (m_uiShadowOfDeathTimer < uiDiff)
		{
			if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1, SPELL_SHADOW_OF_DEATH, SELECT_FLAG_PLAYER))
			{
				if (DoCastSpellIfCan(pTarget, SPELL_SHADOW_OF_DEATH) == CAST_OK)
				{
					DoScriptText(urand(0, 1) ? SAY_SPECIAL1 : SAY_SPECIAL2, m_creature);
					m_uiShadowOfDeathTimer = 30000;
				}
			}
		}
		else
			m_uiShadowOfDeathTimer -= uiDiff;

		if (m_uiBerserkTimer)
		{
			if (m_uiBerserkTimer <= uiDiff)
			{
				if (DoCastSpellIfCan(m_creature, SPELL_BERSERK) == CAST_OK)
				{
					DoScriptText(SAY_ENRAGE, m_creature);
					m_uiBerserkTimer = 0;
				}
			}
			else
				m_uiBerserkTimer -= uiDiff;
		}

		DoMeleeAttackIfReady();
	}
};

struct MANGOS_DLL_DECL npc_doomblossomAI : public ScriptedAI
{
	npc_doomblossomAI(Creature* pCreature) : ScriptedAI(pCreature) { 
		Reset(); 
	}

	uint32 m_uiShadowBoltTimer;
	uint32 m_uiLoadTargetTimer;

	void Reset() override 
	{
		m_uiShadowBoltTimer = 8000;
		m_uiLoadTargetTimer = 500;		
	}

	void AttackStart(Unit* pWho) override{}

	void EnterEvadeMode() override{}

	void UpdateAI(const uint32 uiDiff) override 
	{
		if(m_uiLoadTargetTimer)
		{
			if(m_uiLoadTargetTimer <= uiDiff)
			{
				if (Creature* pTemp = GetClosestCreatureWithEntry(m_creature, NPC_DOOM_BLOSSOM_TARGET, 15.0f))
				{
					m_creature->GetMotionMaster()->MoveFollow(pTemp, 0.0f, 0.0f);
					m_uiLoadTargetTimer = 0;
				}
			}
			else 
				m_uiLoadTargetTimer -= uiDiff;
		}

		if(m_uiShadowBoltTimer < uiDiff)
		{
			if(Creature* pTeron = GetClosestCreatureWithEntry(m_creature, NPC_TERON_GOREFIEND, 40.0f))
			{
				if(Unit* pTarget = pTeron->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, SPELL_SHADOW_BOLT, SELECT_FLAG_PLAYER))
				{
					if(DoCastSpellIfCan(pTarget, SPELL_SHADOW_BOLT) == CAST_OK)
					{
						m_uiShadowBoltTimer = urand(2000, 3000);
					}
				}
			}
		}
		else
			m_uiShadowBoltTimer -= uiDiff;
	}
};

CreatureAI* GetAI_boss_teron_gorefiend(Creature* pCreature)
{
	return new boss_teron_gorefiendAI(pCreature);
}

CreatureAI* GetAI_npc_doomblossom(Creature* pCreature)
{
	return new npc_doomblossomAI(pCreature);
}

void AddSC_boss_teron_gorefiend()
{
	Script* pNewScript;

	pNewScript = new Script;
	pNewScript->Name = "boss_teron_gorefiend";
	pNewScript->GetAI = &GetAI_boss_teron_gorefiend;
	pNewScript->RegisterSelf();

	pNewScript = new Script;
	pNewScript->Name = "npc_doomblossom";
	pNewScript->GetAI = &GetAI_npc_doomblossom;
	pNewScript->RegisterSelf();
}
