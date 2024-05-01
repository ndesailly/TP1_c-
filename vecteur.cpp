#include "vecteur.hpp"
#include <iostream>
#include <cmath>

// Afficher les coordonnées
void Vecteur::affiche() const {
    std::cout << "(" << _x << "," << _y << ")\n" << std::endl;
}

// Calculer la norme
float Vecteur::norme() const {
    return std::sqrt(_x * _x + _y * _y);
}

// Additionner avec un autre vecteur
Vecteur* Vecteur::addition(const Vecteur& v) const {
    return new Vecteur(_x + v._x, _y + v._y);
}