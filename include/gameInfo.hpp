#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

#include "creationTableau.hpp"

using namespace std;

class gameInfo
{
    private:
        /* data */
        string nameOfGame;
        int hauteur;
        int largeur;
        int boardHeight;
        int boardWidth;

        float cellWidth;
        float cellHeight;
        
        sf::RenderWindow window;
        sf::RectangleShape cell;
        sf::VertexArray cellsVertices;

    public:
        gameInfo(string nameOfGame, int hauteur, int largeur, int boardHeight, int boardWidth);
        ~gameInfo();

        float getCellHeight(){
            return cellHeight;
        }

        float getCellWidth(){
            return cellWidth;
        }

        sf::RenderWindow& getWindow(){
            return this->window;
        }

        sf::RectangleShape& getCell(){
            return this->cell;
        }

        sf::VertexArray& getCellsVertices() {
            return cellsVertices;
        }

        void setBox(int x, int y, int cellValue);
        void initializeVertices();
        void updateVertices(const Tableau& gameBoard);
        void render();
};

gameInfo::gameInfo(string nameOfGame, int hauteur, int largeur, int boardHeight, int boardWidth)
{
    this->nameOfGame = nameOfGame;
    this->hauteur = hauteur;
    this->largeur = largeur;
    this->boardHeight = boardHeight;
    this->boardWidth = boardWidth;

    this->cellHeight = static_cast<float>(largeur) / boardHeight;
    this->cellWidth = static_cast<float>(hauteur) / boardWidth;

    this->window.create(sf::VideoMode(hauteur, largeur), nameOfGame);
    this->cell = sf::RectangleShape(sf::Vector2f(cellWidth, cellHeight));
}

void gameInfo::setBox(int x, int y, int cellValue){
    this->cell.setPosition(x * this->cellWidth, y * this->cellHeight);
    this->cell.setFillColor(sf::Color(cellValue, cellValue, cellValue));
    this->window.draw(cell);
}

void gameInfo::initializeVertices() {
    cellsVertices.setPrimitiveType(sf::Quads);
    cellsVertices.resize(boardHeight * boardWidth * 4);
}

void gameInfo::updateVertices(const Tableau& gameBoard) {
    for (int y = 0; y < gameBoard.getHauteur(); y++) {
        for (int x = 0; x < gameBoard.getLargeur(); x++) {
            int cellValue = gameBoard.getCell(y, x);
            sf::Vertex* quad = &cellsVertices[(y * boardWidth + x) * 4];

            quad[0].position = sf::Vector2f(x * cellWidth, y * cellHeight);
            quad[1].position = sf::Vector2f((x + 1) * cellWidth, y * cellHeight);
            quad[2].position = sf::Vector2f((x + 1) * cellWidth, (y + 1) * cellHeight);
            quad[3].position = sf::Vector2f(x * cellWidth, (y + 1) * cellHeight);

            sf::Color color(cellValue, cellValue, cellValue);
            quad[0].color = color;
            quad[1].color = color;
            quad[2].color = color;
            quad[3].color = color;
        }
    }
}

void gameInfo::render() {
    window.clear(sf::Color::Black);
    window.draw(cellsVertices);
    window.display();
}

gameInfo::~gameInfo()
{
}
