/* Copyright (C) 2006 - 2013 ScriptDev2 <http://www.scriptdev2.com/>
* This program is free software licensed under GPL version 2
* Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_HYJAL_H
#define DEF_HYJAL_H

enum
{
	MAX_ENCOUNTER               = 5,

	TYPE_WINTERCHILL            = 0,
	TYPE_ANETHERON              = 1,
	TYPE_KAZROGAL               = 2,
	TYPE_AZGALOR                = 3,
	TYPE_ARCHIMONDE             = 4,

	TYPE_TRASH_COUNT            = 5,
	TYPE_RETREAT                = 6,
	TYPE_SPAWN_GO				= 7,
	TYPE_START_EVENT			= 8,

	WORLD_STATE_WAVES           = 2842,
	WORLD_STATE_ENEMY           = 2453,
	WORLD_STATE_ENEMYCOUNT      = 2454,

	NPC_JAINA                   = 17772,
	NPC_THRALL                  = 17852,
	NPC_TYRANDE                 = 17948,

	// Bosses summoned after every 8 waves
	NPC_WINTERCHILL             = 17767,
	NPC_ANETHERON               = 17808,
	NPC_KAZROGAL                = 17888,
	NPC_AZGALOR                 = 17842,
	NPC_ARCHIMONDE              = 17968,

	// Trash Mobs summoned in waves
	NPC_NECRO                   = 17899,
	NPC_ABOMI                   = 17898,
	NPC_GHOUL                   = 17895,
	NPC_BANSH                   = 17905,
	NPC_CRYPT                   = 17897,
	NPC_GARGO                   = 17906,
	NPC_FROST                   = 17907,
	NPC_GIANT                   = 17908,
	NPC_STALK                   = 17916,
	NPC_DOOMGUARD				= 17864,

	// Helpers for summon NPC_GIANT
	NPC_GIANT_HELPER			= 18242,
	NPC_GIANT_TARGET			= 21075,

	// Pnj Bastion Ally
	NPC_RIFLEMAN				= 17921,
	NPC_PRIESTMAN				= 17928,
	NPC_SORCERESS				= 17922,
	NPC_FOOTMAN					= 17919,
	NPC_KNIGHT					= 17920,

	// PNJ Bastion Horde
	NPC_GRUNT					= 17932,
	NPC_HEADHUNTER				= 17934,
	NPC_DOCTOR					= 17935,
	NPC_SHAMAN					= 17936,
	NPC_TAUREN					= 17933,


	// Summoned by Thrall and Jaina
	NPC_WATER_ELEMENTAL         = 18001,
	NPC_DIRE_WOLF               = 17854,

	GO_ANCIENT_GEM              = 185557,
	GO_ROARING_FIRE				= 182592,
	GO_DOOR_ARCHIMONDE			= 182061,
	GO_DOOR_THRALL				= 182060,

	// Archimonde Spell And Sript Text
	SPELL_SOUL_CHARGE_YELLOW    = 32045,
	SPELL_SOUL_CHARGE_GREEN     = 32051,
	SPELL_SOUL_CHARGE_RED       = 32052,
	SAY_SLAY1                   = -1534024,
	SAY_SLAY2                   = -1534025,
	SAY_SLAY3                   = -1534026,


};

static const float aArchimondeSpawnLoc[4] = {5581.49f, -3445.63f, 1575.1f, 3.905f};

const float SEPARATE_BASE  = -2400.0f;

class MANGOS_DLL_DECL instance_mount_hyjal : public ScriptedInstance
{
public:
	instance_mount_hyjal(Map* pMap);

	void Initialize() override;
	bool IsEncounterInProgress() const override;

	void OnPlayerEnter(Player* pPlayer) override;
	void OnPlayerDeath(Player* pPlayer) override;

	void OnCreatureCreate(Creature* pCreature) override;
	void OnObjectCreate(GameObject* pGo) override;

	void OnCreatureEnterCombat(Creature* pCreature) override;
	void OnCreatureEvade(Creature* pCreature);
	void OnCreatureDeath(Creature* pCreature) override;	

	void SetData(uint32 uiType, uint32 uiData) override;
	uint32 GetData(uint32 uiType) const override;

	const char* Save() const override { return m_strSaveData.c_str(); }
	void Load(const char* chrIn) override;

	void DoSpawnGards(bool isWave = false);
	void DoRetreatGards();

private:
	void DoSpawnArchimonde();

	uint32 m_auiEncounter[MAX_ENCOUNTER];
	std::string m_strSaveData;

	GuidList lAncientGemAllyGUIDList;
	GuidList lAncientGemHordeGUIDList;
	GuidList lRoaringFireAllyGUIDList;
	GuidList lRoaringFireHordeGUIDList;

	GuidList lGardsAllyGUIDList;
	GuidList lGardsHordeGUIDList;

	uint32 m_uiTrashCount;

	bool m_bCanSpawnHordeGem;
};

#endif
