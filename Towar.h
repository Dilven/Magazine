#pragma once
#include <iostream>



using namespace std;

class Towar
{
public:

	string nazwa,id,polozenie;
	int ilosc;
	string napis;
	int ile; // ile jest obiektow w tej klasie

	void wczytaj();

	//wczytuje towary  z pliku
	void wyswietl(); // wyswietla liste towarów

	Towar();
	~Towar();
};

