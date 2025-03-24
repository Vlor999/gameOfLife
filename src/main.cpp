#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>

#include "include/creationTableau.hpp"
#include "include/infoDisplay.hpp"
#include "include/CLIDatas.hpp"
#include "include/gameInfo.hpp"

int main(int argc, char *argv[]) {
    CLIDatas myCLIDatas = CLIDatas(argc, argv);
    float proportionPanel = myCLIDatas.getProportion();

    infoDisplay myInfo;
    int largeur = myInfo.getHeightDisplay() * proportionPanel;
    int hauteur = myInfo.getWidthDisplay() * proportionPanel;

    int boardWidth = 100;
    int boardHeight = 100;
    Tableau gameBoard(boardHeight, boardWidth);
    if (myCLIDatas.getIsManual()) {
        addManualValuesTableau(gameBoard);
    } else {
        addRandomValuesTableau(gameBoard);
    }

    gameInfo myGame(myCLIDatas.getNameOfGame(), hauteur, largeur, boardHeight, boardWidth);
    sf::RenderWindow& window = myGame.getWindow();

    myGame.initializeVertices();

    // Boucle principale
    int tempsAttenteMilli = myCLIDatas.getAttente();
    bool isPaused = false;
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
                if (event.key.code == sf::Keyboard::Space) {
                    isPaused = !isPaused;
                }
                // Add other key events here if needed
            }
        }

        if (!isPaused) {
            updateTableau(gameBoard);
        }
        myGame.updateVertices(gameBoard);
        myGame.render();
        sf::sleep(sf::milliseconds(tempsAttenteMilli));
    }

    return EXIT_SUCCESS;
}
