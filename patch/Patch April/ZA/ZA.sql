#ZUl aman SQL
# Amani'shi Tempest faction & dmg
UPDATE creature_template SET faction_H = 1890, faction_A = 1890, mindmg = 12500, maxdmg = 17000 WHERE entry = 24549;
# Amani'shi Lookout faction
UPDATE creature_template SET faction_H = 1890, faction_A = 1890 WHERE entry = 24175;
# Amani'shi Protector faction & dmg
UPDATE creature_template SET faction_H = 1890, faction_A = 1890, mindmg = 14313, maxdmg = 20438 WHERE entry = 24180;
# Amani'shi Wind Walker dmg
UPDATE creature_template SET mindmg = 11250, maxdmg = 13750 WHERE entry = 24179;
# Warriors
UPDATE creature_template SET faction_H = 1890, faction_A = 1890, mindmg = 10250, maxdmg = 15750 WHERE entry = 24225;


#Add mobs for event akil'zon
#WindWalker
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`) VALUES
(24179, 568, 1, 0, 2179, 224.01, 1433.98, 27.3209, 1.63383, 1800, 0, 0, 57000, 32310, 0, 0),
(24179, 568, 1, 0, 2179, 231.538, 1395.59, 39.7663, 1.56316, 1800, 0, 0, 57000, 32310, 0, 0),
(24179, 568, 1, 0, 2179, 249.237, 1364.29, 49.3218, 1.60635, 1800, 0, 0, 57000, 32310, 0, 0),
(24179, 568, 1, 0, 2179, 281.512, 1384.43, 49.3218, 3.38528, 1800, 0, 0, 57000, 32310, 0, 0);
#Protector
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`) VALUES
(140542, 24180, 568, 1, 0, 0, 232.901, 1433.97, 27.4457, 1.57101, 1800, 0, 0, 71000, 0, 0, 0),
(140544, 24180, 568, 1, 0, 0, 224.222, 1395.65, 39.6685, 1.57887, 1800, 0, 0, 71000, 0, 0, 0),
(140545, 24180, 568, 1, 0, 0, 249.832, 1370.44, 49.3216, 4.41808, 1800, 0, 0, 71000, 0, 0, 0),
(140548, 24180, 568, 1, 0, 0, 283.11, 1375.95, 49.3218, 3.2871, 1800, 0, 0, 71000, 0, 0, 0);
#Lookout
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`) VALUES
(140549, 24175, 568, 1, 0, 0, 228.554, 1460.39, 25.9168, 1.81055, 1800, 0, 0, 14000, 0, 0, 0);
#Tempest
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`) VALUES
(140539, 24549, 568, 1, 0, 0, 302.988, 1385.2, 57.3487, 3.3311, 1800, 0, 0, 140000, 0, 0, 0);