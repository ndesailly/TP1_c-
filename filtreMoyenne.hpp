#ifndef FILTREMOYENNE_HPP
#define FILTREMOYENNE_HPP

#include "filtre.hpp"
#include "image.hpp" 

class FiltreMoyenne : public Filtre {
private:
    int taille; 

public:
    // Constructeur
    FiltreMoyenne(int taille);
    void apply(Image& i) const override;
};

#endif // FILTREMOYENNE_HPP
