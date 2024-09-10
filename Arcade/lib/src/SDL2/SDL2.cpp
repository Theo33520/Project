/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#include "SDL2.hpp"
#include <iostream>
#include <string.h>

Arcade::SDL2::SDL2() : m_Mywindow(nullptr), m_winSurface(nullptr), m_Renderer(nullptr), m_font(nullptr), m_texture(nullptr), m_CharacterSize(12)
{
    this->m_sizeText = 30;
    this->setStatusMenu(false);
    this->setStatusSnacke(false);
    this->setStatusNibbler(false);
    this->OpeningWindow();
}

std::string Arcade::SDL2::getNameModule() const
{
    return "SDL2";
}

Arcade::WINDOW Arcade::SDL2::windowOpen()
{
    return Arcade::WINDOW::OPEN;
}

void Arcade::SDL2::createWindow()
{
    this->m_Mywindow = SDL_CreateWindow("Arcade",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,1920, 1080, SDL_WINDOW_SHOWN);
    if (!this->m_Mywindow) {
        std::cout << "Failed to create window" << std::endl;
        exit(84);
    }
}

void Arcade::SDL2::createGames()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw ArcadeError::ErrorFont("Failed to initialize SDL video!");
    }

    this->m_Mywindow = SDL_CreateWindow("Arcade Interface Graphical", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN);
    if (m_Mywindow == nullptr) {
        throw ArcadeError::ErrorFont("Failed to create SDL window!");
    } else {
        this->m_Renderer = SDL_CreateRenderer(this->m_Mywindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (this->m_Renderer == nullptr) {
            throw ArcadeError::ErrorFont("Failed to create SDL renderer!");
        } else {
            if (TTF_Init() == -1)
                throw ArcadeError::ErrorFont("Failed to initialize SDL TTF!");
        }
    }
}
Arcade::WINDOW Arcade::SDL2::closeWindow() const
{
    return Arcade::WINDOW::CLOSE;
}

Arcade::WINDOW Arcade::SDL2::windowIsOpen() const
{
    return Arcade::WINDOW::OPEN;
}

Arcade::WINDOW Arcade::SDL2::OpeningWindow()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw ArcadeError::ErrorFont("The window has been failed during the loading !");
    }

    this->m_Mywindow = SDL_CreateWindow("Arcade",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,1920, 1080, SDL_WINDOW_SHOWN);
    if (m_Mywindow == nullptr) {
        throw ArcadeError::ErrorFont("The window has been failed during the loading !");
   } else {
        this->m_Renderer = SDL_CreateRenderer(this->m_Mywindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (this->m_Renderer == nullptr) {
            throw ArcadeError::ErrorFont("The window couldn't be created !");
        } else {
            if (TTF_Init() == -1)
                throw ArcadeError::ErrorFont("The window couldn't be created !");
        }
   }
   return Arcade::WINDOW::OPEN;
}

bool Arcade::SDL2::loadFont(const char* fontPath, int size)
{
    this->m_font = TTF_OpenFont(fontPath, size);
    if (m_font == nullptr) {
        printf("Failed to load font ! SDL_ttf");
        return false;
    }
    this->m_CharacterSize = size;
    return true;
}

void Arcade::SDL2::drawText(const char *text, int x,int y, SDL_Color textColor)
{
    if (this->m_font == nullptr)
        return;
    SDL_Surface *textSurface = TTF_RenderText_Solid(this->m_font, text, textColor);
    if (textSurface == nullptr) {
        printf("Unable to render text surface ! SDL_ttf Error");
    }
    this->m_texture = SDL_CreateTextureFromSurface(this->m_Renderer, textSurface);
    if (m_texture == nullptr)
        printf("Unable to create texture from renderer text !");
    else {
        m_textRect.x = x;
        m_textRect.y = y;
        m_textRect.w = textSurface->w;
        m_textRect.h = textSurface->h;
        SDL_RenderCopy(this->m_Renderer, this->m_texture, nullptr, &m_textRect);
    }
    SDL_FreeSurface(textSurface);
}


void Arcade::SDL2::clearWindow()
{
    SDL_RenderClear(this->m_Renderer);
    SDL_SetRenderDrawColor(this->m_Renderer, 0, 0, 0, 255);
}

Arcade::WINDOW Arcade::SDL2::drawMenu()
{
    if (!this->loadFont("./assets/normal.ttf", this->getSizeText())) {
        throw ArcadeError::ErrorFont("Failed for loading font!");
    }
    bool isOpen = true;
    this->setStatusMenu(true);
    while(isOpen && this->getStatusMenu()) {
        while (SDL_PollEvent(&this->m_event) != 0) {
            if (this->m_event.type == SDL_QUIT) {
                isOpen = false;
                SDL_DestroyWindow(this->m_Mywindow);
                return Arcade::WINDOW::CLOSE;
            }
            else if (this->m_event.type == SDL_KEYDOWN) {
                switch (this->m_event.key.keysym.sym) {
                    case SDLK_UP:
                        this->setStatusSnacke(true);
                        this->setStatusNibbler(false);
                        break;
                    case SDLK_DOWN:
                        this->setStatusNibbler(true);
                        this->setStatusSnacke(false);
                        break;
                    case SDLK_RETURN:
                        this->setStatusMenu(false);
                        if (this->getStatusSnacke() && !(this->getStatusMenu()))
                            return Arcade::WINDOW::GAME_SNAKE;
                        else if (this->getStatusNibbler() && !(this->getStatusMenu()))
                            return Arcade::WINDOW::GAME_NIBBLER;
                        break;
                    default:
                        break;
                }
            }
        }
        this->clearWindow();
        this->drawText("Arcade", 875, 100, {255,255,255});
        if (this->getStatusSnacke()) {
            this->drawText("Snacke", 875, 400, {255, 240, 0});
        }
        else
            this->drawText("Snacke", 875, 400, {255,255,255});

        if (this->getStatusNibbler())
            this->drawText("Nibbler", 875 , 600, {255, 240, 0});
        else
            this->drawText("Nibbler", 875, 600, {255,255,255});
        this->displayRenderer();
    }
    return Arcade::WINDOW::OPEN;
}

Arcade::GAME_EVENT Arcade::SDL2::drawGames(std::vector<std::string> gamingPlatform, int mode,int score)
{
    if (mode == 0)
        this->createGames();
    else
        this->clearWindow();
    
    if (!this->loadFont("./assets/normal.ttf", this->getSizeText())) {
        throw ArcadeError::ErrorFont("Failed for loading font!");
    }
    bool isOpen = true;
    while (isOpen) {
        while (SDL_PollEvent(&this->m_event) != 0) {
            if (this->m_event.type == SDL_QUIT) {
                isOpen = false;
                this->closingWindow();
                SDL_DestroyWindow(this->m_Mywindow);
                exit(0);
                return Arcade::GAME_EVENT::CLOSED;
            }
            else if (this->m_event.type == SDL_KEYDOWN) {
                Arcade::Key key = checkKeyPressed(static_cast<SDL_KeyCode>(this->m_event.key.keysym.sym));
                this->m_touchPress(key);
            }
        }
        this->clearWindow();
        if (this->getStatusSnacke() && !this->getStatusNibbler())
            this->drawText("Snacke", 875, 100, {4,225,243});
        else if (!this->getStatusSnacke() && this->getStatusNibbler())
            this->drawText("Nibbler", 875, 100, {249,12,216});
        this->drawText(("Score: " + std::to_string(score)).c_str(), 800, 800, {255, 207, 0});
        this->drawPlateformGames(gamingPlatform);
        this->displayRenderer();
    }
    return Arcade::GAME_EVENT::OPENING;
}


void Arcade::SDL2::drawPlateformGames(std::vector<std::string> gamingPlatform)
{
    const int cellSize = 20;
    for (size_t i = 0; i < gamingPlatform.size(); i++) {
        for (size_t j = 0; j < gamingPlatform.at(i).size(); j++) {
            int x = cellSize * j;
            int y = cellSize * i;

            SDL_Rect rect;
            rect.x = x;
            rect.y = y;
            rect.w = cellSize;
            rect.h = cellSize;

            switch (gamingPlatform[i][j]) {
                case 'X':
                    SDL_SetRenderDrawColor(this->m_Renderer,  0, 0, 0, 255);
                    break;
                case 'O':
                    SDL_SetRenderDrawColor(this->m_Renderer, 255, 255,255, 0);
                    break;
                case 'S':
                    SDL_SetRenderDrawColor(this->m_Renderer, 4, 38, 226, 255);
                    break;
                case 'H':
                    SDL_SetRenderDrawColor(this->m_Renderer, 255, 0, 0, 255);
                    break;
                case 'F':
                    SDL_SetRenderDrawColor(this->m_Renderer, 255, 207, 0, 255);
                    break;
                case 'W':
                    SDL_SetRenderDrawColor(this->m_Renderer, 184, 115, 8, 255);
                default:
                    break;
            }
            SDL_RenderFillRect(this->m_Renderer, &rect);
        }
    }
}


void Arcade::SDL2::setStatusMenu(bool status)
{
    this->m_activateMenu = status;
}

void Arcade::SDL2::setStatusSnacke(bool status)
{
    this->m_activateSnacke = status;
}

void Arcade::SDL2::setStatusNibbler(bool status)
{
    this->m_activateNibbler = status;
}

void Arcade::SDL2::loadingTitleWindowGames()
{
    this->m_snacke = "Snacke";
    this->m_nibbler = "Nibbler";
}

void Arcade::SDL2::displayRenderer()
{
    SDL_RenderPresent(this->m_Renderer);
}

unsigned int Arcade::SDL2::getSizeText()
{
    return this->m_sizeText;
}

void Arcade::SDL2::setTextSize(unsigned int size)
{
    this->m_sizeText = size;
}

void Arcade::SDL2::closingWindow()
{
    SDL_DestroyWindow(m_Mywindow);
}

Arcade::Key Arcade::SDL2::checkKeyPressed(SDL_KeyCode key)
{
    switch (key) {
        case SDLK_UP:
            return Arcade::Key::up;
        case SDLK_DOWN:
            return Arcade::Key::down;
        case SDLK_LEFT:
            return Arcade::Key::left;
        case SDLK_RIGHT:
            return Arcade::Key::right;
        default:
            return Arcade::Key::unknow;
    }
}
