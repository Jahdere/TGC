DELETE FROM creature_ai_scripts WHERE creature_id = 22882;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(2288201, 22882, 1, 0, 100, 2, 0, 0, 0, 0, 21, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Deathshaper - Prevent Combat Movement and Set Phase to 0 on Spawn'),
(2288202, 22882, 1, 0, 100, 3, 1000, 1000, 1800000, 1800000, 11, 13787, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Deathshaper - Cast Demon Armor on Spawn'),
(2288203, 22882, 4, 0, 100, 2, 0, 0, 0, 0, 11, 41069, 8, 0, 23, 1, 0, 0, 0, 0, 0, 0, 'Shadowmoon Deathshaper - Cast Shadow Bolt and Set Phase 1 on Aggro'),
(2288204, 22882, 9, 5, 100, 3, 0, 40, 4000, 5000, 11, 41069, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Deathshaper - Cast Shadow Bolt (Phase 1)'),
(2288205, 22882, 3, 5, 100, 2, 7, 0, 0, 0, 21, 1, 0, 0, 23, 1, 0, 0, 0, 0, 0, 0, 'Shadowmoon Deathshaper - Start Combat Movement and Set Phase 2 when Mana is at 7% (Phase 1)'),
(2288206, 22882, 9, 5, 100, 2, 35, 80, 0, 0, 21, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Deathshaper - Start Combat Movement at 35 Yards (Phase 1)'),
(2288207, 22882, 9, 5, 100, 2, 5, 15, 0, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Deathshaper - Prevent Combat Movement at 15 Yards (Phase 1)'),
(2288208, 22882, 9, 5, 100, 2, 0, 5, 0, 0, 21, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Deathshaper - Start Combat Movement Below 5 Yards (Phase 1)'),
(2288209, 22882, 3, 3, 100, 3, 100, 15, 100, 100, 23, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Deathshaper - Set Phase 1 when Mana is above 15% (Phase 2)'),
(2288210, 22882, 0, 0, 100, 3, 8000, 15000, 12000, 17000, 11, 41070, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Deathshaper - Cast Death Coil'),
(2288211, 22882, 5, 0, 100, 3, 15000, 15000, 0, 0, 11, 41071, 6, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Deathshaper - Cast Raise Dead on Player Kill'),
(2288212, 22882, 27, 0, 100, 3, 13787, 1, 15000, 30000, 11, 13787, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Deathshaper - Cast Demon Armor on Missing Buff'),
(2288213, 22882, 7, 0, 100, 2, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Shadowmoon Deathshaper - Set Phase to 0 on Evade');

DELETE FROM creature_ai_scripts WHERE creature_id = 22953;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(2295301, 22953, 9, 0, 100, 3, 0, 5, 7000, 10000, 11, 15496, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Wrathbone Flayer - Cast Cleave'),
(2295302, 22953, 0, 0, 100, 3, 10000, 13000, 16000, 21000, 11, 39544, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Wrathbone Flayer - Cast Ignored');


#Blades
DELETE FROM creature_template WHERE entry = 23369;
INSERT INTO `creature_template` (`entry`, `heroic_entry`, `KillCredit1`, `KillCredit2`, `modelid_1`, `modelid_2`, `modelid_3`, `modelid_4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `minhealth`, `maxhealth`, `minmana`, `maxmana`, `armor`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `PetSpellDataId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `unk16`, `unk17`, `RacialLeader`, `RegenHealth`, `equipment_id`, `trainer_id`, `vendor_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES
(23369, 0, 0, 0, 11686, 0, 11686, 0, 'Whirling Blade', '', NULL, 0, 71, 71, 201068, 201068, 0, 0, 7018, 14, 14, 0, 1, 1.14286, 2, 0, 2990, 4260, 0, 308, 1, 2000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 1096, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'EventAI', 0, 3, 1, 1, 0, 1, 440, 0, 0, 0, 2, '');
DELETE FROM creature_ai_scripts WHERE creature_id = 23369;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(2336901, 23369, 11, 0, 100, 0, 0, 0, 0, 0, 20, 1, 0, 0, 21, 1, 0, 0, 0, 0, 0, 0, 'Whirling Blade - Start Attack on Spawn'),
(2336902, 23369, 0, 0, 100, 3, 3000, 3000, 15000, 15000, 11, 41058, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Whirling Blade - Cast Whirlwind'),
(2336903, 23369, 0, 0, 100, 3, 13000, 13000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Whirling Blade - Despawn');

#Proc Event Absorb Spell
DELETE FROM spell_proc_event WHERE entry = 41034;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(41034, 127, 0, 0, 0, 0, 131072, 0, 0, 0, 0);

#Teron DoomBlossom
UPDATE creature_template SET ScriptName = 'npc_doomblossom' , AIName = '' WHERE entry = 23123;

#Immune taunt (Naj'entus, Supremus, Teron and Shade of akama, Gurtogg):
UPDATE creature_template SET flags_extra = 769 WHERE entry = 22898 OR entry = 22871 OR entry = 22887 OR entry =22841 OR entry = 22948;

#unit_flags
UPDATE creature_template SET unit_flags = 32832 WHERE entry = 23232 OR entry = 23236 OR entry = 23235 OR entry = 23237;

#Link Trashs
DELETE FROM creature_linking WHERE guid = 12751 OR guid = 12758 OR guid = 12823 OR guid = 12757 OR guid = 12839;
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12751', '12750', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12758', '12750', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12823', '12750', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12839', '12750', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12757', '12750', '3');

DELETE FROM creature_linking WHERE guid = 12753 OR guid = 12842 OR guid = 12759 OR guid = 12825 OR guid = 12841;
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12753', '12752', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12842', '12752', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12759', '12752', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12825', '12752', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12841', '12752', '3');

DELETE FROM creature_linking WHERE guid = 12747 OR guid = 12833 OR guid = 12820 OR guid = 12755 OR guid = 12834;
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12747', '12746', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12833', '12746', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12820', '12746', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12755', '12746', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12834', '12746', '3');

DELETE FROM creature_linking WHERE guid = 12749 OR guid = 12822 OR guid = 12837 OR guid = 12756 OR guid = 12838;
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12749', '12748', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12822', '12748', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12837', '12748', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12756', '12749', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12838', '12749', '3');

DELETE FROM creature_linking WHERE guid = 12744 OR guid = 12832 OR guid = 12754 OR guid = 12818 OR guid = 12831;
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12744', '12745', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12832', '12745', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12754', '12745', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12818', '12744', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12831', '12744', '3');

DELETE FROM creature_linking WHERE guid = 53227 OR guid = 53585 OR guid = 53235 OR guid = 53704 OR guid = 53211 OR guid = 53703;
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('53227', '53228', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('53585', '53228', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('53235', '53228', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('53704', '53228', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('53703', '53228', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('53211', '53228', '3');

DELETE FROM creature_linking WHERE guid = 53234 OR guid = 53216 OR guid = 53700 OR guid = 53701 OR guid = 53215 OR guid = 52308 OR guid = 53617;
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('53234', '53233', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('53216', '53233', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('53700', '53233', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('53701', '53233', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('53215', '53233', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('52308', '53233', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('53617', '53233', '3');

DELETE FROM creature_linking WHERE guid = 53699 OR guid = 53214 OR guid = 53688 OR guid = 53231 OR guid = 53213 OR guid = 53207 OR guid = 53206;
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('53699', '53232', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('53214', '53232', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('53688', '53232', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('53231', '53232', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('53213', '53232', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('53207', '53232', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('53206', '53232', '3');

DELETE FROM creature_linking WHERE guid = 12870 OR guid = 12874 OR guid = 12882;
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12870', '12877', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12874', '12877', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12882', '12877', '3');

DELETE FROM creature_linking WHERE guid = 52753 OR guid = 52752 OR guid = 52454 OR guid = 52758;
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('52753', '12871', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('52752', '12871', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('52454', '12871', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('52758', '12871', '3');

DELETE FROM creature_linking WHERE guid = 52745 OR guid = 52754 OR guid = 52744;
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('52745', '12883', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('52754', '12883', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('52744', '12883', '3');

DELETE FROM creature_linking WHERE guid = 12876 OR guid = 12875 OR guid = 52442 OR guid = 52444 OR guid = 52756 OR guid = 52757;
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12876', '12879', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12875', '12879', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('52442', '12879', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('52444', '12879', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('52756', '12879', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('52757', '12879', '3');

DELETE FROM creature_linking WHERE guid = 52746 OR guid = 12891 OR guid = 52747 OR guid = 12890;
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('52746', '52766', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12891', '52766', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('52747', '52766', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12890', '52766', '3');

DELETE FROM creature_linking WHERE guid = 12725 OR guid = 12722 OR guid = 12723 OR guid = 12724;
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12725', '12726', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12722', '12726', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12723', '12726', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12724', '12726', '3');

DELETE FROM creature_linking WHERE guid = 12880 OR guid = 12872 OR guid = 12873;
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12880', '12881', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12872', '12881', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12873', '12881', '3');

DELETE FROM creature_linking WHERE guid = 52749 OR guid = 13232 OR guid = 52748 OR guid = 13231;
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('52749', '12878', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('13232', '12878', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('52748', '12878', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('13231', '12878', '3');

DELETE FROM creature_linking WHERE guid = 52751 OR guid = 13233 OR guid = 13234 OR guid = 52750;
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('52751', '52767', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('13233', '52767', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('13234', '52767', '3');
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('52750', '52767', '3');

#Movement
DELETE FROM creature_linking WHERE guid = 12840;
DELETE FROM creature_movement WHERE id = 12827;
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12840', '12827', '512'), ('12824', '12827', '512');
INSERT INTO `creature_movement` (`id`, `point`, `position_x`, `position_y`, `position_z`, `waittime`, `script_id`, `textid1`, `textid2`, `textid3`, `textid4`, `textid5`, `emote`, `spell`, `wpguid`, `orientation`, `model1`, `model2`) VALUES
(12827, 1, 799.053, 280.951, 112.744, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.54331, 0, 0),
(12827, 2, 797.47, 370.238, 112.747, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4.6692, 0, 0);
UPDATE creature SET MovementType = 2 WHERE guid = 12827;

DELETE FROM creature_linking WHERE guid = 12821;
DELETE FROM creature_movement WHERE id = 12826;
INSERT INTO `creature_linking` (`guid`, `master_guid`, `flag`) VALUES ('12821', '12826', '512'), ('12835', '12826', '512');
INSERT INTO `creature_movement` (`id`, `point`, `position_x`, `position_y`, `position_z`, `waittime`, `script_id`, `textid1`, `textid2`, `textid3`, `textid4`, `textid5`, `emote`, `spell`, `wpguid`, `orientation`, `model1`, `model2`) VALUES
(12826, 1, 612.649, 265.696, 112.694, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.51588, 0, 0),
(12826, 2, 616.31, 379.466, 112.711, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4.6771, 0, 0);
UPDATE creature SET MovementType = 2 WHERE guid = 12826;

DELETE FROM creature_movement WHERE id = 52742;
INSERT INTO `creature_movement` (`id`, `point`, `position_x`, `position_y`, `position_z`, `waittime`, `script_id`, `textid1`, `textid2`, `textid3`, `textid4`, `textid5`, `emote`, `spell`, `wpguid`, `orientation`, `model1`, `model2`) VALUES
(52742, 1, 840.513, 66.7101, 112.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6.28162, 0, 0),
(52742, 2, 938.17, 66.9404, 112.752, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3.21071, 0, 0);
UPDATE creature SET MovementType = 2 WHERE guid = 52742;

DELETE FROM creature_movement WHERE id = 52741;
INSERT INTO `creature_movement` (`id`, `point`, `position_x`, `position_y`, `position_z`, `waittime`, `script_id`, `textid1`, `textid2`, `textid3`, `textid4`, `textid5`, `emote`, `spell`, `wpguid`, `orientation`, `model1`, `model2`) VALUES
(52741, 1, 825.088, 61.4225, 112.742, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.59753, 0, 0),
(52741, 2, 775.863, 62.4545, 112.738, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3.10942, 0, 0),
(52741, 3, 773.683, 131.154, 111.169, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.69177, 0, 0),
(52741, 4, 829.413, 129.706, 112.559, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2.98375, 0, 0);
UPDATE creature SET MovementType = 2 WHERE guid = 52741;

DELETE FROM creature_movement WHERE id = 52743;
INSERT INTO `creature_movement` (`id`, `point`, `position_x`, `position_y`, `position_z`, `waittime`, `script_id`, `textid1`, `textid2`, `textid3`, `textid4`, `textid5`, `emote`, `spell`, `wpguid`, `orientation`, `model1`, `model2`) VALUES
(52743, 1, 730.318, 131.139, 112.892, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.72318, 0, 0),
(52743, 2, 768.48, 136.102, 112.304, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3.17618, 0, 0),
(52743, 3, 767.344, 67.977, 112.738, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4.69985, 0, 0),
(52743, 4, 685.876, 68.6046, 112.752, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6.26279, 0, 0),
(52743, 5, 731.669, 64.8823, 113.264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.51113, 0, 0);
UPDATE creature SET MovementType = 2 WHERE guid = 52743;

DELETE FROM creature_movement WHERE id = 52739;
INSERT INTO `creature_movement` (`id`, `point`, `position_x`, `position_y`, `position_z`, `waittime`, `script_id`, `textid1`, `textid2`, `textid3`, `textid4`, `textid5`, `emote`, `spell`, `wpguid`, `orientation`, `model1`, `model2`) VALUES
(52739, 1, 888.155, 241.377, 86.1609, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.003498, 0, 0),
(52739, 2, 924.269, 243.236, 85.6413, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.054549, 0, 0),
(52739, 3, 925.962, 290.896, 85.6413, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4.66876, 0, 0);
UPDATE creature SET MovementType = 2 WHERE guid = 52739;

DELETE FROM creature_movement WHERE id = 52740;
INSERT INTO `creature_movement` (`id`, `point`, `position_x`, `position_y`, `position_z`, `waittime`, `script_id`, `textid1`, `textid2`, `textid3`, `textid4`, `textid5`, `emote`, `spell`, `wpguid`, `orientation`, `model1`, `model2`) VALUES
(52740, 1, 927.246, 154.468, 86.1521, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.88845, 0, 0),
(52740, 2, 889.852, 190.747, 86.161, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5.76832, 0, 0),
(52740, 3, 929.227, 227.877, 85.6413, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.690717, 0, 0),
(52740, 4, 961.626, 192.868, 86.1607, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3.33751, 0, 0);
UPDATE creature SET MovementType = 2 WHERE guid = 52740;

DELETE FROM creature_movement WHERE id = 53801;
INSERT INTO `creature_movement` (`id`, `point`, `position_x`, `position_y`, `position_z`, `waittime`, `script_id`, `textid1`, `textid2`, `textid3`, `textid4`, `textid5`, `emote`, `spell`, `wpguid`, `orientation`, `model1`, `model2`) VALUES
(53801, 1, 596.825, 111.457, 139.318, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3.19785, 0, 0),
(53801, 2, 516.727, 112.215, 164.771, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3.13501, 0, 0);
UPDATE creature SET MovementType = 2 WHERE guid = 53801;

DELETE FROM creature_movement WHERE id = 53800;
INSERT INTO `creature_movement` (`id`, `point`, `position_x`, `position_y`, `position_z`, `waittime`, `script_id`, `textid1`, `textid2`, `textid3`, `textid4`, `textid5`, `emote`, `spell`, `wpguid`, `orientation`, `model1`, `model2`) VALUES
(53800, 1, 596.825, 111.457, 139.318, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3.19785, 0, 0),
(53800, 2, 516.727, 112.215, 164.771, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3.13501, 0, 0);
UPDATE creature SET MovementType = 2 WHERE guid = 53800;

DELETE FROM creature_movement WHERE id = 53799;
INSERT INTO `creature_movement` (`id`, `point`, `position_x`, `position_y`, `position_z`, `waittime`, `script_id`, `textid1`, `textid2`, `textid3`, `textid4`, `textid5`, `emote`, `spell`, `wpguid`, `orientation`, `model1`, `model2`) VALUES
(53799, 1, 514.754, 171.034, 163.981, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4.63118, 0, 0),
(53799, 2, 512.748, 115.721, 164.771, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.45424, 0, 0),
(53799, 3, 511.855, 171.383, 163.981, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3.12321, 0, 0),
(53799, 4, 450.247, 169.243, 163.981, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.024815, 0, 0);
UPDATE creature SET MovementType = 2 WHERE guid = 53799;

DELETE FROM creature_movement WHERE id = 53798;
INSERT INTO `creature_movement` (`id`, `point`, `position_x`, `position_y`, `position_z`, `waittime`, `script_id`, `textid1`, `textid2`, `textid3`, `textid4`, `textid5`, `emote`, `spell`, `wpguid`, `orientation`, `model1`, `model2`) VALUES
(53798, 1, 514.754, 171.034, 163.981, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4.63118, 0, 0),
(53798, 2, 512.748, 115.721, 164.771, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.45424, 0, 0),
(53798, 3, 511.855, 171.383, 163.981, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3.12321, 0, 0),
(53798, 4, 450.247, 169.243, 163.981, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.024815, 0, 0);
UPDATE creature SET MovementType = 2 WHERE guid = 53798;

DELETE FROM creature_movement WHERE id = 53797;
INSERT INTO `creature_movement` (`id`, `point`, `position_x`, `position_y`, `position_z`, `waittime`, `script_id`, `textid1`, `textid2`, `textid3`, `textid4`, `textid5`, `emote`, `spell`, `wpguid`, `orientation`, `model1`, `model2`) VALUES
(53797, 1, 435.188, 222.1, 164.769, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4.79293, 0, 0),
(53797, 2, 436.253, 337.047, 192.775, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4.74224, 0, 0);
UPDATE creature SET MovementType = 2 WHERE guid = 53797;

DELETE FROM creature_movement WHERE id = 53796;
INSERT INTO `creature_movement` (`id`, `point`, `position_x`, `position_y`, `position_z`, `waittime`, `script_id`, `textid1`, `textid2`, `textid3`, `textid4`, `textid5`, `emote`, `spell`, `wpguid`, `orientation`, `model1`, `model2`) VALUES
(53796, 1, 435.188, 222.1, 164.769, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4.79293, 0, 0),
(53796, 2, 436.253, 337.047, 192.775, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4.74224, 0, 0);
UPDATE creature SET MovementType = 2 WHERE guid = 53796;