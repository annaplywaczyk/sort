/*
 * uruchom.hh
 *
 *  Created on: 8 mar 2014
 *      Author: Ania
 */

#ifndef DANE_HH_
#define DANE_HH_
/*!
 * \file
 * \brief Definicja klasy dane
 *
 * Plik zawiera definicje klasy dane, ktora jest klasa podstawowa programu
 */
#include <iostream>
#include <string>
#include <vector>


using namespace std;

/*!
 * \brief Modeluje pojecie danych, u¿ytych w programie, które w moim przypadku
 * sa wektorem, ktory zostaje wczytany z pliku. Pierwsza zmienna wczytana z pliku
 * jest liczba elemntow wystepujacych w tym pliku. Przyjelam, ze zmienne wczytane z pliku
 * sa liczbami calkowitymi (int).
 */


class dane{
private:
	/*!
	 * \brief Inicjalizuje liczbe elementow.
	 * Liczba elementow zostaje okreslona poprzez wczytanie z pliku pierwszej zmiennej i okresla
	 *  ile zmiennych bedzie w wektorze,ktore wczytane zostana z pliku wystepujacych w pliku.
	 */
	int liczba_el;
	/*!
	 * \brief Inicjalizuje wektor.
	 * Tworzy wektor, ktory zostanie wypelniony elemenatami znajdujacymi sie w pliku.
	 * W wektorze znajdowac sie beda zmienne, ktore beda liczbami calkowitymi.
	 */
	vector<int>wektor;
public:
	/*!
	 * \brief Funkcja wczytuj¹ca dane do wektora z pliku.
	 * Funkcja otwiera plik zdefiniowany w glownej funkcji przez u¿ytkownika, sprawdza czy plik zosta³ otwarty,
	 * je¿eli zosta³ otwarty wczytana jest liczba elementow pliku, nastepnie wczytywane sa wszystkie
	 * liczby do wektora.
	 * \param[in] nazwa - zmienna, która zostaje wprowadzona przez u¿ytkownika do programu
	 * \return (brak)
	 */
	void wczytaj(string nazwa);
	/*!
	 * \brief Funkcja wypisuj¹ca na ekran wszystkie elementy wektora.
	 * Funkcja wypisuje na ekran wsyztskie elemnty z pliku na ekran w postaci wektora w kolumnie.
	 * \return (brak)
	 */
	void wypisz();
	/*!
	 * \brief Zamiana elementow
	 * Funkcja zamiania dwa elementy wektora, zadane poprzez wywolanie argumentow funkcji
	 * \param[in] i - pierwszy numer elementu, ktory ma zostac zamieniony.
	 * \param[in] j- drugi numer elementu, ktory ma zostac zamieniony.
	 * \return (brak)
	 */
	void zamien_element(int i, int j);
	/*!
	 * \brief Dodawanie elementu.
	 * Funkcja dodaje element na koniec wektora. Funkcja zdefiniowana jest
	 * poprzez wywolanie argumentow funkcji.
	 * \param[in] e - liczba, ktora ma zostac dodana na koniec wektora.
	 * return (brak)
	 */
	void dodaj_element(int e);
	/*!
	 * \brief Odwracanie elementow
	 * Funkcja ogawraca wektor, ostatni element wektora staje siê pierwszy, a pierwszy ostatnim
	 * \return (brak)
	 */
	void odwroc_element();
	/*!
	 * \brief Dodawanie elementu.
	 * Funkcja dodaje element na koniec wektora. Funkcja zdefiniowana jest
	 * poprzez wywolanie argumentow funkcji.
	 * \param[in] wektor2 - wektor, ktory ma zostac dodany na koniec wektora, z dwoch zostaje stworzony jeden.
	 * return (brak)
	 */
	void dodaj_elementy(dane wektor2);
	/*!
	 * \brief Uzycie operatora []
	 * Przeciazenie operatora stwoarzone abysmy mogli odwolac sie do konkretnego elementu wektora
	 * \param[in] indeks - zmienna calkowita, poperzez ktora mozemy dostac do konkretnego elementu wektora.
	 * \return Zwraca wartosc jaka znajduje siê w zadanym elemencie wektora.
	 */
	int & operator [](int indeks);
	/*!
	 * \brief Rozmiar wektora
	 * \return Funkcja zwaraca liczbe elementow wektora.
	 */
	unsigned int size () {
		return wektor.size();
	}
	/*!
	 * \brief Uzycie operatora + na wektorze
	 * Przeciazenie operatora dodwania, ktory mozemy wykonywac na wektorach.
	 * \param[in] wektor2 - wektor danych ktory ma zostac dodany do wektora glownego
	 * \return Zwraca wektor, ktory jest suma dwoch innych
	 */
	dane & operator + (dane wektor2);
	/*!
	 * \brief Uzycie operatora = na wektorze
	 * Przeciazenie opertora przypisywania
	 * \param[in] wektor2 - wektor danych ktory ma zostac przypisany do wektora glownego
	 * \return Zwraca wektor, do ktorego zostal przypisany inny wektor
	 */
	dane & operator = (dane wektor2);
	/*!
	 * \brief Metoda daj¹ca dostep do zawartosci wektora danych
	 * \return Wektor danych.
	 */
	vector<int>& wnetrze(){
		return wektor;
	}
	/*!
	 * \brief Operator porownania dwoch wektorow
	 * Funkcja, ktora jest operatorem porownania dwoch wektorow
	 * \param[in] wektor2 - wektor danych ktory zostaje porownany z danymi glownymi
	 * \return True gdy wektory danych sa jednakowe, natomiast jesli nawet jeden
	 * element sie rozni od wektora porownywanego zwraca false.
	 */
	bool operator == (dane wektor2);
	/*!
	 * \brief Funkcja usuwaj¹ca pierwszy elemnt z wektora.
	 * Funckja usuwa pierwszy element znajduj¹cy siê na wektorze jednoczesnie zmniejszajac
	 * liczbe elemntow, funkcja potrzebna przy sortowaniu przez scalanie.
	 */
	void usun()
	{
		wektor.erase(wektor.begin());
		liczba_el--;
	}
	/*!
	 * \brief Funkcja usuwajaca ostatni element wektora
	 * Funkcja usuwa ostatni element wektora jednoczesnie zmniejszajac liczbe elementow,
	 * czyli rozmiar tablicy.
	 */
	void usun_ostatni()
	{
		wektor.pop_back();
		liczba_el--;
	}
	/*!
	 * \brief Zwalnia pamiec
	 * Funkcja usuwa caly wektor z pamieci.
	 */
	void czysc()
	{
		wektor.clear();
	}
};

#endif /* DANE_HH_ */
