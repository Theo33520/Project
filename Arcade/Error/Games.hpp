/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade.hpp
*/

#pragma once

#include "AError.hpp"

namespace ArcadeError {

    class GamesError : public AError {
        public:
            GamesError(const std::string &messageError) : AError(messageError) {};
            ~GamesError() = default;
    };
}