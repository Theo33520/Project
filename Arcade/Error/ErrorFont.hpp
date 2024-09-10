/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade.hpp
*/

#pragma once

#include "AError.hpp"

namespace ArcadeError {

    class ErrorFont : public AError {
        public:
            ErrorFont(const std::string &messageError) : AError(messageError) {};
            ~ErrorFont() = default;
    };
}