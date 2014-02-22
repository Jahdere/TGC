#Molten Flame
DELETE FROM creature_template WHERE entry = 23095;
INSERT INTO `creature_template` (`entry`, `heroic_entry`, `KillCredit1`, `KillCredit2`, `modelid_1`, `modelid_2`, `modelid_3`, `modelid_4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `minhealth`, `maxhealth`, `minmana`, `maxmana`, `armor`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `PetSpellDataId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `unk16`, `unk17`, `RacialLeader`, `RegenHealth`, `equipment_id`, `trainer_id`, `vendor_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES
(23095, 0, 0, 0, 11686, 0, 11686, 0, 'Supremus Punch Invis Stalker', '', NULL, 0, 73, 73, 1, 1, 0, 0, 0, 14, 14, 0, 1, 0.9, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 33554434, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 1024, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 0, 1, 0, 0, 0, 0, 0, 'molten_flame');

#Script Volcano
DELETE FROM creature_template WHERE entry = 23085;
INSERT INTO `creature_template` (`entry`, `heroic_entry`, `KillCredit1`, `KillCredit2`, `modelid_1`, `modelid_2`, `modelid_3`, `modelid_4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `minhealth`, `maxhealth`, `minmana`, `maxmana`, `armor`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `PetSpellDataId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `unk16`, `unk17`, `RacialLeader`, `RegenHealth`, `equipment_id`, `trainer_id`, `vendor_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES
(23085, 0, 0, 0, 21583, 0, 21583, 0, 'Supremus Volcano', '', NULL, 0, 73, 73, 1, 1, 0, 0, 0, 14, 14, 0, 1, 1.28968, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 1024, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 0, 1, 0, 0, 0, 0, 0, 'npc_volcano');

#IA
DELETE FROM creature_ai_scripts WHERE creature_id = 22874;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(2287401, 22874, 9, 0, 100, 3, 0, 80, 12000, 19000, 11, 40084, 1, 32, 0, 0, 0, 0, 0, 0, 0, 0, 'Coilskar Harpooner - Cast Harpooner''s Mark'),
(2287402, 22874, 9, 0, 100, 3, 0, 10, 21000, 35000, 11, 40082, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Coilskar Harpooner - Cast Hooked Net'),
(2287403, 22874, 0, 0, 100, 3, 5000, 9000, 13000, 18000, 11, 40083, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Coilskar Harpooner - Cast Spear Throw');

DELETE FROM creature_ai_scripts WHERE creature_id = 22885;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(2288501, 22885, 9, 0, 100, 3, 0, 45, 4000, 6000, 11, 40086, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Dragon Turtle - Cast Water Spit'),
(2288502, 22885, 2, 0, 100, 3, 50, 0, 30000, 40000, 11, 40087, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Dragon Turtle - Cast Shell Shield at 50% HP');

DELETE FROM creature_ai_scripts WHERE creature_id = 22873;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(2287301, 22873, 11, 0, 100, 2, 0, 0, 0, 0, 11, 29651, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Coilskar General - Cast Dual Wield on Spawn'),
(2287302, 22873, 0, 0, 100, 3, 1000, 3000, 40000, 48000, 11, 40080, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Coilskar General - Cast Booming Voice'),
(2287303, 22873, 0, 0, 100, 3, 16000, 30000, 24000, 35000, 11, 40081, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Coilskar General - Cast Free Friend');

DELETE FROM creature_ai_scripts WHERE creature_id = 22877;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(2287701, 22877, 9, 0, 100, 3, 0, 5, 7000, 11000, 11, 15284, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Coilskar Wrangler - Cast Cleave'),
(2287702, 22877, 0, 0, 100, 3, 18000, 27000, 28000, 35000, 11, 40066, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Coilskar Wrangler - Cast Lightning Prod'),
(2287703, 22877, 0, 0, 100, 3, 15000, 20000, 30000, 45000, 11, 40076, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Coilskar Wrangler - Cast Electric Spur on Nearby Leviathan Units');

DELETE FROM creature_ai_scripts WHERE creature_id = 22960;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(2296001, 22960, 9, 0, 100, 3, 0, 5, 7000, 12000, 11, 15284, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Dragonmaw Wyrmcaller - Cast Cleave'),
(2296002, 22960, 9, 0, 100, 3, 0, 5, 9000, 14000, 11, 40895, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Dragonmaw Wyrmcaller - Cast Jab'),
(2296003, 22960, 0, 0, 100, 3, 8000, 15000, 30000, 40000, 11, 40892, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Dragonmaw Wyrmcaller - Cast Fixate');

DELETE FROM creature_ai_scripts WHERE creature_id = 22964;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(2296401, 22964, 11, 0, 100, 2, 0, 0, 0, 0, 11, 41362, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Sister of Pleasure - Cast Shared Bonds on Spawn'),
(2296402, 22964, 9, 0, 100, 3, 0, 8, 11000, 17000, 11, 41380, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Sister of Pleasure - Cast Holy Nova'),
(2296403, 22964, 14, 0, 100, 3, 100000, 40, 21000, 27000, 11, 41378, 6, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Sister of Pleasure - Cast Greater Heal on Friendlies'),
(2296404, 22964, 2, 0, 100, 3, 20, 0, 30000, 45000, 11, 41381, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Sister of Pleasure - Cast Shell of Life at 20% HP');

#HitBox
UPDATE  `creature_model_info` SET  `combat_reach` =  '20', `bounding_radius` =  '21' WHERE  `creature_model_info`.`modelid` =21145;
UPDATE  `creature_model_info` SET  `bounding_radius` =  '4', `combat_reach` =  '10.5' WHERE  `creature_model_info`.`modelid` =21174;

# =====================================================================

DELETE FROM creature_ai_scripts WHERE creature_id = 23030;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(2303001, 23030, 1, 0, 100, 2, 0, 0, 0, 0, 21, 0, 0, 0, 20, 0, 0, 0, 23, 1, 0, 0, 'Dragonmaw Sky Stalker - Prevent Combat Movement and Prevent Melee and Set Phase 1 on Spawn'),
(2303002, 23030, 9, 1, 100, 3, 0, 40, 2000, 3000, 11, 40873, 4, 0, 40, 2, 0, 0, 0, 0, 0, 0, 'Dragonmaw Sky Stalker - Cast Shoot and Set Ranged Weapon Model (Phase 1)'),
(2303003, 23030, 9, 1, 100, 3, 0, 60, 11000, 13000, 11, 40872, 4, 1, 40, 2, 0, 0, 0, 0, 0, 0, 'Dragonmaw Sky Stalker - Cast Immolation Arrow and Set Ranged Weapon Model (Phase 1)'),
(2303004, 23030, 9, 1, 100, 3, 40, 100, 0, 0, 21, 1, 1, 0, 20, 1, 0, 0, 0, 0, 0, 0, 'Dragonmaw Sky Stalker - Start Combat Movement and Start Melee at 40 Yards (Phase 1)'),
(2303005, 23030, 9, 1, 100, 3, 0, 10, 0, 0, 21, 1, 0, 0, 40, 1, 0, 0, 20, 1, 0, 0, 'Dragonmaw Sky Stalker - Start Combat Movement and Set Melee Weapon Model and Start Melee Below 10 Yards (Phase 1)'),
(2303006, 23030, 9, 1, 100, 3, 11, 35, 0, 0, 21, 0, 1, 0, 20, 0, 0, 0, 0, 0, 0, 0, 'Dragonmaw Sky Stalker - Prevent Combat Movement and Prevent Melee at 35 Yards (Phase 1)'),
(2303007, 23030, 7, 0, 100, 2, 0, 0, 0, 0, 22, 1, 0, 0, 40, 1, 0, 0, 0, 0, 0, 0, 'Dragonmaw Sky Stalker - Set Phase 1 and Set Melee Weapon Model on Evade');

DELETE FROM creature_ai_scripts WHERE creature_id = 22875;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(2287501, 22875, 9, 0, 100, 3, 0, 30, 4000, 5000, 11, 40088, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Coilskar Sea-Caller - Cast Forked Lightning'),
(2287502, 22875, 0, 0, 100, 3, 8000, 10000, 20000, 30000, 11, 40090, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Coilskar Sea-Caller - Cast Hurricane'),
(2287503, 22875, 0, 0, 100, 3, 60000, 75000, 14000, 19000, 11, 40091, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Coilskar Sea-Caller - Summon Geyser');

DELETE FROM creature_ai_scripts WHERE creature_id = 22885;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(2288501, 22885, 9, 0, 100, 3, 0, 45, 6000, 8000, 11, 40086, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Dragon Turtle - Cast Water Spit'),
(2288502, 22885, 2, 0, 100, 3, 50, 0, 30000, 40000, 11, 40087, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Dragon Turtle - Cast Shell Shield at 50% HP');

DELETE FROM creature_ai_scripts WHERE creature_id = 22884;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(2288401, 22884, 9, 0, 100, 3, 0, 30, 4000, 7000, 11, 40078, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Leviathan - Cast Poison Spit'),
(2288402, 22884, 9, 0, 100, 3, 0, 45, 7000, 13000, 11, 40079, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Leviathan - Cast Debilitating Spray'),
(2288403, 22884, 0, 0, 100, 3, 9000, 14000, 12000, 15000, 11, 40077, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Leviathan - Cast Tail Sweep');

DELETE FROM creature_ai_scripts WHERE creature_id = 22877;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(2287701, 22877, 9, 0, 100, 3, 0, 5, 7000, 11000, 11, 15284, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Coilskar Wrangler - Cast Cleave'),
(2287702, 22877, 0, 0, 100, 3, 18000, 27000, 28000, 35000, 11, 40066, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Coilskar Wrangler - Cast Lightning Prod'),
(2287703, 22877, 0, 0, 100, 3, 8000, 12000, 20000, 30000, 11, 40076, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Coilskar Wrangler - Cast Electric Spur on Nearby Leviathan Units');

#Archimonde mindmg perfect
UPDATE  `creature_template` SET  `mindmg` =  '21462' WHERE  `creature_template`.`entry` =17968;

#SET DMG BT trashs
UPDATE  `creature_template` SET  `mindmg` =  '20962' WHERE  `creature_template`.`entry` =17968;
UPDATE  `creature_template` SET `mindmg` = '12916',  `maxdmg` =  '14293' WHERE  `creature_template`.`entry` =22874;
UPDATE  `creature_template` SET `mindmg` = '17515',  `maxdmg` =  '18344' WHERE  `creature_template`.`entry` =22885;
UPDATE  `creature_template` SET `mindmg` = '8934',  `maxdmg` =  '10036' WHERE  `creature_template`.`entry` =22875;
UPDATE  `creature_template` SET `mindmg` = '15540',  `maxdmg` =  '17074' WHERE  `creature_template`.`entry` =22884;
UPDATE  `creature_template` SET `mindmg` = '16375',  `maxdmg` =  '18442' WHERE  `creature_template`.`entry` =22877;
UPDATE  `creature_template` SET `mindmg` = '13061',  `maxdmg` =  '13857', `mechanic_immune_mask` = '650854235' WHERE  `creature_template`.`entry` =22878;
UPDATE  `creature_template` SET `mindmg` = '8934',  `maxdmg` =  '11036' WHERE  `creature_template`.`entry` =22876;
UPDATE  `creature_template` SET `mindmg` = '18882',  `maxdmg` =  '20810' WHERE  `creature_template`.`entry` =22960;
UPDATE  `creature_template` SET `mindmg` = '8934',  `maxdmg` =  '12036' WHERE  `creature_template`.`entry` =23030;
UPDATE  `creature_template` SET `mindmg` = '12898',  `maxdmg` =  '14552' WHERE  `creature_template`.`entry` =23028;
UPDATE  `creature_template` SET `mindmg` = '1967',  `maxdmg` =  '2238' WHERE  `creature_template`.`entry` =22963;
UPDATE  `creature_template` SET `mindmg` = '20507',  `maxdmg` =  '22609', `mechanic_immune_mask` = '650854235' WHERE  `creature_template`.`entry` =22954;
UPDATE  `creature_template` SET `mindmg` = '12508' WHERE  `creature_template`.`entry` =22887;
UPDATE  `creature_template` SET `mindmg` = '15414', `maxdmg` =  '20741', `speed_walk` = '2.4', `speed_run` = '2.14286' WHERE  `creature_template`.`entry` =22887;
UPDATE  `creature_template` SET `mindmg` = '8441',  `maxdmg` =  '9406' WHERE  `creature_template`.`entry` =23330;


INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('17854', '534', '17852', '4112', '0');

