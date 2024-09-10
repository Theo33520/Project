/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#include "Arcade.hpp"

static void parsing_args(int ac, char **av)
{
    if (ac < 2)
        throw ArcadeError::ArgsError(FEW_ARGS);
    else if (ac > 2)
        throw ArcadeError::ArgsError(MANY_ARGS);
}

int main(int ac, char **av)
{
    try {
        parsing_args(ac,av);
        auto core = std::make_unique<Arcade::Core>(av[1]);
        core->startArcade();
    } catch (const ArcadeError::IError &error) {
        std::cerr << "Error: " << error.what() << std::endl;
        return static_cast<int>(ArcadeError::CodeError::FAILURE);
    }
    return static_cast<int>(ArcadeError::CodeError::SUCCESS);
}