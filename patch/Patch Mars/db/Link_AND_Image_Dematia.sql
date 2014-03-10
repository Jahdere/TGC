DELETE FROM creature_linking_template WHERE master_entry = 22990;
INSERT INTO `creature_linking_template` (`entry`, `map`, `master_entry`, `flag`, `search_range`) VALUES
(23215, 564, 22990, 4112, 0),
(23216, 564, 22990, 4112, 0),
(23318, 564, 22990, 4112, 0),
(23523, 564, 22990, 4112, 0),
(23524, 564, 22990, 4112, 0);

DELETE FROM creature_ai_scripts WHERE creature_id = 22957;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(2295701, 22957, 0, 0, 100, 3, 5000, 8000, 12000, 18000, 11, 41397, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Priestess of Dementia - Cast Confusion'),
(2295702, 22957, 0, 0, 100, 3, 10000, 14000, 35000, 45000, 11, 41404, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Priestess of Dementia - Cast Dementia'),
(2295703, 22957, 0, 0, 100, 3, 10000, 15000, 30000, 40000, 12, 23436, 4, 20000, 0, 0, 0, 0, 0, 0, 0, 0, 'Priestess of Dementia - Summon image of dematia');

DELETE FROM creature_ai_scripts WHERE creature_id = 23436;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(2343601, 23436, 4, 0, 100, 2, 0, 0, 0, 0, 41, 20000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Image of Dementia - Delayed Despawn on Aggro'),
(2343602, 23436, 0, 0, 100, 3, 1000, 1000, 15000, 15000, 11, 41399, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Image of Dementia - Cast Whirlwind on Aggro');
