/*
 * thaszujaca.hh
 *
 *  Created on: 23 kwi 2014
 *      Author: Ania
 */

#ifndef THASZUJACA_HH_
#define THASZUJACA_HH_

#include <iostream>
#include <string>
#include <list>

/*!
 * \file
 * \brief
 * Plik naglowkowy wykorzystywany do stworzenia tablicy haszujacej do przechowywania
 * tablicy o zadanym kluczu i wartosci. W pliku stworzona jest struktura gdzie zdefiniowany
 * jest element wektora oraz klasa gdzie wystepuja wszystkie funkcje operujace na tabilcy.
 */
using namespace std;
/*!
 * \brief
 * Struktura obiekt w ktorej zdefiniowany jest element tablicy czyli klucz, ktory jest stringiem i
 * jego wartosc, ktora jest szablonem.
 */
template <typename Wartosc>
struct obiekt{
	string Klucz;
	Wartosc Wart_Klucza;
};


/*!
 * \brief
 * W klasie hash_table wartosciami prytwatnymi (dostepnymi tylko przez metody klasy)
 * jest liczba_elementow, ktora definiuje stala wartosc elelmntow znajdujacych sie na liscie
 * oraz lista, ktora jest wskaznikiem na korzen elementu.
 * Metodami publicznymi klasy sa funkcje dodajace elemnty, usuwajace i pobierajace
 * element z wektora.
 */
template <typename Wartosc>
class hash_table{
	/*!
	 * \brief
	 * Liczba elementow stala liczba,ktora pomaga w definiowaniu stalej wartosci listy
	 */
	static const int liczba_elementow=10000;
	/*!
	 * \brief
	 * Lista, w ktorej przechowywana jest tablica haszujaca.
	 */
	list<obiekt<Wartosc> > lista[liczba_elementow];
public:
	/*!
	 * \brief
	 * Funkcja tworzaca hash klucza, czyli za konkretne litery podstawiane sa wartosci
	 * w kodzie ASCII i dzielone jest modulo liczbe liczba_elemntow mozliwych dostepnych
	 * na liscie.
	 * \param[in] Pierwszy_Elem - string z ktorego zliczany jest hash
	 * \return Funkcja zwraca liczbe calkowita, liczba ta bedzie indeksem listy, w ktorej
	 * przypisany bedzie obiekt.
	 */
	int hash(string Pierwszy_Elem);
	/*!
	 * \brief Funkcja dodajaca element do tablicy
	 * Funkcja dodaje kolejne elementy do drzewa binarnego badz zmienia wartosci
	 * juz istniejcych elementow, jezeli takie istnieja w niej. Funkcja dodaje elemnty
	 * pod indeks, ktory zwraca funkcja hash. Pod kazdym indeksem listy jest tworzona osobna
	 * lista i kilka elementow moga sie znajdowac pod tym samym elementem tablicy.
	 * \param[in] elem - jest to lista w ktorej znajuduje sie klucz i jego wartosc
	 * \return(brak)
	 */
	void dodaj(obiekt<Wartosc> elem);
	/*!
	 * \brief Usuwanie wskazanego elementu
	 * Funkcja usuwa element o wskazanym kluczu.
	 * \param[in] Pierwszy_Elem - jest to Klucz wektora
	 * \return (brak)
	 */
	bool usun(string Pierwszy_Elem);
	/*!
	 * \brief Funkcja pobieraca element z tablicy.
	 * Funkcja pobiera wartosc, ktora znajduje sie pod wskazanym kluczem.
	 * \param[in] Pierwszy_Elem - jest to Klucz, ktory wyszukiwana jest jego wartosc.
	 * \return Funkcja zwraca wartosc jaka znajduje sie pod wskazanym kluczem,
	 * ktora przyjmuje typ zmiennej w zaleznosci od wykorzystania i zdefiniowania przez uzytkownika.
	 */
	Wartosc pobierz(string Pierwszy_Elem);
	/*!
	 * \brief
	 * Funkcja pomocnicza stworzona w celu wypisania tablicy haszujacej i sprawdzenia
	 * prawidlowego dzialania funkcji dodanaia, usuniecia i pobrania elementow.
	 */
	void wypisz()
	{
		for (int i=0; i< 10; i++){
			cout<<"lista[ "<<i<< " ] = ";
			typename list<obiekt<Wartosc> >::iterator iter;
			iter=lista[i].begin();

			for(;iter!=lista[i].end(); iter++)
			{
				cout << iter->Klucz <<"  ;  ";
			}
			cout << endl;
		}

	}
	int rozmiar();
};

template<typename Wartosc>
void hash_table<Wartosc>::dodaj(obiekt<Wartosc> elem)
{
	int index = hash(elem.Klucz);

	typename list<obiekt<Wartosc> >::iterator iter;
	iter=lista[index].begin();

	for(;iter!=lista[index].end(); iter++)
	{
		if(iter->Klucz==elem.Klucz)
		{
			iter->Wart_Klucza=elem.Wart_Klucza;
		}
	}
	lista[index].push_back(elem);


}

template<typename Wartosc>
bool hash_table<Wartosc>::usun(string Pierwszy_Elem)
{
	int index = hash(Pierwszy_Elem);
	typename list<obiekt<Wartosc> >::iterator iter;
	iter=lista[index].begin();

	for(;iter!=lista[index].end(); ++iter)
	{
		if(iter->Klucz==Pierwszy_Elem)
		{

			lista[index].erase(iter);
			return true;
		}
	}
	return false;
}


template<typename Wartosc>
Wartosc hash_table<Wartosc>::pobierz(string Pierwszy_Elem)
{
	int index = hash(Pierwszy_Elem);
	Wartosc wartosc;
	typename list<obiekt<Wartosc> >::iterator iter;
	iter=lista[index].begin();

	for(;iter!=lista[index].end(); ++iter)
	{
		if(iter->Klucz==Pierwszy_Elem)
		{
			wartosc=iter->Wart_Klucza;
		}
	}
	return wartosc;
}

template <typename Wartosc>
int hash_table<Wartosc>::hash(string Pierwszy_Elem)
{
	int h=0;
	int dlugosc=Pierwszy_Elem.length();
	int index;

	for(int i=0; i<dlugosc; i++)
	{
		h=h+(int)Pierwszy_Elem[i];
	}

	index=h%liczba_elementow;

	return index;
}


#endif /* THASZUJACA_HH_ */
