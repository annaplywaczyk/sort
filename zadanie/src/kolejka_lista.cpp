/*
 * kolejka_lista.cpp
 *
 *  Created on: 13 mar 2014
 *      Author: Ania
 */
#include "kolejka_lista.hh"

using namespace std;




void kolejkalista::enqueue(int el_dodawany){
	lista.push_back(el_dodawany);
}

void kolejkalista::dequeue(int *a){
	if(!isempty()){
		list<int>::iterator iter = lista.begin();
		*a=*iter;
		lista.pop_front();
	}
	else
	{
		cout << "Kolejka jest pusta!" << endl;
	}
}

bool kolejkalista::isempty(){
	 return lista.empty();
}

int kolejkalista::size(){
	return lista.size();
}




