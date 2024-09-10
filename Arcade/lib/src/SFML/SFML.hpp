/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#pragma once

#include "../IDisplayModule.hpp"
#include "includeSFML.hpp"


namespace Arcade {

    class SFML : public IDisplayModule {
        private:
            sf::RenderWindow m_Mywindow;
            sf::Event m_event;
            sf::Font m_titleWindow;
            sf::Text m_menu;
            sf::Text m_score;
            std::string m_NamePlayers;
            bool m_activateMenu;
            bool m_activateSnacke;
            bool m_activateNibbler;
            
            bool m_up;
            bool m_down;
            bool m_rigth;
            bool m_left;
        
            /*------GAMES------*/
            sf::Text m_snacke;
            sf::Text m_nibbler;
            sf::Text m_Enter;
            sf::Text m_scorePlayers;

            sf::Text m_titleGamesSnacke;
            sf::Text m_titleGamesNibbler;

            /*Loading ttf*/
            sf::Font m_arcadeTTF;
            sf::Font m_boldTTF;
            sf::Font m_classcATF;
            sf::Font m_drawTTF;
            sf::Font m_ka1TTF;
            sf::Font m_normalTTF;
            sf::Font m_semiBTTF;
            sf::Font m_gamePlay;
            touchPressed m_touchPress;
        public:
            SFML();
            ~SFML() override {
                this->m_Mywindow.close();
            };
            WINDOW windowOpen() override {
                return WINDOW::OPEN;
            };
            std::string getNameModule() const override {
                return "SFML";
            }
            // MENU
            WINDOW drawMenu() override;
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
            /*---WINDOWS---*/
            void createWindow() override;
            void createGames() override;
            WINDOW OpeningWindow() override;
            WINDOW closeWindow() const override;
            WINDOW windowIsOpen() const override;
            void clearWindow() override;
            void displayWindow() override;

            /*------TEXT WINDOWS-----*/
            unsigned int loadingTypefont();
            void loadingTitleWindowGames() override;
            void DisplayTextMenu();
            void DisplayTitleGames();
            void drawMyText(sf::Text text, std::string strText, int characterSize, int Vectorx, int Vectory, sf::Color color, sf::Font font);
            void handleEventsMenu(sf::Event event);
            void setColorText(sf::Text text,sf::Color color) {
                text.setFillColor(color);
            }
            GAME_EVENT drawGames(std::vector<std::string> gamingPlaterform, int mode,int score) override;
            void closingWindow() override;
            void drawPlateformGames(std::vector<std::string> gamingPlateform) override;
            void setKeyPressedCallBack(touchPressed callback) override{
                this->m_touchPress = callback;
            }
            Key checkKeyPress(sf::Keyboard::Key key);
        };
}

extern "C" Arcade::IDisplayModule *entryPoint()
{
    return new Arcade::SFML;
}
