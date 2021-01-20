#pragma once
/*
* tupel.cpp - GrosseUebung Test 10
* Autor: H.Loose
* 21.10.2020
* 11.11.2020
* 18.11.2020
* 02.12.2020
*/

//#include <stdio.h>
//#include <stdlib.h>
#include "tupel.h"

Tupel* Tupel::clone()  const
{
	return (Tupel *) new Tupel(*this);
}

void Tupel::print() const
{
	cout << *this;
}

void Tupel::vprint() const
{
	cout << *this;
}

const Tupel& Tupel::operator = (const Tupel& p)
{
  	this->a = p.a;
	this->b = p.b;
	return *this;
}

bool operator == (const Tupel& p1, const Tupel& p2)
{
	return p1.a == p2.a && p1.b == p2.b;
}

bool operator != (const Tupel& p1, const Tupel& p2)
{
	return !(p1 == p2);
}

// Standarddatenstörme cin, cout, cerr
//Ausgabe auf die Konsole
ostream& operator << (ostream& s, const Tupel& p)
{
	return s << "(" << p.a << "," << p.b << ")" << endl;
}

//Eingabe von der Konsole
istream& operator >> (istream& s, Tupel& p)
{
	cout << "Geben Sie a und b ein: ";
	s >> p.a >> p.b;
	return s;
}

