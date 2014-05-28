/*
 * graf.cpp
 *
 *  Created on: 15 maj 2014
 *      Author: Ania
 */
#include "graf.hh"
#include <queue>
#include <stack>
#include <cmath>
/*
void Graf::generuj_macierz(int ilosc, int gestosc)
{
	V = ilosc;
	Krawedz pomoc;
	int liczba;
	Tablica = new int*[ilosc];
	for (int i = 0; i < ilosc; i++)
	{
		Tablica[i] = new int[ilosc];
	}

	for (int i = 0; i < ilosc; i++)
	{
		for (int j = 0; j < i; j++)
		{
			int losowa = rand() % 100; //losowanie liczby pseudolosowej
			if (losowa < gestosc) //(1)
			{
				liczba = rand() % (ilosc * ilosc) + 1;
				Tablica[i][j] = Tablica[j][i] = liczba;//(2)
				pomoc.poczatek = i;
				pomoc.koniec = j;
				pomoc.w = liczba;
				lista_krawedzi.push_back(pomoc);
			}
			else
			{
				Tablica[i][j] = Tablica[j][i] = 0;//(3)
			}
		}
	}

	for (int i = 0; i < ilosc; i++)
	{
		Tablica[i][i] = 0;
	}
}
*/
/*
bool Graf::czy_spojny()
{
	int licznik = 0;
	int pomoc;

	bool *wizyta = new bool[V];
	for (int i = 0; i < V; i++)
		wizyta[i] = false;

	pomoc = 0;
	stos.push(pomoc);

	while (!stos.empty())
	{
		pomoc = stos.top();
		stos.pop();
		if (wizyta[pomoc] != true)
		{
			wizyta[pomoc] = true;
			for (int j = 0; j < V; j++)
			{
				int druga;
				if (Tablica[pomoc][j] != 0)
				{
					druga = j;
					if (wizyta[druga] != true)
						stos.push(druga);
				}

			}
			licznik++;
		}

	}
	if (licznik == V)
	{
		cout << endl << "GRAF JEST SPOJNY! " << endl;
		return true;
	}
	else
	{
		cout << endl << "GRAF NIE JEST SPOJNY! " << endl;
		return false;
	}
	delete[] wizyta;
}
*/

double wezel::heurystyka(wezel cel)
{
	int a= cel.x-x;
	int b= cel.y-y;
	double wynik= sqrt(a*a + b*b);
	return wynik;
}

void Graf::wczytaj_graf(std::string nazwa_pliku){
	ifstream plik;

		plik.open(nazwa_pliku.c_str());
		plik >> V;  // liczba wierzcholkow
		plik >> E;  // liczba krawedzi

		Tablica = new int*[V];
		wierzcholek = new wezel[V];


		for (int i = 0; i < V; i++)
		{
			Tablica[i] = new int[V];
		}

		for (int i=0; i<V; i++){
			plik >> wierzcholek[i].x >> wierzcholek[i].y;
		}
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				plik >>Tablica[i][j];
			}
		}
		for(int k=0; k<V; k++){
			wierzcholek[k].ktory=k;
		}

		plik.close();
}

void Graf::wyswietl()
{
	for (int i = 0; i < V; i++)
	{
		cout << endl << setw(3) << i << ":";
		for (int j = 0; j < V; j++)
		{
			cout << setw(3) << Tablica[i][j];
		}
	}
	cout << endl;
}

int Graf::BFS(int koniec, int pocz)
{
	int licznik=0;
	int kolor[V], rodzic[V];
	queue<wezel> kolejka;

	for (int i=0; i<V; i++)
	{
		kolor[i]=-1; //bia³y - nieodwiedzony
		wierzcholek[i].koszt=-1; //pusty
		rodzic[i]=-1; //brak rodzica
	}

	kolor[pocz]=0; //istnieje taki wierzcho³ek
	wierzcholek[pocz].koszt=0;
	rodzic[pocz]=-1; //wierzcho³ek od którego zaczynamy nie posiada rodzica
	kolejka.push(wierzcholek[pocz]);
	while(!kolejka.empty())
	{
		wezel temp=kolejka.front();
		int u = temp.ktory;
		kolejka.pop();
		for(int v=0; v<V; v++)
		{
			if(Tablica[u][v]>0)
			{
				licznik++;
				if(kolor[v]==-1)
				{
					kolor[v]=0;
					wierzcholek[v].koszt=wierzcholek[u].koszt+Tablica[u][v];
					rodzic[v]=u;
					kolejka.push(wierzcholek[v]);
				}
				if(v==koniec)
				{
					cout << "Droga  =  "<< koniec;
					for(int i=koniec; rodzic[i]!=-1; i=rodzic[i])
					{
						cout <<"  " << rodzic[i] ;
					}
					cout << endl << "Odleglosc  " << wierzcholek[v].koszt << endl;
					cout<<"Liczba odwiedzonych  "<<licznik<<endl;
					return 0;
				}
			}
		}
		kolor[u]=1;
	}
}

int Graf::DFS(int koniec, int pocz)
{
	int kolor[V], odleglosc[V], rodzic[V];
	stack<wezel> kolejka;
	int licznik=0;
	for (int i=0; i<V; i++)
	{
		kolor[i]=-1; //bia³y - nieodwiedzony
		odleglosc[i]=-1; //pusty
		rodzic[i]=-1; //brak rodzica
	}

	kolor[pocz]=0; //istnieje taki wierzcho³ek
	wierzcholek[pocz].koszt=0;
	rodzic[pocz]=-1; //wierzcho³ek od którego zaczynamy nie posiada rodzica
	kolejka.push(wierzcholek[pocz]);
	while(!kolejka.empty())
	{
		wezel temp=kolejka.top();
		int u = temp.ktory;
		kolejka.pop();
		for(int v=0; v<V; v++)
		{
			if(Tablica[u][v]>0)
			{
				licznik++;
				if(kolor[v]==-1)
				{
					kolor[v]=0;
					wierzcholek[v].koszt=wierzcholek[u].koszt+Tablica[u][v];
					rodzic[v]=u;
					kolejka.push(wierzcholek[v]);
				}
				if(v==koniec)
				{
					cout << "Droga  =  "<< koniec;
					for(int i=koniec; rodzic[i]!=-1; i=rodzic[i])
					{
						cout <<"  " << rodzic[i] ;
					}
					cout << endl << "Odleglosc  " << wierzcholek[v].koszt << endl;
					cout << "Liczba odwiedzonych  " << licznik << endl;
					return 0;
				}
			}
		}
	}
}

int Graf::a_star(int koniec, int pocz)
{
	bool odwiedzone[V], czy_w_kolejce[V];
	int rodzic[V];
	bool czy_dodajemy=false;
	int licznik=0;
	priority_queue<wezel, vector<wezel>, porownanie> nieodwiedzone;

	for(int i=0; i<V; i++)
	{
		odwiedzone[i]=false;
		czy_w_kolejce[i]=false;
		rodzic[i]=-1;
	}
	nieodwiedzone.push(wierzcholek[pocz]);
	czy_w_kolejce[pocz]=true;
	wierzcholek[pocz].start_akt=0;
	while(!nieodwiedzone.empty())
	{
		wezel najnizszy=nieodwiedzone.top();
		nieodwiedzone.pop();
		int x= najnizszy.ktory;
		czy_w_kolejce[x]=false;
		if(x==koniec)
		{
			cout << "Droga  =  "<< koniec;
							for(int i=koniec; rodzic[i]!=-1; i=rodzic[i])
							{
								cout <<"  " << rodzic[i] ;
							}
							cout << endl << "Odleglosc  " << wierzcholek[x].koszt << endl;
							cout << "Liczba odwiedzonych  " << licznik << endl;
							return 0;
		}
		odwiedzone[x]=true;
		for(int i=0; i<V; i++)
		{
			if(Tablica[x][i]>0 and odwiedzone[i]==false)
			{
				licznik++;
				int koszt_i=wierzcholek[x].start_akt + Tablica[x][i];
				bool czy_lepszy = false;
				if(czy_w_kolejce[i]==false)
				{
					czy_dodajemy=true;

					wierzcholek[i].akt_cel=wierzcholek[i].heurystyka(wierzcholek[koniec]);
					czy_lepszy=true;
				}
				else if (koszt_i < wierzcholek[i].start_akt)
				{
					czy_lepszy=true;
				}
				if(czy_lepszy==true)
				{
					rodzic[i]=x;
					wierzcholek[i].start_akt=koszt_i;
					wierzcholek[i].koszt=wierzcholek[i].start_akt+wierzcholek[i].akt_cel;
				}
				if(czy_dodajemy==true){
					nieodwiedzone.push(wierzcholek[i]);
					czy_dodajemy=false;
					czy_w_kolejce[i]=true;

				}
			}
		}
	}
	return 0;
}

Graf::~Graf()
{
	for (int i = 0; i < V; i++)
	{
		delete[] Tablica[i];
	}
	delete[] Tablica;
}
