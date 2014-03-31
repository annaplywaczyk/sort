/*
 * dane.cpp
 *
 *  Created on: 8 mar 2014
 *      Author: Ania
 */
#include "dane.hh"
#include <fstream>

using namespace std;

void dane::wczytaj(string nazwa)
{
	ifstream plik(nazwa.c_str());
	int liczba_elementow;
	if (!plik)
	{
		cerr << "Brak pliku!" << endl;
	}
	plik >> liczba_elementow;
	int liczba;
	for(int i=1; plik >> liczba; i++)
	{
		wektor.push_back(liczba);
	}
	plik.close();
}

void dane::wypisz()
{
	for(unsigned int i=0; i<wektor.size(); i++)
	{
		cout <<"W["<<i<<"]: "<< wektor[i]<< endl;
	}
}

void dane::zamien_element(int i, int j)
{
	if(i>=liczba_el || j>=liczba_el) {
		cerr <<"B³¹d, wektor nie ma tylu elementow" <<endl;
	}
	else{
		int nowy=wektor[i];
		wektor[i]=wektor[j];
		wektor[j]=nowy;
	}
}

void dane::dodaj_element(int e)
{
	wektor.push_back(e);
	liczba_el++;
}

void dane::odwroc_element()
{
	vector<int>zamiana;
	unsigned int kolejnosc = wektor.size();
	for (unsigned int i=0; i<wektor.size(); i++)
	{
		zamiana.push_back(wektor[kolejnosc-1-i]);
	}
	wektor=zamiana;
}

void dane::dodaj_elementy(dane wektor2)
{
	for(unsigned int i=0; i<wektor2.size(); i++)
	{
		wektor.push_back(wektor2[i]);
	}
}

int & dane::operator [](int indeks)
{
	return wektor[indeks];
}

dane & dane::operator + (dane wektor2)
{
	dodaj_elementy(wektor2);
	return *this;
}

dane & dane::operator = (dane wektor2)
{
	wektor=wektor2.wnetrze();
	liczba_el=wektor2.size();
	return *this;

}

bool dane::operator == (dane wektor2)
{
	if(wektor.size()==wektor2.size())
	{
		for(unsigned int i=0; i<wektor.size(); i++)
		{
			if(wektor[i]!=wektor2[i])
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
return true;
}
