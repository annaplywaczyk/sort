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
 * Klasa odpowaidaj�ca za dzia�anie i sprawdzenie z�o�onoci obliczeniowej ka�dego rodzaju
 * tablicy asocjacyjnej. To w tej kalsie wlaczamy i wylaczamy stoper, wczytujemy
 * plik z danymi i wykonujemy algorytm.
 */
class dzialanie{
private:
	hash_table<int> tablica;
	vector<string> klucze;
public:
	/*!
	* \brief Funkcja zapamietuj�ca czas poczatkowy.
	* Funkcja nale��ca do biblioteki "windows.h",  stoper zostaje w��czony.
	* Funkcja nale��ca do funkcji bool QueryPerformanceCounter(_out LARGE_INTEGER *IpPerformanceCount),
	* funkcja ta zwraca wartosc niezerowa je�eli w�aczenie zako�czy si� sukcesem, natomiast w przeciwnym wypadku
	* zostanie wyrzucony b��d i zwr�ci wartosc 0. Dla komputer�w multiprocesorowych nie ma znaczenia, kt�ry jest u�ywany,
	* mog� jedynie r�ni� si� minimalnie czasy.
	*/
	LARGE_INTEGER wlaczStoper();
	/*!
	* \brief Funkcja zapamietuj�ca czas ko�cowy.
	* Funkcja nale��ca do biblioteki "windows.h",  stoper zostaje wy��czony, aby zosta� zmierzony czas wykonania
	* algorytmu w programie, poprzez odj�cie czasu pocz�tkowego od czasu ko�cowego.
	* Funkcja nale��ca do funkcji bool QueryPerformanceCounter(_out LARGE_INTEGER *IpPerformanceCount),
	* funkcja ta zwraca wartosc niezerowa je�eli wy�aczenie zako�czy si� sukcesem, natomiast w przeciwnym wypadku
	* zostanie wyrzucony b��d i zwr�ci wartosc 0. Dla komputer�w multiprocesorowych nie ma znaczenia, kt�ry jest u�ywany,
	* mog� jedynie r�ni� si� minimalnie czasy.
	*/
	LARGE_INTEGER wylaczStoper();
	/*!
	 * \brief Funkcja wczytuj�ca dane do stosu.
	 * Funkcja otwiera plik zdefiniowany w glownej funkcji przez u�ytkownika, sprawdza czy plik zosta� otwarty,
	 * je�eli zosta� otwarty wczytana jest liczba elementow pliku, nastepnie wczytywane sa wszystkie
	 * liczby do tablicy.
	 * \param[in] nazwa - zmienna, kt�ra zostaje wprowadzona przez u�ytkownika do programu
	 * \return (brak)
	 */
	void wczytaj(string nazwa);
	/*!
	* \brief Funkcja wykonuj�ca zadany algorytm na wektorze.
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
	 * Funkcja czysci wektor kluczy, s�u��cy do pobierania danych z tablicy asocjacyjnej. Aby  nie
	 * zostaly dopisywane klucze do poprzednich, gdyz wydluzylo by to czas dzialania.
	 */
	void czysc();
};



#endif /* URUCHOM_HH_ */
