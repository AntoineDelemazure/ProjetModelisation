#pragma once
#include "Sommet.h"
#include "Arete.h"
#include <vector>
#include "Exception.h"
#include <string>

using namespace std;

class Graphe
{
public:
	Graphe(){
		vector<Sommet*> sommets;
		vector<vector<Arete*>*> aretes;
	};
	~Graphe(){};
	
	void ajouterSommet(Sommet* s){
		sommets.push_back(s);
	}

	void ajouterArete(Arete* a){
		aretes.push_back(a);
	}

	vector<Sommet*> getSommets(){
		return sommets;
	}

	//Une fonction bien tarabiscoté pour afficher le graphe
	friend ostream& operator << (ostream& o, Graphe& g){
		o << "Graphe :\n" << endl;
		for (auto s:g.getSommets())
		{
			o << "Sommet " << s->getName() << endl 
				<< "poids : " << s->getPoids() << "\n"
				<< "NouveauPoids : " << s->getNouveauPoids() << "\n" << endl;
			o << "Aretes de ce sommet : " << endl;
		}
		o << endl;
		o << "{";
		for each (Sommet* s in g.getSommets())
		{
			if (s->getAretes().empty())
				Exception("Liste d'arete vide", true);
			else {
				for each (Arete* a in s->getAretes())
				{
					if (!a->exist())
						o << " - ;";
					else
						o << " " << a->getPoids() << " ;";
					}
				}
			o << endl;
			}
		o << "}";
		o << endl;
		return o;
	}
	
	void FordBellman(int source){
		vector<Sommet*>::iterator it;
		int i = 1;
		bool changement;
		string sortie;
		for (auto it:sommets)
		{
			if (source == i){
				it->setPoids(0);
				it->setNouveauPoids(0);
			}else{
				it->setPoids(-1);
				it->setNouveauPoids(2147483647);
			}
			i++;
		}
		for (int i = 1; i < sommets.size(); i++)
		{
			for (auto j : sommets){
				for (auto k : j->getAretes()){
					if (k->exist()){
						
					}
				}
			}
		}
	}

	void FordBellman2(int source){
		int i = 1;
		bool changement;
		string sortie;
		for (auto it : sommets)
		{
			if (source == i){
				it->setPoids(0);
				it->setNouveauPoids(0);
			}
			else{
				it->setPoids(-1);
				it->setNouveauPoids(2147483647); //max de int en c++
			}
			i++;
		}
		for (int i = 1; i < sommets.size(); i++)
		{
			for (auto j : aretes){
				if (sommets.at(j->getFin()-1)->getNouveauPoids() > (sommets.at(j->getOrigine()-1)->getNouveauPoids() + j->getPoids())){
					sommets.at(j->getFin()-1)->setNouveauPoids((sommets.at(j->getOrigine()-1)->getNouveauPoids() + j->getPoids()));
				}
			}
		}
		for (auto k : aretes){
			if (sommets.at(k->getFin()-1)->getNouveauPoids() > (sommets.at(k->getOrigine()-1)->getNouveauPoids() + k->getPoids())){
				cout << "Cycle de poid négatif";
			}
			else{

			}
		}
	}

private:
	vector<Arete*> aretes;
	vector<Sommet*> sommets;
};
/*
for (int j = 1; j < sommets.size(); j++){
	//cout << "lol1" << endl;
	changement = true;
	for (auto ite : sommets){
		//cout << "lol2" << endl;
		if (changement){
			changement = false;
			if (ite->getNouveauPoids() == j - 1){
				for (auto iter : sommets){
					//cout << "lol3" << endl;
					for (auto itera : iter->getAretes()){
						//cout << "lol4" << endl;
						iter->setNouveauPoids(iter->getPoids() + itera->getPoids());
						//cout << "lol5" << endl;
						if (iter->getNouveauPoids() < itera->getPoids()){
							cout << iter->getName();
							sommets.at(iter->getName() - 1)->setPoids(iter->getPoids());
							changement = true;
						}
					}
				}
			}
		}
	}
}
cout << "PCC : " << sortie << endl;*/