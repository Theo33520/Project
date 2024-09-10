/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pokemon
*/

#include "rpg.h"

bool check_habitat(t_map *map)
{
    sfBool is_well = false;
    unsigned int well = is_hopital(map);
    unsigned int well_house1 = is_house1(map);
    unsigned int well_house2 = is_house2(map);
    unsigned int well_house3 = is_house3(map);
    unsigned int well_pokecent = is_pokecenter(map);
    if (well == 1 || well_house1 == 1 || well_house2 == 1 ||
    well_house3 == 1 || well_pokecent == 1)
        return is_well = true;
    return is_well = false;
}

bool collison_up(t_map *map)
{
    sfVector2f players_pos = sfSprite_getPosition(map->sprite);
    sfBool is_find = false;
    int x = players_pos.x; int y = players_pos.y;
    if (x >= 12.000000 && x <= 21.000000 && y >= -1939.000000&& y <= -1405.000000)
        return is_find = true;
    if (x >= -57.000000 && -48.000000 && y >= -1936.000000 && y <= -1444.000000)
        return is_find = true;
    if (x >= -57.000000 && x <= 21.000000 && y >= -1939.000000 && y <= -1405.000000)
        return is_find = true;
    if (x >= -199.000000 && x <= -105.000000 && y >= -450.000000 && y <= -310.000000)
        return is_find = true;
    if (x >= -42.000000 && x <= 9.000000 && y >= -598.000000 && y <= -493.000000)
        return is_find = true;
    if (x >= -375.000000 && x <= 87.000000 && y >=-535.000000 && y <= -472.000000)
        return is_find = true;
    if (x >= -597.000000 && x <= -288.000000 && y >= -625.000000 && y <= -531.000000)
        return is_find = true;
    if (x >= -420.000000 && x <= -320.000000 && y >= -625.000000 && y <= -349.000000)
        return is_find = true;
    if (x >= -573.000000 && x <= -393.000000 && y >= -390.000000 && y <= -331.000000)
        return is_find = true;
    if (x >=-192.000000 && x <= -93.000000 && y >=-530.000000 && y <= -442.000000)
        return is_find = true;
    if (x >= -363.000000 && x <= -30.000000 && y >= -514.000000 && y <= -451.000000)
        return is_find = true;
    if (x >= -94.900000 && x <= 12.000000 && y >= -1410.000000 && y <= -1324.000000)
        return is_find = true;
    else {
        return is_find = false;
    }
}

bool check_if_in_inside(t_map *map)
{
    sfBool is_well = false;
    int is_hopital = check_in_hopital(map);
    if (is_hopital)
        return is_well = true;
    return is_well = false;
}

bool check_to_fight(t_map *map)
{
    sfBool is_well = false;
    sfVector2f players_pos = sfSprite_getPosition(map->sprite);
    if (players_pos.x >= -564.000000 && players_pos.x <= -479.000000 &&\
players_pos.y >= -2274.000000 && players_pos.y <= -2090.000000)
        return is_well = true;
    return is_well = false;
}

bool check_collision(t_map *map)
{
    sfVector2f players_pos = sfSprite_getPosition(map->sprite);
    //printf("%f %f\n",players_pos.x,players_pos.y);
    sfBool is_find = false;
    sfBool is_up = false;
    sfBool is_habitat = check_habitat(map);
    is_up = collison_up(map);
    int x = players_pos.x; int y = players_pos.y;
    if (x <=  0.000000 && y >= -600.000000 && y <= -580.000000 && x >= -42.000000)
        return is_find = true;
    if (x >= -208.004639 && x <= -110.699974  && y >= -735.399170 && y <= -710.906372)
        return is_find = true;
    if (x >= -106.000000 && x <= -35.000000 && y >= -1330.900024 && y <= -1139.000000)
        return is_find = true;
    if ( x >= -33.100121 && x <= 86.599205 && y >= -788.198975 && y <= -781.600586)
        return is_find = true;
    if (x >= -207.504623 && x <= -114.899956 && y >= -918.196289 && y <= -913.503540)
        return is_find = true;
    if (x >= -207.500015 && x <= -203.999939 && y >= -912.400146 && y <= -870.700562)
        return is_find = true;
    if (x >= -45.000000 && x <= -42.000000 && y >= -1309.000000 && y <= -448.000000)
        return is_find = true;
    if (x >= -205.100067 && x <= -110.000000 && y >= -941.900269 && y <= -680.604980)
        return is_find = true;
    if (x >= 35.399963 && x <= 950.099304 && y >= -1939.999268 && y <= -1433.796387)
        return is_find = false;
    if (x >= -111.000000 && x <= -111.000000  && y >= -1312.000000 && y <= -586.000000)
        return is_find = true;
    if ( x >= -84.000000 && x <= -75.000000 && y >= -1417.000000 && y <= -1411.000000)
        return is_find = false;
    if (x >= -111.000000 && x <= -42.000000 && y >= -1312.000000 && y <= -448.000000)
        return is_find = true;
    if (x >= 81.000000 && x <= 87.000000 && y >= -589.000000 && y <= -454.000000)
        return is_find = true;
    if (x >= 6.000000 && x <= 15.000000  && y >= -598.000000 && y <= -448.000000)
        return is_find = true;
    if (x >=  2.000000 && x <= 87.000000 && y >= -598.000000 && y <= -448.000000)
        return is_find = true;
    if (x >= -51.000000 && x <= -33.000000 && y >= -1564.000000 && y <= -1297.000000)
        return is_find = true;
    if (x >= -63.000000 && x <= 27.000000 && y >= -1939.000000 && y <= -1843.000000)
        return is_find = true;
    if (x >= -342.000000 && x <= 18.000000 && y >= -1957.000000 && y <= -1861.000000)
        return is_find = true;
    if (x >= -345.000000 && x <= -261.000000 && y >= -2068.000000 && y <= -1849.000000)
        return is_find = true;
    if (x >= -558.000000 && x <=  -276.000000 && y >= -2083.000000 && y <= -1978.000000)
        return is_find = true;
    if (x >= -558.000000 && x <= -486.000000 && y >= -2656.000000 && y <= -1984.000000)
        return is_find = true;
    if (is_up == true)
        return is_find = true;
    if (is_habitat == true)
        return is_find = true;
    if (check_pos_inside(map) == true)
        return is_find = true;
    if (check_if_in_inside(map) == true)
        return is_find = true;
    else {
        return is_find = false;
    }
}
