#include <iostream>
#include "Plateau.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::string choix;
    Plateau *plateau = new Plateau();
    plateau->affichePlateau();


    std::cout << "************************************************" << std::endl;
    std::cout << "*     --------------------------------         *" << std::endl;
    std::cout << "*      Bienvenue sur ChessVariants             *" << std::endl;
    std::cout << "*     --------------------------------         *" << std::endl;
    std::cout << "*                                              *" << std::endl;
    std::cout << "*          Choisir le Jeu                      *" << std::endl;
    std::cout << "*                                              *" << std::endl;
    std::cout << "*        1/Jeu de Dames Anglaise               *" << std::endl;
    std::cout << "*        2/Jeu de Dames Francaise              *" << std::endl;
    std::cout << "*        4/Jeu d'Echecs                        *" << std::endl;
    std::cout << "*                                              *" << std::endl;
    std::cout << "*          Votre choix:                        *" << std::endl;
    std::cout << "*                                              *" << std::endl;
    std::cout << "************************************************" << std::endl;

    // menu de jeu pour choisir a completer une fois qu'on aura fait les jeux ..
    return 0;

}
