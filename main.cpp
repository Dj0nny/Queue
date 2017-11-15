#include<iostream>
using namespace std;
#include "Queue.h"

int main() {
	Queue<int>* pi = new Queue<int>;
	int i;
	for(i = 0; i < 10; i++) 
		pi->add(i);
	
	for(i = 0; i < 10; i++)
		cout << pi->remove() << endl;
}
