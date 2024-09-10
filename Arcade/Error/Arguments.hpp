/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade.hpp
*/

#pragma once

#include "AError.hpp"

const char FEW_ARGS[] = "There is too few args !";
const char MANY_ARGS[] = "There is too many args !";

namespace ArcadeError {

    class ArgsError : public AError {
        public:
            ArgsError(const std::string &messageError) : AError(messageError) {};
            ~ArgsError() = default;
    };
}