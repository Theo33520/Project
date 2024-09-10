/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <thread>
#include <cstring>
#include <vector>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <functional>

#define TOP_MAP 10
#define BELOW_MAP 30

namespace Arcade {

    enum class Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    enum class MOVE {
        FORWARD,
        BACKWARD
    };


    class IGames {
        public:
            virtual ~IGames() = default;
            virtual std::string getName() const = 0;
            
            virtual std::pair<int, int> getSizeMapGames() = 0;
            virtual float getSpeedPlayers() = 0;

            virtual int getScorePlayer() = 0;
            virtual std::string titleGameMap() const = 0;

            /*------------GAMES---------*/
            virtual void init_Games() = 0;
            virtual void stop_Games() = 0;
            virtual std::vector<std::string> getPlateFormGaming() = 0;
            virtual void move(Arcade::Direction direction) = 0;

            /*-------Head-----*/
            virtual std::pair<int, int> getPositionsHead() const = 0;
            virtual void setPositionsHead(int x, int y) = 0;

            /*--------------Directions------------*/
            virtual Direction getCurrentPosition() const = 0;
            virtual void setDirection(Direction direction) = 0;
            
            /*-----Positions-----*/
            virtual void setPositions(MOVE move) = 0;
            virtual MOVE getPosition() const = 0;

            virtual void snackeStarting() = 0;
            virtual void setMoveSnacke() = 0;
            virtual void clearGames() = 0;
            virtual void SetGamingPlatForm(int x, int y, char newChar) = 0;

            using mapSnacke = std::function<void(std::vector<std::string>, int)>;
            virtual void setGamingPlatFromCallBack(mapSnacke callMap) = 0;
    };

    const std::string SNACKE_NAME = "Snacke";
    const std::string NIBBLER_NAME = "Nibbler";
}