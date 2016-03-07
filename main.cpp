#pragma once
#include "stdlib.h"
#include <iostream>
#include <string> 
#include <fstream> 
#include "Arc.h"
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

	Arc a1to2(2, 1, 2);
	Arc a2to1(1, 2,1);
	Arc a2to3(1, 2,3);
	Arc a3to1(4, 3,1);

	g.ajouterSommet(&s1);
	g.ajouterSommet(&s2);
	g.ajouterSommet(&s3);

	g.ajouterArc(&a1to2);
	g.ajouterArc(&a2to1);
	g.ajouterArc(&a2to3);
	g.ajouterArc(&a3to1);
	*/
	//lol
	Sommet s1(1);
	Sommet s2(2);
	Sommet s3(3);
	Sommet s4(4);

	Arc a1to3(2, 1, 3);
	Arc a1to4(4, 1, 4);
	Arc a2to3(1, 3, 4);
	Arc a3to1(4, 3, 2);
	Arc a2to4(1, 4, 2);
	Arc a2to1(8, 2, 1);

	g.ajouterSommet(&s1);
	g.ajouterSommet(&s2);
	g.ajouterSommet(&s3);
	g.ajouterSommet(&s4);

	g.ajouterArc(&a1to3);
	g.ajouterArc(&a1to4);
	g.ajouterArc(&a2to3);
	g.ajouterArc(&a3to1);
	g.ajouterArc(&a2to4);
	g.ajouterArc(&a2to1);
//	cout << g;

	Graphe g2;
	std::ifstream fichier("D:/Neo-Fufu/Mes documents/Boulot/Modelisation/Projet2016/9.gpr");
	ConstruireGraphe(&g2, fichier);

	cout << g2;
	g2.FordBellman(2);
	g2.PCC(9);


	system("pause");
	return 0;
}