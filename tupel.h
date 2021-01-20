#pragma once
/*
* tupel.h - GrosseUebung Test 10
* Autor: H.Loose
* 21.10.2020
* 11.11.2020
* 18.11.2020
* 02.12.2020
*/
#include <iostream> //STL
using namespace std; 
#include "print_interface.h"

// Zahlentupel
struct Tupel : public PrintInterface
{ 
//public:
	int a, b; 
	Tupel(int a = 1, int b = 1)     // Tupel(), Tupel(2), Tupel(2,2)
	{
		this->a = a;
		this->b = b;
	}
	Tupel(const Tupel& p) { if (this != &p) *this = p; }
	virtual ~Tupel() {}

	virtual Tupel* clone() const;
	void print() const;
	virtual void vprint() const;
	
	const Tupel& operator = (const Tupel& p);
	friend bool operator == (const Tupel& p1, const Tupel& p2);
	friend bool operator != (const Tupel& p1, const Tupel& p2);
	friend ostream& operator << (ostream& s, const Tupel& p);
	friend istream& operator >> (istream& s, Tupel& p);
};

