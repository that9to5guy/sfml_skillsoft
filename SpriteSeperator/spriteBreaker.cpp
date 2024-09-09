#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

// // Function to find the dimensions and positions of sprites in a sprite sheet
// std::vector<sf::IntRect> findSprites(const sf::Texture& spriteSheetTexture)
// {
//     std::vector<sf::IntRect> spriteRects;
//     sf::Vector2u imageSize = spriteSheetTexture.getSize();

//     // Iterate through each pixel in the sprite sheet
//     for (unsigned int y = 0; y < imageSize.y; ++y)
//     {
//         for (unsigned int x = 0; x < imageSize.x; ++x)
//         {
//             // Check if the current pixel is not transparent
//             sf::Color pixelColor = spriteSheetTexture.copyToImage().getPixel(x,y);
//             std::cout << "Pixel (" << x << "," << y << ") : " << pixelColor.toInteger() << std::endl;
            
//             if (pixelColor.toInteger() != 0)
//             {
//                 // Found the top-left corner of a sprite
//                 unsigned int spriteWidth = 0, spriteHeight = 0;

//                 // Find the width of the sprite
//                 for (unsigned int w = x; w < imageSize.x && spriteSheetTexture.copyToImage().getPixel(w, y).a != 0; ++w)
//                     ++spriteWidth;

//                 // Find the height of the sprite
//                 for (unsigned int h = y; h < imageSize.y && spriteSheetTexture.copyToImage().getPixel(x, h).a != 0; ++h)
//                     ++spriteHeight;

//                 // Add the sprite's rectangle to the vector
//                 spriteRects.emplace_back(x, y, spriteWidth, spriteHeight);

//                 // Skip ahead to the end of the current sprite
//                 x += spriteWidth;
//             }
//         }
//     }

//     return spriteRects;
// }

std::vector<sf::IntRect> findSprites(const sf::Texture& spriteSheetTexture)
{
    std::vector<sf::IntRect> spriteRects;
    sf::Image image = spriteSheetTexture.copyToImage();
    sf::Vector2u imageSize = image.getSize();

    // Scan the image row by row
    for (unsigned int y = 0; y < imageSize.y; ++y)
    {
        bool inSprite = false;
        unsigned int spriteLeft = 0;

        for (unsigned int x = 0; x < imageSize.x; ++x)
        {
            // Check if the current pixel is not transparent
            sf::Color pixelColor = image.getPixel(x, y);
            if (pixelColor.a != 0)
            {
                // Found a non-transparent pixel
                if (!inSprite)
                {
                    // Start of a new sprite
                    inSprite = true;
                    spriteLeft = x;
                    std::cout << "Found start of sprite at (" << x << ", " << y << ")" << std::endl;
                }
            }
            else
            {
                // Found a transparent pixel
                if (inSprite)
                {
                    // End of the current sprite
                    inSprite = false;
                    unsigned int spriteWidth = x - spriteLeft;
                    unsigned int spriteHeight = 1;

                    std::cout << "Found end of sprite at (" << x << ", " << y << ")" << std::endl;
                    std::cout << "Sprite width: " << spriteWidth << std::endl;

                    // Find the height of the sprite
                    for (unsigned int h = y + 1; h < imageSize.y; ++h)
                    {
                        bool rowEmpty = true;
                        for (unsigned int w = spriteLeft; w < spriteLeft + spriteWidth; ++w)
                        {
                            if (image.getPixel(w, h).a != 0)
                            {
                                rowEmpty = false;
                                break;
                            }
                        }
                        if (rowEmpty)
                        {
                            std::cout << "Sprite height: " << spriteHeight << std::endl;
                            break;
                        }
                        ++spriteHeight;
                    }

                    // Add the sprite's rectangle to the vector
                    spriteRects.emplace_back(spriteLeft, y, spriteWidth, spriteHeight);
                    std::cout << "Added sprite rect: (" << spriteLeft << ", " << y << ", " << spriteWidth << ", " << spriteHeight << ")" << std::endl;
                }
            }
        }
    }

    return spriteRects;
}


int main()
{
    sf::RenderWindow window(sf::VideoMode(1500, 500), "Sprite Sheet Seperator");

    // Load the sprite sheet texture
    sf::Texture spriteSheetTexture;
    if (!spriteSheetTexture.loadFromFile("cointoss_bg.png"))
    {
        std::cout << "Failed to load sprite sheet texture" << std::endl;
        return 1;
    }

    // Find the individual sprites in the sprite sheet
    std::vector<sf::Sprite> sprites;
    std::vector<sf::IntRect> spriteRects = findSprites(spriteSheetTexture);

    for (const auto& spriteRect : spriteRects)
    {
        sf::Sprite sprite(spriteSheetTexture);
        sprite.setTextureRect(spriteRect);
        sprites.push_back(sprite);
    }

    // Choose the index of the sprite you want to display
    unsigned int spriteIndex = 0; // Change this to the desired sprite index

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // Draw the chosen sprite
        if (!sprites.empty() && spriteIndex < sprites.size()) {
            sprites[spriteIndex].setPosition(sf::Vector2f(100.f,100.f));
            window.draw(sprites[spriteIndex]);
        }
        window.display();
    }

    return 0;
}
