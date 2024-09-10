/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>


namespace Arcade {

    class IMapGames {
        public:
            virtual ~IMapGames() = default;
            virtual std::vector<std::string> getMapGames() = 0;
    };
}