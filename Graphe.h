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

	void ajouterArete(int p, int o, int f){
		Arete a(p, o, f);
		aretes.push_back(&a);
	}

	vector<Sommet*> getSommets(){
		return sommets;
	}
	vector<Arete*> getAretes(){
		return aretes;
	}

	vector<Sommet*> getSuccesseur(int i){
		vector<Sommet*> listSucc;
		for (auto a : aretes){
			if (a->getOrigine() == i)
			{
				listSucc.push_back(sommets.at(a->getFin()-1));
			}
		}
		return listSucc;
	}

	//Une fonction bien tarabiscoté pour afficher le graphe
	friend ostream& operator << (ostream& o, Graphe& g){
		o << "Graphe :\n" << endl;
		o << "Sommets :" << endl;
		for (auto s : g.getSommets())
		{
			o << *s;
		}
		o << endl << "Aretes :"<< endl;
		for (auto a : g.getAretes())
		{
			o << *a;
		}
		o << endl;
		return o;
	}
	

	void FordBellman(int source){
		//Initialisation
		for (auto it : sommets)
		{
			if (source == it->getName()){
				it->setPoids(0);
			}
			else{
				it->setPoids(20000000); 
				//la valeur max de int en c++ (2147483647) fait planter le calcul (sans fausser le resultat) donc...
			}
		}
		//Relaxation
		bool changement = true;
		for (int i = 1; i < sommets.size(); i++)
		{
			if (changement){
				changement = false;
				for (auto j : aretes){
					if (sommets.at(j->getFin() - 1)->getPoids() >(sommets.at(j->getOrigine() - 1)->getPoids() + j->getPoids())){
						sommets.at(j->getFin() - 1)->setPoids((sommets.at(j->getOrigine() - 1)->getPoids() + j->getPoids()));
						sommets.at(j->getFin() - 1)->setPredecesseur(sommets.at(j->getOrigine() - 1)->getName());
						changement = true;
					}
				}
			}
		}
		//Check cycle poid négatif
		for (auto k : aretes){
			if (sommets.at(k->getFin()-1)->getPoids() > (sommets.at(k->getOrigine()-1)->getPoids() + k->getPoids())){
				cout << "Cycle de poid négatif";
			}

		}
		cout << "PCC :" << endl;
		for (auto s : sommets){
			cout << "Predecesseur du sommet " << s->getName() << " : " << s->getPredecesseur() 
				<< ". Poids du chemin parcouru depuis la source : " << s->getPoids() << endl;
		}
		cout << endl;
	}


private:
	vector<Arete*> aretes;
	vector<Sommet*> sommets;
};