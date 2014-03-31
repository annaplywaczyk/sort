#include "stos.hh"

using namespace std;

void stos::powieksz()
{
	int *nowa;
	int temp;
	switch(powiekszenie){
	case 0:
		temp=2*rozmiar_tab;
		nowa= new int[temp];
		break;
	case 1:
		temp=1+rozmiar_tab;
		nowa= new int[temp];
		break;
	}

	for (int i=0; i<rozmiar_tab; i++)
	{
		nowa[i]=tablica[i];
	}
	delete [] tablica;
	tablica = nowa;
	rozmiar_tab=temp;
}

void stos::pomniejsz()
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

void stos::push(int el_dodawany){
	if (liczba_elementow==rozmiar_tab)
	{
		powieksz();
	}
	tablica[liczba_elementow++]=el_dodawany;
}


void stos::pop(int *a){
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

bool stos::isempty(){
	return liczba_elementow==0;
}

int stos::size(){
	return liczba_elementow;
}
