/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#include "Core.hpp"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

Arcade::Core::Core(const std::string &libInput) : m_libInput(libInput), m_selected(-1), m_mapUpdated(false)
{
    const std::vector<std::string> graphicLibraries = {PATH_LIBRARY_SFML,PATH_LIBRARY_NCURSES,PATH_LIBRARY_SDL2};
    const std::vector<std::string> gameLibraries = {PATH_GAMES_SNACKES, PATH_GAMES_NIBLLER};

    bool graphicalLibraryFound = false;
    bool gameLibraryFound = false;

    for (const auto& lib : graphicLibraries) {
        this->m_LibraryGraphic.push_back("./" + lib);
        //std::cout << "Graphical Library: " << "./" + lib << std::endl; 
        if (!graphicalLibraryFound && is_findLibraryGraphical(m_LibraryGraphic, libInput)) {
            graphicalLibraryFound = true;
        }
    }

    for (const auto& lib : gameLibraries) {
        this->m_LibraryGames.push_back("./" + lib);
        //std::cout << "Games Library: " << "./" + lib << std::endl; 
        if (!gameLibraryFound && is_findLibraryGames(m_LibraryGames, libInput)) {
            gameLibraryFound = true;
        }
    }

    if (graphicalLibraryFound) {
        findIndexGraphical(libInput);
    }
    if (gameLibraryFound) {
        findIndexGames(libInput);
    }
    if (!graphicalLibraryFound && !gameLibraryFound) {
        throw ArcadeError::Library("The library hasn't been found !");
        throw ArcadeError::GamesError("The Games hasn't been found !");
    }
}

void Arcade::Core::findIndexGraphical(const std::string &libInput)
{

    for (int i = 0; i < this->m_LibraryGraphic.size(); ++i) {
        if (std::strcmp(m_LibraryGraphic[i].c_str(), libInput.c_str()) == 0)
            this->m_indexGraphical = i;
    }
}

void Arcade::Core::findIndexGames(const std::string &libInput)
{
    for (int i = 0; i < this->m_LibraryGames.size();++i) {
        if (std::strcmp(m_LibraryGames[i].c_str(), libInput.c_str()) == 0)
            this->m_indexGames = i;
    }
}

std::unique_ptr<Arcade::DLLoader<Arcade::IDisplayModule>> Arcade::Core::LoadingLibraryGraphical()
{
    return std::make_unique<Arcade::DLLoader<Arcade::IDisplayModule>>(this->m_libInput);
}

std::vector<std::unique_ptr<Arcade::DLLoader<Arcade::IGames>>> Arcade::Core::LoadingLibraryGames()
{
    std::vector<std::unique_ptr<Arcade::DLLoader<Arcade::IGames>>> myLoader;

    for (const auto& libGames : this->m_LibraryGames)
        myLoader.push_back(std::make_unique<Arcade::DLLoader<Arcade::IGames>>(libGames));
    return myLoader;
}


void Arcade::Core::startArcade()
{
    std::unique_ptr<Arcade::DLLoader<Arcade::IDisplayModule>> libraryGraphical = LoadingLibraryGraphical();
    std::vector<std::unique_ptr<Arcade::DLLoader<Arcade::IGames>>> libraryGames = LoadingLibraryGames();


    this->m_moduleGraphic.push_back(libraryGraphical->getInstance("entryPoint"));


    for (int i = 0; i < libraryGames.size();i++)
        this->m_moduleGames.push_back(libraryGames[i]->getInstance("entryPointGames"));
    
    if (manage_Menu() == Arcade::GAMES_LAUCH::MENU_CLOSE && this->getSelectedGames() != -1) {
        this->openWindowAndStartGame();
    }
}

void Arcade::Core::updateGamesMoving(std::vector<std::string> platformGames)
{
    this->m_moduleGames.at(this->m_selected)->clearGames();
    platformGames = this->m_moduleGames.at(this->m_selected)->getPlateFormGaming();
}

bool Arcade::Core::getStatusUpdated()
{
    return this->m_mapUpdated;
}

void Arcade::Core::setStatusUpdate(bool update)
{
    this->m_mapUpdated = update;
}

void Arcade::Core::openWindowAndStartGame()
{
    this->m_moduleGames.at(this->m_selected)->init_Games();

    std::vector<std::string> platformGames = this->m_moduleGames.at(this->m_selected)->getPlateFormGaming();
    auto touchPress = [this](Arcade::Key key) {
        switch(key) {
            case Arcade::Key::up:
                this->m_moduleGames.at(this->m_selected)->move(Arcade::Direction::UP);
                break;
            case Arcade::Key::down:
                this->m_moduleGames.at(this->m_selected)->move(Arcade::Direction::DOWN);
                break;
            case Arcade::Key::left:
                this->m_moduleGames.at(this->m_selected)->move(Arcade::Direction::LEFT);
                break;
            case Arcade::Key::right:
                this->m_moduleGames.at(this->m_selected)->move(Arcade::Direction::RIGHT);
                break;
            default:
                break;
        }
    };
    bool isUpdated = false;
    int myScore = 0;
    auto UpdateMap = [this](std::vector<std::string> myMapUpdated, int score) {
        this->m_moduleGraphic.at(0)->drawGames(myMapUpdated, 1,score);
    };
    this->m_moduleGraphic.at(0)->setKeyPressedCallBack(touchPress);
    this->m_moduleGames.at(this->m_selected)->setGamingPlatFromCallBack(UpdateMap);
    if (isUpdated == false) {
        this->m_moduleGraphic.at(0)->drawGames(platformGames, 0, myScore);
        isUpdated = true;
    }
}

void Arcade::Core::setSelectedGames(int select)
{
    this->m_selected = select;
}
