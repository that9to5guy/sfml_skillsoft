/* Global Variables for Bubble Sort */
#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>   // for std::rand and std::srand
#include <ctime>     // for std::time
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

bool arr_sorted = false;

int size = 100;   // Size of the array
int min = 10;     // Minimum value of random numbers
int max = 200;   // Maximum value of random numbers

float posHeight = 50.f;
float posWidth = 7.5f;
float posGap = 0.625f;
float sizeWidth = 6.25f;
