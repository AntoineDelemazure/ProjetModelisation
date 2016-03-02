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
	vector<Arete*> getAretes(){
		return aretes;
	}

	//Une fonction bien tarabiscoté pour afficher le graphe
	friend ostream& operator << (ostream& o, Graphe& g){
		o << "Graphe :\n" << endl;
		o << "Sommets :" << endl;
		for (auto s : g.getSommets())
		{
			o << "Sommet " << s->getName()
				<< "; poids : " << s->getPoids() << endl;
		}
		o << endl << "Aretes :"<< endl;
		for (auto a : g.getAretes())
		{
			o << a->getOrigine() << " vers " << a->getFin()
				<< "; poids : " << a->getPoids() << endl;
		}
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
				it->setPoids(0);
			}else{
				it->setPoids(-1);
				it->setPoids(2147483647);
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
		for (auto it : sommets)
		{
			if (source == it->getName()){
				it->setPoids(0);
			}
			else{
				it->setPoids(20000000); //max de int en c++ 2147483647
			}
		}
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
/*
for (int j = 1; j < sommets.size(); j++){
	//cout << "lol1" << endl;
	changement = true;
	for (auto ite : sommets){
		//cout << "lol2" << endl;
		if (changement){
			changement = false;
			if (ite->getPoids() == j - 1){
				for (auto iter : sommets){
					//cout << "lol3" << endl;
					for (auto itera : iter->getAretes()){
						//cout << "lol4" << endl;
						iter->setPoids(iter->getPoids() + itera->getPoids());
						//cout << "lol5" << endl;
						if (iter->getPoids() < itera->getPoids()){
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