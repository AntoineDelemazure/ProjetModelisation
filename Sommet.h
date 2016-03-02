#pragma once
#include "stdlib.h"
#include <iostream>
#include "Arete.h"
#include <vector>

class Sommet
{
public:
	Sommet(int n){
		name = n;
		poids = 0;
		vector<Arete*> aretes;

	};
	~Sommet(){};

	void ajouterArete(Arete* a){ /*On considere le graphe comme connexe, les 
								 aretes inexistantes seront instancié à NULL.
								 Les arêtes DOIVENT  donc être ajouté dans l'ordre*/
		aretes.push_back(a);
	};

	// === GET SET ===
	int getName(){
		return name;
	};
	int getPoids(){
		return poids;
	};
	void setPoids(int p){
		poids = p;
	};
	vector<Arete*> getAretes(){
		return aretes;
	};
	int getNouveauPoids(){
		return nouveauPoids;
	}
	void setNouveauPoids(int i){
		nouveauPoids = i;
	}

private:
	int name;
	int poids;
	int nouveauPoids;
	vector<Arete*> aretes;
};