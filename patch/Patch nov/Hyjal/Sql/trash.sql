#Crypt Fiend & Crypt Scarab
DELETE FROM creature_ai_scripts WHERE creature_id = 17897;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(1789701, 17897, 9, 0, 100, 3, 0, 10, 10000, 14000, 11, 28991, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Crypt Fiend - Cast Web'),
(1789702, 17897, 9, 0, 100, 3, 0, 20, 5000, 6000, 11, 31591, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Crypt Fiend - Cast Crypt Scarabs');
UPDATE creature_template SET faction_A = 1720, faction_H = 1720, speed_run = 3, speed_walk = 3, mindmg = 300, maxdmg = 300, minlevel = 70, maxlevel = 70, AIName = 'EventAI' WHERE entry = 17967;
INSERT INTO creature_ai_scripts (id, creature_id, event_type, event_chance, event_flags, event_param2, event_param4, action1_type, comment) VALUES(1796701, 17967, 9, 100, 3, 4, 1000, 41, 'Crypt Scarab - Despawn after hit');

#Ghoul Cannibalize
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`, `inverseEffectMask`) VALUES ('31538', '1', '17895', '0');
DELETE FROM `creature_ai_scripts` WHERE creature_id = 17895;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(1789501, 17895, 0, 0, 100, 3, 3000, 7000, 15000, 25000, 11, 31540, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Ghoul - Cast Frenzy'),
(1789502, 17895, 2, 0, 100, 2, 7, 0, 0, 0, 11, 31537, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Ghoul - Cast Cannibalize at 7% HP');

#Abomination
DELETE FROM creature_ai_scripts WHERE creature_id = 17898;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(1789801, 17898, 11, 0, 100, 2, 0, 0, 0, 0, 11, 31607, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Abomination - Cast Disease Cloud on Spawn'),
(1789802, 17898, 9, 0, 100, 3, 0, 5, 12000, 19000, 11, 31610, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Abomination - Cast Knockdown'),
(1789803, 17898, 7, 0, 100, 2, 0, 0, 0, 0, 11, 31607, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Abomination - Cast Disease Cloud on Evade');

#GARGOYLE
DELETE FROM creature_ai_scripts WHERE creature_id = 17906;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(1790601, 17906, 9, 0, 100, 3, 0, 35, 1500, 2000, 11, 31664, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Gargoyle - Cast Frappe de la gargouille (Phase 1)');

UPDATE creature_template SET InhabitType = 5 WHERE entry = 17906;

#Wyrm
UPDATE creature_template SET InhabitType = 5 WHERE entry = 17907;

#Fel stalker
DELETE FROM creature_ai_scripts WHERE creature_id = 17916;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(1791601, 17916, 9, 0, 100, 3, 0, 30, 10000, 15000, 11, 31729, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Fel Stalker - Cast Mana Burn');

#Necro Spells Raise Dead
INSERT INTO spell_script_target (entry, type, targetEntry) VALUES (31625, 2, 17895), (31624, 2, 17895), (31617, 2, 17895);
DELETE FROM creature_ai_scripts WHERE creature_id = 17899;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(1789901, 17899, 0, 0, 100, 3, 6000, 10000, 9000, 16000, 11, 31627, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Shadowy Necromancer - Cast Shadow Bolt'),
(1789902, 17899, 0, 0, 100, 3, 5000, 15000, 45000, 60000, 30, 1, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 'Shadowy Necromancer - Random Phase'),
(1789903, 17899, 0, 13, 100, 2, 0, 0, 0, 0, 11, 31617, 0, 1, 22, 0, 0, 0, 0, 0, 0, 0, 'Shadowy Necromancer - Cast Raise Dead On Ghoul Kill and Set Phase Back To 0 (Phase 1)'),
(1789904, 17899, 0, 11, 100, 2, 0, 0, 0, 0, 11, 31624, 0, 1, 22, 0, 0, 0, 0, 0, 0, 0, 'Shadowy Necromancer - Cast Raise Dead On Ghoul kill and Set Phase Back To 0 (Phase 2)'),
(1789905, 17899, 0, 7, 100, 2, 0, 0, 0, 0, 11, 31625, 0, 1, 22, 0, 0, 0, 0, 0, 0, 0, 'Shadowy Necromancer - Cast Raise Dead On Ghoul kill and Set Phase Back To 0 (Phase 3)'),
(1789906, 17899, 7, 0, 100, 2, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Shadowy Necromancer - Set Phase To 0 On Evade'),
(1789907, 17899, 0, 0, 100, 3, 10000, 15000, 30000, 45000, 11, 31626, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Shadowy Necromancer - Unholy Frenzy');


#Skeleton Mage (17903)
#Skeleton Invader (17902)
UPDATE creature_template SET faction_H = 1720, faction_A = 1720 WHERE entry = 17903 OR entry = 17902;

#Banshee
DELETE FROM creature_ai_scripts WHERE creature_id = 17905;
INSERT INTO creature_ai_scripts (id, creature_id, event_type, event_inverse_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action1_type, action1_param1, action1_param2, action1_param3, action2_type, action2_param1, action2_param2, action2_param3, action3_type, action3_param1, action3_param2, action3_param3, comment) VALUES
(1790501, 17905, 9, 0, 100, 3, 0, 30, 18000, 24000, 11, 31651, 4, 33, 0, 0, 0, 0, 0, 0, 0, 0, 'Banshee - Cast Banshee Curse'),
(1790502, 17905, 0, 0, 100, 3, 7000, 11000, 11000, 16000, 11, 38183, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Banshee - Cast Banshee Wail'),
(1790503, 17905, 0, 0, 100, 3, 15000, 20000, 60000, 90000, 11, 31662, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Banshee - Cast Anti-Magic Shell');


#Avec X = LAST ID EQUIPMENT
#Hunt Horde equipment
#INSERT INTO creature_equip_template (`entry`, `equipentry1`, `equipentry2`, `equipentry3`) VALUES ('X', '2522', '2522', '28537');
#UPDATE creature_template SET `equipment_id`='X' WHERE `entry`='17934';