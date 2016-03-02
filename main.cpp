#pragma once
#include "stdlib.h"
#include <iostream>
#include "Arete.h"
#include "Sommet.h"
#include "Graphe.h"


using namespace std;

int main(){
	/*
	Graphe g;

	Sommet s1(1);
	Sommet s2(2);
	Sommet s3(3);

	Arete a1to1(NULL,false);
	Arete a1to2(2, true);
	Arete a1to3(NULL, false);
	Arete a2to1(1, true);
	Arete a2to2(NULL, false);
	Arete a2to3(1, true);
	Arete a3to1(4, true);
	Arete a3to2(NULL, false);
	Arete a3to3(NULL, false);

	s1.ajouterArete(&a1to1);
	s1.ajouterArete(&a1to2);
	s1.ajouterArete(&a1to3);

	s2.ajouterArete(&a2to1);
	s2.ajouterArete(&a2to2);
	s2.ajouterArete(&a2to3);

	s3.ajouterArete(&a3to1);
	s3.ajouterArete(&a3to2);
	s3.ajouterArete(&a3to3);

	g.ajouterSommet(&s1);
	g.ajouterSommet(&s2);
	g.ajouterSommet(&s3);

	cout << g;

	//g.FordBellman(1);

	cout << g.getSommets().size();
	*/

	Graphe g;
	/*
	Sommet s1(1);
	Sommet s2(2);
	Sommet s3(3);

	Arete a1to2(2, 1, 2);
	Arete a2to1(1, 2,1);
	Arete a2to3(1, 2,3);
	Arete a3to1(4, 3,1);

	g.ajouterSommet(&s1);
	g.ajouterSommet(&s2);
	g.ajouterSommet(&s3);

	g.ajouterArete(&a1to2);
	g.ajouterArete(&a2to1);
	g.ajouterArete(&a2to3);
	g.ajouterArete(&a3to1);
	*/

	Sommet s1(1);
	Sommet s2(2);
	Sommet s3(3);
	Sommet s4(4);

	Arete a1to3(2, 1, 3);
	Arete a1to4(4, 1, 4);
	Arete a2to3(1, 3, 4);
	Arete a3to1(4, 3, 2);
	Arete a2to4(1, 4, 2);
	Arete a2to1(8, 2, 1);

	g.ajouterSommet(&s1);
	g.ajouterSommet(&s2);
	g.ajouterSommet(&s3);
	g.ajouterSommet(&s4);

	g.ajouterArete(&a1to3);
	g.ajouterArete(&a1to4);
	g.ajouterArete(&a2to3);
	g.ajouterArete(&a3to1);
	g.ajouterArete(&a2to4);
	g.ajouterArete(&a2to1);
	cout << g;

	g.FordBellman2(1);

	cout << g;


	cout << "Jusqu'ici tout va bien" << endl;
	system("pause");
	return 0;
}