#include "Towar.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>


using namespace std;


void Towar::wczytaj()
{

	fstream plik;
	plik.open("towary.txt", ios::in);

	if (plik.good() == false)
	{
		cout << "Nie uda³o otworzyæ siê pliku" << endl;
		exit(0);
	}
	int nr_linii=(ile-1)*4+1;
	int aktualny_nr =1;
	string linia;




	while (getline(plik, linia))

	{
		if (aktualny_nr == nr_linii) nazwa = linia;
        if (aktualny_nr == nr_linii+1) id= linia;
        if (aktualny_nr == nr_linii+2) napis = linia;

        istringstream iss(napis);  //zamiana stringa na int
        iss >> ilosc;
        if (aktualny_nr == nr_linii+3) polozenie = linia;

		aktualny_nr++;


	}


	plik.close();

}



void Towar::wyswietl()
{
	cout <<"Towar: "<< nazwa << endl;
	cout <<"ID: "<< id << endl;
	cout <<"Ilosc: "<< ilosc << endl;
	cout <<"Polozenie: " << polozenie << endl;

}
Towar::Towar(int i)
{

        ile=i; // zliczanie obiektu potrzebne do czytania z pliku


}



Towar::~Towar()
{
    ile--; //zmniejsza liczbe obiektow
}
