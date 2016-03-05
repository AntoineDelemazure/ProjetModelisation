#pragma once
#include <fstream> 
#include <string>  
#include <iostream> 
#include <sstream>
#include <algorithm>
#include <iterator>
#include "Graphe.h"
#include "Arete.h"
#include "Sommet.h"

using namespace std;

bool flagSommet = false;
bool flagArete = false;
bool flagSource = false;
bool flagPuit = false;
bool flagGraphe = false;

bool is_readable(const std::ifstream& f)
{
	return !f.fail();
}

bool is_readable2(const std::string & file)
{
	std::ifstream fichier(file.c_str());
	return !fichier.fail();
}

void closeFlags(){
	flagSommet = false;
	flagArete = false;
	flagSource = false;
	flagPuit = false;
	flagGraphe = false;
}

void ConstruireGraphe(Graphe *g, std::ifstream& f){
	if (is_readable(f))
	{
		cout << "lol" << endl;
		string line;

		while (getline(f, line))
		{
			if (line.empty()){
				closeFlags();
			}else{
				if (flagArete)
				{
					istringstream iss(line);
					vector<string> tokens;
					copy(istream_iterator<string>(iss),
						istream_iterator<string>(),
						back_inserter(tokens));
					//cout << a << endl;
					//Arete a(stoi(tokens.at(3)), stoi(tokens.at(1)), stoi(tokens.at(2)));
					//cout << a;
					g->ajouterArete(stoi(tokens.at(3)), stoi(tokens.at(1)), stoi(tokens.at(2)));//g->ajouterArete(stoi(tokens.at(3)), stoi(tokens.at(1).c_str() + 1), stoi(tokens.at(2).c_str() + 1));//
					//cout << endl;
				}

				if (flagSommet)
				{
					istringstream iss(line);
					vector<string> tokens;
					copy(istream_iterator<string>(iss),
						istream_iterator<string>(),
						back_inserter(tokens));
					Sommet s(stoi(tokens.at(0)));//Sommet s(atoi(tokens.at(0).c_str() + 1));//
					g->ajouterSommet(&s);
				}

				if (line == ("sectionSommets")) flagSommet = true;
				if (line == "sources") flagSource;
				if (line == "sectionArcs") flagArete =true;
				if (line == "puits") flagPuit;
				if (line == "sectionGraphes") flagGraphe;
			}
		}
		cout << "Je suis dans la fonction de construction" << *g;
	}
}
