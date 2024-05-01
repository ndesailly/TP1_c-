#include "matrice.hpp"
#include <iostream>

int main() {
    // Test de la construction d'une matrice nulle de taille donnée
    Matrice matrice1(3, 3);
    std::cout << "Matrice 1 :\n" << matrice1 << std::endl;

    // Test de l'accès en lecture et en écriture à la case (i, j)
    matrice1(0, 0) = 1.0;
    matrice1(1, 1) = 2.0;
    matrice1(2, 2) = 3.0;
    std::cout << "Matrice 1 après modifications :\n" << matrice1 << std::endl;

    // Test de la copie entre deux matrices
    Matrice matrice2 = matrice1;
    std::cout << "Matrice 2 (copie de Matrice 1) :\n" << matrice2 << std::endl;

    // Test de l'addition entre matrices
    Matrice matrice3 = matrice1 + matrice2;
    std::cout << "Matrice 3 (addition de Matrice 1 et Matrice 2) :\n" << matrice3 << std::endl;

    // Test de la multiplication d'une matrice par un scalaire
    Matrice matrice4 = matrice1 * 2.0;
    std::cout << "Matrice 4 (matrice1 * 2.0) :\n" << matrice4 << std::endl;

    // Test de la trace d'une matrice carrée
    double trace = matrice1.trace();
    std::cout << "Trace de Matrice 1 : " << trace << std::endl;

    // Test de la comparaison de matrices
    std::cout << "Matrice 1 et Matrice 2 sont-elles égales ? " << (matrice1 == matrice2 ? "Oui" : "Non") << std::endl;

    // Test de la méthode renvoyant une matrice identité d'une taille donnée
    Matrice identite = Matrice::identity(3);
    std::cout << "Matrice identité de taille 3 :\n" << identite << std::endl;

    // Test de la méthode renvoyant une matrice aléatoire d'une taille donnée
    Matrice aleatoire = Matrice::random(3, 3);
    std::cout << "Matrice aléatoire de taille 3x3 :\n" << aleatoire << std::endl;

    return 0;
}
