/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#pragma once

#include <iostream>
#include <string>
#include <dlfcn.h>
#include "../lib/src/IDisplayModule.hpp"
#include "../Games/src/IGames.hpp"


const std::string ERROR_OPENING = "The library hasn't been loaded correctly";
const std::string ERROR_CLOSING = "The library hasn't been closed correctly";

namespace Arcade {

    template<typename T>
    class DLLoader {
        private:
            void *m_handle;
        public:
            typedef T* (*EntryPointFunc)();
            DLLoader(const std::string &path) {
                this->m_handle = dlopen(path.c_str(), RTLD_LAZY);
                if (!this->m_handle) {
                    std::cerr << ERROR_OPENING << dlerror() << std::endl;
                    exit(84);
                }
            }
            ~DLLoader() {
                if (dlclose(this->m_handle) != 0)
                    std::cerr << ERROR_CLOSING << dlerror() << std::endl;
                else
                    this->m_handle = nullptr;
            };

            T *getInstance(const std::string &entry) {
                EntryPointFunc entryPoint = reinterpret_cast<EntryPointFunc>(dlsym(this->m_handle, entry.c_str()));
                if (!entryPoint) {
                    std::cerr << "dlsym() error : " << dlerror() << std::endl;
                    return nullptr;
                }
                return entryPoint();
            }

            void unLoader() {
                if (dlclose(this->m_handle) != 0)
                    std::cerr << ERROR_CLOSING << dlerror() << std::endl;
                else
                    this->m_handle = nullptr;
            }
    };
}
