//
// Created by Nicolas Cuenca on 5/14/2021.
//

#ifndef PROJECT_IMAGE_H
#define PROJECT_IMAGE_H
#include "map"
#include "SFML/Graphics.hpp"
#include <string>


class Image {
public:
    enum image{FOLDER, FILE};
    static std::map<image, sf::Texture> images;
    static std::map<image, bool> loaded;
    static sf::Texture& getImage(image image);
    static void loadImage(image image);
    static std::string getImagePath(image image);
    

};


#endif //PROJECT_IMAGE_H
