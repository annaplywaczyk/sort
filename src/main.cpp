#include "tasocjacyjna.hh"
#include <sstream>
#include <fstream>
#include <time.h>
#include <string>
#include <iostream>

using namespace std;

/*!
 * \file
 * \brief Funkcja glowna ktorej glownym zalozeniem jest wczytanie plikow z rozna wielkoscia
 * elementow znajdujacych siê w pliku, obliczenie sredniej wartosci czasu, w jakim zostaje wykonany
 * algorytm (w naszym przypadku pomnozenie przez 2),nastepnie program porownuje poprawnosc wykoannia
 * mnozenia z plikiem sprawdzajacym.
 * Uzytkownik musi w programie zdefiniowac: liczbe powtorzen (zmienna j), ilosc plikow -
 * do ilu wykonywane jest mnozenie (zmienna i), nazwy plikow (string czesc_1, i, czesc_2 - wszystko opcjonalnie).
 * \return (brak)
 */

/*!
 * \file
 * \brief
 * Przyklad uzycia i poprawnego dzialania tablicy asocjacyjnej.
 */

int main()
{
	Tab_Asocjacyjna<int>  Dane;

	Dane.dodaj("aa",5);
	Dane.dodaj("av",1);
	int c=Dane.rozmiar();
	Dane.dodaj("aa",7);
	Dane.dodaj("cb",8);
	Dane.dodaj("ba",6);
	Dane["ba"]=15;
	int i = Dane["ba"];
	cout << i;
	cout << "roz" << c << endl;
	int pobrany=Dane.pobierz("aa");
	Dane.usun("av");
	c=Dane.rozmiar();
	string b=Dane.znajdz(7);
	cout << "b "<< b << endl;
	cout << "roz" << c << endl;
	cout << pobrany << endl;

	return 0;
}


