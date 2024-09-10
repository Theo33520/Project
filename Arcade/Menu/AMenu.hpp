/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#pragma once

#include "IMenu.hpp"

namespace Arcade {

    class AMenu : public IMenu {
        public:
            AMenu() = default;
            ~AMenu() override = default;

            LIBRARY getLibraryInput(std::string &inputLib) const override{
                if (std::strcmp("./lib/arcade_sfml.so",inputLib.c_str()) == 0)
                    return LIBRARY::SFML;
                else if (std::strcmp("./lib/arcade_ncurses.so", inputLib.c_str()) == 0)
                    return LIBRARY::NCURSES;
                else if (std::strcmp("./lib/arcade_sdl2.so", inputLib.c_str()) == 0)
                    return LIBRARY::SDL2;
                else
                    return LIBRARY::NONE;
            }

            GAMES getGamesInput(std::string &inputGames) const override{
                if (std::strcmp("./Games/arcade_snake.so", inputGames.c_str()) == 0)
                    return GAMES::SNACKE;

                else if (std::strcmp("./Games/arcade_nibbler.so", inputGames.c_str()) == 0)
                    return GAMES::NIBBLER;

                else
                    return GAMES::NONE;
            }

    };
}
