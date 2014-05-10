/* ScriptData
SDName: Boss_Lady_Vashj
SD%Complete: 60
SDComment: Code cleanup needed. This script needs further adjustments.
SDCategory: Coilfang Resevoir, Serpent Shrine Cavern
EndScriptData */

#include "precompiled.h"
#include "serpent_shrine.h"
#include "Item.h"
#include "Spell.h"

enum
{
	SAY_INTRO                   = -1548042,
	SAY_AGGRO1                  = -1548043,
	SAY_AGGRO2                  = -1548044,
	SAY_AGGRO3                  = -1548045,
	SAY_AGGRO4                  = -1548046,
	SAY_PHASE1                  = -1548047,
	SAY_PHASE2                  = -1548048,
	SAY_PHASE3                  = -1548049,
	SAY_BOWSHOT1                = -1548050,
	SAY_BOWSHOT2                = -1548051,
	SAY_SLAY1                   = -1548052,
	SAY_SLAY2                   = -1548053,
	SAY_SLAY3                   = -1548054,
	SAY_DEATH                   = -1548055,

	POINT_MOVE_CENTER           = 0,

	PHASE_1                     = 1,
	PHASE_2                     = 2,
	PHASE_3                     = 3,

	MAX_SHIELD_GEN              = 4,

	SPELL_MULTI_SHOT            = 38310,
	SPELL_SHOCK_BLAST           = 38509,
	SPELL_ENTANGLE              = 38316,
	SPELL_STATIC_CHARGE_TRIGGER = 38280,
	SPELL_FORKED_LIGHTNING      = 38145,
	SPELL_SHOOT                 = 38295,
	SPELL_PERSUASION			= 38511,					// @Lorh : Used before 2.1 (Pre-nerf spell Mind Control)

	SPELL_TOXIC_BOLT_AURA		= 38571,
	SPELL_TOXIC_SPORE			= 38575,
	SPELL_MAGIC_BARRIER         = 38112,
	SPELL_SURGE                 = 38044,

	SPELL_ROOT                  = 38132,

	//tainted elemental
	SPELL_POISON_BOLT           = 38253,
	SPELL_SUMMON_TAINTED        = 38139,

	NPC_TAINTED_ELEMENTAL		= 22009,
	NPC_ENCHANTED_ELEMENTAL		= 21958,
	NPC_TOXIC_BOLT				= 22207,

	NPC_COILFANG_STRIDER        = 22056,
	NPC_COILFANG_ELITE          = 22055,
	NPC_TOXIC_SPOREBAT          = 22140,

	//NPC_SHIELD_GENERATOR        = 19870
};

const float afMiddlePos[3]   = {30.134f, -923.65f, 42.9f};

const float afSporebatPos[4] = {30.977156f, -925.297761f, 60.176567f, 5.223932f};

const float afElementPos[8][4] =
{
	{8.3f  , -835.3f , 21.9f, 5.0f},
	{53.4f , -835.3f , 21.9f, 4.5f},
	{96.0f , -861.9f , 21.8f, 4.0f},
	{96.0f , -986.4f , 21.4f, 2.5f},
	{54.4f , -1010.6f, 22.0f, 1.8f},
	{9.8f  , -1012.0f, 21.7f, 1.4f},
	{-35.0f, -987.6f , 21.5f, 0.8f},
	{-58.9f, -901.6f , 21.5f, 6.0f}
};

const float afCoilfangElitePos[3][4] =
{
	{28.84f    , -923.28f    , 42.9f     , 6.0f     },
	{31.183281f, -953.502625f, 41.523602f, 1.640957f},
	{58.895180f, -923.124268f, 41.545307f, 3.152848f}
};

const float afCoilfangStriderPos[3][4] =
{
	{66.427f, -948.778f, 41.262245f, 2.584f},
	{7.513f , -959.538f, 41.300422f, 1.0346f},
	{-12.843f, -907.798f, 41.239620f, 6.087f}
};

const float afShieldGeneratorChannelPos[4][4] =
{
	{49.626f, -902.181f, 35.54f, 3.956f},
	{10.988f, -901.616f, 35.54f, 5.437f},
	{10.385f, -944.036f, 35.54f, 0.779f},
	{49.312f, -943.398f, 35.54f, 2.401f}
};

//Lady Vashj AI
struct MANGOS_DLL_DECL boss_lady_vashjAI : public ScriptedAI
{
	boss_lady_vashjAI(Creature* pCreature) : ScriptedAI(pCreature)
	{
		m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
		Reset();
	}

	ScriptedInstance *m_pInstance;                          // the instance

	ObjectGuid m_auiShieldGeneratorChannel[MAX_SHIELD_GEN];

	// timers
	uint32 m_uiShockBlast_Timer;
	uint32 m_uiEntangle_Timer;
	uint32 m_uiStaticCharge_Timer;
	uint32 m_uiForkedLightning_Timer;
	uint32 m_uiCheck_Timer;
	uint32 m_uiEnchantedElemental_Timer;
	uint32 m_uiTaintedElemental_Timer;
	uint32 m_uiCoilfangElite_Timer;
	uint32 m_uiCoilfangStrider_Timer;
	uint32 m_uiSummonSporebat_Timer;
	uint32 m_uiSummonSporebat_StaticTimer;
	uint32 m_uiAddSporebat;							// @Lorh : Timer to increase the number of sporebat summoned
	uint32 m_uiPersuasionTimer;						// @Lorh : Timer For Mind Control
	uint8  m_uiEnchantedElemental_Pos;
	uint8  m_uiPhase;
	uint8  m_uiShieldGeneratorDown;
	uint8  m_uiCountSporebat;						// @Lorh : Control How Many sporebat are summoned

	bool m_bEntangle;
	bool m_bShielded;

	void Reset()
	{
		SetCombatMovement(true);

		m_uiShockBlast_Timer           = urand(1000, 60000);
		m_uiEntangle_Timer             = 30000;
		m_uiStaticCharge_Timer         = urand(10000, 25000);
		m_uiCheck_Timer                = 1000;

		m_uiForkedLightning_Timer      = urand(43000, 49000);
		m_uiEnchantedElemental_Timer   = 10000;
		m_uiTaintedElemental_Timer     = 50000;
		m_uiCoilfangElite_Timer        = 45000;
		m_uiCoilfangStrider_Timer      = 60000;

		m_uiSummonSporebat_Timer       = 10000;
		m_uiSummonSporebat_StaticTimer = 24000;		// @Lorh : With this timer, soft enrage (4mn) arrive when m_uiSummonSporebat_StaticTimer = 10000;
		m_uiPersuasionTimer			   = 30000;		// @Lorh : Here Mind Control timer
		m_uiAddSporebat				   = 60000;		// @Lorh : Control timer used for increasing m_uiCountSporebat
		m_uiCountSporebat			   = 1;			// @Lorh : Start with 2 sporebat, it will increase with time
		m_uiEnchantedElemental_Pos     = 0;
		m_uiShieldGeneratorDown        = 0;
		m_uiPhase                      = PHASE_1;

		m_bShielded = false;
		m_bEntangle = false;

		RemoveAllShieldGenerators();

		if (m_pInstance)
			m_pInstance->SetData(TYPE_LADYVASHJ_EVENT, NOT_STARTED);
	}

	void RemoveAllShieldGenerators()
	{
		for(uint8 i = 0; i < MAX_SHIELD_GEN; ++i)
		{
			if (Creature* pTemp = m_creature->GetMap()->GetCreature(m_auiShieldGeneratorChannel[i]))
			{
				if (pTemp->isAlive())
					pTemp->SetDeathState(JUST_DIED);

				m_auiShieldGeneratorChannel[i].Clear();
			}
		}
	}

	void RefreshShieldGenerators()
	{
		for(uint8 i = 0; i < MAX_SHIELD_GEN; ++i)
		{
			if (Creature* pTemp = m_creature->GetMap()->GetCreature(m_auiShieldGeneratorChannel[i]))
			{
				if (pTemp->isAlive())
				{
					pTemp->CastStop();
					pTemp->CastSpell(m_creature,SPELL_MAGIC_BARRIER,true);
				}
			}
		}
	}

	void Aggro(Unit* pWho)
	{
		switch(urand(0, 3))
		{
		case 0: DoScriptText(SAY_AGGRO1, m_creature); break;
		case 1: DoScriptText(SAY_AGGRO2, m_creature); break;
		case 2: DoScriptText(SAY_AGGRO3, m_creature); break;
		case 3: DoScriptText(SAY_AGGRO4, m_creature); break;
		}

		if (m_pInstance)
		{
			m_pInstance->SetData(TYPE_LADYVASHJ_EVENT, IN_PROGRESS);

			// clean all tainted cores from player inventory
			Map::PlayerList const& lPlayers = m_pInstance->instance->GetPlayers();
			if (!lPlayers.isEmpty())
			{
				for(Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
				{
					if (Player* pPlayer = itr->getSource())
						pPlayer->DestroyItemCount(31088, 4, true);
				}
			}
		}

	}

	void MovementInform(uint32 uiType, uint32 uiPointId)
	{
		if (uiType != POINT_MOTION_TYPE)
			return;

		if (uiPointId == POINT_MOVE_CENTER && !m_bShielded)
		{
			m_creature->RemoveAllAuras();

			m_bShielded = true;
			for(uint8 i = 0; i < MAX_SHIELD_GEN; ++i)
			{
				if (Creature* pCreature = m_creature->SummonCreature(NPC_SHIELD_GENERATOR, afShieldGeneratorChannelPos[i][0],  afShieldGeneratorChannelPos[i][1],  afShieldGeneratorChannelPos[i][2],  afShieldGeneratorChannelPos[i][3], TEMPSUMMON_CORPSE_DESPAWN, 0))
					m_auiShieldGeneratorChannel[i] = pCreature->GetObjectGuid();
			}
		}
	}

	void JustSummoned(Creature* pSummoned)
	{
		//pSummoned->addUnitState(UNIT_STAT_IGNORE_PATHFINDING);
		uint32 uiEntry = pSummoned->GetEntry();

		//@Lorh : better with a switch case
		switch(uiEntry)
		{
		case NPC_COILFANG_STRIDER:
		case NPC_COILFANG_ELITE:
			pSummoned->SetInCombatWithZone();
			if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
				pSummoned->AI()->AttackStart(pTarget);
			break;
		case NPC_TOXIC_SPOREBAT:
			pSummoned->addUnitState(MOVEFLAG_LEVITATING);	////@Lorh : Flyyyyyy little wing... sporebat !
			pSummoned->SetInCombatWithZone();
			pSummoned->setFaction(m_creature->getFaction());
			break;
		case NPC_SHIELD_GENERATOR:
			//we should really expect database to have this set already
			if (!pSummoned->HasFlag(UNIT_FIELD_FLAGS, (UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE)))
			{
				pSummoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
				pSummoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
			}

			pSummoned->CastSpell(m_creature,SPELL_MAGIC_BARRIER,true);
			break;
		}
	}

	//called when any summoned (by m_creature) despawns
	void SummonedCreatureDespawn(Creature* pDespawned)
	{
		if (pDespawned->GetEntry() == NPC_TAINTED_ELEMENTAL)
		{
			if (m_uiTaintedElemental_Timer > 50000)
				m_uiTaintedElemental_Timer = 50000;
		}
	}

	void KilledUnit(Unit* pVictim)
	{
		switch(urand(0, 3))
		{
		case 0: DoScriptText(SAY_SLAY1, m_creature); break;
		case 1: DoScriptText(SAY_SLAY2, m_creature); break;
		case 2: DoScriptText(SAY_SLAY3, m_creature); break;
		case 3: break;
		}
	}

	void JustDied(Unit* pVictim)
	{
		DoScriptText(SAY_DEATH, m_creature);

		if (m_pInstance)
			m_pInstance->SetData(TYPE_LADYVASHJ_EVENT, DONE);
	}

	void CastShootOrMultishot(Unit* pTarget)
	{
		//Shoot: Used in m_uiPhases 1 and 3 after Entangle or while having nobody in melee range. A shot that hits her target for 4097-5543 Physical damage.
		//Multishot: Used in m_uiPhases 1 and 3 after Entangle or while having nobody in melee range. A shot that hits 1 person and 4 people around him for 6475-7525 physical damage.
		DoCastSpellIfCan(pTarget, urand(0,1) ? SPELL_SHOOT : SPELL_MULTI_SHOT);

		if (urand(0, 2))
			DoScriptText(urand(0,1) ? SAY_BOWSHOT1 : SAY_BOWSHOT2, m_creature);
	}

	void UpdateAI(const uint32 uiDiff)
	{
		//Return since we have no target
		if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
			return;

		if (m_uiPhase == PHASE_1 || m_uiPhase == PHASE_3)
		{
			//m_uiShockBlast_Timer
			if (m_uiShockBlast_Timer < uiDiff)
			{
				//Randomly used in m_uiPhases 1 and 3 on Vashj's target, it's a Shock spell doing 8325-9675 nature damage and stunning the target for 5 seconds, during which she will not attack her target but switch to the next person on the aggro list.
				DoCastSpellIfCan(m_creature->getVictim(), SPELL_SHOCK_BLAST);
				m_uiShockBlast_Timer = urand(1000, 15000);  //random cooldown
			}else 
				m_uiShockBlast_Timer -= uiDiff;

			//m_uiStaticCharge_Timer
			if (m_uiStaticCharge_Timer < uiDiff)
			{
				//Used on random people (only 1 person at any given time) in m_uiPhases 1 and 3, it's a debuff doing 2775 to 3225 Nature damage to the target and everybody in about 5 yards around it, every 1 seconds for 30 seconds. It can be removed by Cloak of Shadows, Iceblock, Divine Shield, etc, but not by Cleanse or Dispel Magic.
				Unit *pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);

				//cast Static Charge every 2 seconds for 20 seconds
				if (pTarget && !pTarget->HasAura(SPELL_STATIC_CHARGE_TRIGGER))
					DoCastSpellIfCan(pTarget, SPELL_STATIC_CHARGE_TRIGGER);

				m_uiStaticCharge_Timer = urand(10000, 30000);
			}else 
				m_uiStaticCharge_Timer -= uiDiff;

			//m_uiEntangle_Timer
			if (m_uiEntangle_Timer < uiDiff)
			{
				if (!m_bEntangle)
				{
					//Used in m_uiPhases 1 and 3, it casts Entangling Roots on everybody in a 15 yard radius of Vashj, immobilzing them for 10 seconds and dealing 500 damage every 2 seconds. It's not a magic effect so it cannot be dispelled, but is removed by various buffs such as Cloak of Shadows or Blessing of Freedom.
					DoCastSpellIfCan(m_creature->getVictim(), SPELL_ENTANGLE);
					m_bEntangle = true;
					m_uiEntangle_Timer = 10000;
				}
				else
				{
					CastShootOrMultishot(m_creature->getVictim());
					m_bEntangle = false;
					m_uiEntangle_Timer = urand(20000, 25000);
				}
			}else 
				m_uiEntangle_Timer -= uiDiff;

			//m_uiPhase 1
			if (m_uiPhase == PHASE_1)
			{
				//m_uiPhase 2 begins when Vashj hits 70%. She will run to the middle of her platform and surround herself in a shield making her invulerable.
				if (m_creature->GetHealthPercent() <= 70.0f)
				{
					DoScriptText(SAY_PHASE2, m_creature);

					if (m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() == CHASE_MOTION_TYPE)
					{
						//set false, so MoveChase is not triggered in AttackStart
						SetCombatMovement(false);

						m_creature->GetMotionMaster()->MovementExpired();
						m_creature->GetMotionMaster()->MovePoint(POINT_MOVE_CENTER, afMiddlePos[0], afMiddlePos[1], afMiddlePos[2]);
					}

					m_uiPhase = PHASE_2;
					return;
				}
			}
			//m_uiPhase PHASE_3
			else
			{
				// @Lorh : Mind Control (effect on 2 random target)
				if(m_uiPersuasionTimer <= uiDiff)
				{
					if(DoCastSpellIfCan(m_creature, SPELL_PERSUASION) == CAST_OK)
						m_uiPersuasionTimer = urand(30000, 40000);
				}else
					m_uiPersuasionTimer -= uiDiff;

				//@Lorh : Custom increase sporebat
				if(m_uiAddSporebat < uiDiff)
				{
					if(m_uiCountSporebat < 4)		//Stop at 4 sporebat summoned. After 4mn , m_uiSummonSporebat_Timer manage soft enrage
						m_uiCountSporebat++;

					//Switch case, more easy to adapt timer if needed
					switch(m_uiCountSporebat)
					{
					case 2:									// 2 sporebat at 1mn
						m_uiAddSporebat = 130000;			
						break;
					case 3:									// 3 sporebat at 3mn10
						m_uiAddSporebat = 50000;			
						break;
					default:								// 4 sporebat at 4mn, go enrage 
						m_uiAddSporebat = 80000;
						break;
					}
				}else
					m_uiAddSporebat -= uiDiff;

				// Summon Sporebat timer
				if (m_uiSummonSporebat_Timer < uiDiff)
				{
					for(uint8 summonSporebat = 0; summonSporebat < m_uiCountSporebat; summonSporebat++)						
						m_creature->SummonCreature(NPC_TOXIC_SPOREBAT,afSporebatPos[0], afSporebatPos[1], afSporebatPos[2], frand(-6.0f, 6.0f),TEMPSUMMON_DEAD_DESPAWN, 5000);

					if(m_uiSummonSporebat_StaticTimer <= 4000)
						m_uiSummonSporebat_StaticTimer = 4000;		//This case happened after 4mn, soft enrage start
					else 
						m_uiSummonSporebat_StaticTimer -= 1000;

					m_uiSummonSporebat_Timer = m_uiSummonSporebat_StaticTimer;
				}
				else
					m_uiSummonSporebat_Timer -= uiDiff;
			}

			//Melee attack
			DoMeleeAttackIfReady();

			//m_uiCheck_Timer - used to check if somebody is in melee range
			if (m_uiCheck_Timer < uiDiff)
			{
				//if nobody is in melee range
				if (!m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, uint32(0), SELECT_FLAG_IN_MELEE_RANGE))
					CastShootOrMultishot(m_creature->getVictim());

				m_uiCheck_Timer = 1500;
			}else 
				m_uiCheck_Timer -= uiDiff;
		}
		//m_uiPhase PHASE_2
		else
		{
			//m_uiForkedLightning_Timer
			if (m_uiForkedLightning_Timer < uiDiff)
			{
				//Used constantly in m_uiPhase 2, it shoots out completely randomly targeted bolts of lightning which hit everybody in a roughtly 60 degree cone in front of Vashj for 2313-2687 nature damage.
				Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);

				if (!pTarget)
					pTarget = m_creature->getVictim();

				DoCastSpellIfCan(pTarget, SPELL_FORKED_LIGHTNING);

				m_uiForkedLightning_Timer = urand(2000,8000);
			}else 
				m_uiForkedLightning_Timer -= uiDiff;

			//NPC_ENCHANTED_ELEMENTAL
			if (m_uiEnchantedElemental_Timer < uiDiff)
			{
				if (Creature* pElemental = m_creature->SummonCreature(NPC_ENCHANTED_ELEMENTAL, afElementPos[m_uiEnchantedElemental_Pos][0], afElementPos[m_uiEnchantedElemental_Pos][1], afElementPos[m_uiEnchantedElemental_Pos][2], afElementPos[m_uiEnchantedElemental_Pos][3], TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 60000))
					pElemental->GetMotionMaster()->MoveFollow(m_creature, 0.0f, 0.0f);

				if (m_uiEnchantedElemental_Pos == 7)
					m_uiEnchantedElemental_Pos = 0;
				else
					++m_uiEnchantedElemental_Pos;

				switch(m_uiShieldGeneratorDown)
				{
				case 1: m_uiEnchantedElemental_Timer = urand(6000, 9000); break;
				case 2: m_uiEnchantedElemental_Timer = urand(6000, 8000); break;
				case 3: m_uiEnchantedElemental_Timer = urand(6000, 7000); break;
				case 4: m_uiEnchantedElemental_Timer = urand(6000, 6500); break;
				default: m_uiEnchantedElemental_Timer = urand(6000, 10000); break;
				}

			}else 
				m_uiEnchantedElemental_Timer -= uiDiff;

			//NPC_TAINTED_ELEMENTAL
			if (m_uiTaintedElemental_Timer < uiDiff)
			{
				uint32 uiPos = urand(0,7);

				m_creature->SummonCreature(NPC_TAINTED_ELEMENTAL,afElementPos[uiPos][0], afElementPos[uiPos][1], afElementPos[uiPos][2], afElementPos[uiPos][3],TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 15000);

				m_uiTaintedElemental_Timer = 120000;
			}else 
				m_uiTaintedElemental_Timer -= uiDiff;

			//NPC_COILFANG_ELITE
			if (m_uiCoilfangElite_Timer < uiDiff)
			{
				uint32 uiPos = urand(0,2);

				m_creature->SummonCreature(NPC_COILFANG_ELITE,
					afCoilfangElitePos[uiPos][0], afCoilfangElitePos[uiPos][1], afCoilfangElitePos[uiPos][2], afCoilfangElitePos[uiPos][3],TEMPSUMMON_TIMED_OOC_OR_DEAD_DESPAWN, 15000); // @Lorh : I change the flag to avoid that he despawn after 45sec

				//wowwiki says 50 seconds, bosskillers says 45
				m_uiCoilfangElite_Timer = urand(45000, 50000);
			}else 
				m_uiCoilfangElite_Timer -= uiDiff;

			//NPC_COILFANG_STRIDER
			if (m_uiCoilfangStrider_Timer < uiDiff)
			{
				uint32 uiPos = urand(0,2);

				m_creature->SummonCreature(NPC_COILFANG_STRIDER,
					afCoilfangStriderPos[uiPos][0], afCoilfangStriderPos[uiPos][1], afCoilfangStriderPos[uiPos][2], afCoilfangStriderPos[uiPos][3],
					TEMPSUMMON_TIMED_OOC_OR_CORPSE_DESPAWN, 5000); //@Lorh : I changed the flag, to avoid that aoe fear take effect after death

				//wowwiki says 60 seconds, bosskillers says 60-70
				m_uiCoilfangStrider_Timer = urand(60000, 70000);
			}else 
				m_uiCoilfangStrider_Timer -= uiDiff;

			//m_uiCheck_Timer
			if (m_uiCheck_Timer < uiDiff)
			{
				//Start m_uiPhase 3
				if (m_pInstance && m_pInstance->GetData(TYPE_VASHJ_PHASE3_CHECK) == DONE)
				{
					DoScriptText(SAY_PHASE3, m_creature);

					SetCombatMovement(true);
					//@Lorh : Reset Aggro 
					DoResetThreat();

					if (m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() != CHASE_MOTION_TYPE)
						m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim());

					m_uiPhase = PHASE_3;
				}
				m_uiCheck_Timer = 1000;
			}
			else m_uiCheck_Timer -= uiDiff;
		}
	}
};

//Enchanted Elemental
//If one of them reaches Vashj he will increase her damage done by 5%.
struct MANGOS_DLL_DECL mob_enchanted_elementalAI : public ScriptedAI
{
	mob_enchanted_elementalAI(Creature* pCreature) : ScriptedAI(pCreature)
	{
		m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
		SetCombatMovement(false);
		Reset();
	}

	ScriptedInstance *m_pInstance;                          // the instance

	void Reset() { }

	void MoveInLineOfSight(Unit* pWho)
	{
		if (m_pInstance)
		{
			if (Creature* pVashj = m_pInstance->GetSingleCreatureFromStorage(NPC_LADYVASHJ))
			{
				if (pVashj->IsWithinDistInMap(m_creature, INTERACTION_DISTANCE))
				{
					//increase lady vashj damage
					if (pVashj->isAlive() && pVashj->isInCombat())
						m_creature->CastSpell(pVashj, SPELL_SURGE, false, NULL, NULL, pVashj->GetObjectGuid());
					else
						m_creature->SetDeathState(JUST_DIED);
				}
			}
		}
	}

	void UpdateAI(const uint32 uiDiff) { }
};

//Tainted Elemental
//This mob has 6,900 life, doesn't move, and shoots Poison Bolts at one person anywhere in the area, doing 3,000 nature damage and placing a posion doing 2,000 damage every 2 seconds. He will switch targets often, or sometimes just hang on a single player, but there is nothing you can do about it except heal the damage and kill the Tainted Elemental
struct MANGOS_DLL_DECL mob_tainted_elementalAI : public ScriptedAI
{
	mob_tainted_elementalAI(Creature* pCreature) : ScriptedAI(pCreature)
	{
		m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
		SetCombatMovement(false);
		Reset();
	}

	ScriptedInstance* m_pInstance;                          // the instance

	// timers
	uint32 m_uiPoisonBolt_Timer;

	void Reset()
	{
		m_uiPoisonBolt_Timer = urand(5000, 10000);
	}

	void UpdateAI(const uint32 uiDiff)
	{
		if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
			return;

		//m_uiPoisonBolt_Timer
		if (m_uiPoisonBolt_Timer < uiDiff)
		{
			Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);

			if (pTarget && pTarget->IsWithinDistInMap(m_creature, 30.0f))
				DoCastSpellIfCan(pTarget, SPELL_POISON_BOLT);

			m_uiPoisonBolt_Timer = urand(5000, 10000);
		}else m_uiPoisonBolt_Timer -= uiDiff;
	}
};

//Toxic Sporebat
//Toxic Spores: Used in m_uiPhase 3 by the Spore Bats, it creates a contaminated green patch of ground, dealing about 2775-3225 nature damage every second to anyone who stands in it.
struct MANGOS_DLL_DECL mob_toxic_sporebatAI : public Scripted_NoMovementAI
{
	mob_toxic_sporebatAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
	{
		m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
		Reset();
	}


	ScriptedInstance* m_pInstance;

	uint32 m_uiCheck_Timer;

	void Reset()
	{        
		m_uiCheck_Timer = 1000;

		//@Lorh : Set position here
		float PosX, PosY, PosZ;
		m_creature->GetRandomPoint(afSporebatPos[0], afSporebatPos[1], afSporebatPos[2], 44.0f, PosX, PosY, PosZ);
		m_creature->Relocate(PosX, PosY,  afSporebatPos[2]);

		// @Lorh : This aura cast toxic bolt every 15sec
		DoCastSpellIfCan(m_creature, SPELL_TOXIC_BOLT_AURA, CAST_TRIGGERED);
	}

	void JustSummoned(Creature* pSummoned)
	{
		if(pSummoned->GetEntry() == NPC_TOXIC_BOLT)
		{
			pSummoned->setFaction(m_creature->getFaction());
			pSummoned->SetInCombatWithZone();
		}
	}

	void JustDied(Unit* pVictim)
	{
		if(m_creature->HasAura(SPELL_TOXIC_BOLT_AURA))  
			m_creature->RemoveAurasDueToSpell(SPELL_TOXIC_BOLT_AURA);
	}

	// @Lorh : Sporebat don't attack, just flying
	void AttackStart(Unit* pWho) override { }

	void UpdateAI(const uint32 uiDiff)
	{
		if (m_uiCheck_Timer < uiDiff)
		{
			if (m_pInstance)
			{
				//check if vashj is death
				Creature* pVashj = m_pInstance->GetSingleCreatureFromStorage(NPC_LADYVASHJ);
				if (!pVashj || !pVashj->isAlive())
				{
					//remove
					m_creature->SetDeathState(DEAD);
					m_creature->RemoveCorpse();
					m_creature->setFaction(35);
				}
			}

			m_uiCheck_Timer = 1000;
		}else 
			m_uiCheck_Timer -= uiDiff;
	}
};

//can probably be removed
struct MANGOS_DLL_DECL mob_shield_generator_channelAI : public ScriptedAI
{
	mob_shield_generator_channelAI(Creature* pCreature) : ScriptedAI(pCreature)
	{
		m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
		Reset();
	}

	ScriptedInstance* m_pInstance;                          // the instance

	void Reset() { }

	void MoveInLineOfSight(Unit* pWho) { }
};

//this is wrong, alternative script needed
bool ItemUse_item_tainted_core(Player* pPlayer, Item* pItem, SpellCastTargets const& sctTargets)
{
	ScriptedInstance* pInstance = (ScriptedInstance*)pPlayer->GetInstanceData();

	if (!pInstance)
	{
		error_log("SD2: Lady Vashj Tainted Core: Instance Script Not Initialized");
		return true;
	}

	Creature* pVashj = pInstance->GetSingleCreatureFromStorage(NPC_LADYVASHJ);

	if (!pVashj)
		return true;

	boss_lady_vashjAI* pVashjAI = dynamic_cast<boss_lady_vashjAI*>(pVashj->AI());

	if (sctTargets.getUnitTarget() && sctTargets.getUnitTarget()->GetTypeId() == TYPEID_PLAYER && pPlayer->IsWithinLOSInMap(sctTargets.getUnitTarget()))
	{
		pPlayer->DestroyItemCount(31088, 1, true);
		pPlayer->RemoveAurasDueToSpell(38132);
		pPlayer->CastSpell(sctTargets.getUnitTarget(), 38134, true);
		return true;
	}

	if (pVashjAI && pVashjAI->m_uiPhase == 2)
	{
		if (sctTargets.getGOTarget() && sctTargets.getGOTarget()->GetTypeId() == TYPEID_GAMEOBJECT)
		{
			uint32 uiIdentifier;
			uint8 uiChannelIdentifier;
			switch(sctTargets.getGOTarget()->GetEntry())
			{
			case 185052:
				uiIdentifier = TYPE_SHIELDGENERATOR1;
				uiChannelIdentifier = 0;
				break;
			case 185053:
				uiIdentifier = TYPE_SHIELDGENERATOR2;
				uiChannelIdentifier = 1;
				break;
			case 185051:
				uiIdentifier = TYPE_SHIELDGENERATOR3;
				uiChannelIdentifier = 2;
				break;
			case 185054:
				uiIdentifier = TYPE_SHIELDGENERATOR4;
				uiChannelIdentifier = 3;
				break;
			default:
				return true;
				break;
			}

			if (pInstance->GetData(uiIdentifier) == DONE)
				return true;

			//get and remove channel
			if (Creature* pChannel = pVashj->GetMap()->GetCreature(pVashjAI->m_auiShieldGeneratorChannel[uiChannelIdentifier]))
				pChannel->SetDeathState(JUST_DIED);         //calls Unsummon()

			pInstance->SetData(uiIdentifier, DONE);

			pVashjAI->m_uiShieldGeneratorDown += 1;
			if (pVashjAI->m_uiShieldGeneratorDown < 4)
				pVashjAI->RefreshShieldGenerators();
			pVashj->SetHealth((pVashj->GetMaxHealth() * 0.70) - (pVashj->GetMaxHealth() * 0.05 * pVashjAI->m_uiShieldGeneratorDown));

			//remove this item
			pPlayer->DestroyItemCount(31088, 1, true);
			pPlayer->RemoveAurasDueToSpell(38132);
		}
	}
	return true;
}

CreatureAI* GetAI_boss_lady_vashj(Creature* pCreature)
{
	return new boss_lady_vashjAI(pCreature);
}

CreatureAI* GetAI_mob_enchanted_elemental(Creature* pCreature)
{
	return new mob_enchanted_elementalAI(pCreature);
}

CreatureAI* GetAI_mob_tainted_elemental(Creature* pCreature)
{
	return new mob_tainted_elementalAI(pCreature);
}

CreatureAI* GetAI_mob_toxic_sporebat(Creature* pCreature)
{
	return new mob_toxic_sporebatAI(pCreature);
}

CreatureAI* GetAI_mob_shield_generator_channel(Creature* pCreature)
{
	return new mob_shield_generator_channelAI(pCreature);
}

void AddSC_boss_lady_vashj()
{
	Script* pNewScript;

	pNewScript = new Script;
	pNewScript->Name = "boss_lady_vashj";
	pNewScript->GetAI = &GetAI_boss_lady_vashj;
	pNewScript->RegisterSelf();

	pNewScript = new Script;
	pNewScript->Name = "mob_enchanted_elemental";
	pNewScript->GetAI = &GetAI_mob_enchanted_elemental;
	pNewScript->RegisterSelf();

	pNewScript = new Script;
	pNewScript->Name = "mob_tainted_elemental";
	pNewScript->GetAI = &GetAI_mob_tainted_elemental;
	pNewScript->RegisterSelf();

	pNewScript = new Script;
	pNewScript->Name = "mob_toxic_sporebat";
	pNewScript->GetAI = &GetAI_mob_toxic_sporebat;
	pNewScript->RegisterSelf();

	pNewScript = new Script;
	pNewScript->Name = "mob_shield_generator_channel";
	pNewScript->GetAI = &GetAI_mob_shield_generator_channel;
	pNewScript->RegisterSelf();

	pNewScript = new Script;
	pNewScript->Name = "item_tainted_core";
	pNewScript->pItemUse = &ItemUse_item_tainted_core;
	pNewScript->RegisterSelf();
}