/* Copyright (C) 2006 - 2011 ScriptDev2 <http://www.scriptdev2.com/>
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
SDName: Instance_Mechanar
SD%Complete: 20
SDComment:
SDCategory: Mechanar
EndScriptData */

#include "precompiled.h"
#include "mechanar.h"

instance_mechanar::instance_mechanar(Map* pMap) : ScriptedInstance(pMap),
	m_uiEventDeathCount(0)
{ 
    Initialize();
}

void instance_mechanar::Initialize()
{
    memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
}

void instance_mechanar::OnObjectCreate(GameObject* pGo)
{
	switch(pGo->GetEntry())
	{
        case GO_MOARG_DOOR1:
            if (GetData(TYPE_GYROKILL) == DONE)
				pGo->SetGoState(GO_STATE_ACTIVE);
            break;
        case GO_MOARG_DOOR2:
            if (GetData(TYPE_IRONHAND) == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            break;
		default: return;
	}
    m_mGoEntryGuidStore[pGo->GetEntry()] = pGo->GetObjectGuid();
}

void instance_mechanar::OnCreatureCreate(Creature * pCreature)
{
    if(pCreature->GetEntry() == NPC_PATHALEON)
        m_mNpcEntryGuidStore[NPC_PATHALEON] = pCreature->GetObjectGuid();
}

void instance_mechanar::OnCreatureDeath(Creature * pCreature)
{
	switch(pCreature->GetEntry())
	{
		case NPC_GYROKILL: SetData(TYPE_GYROKILL, DONE); break;
		case NPC_IRONHAND: SetData(TYPE_IRONHAND, DONE); break;
        case NPC_SUNSEEKER_ASTROMAGE:
        case NPC_BLOODWARDER_CENTURION:
        case NPC_BLOODWARDER_PHYSICIAN:
        case NPC_TEMPEST_DESTROYER:
        case NPC_SUNSEEKER_ENGINEER:
        case NPC_SUNSEEKER_NETHERBINDER:
            if (m_auiEncounter[TYPE_EVENT1] == DONE)
            {
                ++m_uiEventDeathCount;
                HandleEvent();
            }
            break;
		default : return;
	}
}

void instance_mechanar::HandleEvent(uint8 uiPhase)
{
    if(Creature* pPathaleon = GetSingleCreatureFromStorage(NPC_PATHALEON))
        switch(uiPhase)
        {
            case 1:
                for(uint8 i = 0; i < 4; ++i)
                    pPathaleon->SummonCreature(sPathLoc[i].m_uiEntry, sPathLoc[i].m_fX, sPathLoc[i].m_fY, sPathLoc[i].m_fZ, 0, TEMPSUMMON_DEAD_DESPAWN,0);
                break;
            case 2:
                for(uint8 i = 7; i < 10; ++i)
                    pPathaleon->SummonCreature(sPathLoc[i].m_uiEntry, sPathLoc[i].m_fX, sPathLoc[i].m_fY, sPathLoc[i].m_fZ, 0, TEMPSUMMON_DEAD_DESPAWN,0);
                break;
            default:
            {
                switch(m_uiEventDeathCount)
                {
                    case 4:
                        pPathaleon->SummonCreature(sPathLoc[4].m_uiEntry, sPathLoc[4].m_fX, sPathLoc[4].m_fY, sPathLoc[4].m_fZ, 0, TEMPSUMMON_DEAD_DESPAWN,0);                        
                        break;
                    case 5:
                        for(uint8 i = 5; i < 7; ++i)
                            pPathaleon->SummonCreature(sPathLoc[i].m_uiEntry, sPathLoc[i].m_fX, sPathLoc[i].m_fY, sPathLoc[i].m_fZ, 0, TEMPSUMMON_DEAD_DESPAWN,0);
                        break;
                    case 10:
                        pPathaleon->SummonCreature(sPathLoc[10].m_uiEntry, sPathLoc[10].m_fX, sPathLoc[10].m_fY, sPathLoc[10].m_fZ, 0, TEMPSUMMON_DEAD_DESPAWN,0);                        
                        break;
                    case 11:
                        for(uint8 i = 11; i < 15; ++i)
                            pPathaleon->SummonCreature(sPathLoc[i].m_uiEntry, sPathLoc[i].m_fX, sPathLoc[i].m_fY, sPathLoc[i].m_fZ, 0, TEMPSUMMON_DEAD_DESPAWN,0);
                        break;
                    case 15:
                        pPathaleon->NearTeleportTo( 137.988f, 90.994f, 26.3734f, 0.0f );
                        if(Player* pTarget = GetPlayerInMap(true, false))
                            pPathaleon->AI()->AttackStart(pTarget);
                        break;
                    default: return;
                }
            }
        }
}

void instance_mechanar::SetData(uint32 uiType, uint32 uiData)
{
    switch(uiType)
    {
		case TYPE_GYROKILL:
            m_auiEncounter[TYPE_GYROKILL] = uiData;
            if (uiData == DONE)
				if(GameObject* pGo = GetSingleGameObjectFromStorage(GO_MOARG_DOOR1))
					pGo->SetGoState(GO_STATE_ACTIVE);
			break;
		case TYPE_IRONHAND:
            m_auiEncounter[TYPE_IRONHAND] = uiData;
            if (uiData == DONE)
			   if(GameObject* pGo = GetSingleGameObjectFromStorage(GO_MOARG_DOOR2))
					pGo->SetGoState(GO_STATE_ACTIVE);
			break;
        case TYPE_SEPETHREA:
            m_auiEncounter[TYPE_SEPETHREA] = uiData;
            break;
        case TYPE_EVENT1:
            if ( m_auiEncounter[TYPE_EVENT1] != DONE )
                HandleEvent(1);
            m_auiEncounter[TYPE_EVENT1] = uiData;
            break;
        case TYPE_EVENT2:
            if ( m_auiEncounter[TYPE_EVENT2] != DONE )
                HandleEvent(2);
            m_auiEncounter[TYPE_EVENT2] = uiData;
            break;
    }

    if (uiData == DONE)
    {
        OUT_SAVE_INST_DATA;

        std::ostringstream saveStream;

        saveStream << m_auiEncounter[0] << " " << m_auiEncounter[1] << " " << m_auiEncounter[2] << " "
                   << m_auiEncounter[3]  << " " << m_auiEncounter[4];

        m_strInstData = saveStream.str();

        SaveToDB();
        OUT_SAVE_INST_DATA_COMPLETE;
    }
}

void instance_mechanar::Load(const char* chrIn)
{
    if (!chrIn)
    {
        OUT_LOAD_INST_DATA_FAIL;
        return;
    }

    OUT_LOAD_INST_DATA(chrIn);

    std::istringstream loadStream(chrIn);
    loadStream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2] >> m_auiEncounter[3]
               >> m_auiEncounter[4];

    for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
    {
        if (m_auiEncounter[i] == IN_PROGRESS)
            m_auiEncounter[i] = NOT_STARTED;
    }

    OUT_LOAD_INST_DATA_COMPLETE;
}

uint32 instance_mechanar::GetData(uint32 uiType) const
{
    if (uiType < MAX_ENCOUNTER)
        return m_auiEncounter[uiType];

    return 0;
}

InstanceData* GetInstanceData_instance_mechanar(Map* pMap)
{
    return new instance_mechanar(pMap);
}

void AddSC_instance_mechanar()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "instance_mechanar";
    pNewScript->GetInstanceData = &GetInstanceData_instance_mechanar;
    pNewScript->RegisterSelf();
}
