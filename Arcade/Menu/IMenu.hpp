/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#pragma once

#include <string>
#include <cstring>

namespace Arcade {

    enum class LIBRARY {
        SFML,
        NCURSES,
        SDL2,
        NONE
    };

    enum class GAMES {
        NIBBLER,
        SNACKE,
        NONE
    };

    enum class MENU {
        OPEN_STATUS,
        CLOSE_STATUS
    };

    class IMenu {
        public:
            virtual ~IMenu() = default;
            virtual LIBRARY getLibraryInput(std::string &inputLib) const = 0;
            virtual GAMES getGamesInput(std::string &gamesLib) const = 0;

    };
}
