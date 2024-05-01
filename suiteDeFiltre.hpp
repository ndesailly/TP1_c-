// SuiteDeFiltre.hpp
#ifndef SUITEDEFILTRE_HPP
#define SUITEDEFILTRE_HPP

#include "filtre.hpp"
#include <vector>

class SuiteDeFiltre : public Filtre {
private:
    std::vector<Filtre*> filtres; 

public:
    // Constructeur
    SuiteDeFiltre();
    void add(Filtre* f);
    void apply(Image& i) const override;

    // Destructeur
    ~SuiteDeFiltre();
};

#endif // SUITEDEFILTRE_HPP
