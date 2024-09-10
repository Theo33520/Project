/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade.hpp
*/

#pragma once

#include "IError.hpp"

namespace ArcadeError {

    class AError : public IError {
    private:
        std::string m_messageError;

    public:
        AError(const std::string& messageError) {
            this->m_messageError = messageError;
        }
        virtual ~AError() noexcept override = default;
        const char* what() const noexcept override {
            return m_messageError.c_str();
        }
    };
}