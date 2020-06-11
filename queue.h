#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cstdlib>

using namespace std;

class queue{	
		class node{ 
		int _data; 
		node *_next;
		
		public:
			node(int x): _data(x), _next(NULL) {} 
												
			int data() {return _data;}			
			node *next(){return _next;}			
			node *next(node *p){return _next = p;}
	};
	
	node *rear; 
	node *starting; 
	int n; //capacidad
	int s; //tamaño
	
	public:
	
	queue(int size): n(size), s(0){rear = NULL, starting = NULL;} 
	~queue(){while(!empty()) dequeue();} 
	
	void enqueue(int); 
	int dequeue(); 
	
	int capacity(){ return n;} 
	int size(){ return s;} 
	
	bool empty(){ return s == 0;}
	bool full(){ return s == n;}
};

#endif
