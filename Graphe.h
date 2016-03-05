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
	/*Constructeur
	Le graphe est vide � sa cr�ation et dois �tre "rempli" par la suite */
	Graphe(){
		vector<Sommet*> sommets;
		vector<vector<Arete*>*> aretes;
	};
	virtual ~Graphe(){};
	
	//Permet d'ajouter un sommet � la liste des sommets du graphe
	void ajouterSommet(Sommet* s){
		sommets.push_back(s);
	}

	//Permet d'ajouter une arete � la liste des aretes du graphe
	void ajouterArete(Arete* a){
		aretes.push_back(a);
	}

	/*Permet d'ajouter une arete � la liste des aretes du graphe
	Cette fonction diff�re de la pr�c�dente, permettant de construire l'arete directement et non avant.*/
	void ajouterArete(int p, int o, int f){
		Arete a(p, o, f);
		aretes.push_back(&a);
	}

	//Retourne la liste de sommets
	vector<Sommet*> getSommets(){
		return sommets;
	}
	//retourne la liste d'aretes
	vector<Arete*> getAretes(){
		return aretes;
	}
	//Retourne la liste des successeurs d'un sommet
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

	//Fonction d'impression
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
	
	/*L'algorithme de Ford-Bellman
	Le r�sultat s'afiche sur la console de la facon suivante:
	Chaque sommet est list� indiquant sont pr�d�cesseur dans l'arbre du plus court chemin,
	dont la racine est la source.
	Il indique �galement le poids du chemin jusqu'� lui
	Reconstituer */
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
		//Check cycle poid n�gatif
		for (auto k : aretes){
			if (sommets.at(k->getFin()-1)->getPoids() > (sommets.at(k->getOrigine()-1)->getPoids() + k->getPoids())){
				cout << "Cycle de poid n�gatif";
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