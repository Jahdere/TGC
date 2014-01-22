DELETE FROM creature_movement_template WHERE entry = 17711;
INSERT INTO `creature_movement_template` (`entry`, `point`, `position_x`, `position_y`, `position_z`, `waittime`, `script_id`, `textid1`, `textid2`, `textid3`, `textid4`, `textid5`, `emote`, `spell`, `wpguid`, `orientation`, `model1`, `model2`) VALUES
(17711,1,-3561.42,297.709,40.0321,0,0,0,0,0,0,0,0,0,0,1.54789,0,0),
(17711,2,-3538.16,305.597,41.1796,0,0,0,0,0,0,0,0,0,0,0.210355,0,0),
(17711,3,-3526.27,333.917,38.747,0,0,0,0,0,0,0,0,0,0,1.14498,0,0),
(17711,4,-3484.29,325.027,39.7747,20000,17711,0,0,0,0,0,0,0,0,0.112965,0,0),
(17711,5,-3530.71,325.109,39.7098,0,0,0,0,0,0,0,0,0,0,3.30953,0,0),
(17711,6,-3563.71,263.471,41.1716,0,0,0,0,0,0,0,0,0,0,4.20253,0,0),
(17711,7,-3563.4,219.333,44.3345,20000,17711,0,0,0,0,0,0,0,0,4.67377,0,0);

UPDATE creature_template SET `MovementType` = '2' WHERE `entry` = '17711'; 

DELETE FROM dbscripts_on_creature_movement WHERE id = 17711;
insert into `dbscripts_on_creature_movement` (`id`, `delay`, `command`, `datalong`, `datalong2`, `buddy_entry`, `search_radius`, `data_flags`, `dataint`, `dataint2`, `dataint3`, `dataint4`, `x`, `y`, `z`, `o`, `comments`) values('17711','0','15','36636','0','0','0','0','0','0','0','0','0','0','0','0','');



-- Spawn place/time
-- (84633,17711,530,1,0,0,-3563.34,233.887,44.1936,4.7331,86400,0,0,2276400,0,0,2),

-- .go xyz -3563.34 233.887 44.1936