#pragma once
#include "stdlib.h"
#include <iostream>

using namespace std;

class Arete
{
public:
	//J'aime pas trop cette façon de faire mais tant pis, je suis trop malade pour etre intelligent.
	Arete(int p, bool e){
		poids = p;
		existence = e;
	};

	~Arete(){};

	friend ostream& operator << (ostream& o, Arete& a){
		o << "Poids : " << a.poids << endl;
		return o;
	}
	
	//=== GET SET ===
	int getPoids(){
		return poids;
	}
	int setPoids(int i){
		poids = i;
	}
	bool exist(){
		return existence;
	}
private:
	int poids; 
	bool existence;
};
