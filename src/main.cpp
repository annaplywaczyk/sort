#include "graf.hh"
#include <queue>

using namespace std;



int main(){


Graf tab1;
cout << endl;
tab1.wczytaj_graf("dane20.txt");
tab1.wyswietl();
tab1.a_star(6,19);


return 0;
}
