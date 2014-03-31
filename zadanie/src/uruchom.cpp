/*
 * uruchom.cpp
 *
 *  Created on: 8 mar 2014
 *      Author: Ania
 */
#include "uruchom.hh"
#include <fstream>
#include <cmath>
#include <ctime>


using namespace std;

void zegar::algorytm()
{
	for (unsigned int i=0; i<dane_podstawowe.size(); i++)
	{dane_podstawowe[i]=dane_podstawowe[i]*2;}
}

LARGE_INTEGER zegar::wlaczStoper()
{
 LARGE_INTEGER start;
 DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
 QueryPerformanceCounter(&start);
 SetThreadAffinityMask(GetCurrentThread(), oldmask);
 return start;
}

LARGE_INTEGER zegar::wylaczStoper()
{
 LARGE_INTEGER stop;
 DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
 QueryPerformanceCounter(&stop);
 SetThreadAffinityMask(GetCurrentThread(), oldmask);
 return stop;
}

void zegar::wczytaj(string nazwa)
{
	ifstream plik(nazwa.c_str());
	int liczba_ele;
	if (!plik)
	{
		cerr << "Brak pliku!" << endl;
	}
	plik >> liczba_ele;
	int liczba;
	for(int i=1; plik >> liczba; i++)
	{
		stosik.push(liczba);
	}
	plik.close();
}

dane zegar::scal_sort(dane	tab)
{
	dane lewo, prawo;
	int dl=tab.size();

	if(dl<=1)
		return tab;
	int srednia=dl/2;
	for(int i=0; i<srednia; i++)
	{
		lewo.dodaj_element(tab[i]);

	}
	for(int i=srednia; i<dl; i++)
	{
		prawo.dodaj_element(tab[i]);
	}

	lewo=scal_sort(lewo);
	prawo=scal_sort(prawo);
	dane rezultat = scal(lewo, prawo);
	return rezultat;
}

dane zegar::scal(dane lewo, dane prawo)
{
	dane rezultat;

	int dl1=lewo.size();
	int dl2=prawo.size();
	while(dl1>0  or dl2>0)
	{


		if(dl1>0 and dl2>0)
		{

			if(lewo[0]<=prawo[0])
			{
				rezultat.dodaj_element(lewo[0]);
				lewo.usun();
			}
			else
			{
				rezultat.dodaj_element(prawo[0]);
				prawo.usun();
			}
		}
		else if (dl1>0)
		{
			rezultat.dodaj_element(lewo[0]);
			lewo.usun();
		}
		else if (dl2>0)
		{
			rezultat.dodaj_element(prawo[0]);
			prawo.usun();
		}
		dl1=lewo.size();
		dl2=prawo.size();
	}

	return rezultat;
}


dane zegar::heap(dane tab)
{

	int dl =tab.size()-1;
	int wys= (log(dl)/log(2));

	for(int m=0; m<wys; m++)
	{
		for (int n=1; n<pow(2,wys); n++)
		{
			int l=2*n;
			int k=2*n+1;
			if(l<=dl and k<=dl)
			{
			if(tab[l]>tab[n])
				tab.zamien_element(l,n);
			else if(tab[k]>tab[n])
				tab.zamien_element(k,n);
		}
	}}
	return tab;
}

dane zegar::heap_sort(dane tablica)
{
	dane tab;
	tab.dodaj_element(0);
	tab=tab+tablica;
	dane wynik;
	int dl =tab.size()-1;
	for(int i=0; i<dl; i++)
	{
		tab=heap(tab);
		int dl1 =tab.size()-1;
		wynik.dodaj_element(tab[1]);
		tab.zamien_element(1,dl1);
		tab.usun_ostatni();

	}
	return wynik;
}


void zegar::quick(dane *wektorQ, int a, int b)
{

     int i,j,podz;
     i=a;
     j=b;
     //Przy poczatkowej wersji programu
     //podz=(*wektorQ)[a];
     //Przy 2 czesci porgramu, w gdy losujemy liczbe wedlug ktorej ma byc uzyta mediana

     int w=rand()%b;
     podz=(*wektorQ)[w];
     do
     {
       while(podz>(*wektorQ)[i]) i++;
       while(podz<(*wektorQ)[j]) j--;
       if(i<=j)
       {
         wektorQ->zamien_element(i,j);
         i++;
         j--;
       }
     }
     while(i<=j);

     if(a<j){ quick (wektorQ,a,j);}
     if(i<b){ quick (wektorQ,i,b);}

}
