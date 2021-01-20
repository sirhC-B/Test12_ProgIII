/*
* queue.cpp - Test12
* Author: C.Boesener - Semester III
* 13.01.2021
*/

#include<iostream>
#include<string>
using namespace std;



	template <class T, unsigned int N>
	Queue<T, N>::Queue(const Queue<T, N>& q)
	{
		data = NULL;
		if (this != &q) *this = q;
	}

	template <class T, unsigned int N>
	ostream& operator << (ostream& s, const Queue<T, N>& p)
	{
		s << p.getSize() << " ";
		for (int i = 0; i < p.getSize(); i++)
			s << p.data[i] << " ";
		return s << endl;
	}

