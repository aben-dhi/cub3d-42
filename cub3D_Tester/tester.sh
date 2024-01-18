#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
PURPLE='\033[0;35m'
RESET='\033[0m'

cd .. ; make
echo -e "${PURPLE} ---------------------------------------------------------------${RESET}"
echo -e "${PURPLE}                    TESTING INPUT FILE${RESET}"
echo -e "${PURPLE} ---------------------------------------------------------------\n${RESET}"

echo -e "${RED}--> Missing file${RESET}"
./cub3D

echo -e "${RED}--> Incorrect extension${RESET}"
./cub3D srcs/main.c

echo -e "${RED}--> Inexistent file${RESET}"
./cub3D blabla.cub

echo -e "${RED}--> Directory with .cub ending${RESET}"
mkdir "test.cub" ; ./cub3D "test.cub" ; rm -rf "test.cub"

echo -e "${PURPLE} ---------------------------------------------------------------${RESET}"
echo -e "${PURPLE}                    TESTING TYPE IDENTIFIERS${RESET}"
echo -e "${PURPLE} ---------------------------------------------------------------\n${RESET}"

echo -e "${RED}--> Missing a type identifier${RESET}"
./cub3D Cub3D_Tester/maps/id_missing.cub

echo -e "${RED}--> Has a type identifier multiple times${RESET}"
./cub3D Cub3D_Tester/maps/id_multiple.cub

echo -e "${RED}--> A type identifier is not the first element of a line${RESET}"
./cub3D Cub3D_Tester/maps/id_not_first.cub

echo -e "${RED}--> A texture is not readable${RESET}"
./cub3D Cub3D_Tester/maps/nonvalid_texture.cub

echo -e "${RED}--> Color has an extra comma${RESET}"
./cub3D Cub3D_Tester/maps/extra_comma.cub

echo -e "${RED}--> Color has an rgb higher than 255${RESET}"
./cub3D Cub3D_Tester/maps/300rgb.cub

echo -e "${GREEN}--> Has spaces before type identifier${RESET}"
./cub3D Cub3D_Tester/maps/map.cub

echo -e "${PURPLE} ---------------------------------------------------------------${RESET}"
echo -e "${PURPLE}                        TESTING MAP${RESET}"
echo -e "${PURPLE} ---------------------------------------------------------------\n${RESET}"

echo -e "${RED}--> Invalid non-map character${RESET}"
./cub3D Cub3D_Tester/maps/nonmap_char.cub

echo -e "${RED}--> Two players${RESET}"
./cub3D Cub3D_Tester/maps/two_players.cub

echo -e "${RED}--> No players${RESET}"
./cub3D Cub3D_Tester/maps/no_players.cub

echo -e "${RED}--> Not surrounded by walls${RESET}"
./cub3D Cub3D_Tester/maps/not_surrounded.cub

echo -e "${RED}--> has spaces in the middle of the map${RESET}"
./cub3D Cub3D_Tester/maps/spaced.cub

echo -e "${GREEN}--> Egypt${RESET}"
./cub3D Cub3D_Tester/maps/Maze.cub

echo -e "${GREEN}--> Playable${RESET}"
./cub3D Cub3D_Tester/maps/Egypt.cub
