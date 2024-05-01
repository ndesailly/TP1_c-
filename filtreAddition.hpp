#ifndef FILTREADDITION_HPP
#define FILTREADDITION_HPP

#include "filtre.hpp"
#include "image.hpp"
class FiltreAddition : public Filtre {
private:
    int valeur; 

public:
    // Constructeur
    FiltreAddition(int valeur);
    void apply(Image& i) const override;
};

#endif // FILTREADDITION_HPP