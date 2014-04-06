/*
 * tasocjacyjna.hh
 *
 *  Created on: 3 kwi 2014
 *      Author: Ania
 */

#ifndef TASOCJACYJNA_HH_
#define TASOCJACYJNA_HH_
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
/*!
 * \file
 * \brief
 * Plik naglowkowy tasocjacyjna, ktora sluzy do stowrzenia tablicy asocjacyjnej,
 * tablica ta posiada klucz, ktory jest argumentem wektora, w moim przypadku oraz
 * wartosc klucza, czyli jaka wartosc znajduje sie pod kluczem.
 * W tym pliku stworzone sa dwie klasy. Klasa glowna Tab_Asocjacyjna korzysta z
 * malej klasy Liczby, ktora jest pomocnicza i rezprezentujaca elemnty.
 */

using namespace std;

/*!
 * \brief
 * Klasa ta jest wykorzystana do stworzenia szablonu, czyli aby wartoscia moglabyc dowolna
 * zmienna wykorzystana przez uzytkownika.
 * Docelowo kluczem jest string czyli wartosc indeksujaca tablice.
 * W klasie tej stworzone sa konstruktory i referencje do modyfikowania wartosci oraz odczytu.
 */
template < typename Wartosc> class Liczby{
private:
	Wartosc Wart_Klucza;
	string Klucz;
public:
	/*!
	 * \brief Konstrukor inicjujacy wartosci
	 */
	Liczby() : Klucz(Klucz), Wart_Klucza(Wart_Klucza){
	}
	/*!
	 * \brief Konstrukor inicjujacy wartosci
	 */
	Liczby(const string & Klucz) : Klucz(Klucz){
	}
	/*!
	 * \brief Konstrukor inicjujacy wartosci
	 */
	Liczby(const string & Klucz, const Wartosc & Wart_Klucza) : Klucz(Klucz), Wart_Klucza(Wart_Klucza){
	}
	/*!
	 * \brief Referencja do pola Klucz, dzieki niej mozemy modyfikowac zmienna.
	 * \return Klucz - string, ktory jest indeksem tablicy
	 */
	string & Pierwszy_Elem(){
		return Klucz;
	}
	/*!
	 * \brief Funkcja umozliwiajaca odczytanie wartosci znajdujacej sie pod zmienna Klucz.
	 * \return Klucz - string, ktory jest indeksem tablicy
	 */
	const string & Pierwszy_Elem() const{
		return Klucz;
	}
	/*!
	 * \brief Referencja do pola Wart_Klucza, dzieki niej mozemy modyfikowac zmienna.
	 * \return Wart_Klucza - zmienna typu Wartosc(nasz szablon), ktora jest wartosc Klucza.
	 */
	Wartosc & Drugi_Elem(){
		return Wart_Klucza;
	}
	/*!
	 * \brief Funkcja umozliwiajaca odczytanie wartosci znajdujacej sie pod zmienna Wart_Klucza.
	 * \return Wart_Klucza - zmienna typu Wartosc(nasz szablon), ktora jest wartosc Klucza.
	 */
	const Wartosc & Drugi_Elem() const{
		return Wart_Klucza;
	}

};
/*!
 * \brief Przeciazenie operatora <
 * Przeciazenie porownujace klucze, czyli stringi. Przeciazenie to wykorzystane jest przy
 * sortowaniu uzytym przy kazdym dodawaniu elementow do tablicy
 * \param[in] pierwszy - element porownywany nalzezacy do klasy Liczby o szablonie Wartosc
 * \param[in] drugi - element porownywany nalzezacy do klasy Liczby o szablonie Wartosc
 * \return Funkcja zwraca true jezeli pierwszy porownywany element jest mniejszy od drugiego
 * w przeciwnym wypadku false.
 */
template <typename Wartosc>
bool operator < (Liczby<Wartosc> pierwszy,Liczby<Wartosc> drugi)
{
	return pierwszy.Pierwszy_Elem() < drugi.Pierwszy_Elem();
}

/*!
 * \brief
 * Klasa Tab_Asocjacyjna, to w niej tworzony jest wektor, w ktorym przechowywane sa wszystkie
 * elementy. Indeksami tego wektora sa Klucze (string), ktorym odpowiadaja wartosci
 * w zaleznosci jaka uzytkownik zdefiniuje zmienna. Znajduja sie tez rowniez rozne funkcje(metody),
 * ktore moga zostac uzyte przy wykorzystywaniu tablicy asocjacyjnej.
 */

template < typename Wartosc>
class Tab_Asocjacyjna{
private:
	/*!
	 * \brief Inicjowany jest wektor, ktorego indeksem sa stringi natomiast wartosciami klucza
	 * sa zmienne zdefiniowane przezsoobe wykorzystujaca tablice asocjacyjna.
	 */
	vector<Liczby<Wartosc > > Tablica;
	/*!
	 * Zmienna zwraca liczbe elementow znajdujacych sie tablicy asocjacyjnej.
	 */
	unsigned int LiczbaElementow;
public:
	/*!
	 * \brief
	 * Konstruktor Tab_Asocjacyjna, w kotrym definiowana jest liczba elementow
	 * znjadujacych sie w tablicy przy inicjacjowaniu, a wiec wartosc ta wynosi 0.
	 */
	Tab_Asocjacyjna()
	{
		LiczbaElementow=0;
	}
	/*!
	 * \brief Funkcja dodajaca element do tablicy
	 * Funkcja dodaje kolejne elementy do tablicy asocjacyjnej badz zmienia wartosci
	 * juz istniejcych elementow, jezeli takie istnieja w niej.
	 * \param[in] Pierwszy_Elem - jest to Klucz czyli indeks tablicy
	 * \param[in] Drugi_Elem - zmienna ta jest wartosc klucza, moze przyjmowac rozne typy
	 * \return(brak)
	 */
	void dodaj(string Pierwszy_Elem, Wartosc Drugi_Elem);
	/*!
	 * \brief Funkcja pobieraca elemnt z tablicy.
	 * Funkcja pobiera wartosc, ktora znajduje sie pod wskazanym kluczem.
	 * \param[in] Pierwszy_Elem - jest to Klucz wektora, czyli indeks tablicy
	 * \return Funkcja zwraca wartosc jaka znajduje sie pod wskazanym kluczem,
	 * ktora przyjmuje typ zmiennej w zaleznosci od wykorzystania i zdefiniowania przez uzytkownika.
	 */
	Wartosc pobierz(string Pierwszy_Elem);
	/*!
	 * \brief Usuwanie wskazanego elementu
	 * Funkcja usuwa element o wskazanym kluczu, czyli indeksie tablicy asocjacyjnej.
	 * \param[in] Pierwszy_Elem - jest to Klucz wektora, czyli indeks tablicy
	 * \return (brak)
	 */
	void usun(string Pierwszy_Elem);
	/*!
	 * \brief Znajdowanie Klucza o podanej jego wartosci.
	 * Funkcja znajduje Klucz, ktorego elementem jest szukana wartosc. Funkcja dziala
	 * podobnie jak funkcja pobierz, tylko zamiast wartosci znajduje klucz.
	 * \param[in] Drugi_Elem - do tej wartosci, ktora przyjmuje dolowny typ poszukujemy Klucz
	 * \return Funkcja zwraca nazwe klucza, czyli indeks wektora.
	 */
	string znajdz(Wartosc Drugi_Elem);
	/*!
	 * \brief Sprawdzanie rozmiaru tablicy.
	 * \return Funkcja zwraca liczbe calkowita, ktora jest rozmiarem calej tablicy asocjacyjnej
	 */
	int rozmiar();
	/*!
	 * \brief Funkcja sprawdzajaca czy tablica jest pusta.
	 * \return Jezeli funkcja jest pusta funkcja zwraca nam true w przciwnym wypadku flase.
	 */
	bool Czy_Pusta();
	/*!
	 * \brief Przeciazenie operatora []
	 * Przeciazenie operatora za pomoca ktorego mozemy odwolywac sie do wskazanego elementu tablicy
	 * asocjacyjnej. Wartosc wektora przy uzyciu przeciazenia przyjmuje nam typ Wartosc, ktory uzytkownik definiuje.
	 * \param[in] Pierwszy_Elem - jest to klucz naszej tablicy, czyli string. To dzieki niemu mamy dostep do wartosci klucza.
	 * \return Przeciazenie zwraca wartosc do elemntu znajdujacego sie o poadanym kluczu.
	 */
	Wartosc & operator [] (string Pierwszy_Elem);

};

template <typename Wartosc>
Wartosc & Tab_Asocjacyjna<Wartosc>::operator [] (string Pierwszy_Elem)
{
	if(Tablica.size()==0)
	{
		cerr << "Brak elementu do zdjecia" << endl;
	}
	else
	{
		int start=0;
		int end=Tablica.size()-1;
		int half=end/2;
		do{
		if(Tablica[half].Pierwszy_Elem()==Pierwszy_Elem)
		{
			return (Tablica[half].Drugi_Elem());
		}
		else
		{
			if(Tablica[half].Pierwszy_Elem()>Pierwszy_Elem)
			{
				end=half;
				half=(end-start)/2;
			}
			else if (Tablica[half].Pierwszy_Elem()<Pierwszy_Elem)
			{
				start=half;
				half=(end+1-start)/2 + start;
			}
		}}while(end>start);
	}
}

template <typename Wartosc>
int Tab_Asocjacyjna<Wartosc>::rozmiar()
{
	return Tablica.size();
}

template <typename Wartosc>
bool Tab_Asocjacyjna<Wartosc>::Czy_Pusta()
{
	if(LiczbaElementow==0)
		return true;
	else
		return false;
}
template <typename Wartosc>
void Tab_Asocjacyjna<Wartosc>::dodaj(string Pierwszy_Elem, Wartosc Drugi_Elem)
{
	Liczby<Wartosc> elementy (Pierwszy_Elem, Drugi_Elem);
	typename vector< Liczby<Wartosc> >::iterator iter_p, iter_k;
	bool flaga=false;
	iter_p = Tablica.begin();
	iter_k = Tablica.end();
	iter_k--;
	int spr=Tablica.size();
	if(spr>0)
	{

		do
		{
			if(elementy.Pierwszy_Elem()==iter_p->Pierwszy_Elem())
			{
				iter_p->Drugi_Elem()=Drugi_Elem;
				flaga=true;
			}

		}while(iter_p++ != iter_k);

		if(flaga==false){
		Tablica.push_back(elementy);
		sort(Tablica.begin(), Tablica.end());
		LiczbaElementow++;}

	}
	else
	{
		Tablica.push_back(elementy);
		LiczbaElementow++;
	}
}


template <typename Wartosc>
Wartosc Tab_Asocjacyjna<Wartosc>::pobierz(string Pierwszy_Elem)
{
	if(Tablica.size()==0)
	{
		cerr << "Brak elementu do zdjecia" << endl;
	}
	else
	{
		int start=0;
		int end=Tablica.size()-1;
		int half=end/2;
		do{
		if(Tablica[half].Pierwszy_Elem()==Pierwszy_Elem)
		{
			return (Tablica[half].Drugi_Elem());
		}
		else
		{
			if(Tablica[half].Pierwszy_Elem()>Pierwszy_Elem)
			{
				end=half;
				half=(end-start)/2;
			}
			else if (Tablica[half].Pierwszy_Elem()<Pierwszy_Elem)
			{
				start=half;
				half=(end+1-start)/2 + start;
			}
		}}while(end>start);
	}
}

template <typename Wartosc>
void Tab_Asocjacyjna<Wartosc>::usun(string Pierwszy_Elem)
{
	typename vector< Liczby<Wartosc> >::iterator iter_p, iter_k;
	iter_p = Tablica.begin();
	iter_k = Tablica.end();
	iter_k--;
	while(iter_p!=iter_k)
	{
		if(iter_p->Pierwszy_Elem()==Pierwszy_Elem)
		{
			Tablica.erase(iter_p);
			LiczbaElementow--;
		}
		iter_p++;
	}
}

template <typename Wartosc>
string Tab_Asocjacyjna<Wartosc>::znajdz(Wartosc Drugi_Elem)
{
	typename vector< Liczby<Wartosc> >::iterator iter_p, iter_k;
	iter_p = Tablica.begin();
	iter_k = Tablica.end();
	while(iter_p!=iter_k)
	{
		if(iter_p->Drugi_Elem()==Drugi_Elem)
		{
			return iter_p->Pierwszy_Elem();
		}
		iter_p++;
	}
}

#endif /* TASOCJACYJNA_HH_ */
