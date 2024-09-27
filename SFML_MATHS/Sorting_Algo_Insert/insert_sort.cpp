/* Bubble Sorting Viewer */
#include "insert.h"

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;

void generate_random_array(std::vector<int> &arr, int size, int min, int max) {
    arr.clear(); // Clear the vector to ensure it's empty
    arr.reserve(size); // Reserve space for 'size' elements (optional)
    // arr.resize(size); // Resize the vector to the required size

    std::srand(static_cast<unsigned>(std::time(0))); // Seed random number generator

    for (int i = 0; i < size; ++i) {
        int randomNum = min + std::rand() % (max - min + 1);
        arr.push_back(randomNum); // Add random number to the vector
    }
}

void insertion_sort(std::vector<int> &myArray, sf::RenderWindow &window, std::vector<sf::RectangleShape> &rectangles, sf::Text &heading, sf::Sound &click_sound) {
    int temp = 0;
    int nums = myArray.size();
    for (int i = 1; i < nums; i++) {
        // click_sound.play();
        int key = myArray[i];
        int j = i - 1;

        // Move elements of myArray[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && myArray[j] > key) {
            myArray[j + 1] = myArray[j];

            // Update rectangle sizes and color
            rectangles[j + 1].setSize(sf::Vector2f(sizeWidth, myArray[j]));
            rectangles[j + 1].setFillColor(sf::Color::Green);
            rectangles[j].setFillColor(sf::Color::Red);

            // Clear window, draw rectangles, and display
            window.clear(sf::Color::Black);
            for (int k = 0; k < nums; k++) {
                window.draw(rectangles[k]);
            }
            window.display();

            // Sleep for a short duration to visualize the sorting process
            sf::sleep(sf::milliseconds(10));

            // Reset color of rectangles to cyan
            rectangles[j + 1].setFillColor(sf::Color::Cyan);
            rectangles[j].setFillColor(sf::Color::Cyan);

            j--;
        }
        myArray[j + 1] = key;

        // Update the size of the rectangle where the key is placed
        rectangles[j + 1].setSize(sf::Vector2f(sizeWidth, key));
        
        // Update all rectangles to reflect any final changes
        window.clear(sf::Color::Black);
        for (int k = 0; k < nums; k++) {
            window.draw(rectangles[k]);
        }
        window.display();
        
        sf::sleep(sf::milliseconds(10));
    }

    arr_sorted = true;
    heading.setString("Insert Sort Complete");
    heading.setOrigin(249.5f,13.5f);
    // std::cout << heading.getLocalBounds().getSize().x << " " << heading.getLocalBounds().getSize().y << std::endl;
}

int main()
{
    std::vector<int> myArray;

    // Generate random numbers and fill the vector
    generate_random_array(myArray, size, min, max);

    // Print the generated array
    std::cout << "Random Array:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    sf::RenderWindow window(VideoMode(750, 600), "Drawing Graphs");

    std::vector<sf::RectangleShape> rectangles(size);
    for(int i = 0; i < size; i++) {
        rectangles[i].setFillColor(sf::Color::Cyan);
        rectangles[i].setOutlineColor(sf::Color::Magenta);
        // rectangles[i].setOutlineThickness(-0.5f);
        rectangles[i].setPosition(sf::Vector2f(posGap + (posWidth*i), posHeight));
        rectangles[i].setSize(sf::Vector2f(sizeWidth, myArray[i]));
    }

    sf::Font heading_font;
    if (!heading_font.loadFromFile("../font/PressStart2P-Regular.ttf")) {
        std::cout << "Error loading font - PressStart2P-Regular.ttf" << std::endl;
        return -1;
    }
    sf::Text heading;
    heading.setFont(heading_font);
    heading.setString("Press SPACE_BAR");
    heading.setPosition(sf::Vector2f(375.0f, 500.0f));
    heading.setCharacterSize(25);
    heading.setFillColor(sf::Color::Red);
    heading.setOutlineColor(sf::Color::Blue);
    heading.setOrigin(187.f,13.5f);
    heading.setOutlineThickness(1);
    // std::cout << heading.getLocalBounds().getSize().x << " " << heading.getLocalBounds().getSize().y << std::endl;
    sf::Sound click_sound;
    sf::SoundBuffer click_buffer;
    if (!click_buffer.loadFromFile("../audio/clickSound.wav")) {
        std::cout << "Error loading Audio file" << std::endl;
        return -1;
    }
    click_sound.setBuffer(click_buffer);
    click_sound.setVolume(25.0f);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            else if (event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                if(!arr_sorted) {
                    insertion_sort(myArray, window, rectangles, heading,click_sound);
                }
            }
        }
        
        window.clear(sf::Color::Black);
        window.draw(heading);
        for(int k=0;k<size;k++) {
            window.draw(rectangles[k]);
        }
        window.display();

        // sf::sleep(sf::seconds(0.5)); // Optional sleep to reduce CPU usage
    }

    return 0;
}
