/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#include "SFML.hpp"
#include <iostream>

Arcade::SFML::SFML()
{
    this->loadingTypefont();
    this->loadingTitleWindowGames();
    this->setStatusMenu(false);
    this->setStatusSnacke(false);
    this->setStatusNibbler(false);
    this->createWindow();
}

void Arcade::SFML::createWindow()
{
    sf::VideoMode mode(1920, 1080);
    this->m_Mywindow.create(mode, "Arcade Menu");
}

void Arcade::SFML::createGames()
{
    sf::VideoMode mode(1920, 1080);
    this->m_Mywindow.create(mode, "Arcade Games");
}

Arcade::WINDOW Arcade::SFML::closeWindow() const
{
    return Arcade::WINDOW::CLOSE;
}

Arcade::WINDOW Arcade::SFML::windowIsOpen() const
{
    if (!this->m_Mywindow.isOpen())
        return Arcade::WINDOW::CLOSE;
    return Arcade::WINDOW::OPEN;
}

void Arcade::SFML::clearWindow()
{
    this->m_Mywindow.clear(sf::Color::Black);
}

void Arcade::SFML::displayWindow()
{
    this->m_Mywindow.display();
}

unsigned int Arcade::SFML::loadingTypefont()
{
    std::vector<std::pair<std::string, sf::Font*>> assetsFont = {
        {"./assets/arcade.ttf", &this->m_arcadeTTF},
        {"./assets/bold.ttf", &this->m_boldTTF},
        {"./assets/classicA.ttf", &this->m_classcATF},
        {"./assets/draw.ttf", &this->m_drawTTF},
        {"./assets/ka1.ttf", &this->m_ka1TTF},
        {"./assets/normal.ttf", &this->m_normalTTF},
        {"./assets/semiB.ttf", &this->m_semiBTTF},
        {"./assets/gamePlay.ttf", &this->m_gamePlay},
    };

    for (const auto& font : assetsFont) {
        if (!(font.second->loadFromFile(font.first)))
            throw ArcadeError::ErrorFont("The loading has been failed !");
    }
    return assetsFont.size();
}

void Arcade::SFML::loadingTitleWindowGames()
{
    std::vector<std::pair<std::string, sf::Text *>> Games = {
        {"Snacke", &this->m_snacke},
        {"Nibbler", &this->m_nibbler}
    };

    for (const auto& games : Games) {
        if (games.second == nullptr)
            throw ArcadeError::ErrorText("The loading of text has been failed !");
    }
}

Arcade::WINDOW Arcade::SFML::OpeningWindow()
{
    return Arcade::WINDOW::OPEN;
}

void Arcade::SFML::drawMyText(sf::Text text, std::string strText, int characterSize, int Vectorx, int Vectory, sf::Color color, sf::Font font)
{
    text.setFont(font);
    text.setString(strText);
    text.setCharacterSize(characterSize);
    text.setFillColor(color);
    text.setPosition(Vectorx, Vectory);
    text.setFillColor(color);
    this->m_Mywindow.draw(text);
}

void Arcade::SFML::handleEventsMenu(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Enter)
            this->setStatusMenu(false);

        else if(event.key.code == sf::Keyboard::Up) {
                this->setStatusSnacke(true);
                this->setStatusNibbler(false);
        }

        else if(event.key.code == sf::Keyboard::Down) {
            this->setStatusNibbler(true);
            this->setStatusSnacke(false);
        }
    }
}

void Arcade::SFML::DisplayTextMenu()
{
    sf::Color snackeColor = (m_activateSnacke) ? sf::Color::Yellow : sf::Color::White;
    sf::Color nibblerColor = (m_activateNibbler) ? sf::Color::Yellow : sf::Color::White;

    this->drawMyText(this->m_menu, "Arcade", 250, 600, 40, sf::Color::Blue, this->m_arcadeTTF);
    this->drawMyText(this->m_snacke, "Snacke", 75, 810, 400, snackeColor, this->m_arcadeTTF);
    this->drawMyText(this->m_nibbler, "Nibbler", 75, 820, 600, nibblerColor, this->m_arcadeTTF);
    this->drawMyText(this->m_Enter, "Press Enter", 60, 700, 840, sf::Color::White, this->m_gamePlay);
}

void Arcade::SFML::DisplayTitleGames()
{
    bool statusNibbler = this->getStatusNibbler();
    bool statusSnake = this->getStatusSnacke();

    if (statusSnake == true && statusNibbler == false)
        this->drawMyText(this->m_titleGamesSnacke, "Snake", 100, 730, 40, sf::Color::Cyan, this->m_semiBTTF);
    else if (statusSnake == false && statusNibbler == true)
        this->drawMyText(this->m_titleGamesNibbler, "Nibbler", 100, 630, 40, sf::Color::Magenta, this->m_semiBTTF);
}

Arcade::WINDOW Arcade::SFML::drawMenu()
{
    this->setStatusMenu(true);
    
    while (this->m_Mywindow.isOpen() && getStatusMenu()) {
        this->DisplayTextMenu();
        while (this->m_Mywindow.pollEvent(this->m_event)) {
            if (m_event.type == sf::Event::Closed) {
                this->m_Mywindow.close();
                return Arcade::WINDOW::CLOSE;
            }
            this->handleEventsMenu(m_event);

            if (this->getStatusSnacke() && !this->getStatusMenu()) {
                return Arcade::WINDOW::GAME_SNAKE;
            }
            else if (this->getStatusNibbler() && !this->getStatusMenu()) {
                return Arcade::WINDOW::GAME_NIBBLER;
            }
        }
        this->displayWindow();
    }
    return Arcade::WINDOW::OPEN;
}

Arcade::GAME_EVENT Arcade::SFML::drawGames(std::vector<std::string> gamingPlaterform, int mode,int score)
{
    bool openGame = true;
    if (mode == 0)
        this->createGames();
    else
        this->clearWindow();
    while (this->m_Mywindow.isOpen() && openGame) {
        this->DisplayTitleGames();
        this->drawPlateformGames(gamingPlaterform);
        this->drawMyText(this->m_scorePlayers, "Score: " + std::to_string(score), 100, 800, 800, sf::Color::Yellow, this->m_semiBTTF);
        while (this->m_Mywindow.pollEvent(this->m_event)) {
            if (this->m_event.type == sf::Event::Closed) {
                this->m_Mywindow.close();
                openGame = false;
                return Arcade::GAME_EVENT::CLOSED;
            }
            else if (this->m_event.type == sf::Event::KeyPressed) {
                Arcade::Key key = checkKeyPress(this->m_event.key.code);
                this->m_touchPress(key);
            }
        }
        this->displayWindow();
    }
    return Arcade::GAME_EVENT::OPENING;
}

void Arcade::SFML::setStatusMenu(bool status)
{
    this->m_activateMenu = status;
}

void Arcade::SFML::setStatusSnacke(bool status)
{
    this->m_activateSnacke = status;
}

void Arcade::SFML::setStatusNibbler(bool status)
{
    this->m_activateNibbler = status;
}

void Arcade::SFML::closingWindow()
{
    if (this->m_Mywindow.isOpen())
        this->m_Mywindow.close();
}

void Arcade::SFML::drawPlateformGames(std::vector<std::string> gamingPlatform)
{
    const int cellSize = 20;
    sf::RectangleShape rectangle(sf::Vector2f(cellSize, cellSize));
    rectangle.setOutlineThickness(1);
    rectangle.setOutlineColor(sf::Color::Black);

    for (size_t i = 0; i < gamingPlatform.size(); i++) {
        for (size_t j = 0; j < gamingPlatform[i].size(); j++) {
            int x = j * cellSize;
            int y = i * cellSize;
            rectangle.setPosition(x, y);

            switch (gamingPlatform[i][j]) {
                case 'X':
                    rectangle.setFillColor(sf::Color::White);
                    break;
                case 'O':
                    rectangle.setFillColor(sf::Color::Transparent);
                    break;
                case 'S':
                    rectangle.setFillColor(sf::Color::Blue);
                    break;
                case 'H':
                    rectangle.setFillColor(sf::Color::Red);
                    break;
                case 'F':
                    rectangle.setFillColor(sf::Color::Green);
                    break;
                case 'W':
                    rectangle.setFillColor(sf::Color::Red);
                    break;
                default:
                    break;
            }
            this->m_Mywindow.draw(rectangle);
        }
    }
}

Arcade::Key Arcade::SFML::checkKeyPress(sf::Keyboard::Key key)
{
    switch (key) {
        case sf::Keyboard::Up:
            return Arcade::Key::up;
        case sf::Keyboard::Down:
            return Arcade::Key::down;
        case sf::Keyboard::Left:
            return Arcade::Key::left;
        case sf::Keyboard::Right:
            return Arcade::Key::right;
        default:
            return Arcade::Key::unknow;
    }
}
