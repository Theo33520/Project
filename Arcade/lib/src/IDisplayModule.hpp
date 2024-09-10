/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#pragma once

#include <string>
#include <memory>


#include "../../Error/ErrorFont.hpp"
#include "../../Error/ErrorText.hpp"
#include <vector>
#include <map>
#include <functional>

namespace Arcade {

    enum class WINDOW {
        OPEN,
        CLOSE,
        GAME_SNAKE,
        GAME_NIBBLER,
    };

    enum class Key {
        up,
        down,
        left,
        right,
        unknow
    };

    enum class GAME_EVENT {
        MENU,
        OPENING,
        CLOSED
    };

    class IDisplayModule {
    public:
        virtual ~IDisplayModule() = default;
        virtual WINDOW windowOpen() = 0;

        virtual void createWindow() = 0;
        virtual void createGames() = 0;
        virtual WINDOW closeWindow() const = 0;
        virtual WINDOW windowIsOpen() const = 0;
        virtual void clearWindow() = 0;

        virtual WINDOW OpeningWindow() = 0;
        virtual std::string getNameModule() const = 0;
        virtual void displayWindow() = 0;

        /*MENU AND GAME*/
        virtual bool getStatusMenu() const = 0;
        virtual bool getStatusSnacke() const = 0;
        virtual bool getStatusNibbler() const = 0;

        virtual void setStatusMenu(bool status) = 0;
        virtual void setStatusSnacke(bool status) = 0;
        virtual void setStatusNibbler(bool status) = 0;
        virtual void loadingTitleWindowGames() = 0;

        /*-------------DISPLAY-------------*/
        virtual WINDOW drawMenu() = 0;
        virtual GAME_EVENT drawGames(std::vector<std::string> gamingPlaterform,int mode,int score) = 0;
        virtual void closingWindow() = 0;

        virtual void drawPlateformGames(std::vector<std::string> gamingPlateform) = 0;

        using touchPressed = std::function<void(Key)>;
        virtual void setKeyPressedCallBack(touchPressed callback) = 0;
    };
}
