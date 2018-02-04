#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <Windows.h>
#include <exception>
#include "Misc.h"

struct ExceptionNoFocus : std::exception {
    const char* what() const noexcept { return "\n\n!!!ERROR!!!\nCritical failure on Interaction: there is no object in focus currently."; }
};