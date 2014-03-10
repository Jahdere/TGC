#Coeff spell data
#Rejuvenation
UPDATE spell_bonus_data SET dot_bonus = 0.2 WHERE entry = 774;
#Flame strike
UPDATE spell_bonus_data SET direct_bonus = 0.1761, dot_bonus = 0.0274 WHERE entry = 2120;
#Holy Fire
UPDATE spell_bonus_data SET direct_bonus = 0.8571 , dot_bonus = 0.033 WHERE entry = 14914;
#Lighting bolt
UPDATE spell_bonus_data SET direct_bonus = 0.794 WHERE entry = 403;
#Immolate
UPDATE spell_bonus_data SET dot_bonus = 0.13 WHERE entry = 348;
#Mana shield
UPDATE spell_bonus_data SET direct_bonus = 0.5 WHERE entry = 1463;


#PROC Cooldown
#Masquerade Gown
DELETE FROM spell_proc_event WHERE entry = 34584;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES ('34584', '127', '0', '0', '0', '0', '0', '0', '0', '0', '45');
#Robe of the Elder Scribes
DELETE FROM spell_proc_event WHERE entry = 34598;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES ('34598', '127', '0', '0', '0', '0', '0', '0', '0', '0', '45');
#Insightful Earthstorm Diamond
UPDATE spell_proc_event SET Cooldown = 15 WHERE entry = 27521;
#Mark of Defiance
DELETE FROM spell_proc_event WHERE entry = 33511;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES ('33511', '127', '0', '0', '0', '0', '0', '0', '0', '0', '15');
#Blade of Wizardry
DELETE FROM spell_proc_event WHERE entry = 38319;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES ('38319', '127', '0', '0', '0', '0', '0', '0', '0', '0', '15');
#Bangle of Endless Blessings
UPDATE  `spell_proc_event` SET  `Cooldown` =  '45' WHERE  `spell_proc_event`.`entry` = 38334;
