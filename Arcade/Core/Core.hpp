/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#pragma once

#include "DLLoader.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include "../Error/Library.hpp"
#include "../Error/Games.hpp"
#include "../Menu/AMenu.hpp"

template<typename LibraryGraphical, typename T>
bool is_findLibraryGraphical(const LibraryGraphical& lib, const T& inputLib)
{
    return std::find(lib.begin(), lib.end(), inputLib) != lib.end();
}

template<typename LibraryGames, typename T>
bool is_findLibraryGames(const LibraryGames& lib, const T& inputLib)
{
    return std::find(lib.begin(), lib.end(), inputLib) != lib.end();
}

namespace Arcade {

    enum class GAMES_LAUCH {
        IN_PROGRESS,
        GAMES_OVER,
        MENU_OPEN,
        MENU_CLOSE,
        GAME_OPENNING,
        GAME_CLOSED,
    };


    class Core {

        public:
            Core(const std::string &libInput);
            ~Core() = default;
            void findIndexGraphical(const std::string &libInput);
            void findIndexGames(const std::string &libInput);
            std::unique_ptr<DLLoader<IDisplayModule>>LoadingLibraryGraphical();
            std::vector<std::unique_ptr<DLLoader<IGames>>>LoadingLibraryGames();
            void startArcade();
            void openWindowAndStartGame();
            GAMES_LAUCH manage_Menu();
            void manage_GameSelection();
            GAMES_LAUCH manage_LibrarySelection();
            int getSelectedGames() {
                return this->m_selected;
            }
            void setSelectedGames(int select);
            void updateGamesMoving(std::vector<std::string> platformGames);
            bool getStatusUpdated();
            void setStatusUpdate(bool update);
        private:
            AMenu m_MyMenu;
            std::string m_libInput;
            std::vector<std::string> m_LibraryGraphic;
            std::vector<std::string> m_LibraryGames;
            std::vector<IDisplayModule *> m_moduleGraphic;
            std::vector<IGames *> m_moduleGames;
            unsigned int m_indexGraphical;
            unsigned int m_indexGames;
            int m_selected;
            Key m_event;
            bool m_mapUpdated;
    };
}

/*---------------------------LIBRARY GRAPHICAL--------------------------*/
const std::string PATH_LIBRARY_NCURSES = "lib/arcade_ncurses.so";
const std::string PATH_LIBRARY_SFML = "lib/arcade_sfml.so";
const std::string PATH_LIBRARY_SDL2 = "lib/arcade_sdl2.so";

/*-----------------------------GAMES-------------------------------*/
const std::string PATH_GAMES_SNACKES = "Games/arcade_snake.so";
const std::string PATH_GAMES_NIBLLER = "Games/arcade_nibbler.so";