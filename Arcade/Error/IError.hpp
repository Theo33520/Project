/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade.hpp
*/

#pragma once


namespace ArcadeError {

    enum class CodeError {
        SUCCESS = 0,
        FAILURE = 84
    };

    class IError : public std::exception {
    public:
        virtual ~IError() noexcept = default;
        virtual const char* what() const noexcept = 0;
    };

}
