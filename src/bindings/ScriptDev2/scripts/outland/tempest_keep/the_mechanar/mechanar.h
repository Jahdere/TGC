/* Copyright (C) 2006 - 2011 ScriptDev2 <http://www.scriptdev2.com/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_MECHANAR_H
#define DEF_MECHANAR_H

/*
insert thoses mob in DB to create triggers for the event:
INSERT INTO `creature_ai_scripts` VALUES 
(10020001, 100200, 10, 0, 100, 6, 1, 5, 0, 0, 34, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Mechanar Trigger Event'),
(10020101, 100201, 10, 0, 100, 6, 1, 5, 0, 0, 34, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Mechanar Trigger Event');

INSERT INTO `creature_template` (`entry`, `KillCredit1`, `KillCredit2`, `modelid_1`, `modelid_2`, `modelid_3`, `modelid_4`, `name`, 
`subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `minhealth`, `maxhealth`, `minmana`, `maxmana`, `armor`, `faction_A`, 
`faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, 
`baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, 
`trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, 
`resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `PetSpellDataId`, 
`mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `unk16`, `unk17`, `RacialLeader`, `RegenHealth`, `equipment_id`, `trainer_id`,
 `vendor_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) 
 VALUES (100200, 0, 0, 10045, 0, 10045, 0, 'Trigger (Mechanar) 1', 'Visual', '', 0, 1, 1, 8, 8, 0, 0, 0, 35, 35, 0, 0.91, 1.14286, 1, 
 0, 7, 7, 0, 3, 1, 2000, 2200, 0, 4096, 0, 8, 0, 0, 0, 0, 1.76, 2.42, 100, 8, 5242886, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
 0, 0, 'EventAI', 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 130, ''),
 (100201, 0, 0, 10045, 0, 10045, 0, 'Trigger (Mechanar) 2', 'Visual', '', 0, 1, 1, 8, 8, 0, 0, 0, 35, 35, 0, 0.91, 1.14286, 1, 
 0, 7, 7, 0, 3, 1, 2000, 2200, 0, 4096, 0, 8, 0, 0, 0, 0, 1.76, 2.42, 100, 8, 5242886, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
 0, 0, 'EventAI', 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 130, '');

INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, 
 `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`)
 VALUES (140522, 100200, 554, 1, 0, 0, 255.513, -22.6452, 26.3284, 6.2606, 25, 5, 0, 8, 0, 0, 0),
 (140523, 100201, 554, 1, 0, 0, 157.109, -9.76833, 24.8745, 5.75477, 25, 5, 0, 8, 0, 0, 0);
*/

enum
{
    MAX_ENCOUNTER               = 5,  //Three boss and 2 event part

    TYPE_GYROKILL               = 0,
    TYPE_IRONHAND               = 1,
    TYPE_SEPETHREA              = 2,
    TYPE_EVENT1                 = 3,
    TYPE_EVENT2                 = 4,
	
	NPC_GYROKILL		        = 19218,
	NPC_IRONHAND		        = 19710,
    
    NPC_PATHALEON               = 19220,
	
    NPC_SUNSEEKER_ASTROMAGE     = 19168,
    NPC_BLOODWARDER_CENTURION   = 19510,
    NPC_BLOODWARDER_PHYSICIAN   = 20990,
    NPC_TEMPEST_DESTROYER       = 19735,
    NPC_SUNSEEKER_ENGINEER      = 20988,
    NPC_SUNSEEKER_NETHERBINDER  = 20059,
    
	GO_MOARG_DOOR1		        = 184322,
	GO_MOARG_DOOR2		        = 184632,
};

struct sEventLocInfo
{
    uint32 m_uiEntry;
    float m_fX, m_fY, m_fZ;
};

static sEventLocInfo sPathLoc[] =
{
    {NPC_BLOODWARDER_CENTURION, 241.014f, -22.6322f, 26.3284f},           //wave 1
    {NPC_BLOODWARDER_PHYSICIAN, 236.046f, -18.8698f, 26.3284f},           //wave 1
    {NPC_SUNSEEKER_ASTROMAGE, 236.175f, -22.5076f, 26.3284f},             //wave 1
    {NPC_SUNSEEKER_ASTROMAGE, 236.313f, -26.4251f, 26.3284f},             //wave 1
    {NPC_TEMPEST_DESTROYER, 218.705f, -23.2104f, 24.8745f},               //wave 2
    {NPC_BLOODWARDER_PHYSICIAN, 202.15f, -19.5865f, 24.8745f},            //wave 3
    {NPC_SUNSEEKER_ENGINEER, 202.632f, -26.3383f, 24.8745f},              //wave 3
    {NPC_SUNSEEKER_ENGINEER, 150.271f, 7.18519f, 24.8745f},               //wave 4
    {NPC_BLOODWARDER_PHYSICIAN, 146.29f, 4.7472f, 24.8745f},              //wave 4
    {NPC_SUNSEEKER_ASTROMAGE, 142.012f, 2.13512f, 24.8745f},              //wave 4
    {NPC_TEMPEST_DESTROYER, 137.64f, 37.6397f, 24.8745f},                 //wave 5
    {NPC_SUNSEEKER_ENGINEER, 144.526f, 65.8017f, 24.8987f},               //wave 6
    {NPC_SUNSEEKER_ASTROMAGE, 139.807f, 64.7847f, 24.8745f},              //wave 6
    {NPC_SUNSEEKER_NETHERBINDER, 135.123f, 64.4382f, 24.8745f},           //wave 6
    {NPC_BLOODWARDER_PHYSICIAN, 130.921f, 64.2422f, 24.9186f},            //wave 6
};

class MANGOS_DLL_DECL instance_mechanar : public ScriptedInstance
{
    public:
        instance_mechanar(Map* pMap);

        void Initialize();

        void SetData(uint32 uiType, uint32 uiData);
        uint32 GetData(uint32 uiType) const;
		void OnCreatureDeath(Creature * pCreature);
        void OnCreatureCreate(Creature * pCreature);
		void OnObjectCreate(GameObject* pGo);

        const char* Save() const override { return m_strInstData.c_str(); }
        void Load(const char* chrIn) override;

    private:
        void HandleEvent(uint8 uiPhase = 0);

        uint32 m_auiEncounter[MAX_ENCOUNTER];
        std::string m_strInstData;
        
        uint32 m_uiEventDeathCount;
};

#endif
