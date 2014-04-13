#Gurtogg Link Trashs
DELETE FROM `creature_linking_template` WHERE `master_entry` = 22948;
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('23196', '564', '22948', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('23236', '564', '22948', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('23235', '564', '22948', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('23237', '564', '22948', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('23222', '564', '22948', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('23239', '564', '22948', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('23223', '564', '22948', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('23232', '564', '22948', '1024', '0');

#Teron Link Trashs
DELETE FROM `creature_linking_template` WHERE `master_entry` = 22871;
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('23172', '564', '22871', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('22945', '564', '22871', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('22880', '564', '22871', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('22882', '564', '22871', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('23147', '564', '22871', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('22879', '564', '22871', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('23047', '564', '22871', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('23049', '564', '22871', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('22953', '564', '22871', '1024', '0');

#Reliquary of Souls Link Trashs
DELETE FROM `creature_linking_template` WHERE `master_entry` = 22856;
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('23398', '564', '22856', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('23401', '564', '22856', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('23399', '564', '22856', '1024', '0');

#Mother Shahraz Link Trashs
DELETE FROM `creature_linking_template` WHERE `master_entry` = 22947;
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('22957', '564', '22947', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('22962', '564', '22947', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('22956', '564', '22947', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('22964', '564', '22947', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('22955', '564', '22947', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('22959', '564', '22947', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('22965', '564', '22947', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('22939', '564', '22947', '1024', '0');

#Illidari Link Trashs
DELETE FROM `creature_linking_template` WHERE `master_entry` = 22950;
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('23400', '564', '22950', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('23403', '564', '22950', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('23402', '564', '22950', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('23397', '564', '22950', '1024', '0');
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES ('23394', '564', '22950', '1024', '0');




#All trash respawn after 2 hours
UPDATE creature SET spawntimesecs = 7200 WHERE spawntimesecs = 3600 AND map = 564;


#Shahraz trash Linking pack
DELETE FROM `creature_linking` WHERE `guid` = 52906 OR `guid` = 52856;
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('52906', '52858', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('52856', '52905', '3');

#Illidari trash linking pack
DELETE FROM `creature_linking` WHERE `guid` = 52433 OR `guid` = 16197 OR `guid` = 52439 OR `guid` = 16198 OR `guid` = 52438;
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('52433', '52417', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('16197', '52417', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('52439', '52417', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('16198', '52417', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('52438', '52417', '3');


#Shahraz Trash Dmg
UPDATE creature_template SET mindmg = 25769 , maxdmg = 33667 WHERE entry = 22962;
UPDATE creature_template SET mindmg = 18140 , maxdmg = 24513 WHERE entry = 22957;
UPDATE creature_template SET mindmg = 20052 , maxdmg = 24055 WHERE entry = 22964;
UPDATE creature_template SET mindmg = 21052 , maxdmg = 26055 WHERE entry = 22956;
UPDATE creature_template SET mindmg = 14444 , maxdmg = 16959 WHERE entry = 22959;
UPDATE creature_template SET mindmg = 16999 , maxdmg = 18814 WHERE entry = 22965;

#Illidari Trash Dmg
UPDATE creature_template SET mindmg = 22461 , maxdmg = 29926 WHERE entry = 23394;
UPDATE creature_template SET mindmg = 22515 , maxdmg = 28506 WHERE entry = 23397;
UPDATE creature_template SET mindmg = 14701 , maxdmg = 19703 WHERE entry = 23402;
UPDATE creature_template SET mindmg = 17423 , maxdmg = 21129 WHERE entry = 23403;
UPDATE creature_template SET mindmg = 12701 , maxdmg = 16703 WHERE entry = 23400;

#Movement Trashs
DELETE FROM creature_movement WHERE id = 12884;
INSERT INTO `creature_movement` (`id`, `point`, `position_x`, `position_y`, `position_z`, `waittime`, `script_id`, `textid1`, `textid2`, `textid3`, `textid4`, `textid5`, `emote`, `spell`, `wpguid`, `orientation`, `model1`, `model2`) VALUES
(12884, 1, 812.578, 122.974, 204.768, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.54047, 0, 0),
(12884, 2, 813.018, 173.542, 204.768, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4.68206, 0, 0),
(12884, 3, 761.628, 171.713, 218.486, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6.28034, 0, 0),
(12884, 4, 759.954, 125.854, 218.485, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.38731, 0, 0),
(12884, 5, 814.161, 123.491, 204.768, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.55618, 0, 0);

DELETE FROM creature_movement WHERE id = 12889;
INSERT INTO `creature_movement` (`id`, `point`, `position_x`, `position_y`, `position_z`, `waittime`, `script_id`, `textid1`, `textid2`, `textid3`, `textid4`, `textid5`, `emote`, `spell`, `wpguid`, `orientation`, `model1`, `model2`) VALUES
(12889, 1, 705.942, 123.731, 232.065, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.56402, 0, 0),
(12889, 2, 708.577, 173.246, 232.001, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.49726, 0, 0),
(12889, 3, 659.375, 176.045, 245.553, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4.56817, 0, 0),
(12889, 4, 657.352, 126.382, 245.463, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4.69383, 0, 0),
(12889, 5, 707.257, 124.164, 232.055, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6.25677, 0, 0);

DELETE FROM creature_movement WHERE id = 12888;
INSERT INTO `creature_movement` (`id`, `point`, `position_x`, `position_y`, `position_z`, `waittime`, `script_id`, `textid1`, `textid2`, `textid3`, `textid4`, `textid5`, `emote`, `spell`, `wpguid`, `orientation`, `model1`, `model2`) VALUES
(12888, 1, 547.433, 301.661, 271.384, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4.64522, 0, 0),
(12888, 2, 548.344, 181.912, 258.736, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4.73161, 0, 0);

DELETE FROM creature_movement WHERE id = 12886;
INSERT INTO `creature_movement` (`id`, `point`, `position_x`, `position_y`, `position_z`, `waittime`, `script_id`, `textid1`, `textid2`, `textid3`, `textid4`, `textid5`, `emote`, `spell`, `wpguid`, `orientation`, `model1`, `model2`) VALUES
(12886, 1, 576.97, 149.289, 258.44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6.25922, 0, 0),
(12886, 2, 654.964, 150.647, 245.327, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6.271, 0, 0);

#AiScript Assassin :
DELETE FROM creature_ai_scripts WHERE creature_id = 23403;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(2340301, 23403, 9, 0, 100, 3, 0, 5, 11000, 15000, 11, 3609, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Illidari Assassin - Cast Paralyzing Poison'),
(2340302, 23403, 0, 0, 100, 3, 9000, 15000, 9000, 12000, 11, 39667, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Illidari Assassin - Cast Vanish'),
(2340303, 23403, 0, 0, 100, 3, 7000, 8000, 15000, 25000, 11, 41392, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Illidari Assassin - Cast Riposte');