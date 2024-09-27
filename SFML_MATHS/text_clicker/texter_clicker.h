/* Global Variables for Bubble Sort */
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>   // for std::rand and std::srand
#include <ctime>     // for std::time
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int SIZE = 10;

/* Version2 :Implement the game state mechanism with flags or vars ??? */

bool START = false;
bool inGame = false;
bool enGame = false;
int points = 0;

sf::Keyboard::Key current_key = sf::Keyboard::Space;

// Define the key-to-string mapping
std::map<sf::Keyboard::Key, std::string> keyMappings = {
    {sf::Keyboard::Space, "S P A C E B A R"},
    {sf::Keyboard::Backspace, "B A C K S P A C E"},
    {sf::Keyboard::Enter, "E N T E R"},
    {sf::Keyboard::Escape, "E S C A P E"},
    {sf::Keyboard::RShift, "R - S H I F T"},
    {sf::Keyboard::LShift, "L - S H I F T"},
    {sf::Keyboard::RControl, "R - C O N T R O L"},
    {sf::Keyboard::LControl, "L - C O N T R O L"},
    {sf::Keyboard::RAlt, "R - A L T"},
    {sf::Keyboard::LAlt, "L - A L T"},
    {sf::Keyboard::Tab, "T A B"},
    {sf::Keyboard::End, "E N D"},
    {sf::Keyboard::Home, "H O M E"},
    {sf::Keyboard::Insert, "I N S E R T"},
};
