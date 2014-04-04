#include "uruchom.hh"
#include <sstream>
#include <fstream>
#include <time.h>

using namespace std;

/*!
 * \file
 * \brief Funkcja glowna ktorej glownym zalozeniem jest wczytanie plikow z rozna wielkoscia
 * elementow znajdujacych si� w pliku, obliczenie sredniej wartosci czasu, w jakim zostaje wykonany
 * algorytm (w naszym przypadku pomnozenie przez 2),nastepnie program porownuje poprawnosc wykoannia
 * mnozenia z plikiem sprawdzajacym.
 * Uzytkownik musi w programie zdefiniowac: liczbe powtorzen (zmienna j), ilosc plikow -
 * do ilu wykonywane jest mnozenie (zmienna i), nazwy plikow (string czesc_1, i, czesc_2 - wszystko opcjonalnie).
 * \return (brak)
 */


int main()

{
	dane tab;
	zegar dzialanie;
	LARGE_INTEGER start, end;
	double suma=0;
	int a=0, il;
	ofstream plik("wnioski1q2.csv");
	for (il=10; il<1000000; il=il*10)
	{
		// zdefiniowane zmienne oraz czesci nazw plikow, ktore sie zmieniac beda;
				string czesc_1 = "sort";
				int liczba=il;
				string czesc_2=".txt";
				string nazwa_pliku1;
				suma = 0;

				// konwersja int na string aby nazwa programu mogla sie zmieniac samoczynnie;
				ostringstream numer;
				numer << liczba;
				string element=numer.str();

				//tworzone nazwy plikow
				nazwa_pliku1=czesc_1+element+czesc_2;
				for (a=0; a<10; a++)
				{
					tab.wczytaj(nazwa_pliku1);
					int i=tab.size()-1;
					start=dzialanie.wlaczStoper();
					dzialanie.quick(&tab,0,i);
					//tab=dzialanie.scal_sort(tab);
					//dzialanie.heap_sort(tab);
					end=dzialanie.wylaczStoper();
					tab.czysc();
					double czas=end.QuadPart- start.QuadPart;
					cout << czas << endl;
					suma+=czas;
				}
				cout << suma/10 << endl;
				//stworzenie pliku i zapisanie do niego danych o testowanym pliku

				plik << il << "," << a <<"," <<suma/10 << endl;
				plik.flush();
	}
	return 0;
}


