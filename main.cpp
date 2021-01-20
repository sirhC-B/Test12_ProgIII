/* main.cpp
Testat 12
* Klassendefinitionen
* Autor: Harald Loose
* 28.11.2013
* 09.12.2020
* 13.01.2021
*/

#include <iostream>
#include <string>
using namespace std;

#include "tupel.h"
#include "queue.h"


int main(int argc, char* argv[])
{
	cout << "\n*******************************************";
	cout << "\nTESTAT 12: C. Boesener, 13.01.2021";
	cout << "\n*******************************************\n";

	//PrintInterface pi;
	Tupel t1, t2(333, 222), t3(-100, -200);
	cout << "t1:" << t1;
	cout << "t2:" << t2;
	cout << "t3:" << t3;

	Queue<Tupel, 3> stTupel(2);
	try {
		stTupel.enqueue(t1);
		stTupel += t2;
		cout << stTupel;
		stTupel.enqueue(t3);
	}
	catch (QueueException e) { cout << e.getMessage() << endl; }
	cout << "stTupel " << stTupel;

	Queue<Tupel, 3> stTupel2;
	stTupel2 = stTupel;
	cout << "stTupel2 " << stTupel2;

	try {
		Queue<Tupel, 3> stTupel3(stTupel);
		cout << "stTupel3 " << stTupel3;
		cout << "stTupel3[1]" << stTupel3[1] << endl;
	}
	catch (QueueException e) { cout << e.getMessage() << endl; }

	try {
		stTupel -= t1;
		cout << "dequeue:" << stTupel << endl;
		cout << t1 << "       " << stTupel;
		cout << "dequeue:" << stTupel.dequeue() << endl;
		cout << "dequeue:" << stTupel.dequeue() << endl;
		cout << "dequeue:" << stTupel.dequeue() << endl;
	}
	catch (QueueException e) { cout << e.getMessage() << endl; }


	printf("\n");
	//system("pause");
	return 0;
}
