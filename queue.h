#pragma once
/*
* queue.h - Test12
* Author: C.Boesener - Semester III
* 13.01.2021
*/

#include<string>
#include<iostream>
using namespace std;


	template<class T, unsigned int N>
	class Queue;

	class QueueException
	{
	private:
		string message;
	public:
		QueueException(string message = "")
		{
			this->message = message;
		}
		string getMessage() const { return message; }
	};

	template<class T, unsigned int N>
	class Queue
	{
	private:
		T* data;
		
		int first;
		int last;
		int size;

		//hilfsfunktionen
		bool isFull() const { return last == size ? true : false; }
		bool isEmpty() const { return first == size ? true : false; }


	public:
		// constructors
		Queue(int size = N)
		{
			this->first = 0;
			this->last = 0;
			this->size = size > 0 ? size : 3;
			data = new T[size];
		}

		Queue(const Queue& q);

		~Queue()
		{
			if (data) delete[] data;
			first = 0;
			last = 0;
			size = 0;
		}

		// methods

		//int getCount()const { return last; }

		int getSize()const { return size; }

		void enqueue(T& i)
		{
			if (!isFull())
				data[last++] = i;
			else
				throw QueueException("Queue is Full.");
		}

		T& dequeue()
		{
			if (!isEmpty())
				return data[first++];
			else
				throw QueueException("Queue is Empty.");
		}

		// operator 

		const Queue& operator = (const Queue& q)
		{
			if (&q != this)
			{
				size = q.getSize();
				first = q.first;
				last = q.last;
				if (data) delete[] data;
				data = new T[size];
				for (int i = 0; i < q.getSize(); i++)
					data[i] = q.data[i];
			}
			return *this;
		}

		T& operator [ ] (int i)
		{
			return this->data[i];
		}

		Queue& operator += (T& t)
		{
	
			this->enqueue(t);
			return *this;
		}

		Queue& operator -= (T& t)
		{
			this->dequeue();
			return *this;
		}

		friend bool operator == (Queue & q1, Queue & q2)
		{
			if (q1.getSize() != q2.getSize()) return false;
			if (q1.first() != q2.first()) return false;
			if (q1.last() != q2.last()) return false;
			for (int i = 0; i <= q1.last; i++)
			{
				if (q1[i] != q2[i]) return false;
			}
			return true;
		}

		friend bool operator != (Queue& q1, Queue& q2)
		{
			if (q1 == q2) return false;
			return true;

		}

		

		friend ostream& operator << <>(ostream& s, const Queue& q);

	};


#include"queue.cpp"