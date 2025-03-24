#include <SFML/Graphics.hpp>
#include <vector>
#include "include/creationTableau.hpp"

int main() {
    // Création de la fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game of Life");
    
    // Création du tableau pour le jeu de la vie
    Tableau gameBoard = creationTableau();
    
    // Configuration d'un cercle de test pour vérifier que SFML fonctionne
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(375, 275);

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
