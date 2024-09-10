/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#pragma once

#include "../IDisplayModule.hpp"
#include <ncurses.h>

namespace Arcade {

    class Ncurses : public IDisplayModule {
        private:
            bool m_activateMenu;
            bool m_activateSnacke;
            bool m_activateNibbler;
            const char *m_snacke;
            const char *m_nibbler;
            GAME_EVENT m_gameEvent;

            touchPressed m_touchPress;
        public:
            Ncurses();
            ~Ncurses() override = default;
            WINDOW windowOpen() override;
            void displayWindow() override {
                return;
            }
            /*From interface IDisplayModule*/
            void createWindow() override;
            void createGames() override;
            WINDOW closeWindow() const override;
            WINDOW windowIsOpen() const override;
            void clearWindow() override;

            bool getStatusMenu() const override {
                return this->m_activateMenu;
            };
            bool getStatusSnacke() const override {
                return this->m_activateSnacke;
            };
            bool getStatusNibbler() const override {
                return this->m_activateNibbler;
            };
            void setStatusMenu(bool status) override;
            void setStatusSnacke(bool status) override;
            void setStatusNibbler(bool status) override;
            WINDOW OpeningWindow() override;
            std::string getNameModule() const override;
            WINDOW drawMenu() override;
            void loadingTitleWindowGames() override;
            GAME_EVENT drawGames(std::vector<std::string> gamingPlaterform, int mode,int score) override;
            void closingWindow() override;
            void drawPlateformGames(std::vector<std::string> gamingPlateform) override;
            void setKeyPressedCallBack(touchPressed callback) override {
                this->m_touchPress = callback;
            }
            Key checkKeyPress(int key);
    };

}

extern "C" Arcade::IDisplayModule *entryPoint()
{
    return new Arcade::Ncurses;
}