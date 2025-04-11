#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

#include "creationTableau.hpp"
#include "case.hpp"

using namespace std;

class gameInfo
{
    private:
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
        ~gameInfo() = default;

        float getCellHeight() const {
            return cellHeight;
        }

        float getCellWidth() const {
            return cellWidth;
        }

        sf::RenderWindow& getWindow() {
            return window;
        }

        sf::RectangleShape& getCell() {
            return cell;
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
    : nameOfGame(std::move(nameOfGame)), hauteur(hauteur), largeur(largeur), boardHeight(boardHeight), boardWidth(boardWidth),
      cellHeight(static_cast<float>(largeur) / boardHeight), cellWidth(static_cast<float>(hauteur) / boardWidth),
      window(sf::VideoMode(hauteur, largeur), sf::String(this->nameOfGame)), cell(sf::Vector2f(cellWidth, cellHeight)) {}

void gameInfo::setBox(int x, int y, int cellValue) {
    cell.setPosition(x * cellWidth, y * cellHeight);
    cell.setFillColor(sf::Color(cellValue, cellValue, cellValue));
    window.draw(cell);
}

void gameInfo::initializeVertices() {
    cellsVertices.setPrimitiveType(sf::Quads);
    cellsVertices.resize(boardHeight * boardWidth * 4);
}

void gameInfo::updateVertices(const Tableau& gameBoard) {
    for (int y = 0; y < gameBoard.getHauteur(); y++) {
        for (int x = 0; x < gameBoard.getLargeur(); x++) {
            Case currentCell = gameBoard.getCell(y, x);
            int cellValue = currentCell.getValue();
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
