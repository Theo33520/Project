/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#pragma once

#include "IMapGames.hpp"

namespace Arcade {

    class MapGames : public IMapGames {
        private:
            std::vector<std::string> m_mapGames;
            std::string FILE_PATH_MAP = "./assets/SnakeSquare.txt";
        public:
            MapGames() = default;
            ~MapGames() override = default;
            std::vector<std::string> getMapGames() override {
                std::ifstream file(FILE_PATH_MAP);
                std::string line;
                while (std::getline(file, line)) {
                    this->m_mapGames.push_back(line);
                }
                file.close();
                return this->m_mapGames;
            }
    };
}