#pragma once
#include "stdlib.h"
#include <iostream>
#include "Arete.h"
#include <vector>

class Sommet
{
public:
	//Constructeur
	Sommet(int n){
		name = n;
		poids = 0;
		predecesseur = n;
	}

	//avant, ici, y avait un vestige de code que je voulais garder, mais finalement
	//j'ai du l'écraser

	//La fonction d'impression
	friend ostream& operator << (ostream& o, Sommet& s){
		o << "Sommet " << s.name
			<< "; poids : " << s.poids << endl;
		return o;
	}

	// === GET SET ===
	int getName(){
		return name;
	};
	int getPoids(){
		return poids;
	};
	void setPoids(int p){
		poids = p;
	}
	void setNouveauPoids(int i){
		nouveauPoids = i;
	}
	void setPredecesseur(int i){ predecesseur = i; }
	int getPredecesseur(){ return predecesseur; }

private:
	int name; // le nom. Permet de récuperer facilement un sommet
	int poids; // le poids, la "distance" entre ce sommet et la source
	int predecesseur; // le prédecesseur dans le plus court chemin depuis la source.
};