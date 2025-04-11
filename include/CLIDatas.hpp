#pragma once
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class CLIDatas
{
private:
    string currentFile;
    string nameOfGame;
    float proportion;
    int attente;
    bool isHelp = false;
    bool isManual = false;
    int height = 100;
    int width = 100;
public:
    CLIDatas() : proportion(1.0), nameOfGame("Game of life"), attente(0) {}

    CLIDatas(int argc, char* argv[]) : proportion(1.0), nameOfGame("Game of life"), attente(0), currentFile(argv[0]) {
        for (int i = 1; i < argc; i++) {
            if (std::strcmp(argv[i], "--p") == 0) {
                if (i + 1 < argc) {
                    proportion = std::atof(argv[i + 1]);
                    i++;
                } else {
                    proportion = 1.0;
                }
            } else if (std::strcmp(argv[i], "--help") == 0) {
                isHelp = true;
            } else if (std::strcmp(argv[i], "--m") == 0) {
                isManual = true;
                cout << "Command : --m not yet available\n";
            } else if (std::strcmp(argv[i], "--n") == 0 && i + 1 < argc) {
                nameOfGame = argv[i + 1];
                i++;
            } else if (std::strcmp(argv[i], "--s") == 0 && i + 1 < argc) {
                attente = std::atoi(argv[i + 1]);
                i++;
            } else if (std::strcmp(argv[i], "--size") == 0 && i + 2 < argc) {
                height = std::atoi(argv[i + 1]);
                width = std::atoi(argv[i + 1]);
                i += 2;
            } else {
                displayHelp();
                return;
            }
        }

        if (isHelp) {
            displayHelp();
            exit(EXIT_SUCCESS);
        }
    }

    ~CLIDatas() = default;

    float getProportion() const {
        return proportion;
    }

    string getNameOfGame() const {
        return nameOfGame;
    }

    bool getIsManual() const {
        return isManual;
    }

    int getAttente() const {
        return attente;
    }

    int getHeight() const {
        return height;
    }

    int getWidth() const {
        return width;
    }

    void displayHelp() const {
        std::cout << "Usage: " << currentFile << " [options]\n"
                  << "Options:\n"
                  << "  --p <value>               Set the proportion value\n"
                  << "  --n <name of your game>   Set the name of the window\n"
                  << "  --m                       You are going to set the position of the object\n"
                  << "  --help                    Display this help message\n";
    }
};
