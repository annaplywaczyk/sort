/*
 * kolejka.cpp
 *
 *  Created on: 15 mar 2014
 *      Author: Ania
 */

#include "kolejka.hh"

using namespace std;

void kolejkatab::powieksz()
{
	int *nowa;
	int temp;
	temp=2*rozmiar_tab;
	nowa= new int[temp];
	for (int i=0; i<rozmiar_tab; i++)
	{
		nowa[i]=tablica[i];
	}
	delete [] tablica;
	tablica = nowa;
	rozmiar_tab=temp;
}

void kolejkatab::pomniejsz()
{
	int *nowa= new int[rozmiar_tab/4];
	for (int i=0; i<liczba_elementow; i++)
	{
		nowa[i]=tablica[i];
	}
	delete [] tablica;
	tablica = nowa;
	rozmiar_tab=rozmiar_tab/4;
}

void kolejkatab::enqueue(int el_dodawany){
	int *nowa;
	if (liczba_elementow==rozmiar_tab)
	{
		powieksz();
	}
	nowa=new int [rozmiar_tab];
	nowa[0]=el_dodawany;
	for(int i=0; i<liczba_elementow; i++)
	{
		int j=i+1;
		nowa[j] = tablica[i];
	}
	delete[] tablica;
	tablica = nowa;
	liczba_elementow++;

}

void kolejkatab::dequeue(int *a){
	if(!isempty()){
		if(liczba_elementow<=rozmiar_tab/4)
		{
			pomniejsz();
		}
		*a=tablica[liczba_elementow-1];
		liczba_elementow--;
	}
	else
	{
		cout << "Stos jest pusty!" << endl;
	}
}

bool kolejkatab::isempty(){
	return liczba_elementow==0;
}

int kolejkatab::size(){
	return liczba_elementow;
}



