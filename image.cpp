#include "image.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm> 
#include <stdexcept> 
#include <fstream>

//Allocaion de la mémoire
void Image::allocateData() {
	// On alloue une zone de memoire de taille w*h pour stocker les pixels de l'image
    data = new unsigned char[w * h];
}

//Libération de la mémoire
void Image::freeData() {
	//On utilise la fontion delete[] afin de desalouer la mémoire occupée dans data
    delete[] data;
}

// Constructeur par défaut
Image::Image(const std::string& fichier) {
    load(fichier); 
}

// Constructeur par copie
Image::Image(const Image& other) : w(other.w), h(other.h) {
    allocateData();
    std::copy(other.data, other.data + w * h, data); 
}

// Opérateur d'assignement
Image& Image::operator=(const Image& other) {
    if (this != &other) {
        freeData(); 
        w = other.w; 
        h = other.h;
        allocateData();
        std::copy(other.data, other.data + w * h, data);
    }
    return *this;
}



	// DESTRUCTEUR

Image::~Image() {
    freeData();
}




	// GETTERS  

//Get de la valeur d'un pixel
unsigned char Image::get(int i, int j) const {
    if (i < 0 || i >= static_cast<int>(h) || j < 0 || j >= static_cast<int>(w)) {
        throw std::out_of_range("Indices de pixel hors limites");
    }
    return data[i * w + j];
}


//Get de la valeur de la largeure
size_t Image::get_w() const {
    return w;
}

//Get de la valeur de la hauteur
size_t Image::get_h() const {
    return h;
}

//Set de la valeur d'un pixel
void Image::set(int i, int j, unsigned char valeur) {
    if (i < 0 || i >= static_cast<int>(h) || j < 0 || j >= static_cast<int>(w)) {
        throw std::out_of_range("Indices de pixel hors limites");
    }
    data[i * w + j] = valeur;
}

//Chargement d'une image à partir du nom d'un fichier
void Image::load(const std::string& fichier)
{
	std::ifstream f(fichier.c_str());
	

	//Test que l'ouverture ait été bien réalisée
	if(!f.good())
		throw std::runtime_error("Unable to open file for reading");
	
	//On test que l'image soit bien de type PGM
	std::string kind;
	f >> kind;
	if(kind != "P5")
		throw std::runtime_error("File is not a PGM image");
		
	f >> w >> h;	
	data = new unsigned char[w * h];
	f.read((char*)data, w * h);
}

// Sauvegarde d'une image dans un fichier
void Image::write(const std::string& fichier) const{
  	std::ofstream ofs(fichier);
  	if(!ofs.good())
    	throw std::runtime_error("Unable to open file for writing");

	//On écrit le header de l'image (type P5 et taille w*h ainsi que la valeure maximale du pixel 255)
  	ofs << "P5" << std::endl << w << " " << h << std::endl << 255 << std::endl;
  	ofs.write((char*)data, w*h);
  
}