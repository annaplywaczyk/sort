#include "uruchom.hh"
#include <sstream>
#include <fstream>
#include <time.h>

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

/*

int podziel(int p, int k, dane *tab){
	int piwot=(*tab)[k];// jako piwot przyjmujemy ostatni element zbioru
	int i=p;
	int j=k-1;

	while (true){
		while ((*tab)[j] > piwot) // dopoki elementy sa wieksze od piwotu
			j--;
		while ((*tab)[i] < piwot) // dopoki elementy sa mniejsze od piwotu
			i++;
		//w tym momencie indeks 'i' wskazuje na pierwsza liczbe wieksza od piwotu
		//natomiast indeks 'j' pierwsza od konca mniejsza od piwotu
		if (i < j){
			tab->zamien_element(i,j);// zamieniamy te liczby
			i++;
			j--;
		}
		// gdy 'i' i 'j' sie "spotkaja" oznacza to tyle ze na lewo wlacznie od 'j' sa liczby mniejsze od piwotu
		// a na prawo wieksze
		else{
			tab->zamien_element(k,j+1); // ustawiamy piwot pomiedzy tymi zbiorami
			return j; // zwracamy indeks podzialu
		}
	}

}

dane Quicksort(int p, int k, dane tab){
	int podzial;
	if (p < k)
	{
		podzial = podziel(p,k, &tab);
		tab=Quicksort( p, podzial,tab);
		tab=Quicksort( podzial+1, k,tab);
	}
	return tab;
}*/

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


