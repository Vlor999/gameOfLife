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
        ~infoDisplay() = default;
        void showInfo();

        int getHeightDisplay() const {
            return hauteur;
        }

        int getWidthDisplay() const {
            return largeur;
        }
};

infoDisplay::infoDisplay(/* args */)
    : hauteur(sf::VideoMode::getDesktopMode().height), largeur(sf::VideoMode::getDesktopMode().width) {}

void infoDisplay::showInfo() {
    cout << "Hauteur (height): " << hauteur << ", Largeur (width): " << largeur << "\n";
}
