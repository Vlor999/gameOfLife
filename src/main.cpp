#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include "include/creationTableau.hpp"
#include "include/infoDisplay.hpp"
#include "include/CLIDatas.hpp"

int main(int argc, char *argv[]) {
    CLIDatas myCLIDatas = CLIDatas(argc, argv);
    infoDisplay myInfo;
    myInfo.showInfo();
    int largeur = myInfo.getHeightDisplay() * myCLIDatas.getProportion();
    int hauteur = myInfo.getWidthDisplay() * myCLIDatas.getProportion();
    sf::RenderWindow window(sf::VideoMode(hauteur, largeur), "Game of Life");
    
    Tableau gameBoard = creationTableau();
    addRandomValuesTableau(gameBoard);
    
    // Configuration d'un cercle de test pour vérifier que SFML fonctionne
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition((hauteur - shape.getRadius() * 2) / 2, (largeur - shape.getRadius() * 2) / 2);

    // Boucle principale
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    
    return 0;
}
