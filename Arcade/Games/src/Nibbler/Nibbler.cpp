/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#include "Nibbler.hpp"

std::string Arcade::Nibbler::getName() const
{
    return this->m_nameGames;
}

std::pair<int, int> Arcade::Nibbler::getSizeMapGames()
{
    return this->m_sizeMap;
}

float Arcade::Nibbler::getSpeedPlayers()
{
    return this->m_speed;
}

int Arcade::Nibbler::getScorePlayer()
{
    return this->m_score;
}

std::string Arcade::Nibbler::titleGameMap() const
{
    return this->m_titleGames;
}

void Arcade::Nibbler::init_Games()
{
    this->m_nameGames = "Nibbler";
    this->m_sizeMap = std::make_pair(50,50);
    this->m_speed = 1.0f;
    this->m_score = 0;
    this->m_titleGames = "Classic Nibbler";
    this->m_instanceMap = std::make_unique<Arcade::MapGames>();
    this->snackeStarting();
}

void Arcade::Nibbler::stop_Games()
{
    std::cout << "The games has been stopped" << std::endl;
}

std::vector<std::string> Arcade::Nibbler::getPlateFormGaming()
{
    if (this->m_instanceMap) {
        this->m_MapGames = this->m_instanceMap->getMapGames();
        return this->m_MapGames;
    }
    else
        return {};
}

void Arcade::Nibbler::snackeStarting()
{

    this->m_head = std::make_pair(20,28);
        for (size_t i = 25; i < 28;i++) {
        this->m_tail.push_back(std::make_pair(20,i));
    }
}

void Arcade::Nibbler::GenerateWall()
{
    std::srand(std::time(nullptr));
    for (size_t i = 10; i < 29; i++) {
        int index_wall_j = (std::rand() % 40) + 10;
        for (int j = index_wall_j; j < index_wall_j + 4; j++) {
            SetGamingPlatForm(i, j, 'W');
            m_wallPos.push_back({i, j});
        }
    }
}

void Arcade::Nibbler::move(Arcade::Direction direction)
{
    static bool wallsGenerated = false;
    
    if (!wallsGenerated) {
        this->GenerateWall();
        wallsGenerated = true;
    }
    
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

    for (auto it = m_wallPos.begin(); it != m_wallPos.end(); ++it) {
        if (it->first == m_head.first && it->second == m_head.second)
            statusGame(-1);
    }
    for (size_t i = 0; i < m_tail.size(); i++) {
        std::pair<int, int> current_tail_position = m_tail[i];
        m_tail[i] = prev_head_position;
        SetGamingPlatForm(m_tail[i].first, m_tail[i].second, 'S');
        prev_head_position = current_tail_position;
    }
    SetGamingPlatForm(prev_head_position.first, prev_head_position.second, 'O');
    std::vector<std::string> snacke = getUpdateMap();
    int newScore = getScorePlayer();
    std::string status = getStatusGame();
    m_callMapSnake(snacke, newScore);
}


void Arcade::Nibbler::setMoveSnacke()
{
    this->move(Arcade::Direction::UP);
}

std::vector<std::string> Arcade::Nibbler::getUpdateMap()
{
    return this->m_MapGames;
}