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

#SET DMG BT trashs
UPDATE  `creature_template` SET  `mindmg` = '20962' WHERE  `creature_template`.`entry` =17968;
UPDATE  `creature_template` SET `mindmg` = '10416',  `maxdmg` =  '11793' WHERE  `creature_template`.`entry` =22874;
UPDATE  `creature_template` SET `mindmg` = '15015',  `maxdmg` =  '15844' WHERE  `creature_template`.`entry` =22885;
UPDATE  `creature_template` SET `mindmg` = '6434',  `maxdmg` =  '7536' WHERE  `creature_template`.`entry` =22875;
UPDATE  `creature_template` SET `mindmg` = '13040',  `maxdmg` =  '14574' WHERE  `creature_template`.`entry` =22884;
UPDATE  `creature_template` SET `mindmg` = '13875',  `maxdmg` =  '15942' WHERE  `creature_template`.`entry` =22877;
UPDATE  `creature_template` SET `mindmg` = '10561',  `maxdmg` =  '11357', `mechanic_immune_mask` = '650854235' WHERE  `creature_template`.`entry` =22878;
UPDATE  `creature_template` SET `mindmg` = '6434',  `maxdmg` =  '8536' WHERE  `creature_template`.`entry` =22876;
UPDATE  `creature_template` SET `mindmg` = '15382',  `maxdmg` =  '17310' WHERE  `creature_template`.`entry` =22960;
UPDATE  `creature_template` SET `mindmg` = '6434',  `maxdmg` =  '9536' WHERE  `creature_template`.`entry` =23030;
UPDATE  `creature_template` SET `mindmg` = '10398',  `maxdmg` =  '12052' WHERE  `creature_template`.`entry` =23028;
UPDATE  `creature_template` SET `mindmg` = '1967',  `maxdmg` =  '2238' WHERE  `creature_template`.`entry` =22963;
UPDATE  `creature_template` SET `mindmg` = '16007',  `maxdmg` =  '18009', `mechanic_immune_mask` = '650854235' WHERE  `creature_template`.`entry` =22954;
UPDATE  `creature_template` SET `mindmg` = '11508' WHERE  `creature_template`.`entry` =22887;
UPDATE  `creature_template` SET `mindmg` = '15414', `maxdmg` =  '19741', `speed_walk` = '2.4', `speed_run` = '2.14286' WHERE  `creature_template`.`entry` =22898;
UPDATE  `creature_template` SET `mindmg` = '6441',  `maxdmg` =  '8406' WHERE  `creature_template`.`entry` =23330;

