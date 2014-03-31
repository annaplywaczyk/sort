/*
 * stos.hh
 *
 *  Created on: 13 mar 2014
 *      Author: Ania
 */

#ifndef STOS_HH_
#define STOS_HH_
/*!
 * \file
 * \brief Definicja klasy stos.
 *
 * Plik zawiera definicje klasy stos, ktora do zapisu i zapamietania liczb uzywa tablice.
 */
#include <iostream>
#include <cstdlib>


using namespace std;

/*!
 * \brief
 * Klasa modeluje pojecie stosu,bazujacego na tablicy. Na stosie wyonywane sa operacje
 * dodatnia na stos, zdjecia ze stosu, sprawdzenia czy jest pusty oraz sprawdzenia rozmiaru.
 * Tablice zaalokowalam w sposob dynamiczny. Dodatkowo u¿yte niektore funkcje pomocnicze
 * jak np. powiekszenie stosu.
 */
class stos{
private:
	/*!
	 * \brief
	 * Liczba elemntow ktore tablica moze pomiescic na stosie (tablicy).
	 */
	int rozmiar_tab;
	/*!
	 * \brief
	 * Liczba elementow znajujacych sie na stosie
	 */
	int liczba_elementow;
	/*!
	 * \brief Tablica
	 * Do przechowywania elementow na stosie uzyta zostala dynamiczna alokacja pamieci. Tablica
	 * zaimplementowana jest jako tablica liczb calkowitych.
	 */
	int *tablica;
	/*!
	 * \brief Powiekszenie
	 * Zmienna wykorzystana w celu oznaczenia czy powiekszenie tablicy ma byc dwa razy wieksze
	 * czy o jeden element zwiekszony.
	 */
	int powiekszenie;
	/*!
	 * \brief Powiekszenie tablicy
	 * Funkcja zostala stworzona aby powiekszyc tablice dwukrotnie, w przypadku gdy
	 * bedziemy chcieli dodac element do tablicy a nam zabraknie miejsca.
	 * W funkcji tworzymy nowa tablice dwa razy wieksza niz poprzednia, nastepnie
	 * stara tablice dodajemy do nowej, stara tablica jest kasowana a stara pokazuje na nowa.
	 * \return (brak)
	 */
	void powieksz();
	/*!
	 * \brief Pomniejszenie tablicy
	 * Funkcja zostala stworzona aby zmniejszyc tablice dwukrotnie, w przypadku gdy
	 * liczba elementow z tablicy bedzie mniejsza badz rowna 1/4 mozliwosci tablicy.
	 * W funkcji tworzymy nowa tablice dwa razy mniejsza, nastepnie
	 * stara tablice dodajemy do nowej, stara tablica pokazuje na nowa.
	 * \return (brak)
	 */
	void pomniejsz();
public:
	/*!
	 * \brief Konstruktor bezargumentowy.
	 * Przy tworzeniu tablica jest pusta, w konstruktorze przydzielana jest dynamicznie,
	 * na poczatku tablica ma mozliwosc przypisania tablicy  o rozmiarze 1. Jezeli
	 * nie uda sie utworzyc tablicy wyrzucany jest blad. Przy wywo³aniu konstrktora
	 * bezparametrycznego powiekszajaca tablica bedzie dwa razy wieksza.
	 */
	stos() {
		liczba_elementow=0;
		rozmiar_tab=1;
		tablica=new int[rozmiar_tab];
		if (tablica==NULL)
		{
			cerr << "Blad alokacji pamieci";
		}
		powiekszenie=0;
	}
	/*!
	 * \brief Konstruktor parametryczny.
	 * Przy tworzeniu tablica jest pusta, w konstruktorze przydzielana jest dynamicznie,
	 * na poczatku tablica ma mozliwosc przypisania tablicy  o rozmiarze 1. Jezeli
	 * nie uda sie utworzyc tablicy wyrzucany jest blad. Przy wywo³aniu konstrktora
	 * parametrycznego tablica zostanie powiekszona o 1 element.
	 */
	stos(int cos) {
		liczba_elementow=0;
		rozmiar_tab=1;
		tablica=new int[rozmiar_tab];
		if (tablica==NULL)
		{
			cerr << "Blad alokacji pamieci";
		}
		powiekszenie=1;
	}
	/*!
	 * \brief Dodanie elementu na stos.
	 * Funkcja dodaje element na koniec stosu, jezeli brakuje miejsca powieksza pamiec
	 * \param[in] el_dodawany - zmienna stala, ktora ma zostac dodana na koniec stosu
	 * \return (brak)
	 */
	void push(int el_dodawany);

	/*!
	 * \brief Zdejmowanie elementu ze stosu.
	 * Funkcja zdejmuje element z konca stosu, jezeli liczba elementow bedzie mniejsza
	 * badz rowna 1/4 mozliwych elementow w tablicy, zostaje ona pomniejszana.
	 * \param[in] a - wskaznik do ktorego przypisywany jest element zdejmowany, aby mogl zostal
	 * uzyty w przyszlosci
	 * \return (brak)
	 */
	void pop(int *a);
	/*!
	 * \brief Zwrocenie rozmiaru stosu
	 * Funkcja sprawdza czy stos jest pusty poprzez porownanie liczby_elementow do 0.
	 * \return true jezeli funkcja jest pusta, w przeciwnym wypadku false.
	 */
	bool isempty();
	/*!
	 * \brief Sprawdzenie rozmiaru funkcji
	 * Funkcja sprawdza ile elementow jest na stosie
	 * \return Zwraca liczbe elementow znajdujacych sie na stosie
	 */
	int size();


};


#endif /* STOS_HH_ */
