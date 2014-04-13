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
SDName: Boss_Akilzon
SD%Complete: 80
SDComment: Timers; Some details may need adjustments.
SDCategory: Zul'Aman
EndScriptData */

#include "precompiled.h"
#include "zulaman.h"

enum
{
	SAY_EVENT1              = -1568024,
	SAY_EVENT2              = -1568025,
	SAY_AGGRO               = -1568026,
	SAY_SUMMON              = -1568027,
	SAY_SUMMON_ALT          = -1568028,
	SAY_ENRAGE              = -1568029,
	SAY_SLAY1               = -1568030,
	SAY_SLAY2               = -1568031,
	SAY_DEATH               = -1568032,
	EMOTE_STORM             = -1568033,

	SPELL_STATIC_DISRUPTION = 43622,
	SPELL_CALL_LIGHTNING    = 43661,
	SPELL_GUST_OF_WIND      = 43621,
	SPELL_ELECTRICAL_STORM  = 43648,
	SPELL_STORMCLOUD_VISUAL = 45213,
	SPELL_BERSERK           = 45078,

	// spell used by eagles
	SPELL_EAGLE_SWOOP       = 44732,

	// spell used by Tempest mob
	SPELL_CHAIN_LIGHTNING	= 43435,
	SPELl_THUNDERCLAP		= 44033,

	NPC_SOARING_EAGLE       = 24858,
	MAX_EAGLE_COUNT         = 6,
};

struct MANGOS_DLL_DECL boss_akilzonAI : public ScriptedAI
{
	boss_akilzonAI(Creature* pCreature) : ScriptedAI(pCreature)
	{
		m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
		Reset();
	}

	ScriptedInstance* m_pInstance;

	uint32 m_uiStaticDisruptTimer;
	uint32 m_uiCallLightTimer;
	uint32 m_uiGustOfWindTimer;
	uint32 m_uiStormTimer;
	uint32 m_uiSummonEagleTimer;
	uint32 m_uiBerserkTimer;

	void Reset() override
	{
		m_uiStaticDisruptTimer  = urand(7000, 14000);
		m_uiCallLightTimer      = urand(15000, 25000);
		m_uiGustOfWindTimer     = urand(20000, 30000);
		m_uiStormTimer          = 50000;
		m_uiSummonEagleTimer    = 65000;
		m_uiBerserkTimer        = 10 * MINUTE * IN_MILLISECONDS;
	}

	void Aggro(Unit* /*pWho*/) override
	{
		DoScriptText(SAY_AGGRO, m_creature);

		if (m_pInstance)
			m_pInstance->SetData(TYPE_AKILZON, IN_PROGRESS);
	}

	void KilledUnit(Unit* /*pVictim*/) override
	{
		DoScriptText(urand(0, 1) ? SAY_SLAY1 : SAY_SLAY2, m_creature);
	}

	void JustDied(Unit* /*pKiller*/) override
	{
		DoScriptText(SAY_DEATH, m_creature);

		if (!m_pInstance)
			return;

		m_pInstance->SetData(TYPE_AKILZON, DONE);
	}

	void JustReachedHome() override
	{
		if (m_pInstance)
			m_pInstance->SetData(TYPE_AKILZON, FAIL);
	}

	void JustSummoned(Creature* pSummoned) override
	{
		if (pSummoned->GetEntry() == NPC_SOARING_EAGLE)
		{
			pSummoned->SetLevitate(true);
			pSummoned->SetInCombatWithZone();
		}
	}

	void DoSummonEagles()
	{
		for (uint32 i = 0; i < MAX_EAGLE_COUNT; ++i)
		{
			float fX, fY, fZ;
			m_creature->GetRandomPoint(m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ() + 15.0f, 30.0f, fX, fY, fZ);
			m_creature->SummonCreature(NPC_SOARING_EAGLE, fX, fY, fZ, m_creature->GetOrientation(), TEMPSUMMON_DEAD_DESPAWN, 0);
		}
	}

	void UpdateAI(const uint32 uiDiff) override
	{
		if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
			return;

		if (m_uiCallLightTimer < uiDiff)
		{
			if (DoCastSpellIfCan(m_creature->getVictim(), SPELL_CALL_LIGHTNING) == CAST_OK)
				m_uiCallLightTimer = urand(15000, 25000);
		}
		else
			m_uiCallLightTimer -= uiDiff;

		if (m_uiStaticDisruptTimer < uiDiff)
		{
			if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1))
			{
				if (DoCastSpellIfCan(pTarget, SPELL_STATIC_DISRUPTION) == CAST_OK)
					m_uiStaticDisruptTimer = urand(7000, 14000);
			}
		}
		else
			m_uiStaticDisruptTimer -= uiDiff;

		if (m_uiStormTimer < uiDiff)
		{
			if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
			{
				if (DoCastSpellIfCan(pTarget, SPELL_ELECTRICAL_STORM) == CAST_OK)
				{
					DoScriptText(EMOTE_STORM, m_creature);
					m_uiStormTimer = 55000;
				}
			}
		}
		else
			m_uiStormTimer -= uiDiff;

		if (m_uiGustOfWindTimer < uiDiff)
		{
			if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1))
			{
				if (DoCastSpellIfCan(pTarget, SPELL_GUST_OF_WIND) == CAST_OK)
					m_uiGustOfWindTimer = urand(20000, 30000);
			}
		}
		else
			m_uiGustOfWindTimer -= uiDiff;

		if (m_uiSummonEagleTimer < uiDiff)
		{
			DoScriptText(urand(0, 1) ? SAY_SUMMON : SAY_SUMMON_ALT, m_creature);
			DoSummonEagles();
			m_uiSummonEagleTimer = 60000;
		}
		else
			m_uiSummonEagleTimer -= uiDiff;

		if (m_uiBerserkTimer)
		{
			if (m_uiBerserkTimer < uiDiff)
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

CreatureAI* GetAI_boss_akilzon(Creature* pCreature)
{
	return new boss_akilzonAI(pCreature);
}

struct MANGOS_DLL_DECL mob_soaring_eagleAI : public ScriptedAI
{
	mob_soaring_eagleAI(Creature* pCreature) : ScriptedAI(pCreature)
	{
		m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
		Reset();
	}

	ScriptedInstance* m_pInstance;

	uint32 m_uiEagleSwoopTimer;
	uint32 m_uiReturnTimer;
	bool m_bCanMoveToRandom;

	void Reset() override
	{
		m_uiEagleSwoopTimer = 0;
		m_uiReturnTimer     = 800;
		m_bCanMoveToRandom  = false;
	}

	void AttackStart(Unit* pWho) override
	{
		if (!pWho)
			return;

		if (m_creature->Attack(pWho, false))
		{
			m_creature->AddThreat(pWho);
			m_creature->SetInCombatWith(pWho);
			pWho->SetInCombatWith(m_creature);
		}
	}

	void MovementInform(uint32 uiType, uint32 uiPointId) override
	{
		if (uiType != POINT_MOTION_TYPE || !uiPointId)
			return;

		m_uiEagleSwoopTimer = urand(2000, 6000);
	}

	void DoMoveToRandom()
	{
		if (!m_pInstance)
			return;

		if (Creature* pAzkil = m_pInstance->GetSingleCreatureFromStorage(NPC_AKILZON))
		{
			float fX, fY, fZ;
			pAzkil->GetRandomPoint(pAzkil->GetPositionX(), pAzkil->GetPositionY(), pAzkil->GetPositionZ() + 15.0f, 30.0f, fX, fY, fZ);

			m_creature->SetWalk(false);
			m_creature->GetMotionMaster()->MovePoint(1, fX, fY, fZ);
		}
	}

	void UpdateAI(const uint32 uiDiff) override
	{
		if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
			return;

		if (m_uiReturnTimer)
		{
			if (m_uiReturnTimer <= uiDiff)
			{
				DoMoveToRandom();
				m_uiReturnTimer = 0;
			}
			else
				m_uiReturnTimer -= uiDiff;
		}

		if (m_uiEagleSwoopTimer)
		{
			if (m_uiEagleSwoopTimer <= uiDiff)
			{
				if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
				{
					if (DoCastSpellIfCan(pTarget, SPELL_EAGLE_SWOOP) == CAST_OK)
					{
						m_uiEagleSwoopTimer = 0;
						m_uiReturnTimer     = 1000;
					}
				}
			}
			else
				m_uiEagleSwoopTimer -= uiDiff;
		}
	}
};

CreatureAI* GetAI_mob_soaring_eagle(Creature* pCreature)
{
	return new mob_soaring_eagleAI(pCreature);
}

struct AddPosSpawn {
	float m_fX, m_fY, m_fZ;
};

static const AddPosSpawn aPositionSpawn[2] = 
{
	{280.807f, 1379.943f, 49.321f},	// Eagle position
	{193.848f, 1438.121f, 15.108f}, // Warrior position   
};

// This mob handle the gauntlet event
struct MANGOS_DLL_DECL mob_amanashi_tempestAI : public ScriptedAI
{
	mob_amanashi_tempestAI(Creature* pCreature) : ScriptedAI(pCreature)
	{
		m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
		Reset();
	}

	ScriptedInstance* m_pInstance;

	uint32 m_uiSpawnTimer;
	uint32 m_uiThunderClapTimer;
	
	void Reset() override
	{
		m_uiSpawnTimer = 20000;
		m_uiThunderClapTimer = 5000;
	}

	void JustDied(Unit* pKiller) override
	{
		if (m_pInstance)
			m_pInstance->SetData(TYPE_EVENT_GAUNTLET, DONE);
	}

	void JustReachedHome() override
	{
		if (m_pInstance)
			m_pInstance->SetData(TYPE_EVENT_GAUNTLET, FAIL);
	}

	void SummonedMovementInform(Creature* pSummoned, uint32 uiMotionType, uint32 uiPointId) override
	{

	if (uiMotionType != POINT_MOTION_TYPE || !uiPointId || pSummoned->isDead())
		return;

		if (uiPointId == POINT_ID_FAIL_GAUNTLET)
		{
			if(m_pInstance)
				m_pInstance->SetData(TYPE_EVENT_GAUNTLET, FAIL);
		}

		
	}

	// Stock all summon
	void JustSummoned(Creature* pSummoned) override
	{
		switch(pSummoned->GetEntry())
		{
		case NPC_EAGLE:
			{
				pSummoned->SetWalk(false);
				pSummoned->GetMotionMaster()->MovePoint(POINT_ID_FAIL_GAUNTLET, aPositionSpawn[1].m_fX, aPositionSpawn[1].m_fY, aPositionSpawn[1].m_fZ);
				break;
			}
		case NPC_WARRIOR:
			{
				pSummoned->SetWalk(false);
				pSummoned->GetMotionMaster()->MovePoint(0, aPositionSpawn[0].m_fX, aPositionSpawn[0].m_fY, aPositionSpawn[0].m_fZ);
				break;
			}
		default:break;
		}
	}

	// Summon 5 or 6 eagles
	void DoSummonEagles()
	{
		int8 countMaxEagles = urand(5,6);
		for(int8 i = 0; i < countMaxEagles; i++)
		{
			float m_fX, m_fY, m_fZ;
			m_creature->GetRandomPoint(aPositionSpawn[0].m_fX, aPositionSpawn[0].m_fY, aPositionSpawn[0].m_fZ, 10.0f, m_fX, m_fY, m_fZ);
			m_creature->SummonCreature(NPC_EAGLE, m_fX, m_fY, m_fZ, 0.0f, TEMPSUMMON_DEAD_DESPAWN, 0);
		}
	}

	// Summon 2 warriors
	void DoSummonWarriors()
	{
		for(int8 i = 0; i < 2; i++)
		{
			float m_fX, m_fY, m_fZ;
			m_creature->GetRandomPoint(aPositionSpawn[1].m_fX, aPositionSpawn[1].m_fY, aPositionSpawn[1].m_fZ, 10.0f, m_fX, m_fY, m_fZ);
			m_creature->SummonCreature(NPC_WARRIOR, m_fX, m_fY, m_fZ, 0.0f, TEMPSUMMON_DEAD_DESPAWN, 0);
		}
	}

	void UpdateAI(const uint32 uiDiff) override
	{
		if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
		{
			if(m_pInstance)
			{
				if(m_pInstance->GetData(TYPE_EVENT_GAUNTLET) == IN_PROGRESS)
				{
					if(m_uiSpawnTimer < uiDiff)
					{
						DoSummonEagles();
						DoSummonWarriors();
						m_uiSpawnTimer = urand(15000, 25000);
					}
					else
						m_uiSpawnTimer -= uiDiff;
				}
			}
			return;
		}

		if (m_uiThunderClapTimer < uiDiff)
		{
			if(DoCastSpellIfCan(m_creature->getVictim(), SPELl_THUNDERCLAP) == CAST_OK)
				m_uiThunderClapTimer = urand(15000 , 25000);
		}
		else
			m_uiThunderClapTimer -= uiDiff;

		DoMeleeAttackIfReady();
	}
};

CreatureAI* GetAI_mob_amanashi_tempest(Creature* pCreature)
{
	return new mob_amanashi_tempestAI(pCreature);
}

// This mob launch the event and run away
struct MANGOS_DLL_DECL mob_amanashi_lookoutAI : public ScriptedAI
{
	mob_amanashi_lookoutAI(Creature* pCreature) : ScriptedAI(pCreature)
	{
		m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
		Reset();
	}

	ScriptedInstance* m_pInstance;

	void Reset() override {}
	void Aggro(Unit* /*pWho*/) override
	{
		if (m_pInstance)
			m_pInstance->SetData(TYPE_EVENT_GAUNTLET, IN_PROGRESS);
		m_creature->SetWalk(false);
		m_creature->GetMotionMaster()->MovePoint(POINT_ID_LOOKOUT, aPositionSpawn[0].m_fX, aPositionSpawn[0].m_fY, aPositionSpawn[0].m_fZ);
	}

	void MovementInform(uint32 uiType, uint32 uiPointId) override
	{
		if (uiType != POINT_MOTION_TYPE || !uiPointId)
			return;

		if(uiPointId == POINT_ID_LOOKOUT)
			m_creature->ForcedDespawn();		
	}

	// Do-Nothing-Just-Run
	void AttackStart(Unit* /*pWho*/) override { }
	void UpdateAI(const uint32 /*uiDiff*/) override { }	
};

CreatureAI* GetAI_mob_amanashi_lookout(Creature* pCreature)
{
	return new mob_amanashi_lookoutAI(pCreature);
}


void AddSC_boss_akilzon()
{
	Script* pNewScript;

	pNewScript = new Script;
	pNewScript->Name = "boss_akilzon";
	pNewScript->GetAI = &GetAI_boss_akilzon;
	pNewScript->RegisterSelf();

	pNewScript = new Script;
	pNewScript->Name = "mob_soaring_eagle";
	pNewScript->GetAI = &GetAI_mob_soaring_eagle;
	pNewScript->RegisterSelf();

	pNewScript = new Script;
	pNewScript->Name = "mob_amanashi_tempest";
	pNewScript->GetAI = &GetAI_mob_amanashi_tempest;
	pNewScript->RegisterSelf();

	pNewScript = new Script;
	pNewScript->Name = "mob_amanashi_lookout";
	pNewScript->GetAI = &GetAI_mob_amanashi_lookout;
	pNewScript->RegisterSelf();
}
