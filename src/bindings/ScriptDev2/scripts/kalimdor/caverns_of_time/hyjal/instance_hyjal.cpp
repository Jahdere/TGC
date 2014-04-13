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
SDName: Instance_Mount_Hyjal
SD%Complete: 100
SDComment: Instance Data Scripts and functions to acquire mobs and set encounter status for use in various Hyjal Scripts
SDCategory: Caverns of Time, Mount Hyjal
EndScriptData */

#include "precompiled.h"
#include "hyjal.h"

/* Battle of Mount Hyjal encounters:
0 - Rage Winterchill event
1 - Anetheron event
2 - Kaz'rogal event
3 - Azgalor event
4 - Archimonde event
*/

instance_mount_hyjal::instance_mount_hyjal(Map* pMap) : ScriptedInstance(pMap),
	m_uiTrashCount(0)
{
	Initialize();
	m_bCanSpawnHordeGem = false;
}

void instance_mount_hyjal::Initialize()
{
	memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
}

bool instance_mount_hyjal::IsEncounterInProgress() const
{
	for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
		if (m_auiEncounter[i] == IN_PROGRESS) return true;

	return false;
}

void instance_mount_hyjal::OnPlayerEnter(Player* /*pPlayer*/)
{
	if (GetData(TYPE_AZGALOR) == DONE)
		DoSpawnArchimonde();
}

void instance_mount_hyjal::OnPlayerDeath(Player* pPlayer)
{
	if(GetData(TYPE_ARCHIMONDE) == IN_PROGRESS)
	{
		if(Creature* pCreature = GetSingleCreatureFromStorage(NPC_ARCHIMONDE))
		{
			switch (urand(0, 2))
			{
			case 0: DoScriptText(SAY_SLAY1, pCreature); break;
			case 1: DoScriptText(SAY_SLAY2, pCreature); break;
			case 2: DoScriptText(SAY_SLAY3, pCreature); break;
			}

			switch (pPlayer->getClass())
			{
			case CLASS_PRIEST:
			case CLASS_PALADIN:
			case CLASS_WARLOCK:
				pPlayer->CastSpell(pCreature, SPELL_SOUL_CHARGE_RED, true);
				break;
			case CLASS_MAGE:
			case CLASS_ROGUE:
			case CLASS_WARRIOR:
				pPlayer->CastSpell(pCreature, SPELL_SOUL_CHARGE_YELLOW, true);
				break;
			case CLASS_DRUID:
			case CLASS_SHAMAN:
			case CLASS_HUNTER:
				pPlayer->CastSpell(pCreature, SPELL_SOUL_CHARGE_GREEN, true);
				break;
			}
		}
	}
}

void instance_mount_hyjal::OnCreatureCreate(Creature* pCreature)
{
	switch(pCreature->GetEntry())
	{
	case NPC_ARCHIMONDE:
	case NPC_WINTERCHILL:
	case NPC_ANETHERON:
	case NPC_KAZROGAL:
	case NPC_AZGALOR:
	case NPC_THRALL:
		m_mNpcEntryGuidStore[pCreature->GetEntry()] = pCreature->GetObjectGuid();
		break;
	case NPC_FOOTMAN:
	case NPC_KNIGHT:
	case NPC_SORCERESS:
	case NPC_PRIESTMAN:
	case NPC_RIFLEMAN:
		lGardsAllyGUIDList.push_back(pCreature->GetObjectGuid());
		break;
	case NPC_GRUNT:
	case NPC_HEADHUNTER:
	case NPC_DOCTOR:
	case NPC_SHAMAN:
	case NPC_TAUREN:
		lGardsHordeGUIDList.push_back(pCreature->GetObjectGuid());
		break;
	case NPC_DOOMGUARD:
		pCreature->SetInCombatWithZone();
		break;
	default:break;
	}
}

void instance_mount_hyjal::OnObjectCreate(GameObject* pGo)
{
	switch(pGo->GetEntry())
	{
	case GO_ANCIENT_GEM:
		{
			if(pGo->GetPositionY() < SEPARATE_BASE)
				lAncientGemHordeGUIDList.push_back(pGo->GetObjectGuid());
			else
				lAncientGemAllyGUIDList.push_back(pGo->GetObjectGuid());

			SetData(TYPE_SPAWN_GO, SPECIAL);
			break;
		}
	case GO_ROARING_FIRE:
		{
			if(pGo->GetPositionY() < SEPARATE_BASE)
				lRoaringFireHordeGUIDList.push_back(pGo->GetObjectGuid());
			else
				lRoaringFireAllyGUIDList.push_back(pGo->GetObjectGuid());

			SetData(TYPE_SPAWN_GO, SPECIAL);
			break;
		}
	case GO_DOOR_THRALL:
		{			
			if (GetData(TYPE_ANETHERON) == DONE)
			{			
				pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED);
				pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
				pGo->SetGoState(GO_STATE_ACTIVE);
			}
			else
			{
				pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED);
			}
			m_mGoEntryGuidStore[pGo->GetEntry()] = pGo->GetObjectGuid();
			break;
		}		
	case GO_DOOR_ARCHIMONDE:
		{
			if (GetData(TYPE_AZGALOR) == DONE)
			{
				pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED);
				pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
				pGo->SetGoState(GO_STATE_ACTIVE);
			}
			else
			{
				pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED);
			}
			m_mGoEntryGuidStore[pGo->GetEntry()] = pGo->GetObjectGuid();
			break;
		}
	default: return;
	}
}

void instance_mount_hyjal::OnCreatureEnterCombat(Creature* pCreature)
{
	switch (pCreature->GetEntry())
	{
	case NPC_WINTERCHILL: SetData(TYPE_WINTERCHILL, IN_PROGRESS); break;
	case NPC_ANETHERON:   SetData(TYPE_ANETHERON, IN_PROGRESS);   break;
	case NPC_KAZROGAL:    SetData(TYPE_KAZROGAL, IN_PROGRESS);    break;
	case NPC_AZGALOR:     SetData(TYPE_AZGALOR, IN_PROGRESS);     break;
	case NPC_ARCHIMONDE:  SetData(TYPE_ARCHIMONDE, IN_PROGRESS);  break;
	}
}

void instance_mount_hyjal::OnCreatureEvade(Creature* pCreature)
{
	switch (pCreature->GetEntry())
	{
	case NPC_WINTERCHILL:
		{
			SetData(TYPE_WINTERCHILL, FAIL);
			pCreature->GetMotionMaster()->MovePoint(3 , 5083.910f, -1789.040f, 1322.569f);
		}
		break;
	case NPC_ANETHERON:
		{
			SetData(TYPE_ANETHERON, FAIL);  
			pCreature->GetMotionMaster()->MovePoint(3 , 5083.910f, -1789.040f, 1322.569f);
			break;
		}
	case NPC_KAZROGAL:
		{
			SetData(TYPE_KAZROGAL, FAIL);
			pCreature->GetMotionMaster()->MovePoint(7 , 5449.970f, -2723.770f, 1485.670f);
			break;
		}
	case NPC_AZGALOR:
		{    
			SetData(TYPE_AZGALOR, FAIL);
			pCreature->GetMotionMaster()->MovePoint(7 , 5449.970f, -2723.770f, 1485.670f);
			break;
		}
	case NPC_NECRO:
	case NPC_ABOMI:
	case NPC_GHOUL:
	case NPC_BANSH:
	case NPC_CRYPT:
	case NPC_GIANT:
	case NPC_STALK:
		{
			float fX, fY, fZ;
			if(GetData(TYPE_ANETHERON) == DONE && GetData(TYPE_AZGALOR) != DONE && !m_uiTrashCount)
			{
				pCreature->GetRandomPoint(5083.910f, -1789.040f, 1322.569f, 5.0f, fX, fY, fZ);
				pCreature->GetMotionMaster()->MoveRandomAroundPoint(fX, fY, fZ, 80.0f);	// Ally Base retreat event
			}
			else if(GetData(TYPE_AZGALOR) == DONE && !m_uiTrashCount)
			{
				pCreature->GetRandomPoint(5523.940f, -2729.156f, 1483.631f, 5.0f, fX, fY, fZ);
				pCreature->GetMotionMaster()->MoveRandomAroundPoint(fX, fY, fZ, 80.0f);	// Horde Base retreat event
			}
			else if(GetData(TYPE_ANETHERON) == DONE)
			{
				pCreature->GetRandomPoint(5449.970f, -2723.770f, 1485.670f, 5.0f, fX, fY, fZ);
				pCreature->GetMotionMaster()->MovePoint(7 , fX, fY, fZ);	// Horde Base wave event
			}
			else
			{
				pCreature->GetRandomPoint(5083.910f, -1789.040f, 1322.569f, 5.0f, fX, fY, fZ);
				pCreature->GetMotionMaster()->MovePoint(3 , fX, fY, fZ);	// Ally Base wave event
			}
			break;
		}
	case NPC_GARGO:
	case NPC_FROST:
		float fX, fY, fZ;
		if(GetData(TYPE_AZGALOR) == DONE && !m_uiTrashCount)
		{
			pCreature->GetRandomPoint(5523.940f, -2729.156f, 1500.631f, 5.0f, fX, fY, fZ);
			pCreature->GetMotionMaster()->MoveRandomAroundPoint(fX, fY, fZ, 80.0f);	// Horde Base retreat event
		}
		else
		{
			pCreature->GetRandomPoint(5449.970f, -2723.770f, 1500.670f, 5.0f, fX, fY, fZ);
			pCreature->GetMotionMaster()->MovePoint(7 , fX, fY, fZ);	// Horde Base wave (z +15.0f)
		}
		break;

	}

}

void instance_mount_hyjal::OnCreatureDeath(Creature* pCreature)
{
	switch (pCreature->GetEntry())
	{
	case NPC_WINTERCHILL: SetData(TYPE_WINTERCHILL, DONE);	break;
	case NPC_ANETHERON:		SetData(TYPE_ANETHERON, DONE);	break;
	case NPC_KAZROGAL:		SetData(TYPE_KAZROGAL, DONE);	break;
	case NPC_AZGALOR:		SetData(TYPE_AZGALOR, DONE);	break;
	case NPC_ARCHIMONDE:	SetData(TYPE_ARCHIMONDE, DONE); break;
		// Trash Mobs summoned in waves
	case NPC_NECRO:
	case NPC_ABOMI:
	case NPC_GHOUL:
	case NPC_BANSH:
	case NPC_CRYPT:
	case NPC_GARGO:
	case NPC_FROST:
	case NPC_GIANT:
	case NPC_STALK:
		// Decrease counter, and update world-state
		if (m_uiTrashCount)
		{
			--m_uiTrashCount;
			DoUpdateWorldState(WORLD_STATE_ENEMYCOUNT, m_uiTrashCount);
		}
		break;
	}
}

void instance_mount_hyjal::SetData(uint32 uiType, uint32 uiData)
{
	switch (uiType)
	{
	case TYPE_WINTERCHILL:	
	case TYPE_KAZROGAL:
		m_auiEncounter[uiType] = uiData;
		break;
	case TYPE_ANETHERON:
		m_auiEncounter[uiType] = uiData;
		if (uiData == DONE)
		{
			if(GameObject* pGo = GetSingleGameObjectFromStorage(GO_DOOR_THRALL))
			{
				pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED);
				pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
				pGo->SetGoState(GO_STATE_ACTIVE);
			}
		}
		break;
	case TYPE_AZGALOR:
		m_auiEncounter[uiType] = uiData;
		if (uiData == DONE)
		{
			if(GameObject* pGo = GetSingleGameObjectFromStorage(GO_DOOR_ARCHIMONDE))
			{
				pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED);
				pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
				pGo->SetGoState(GO_STATE_ACTIVE);
			}
			DoSpawnArchimonde();
			m_bCanSpawnHordeGem = true;
		}
		break;
	case TYPE_ARCHIMONDE:
		m_auiEncounter[uiType] = uiData;
		break;

	case TYPE_TRASH_COUNT:
		m_uiTrashCount = uiData;
		DoUpdateWorldState(WORLD_STATE_ENEMYCOUNT, m_uiTrashCount);
		DoSpawnGards(true);
		break;

	case TYPE_START_EVENT:
		DoSpawnGards();
		break;

	case TYPE_RETREAT:
		if (uiData == SPECIAL)
		{
			if(GetData(TYPE_AZGALOR) == DONE)
			{
				if(!lAncientGemHordeGUIDList.empty())
					for (GuidList::const_iterator itr = lAncientGemHordeGUIDList.begin(); itr != lAncientGemHordeGUIDList.end(); ++itr)
						DoRespawnGameObject(*itr, DAY);
				if(!lRoaringFireHordeGUIDList.empty())
					for (GuidList::const_iterator itr = lRoaringFireHordeGUIDList.begin(); itr != lRoaringFireHordeGUIDList.end(); ++itr)
						DoRespawnGameObject(*itr, DAY);
			}
			else
			{
				if(!lAncientGemAllyGUIDList.empty())
					for (GuidList::const_iterator itr = lAncientGemAllyGUIDList.begin(); itr != lAncientGemAllyGUIDList.end(); ++itr)
						DoRespawnGameObject(*itr, DAY);
				if(!lRoaringFireAllyGUIDList.empty())
					for (GuidList::const_iterator itr = lRoaringFireAllyGUIDList.begin(); itr != lRoaringFireAllyGUIDList.end(); ++itr)
						DoRespawnGameObject(*itr, DAY);
			}
			DoRetreatGards();
		}
		break;

	case TYPE_SPAWN_GO:
		if (uiData == SPECIAL)
		{
			if(GetData(TYPE_AZGALOR) == DONE)
			{
				if(!lRoaringFireHordeGUIDList.empty())
					for (GuidList::const_iterator itr = lRoaringFireHordeGUIDList.begin(); itr != lRoaringFireHordeGUIDList.end(); ++itr)
						DoRespawnGameObject(*itr, DAY);
				if(!lRoaringFireAllyGUIDList.empty())
					for (GuidList::const_iterator itr = lRoaringFireAllyGUIDList.begin(); itr != lRoaringFireAllyGUIDList.end(); ++itr)
						DoRespawnGameObject(*itr, DAY);

				// Need to spawn with OnCreateObject call
				if(m_bCanSpawnHordeGem)
				{
					if (!lAncientGemHordeGUIDList.empty())
						for (GuidList::const_iterator itr = lAncientGemHordeGUIDList.begin(); itr != lAncientGemHordeGUIDList.end(); ++itr)
							DoRespawnGameObject(*itr, DAY);
				}
			}
			else if(GetData(TYPE_ANETHERON) == DONE)
			{
				if(!lRoaringFireAllyGUIDList.empty())
					for (GuidList::const_iterator itr = lRoaringFireAllyGUIDList.begin(); itr != lRoaringFireAllyGUIDList.end(); ++itr)
						DoRespawnGameObject(*itr, DAY);
			}
		}
		break;
	}

	debug_log("SD2: Instance Hyjal: Instance data updated for event %u (Data=%u)", uiType, uiData);

	if (uiData == DONE)
	{
		OUT_SAVE_INST_DATA;

		std::ostringstream saveStream;
		saveStream << m_auiEncounter[0] << " " << m_auiEncounter[1] << " " << m_auiEncounter[2] << " "
			<< m_auiEncounter[3] << " " << m_auiEncounter[4];

		m_strSaveData = saveStream.str();

		SaveToDB();
		OUT_SAVE_INST_DATA_COMPLETE;
	}
}

void instance_mount_hyjal::DoSpawnArchimonde()
{
	// Don't spawn if already killed
	if (GetData(TYPE_ARCHIMONDE) == DONE)
		return;

	// Don't spawn him twice
	if (GetSingleCreatureFromStorage(NPC_ARCHIMONDE, true))
		return;

	// Summon Archimonde
	if (Player* pPlayer = GetPlayerInMap())
		pPlayer->SummonCreature(NPC_ARCHIMONDE, aArchimondeSpawnLoc[0], aArchimondeSpawnLoc[1], aArchimondeSpawnLoc[2], aArchimondeSpawnLoc[3], TEMPSUMMON_DEAD_DESPAWN, 0);
}


// Only Spawn Grunt or Footman during waves , else spawn all guards when a boss die for the next event
void instance_mount_hyjal::DoSpawnGards(bool isWave)
{
	if(GetData(TYPE_ANETHERON) != DONE)
	{
		if (!lGardsAllyGUIDList.empty())
		{
			for (GuidList::const_iterator itr = lGardsAllyGUIDList.begin(); itr != lGardsAllyGUIDList.end(); ++itr)
			{
				if(Creature* pTempGard = instance->GetCreature(*itr))
				{
					if(!isWave || (isWave && pTempGard->GetEntry() == NPC_FOOTMAN))
					{
						if(!pTempGard->isAlive() || !pTempGard->IsDespawned())
							pTempGard->Respawn();
					}
				}
			}
		}
	}
	else
	{
		if (!lGardsHordeGUIDList.empty())
		{
			for (GuidList::const_iterator itr = lGardsHordeGUIDList.begin(); itr != lGardsHordeGUIDList.end(); ++itr)
			{
				if(Creature* pTempGard = instance->GetCreature(*itr))
				{
					if(!isWave || (isWave && pTempGard->GetEntry() == NPC_GRUNT))
					{
						if(!pTempGard->isAlive() || !pTempGard->IsDespawned())
							pTempGard->Respawn();
					}
				}
			}
		}
	}
}

// Start Event
void instance_mount_hyjal::DoRetreatGards()
{
	if(GetData(TYPE_ANETHERON) == DONE && GetData(TYPE_KAZROGAL) != DONE)
	{
		if(!lGardsAllyGUIDList.empty())
		{
			float fX, fY, fZ;
			for (GuidList::const_iterator itr = lGardsAllyGUIDList.begin(); itr != lGardsAllyGUIDList.end(); ++itr)
			{
				if(Creature* pTempGard = instance->GetCreature(*itr))
				{
					if(!pTempGard->isAlive() || !pTempGard->IsDespawned())
						pTempGard->Respawn();
					pTempGard->GetRandomPoint(5083.910f, -1789.040f, 1322.569f, 3.0f, fX, fY, fZ);
					pTempGard->SetWalk(false);
					pTempGard->GetMotionMaster()->MovePoint(3 , fX, fY, fZ);
				}
			}
		}
	}else{
		if(!lGardsHordeGUIDList.empty())
		{
			float fX, fY, fZ;
			for (GuidList::const_iterator itr = lGardsHordeGUIDList.begin(); itr != lGardsHordeGUIDList.end(); ++itr)
			{
				if(Creature* pTempGard = instance->GetCreature(*itr))
				{
					if(!pTempGard->isAlive() || !pTempGard->IsDespawned())
						pTempGard->Respawn();
					pTempGard->GetRandomPoint(5449.970f, -2723.770f, 1485.670f, 3.0f, fX, fY, fZ);
					pTempGard->SetWalk(false);
					pTempGard->GetMotionMaster()->MovePoint(7 , fX, fY, fZ);
				}
			}
		}
	}
}

uint32 instance_mount_hyjal::GetData(uint32 uiType) const
{
	switch (uiType)
	{
	case TYPE_WINTERCHILL:
	case TYPE_ANETHERON:
	case TYPE_KAZROGAL:
	case TYPE_AZGALOR:
	case TYPE_ARCHIMONDE:
		return m_auiEncounter[uiType];
	case TYPE_TRASH_COUNT:
		return m_uiTrashCount;
	default:
		return 0;
	}
}

void instance_mount_hyjal::Load(const char* chrIn)
{
	if (!chrIn)
	{
		OUT_LOAD_INST_DATA_FAIL;
		return;
	}

	OUT_LOAD_INST_DATA(chrIn);

	std::istringstream loadStream(chrIn);
	loadStream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2] >> m_auiEncounter[3] >> m_auiEncounter[4];

	for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
		if (m_auiEncounter[i] == IN_PROGRESS)               // Do not load an encounter as IN_PROGRESS - reset it instead.
			m_auiEncounter[i] = NOT_STARTED;

	OUT_LOAD_INST_DATA_COMPLETE;
}

InstanceData* GetInstanceData_instance_mount_hyjal(Map* pMap)
{
	return new instance_mount_hyjal(pMap);
}

void AddSC_instance_mount_hyjal()
{
	Script* pNewScript;

	pNewScript = new Script;
	pNewScript->Name = "instance_hyjal";
	pNewScript->GetInstanceData = &GetInstanceData_instance_mount_hyjal;
	pNewScript->RegisterSelf();
}
