/*
 * uruchom.hh
 *
 *  Created on: 11 maj 2014
 *      Author: Ania
 */

#ifndef URUCHOM_HH_
#define URUCHOM_HH_

#include <windows.h>
#include "thaszujaca.hh"
#include <vector>

using namespace std;
/*!
 * \file
 * \brief
 * Klasa odpowaidaj¹ca za dzia³anie i sprawdzenie z³o¿onoci obliczeniowej ka¿dego rodzaju
 * tablicy asocjacyjnej. To w tej kalsie wlaczamy i wylaczamy stoper, wczytujemy
 * plik z danymi i wykonujemy algorytm.
 */
class dzialanie{
private:
	hash_table<int> tablica;
	vector<string> klucze;
public:
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
	* \brief Funkcja wykonuj¹ca zadany algorytm na wektorze.
	* Funkcja wykonuje zadany algorytm na wektorze wejsciowym.
	* W naszym przypadku pobieranie elementow o zadanym kluczu z tablicy asocjacyjnej.
	* \return (brak)
	*/
	void algorytm();
	/*!
	 * \brief
	 * Funkcja odpowiedzialana za zmierzenie czasu dzialania danego algorytmu i jego zwrocenie.
	 * return Funkcja zwraca czas pobrania wartosci z tablicy.
	 */
	int stoper();
	/*!
	 * \brief
	 * Funkcja czysci wektor kluczy, s³u¿¹cy do pobierania danych z tablicy asocjacyjnej. Aby  nie
	 * zostaly dopisywane klucze do poprzednich, gdyz wydluzylo by to czas dzialania.
	 */
	void czysc();
};



#endif /* URUCHOM_HH_ */
