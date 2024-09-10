/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#include "Core.hpp"

Arcade::GAMES_LAUCH Arcade::Core::manage_Menu()
{
    switch (this->m_MyMenu.getGamesInput(m_libInput)) {
        case Arcade::GAMES::SNACKE:
        case Arcade::GAMES::NIBBLER:
            this->manage_GameSelection();
            exit(84);
            break;
        default:
            if (manage_LibrarySelection() == Arcade::GAMES_LAUCH::GAME_OPENNING) {
                return Arcade::GAMES_LAUCH::MENU_CLOSE;
            }
            break;
    }

}

void Arcade::Core::manage_GameSelection()
{
    std::cout << "The library doesn't exist !" << std::endl;
}

Arcade::GAMES_LAUCH Arcade::Core::manage_LibrarySelection()
{
    Arcade::WINDOW Games;
    switch (this->m_MyMenu.getLibraryInput(m_libInput)) {
        case Arcade::LIBRARY::SFML:
            Games = this->m_moduleGraphic.at(0)->drawMenu();
            if (Games == Arcade::WINDOW::GAME_SNAKE)
                this->setSelectedGames(0);
            else if (Games == Arcade::WINDOW::GAME_NIBBLER)
                this->setSelectedGames(1);
            break;
        case Arcade::LIBRARY::NCURSES:
            Games = this->m_moduleGraphic.at(0)->drawMenu();
            if (Games == Arcade::WINDOW::GAME_SNAKE)
                this->setSelectedGames(0);
            else if (Games == Arcade::WINDOW::GAME_NIBBLER)
               this->setSelectedGames(1);
            break;
        case Arcade::LIBRARY::SDL2:
            Games = this->m_moduleGraphic.at(0)->drawMenu();
            if (Games == Arcade::WINDOW::GAME_SNAKE)
                this->setSelectedGames(0);
            else if (Games == Arcade::WINDOW::GAME_NIBBLER)
                this->setSelectedGames(1);
            break;
        default:
            break;
    }
    this->m_moduleGraphic.at(0)->closingWindow();
    return Arcade::GAMES_LAUCH::GAME_OPENNING;
}
