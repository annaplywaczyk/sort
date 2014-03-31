/*
 * uruchom.hh
 *
 *  Created on: 8 mar 2014
 *      Author: Ania
 */

#ifndef URUCHOM_HH_
#define URUCHOM_HH_

/*!
 * \file
 * \brief Definicja klasy zegar
 *
 * Plik zawiera definicje klasy zegar, ktora jest klasa glowna programu.
 * Klasa ta jest pochodna i specjalizacja klasy dane.
 */
#include "dane.hh"
#include <windows.h>
#include "stos.hh"

using namespace std;
/*!
 * \brief Klasa modeluje uruchomienia g³ownych wlasciowosci programu.
 * Atrybutem klasy sa stowrzone dwa elemnty klasy dane, na ktorych wykonywane sa dzialania.
 */

class zegar{
private:
	/*!
	 * \brief Element podsatwowy klasy dane.
	 * Dane_podstawowe sa elementem klasy dane, na ktorych wykonywany jest alagorytm
	 * oraz jest jakby glownym elementem programu.
	 */
	dane dane_podstawowe;
	/*!
	 * \brief Element sprawdzajacy klasy dane.
	 * Dane_sprawdzjace sa elementem klasy dane, wektor ten wykorzystywany jest do porownania
	 * wykannego algorytmu z denymi podstawowymi.
	 */
	dane dane_sprawdzajace;
	stos stosik;

public:
	zegar(){
		stos stos(2);
		stosik=stos;
	};
	/*!
	 * \brief Wczytanie danych podstawowych
	 * Funkcja wczytuje dane, na ktorych wykonywany jest algorytm.
	 * Dane te sa glowna funkcja programu.
	 * \param[in] nazwa_pliku_pod - jest to zmienna ktora jest ciagiem
	 * znakow (nazwa pliku), ktory ma zostac otwarty.
	 * \return (brak)
	 */
	void wczytaj_dane_pod(string nazwa_pliku_pod){
		dane_podstawowe.wczytaj(nazwa_pliku_pod);
	}
	/*!
	 * \brief Wczytanie danych sprawdzajacych
	 * Funkcja wczytuje dane, na ktore zostaja porwonane z danymi na ktorych
	 * zostal wykonany algorytm.
	 * \param[in] nazwa_pliku_spr - jest to zmienna ktora jest ciagiem
	 * znakow (nazwa pliku), ktory ma zostac otwarty, w celu porownania.
	 * \return (brak)
	 */
	void wczytaj_dane_spr(string nazwa_pliku_spr){
		dane_sprawdzajace.wczytaj(nazwa_pliku_spr);
	}
	/*!
	* \brief Funkcja wykonuj¹ca zadany algorytm na wektorze.
	* Funkcja wykonuje zadany algorytm na wektorze wejsciowym.
	* W naszym przypadku wektor pomno¿ony jest przez sta³¹ liczbê 2.
	* \return (brak)
	*/
	void algorytm();
	/*!
	* \brief Funkcja porównuj¹ca dwa wektory.
	* Funkcja porównuje dwa wektory, sprawdza czy wszystkie elemnty s¹ ze sob¹ równe.
	* \return Funkcja zwraca true jezeli wektory sa jednakowe w przeciwnym wypadku zostaje wzrocony false.
	*/
	bool porownaj(){
		return dane_podstawowe==dane_sprawdzajace;
	}
	/*!
	* \brief Funkcja zapamietuj¹ca czas poczatkowy.
	* Funkcja nale¿¹ca do biblioteki "windows.h",  stoper zostaje w³¹czony.
	* Funkcja nale¿¹ca do funkcji bool QueryPerformanceCounter(_out LARGE_INTEGER *IpPerformanceCount),
	* funkcja ta zwraca wartosc niezerowa je¿eli w³aczenie zakoñczy siê sukcesem, natomiast w przeciwnym wypadku
	* zostanie wyrzucony b³¹d i zwróci wartosc 0. Dla komputerów multiprocesorowych nie ma znaczenia, który jest u¿ywany,
	* mog¹ jedynie ró¿niæ siê minimalnie czasy.
	*/
	LARGE_INTEGER wlaczStoper();
	/*!
	* \brief Funkcja zapamietuj¹ca czas koñcowy.
	* Funkcja nale¿¹ca do biblioteki "windows.h",  stoper zostaje wy³¹czony, aby zosta³ zmierzony czas wykonania
	* algorytmu w programie, poprzez odjêcie czasu pocz¹tkowego od czasu koñcowego.
	* Funkcja nale¿¹ca do funkcji bool QueryPerformanceCounter(_out LARGE_INTEGER *IpPerformanceCount),
	* funkcja ta zwraca wartosc niezerowa je¿eli wy³aczenie zakoñczy siê sukcesem, natomiast w przeciwnym wypadku
	* zostanie wyrzucony b³¹d i zwróci wartosc 0. Dla komputerów multiprocesorowych nie ma znaczenia, który jest u¿ywany,
	* mog¹ jedynie ró¿niæ siê minimalnie czasy.
	*/
	LARGE_INTEGER wylaczStoper();
	/*!
	 * \brief Funkcja wczytuj¹ca dane do stosu.
	 * Funkcja otwiera plik zdefiniowany w glownej funkcji przez u¿ytkownika, sprawdza czy plik zosta³ otwarty,
	 * je¿eli zosta³ otwarty wczytana jest liczba elementow pliku, nastepnie wczytywane sa wszystkie
	 * liczby do tablicy.
	 * \param[in] nazwa - zmienna, która zostaje wprowadzona przez u¿ytkownika do programu
	 * \return (brak)
	 */

	void wczytaj(string nazwa);

	/*!
	 * \brief Sortowanie przez scalanie glowne wywolanie funkcji
	 * Funkcja sortujaca liczby poprzez scalnie. Ta czesc funkcji dzieli ciag na dwa rowne podciagi,
	 * nastepnie kazda z czesci sortujemy, wywolujac rekurencyjnie ta funkcje. Gdy podciagi beda
	 * uporzadkowane scalilmy te male podciagi i powstanie nam ciag liczb posortowanych.
	 * \param[in] tab - zmienna bedaca wektorem, na ktorym umieszczone sa liczby do posortowania
	 * \return rezultat - funkcja zwraca wekotr posortowany.
	 */
	dane scal_sort(dane	tab);
	/*!
	 * \brief Funkcja wykorzystana do sortowania przez scalanie
	 * Funkcja ta odpowiedzialana jest za scalanie dwoch wektorow w jeden. Porownuje dwa elementy
	 * i wiekszy elemnt dodaje do wektora
	 * \param[in] lewo - wektor z ciagiem liczb do scalania(polaczenia w jeden)
	 * \param[in] prawo - wektor z ciagiem liczb do scalenia(polaczenia w jeden)
	 * \return rezultat - funkcja zwraca wektor uporzadkowany
	 */
	dane scal(dane lewo, dane prawo);

	/*!
	 * \brief Funkcja tworzaca kopiec
	 * Funkcja ta uzyta jest do sortowania poprzez kopcowanie. Tworzy drzewo binarne czyli kopiec
	 * Najwiekszy element jest na szczycie kopca i jest to tzw ojciec, ktory ma dwoch synow ktore sa
	 * mniejsze od niego, jezeli nie zamienia miejscami ojca z synem.Tak stowrzony kopiec uporzadkowany
	 * jest prawie malejaco.
	 * \param[in] tab - wektor z danymi, na ktorym bediemy operowac czyli robic kopiec.
	 * \return tab - funkcja zwraca utworzony kopiec
	 */
	dane heap(dane tab);
	/*!
	 * \brief Glowna funkcja sortujaca poprzez kopcowanie
	 * Funkcja sortujaca liczby poprzez kopcowanie. Ta czesc funkcji odpowiada za prawidlowe posortowanie
	 * ciagu liczb ktore znajduja sie na kopcu. Czyli mierzemy najwiekszy element, odkladmy go w nowym wektorze,
	 * nastepnie zamieniamy ten element z ostatnim na kopcu i go usuwamy, po czym wywolujemy funkcje utowrzenia
	 * drzewa binarnego jeszcze raz. Elementy te powtrzamy tak dlugo, az w kopcu nie bedzie zadnej liczby do posortowania.
	 * \param[in] tab - zmienna bedaca kopcem z ciagiem liczb
	 * \return wynik - funkcja zwraca wekotr posortowany.
	 */
	dane heap_sort(dane tab);

	/*!
	 * \brief Funkcja sortujaca - quicksort
	 * Zadaniem tej funkcji jest posortowanie tablicy. Funkcja ta polega na metodzie dziel i zwyciezaj.
	 * Oznacza to ze ciag liczb dzielony jest na mniejsze wzgledem ustalonego elementu, nastepnie sortowane sa elementy
	 * po lewej stronie i prawej mediany poprzez rekursywne wyowalanie funkcji. Rekursja wystepuje do momentu podzielenia
	 * wektora na jednoelementowe czesci i laczenie ich w jedna calosc.
	 * Funkcji tej sa dwie wersje wyszukiwania mediany, poprzez pierwszy element wektora lub poprzez losowa wartosc
	 * \prarm[in] a - element wzgledem ktorego ma byc podzielony wektor
	 * \param[in] b - liczba elemntow do posortowania
	 * \param[in] wektor - wektor z ciagiem liczb do posortowania
	 */
	void quick(dane *wektorQ, int a, int b);

};




#endif /* URUCHOM_HH_ */
