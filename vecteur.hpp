#ifndef VECTEUR_HPP
#define VECTEUR_HPP

class Vecteur {
	private:
		float _x;
		float _y;  // Coordonnées du vecteur

	public:
	// Constructeurs
		Vecteur() : _x(0), _y(0) {}  // Constructeur par défaut
		Vecteur(float x, float y) : _x(_x), _y(_y) {}  // Constructeur avec coordonnées
		void affiche() const;
		float norme() const;
		Vecteur* addition(const Vecteur& v) const;

		// Accesseurs
		float getX() const { return _x; }
		float getY() const { return _y; }
	
};

#endif // VECTEUR_HPP