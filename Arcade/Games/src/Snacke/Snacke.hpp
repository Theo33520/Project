/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#pragma once

#include "../IGames.hpp"
#include "../../../MapGames/IMapGames.hpp"
#include "../../../MapGames/MapGames.hpp"
#include <vector>
#include <map>
#include <functional>

namespace Arcade {

    class Snacke : public IGames {
        private:
            std::string m_nameGames;
            std::pair<int, int> m_sizeMap;
            std::pair<int, int> m_head;
            std::vector<std::pair<int, int>> m_tail;
            std::pair<int, int> m_top;
            std::pair<int, int> m_below;

            float m_speed;
            int m_score;
            std::string m_titleGames;
            int m_sizeObject;
            std::vector<std::string> m_MapGames;
            std::unique_ptr<Arcade::IMapGames> m_instanceMap;
            Direction m_curDir;
            MOVE m_move;
            mapSnacke m_callMapSnake;
            std::pair<int, int> pair_ij;
        public:
            Snacke() : m_instanceMap(nullptr), pair_ij(21, 20) {};
            ~Snacke() override = default;
            std::string getName() const override;
            std::pair<int, int> getSizeMapGames() override;
            float getSpeedPlayers() override;
            int getScorePlayer() override;
            std::string titleGameMap() const override;
            std::pair<int, int> getPairFruit() {
                return pair_ij;
            }

            void setFruitPair(int x,int y) {
                pair_ij.first = x;
                pair_ij.second = y;
            };

            /*------------GAMES------------*/
            void init_Games() override;
            void stop_Games() override;
            std::vector<std::string> getPlateFormGaming() override;
            void move(Arcade::Direction direction) override;
            /*-------Head-----*/
            std::pair<int, int> getPositionsHead() const override {
                return this->m_head;
            }
            void setPositionsHead(int x, int y) override {
                this->m_head.first = x;
                this->m_head.second = y;
            }

            /*--------------Directions------------*/
            Direction getCurrentPosition() const override;
            void setDirection(Direction direction) override;
            
            /*-----Positions-----*/
            void setPositions(MOVE move) override {
                this->m_move = move;
            }
            MOVE getPosition() const override {
                return this->m_move;
            };
            void snackeStarting() override;
            void setMoveSnacke() override;
            void clearGames() override {
                this->m_MapGames.clear();
            }
            void SetGamingPlatForm(int x, int y, char newChar) override {
                m_MapGames[x][y] = newChar;
            }

            void setGamingPlatFromCallBack(mapSnacke callMap) override {
                this->m_callMapSnake = callMap;
            };


            std::vector<std::string> getUpdateMap();
            void setScorelayersCall() {
                this->m_score = m_score + 1;
            };
    };
}

extern "C" Arcade::IGames *entryPointGames() 
{
    return new Arcade::Snacke;
}