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
		predecesseur = n;
	};
	~Sommet(){};

	//Ici, un vestige d'une autre version. Je le garde pour le plaisir.
	void ajouterArete(Arete* a){
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
	void setPredecesseur(int i){ predecesseur = i; }
	int getPredecesseur(){ return predecesseur; }

private:
	int name;
	int poids;
	int nouveauPoids;
	vector<Arete*> aretes;
	int predecesseur;
};