/*
 * kolejka.hh
 *
 *  Created on: 15 mar 2014
 *      Author: Ania
 */

#ifndef KOLEJKA_HH_
#define KOLEJKA_HH_
/*!
 * \file
 * \brief Definicja klasy kolejkatab.
 *
 * Plik zawiera definicje klasy kolejkatab, w ktorej wykorzystana jest tablica
 * do zapisania elementow w kolejce.
 */

#include "uruchom.hh"

using namespace std;

/*!
 * \brief
 * Klasa modeluje pojecie kolejki, bazujacej na tablicy. Wykonywane sa operacje
 * dodawnia do kolejki, zdjecia z kolejki, sprawdzenia czy jest pusta oraz sprawdzenia rozmiaru.
 * Tablice zaalokowalam w sposob dynamiczny. Dodatkowo u¿yte niektore funkcje pomocnicze
 * jak np. powiekszenie tablicy.
 */
class kolejkatab{
private:
	/*!
	 * \brief
	 * Liczba elemntow ktore tablica moze pomiescic w kolejce.
	 */
	int rozmiar_tab;
	/*!
	 * \brief
	 * Liczba elementow znajujacych sie w kolejce
	 */
	int liczba_elementow;
	/*!
	 * \brief Tablica
	 * Do przechowywania elementow w kolejce uzyta zostala dynamiczna alokacja pamieci. Tablica
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
	kolejkatab() {
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
	 * \brief Dodanie elementu z kolejki
	 * Funkcja dodaje element na poczatek kolejki, jezeli brakuje miejsca podwaja pamiec
	 * \param[in] el_dodawany - zmienna stala, ktora ma zostac dodana na koniec stosu
	 * \return (brak)
	 */
	void enqueue(int el_dodawany);

	/*!
	 * \brief Zdejmowanie elementu z kolejki.
	 * Funkcja zdejmuje element z konca kolejki, jezeli liczba elementow bedzie mniejsza
	 * badz rowna 1/4 mozliwych elementow w tablicy, zostaje ona pomniejszana.
	 * \param[in] a - wskaznik do ktorego przypisywany jest element zdejmowany, aby mogl zostal
	 * uzyty w przyszlosci
	 * \return (brak)
	 */
	void dequeue(int *a);
	/*!
	 * \brief Sprawdzanie pojemnosci w kolejce.
	 * Funkcja sprawdza czy jest pusta poprzez porownanie liczby_elementow do 0.
	 * \return true jezeli funkcja jest pusta, w przeciwnym wypadku false.
	 */
	bool isempty();
	/*!
	 * \brief Sprawdzenie rozmiaru funkcji
	 * Funkcja sprawdza ile elementow jest w kolejce
	 * \return (brak)
	 */
	int size();


};


#endif /* KOLEJKA_HH_ */
