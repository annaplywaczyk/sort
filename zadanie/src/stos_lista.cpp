/*
 * stos_lista.cpp
 *
 *  Created on: 13 mar 2014
 *      Author: Ania
 */
#include "stos_lista.hh"
using namespace std;



void stoslista::push(int el_dodawany){
	lista.push_back(el_dodawany);
}


void stoslista::pop(int *a){
	if(!isempty()){
		list<int>::iterator iter = lista.end();
		*a=*(--iter);
		lista.pop_back();
	}
	else
	{
		cout << "Stos jest pusty!" << endl;
	}
}

bool stoslista::isempty(){
	 return lista.empty();
}

int stoslista::size(){
	return lista.size();
}



