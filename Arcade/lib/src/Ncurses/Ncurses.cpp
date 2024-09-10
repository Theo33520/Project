/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#include "Ncurses.hpp"
#include <iostream>


Arcade::Ncurses::Ncurses()
{
    this->loadingTitleWindowGames();
    this->setStatusMenu(false);
    this->setStatusSnacke(false);
    this->setStatusNibbler(false);
    this->createWindow();
}

std::string Arcade::Ncurses::getNameModule() const
{
    return "Ncurses";
}

Arcade::WINDOW Arcade::Ncurses::windowOpen()
{
    return Arcade::WINDOW::OPEN;
}

void Arcade::Ncurses::createWindow()
{
    initscr();
    nodelay(stdscr, true);
    curs_set(FALSE);
    init_color(COLOR_BLACK,0,0,0);
    noecho();
    keypad(stdscr, TRUE);
    cbreak();
}

void Arcade::Ncurses::createGames()
{
    initscr();
    nodelay(stdscr, true);
    curs_set(FALSE);
    init_color(COLOR_BLACK,0,0,0);
    noecho();
    keypad(stdscr, TRUE);
    cbreak();
}

Arcade::WINDOW Arcade::Ncurses::closeWindow() const
{
    return Arcade::WINDOW::CLOSE;
}

Arcade::WINDOW Arcade::Ncurses::windowIsOpen() const
{
    return Arcade::WINDOW::OPEN;
}

void Arcade::Ncurses::clearWindow()
{
    clear();
}

Arcade::WINDOW Arcade::Ncurses::drawMenu()
{

    this->createWindow();
    Arcade::WINDOW STATE = Arcade::WINDOW::OPEN;

    attron(A_BOLD);

    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);
    mvprintw(0, (max_x /2), "Arcade\n");
    mvprintw(10,(max_x /2), this->m_snacke);
    mvprintw(20,(max_x /2), this->m_nibbler);
    refresh();
    while (STATE == Arcade::WINDOW::OPEN) {
        int press = getch();
        if (press == 'c' || press == 'C') {
            endwin();
            exit(0);
        } else if (press == KEY_UP) {
            attron(A_REVERSE);
            mvprintw(10,(max_x /2), this->m_snacke);
            attroff(A_REVERSE);
            mvprintw(20,(max_x /2), this->m_nibbler);
            this->setStatusSnacke(true);
            this->setStatusNibbler(false);
        } else if (press == KEY_DOWN) {
            attron(A_REVERSE);
            mvprintw(20,(max_x /2), this->m_nibbler);
            attroff(A_REVERSE);
            mvprintw(10,(max_x /2), this->m_snacke);
            this->setStatusSnacke(false);
            this->setStatusNibbler(true);
        } else if (press == '\n') {
            this->setStatusMenu(false);
            if (this->getStatusSnacke() && !this->getStatusMenu()) {
                endwin();
                return Arcade::WINDOW::GAME_SNAKE;
            }
            else if (this->getStatusNibbler() && !this->getStatusMenu()) {
                endwin();
                return Arcade::WINDOW::GAME_NIBBLER;
            }
        }
        refresh();
    }
    attroff(A_BOLD);
    endwin();
    return STATE;
}

void Arcade::Ncurses::setStatusMenu(bool status)
{
    this->m_activateMenu = status;
}

void Arcade::Ncurses::setStatusSnacke(bool status)
{
    this->m_activateSnacke = status;
}

void Arcade::Ncurses::setStatusNibbler(bool status)
{
    this->m_activateNibbler = status;
}

Arcade::WINDOW Arcade::Ncurses::OpeningWindow()
{
    return Arcade::WINDOW::CLOSE;
}

void Arcade::Ncurses::loadingTitleWindowGames()
{
    this->m_snacke = "Snacke";
    this->m_nibbler = "Nibbler";
}

void Arcade::Ncurses::closingWindow()
{
    endwin();
}

Arcade::GAME_EVENT Arcade::Ncurses::drawGames(std::vector<std::string> gamingPlatform, int mode,int score)
{
    if (mode == 0)
        this->createWindow();
    else
        this->clearWindow();
    bool openGame = true;
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);
    while (openGame) {
        this->clearWindow();
        this->drawPlateformGames(gamingPlatform);
        if (this->getStatusSnacke() == true && this->getStatusNibbler() == false)
            mvprintw(0, (max_x /2), "Snake\n");
        else if (this->getStatusSnacke() == false && this->getStatusNibbler() == true)
            mvprintw(0, (max_x /2), "Nibbler\n");
        mvprintw(50, 50,("Score: " + std::to_string(score)).c_str());
        int press = getch();
        Arcade::Key key = checkKeyPress(press);
        this->m_touchPress(key);
        if (press == 'c' || press == 'C') {
            openGame = false;
            break;
        }
    }
    this->closingWindow();
    return Arcade::GAME_EVENT::CLOSED;
}

void Arcade::Ncurses::drawPlateformGames(std::vector<std::string> gamingPlatform)
{
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);
    const int cellSize = 1;

    for (size_t i = 0; i < gamingPlatform.size(); i++) {
        for (size_t j = 0; j < gamingPlatform[i].size(); j++) {
            int x = j * cellSize;
            int y = i * cellSize;
            if (gamingPlatform[i][j] == 'X')
                mvprintw(y, x, "X");
            else if (gamingPlatform[i][j] == 'O')
                mvprintw(y, x, " ");
            else if (gamingPlatform[i][j] == 'S')
                mvprintw(y, x, "-");
            else if (gamingPlatform[i][j] == 'H')
                mvprintw(y, x, "o");
            else if (gamingPlatform[i][j] == 'F')
                mvprintw(y, x, "+1");
            else if (gamingPlatform[i][j] == 'W')
                mvprintw(y, x, "||");
        }
    }
    refresh();
}

Arcade::Key Arcade::Ncurses::checkKeyPress(int key)
{
    switch(key) {
        case KEY_UP:
            return Arcade::Key::up;
        case KEY_DOWN:
            return Arcade::Key::down;
        case KEY_LEFT:
            return Arcade::Key::left;
        case KEY_RIGHT:
            return Arcade::Key::right;

        default:
            return Arcade::Key::unknow;
    }
}