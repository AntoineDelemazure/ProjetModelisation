#pragma once
#include "Sommet.h"
#include "Arc.h"
#include <vector>
#include <list>
#include "Exception.h"
#include <string>

using namespace std;

class Graphe
{
public:
	/*Constructeur
	Le graphe est vide à sa création et dois être "rempli" par la suite */
	Graphe(){
		vector<Sommet*> sommets;
		vector<vector<Arc*>*> arcs;
		cyclenegatif = false;
	};
	virtual ~Graphe(){};
	
	//Permet d'ajouter un sommet à la liste des sommets du graphe
	void ajouterSommet(Sommet* s){
		sommets.push_back(s);
	}

	//Permet d'ajouter une Arc à la liste des Arcs du graphe
	void ajouterArc(Arc* a){
		arcs.push_back(a);
	}

	/*Permet d'ajouter une Arc à la liste des Arcs du graphe
	Cette fonction diffère de la précédente, permettant de construire l'Arc directement et non avant.*/
	void ajouterArc(int p, int o, int f){
		Arc a(p, o, f);
		arcs.push_back(&a);
	}

	//Retourne la liste de sommets
	vector<Sommet*> getSommets(){
		return sommets;
	}
	//retourne la liste d'Arcs
	vector<Arc*> getArcs(){
		return arcs;
	}
	//Retourne la liste des successeurs d'un sommet
	vector<Sommet*> getSuccesseur(int i){
		vector<Sommet*> listSucc;
		for (auto a : arcs){
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
		o << endl << "Arcs :"<< endl;
		for (auto a : g.getArcs())
		{
			o << *a;
		}
		o << endl;
		return o;
	}
	
	/*L'algorithme de Ford-Bellman
	Le résultat s'afiche sur la console de la facon suivante:
	Chaque sommet est listé indiquant sont prédécesseur dans l'arbre du plus court chemin,
	dont la racine est la source.
	Il indique également le poids du chemin jusqu'à lui.
	Reconstituer le chemin le plus court depuis un sommet peut être fait en remontant la chaine des prédécesseurs*/
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
		cyclenegatif = false;
		bool changement = true;
		for (int i = 1; i < sommets.size(); i++)
		{
			if (changement){
				changement = false;
				for (auto j : arcs){
					if (sommets.at(j->getFin() - 1)->getPoids() >(sommets.at(j->getOrigine() - 1)->getPoids() + j->getPoids())){
						sommets.at(j->getFin() - 1)->setPoids((sommets.at(j->getOrigine() - 1)->getPoids() + j->getPoids()));
						sommets.at(j->getFin() - 1)->setPredecesseur(sommets.at(j->getOrigine() - 1)->getName());
						changement = true;
					}
				}
			}
		}
		//Check cycle poid négatif
		if (changement){
			for (auto k : arcs){
				if (sommets.at(k->getFin() - 1)->getPoids() > (sommets.at(k->getOrigine() - 1)->getPoids() + k->getPoids())){
					cout << "Cycle de poid négatif" << endl;
					cyclenegatif = true;
					break;
				}
			}
		}
		if (!cyclenegatif){
			cout << "PCC :" << endl;
			for (auto s : sommets){
				cout << "Predecesseur du sommet " << s->getName() << " : " << s->getPredecesseur()
					<< ". Poids du chemin parcouru depuis la source : " << s->getPoids() << endl;
			}
			cout << endl;
		}
	}

	/*Un fonction pour imprimer un plus court chemin en particulier depuis la racine*/
	void PCC(int dest){
		if (!cyclenegatif)
		{
			int k = 0;
			int l = dest;
			int p = (this->getSommets().at(	l - 1))->getPoids();
			list<int> liste;
			liste.push_front(dest);
			while (k != (this->getSommets().at(l- 1))->getPredecesseur() &&
				l != (this->getSommets().at(l - 1))->getPredecesseur()){
				k = this->getSommets().at(l - 1)->getPredecesseur();
				liste.push_front(k);
				l = k;
			}
			//Ecriture du résultat
			if (liste.size() == 1)
			{
				cout << "Le sommet "<< dest <<" n'est pas relie a la source (ou est la source)" << endl;
			}else{
				cout << "Le plus court chemin de la source vers le sommet " << dest << " est : ";
				for (list<int>::iterator it = liste.begin(); it != liste.end()--; it++){
					cout << *it << " ";
				}
				cout << endl <<
					"Le poids du chemin s'eleve a : " << p << endl;
			}
		}
	}

private:
	vector<Arc*> arcs;
	vector<Sommet*> sommets;
	bool cyclenegatif;
};