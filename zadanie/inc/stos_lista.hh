/*
 * stos_lista.hh
 *
 *  Created on: 13 mar 2014
 *      Author: Ania
 */

#ifndef STOS_LISTA_HH_
#define STOS_LISTA_HH_
#include <list>
#include <iostream>
#include <cstdlib>
/*!
 * \file
 * \brief Definicja klasy stoslista.
 *
 * Plik zawiera definicje klasy stoslista, ktora do zapisu i zapamietania liczb uzywa listy.
 */
using namespace std;
/*!
 * \brief
 * Klasa modeluje pojecie stosu,bazujacego na liscie. Na stosie wyonywane sa operacje
 * dodatnia na stos, zdjecia ze stosu, sprawdzenia czy jest pusty oraz sprawdzenia rozmiaru.
 */
class stoslista{
private:
	/*!
	 * \brief Lista
	 * Do przechowywania elementow na stosie uzyta zostala lista, w ktorej uzyte sa
	 * liczby calkowite
	 */
	list <int>lista;

public:

	/*!
	 * \brief Dodanie elementu na stos.
	 * Funkcja dodaje element na koniec stosu
	 * \param[in] el_dodawany - zmienna stala, ktora ma zostac dodana na koniec stosu
	 * \return (brak)
	 */
	void push(int el_dodawany);

	/*!
	 * \brief Zdejmowanie elementu ze stosu.
	 * Funkcja zdejmuje element z konca stosu.
	 * \param[in] a - wskaznik do ktorego przypisywany jest element zdejmowany, aby mogl zostal
	 * uzyty w przyszlosci
	 * \return (brak)
	 */
	void pop(int *a);
	/*!
	 * \brief Sprawdzenie czy funkcja jest pusta
	 * Funkcja sprawdza czy stos jest pusty poprzez uzycie funkcji size ktora dziala na liscie.
	 * \return true jezeli funkcja jest pusta, w przeciwnym wypadku false.
	 */
	bool isempty();
	/*!
	 * \brief Zwrocenie rozmiaru funkcji
	 * Funkcja sprawdza ile elementow jest na stosie
	 * \return Zwraca liczbe elementow znajdujacych sie na stosie.
	 */
	int size();

};




#endif /* STOS_LISTA_HH_ */
