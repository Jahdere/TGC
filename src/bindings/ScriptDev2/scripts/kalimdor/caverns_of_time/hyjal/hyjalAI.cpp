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
SDName: HyjalAI
SD%Complete: 100
SDComment:
SDCategory: Caverns of Time, Mount Hyjal
EndScriptData */

#include "precompiled.h"
#include "hyjalAI.h"

struct HyjalLocation
{
	eBaseArea m_pBaseArea;
	float m_fX, m_fY, m_fZ;
	MovePoint m_movePoint;
};

// Locations for summoning waves
// Must be even number

static const HyjalLocation aHyjalSpawnLoc[7] =
{
	{BASE_ALLY,  4969.819f, -1637.413f, 1343.208f, POINT_ID_ALLY},
	{BASE_HORDE, 5526.233f, -2550.069f, 1482.918f, POINT_ID_HORDE},
	{BASE_HORDE, 5567.597f, -2808.696f, 1513.156f, POINT_ID_HORDE_FLY_BACK},
	{BASE_HORDE, 5441.202f, -2604.294f, 1545.218f, POINT_ID_HORDE_FLY_FRONT},
	{BASE_HORDE, 5511.520f, -2727.871f, 1484.247f, POINT_ID_HORDE_TRIGGER_GIANT},
	{BASE_HORDE, 5544.236f, -2635.696f, 1481.903f, POINT_ID_HORDE_EVENT},
	{BASE_HORDE, 4991.555f, -1721.968f, 1334.545f, POINT_ID_ALLY_EVENT},
};

// used to inform the wave where to move after spawn
static const HyjalLocation aHyjalWaveMoveTo[7] =
{
	{BASE_ALLY,  4920.873f, -1676.423f, 1325.010f, POINT_ID_ALLY1},
	{BASE_ALLY,  4991.555f, -1721.968f, 1334.545f, POINT_ID_ALLY2},
	{BASE_ALLY,  5083.910f, -1789.040f, 1322.569f, POINT_ID_ALLY_JAINA},
	{BASE_HORDE, 5548.570f, -2555.973f, 1478.572f, POINT_ID_HORDE1},
	{BASE_HORDE, 5544.236f, -2635.696f, 1481.903f, POINT_ID_HORDE2},
	{BASE_HORDE, 5536.866f, -2756.464f, 1500.099f, POINT_ID_HORDE_FLY_BACK1},
	{BASE_HORDE, 5449.970f, -2723.770f, 1485.670f, POINT_ID_HORDE_TRALL},
};

struct HyjalYells
{
	uint32   uiCreatureEntry;
	YellType m_pYellType;                                   // Used to determine the type of yell (attack, rally, etc)
	int32    m_iTextId;                                     // The text id to be yelled
};

static const HyjalYells aHyjalYell[] =
{
	{NPC_JAINA,  ATTACKED, -1534000},
	{NPC_JAINA,  ATTACKED, -1534001},
	{NPC_JAINA,  INCOMING, -1534002},
	{NPC_JAINA,  BEGIN,    -1534003},
	{NPC_JAINA,  RALLY,    -1534004},
	{NPC_JAINA,  RALLY,    -1534005},
	{NPC_JAINA,  FAILURE,  -1534006},
	{NPC_JAINA,  SUCCESS,  -1534007},
	{NPC_JAINA,  DEATH,    -1534008},

	{NPC_THRALL, ATTACKED, -1534009},
	{NPC_THRALL, ATTACKED, -1534010},
	{NPC_THRALL, INCOMING, -1534011},
	{NPC_THRALL, BEGIN,    -1534012},
	{NPC_THRALL, RALLY,    -1534013},
	{NPC_THRALL, RALLY,    -1534014},
	{NPC_THRALL, FAILURE,  -1534015},
	{NPC_THRALL, SUCCESS,  -1534016},
	{NPC_THRALL, DEATH,    -1534017}
};

struct HyjalWave
{
	uint32 m_auiMobEntry[MAX_WAVE_MOB];                     // Stores Creature Entries to be summoned in Waves
	uint32 m_uiWaveTimer;                                   // The timer before the next wave is summoned
	bool   m_bIsBoss;                                       // Simply used to inform the wave summoner that the next wave contains a boss to halt all waves after that
};

// Waves that will be summoned in the Alliance Base
static const HyjalWave aHyjalWavesAlliance[] =
{
	// Rage Winterchill Wave 1-8
	{{NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, 0, 0, 0, 0, 0, 0, 0, 0}, 125000, false},
	{{NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_CRYPT, NPC_CRYPT, 0, 0, 0, 0, 0, 0}, 125000, false},
	{{NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, 0, 0, 0, 0, 0, 0}, 125000, false},
	{{NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_NECRO, NPC_NECRO, 0, 0, 0, 0, 0, 0}, 125000, false},
	{{NPC_GHOUL, NPC_GHOUL, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_NECRO, NPC_NECRO, NPC_NECRO, NPC_NECRO, 0, 0, 0, 0, 0, 0}, 125000, false},
	{{NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, 0, 0, 0, 0, 0, 0}, 125000, false},
	{{NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_NECRO, NPC_NECRO, NPC_NECRO, NPC_NECRO, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, 0, 0, 0, 0, 0, 0}, 125000, false},
	{{NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_ABOMI, NPC_ABOMI, NPC_NECRO, NPC_NECRO, 0, 0, 0, 0}, 140000, false},
	// All 8 Waves are summoned, summon Rage Winterchill, next few waves are for Anetheron
	{{NPC_WINTERCHILL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, true},
	// Anetheron Wave 1-8
	{{NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, 0, 0, 0, 0, 0, 0, 0, 0}, 125000, false},
	{{NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, 0, 0, 0, 0, 0, 0}, 125000, false},
	{{NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_NECRO, NPC_NECRO, NPC_NECRO, NPC_NECRO, 0, 0, 0, 0, 0, 0}, 125000, false},
	{{NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_NECRO, NPC_NECRO, NPC_NECRO, NPC_NECRO, NPC_BANSH, NPC_BANSH, 0, 0, 0, 0, 0, 0}, 125000, false},
	{{NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_BANSH, NPC_BANSH, NPC_BANSH, NPC_BANSH, NPC_NECRO, NPC_NECRO, 0, 0, 0, 0, 0, 0}, 125000, false},
	{{NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_ABOMI, NPC_ABOMI, NPC_NECRO, NPC_NECRO, NPC_NECRO, NPC_NECRO, 0, 0, 0, 0, 0, 0}, 125000, false},
	{{NPC_GHOUL, NPC_GHOUL, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_BANSH, NPC_BANSH, NPC_BANSH, NPC_BANSH, 0, 0, 0, 0}, 125000, false}, // Ajout 2 bansh
	{{NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_BANSH, NPC_BANSH, NPC_NECRO, NPC_NECRO, 0, 0, 0, 0}, 140000, false},
	// All 8 Waves are summoned, summon Anatheron
	{{NPC_ANETHERON, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, true}
};

// Waves that are summoned in the Horde base
static const HyjalWave aHyjalWavesHorde[] =
{
	// Kaz'Rogal Wave 1-8
	{{NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_BANSH, NPC_BANSH, NPC_NECRO, NPC_NECRO, 0, 0, 0, 0, 0, 0}, 135000, false},
	{{NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GARGO, NPC_GARGO, NPC_GARGO, NPC_GARGO, NPC_GARGO, NPC_GARGO, NPC_GARGO, NPC_GARGO, NPC_GARGO, NPC_GARGO, 0, 0, 0, 0}, 165000, false},
	{{NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_NECRO, NPC_NECRO, 0, 0, 0, 0}, 160000, false},
	{{NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_GARGO, NPC_GARGO, NPC_GARGO, NPC_GARGO, NPC_GARGO, NPC_GARGO, NPC_NECRO, NPC_NECRO, 0, 0, 0, 0}, 165000, false},
	{{NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_NECRO, NPC_NECRO, NPC_NECRO, NPC_NECRO, 0, 0, 0, 0}, 135000, false},
	{{NPC_GARGO, NPC_GARGO, NPC_GARGO, NPC_GARGO, NPC_GARGO, NPC_GARGO, NPC_GARGO, NPC_GARGO, NPC_FROST, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 135000, false},
	{{NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_FROST, 0, 0, 0, 0, 0, 0, 0}, 195000, false},
	{{NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_CRYPT, NPC_CRYPT, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_NECRO, NPC_NECRO, NPC_BANSH, NPC_BANSH, 0, 0}, 225000, false},
	// All 8 Waves are summoned, summon Kaz'Rogal, next few waves are for Azgalor
	{{NPC_KAZROGAL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, true},
	// Azgalor Wave 1-8
	{{NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_NECRO, NPC_NECRO, NPC_NECRO, NPC_NECRO, NPC_NECRO, NPC_NECRO, 0, 0, 0, 0, 0, 0}, 135000, false},
	{{NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_FROST, NPC_GARGO, NPC_GARGO, NPC_GARGO, NPC_GARGO, NPC_GARGO, NPC_GARGO, NPC_GARGO, NPC_GARGO, 0, 0, 0, 0}, 165000, false},
	{{NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GHOUL, NPC_GIANT_HELPER, NPC_GIANT_HELPER, NPC_GIANT_HELPER, NPC_GIANT_HELPER, NPC_GIANT_HELPER, NPC_GIANT_HELPER, NPC_GIANT_HELPER, NPC_GIANT_HELPER, 0, 0, 0, 0}, 160000, false}, // Ajout de 2gouhl
	{{NPC_GIANT_HELPER, NPC_GIANT_HELPER, NPC_GIANT_HELPER, NPC_GIANT_HELPER, NPC_GIANT_HELPER, NPC_GIANT_HELPER, NPC_GIANT_HELPER, NPC_GIANT_HELPER, NPC_STALK, NPC_STALK, NPC_STALK, NPC_STALK, NPC_STALK, NPC_STALK, 0, 0, 0, 0}, 165000, false}, // Remplace 2 STALK par 2 GIANT
	{{NPC_STALK, NPC_STALK, NPC_STALK, NPC_STALK, NPC_STALK, NPC_STALK, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_NECRO, NPC_NECRO, NPC_NECRO, NPC_NECRO, 0, 0, 0, 0}, 135000, false},
	{{NPC_NECRO, NPC_NECRO, NPC_NECRO, NPC_NECRO, NPC_NECRO, NPC_NECRO, NPC_BANSH, NPC_BANSH, NPC_BANSH, NPC_BANSH, NPC_BANSH, NPC_BANSH, 0, 0, 0, 0, 0, 0}, 135000, false},
	{{NPC_GHOUL, NPC_GHOUL, NPC_CRYPT, NPC_CRYPT, NPC_STALK, NPC_STALK, NPC_GIANT_HELPER, NPC_GIANT_HELPER, NPC_GIANT_HELPER, NPC_GIANT_HELPER, NPC_GIANT_HELPER, NPC_GIANT_HELPER, NPC_GIANT_HELPER, NPC_GIANT_HELPER, 0, 0, 0, 0}, 195000, false},
	{{NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_CRYPT, NPC_STALK, NPC_STALK, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_ABOMI, NPC_BANSH, NPC_BANSH, NPC_BANSH, NPC_BANSH, NPC_NECRO, NPC_NECRO, 0, 0}, 225000, false}, //Ajout de 2 bansh
	// All 8 Waves are summoned, summon Azgalor
	{{NPC_AZGALOR, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, true}
};


void hyjalAI::Reset()
{
	// Timers
	m_uiNextWaveTimer = 10000;
	m_uiWaveMoveTimer = 15000;
	m_uiRetreatTimer = 25000;

	// Misc
	m_uiWaveCount = 0;
	m_uiEnemyCount = 0;

	// Set base area based on creature entry
	switch (m_creature->GetEntry())
	{
	case NPC_JAINA:
		m_uiBase = BASE_ALLY;
		DoCastSpellIfCan(m_creature, SPELL_BRILLIANCE_AURA, CAST_TRIGGERED);
		break;
	case NPC_THRALL:
		m_uiBase = BASE_HORDE;
		break;
	}

	// Bools
	m_bIsEventInProgress = false;
	m_bIsSummoningWaves = false;

	m_bIsRetreating = false;
	m_bDebugMode = false;

	// Flags
	m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

	if (!m_pInstance)
		return;

	// Reset World States
	m_pInstance->DoUpdateWorldState(WORLD_STATE_WAVES, 0);
	m_pInstance->DoUpdateWorldState(WORLD_STATE_ENEMY, 0);
	m_pInstance->DoUpdateWorldState(WORLD_STATE_ENEMYCOUNT, 0);

	// Reset Instance Data for trash count
	m_pInstance->SetData(TYPE_TRASH_COUNT, 0);

	m_bIsFirstBossDead  = m_pInstance->GetData(m_uiBase ? TYPE_KAZROGAL : TYPE_WINTERCHILL) == DONE;
	m_bIsSecondBossDead = m_pInstance->GetData(m_uiBase ? TYPE_AZGALOR  : TYPE_ANETHERON) == DONE;
}

bool hyjalAI::IsEventInProgress() const
{
	if (m_bIsEventInProgress)
		return true;

	// The boss might still be around and alive
	for (uint8 i = 0; i < 2; ++i)
	{
		Creature* pBoss = m_creature->GetMap()->GetCreature(m_aBossGuid[i]);
		if (pBoss && pBoss->isAlive())
			return true;
	}

	return false;
}

void hyjalAI::EnterEvadeMode()
{
	m_creature->RemoveAllAurasOnEvade();
	m_creature->DeleteThreatList();
	m_creature->CombatStop(true);

	m_creature->GetMotionMaster()->MoveTargetedHome();

	m_creature->SetLootRecipient(NULL);
}

void hyjalAI::JustReachedHome()
{
	if (m_uiBase == BASE_ALLY)
		DoCastSpellIfCan(m_creature, SPELL_BRILLIANCE_AURA, CAST_TRIGGERED);

	if(m_bIsRetreating)
		DoCastSpellIfCan(m_creature, SPELL_MASS_TELEPORT);

	m_bIsFirstBossDead = m_uiBase ? m_pInstance->GetData(TYPE_KAZROGAL) == DONE : m_pInstance->GetData(TYPE_WINTERCHILL) == DONE;
	m_bIsSecondBossDead = m_uiBase ? m_pInstance->GetData(TYPE_AZGALOR) == DONE : m_pInstance->GetData(TYPE_ANETHERON) == DONE;	
}

void hyjalAI::Aggro(Unit* /*who*/)
{
	for (uint8 i = 0; i < MAX_SPELL; ++i)
		if (m_aSpells[i].m_uiCooldown)
			m_uiSpellTimer[i] = m_aSpells[i].m_uiCooldown;

	DoTalk(ATTACKED);
}

void hyjalAI::SpawnCreatureForWave(uint32 uiMobEntry)
{
	HyjalLocation const* pSpawn = NULL;

	uint32 uiMaxCount = countof(aHyjalSpawnLoc);
	for (uint32 i = 0; i < uiMaxCount; ++i)
	{
		if (aHyjalSpawnLoc[i].m_pBaseArea != (eBaseArea)m_uiBase)
			continue;

		if(uiMobEntry == NPC_GARGO || uiMobEntry == NPC_FROST)
		{

			if(!m_bIsFirstBossDead)
			{
				if(aHyjalSpawnLoc[i].m_movePoint != POINT_ID_HORDE_FLY_BACK)
					continue;
			}else
				if(aHyjalSpawnLoc[i].m_movePoint != POINT_ID_HORDE_FLY_FRONT)
					continue;
		}
		else if(uiMobEntry == NPC_GIANT_HELPER)
		{
			if(aHyjalSpawnLoc[i].m_movePoint != POINT_ID_HORDE_TRIGGER_GIANT)
				continue;
		}

		pSpawn = &aHyjalSpawnLoc[i];
		break;
	}

	if (pSpawn)
	{
		if(uiMobEntry == NPC_GIANT_HELPER)
		{
			float fX, fY, fZ;
			m_creature->GetRandomPoint(pSpawn->m_fX, pSpawn->m_fY, pSpawn->m_fZ, 40.0f, fX, fY, fZ);
			m_creature->SummonCreature(uiMobEntry, fX, fY, fZ + 30.0f, 10.0f, TEMPSUMMON_TIMED_DESPAWN, 15000);
		}else
			m_creature->SummonCreature(uiMobEntry, pSpawn->m_fX, pSpawn->m_fY, pSpawn->m_fZ, 5.0f, TEMPSUMMON_DEAD_DESPAWN, 120000);
	}
}

void hyjalAI::JustSummoned(Creature* pSummoned)
{
	// not interesting for us
	if (pSummoned->GetEntry() == NPC_WATER_ELEMENTAL || pSummoned->GetEntry() == NPC_DIRE_WOLF || pSummoned->GetEntry() == NPC_GIANT_TARGET)
		return;

	HyjalLocation const* pMove = NULL;
	float fX, fY, fZ;

	//Ally / Horde Base retreat event
	if(m_pInstance)
	{
		if(m_uiBase == BASE_HORDE && m_pInstance->GetData(TYPE_AZGALOR) == DONE)
		{
			pMove = &aHyjalWaveMoveTo[6];
			pSummoned->SetWalk(false);
			pSummoned->GetRandomPoint(pMove->m_fX, pMove->m_fY, pMove->m_fZ, 10.0f, fX, fY, fZ);
			pSummoned->GetMotionMaster()->MovePoint(POINT_ID_HORDE_TRALL, fX, fY, fZ);
			return;
		}
		else if(m_uiBase == BASE_ALLY && m_pInstance->GetData(TYPE_ANETHERON) == DONE)
		{
			pMove = &aHyjalWaveMoveTo[2];
			pSummoned->SetWalk(false);
			pSummoned->GetRandomPoint(pMove->m_fX, pMove->m_fY, pMove->m_fZ, 10.0f, fX, fY, fZ);
			pSummoned->GetMotionMaster()->MovePoint(POINT_ID_ALLY_JAINA, fX, fY, fZ);
			return;
		}
	}

	// Increment Enemy Count to be used in World States and instance script
	if(pSummoned->GetEntry() != NPC_GIANT)	// Dont count twice
		++m_uiEnemyCount;

	// Just count
	if(pSummoned->GetEntry() == NPC_GIANT_HELPER)
		return;

	for (uint32 i = 0; i < countof(aHyjalWaveMoveTo); ++i)
	{
		if (aHyjalWaveMoveTo[i].m_pBaseArea != (eBaseArea)m_uiBase)
			continue;

		switch(pSummoned->GetEntry())
		{
		case NPC_GARGO:
		case NPC_FROST:
			{
				if(!m_bIsFirstBossDead)	// Flying from the back
				{
					if(aHyjalWaveMoveTo[i].m_movePoint != POINT_ID_HORDE_FLY_BACK1)			
						continue;
				}else{
					if(aHyjalWaveMoveTo[i].m_movePoint != POINT_ID_HORDE2)	// Flying from the front
						continue;
				}
				break;
			}
		case NPC_GIANT:	//Just Set Target
			{
				pSummoned->SetInCombatWithZone();
				if (Unit* pTarget = pSummoned->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
					pSummoned->AI()->AttackStart(pTarget);
				else
				{
					pMove = &aHyjalWaveMoveTo[6];
					pSummoned->GetMotionMaster()->MovePoint(POINT_ID_HORDE_TRALL, pMove->m_fX, pMove->m_fY, pMove->m_fZ);
				}
				continue;
				break;
			}
		default:
			if((aHyjalWaveMoveTo[i].m_movePoint != POINT_ID_ALLY1 && m_uiBase == BASE_ALLY) || (aHyjalWaveMoveTo[i].m_movePoint != POINT_ID_HORDE1 && m_uiBase == BASE_HORDE))
				continue;
		}

		pMove = &aHyjalWaveMoveTo[i];
		break;
	}

	if (pMove)
	{
		pSummoned->GetRandomPoint(pMove->m_fX, pMove->m_fY, pMove->m_fZ, 10.0f, fX, fY, fZ);

		pSummoned->SetWalk(false);
		if(pSummoned->GetEntry() == NPC_FROST || pSummoned->GetEntry() == NPC_GARGO)
			pSummoned->GetMotionMaster()->MovePoint(pMove->m_movePoint, fX, fY, fZ + 15.0f);
		else
			pSummoned->GetMotionMaster()->MovePoint(pMove->m_movePoint, fX, fY, fZ);
	}

	// Check if creature is a boss.
	if (pSummoned->IsWorldBoss())
		m_aBossGuid[!m_bIsFirstBossDead ? 0 : 1] = pSummoned->GetObjectGuid();
	else
		lWaveMobGUIDList.push_back(pSummoned->GetObjectGuid());
}

void hyjalAI::SummonedMovementInform(Creature* pSummoned, uint32 uiMotionType, uint32 uiPointId)
{

	if (uiMotionType != POINT_MOTION_TYPE || !uiPointId || pSummoned->isDead())
		return;


	float fX, fY, fZ;
	HyjalLocation const* pMove = NULL;

	switch(uiPointId)
	{
	case POINT_ID_ALLY1:	// Go next step
	case POINT_ID_ALLY2:	// Go Jaina
		pMove = &aHyjalWaveMoveTo[uiPointId];
		pSummoned->GetRandomPoint(pMove->m_fX, pMove->m_fY, pMove->m_fZ, 2.0f, fX, fY, fZ);		
		pSummoned->GetMotionMaster()->MovePoint(pMove->m_movePoint, fX, fY, fZ);
		break;
	case POINT_ID_HORDE1:	// Go next step
		pMove = &aHyjalWaveMoveTo[4];
		pSummoned->GetRandomPoint(pMove->m_fX, pMove->m_fY, pMove->m_fZ, 10.0f, fX, fY, fZ);
		if(pSummoned->GetEntry() == NPC_FROST || pSummoned->GetEntry() == NPC_GARGO)
			pSummoned->GetMotionMaster()->MovePoint(pMove->m_movePoint,fX, fY, fZ + 15.0f);
		else
			pSummoned->GetMotionMaster()->MovePoint(pMove->m_movePoint,fX, fY, fZ);
		break;
	case POINT_ID_HORDE_FLY_BACK1:	// Go Thrall
	case POINT_ID_HORDE2:		
		if((pSummoned->GetEntry() == NPC_FROST || pSummoned->GetEntry() == NPC_GARGO) && m_bIsSecondBossDead)
		{
			pSummoned->GetMotionMaster()->MoveRandomAroundPoint(pSummoned->GetPositionX(), pSummoned->GetPositionY(), pSummoned->GetPositionZ(), 80.0f);
			break;
		}
		pMove = &aHyjalWaveMoveTo[6];
		pSummoned->GetRandomPoint(pMove->m_fX, pMove->m_fY, pMove->m_fZ, 10.0f, fX, fY, fZ);
		pSummoned->GetMotionMaster()->MovePoint(pMove->m_movePoint,fX, fY, fZ);
		break;
	case POINT_ID_ALLY_JAINA:
		if(m_pInstance)
		{
			if(m_uiBase == BASE_ALLY && m_pInstance->GetData(TYPE_ANETHERON) == DONE)
			{
				pSummoned->GetRandomPoint(5083.910f, -1789.040f, 1322.569f, 5.0f, fX, fY, fZ);
				pSummoned->GetMotionMaster()->MoveRandomAroundPoint(fX, fY, fZ, 80.0f);	// Ally Base retreat event
			}
		}
		break;
	case POINT_ID_HORDE_TRALL:
		if(m_pInstance)
		{
			if(m_uiBase == BASE_HORDE && m_pInstance->GetData(TYPE_AZGALOR) == DONE)
			{
				pSummoned->GetRandomPoint(5523.940f, -2729.156f, 1483.631f, 5.0f, fX, fY, fZ);
				pSummoned->GetMotionMaster()->MoveRandomAroundPoint(fX, fY, fZ, 80.0f);	// Horde Base retreat event
			}
		}
		break;
	}
}

void hyjalAI::SummonedCreatureJustDied(Creature* pSummoned)
{
	if(pSummoned->GetEntry() == NPC_GIANT)	//Prevent remove aura Immolation
		pSummoned->RemoveAurasDueToSpell(37059);

	if (!pSummoned->IsWorldBoss())                          // Only do stuff when bosses die
		return;

	if (m_aBossGuid[0] == pSummoned->GetObjectGuid())
	{
		DoTalk(INCOMING);
		m_bIsFirstBossDead = true;
	}
	else if (m_aBossGuid[1] == pSummoned->GetObjectGuid())
	{
		DoTalk(SUCCESS);
		m_bIsSecondBossDead = true;
	}

	m_bIsEventInProgress = false;

	m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

	// Reset world state for enemies to disable it
	m_pInstance->DoUpdateWorldState(WORLD_STATE_ENEMY, 0);

	m_creature->SetActiveObjectState(false);

	lWaveMobGUIDList.clear();
}

void hyjalAI::SummonNextWave()
{
	// 1 in 4 chance we give a rally yell. Not sure if the chance is offilike.
	if (!urand(0, 3))
		DoTalk(RALLY);

	if (!m_pInstance)
		return;

	HyjalWave const* pWaveData = m_uiBase ? &aHyjalWavesHorde[m_uiWaveCount] : &aHyjalWavesAlliance[m_uiWaveCount];

	if (!pWaveData)
	{
		script_error_log("hyjalAI not able to obtain wavedata for SummonNextWave.");
		return;
	}

	m_uiEnemyCount = m_pInstance->GetData(TYPE_TRASH_COUNT);

	for (uint8 i = 0; i < MAX_WAVE_MOB; ++i)
	{
		if (pWaveData->m_auiMobEntry[i])
			SpawnCreatureForWave(pWaveData->m_auiMobEntry[i]);
	}

	if (!pWaveData->m_bIsBoss)
	{
		uint32 stateValue = m_uiWaveCount + 1;

		if (m_bIsFirstBossDead)
			stateValue -= MAX_WAVES;                        // Subtract 9 from it to give the proper wave number if we are greater than 8

		// Set world state to our current wave number
		m_pInstance->DoUpdateWorldState(WORLD_STATE_WAVES, stateValue);
		// Enable world state
		m_pInstance->DoUpdateWorldState(WORLD_STATE_ENEMY, 1);

		m_pInstance->SetData(TYPE_TRASH_COUNT, m_uiEnemyCount);   // Send data for instance script to update count

		if (!m_bDebugMode)
			m_uiNextWaveTimer = pWaveData->m_uiWaveTimer;
		else
		{
			m_uiNextWaveTimer = 15000;
			debug_log("SD2: HyjalAI: debug mode is enabled. Next Wave in 15 seconds");
		}
	}
	else
	{
		// Set world state for waves to 0 to disable it.
		m_pInstance->DoUpdateWorldState(WORLD_STATE_WAVES, 0);
		m_pInstance->DoUpdateWorldState(WORLD_STATE_ENEMY, 1);

		// Set World State for enemies invading to 1.
		m_pInstance->DoUpdateWorldState(WORLD_STATE_ENEMYCOUNT, 1);

		m_bIsSummoningWaves = false;
	}

	m_uiWaveMoveTimer = 15000;
	++m_uiWaveCount;
}

void hyjalAI::StartEvent()
{
	if (!m_pInstance)
		return;

	if (IsEventInProgress())
		return;

	DoTalk(BEGIN);

	m_bIsEventInProgress = true;
	m_bIsSummoningWaves = true;

	m_uiNextWaveTimer = 10000;

	m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

	m_pInstance->DoUpdateWorldState(WORLD_STATE_WAVES, 0);
	m_pInstance->DoUpdateWorldState(WORLD_STATE_ENEMY, 0);
	m_pInstance->DoUpdateWorldState(WORLD_STATE_ENEMYCOUNT, 0);

	m_pInstance->SetData(TYPE_START_EVENT, 0);

	m_creature->SetActiveObjectState(true);
}

void hyjalAI::DoTalk(YellType pYellType)
{
	HyjalYells const* pYell = NULL;

	bool bGetNext = false;

	for (uint32 i = 0; i < countof(aHyjalYell); ++i)
	{
		if (aHyjalYell[i].uiCreatureEntry == m_creature->GetEntry() && aHyjalYell[i].m_pYellType == pYellType)
		{
			// this would not be safe unless we knew these had two entries in m_aYell
			if (pYellType == ATTACKED || pYellType == RALLY)
			{
				if (!bGetNext && urand(0, 1))
				{
					bGetNext = true;
					continue;
				}
			}

			pYell = &aHyjalYell[i];
			break;
		}
	}

	if (pYell)
		DoScriptText(pYell->m_iTextId, m_creature);
}

// Start event
void hyjalAI::SpellHitTarget(Unit* pTarget, const SpellEntry* pSpell)
{
	// TODO: this spell should cause misc mobs to despawn
	if (pSpell->Id == SPELL_MASS_TELEPORT && pTarget->GetTypeId() != TYPEID_PLAYER)
	{
		((Creature*)pTarget)->ForcedDespawn(1500);
		((Creature*)pTarget)->SetRespawnDelay(1500);
		((Creature*)pTarget)->SetRespawnTime(WEEK);

		if(m_bIsRetreating)
		{
			m_creature->ForcedDespawn(1500);
			m_creature->SetRespawnDelay(1500);
			m_creature->SetRespawnTime(WEEK);
			SpawnInvaders();
			m_bIsRetreating = false;
		}
	}
}

// Event retreat process
void hyjalAI::SpawnInvaders()
{
	if(m_uiBase == BASE_ALLY)
	{
		HyjalLocation const* pSpawn = &aHyjalSpawnLoc[6];
		float fX, fY, fZ;		
		if(pSpawn)
		{
			for (uint8 i = 0; i < 15; ++i)
			{
				m_creature->GetRandomPoint(pSpawn->m_fX, pSpawn->m_fY, pSpawn->m_fZ, 10.0f, fX, fY, fZ);
				m_creature->SummonCreature(NPC_ABOMI, fX, fY, fZ, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 120000);
				m_creature->SummonCreature(NPC_CRYPT, fX, fY, fZ, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 120000);
				m_creature->SummonCreature(NPC_GHOUL, fX, fY, fZ, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 120000);
				m_creature->SummonCreature(NPC_BANSH, fX, fY, fZ, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 120000);
				m_creature->SummonCreature(NPC_NECRO, fX, fY, fZ, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 120000);
			}
		}
	}
	else
	{
		HyjalLocation const* pSpawn = &aHyjalSpawnLoc[5];
		HyjalLocation const* pSpawn_fly = &aHyjalSpawnLoc[2];
		HyjalLocation const* pSpawn_inferno = &aHyjalSpawnLoc[4];
		float fX, fY, fZ;
		if(pSpawn && pSpawn_fly && pSpawn_inferno)
		{
			for (uint8 i = 0; i < 15; ++i)
			{
				m_creature->SummonCreature(NPC_ABOMI, pSpawn->m_fX, pSpawn->m_fY, pSpawn->m_fZ, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 120000);
				m_creature->SummonCreature(NPC_CRYPT, pSpawn->m_fX, pSpawn->m_fY, pSpawn->m_fZ, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 120000);
				m_creature->SummonCreature(NPC_GHOUL, pSpawn->m_fX, pSpawn->m_fY, pSpawn->m_fZ, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 120000);
				m_creature->SummonCreature(NPC_BANSH, pSpawn->m_fX, pSpawn->m_fY, pSpawn->m_fZ, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 120000);
				m_creature->SummonCreature(NPC_NECRO, pSpawn->m_fX, pSpawn->m_fY, pSpawn->m_fZ, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 120000);

				m_creature->SummonCreature(NPC_GARGO, pSpawn_fly->m_fX, pSpawn_fly->m_fY, pSpawn_fly->m_fZ, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 120000);
				if(i < 3)
				{
					m_creature->GetRandomPoint(pSpawn_fly->m_fX, pSpawn_fly->m_fY, pSpawn_fly->m_fZ, 40.0f, fX, fY, fZ);
					m_creature->SummonCreature(NPC_FROST, fX, fY, fZ, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 120000);
				}

				m_creature->GetRandomPoint(pSpawn_inferno->m_fX, pSpawn_inferno->m_fY, pSpawn_inferno->m_fZ, 40.0f, fX, fY, fZ);
				m_creature->SummonCreature(NPC_GIANT_HELPER, fX, fY, fZ + 30.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 15000);
			}
		}
	}
}

void hyjalAI::Retreat()
{
	// this will trigger ancient gem respawn
	if (m_pInstance)
		m_pInstance->SetData(TYPE_RETREAT, SPECIAL);

	m_creature->GetMotionMaster()->MoveTargetedHome();

	m_bIsRetreating = true;
}

void hyjalAI::JustDied(Unit* pKiller)
{
	DoTalk(DEATH);
	m_creature->SetActiveObjectState(false);

	if(m_pInstance)
	{

		for(uint8 i = 0; i < MAX_ENCOUNTER; i++)
		{
			if(m_pInstance->GetData(i) == IN_PROGRESS)
			{
				switch(i)
				{
				case TYPE_WINTERCHILL:
					m_pInstance->GetSingleCreatureFromStorage(NPC_WINTERCHILL)->ForcedDespawn();
					m_pInstance->SetData(i, FAIL);
					break;
				case TYPE_ANETHERON:
					m_pInstance->GetSingleCreatureFromStorage(NPC_ANETHERON)->ForcedDespawn();
					m_pInstance->SetData(i, FAIL);
					break;
				case TYPE_KAZROGAL:
					m_pInstance->GetSingleCreatureFromStorage(NPC_KAZROGAL)->ForcedDespawn();
					m_pInstance->SetData(i, FAIL);
					break;
				case TYPE_AZGALOR:
					m_pInstance->GetSingleCreatureFromStorage(NPC_AZGALOR)->ForcedDespawn();
					m_pInstance->SetData(i, FAIL);
					break;
				}
			}
		}

		// Despawn current wave
		for (GuidList::const_iterator itr = lWaveMobGUIDList.begin(); itr != lWaveMobGUIDList.end(); ++itr)
		{
			if (Creature* pTemp = m_pInstance->instance->GetCreature(*itr))
				pTemp->ForcedDespawn();
		}

		lWaveMobGUIDList.clear();
	}
}

void hyjalAI::UpdateAI(const uint32 uiDiff)
{
	if (!m_bIsEventInProgress)
		return;

	if (m_bIsSummoningWaves && m_pInstance)
	{
		if (m_uiWaveMoveTimer < uiDiff)
 		{
 			// Skip the master timer, and start next wave in 5. Clear the list, it should not be any here now.
 			if (!m_pInstance->GetData(TYPE_TRASH_COUNT))
 				m_uiNextWaveTimer = std::min(m_uiNextWaveTimer, (uint32)5000);
 
 			m_uiWaveMoveTimer = 10000;
 		}
 		else
 			m_uiWaveMoveTimer -= uiDiff;

		if (m_uiNextWaveTimer < uiDiff)
			SummonNextWave();
		else
			m_uiNextWaveTimer -= uiDiff;
	}

	if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
		return;

	for (uint8 i = 0; i < MAX_SPELL; ++i)
	{
		if (m_aSpells[i].m_uiSpellId)
		{
			if (m_uiSpellTimer[i] < uiDiff)
			{
				if (m_creature->IsNonMeleeSpellCasted(false))
					m_creature->InterruptNonMeleeSpells(false);

				Unit* pTarget = NULL;

				switch (m_aSpells[i].m_pType)
				{
				case TARGETTYPE_SELF:   pTarget = m_creature; break;
				case TARGETTYPE_RANDOM: pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0); break;
				case TARGETTYPE_VICTIM: pTarget = m_creature->getVictim(); break;
				}

				if (pTarget)
				{
					DoCastSpellIfCan(pTarget, m_aSpells[i].m_uiSpellId);
					m_uiSpellTimer[i] = m_aSpells[i].m_uiCooldown;
				}
			}
			else
				m_uiSpellTimer[i] -= uiDiff;
		}
	}

	DoMeleeAttackIfReady();
}

void hyjalAI::JustRespawned()
{
	Reset();
}
