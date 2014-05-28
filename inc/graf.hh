/*
 * graf.hh
 *
 *  Created on: 15 maj 2014
 *      Author: Ania
 */

#ifndef GRAF_HH_
#define GRAF_HH_

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stack>
/*!
 * \file
 * \brief
 * Plik w ktorym wczytujemy plik tworzymy macierz sasiedztwa oraz zdefiniowane
 * sa funkcje zwiazane z grafem do przesukiwan drogi miedzy punktami.
 */
using namespace std;

/*!
 * \brief
 * Struktura w ktorej definiujemy wezel- wiercholek.
 */
typedef struct wezel {
	/*!
	 * \brief
	 * Numer wierzcho³ka, jego ID.
	 */
	int ktory;
	/*!
	 * \brief
	 * Droga jak¹ pokona³ algorytm poszukiwania binarnego od pocz¹tku
	 * do miejsca w ktorym siê aktulanie znajdujemy.
	 */
	int start_akt;
	/*!
	 * \brief
	 * Droga jaka zosta³a do pokonoania. Zmienna wykorzystywana w poszukiwaniu A*.
	 * Do zmiennej przypisujemy heurystyke, ktora wyszukuje nam optymalna droge.
	 */
	double akt_cel;
	/*!
	 * \brief
	 * Suma zmiennych start_akt i akt_cel, czyli jest to droga jaka prawdopodobnie
	 * trzeba pokonac aby przejscz punktu A do punktu B.
	 */
	double koszt;
	/*!
	 * \brief
	 * Wspolrzedna x wierzcholka wykorzystywana w A*.
	 */
	int x;
	/*!
	 * \brief
	 * Wspolrzedna y wierzcholka wykorzystywana w A*.
	 */
	int y;

	/*!
	 * \brief
	 * Funkcja znajdujaca rozwiazanie, dla ktorej nie ma gwarancji znalezienia metody optymalnej.
	 * Sluzy do znajdowania rozwiazan przyblizonych, na podstawie ktorej
	 * wyliczany jest ostateczny rezultat. W funkcji znajdujemy droge pomiedzy dwoma wierzcholkami
	 * w linii prostej na podstawie twierdzenia Pitagorasa. Kazdy wierzcholek ma wspolrzedne x i y.
	 * \param[in] cel - informacje ktore sa zawarte w wierzcholku do ktorego mamy znalezc droge
	 * \return Funkcja zwraca liczbe zmiennoprzecinkowa, ktora jest najkrotsza droga z punktu A do B.
	 */
	double heurystyka(wezel cel);
	/*!
	 * \brief
	 * Konstruktor w ktorym definiujemy poczatowe wartosci wezla aby informacje o wierzcholku nie
	 * przyjmowaly nam losowych wartosci.
	 */
	wezel(){
		ktory = 0;
		start_akt = -1;
		akt_cel = -1;
		koszt = 100000000;
		y = -1;;
		x = -1;
	}
}wezel;

/*!
 * \brief
 * Klasa porownanie wykorzystywana do poszukiwania A*. Sluzaca do definicji kolejki piorytetowej -
 * abstrakcyjnego typu danych sluzacego do przechowywania elemntow zbioru w ustalonym porzadku.
 */
class porownanie{
public:
	/*!
	 * \brief
	 * Funkcja pomocna do ustalenia porzadku w jakim maja byc przechowywane wierzcholki
	 * nieodwiedzone. W naszym przypadku ma byc uporzadkowane wedlug kosztu wierzcholka,
	 * czyli wagi rosnaco.
	 * \param[in] pier - wezel uzyty do porownywania wag z innym wezelem
	 * \param[in] drugi - wezel uzyty do porownywania wag z innym wezelem
	 * \return Funkcja zwraca true jezeli waga pier jest wieksza niz drugiego w przciwnym
	 * wypadku false.
	 */
	bool operator () (const  wezel& pier, const wezel& drugi) const
		{
			if (pier.koszt > drugi.koszt)
				return true;
			else
			 	return false;
		}
};

/*!
 * \brief
 * Klasa graf w ktorej zdefiniowane sa wszystkie parametry i funkcje zwiazane
 * z operacjami przeprowadzanymi  na nim.
 */
class Graf
{
public:
	/*!
	 * \brief
	 * Tablica, ktora jest macierza sasiedztwa
	 */
	int **Tablica;
	/*!
	 * \brief
	 * Zmienna wykorzystywana do przechowywania liczby wierzcholkow w grafie.
	 */
	int V;
	/*!
	 * \brief
	 * Zmienna wykorzystywana do przechowywania liczby krawedzi uzytych w grafie.
	 */
	int E;
	/*!
	 * \brief
	 * Lista wierzcholkow.
	 */
	wezel *wierzcholek;

public:
	/* Funkcja stworzona poczatkowo do wygenerowania macierzy, aby nie bylo
	 * potrzeby za kazdym razem wpisywania po koleji wierzcholkow i punktow do programu.
	 * ilosc - liczba wierzcholkow
	 * gestosc - liczba krawedzi
	 * Funkcja nic nie zwraca
	 */
	void generuj_macierz(int ilosc, int gestosc);
	/* Funkcja sprawdza czy wygenerwoany graf jest spojny.
	 */
	bool czy_spojny();
	/*!
	 * \brief
	 * Funkcja wyswietla graf wczytany z pliku, a dokladnie wyswietla jego macierz sasiedztwa.
	 * \return (brak)
	 */
	void wyswietl();
	/*!
	 * \brief
	 * Funkcja wczytuje graf z pliku (jego macierz sasiedztwa) i zapisuje do pamieci
	 * abysmy mogli nastepnie uzywac.
	 * \return (brak)
	 */
	void wczytaj_graf(string nazwa_pliku);
	/*!
	 * \brief BST - Breadth-first search
	 * Funkcja przeszukiwania grafu wszerz. Przechodzenie grafu rozpoczyna sie od zadanego
	 * wierzcholka i polega na odwiedzeniu wszystkich osiagalnych z niego wierzcholkow w celu
	 * odnalezienia drogi do drugiego wierzcholka. Funkcja dziala na macierzy sasiedztwa.
	 * \param[in] pocz - punkt poczatkowy do znalezienia drogi w grafie
	 * \param[in] koniec - punkt koncowy do znalezienia drogi w grafie
	 * \return Dzieki funkcji otrzymac mozemy dlugosc (koszt) drogi z punkty A do B.
	 */
	int BFS(int pocz, int koniec);
	/*!
	 * \brief DST - Depth-first search
	 * Funkcja przeszukiwania grafu w glab. Przechodzenie grafu rozpoczyna sie od zadanego
	 * wierzcholka i polega na badaniu wszystkich krawedzi wychodzacych z podanego wierzcholka.
	 * Po zbadaniu wszystkich krawedzi wychodzacych z danego wierzcholka algorytm poawraca do
	 * wierzcholka, z ktorego dany wierzcholek zostal odiwedzony. Funkcja uzyta w celu
	 * odnalezienia drogi do drugiego wierzcholka. Funkcja dziala na macierzy sasiedztwa.
	 * \param[in] pocz - punkt poczatkowy do znalezienia drogi w grafie
	 * \param[in] koniec - punkt koncowy do znalezienia drogi w grafie
	 * \return Dzieki funkcji otrzymac mozemy dlugosc (koszt) drogi z punkty A do B.
	 */
	int DFS(int pocz, int koniec);
	/*!
	 * \brief A* - A star
	 * Algorytm heurystyczny sluzacy do odnalezienia najkrotszej sciezki w grafie. Algorytm jest
	 * zupelny i optymalny, znajduje sciezke jezeli tylko taka istnieje i przy tym najkrtosza sciezke.
	 * Algorytm A* od poczatku tworzy sciezke, za kazdym razem wybierajac wierzcholek x z dostepnych
	 * w danym kroku niezbadanych wierzcholkow tak aby minimalizowac funkcje f(x) - zmienna koszt.
	 * Funkcja ta nigdy nie przeoczy sciezki o nizszym koszcie, dlatego wyszukuje najkrotsza droge
	 * sposrod trzech przeszukiwan w moim programie (BFS, DFS, A*).
	 * \param[in] pocz - punkt poczatkowy do znalezienia drogi w grafie
	 * \param[in] koniec - punkt koncowy do znalezienia drogi w grafie
	 * \return Dzieki funkcji otrzymac mozemy dlugosc (koszt) drogi z punkty A do B.
	 */
	int a_star(int pocz, int koniec);
	/*!
	 * \brief
	 * Dekonstruktor klasy Graf. Gdy zakonczymy dzialanie tej klasie pamiec zostaje zwolniona.
	 */
	~Graf();
};


#endif /* GRAF_HH_ */
