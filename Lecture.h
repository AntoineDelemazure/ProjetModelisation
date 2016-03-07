#pragma once
#include <fstream> 
#include <string>  
#include <iostream> 
#include <sstream>
#include <algorithm>
#include <iterator>
#include "Graphe.h"
#include "Arc.h"
#include "Sommet.h"

using namespace std;

bool flagSommet = false;
bool flagArc = false;
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
	flagArc = false;
	flagSource = false;
	flagPuit = false;
	flagGraphe = false;
}

void ConstruireGraphe(Graphe *g, std::ifstream& f){
	if (is_readable(f))
	{
		string line;

		while (getline(f, line))
		{
			if (line.empty()){
				closeFlags();
			}else{
				if (flagArc)
				{
					istringstream iss(line);
					vector<string> tokens;
					copy(istream_iterator<string>(iss),
						istream_iterator<string>(),
						back_inserter(tokens));
					Arc* a = new Arc(stoi(tokens.at(3)), stoi(tokens.at(1)), stoi(tokens.at(2)));
					g->ajouterArc(a);//g->ajouterArc(stoi(tokens.at(3)), stoi(tokens.at(1).c_str() + 1), stoi(tokens.at(2).c_str() + 1));//
				}

				if (flagSommet)
				{
					istringstream iss(line);
					vector<string> tokens;
					copy(istream_iterator<string>(iss),
						istream_iterator<string>(),
						back_inserter(tokens));
					Sommet* s = new Sommet(stoi(tokens.at(0)));//Sommet s(atoi(tokens.at(0).c_str() + 1));//
					g->ajouterSommet(s);
				}

				if (line == ("sectionSommets")) flagSommet = true;
				if (line == "sources") flagSource;
				if (line == "sectionArcs") flagArc =true;
				if (line == "puits") flagPuit;
				if (line == "sectionGraphes") flagGraphe;
			}
		}
	}
}
