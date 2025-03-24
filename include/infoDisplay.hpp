#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std;

class infoDisplay
{
    private:
        int hauteur;
        int largeur;
    public:
        infoDisplay(/* args */);
        ~infoDisplay();
        void showInfo();

        int getHeightDisplay(){
            return this->hauteur;
        }

        int getWidthDisplay(){
            return this->largeur;
        }
};

infoDisplay::infoDisplay(/* args */)
{
    this->hauteur = sf::VideoMode::getDesktopMode().height;
    this->largeur = sf::VideoMode::getDesktopMode().width;
}

infoDisplay::~infoDisplay()
{
}

void infoDisplay::showInfo(){
    cout << "Hauteur (height): " << this->hauteur << ", Largeur (width): " << this->largeur << "\n";
}
