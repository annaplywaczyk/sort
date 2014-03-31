/*
 * kolejka_lista.hh
 *
 *  Created on: 13 mar 2014
 *      Author: Ania
 */

#ifndef KOLEJKA_LISTA_HH_
#define KOLEJKA_LISTA_HH_

#include <list>
#include <iostream>
#include <cstdlib>
/*!
 * \file
 * \brief Definicja klasy kolejkalista.
 *
 * Plik zawiera definicje klasy kolejkalista, w ktorej wykorzystana jest lista
 * do zapisania elementow w kolejce.
 */
using namespace std;
/*!
 * \brief
 * Klasa modeluje pojecie kolejki, bazujacej na liscie. Wykonywane sa operacje
 * dodawnia fo kolejki, zdjecia z kolejki, sprawdzenia czy jest pusta oraz sprawdzenia rozmiaru.
 * Tablice zaalokowalam w sposob dynamiczny.
 */

class kolejkalista{
private:
	/*!
	 * \brief Lista
	 * Do przechowywania elementow w kolejce uzyta zostala lista, w ktorej uzyte sa
	 * liczby calkowite
	 */

	list <int>lista;

public:

	/*!
	 * \brief Dodanie elementu z kolejki
	 * Funkcja dodaje element na poczatek kolejki.
	 * \param[in] el_dodawany - zmienna stala, ktora ma zostac dodana poczatek kolejki
	 * \return (brak)
	 */
	void enqueue(int el_dodawany);

	/*!
	 * \brief Zdejmowanie elementu z kolejki.
	 * Funkcja zdejmuje element z konca kolejki.
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
	 * \brief Zrowcenie rozmiaru funkcji.
	 * Funkcja sprawdza ile elementow jest w kolejce
	 * \return Zwraca liczbe elementow.
	 */
	int size();

};







#endif /* KOLEJKA_LISTA_HH_ */
