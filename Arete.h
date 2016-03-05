#pragma once
#include "stdlib.h"
#include <iostream>

using namespace std;

class Arete
{
public:
	Arete(int p, int o, int f){
		poids = p;
		origine = o;
		fin = f;
	};

	~Arete(){};

	friend ostream& operator << (ostream& o, Arete& a){

		o <<"De " << a.origine << " vers "<< a.fin << " Poids : " << a.poids << endl;
		return o;
	}
	
	//=== GET SET ===
	int getPoids(){
		return poids;
	}
	int setPoids(int i){
		poids = i;
	}
	int getOrigine(){ return origine; }
	int getFin(){ return fin;}
	void setOrigine(int o){ origine = o; }
	void setFin(int f){ fin = f; }

private:
	int poids; 
	int origine;
	int fin;
};
