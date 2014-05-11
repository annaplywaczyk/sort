/*
 * drzewobinarne.hh
 *
 *  Created on: 10 kwi 2014
 *      Author: Ania
 */

#ifndef DRZEWOBINARNE_HH_
#define DRZEWOBINARNE_HH_

#include <iostream>
#include <string>
/*!
 * \file
 * \brief
 * Plik naglowkowy wykorzystywany do stworzenia drzewa binarnego do przechowywania
 * tablicy o zadanym kluczu i wartosci. W pliku stworzona jest struktura gdzie zdefiniowany
 * jest element wektora oraz klasa gdzie wystepuja wszystkie funkcje operujace na drzewie.
 */
using namespace std;

/*!
 * \brief
 * Struktura wezel w ktorej zdefiniowany jest element tablicy czyli klucz, ktory jest stringiem i
 * jego wartosc, ktora jest szablonem. W strukturze tej znajduje sie rowniez wskaznik do
 * konkretnego wezla (rodzica i jego dzieci), co ulatwia nam poruszanie sie po drzewie.
 */
template <typename Wartosc>
struct wezel{
	wezel *lewy, *prawy, *rodzic;
	string Klucz;
	Wartosc Wart_Klucza;
};

/*!
 * \brief
 * W klasie drzewo wartosciami prytwatnymi (dostepnymi tylko przez metody klasy)
 * jest licznik liczba_elementow, ktory zlicza ile jest elementow w drzewie binarnym
 * oraz wektor, ktory jest wskaznikiem na korzen elementu.
 * Metodami publicznymi klasy sa funkcje dodajace elemnty, usuwajace i pobierajace
 * element z wektora.
 */
template <typename Wartosc>
class drzewo{
private:
	/*!
	 * \brief
	 * Tworzenie korzenia o zadanym kluczu i jego wartosci oraz inicjowanie wskaznika na rodzica i jego dzieci.
	 */
	struct wezel<Wartosc> *korzen;
	/*!
	 * \brief
	 * Licznik zliczajacy liczbe elementow znajdujacyc sie w drzewie.
	 */
	int liczba_elementow;
public:
	/*!
	 * \brief
	 * Konstruktor inicjujacy wartosci przy wywolaniu klasy.
	 */
	drzewo()
{
		liczba_elementow=0;
		korzen=NULL;
}
	/*!
	 * \brief Funkcja dodajaca element do tablicy
	 * Funkcja dodaje kolejne elementy do drzewa binarnego badz zmienia wartosci
	 * juz istniejcych elementow, jezeli takie istnieja w niej.
	 * \param[in] Pierwszy_Elem - jest to Klucz czyli indeks tablicy
	 * \param[in] Drugi_Elem - zmienna ta jest wartosc klucza, moze przyjmowac rozne typy
	 * \return(brak)
	 */
	void dodaj(string Pierwszy_Elem, Wartosc Drugi_Elem);
	/*!
	 * \brief Funkcja pobieraca element z tablicy.
	 * Funkcja pobiera wartosc, ktora znajduje sie pod wskazanym kluczem.
	 * \param[in] Pierwszy_Elem - jest to Klucz wektora, czyli indeks tablicy
	 * \return Funkcja zwraca wartosc jaka znajduje sie pod wskazanym kluczem,
	 * ktora przyjmuje typ zmiennej w zaleznosci od wykorzystania i zdefiniowania przez uzytkownika.
	 */
	Wartosc pobierz(string Pierwszy_Elem);
	/*!
	 * \brief Usuwanie wskazanego elementu
	 * Funkcja usuwa element o wskazanym kluczu.
	 * \param[in] Pierwszy_Elem - jest to Klucz wektora
	 * \return (brak)
	 */
	void usun(string Pierwszy_Elem);
	/*!
	 * \brief Sprawdzanie rozmiaru tablicy.
	 * \return Funkcja zwraca liczbe calkowita, ktora jest rozmiarem calego drzewa binarnego.
	 */
	int rozmiar();
	/*!
	 * \brief Najmniejszy element drzewa.
	 * Funkcja wyszukuje najmniejszy element znajdujacy sie w drzewie. Funkcja wykorzystywana jest do
	 * usuwania elemntu z wektora.
	 * \param[in] w - jest to wektora, ktory jest drzewem binarnym
	 * \return Funkcja zwraca wartosc najmniejszego elementu znajdujacego sie w wezle
	 */
	struct wezel<Wartosc>* Najmniejszy_Element(struct wezel<Wartosc>* w)
		{
			struct wezel<Wartosc> *najmniejszy=w;
			while(najmniejszy->lewy!=NULL)
			{
				if(najmniejszy->lewy!=NULL)
				{
					najmniejszy=najmniejszy->lewy;
				}
			}
			return najmniejszy;
		};

	/*!
	 * \brief Wyszukiwanie elementu
	 * Szukanie nastepnika, ktory bedzie zastepowal miejsce usunietego elementu.
	 * Funkcja uzyteczna jest do usuwania elementu.
	 * \param[in] w - jest to wektora, ktory jest drzewem binarnym
	 * \return Funkcja zwraca wartosc najmniejszego elementu znajdujacego sie w wezle
	 */
	struct wezel<Wartosc>* Posz_Nastep(struct wezel<Wartosc>* w)
		{
			struct wezel<Wartosc> *nastepnik;
			if(w->prawy != NULL)
			{
				nastepnik = Najmniejszy_Element(w->prawy);
			}
			else if(w==NULL)
			{
				nastepnik = NULL;
			}
			else
			{
				nastepnik=w->rodzic;
				while(nastepnik != NULL && w == nastepnik->prawy)
				{
					w=nastepnik;
					nastepnik=w->rodzic;
				}
			}
			return nastepnik;
		}
};

template <typename Wartosc>
void drzewo<Wartosc>::dodaj(string Pierwszy_Elem, Wartosc Drugi_Elem)
{
	struct wezel<Wartosc> *nowy;
	nowy = new struct wezel<Wartosc>;
	nowy->lewy=NULL;
	nowy->prawy=NULL;
	nowy->rodzic=NULL;
	nowy->Klucz=Pierwszy_Elem;
	nowy->Wart_Klucza=Drugi_Elem;

	//jezeli w drzewie nic sie nie znaduje dodaj nowy korzen bez przeszukiwania
	if(liczba_elementow==0)
	{
		korzen=nowy;
		liczba_elementow++;
	}
	// wyszukujemy gdzie powinnismy wstawic nowy korzen
	else
	{
		struct wezel<Wartosc> *gdzie_wstawic=korzen;
		struct wezel<Wartosc> *rodzice;

		while(gdzie_wstawic!=NULL)
		{

			//porownujemy wartosci klucza znajdujacego sie na drzewie z wartoscia ktora chcemy wstawic
			if(Pierwszy_Elem < gdzie_wstawic->Klucz)
			{
				rodzice=gdzie_wstawic;
				gdzie_wstawic=gdzie_wstawic->lewy;

			}
			else if(Pierwszy_Elem > gdzie_wstawic->Klucz)
			{
				rodzice=gdzie_wstawic;
				gdzie_wstawic=gdzie_wstawic->prawy;
			}
			else
			{
				rodzice=gdzie_wstawic;
				gdzie_wstawic->Wart_Klucza=Drugi_Elem;
				break;
			}
		}

		if(Pierwszy_Elem < rodzice->Klucz)
		{
			rodzice->lewy=nowy;
			nowy->rodzic=rodzice;
			liczba_elementow++;

		}
		else if(Pierwszy_Elem > rodzice->Klucz)
		{
			rodzice->prawy=nowy;
			nowy->rodzic=rodzice;
			liczba_elementow++;

		}
	}
}

template <typename Wartosc>
Wartosc drzewo<Wartosc>::pobierz(string Pierwszy_Elem)
{
	struct wezel<Wartosc> *poszukiwany=korzen;

	if(liczba_elementow==0)
	{
		cerr << "Brak elementu do zdjecia"<< endl;
	}
	else
	{
		while(poszukiwany!=NULL)
		{
			if( Pierwszy_Elem < poszukiwany->Klucz)
			{
				poszukiwany=poszukiwany->lewy;
			}
			else if (Pierwszy_Elem > poszukiwany->Klucz)
			{
				poszukiwany=poszukiwany->prawy;
			}
			else if(Pierwszy_Elem == poszukiwany->Klucz)
			{
				return poszukiwany->Wart_Klucza;
			}
			else
			{
				cerr<< "Nie ma poszukiwanego elementu" << endl;
			}
		}
	}
}

template <typename Wartosc>
void drzewo<Wartosc>::usun(string Pierwszy_Elem)
{
	//poszukiwanie elementu
	struct wezel<Wartosc> *poszukiwany=korzen;
	if(liczba_elementow==0)
	{
		cerr << "Brak elementu do zdjecia"<< endl;
	}
	else
	{
		while(poszukiwany!=NULL)
		{
			if( Pierwszy_Elem < poszukiwany->Klucz)
			{
				poszukiwany=poszukiwany->lewy;
			}
			else if (Pierwszy_Elem > poszukiwany->Klucz)
			{
				poszukiwany=poszukiwany->prawy;
			}
			else if(Pierwszy_Elem == poszukiwany->Klucz)
			{
				break;
			}
			else
			{
				cerr<< "Nie ma poszukiwanego elementu" << endl;
			}
		}
	}

	//gdy usuwany element nie ma dzieci
	if(poszukiwany->lewy == NULL && poszukiwany->prawy == NULL)
	{

		if(poszukiwany->Klucz < poszukiwany->rodzic->Klucz)
		{
			poszukiwany->rodzic->lewy=NULL;
		}
		else if(poszukiwany->Klucz > poszukiwany->rodzic->Klucz)
		{
			poszukiwany->rodzic->prawy=NULL;
		}
		delete poszukiwany;
	}
	//gdy usuwany element ma jedno dziecko
	else if(poszukiwany->lewy == NULL || poszukiwany->prawy == NULL)
	{
		if(poszukiwany->lewy == NULL)
		{
			if(poszukiwany->Klucz < poszukiwany->rodzic->Klucz)
			{
				poszukiwany->rodzic->lewy = poszukiwany->prawy;
				poszukiwany->prawy->rodzic=poszukiwany->rodzic;
				delete poszukiwany;
			}
			else if(poszukiwany->Klucz > poszukiwany->rodzic->Klucz)
			{
				poszukiwany->rodzic->prawy = poszukiwany->prawy;
				poszukiwany->prawy->rodzic=poszukiwany->rodzic;
				delete poszukiwany;
			}

		}
		else
		{
			if(poszukiwany->Klucz < poszukiwany->rodzic->Klucz)
			{
				poszukiwany->rodzic->lewy = poszukiwany->lewy;
				poszukiwany->lewy->rodzic=poszukiwany->rodzic;
				delete poszukiwany;
			}
			else if(poszukiwany->Klucz > poszukiwany->rodzic->Klucz)
			{
				poszukiwany->rodzic->prawy = poszukiwany->lewy;
				poszukiwany->lewy->rodzic=poszukiwany->rodzic;
				delete poszukiwany;
			}
		}
	}
	//gdy usuwany element ma dwojke dzieci
	else
	{

		struct wezel<Wartosc> *zmienna=Posz_Nastep(poszukiwany);
		if(zmienna->prawy !=NULL) zmienna->prawy->rodzic=zmienna->rodzic;
		zmienna->rodzic->lewy=zmienna->prawy;
		zmienna->rodzic=poszukiwany->rodzic;
		if(poszukiwany->Klucz < poszukiwany->rodzic->Klucz)
		{
			poszukiwany->rodzic->lewy=zmienna;
		}
		else if(poszukiwany->Klucz > poszukiwany->rodzic->Klucz)
		{
			poszukiwany->rodzic->prawy=zmienna;
		}
		zmienna->lewy=poszukiwany->lewy;
		zmienna->prawy=poszukiwany->prawy;
		zmienna->prawy->rodzic=zmienna;
		zmienna->lewy->rodzic=zmienna;
		delete poszukiwany;
	}
	liczba_elementow--;
}


template <typename Wartosc>
int drzewo<Wartosc>::rozmiar()
{
	return liczba_elementow;
}
#endif /* DRZEWOBINARNE_HH_ */
