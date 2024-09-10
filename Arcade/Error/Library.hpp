/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade.hpp
*/

#pragma once

#include "AError.hpp"

namespace ArcadeError {

    class Library : public AError {
        public:
            Library(const std::string &messageError) : AError(messageError) {};
            ~Library() = default;
    };
}