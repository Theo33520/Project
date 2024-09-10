/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#pragma once

#include "../IDisplayModule.hpp"
#include "includesSDL2.hpp"
#include <string>
#include <vector>

namespace Arcade
{
    class SDL2 : public IDisplayModule {
        private:
            SDL_Window *m_Mywindow;
            SDL_Surface *m_winSurface;
            SDL_Texture* m_texture;
            SDL_Rect m_textRect;

            SDL_Renderer* m_Renderer;
            TTF_Font *m_font;
            int m_CharacterSize;

            unsigned int m_sizeText;


            bool m_activateMenu;
            bool m_activateSnacke;
            bool m_activateNibbler;

            /*---------MENU----------*/
            std::string m_snacke;
            std::string m_nibbler;
            std::string m_titleMenu;
            GAME_EVENT m_gameEvent;

            touchPressed m_touchPress;

        public:
            SDL2();
            ~SDL2() {
                SDL_DestroyTexture(m_texture);
                SDL_FreeSurface(m_winSurface);
                SDL_DestroyRenderer(m_Renderer);
                SDL_DestroyWindow(m_Mywindow);
                TTF_Quit();
                SDL_Quit();

            }
            SDL_Event m_event;
            WINDOW windowOpen() override;
            /*From interface IDisplayModule*/
            void createWindow() override;
            void createGames() override;
            WINDOW closeWindow() const override;
            WINDOW windowIsOpen() const override;
            std::vector<std::pair<int, int>> getVectorCoordonees();
            void clearWindow() override;
            void displayWindow() override {
                return;
            }
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
            void loadingTitleWindowGames() override;
            std::string getNameModule() const override;
            WINDOW drawMenu() override;
            bool loadFont(const char* fontPath, int size);
            void drawText(const char* text, int x, int y, SDL_Color textColor);
            void displayRenderer();
            unsigned int getSizeText();
            void setTextSize(unsigned int size);
            GAME_EVENT drawGames(std::vector<std::string> gamingPlaterform, int mode,int score) override;
            void closingWindow() override;
            void drawPlateformGames(std::vector<std::string> gamingPlateform) override;
            void setKeyPressedCallBack(touchPressed callback) override{
                    this->m_touchPress = callback;
            }
            Key checkKeyPressed(SDL_KeyCode key);
    };

}

extern "C" Arcade::IDisplayModule *entryPoint()
{
    return new Arcade::SDL2;
}