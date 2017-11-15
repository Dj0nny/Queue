#ifndef QUEUE_H
#define QUEUE_H

template <class T> 
class QueueItem {
	public:
		QueueItem(const T& val) : info(val), next(0) {}
		T info;
		QueueItem* next;
};

template <class T>
class Queue {
	public:
		Queue(): first(0), last(0) {}
		bool is_empty() const;
		void add(const T&);
		T remove();
		~Queue();
	private:
		QueueItem<T>* first;
		QueueItem<T>* last;
};


template <class T>
bool Queue<T>::is_empty() const { return (first == 0); }

template <class T>
void Queue<T>::add(const T& val) {
	QueueItem<T>* p = new QueueItem<T>(val);
	if(is_empty())
		first = last = p;
	else {
		last->next = p;
		last = p;
	}	
}

#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
T Queue<T>::remove() {
	if(is_empty()) {
		cerr << "remove() on empty queue" << endl;
		exit(1); 
	}
	QueueItem<T>* p = first;
	first = first->next;
	T aux = p->info;
	delete p;
	return aux;
}

template <class T>
Queue<T>::~Queue() {
	while(!is_empty()) remove();
}
#endif
