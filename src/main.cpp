#include "uruchom.hh"
#include <sstream>
#include <fstream>
#include <time.h>
#include <string>
#include <iostream>

using namespace std;



/*!
 * \file
 * \brief
 * Funkcja zmieniajaca nazwy dla roznych wielkosci problemu, aby za kazdym razem nie
 * trzeba bylo wczytywac na nowo pliku.
 * \param[in] i - zmienna wykorzystana aby zdefiniowac jaka wielkosc problemu ma byc sprawdzona w programie.
 * \return Funkcja zwraca nazwy plikow do wczytania.
 */

string zmien_nazwy(int i)
{
	// zdefiniowane zmienne oraz czesci nazw plikow, ktore sie zmieniac beda;
			string czesc_1 = "dane";
			int liczba=i;
			string czesc_2=".txt";
			string nazwa_pliku1;

			// konwersja int na string aby nazwa programu mogla sie zmieniac samoczynnie;
			ostringstream numer;
			numer << liczba;
			string element=numer.str();

			//tworzone nazwy plikow
			return nazwa_pliku1=czesc_1+element+czesc_2;
}

/*!
 * \brief
 * Funkcja otwiera plik do zapisania wnioskow i danych z obliczonym czasem pobierania wartosci
 * z tablicy asocjacyjnej. W funkcji tej wykorzystane jest rowniez powtorzenie danego problemu,
 * aby miec usredniony czas.
 */

void dzialaj()
{
	dzialanie tab;

	int a=0, il;
	ofstream plik("wnioski3.csv");
	for (il=10; il<1000000; il=il*10)
	{
		double suma=0;
		string nazwa=zmien_nazwy(il);
		for (a=0; a<10; a++)
		{
			tab.wczytaj(nazwa);
			double czas=tab.stoper();
			cout << czas << endl;
			suma+=czas;
		}
		cout << suma/10 << endl;
		//stworzenie pliku i zapisanie do niego danych o testowanym pliku

		plik << il << "," << a <<"," <<suma/10 << endl;
		plik.flush();
		tab.czysc();
	}
}

/*!
 * \brief
 * Przyklad uzycia i poprawnego dzialania tablicy asocjacyjnej.
 */

int main()
{

	dzialaj();

	return 0;
}


