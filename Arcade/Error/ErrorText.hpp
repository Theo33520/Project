/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade.hpp
*/

#pragma once

#include "AError.hpp"

namespace ArcadeError {

    class ErrorText : public AError {
        public:
            ErrorText(const std::string &messageError) : AError(messageError) {};
            ~ErrorText() = default;
    };
}