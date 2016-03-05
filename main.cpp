#pragma once
#include "stdlib.h"
#include <iostream>
#include <string> 
#include <fstream> 
#include "Arete.h"
#include "Sommet.h"
#include "Graphe.h"
#include "Lecture.h"


using namespace std;

int main(){

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

	Graphe g2;
	std::ifstream fichier("D:/Neo-Fufu/Mes documents/Boulot/Modelisation/Projet2016/data_VRPTW_10_3_2_4.gpr");
	ConstruireGraphe(&g2, fichier);

	//g.FordBellman2(3);

	cout << g2;




	cout << endl << "Jusqu'ici tout va bien" << endl;
	system("pause");
	return 0;
}