#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

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
}

gameInfo::~gameInfo()
{
}
