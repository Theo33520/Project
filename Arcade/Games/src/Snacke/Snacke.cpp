/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#include "Snacke.hpp"

std::string Arcade::Snacke::getName() const
{
    return this->m_nameGames;
}

std::pair<int, int> Arcade::Snacke::getSizeMapGames()
{
    return this->m_sizeMap;
}

float Arcade::Snacke::getSpeedPlayers()
{
    return this->m_speed;
}

int Arcade::Snacke::getScorePlayer()
{
    return this->m_score;
}

std::string Arcade::Snacke::titleGameMap() const
{
    return this->m_titleGames;
}

std::vector<std::string> Arcade::Snacke::getPlateFormGaming()
{
    if (m_instanceMap) {
        this->m_MapGames = this->m_instanceMap->getMapGames();
        return this->m_MapGames;
    }
    else {
        return {};
    }
}

void Arcade::Snacke::init_Games()
{
    this->m_nameGames = "Snake";
    this->m_sizeMap = std::make_pair(50,50);
    this->m_speed = 1.0f;
    this->m_score = 0;
    this->m_titleGames = "Classic Snake";
    this->m_instanceMap = std::make_unique<Arcade::MapGames>();
    this->snackeStarting();
    //std::cout << "The games Snake has been init" << std::endl;
}

void Arcade::Snacke::stop_Games()
{
    std::cout << "The games has been stopped" << std::endl;
}

Arcade::Direction Arcade::Snacke::getCurrentPosition() const
{
    return this->m_curDir;
}

void Arcade::Snacke::setDirection(Arcade::Direction direction)
{
    this->m_curDir = direction;
}

void Arcade::Snacke::snackeStarting()
{

    this->m_head = std::make_pair(20,28);

    for (size_t i = 25; i < 28;i++) {
        this->m_tail.push_back(std::make_pair(20,i));
    }
}

void Arcade::Snacke::move(Arcade::Direction direction)
{
    std::pair<int, int> prev_head_position = m_head;
    std::srand(std::time(nullptr));
    bool isfind = false;
    switch(direction) {
        case Arcade::Direction::UP:
            m_head.first--;
            break;
        case Arcade::Direction::DOWN:
            m_head.first++;
            break;
        case Arcade::Direction::RIGHT:
            m_head.second++;
            break;
        case Arcade::Direction::LEFT:
            m_head.second--;
            break;
        default:
            break;
    }
    if (m_head.first == pair_ij.first && m_head.second == pair_ij.second) {
        isfind = true;
    }
    if (isfind == true) {
        int i = (std::rand() % 21) + 10;
        int j = (std::rand() % 40) + 10;
        if (i < 11 || i >= 29)
            j = (std::rand() % 10) + 10;
        else {
            this->pair_ij = std::make_pair(i,j);
            isfind = false;
            m_tail.push_back(prev_head_position);
            setScorelayersCall();
        }
    }
    SetGamingPlatForm(pair_ij.first, pair_ij.second, 'F');
    SetGamingPlatForm(m_head.first, m_head.second, 'H');

    for (size_t i = 0; i < m_tail.size(); i++) {
        std::pair<int, int> current_tail_position = m_tail[i];
        m_tail[i] = prev_head_position;
        SetGamingPlatForm(m_tail[i].first, m_tail[i].second, 'S');
        prev_head_position = current_tail_position;
    }
    SetGamingPlatForm(prev_head_position.first, prev_head_position.second, 'O');
    std::vector<std::string> snacke = getUpdateMap();
    int newScore = getScorePlayer();
    m_callMapSnake(snacke, newScore);
}

void Arcade::Snacke::setMoveSnacke()
{
    this->move(Arcade::Direction::UP);
}

std::vector<std::string> Arcade::Snacke::getUpdateMap()
{
    return this->m_MapGames;
}