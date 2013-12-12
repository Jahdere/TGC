#TODO GT3
#RageFroid Immune Cast Interupt + immune taunt
UPDATE creature_template SET mechanic_immune_mask = 650854235, flags_extra = 769 WHERE entry = 17767;

#Anetheron target spell + cooldown + infernal immune taunt:
UPDATE creature_ai_scripts SET action1_param2 = 4 WHERE id = 1780802;
UPDATE creature_ai_scripts SET action1_param3 = 2 WHERE id = 1780803;
UPDATE creature_ai_scripts SET event_param1 = 20000, event_param2 = 30000, event_param3 = 55000, event_param4 = 65000 WHERE id = 1780804;

#Update somme immune taunt

#Anetheron
UPDATE creature_template SET flags_extra = 769 WHERE entry = 17808;

#Kaz'rogal
UPDATE creature_template SET flags_extra = 769 WHERE entry = 17888;

#Azgalor
UPDATE creature_template SET flags_extra = 769 WHERE entry = 17842;

#Archimonde
UPDATE creature_template SET flags_extra = 801 WHERE entry = 17968;

#Towering Infernal
DELETE FROM creature_ai_scripts WHERE creature_id = 17818;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(1781801, 17818, 11, 0, 100, 2, 0, 0, 0, 0, 11, 31302, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Towering Infernal - Cast Inferno Effect on Spawn'),
(1781802, 17818, 0, 0, 100, 2, 0, 500, 45000, 60000, 11, 31304, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Towering Infernal - Cast Immolation Aura');
UPDATE creature_template SET flags_extra = 256 WHERE entry = 17818;

#Lesser Doomguard
DELETE FROM creature_ai_scripts WHERE creature_id = 17864;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(1786401, 17864, 9, 0, 100, 3, 0, 45, 13000, 20000, 11, 31406, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Lesser Doomguard - Cast Cripple'),
(1786402, 17864, 0, 0, 100, 3, 7000, 11000, 11000, 18000, 11, 31408, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Lesser Doomguard - Cast War Stomp'),
(1786403, 17864, 11, 0, 100, 2, 0, 0, 0, 0, 11, 31607, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Lesser Doomguard - Cast Thrash on Spawn');

#Infernal helper
UPDATE creature_template SET ScriptName = 'npc_helper_giant' WHERE entry = 18242;

#Script scarab
UPDATE creature_template SET unit_flags = 33554434, mindmg = 400, maxdmg = 500 WHERE entry = 17967;

#Mines Spawn 
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(185557, 534, 1, 5236.75, -1950.55, 1367.76, 1.79398, 0, 0, 0.781452, 0.623966, -180, 100, 1),
(185557, 534, 1, 5271.9, -1914.41, 1357.98, 2.65006, 0, 0, 0.969952, 0.243298, -180, 100, 1),
(185557, 534, 1, 5182.05, -1998.97, 1376.87, 2.3359, 0, 0, 0.91995, 0.392036, -180, 100, 1),
(185557, 534, 1, 4929.78, -2037.17, 1400.69, 2.19453, 0, 0, 0.889964, 0.45603, -180, 100, 1),
(185557, 534, 1, 5049.71, -2046.92, 1377.68, 1.04786, 0, 0, 0.500286, 0.86586, -180, 100, 1),
(185557, 534, 1, 5313.08, -1946.62, 1351.7, 0.104575, 0, 0, 0.0522639, 0.998633, -180, 100, 1),
(185557, 534, 1, 5004.52, -2099.42, 1374.48, 2.6689, 0, 0, 0.9722, 0.23415, -180, 100, 1),
(185557, 534, 1, 5101.23, -2040.61, 1385.89, 2.64141, 0, 0, 0.96889, 0.247491, -180, 100, 1),
(185557, 534, 1, 5013.33, -2162.45, 1383.97, 3.09695, 0, 0, 0.999751, 0.0223187, -180, 100, 1),
(185557, 534, 1, 5412.5, -3333.82, 1651.07, 6.21399, 0, 0, 0.0345923, -0.999402, -180, 100, 1),
(185557, 534, 1, 5396.3, -3368.11, 1658.31, 2.58545, 0, 0, 0.961587, 0.2745, -180, 100, 1),
(185557, 534, 1, 5356.8, -3395.88, 1659.11, 1.7922, 0, 0, 0.780896, 0.62466, -180, 100, 1),
(185557, 534, 1, 5290.41, -3349.15, 1662.48, 1.76471, 0, 0, 0.772237, 0.635334, -180, 100, 1),
(185557, 534, 1, 5326.59, -3375.18, 1661.44, 1.07749, 0, 0, 0.513057, 0.858354, -180, 100, 1),
(185557, 534, 1, 5237.08, -3287.38, 1668.62, 1.07749, 0, 0, 0.513058, 0.858354, -180, 100, 1),
(185557, 534, 1, 5208.58, -3258.75, 1682.55, 0.943969, 0, 0, 0.454655, 0.890668, -180, 100, 1);

#Gargoyle AI
DELETE FROM creature_ai_scripts WHERE creature_id = 17906;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(1790601, 17906, 1, 0, 100, 2, 0, 0, 0, 0, 21, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 'Gargoyle - Prevent Combat Movement and Set Phase to 0 on Spawn'),
(1790602, 17906, 4, 0, 100, 2, 0, 0, 0, 0, 11, 31664, 1, 0, 23, 1, 0, 0, 0, 0, 0, 0, 'Gargoyle - Cast Gargoyle Strike and Set Phase 1 on Aggro'),
(1790603, 17906, 9, 5, 100, 3, 0, 25, 1500, 2500, 11, 31664, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Gargoyle - Gargoyle Strike (Phase 1)'),
(1790604, 17906, 9, 5, 100, 2, 30, 80, 0, 0, 21, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Gargoyle - Start Combat Movement at 30 Yards (Phase 1)'),
(1790605, 17906, 9, 5, 100, 2, 0, 25, 0, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Gargoyle - Prevent Combat Movement at 25 Yards (Phase 1)'),
(1790606, 17906, 7, 0, 100, 2, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Gargoyle - Set Phase to 0 on Evade');

#Frost Wyrm
#J'ai modifié une seule chose, mais pour être sur que les entrées soient les memes , je dump tout l'IA
DELETE FROM creature_ai_scripts WHERE creature_id = 17907;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(1790701, 17907, 1, 0, 100, 2, 0, 0, 0, 0, 21, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 'Frost Wyrm - Prevent Combat Movement and Set Phase to 0 on Spawn'),
(1790702, 17907, 4, 0, 100, 2, 0, 0, 0, 0, 11, 31688, 1, 0, 23, 1, 0, 0, 0, 0, 0, 0, 'Frost Wyrm - Cast Frost Breath and Set Phase 1 on Aggro'),
(1790703, 17907, 9, 5, 100, 3, 0, 35, 5000, 9000, 11, 31688, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Frost Wyrm - Cast Frost Breath (Phase 1)'),
(1790704, 17907, 3, 5, 100, 2, 7, 0, 0, 0, 21, 1, 0, 0, 23, 1, 0, 0, 0, 0, 0, 0, 'Frost Wyrm - Start Combat Movement and Set Phase 2 when Mana is at 7% (Phase 1)'),
(1790705, 17907, 9, 5, 100, 2, 30, 80, 0, 0, 21, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Frost Wyrm - Start Combat Movement at 30 Yards (Phase 1)'),
(1790706, 17907, 9, 5, 100, 2, 5, 25, 0, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Frost Wyrm - Prevent Combat Movement at 25 Yards (Phase 1)'),
(1790707, 17907, 9, 5, 100, 2, 0, 5, 0, 0, 21, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Frost Wyrm - Start Combat Movement Below 5 Yards (Phase 1)'),
(1790708, 17907, 3, 3, 100, 3, 100, 15, 100, 100, 23, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Frost Wyrm - Set Phase 1 when Mana is above 15% (Phase 2)'),
(1790709, 17907, 7, 0, 100, 2, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Frost Wyrm - Set Phase to 0 on Evade');