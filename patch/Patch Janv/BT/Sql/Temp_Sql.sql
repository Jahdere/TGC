
#SUPREMUS
#Hit box supremus
UPDATE creature_model_info SET bounding_radius = 10 , combat_reach = 9 WHERE modelid = 21145;

#AKAMA
#Time respawn
UPDATE creature SET spawntimesecs = 300 WHERE id = 22990;

#Thrall GT1 hero
UPDATE creature_template SET minlevel = 72, maxlevel = 72, minhealth = 143000, maxhealth = 143000, mindmg = 800, maxdmg = 1200, attackpower = 200, baseattacktime = 1400, faction_A = 1747, faction_H = 1747 WHERE entry = 20548;

#GT3 inferno
UPDATE creature_ai_scripts SET action1_param1 = 31724 WHERE id = 1790802;
UPDATE creature_template SET mechanice_immune_mask = 1 WHERE entry = 17908;

#Makazradon Immune MC
UPDATE creature_template SET mechanice_immune_mask = 1 WHERE entry = 21501;


DELETE FROM gameobject WHERE id = 175570 AND map = 534;
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(182061, 534, 1, 4204.68, -4114.39, 877.761, 1.87458, 0, 0, 0.805957, 0.591974, 25, 100, 1);
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(182060, 534, 1, 4269.91, -4143.11, 870.084, 6.05215, 0, 0, 0.115263, -0.993335, 0, 100, 1);

#AZGALOR CRUSH
UPDATE creature_template SET flags_extra = 801 WHERE entry = 17842;


#SpawnTimes PNJ
UPDATE creature SET spawntimesecs = 86400 WHERE id BETWEEN 17919 AND 17922 OR id BETWEEN 17932 AND 17936 OR id = 17928;

#Infernal Relay Trigger
UPDATE creature_template set modelid_1 = 11686, modelid_2 = 11686 WHERE entry = 18242;

#================================ SEPARATOR DONE

#Speed Molten Flame
UPDATE creature_template SET modelid_1 = 11686 , modelid_2 = 11686, speed_walk = 0.9, speed_run = 0.9, ScriptName = "molten_flame" WHERE entry = 23095;

#Ai script Volcano
UPDATE creature_template SET ScriptName = "npc_volcano" WHERE entry = 23085;


