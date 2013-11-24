#BOSS SQL HYJAL

#Winterchill
DELETE FROM creature_ai_scripts WHERE creature_id = 17767;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(1776701, 17767, 4, 0, 100, 2, 0, 0, 0, 0, 1, -125, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Rage Winterchill - Yell on Aggro'),
(1776702, 17767, 0, 0, 100, 3, 5000, 9000, 9000, 15000, 11, 31249, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Rage Winterchill - Cast Icebolt'),
(1776703, 17767, 0, 0, 100, 3, 12000, 17000, 19000, 26000, 11, 31250, 1, 0, 1, -126, -127, 0, 0, 0, 0, 0, 'Rage Winterchill - Cast Frost Nova with Yells'),
(1776704, 17767, 0, 0, 100, 3, 21000, 28000, 35000, 45000, 11, 31258, 4, 1, 1, -128, -129, 0, 0, 0, 0, 0, 'Rage Winterchill - Cast Death and Decay with Yells'),
(1776705, 17767, 0, 0, 100, 3, 18000, 24000, 30000, 45000, 11, 31256, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Rage Winterchill - Cast Frost Armor'),
(1776706, 17767, 0, 0, 100, 3, 600000, 600000, 300000, 300000, 11, 26662, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Rage Winterchill - Enrage in 10 minutes'),
(1776707, 17767, 5, 0, 100, 3, 5000, 5000, 0, 0, 1, -130, -131, -112, 0, 0, 0, 0, 0, 0, 0, 0, 'Rage Winterchill - Random Yell on Player Kill'),
(1776708, 17767, 6, 0, 100, 2, 0, 0, 0, 0, 1, -132, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Rage Winterchill - Yell on Death');


#Anetheron
UPDATE creature_model_info SET bounding_radius = 6, combat_reach = 6 WHERE modelid = 21069;
DELETE FROM creature_ai_scripts WHERE creature_id = 17808;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(1780801, 17808, 4, 0, 100, 2, 0, 0, 0, 0, 1, -217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Anetheron - Yell on Aggro'),
(1780802, 17808, 0, 0, 100, 3, 20000, 28000, 10000, 15000, 11, 31306, 1, 0, 1, -222, -223, 0, 0, 0, 0, 0, 'Anetheron - Cast Carrion Swarm and Random Yell'),
(1780803, 17808, 0, 0, 100, 3, 25000, 32000, 35000, 48000, 11, 31298, 5, 1, 1, -224, -225, 0, 0, 0, 0, 0, 'Anetheron - Cast Sleep and Random Yell'),
(1780804, 17808, 0, 0, 100, 3, 30000, 48000, 60000, 80000, 11, 31299, 4, 1, 1, -226, -227, 0, 0, 0, 0, 0, 'Anetheron - Cast Inferno and Random Yell'),
(1780805, 17808, 0, 0, 100, 2, 3000, 11000, 26000, 35000, 11, 31317, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Anetheron - Cast Vampiric Aura'),
(1780806, 17808, 0, 0, 100, 3, 600000, 600000, 300000, 300000, 11, 26662, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Anetheron - Enrage After 10 Minutes'),
(1780807, 17808, 5, 0, 100, 3, 5000, 5000, 0, 0, 1, -218, -219, -220, 0, 0, 0, 0, 0, 0, 0, 0, 'Anetheron - Yell on Player Kill'),
(1780808, 17808, 6, 0, 100, 2, 0, 0, 0, 0, 1, -221, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Anetheron - Yell on Death');
#SLEEP
UPDATE creature_ai_scripts SET action1_param2 = 0 WHERE id =1780803;


#Kaz'Rogal
UPDATE creature_model_info SET bounding_radius = 5, combat_reach = 5 WHERE modelid = 17886;
DELETE FROM creature_ai_scripts WHERE creature_id = 17888;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(1788801, 17888, 4, 0, 100, 2, 0, 0, 0, 0, 1, -570, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Kaz''rogal - Yell on Aggro'),
(1788802, 17888, 9, 0, 100, 3, 0, 5, 6000, 21000, 11, 31436, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Kaz''rogal - Cast Malevolent Cleave'),
(1788803, 17888, 0, 0, 100, 3, 12000, 18000, 15000, 25000, 11, 31480, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Kaz''rogal - Cast War Stomp'),
(1788804, 17888, 0, 0, 100, 3, 6000, 11000, 10000, 12000, 11, 31477, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Kaz''rogal - Cast Cripple'),
(1788805, 17888, 0, 0, 100, 2, 45000, 45000, 0, 0, 11, 31447, 0, 4, 1, -571, -572, 0, 0, 0, 0, 0, 'Kaz''rogal - First Cast Mark Of Kaz''rogal and Random Yells'),
(1788806, 17888, 0, 0, 100, 2, 85000, 85000, 0, 0, 11, 31447, 0, 4, 1, -571, -572, 0, 0, 0, 0, 0, 'Kaz''rogal - Second Cast Mark Of Kaz''rogal and Random Yells'),
(1788807, 17888, 0, 0, 100, 2, 120000, 120000, 0, 0, 11, 31447, 0, 4, 1, -571, -572, 0, 0, 0, 0, 0, 'Kaz''rogal - Third Cast Mark Of Kaz''rogal and Random Yells'),
(1788808, 17888, 0, 0, 100, 2, 150000, 150000, 0, 0, 11, 31447, 0, 4, 1, -571, -572, 0, 0, 0, 0, 0, 'Kaz''rogal - Fourth Cast Mark Of Kaz''rogal and Random Yells'),
(1788809, 17888, 0, 0, 100, 2, 175000, 175000, 0, 0, 11, 31447, 0, 4, 1, -571, -572, 0, 0, 0, 0, 0, 'Kaz''rogal - Fifth Cast Mark Of Kaz''rogal and Random Yells'),
(1788810, 17888, 0, 0, 100, 2, 195000, 195000, 0, 0, 11, 31447, 0, 4, 1, -571, -572, 0, 0, 0, 0, 0, 'Kaz''rogal - Sixth Cast Mark Of Kaz''rogal and Random Yells'),
(1788811, 17888, 0, 0, 100, 3, 210000, 210000, 10000, 10000, 11, 31447, 0, 4, 1, -571, -572, 0, 0, 0, 0, 0, 'Kaz''rogal - Repeatable Cast Mark Of Kaz''rogal and Random Yells'),
(1788812, 17888, 5, 0, 100, 3, 5000, 5000, 0, 0, 1, -573, -574, -575, 0, 0, 0, 0, 0, 0, 0, 0, 'Kaz''rogal - Yell on Player Kill'),
(1788813, 17888, 6, 0, 100, 2, 0, 0, 0, 0, 4, 11018, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Kaz''rogal - Yell on Death');


#AZGALOR
DELETE FROM creature_ai_scripts WHERE creature_id = 17842;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(1784201, 17842, 4, 0, 100, 2, 0, 0, 0, 0, 1, -117, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Azgalor - Yell on Aggro (After 8th Wave)'),
(1784202, 17842, 9, 0, 100, 3, 0, 5, 10000, 16000, 11, 31345, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Azgalor - Cast Cleave'),
(1784203, 17842, 0, 0, 100, 3, 9000, 20000, 20000, 35000, 11, 31340, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Azgalor - Cast Rain of Fire'),
(1784204, 17842, 0, 0, 100, 3, 15000, 21000, 15000, 22000, 11, 31344, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Azgalor - Cast Howl of Azgalor'),
(1784205, 17842, 0, 0, 100, 3, 30000, 45000, 45000, 50000, 11, 31347, 5, 1, 1, -119, -199, 0, 0, 0, 0, 0, 'Azgalor - Cast Doom and Random Yell'),
(1784206, 17842, 0, 0, 100, 3, 600000, 600000, 300000, 300000, 11, 26662, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Azgalor - Enrage After 10 Minutes'),
(1784207, 17842, 5, 0, 100, 3, 5000, 5000, 0, 0, 1, -118, -120, -122, 0, 0, 0, 0, 0, 0, 0, 0, 'Azgalor - Random Yell on Player Kill'),
(1784208, 17842, 6, 0, 100, 2, 0, 0, 0, 0, 1, -121, 0, 0, 12, 13083, 0, 35000, 0, 0, 0, 0, 'Azgalor - Yell and Spawn Echo of Archimonde on Death');

#Archimonde
UPDATE creature_model_info SET bounding_radius = 17 , combat_reach = 17 WHERE modelid = 18292;
UPDATE creature_template SET scale = 0.4 WHERE entry = 17968;
UPDATE creature_template SET unit_flags = 33685506 WHERE entry = 18095;