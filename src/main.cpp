#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>

#include "include/creationTableau.hpp"
#include "include/infoDisplay.hpp"
#include "include/CLIDatas.hpp"
#include "include/gameInfo.hpp"
#include "include/waiter.hpp"

int main(int argc, char *argv[]) {
    CLIDatas myCLIDatas = CLIDatas(argc, argv);
    float proportionPanel = myCLIDatas.getProportion();

    infoDisplay myInfo;
    int largeur = myInfo.getHeightDisplay() * proportionPanel;
    int hauteur = myInfo.getWidthDisplay() * proportionPanel;
    
    int boardWidth = 100;
    int boardHeight = 100;
    Tableau gameBoard(boardHeight, boardWidth);
    addRandomValuesTableau(gameBoard);

    gameInfo myGame = gameInfo(myCLIDatas.getNameOfGame(), hauteur, largeur, boardHeight, boardWidth);
    sf::RenderWindow& window = myGame.getWindow();
    sf::RectangleShape& cell = myGame.getCell();
    
    // Boucle principale
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        
        // Dessin de chaque cellule du tableau
        for (int y = 0; y < gameBoard.getHauteur(); y++) {
            for (int x = 0; x < gameBoard.getLargeur(); x++) {
                int cellValue = gameBoard.getCell(y, x);
                myGame.setBox(x, y, cellValue);
            }
        }
        
        window.display();
        
        updateTableau(gameBoard);
    }
    
    return EXIT_SUCCESS;
}
