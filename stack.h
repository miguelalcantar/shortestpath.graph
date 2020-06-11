#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstdlib>

using namespace std;

class stack{
	class node{ 
		long _data; 
		node *_next; 
		
		public:
			node(long x): _data(x), _next(NULL) {} 
												
			long data() {return _data;}			
			node *next(){return _next;}			
			node *next(node *p){return _next = p;} 
	};
	
	node *init; 
	long n; 
	long s; 
	
	public:	
	
	stack(long size): n(size), s(0) {init = NULL;} 
	~stack() {while(!empty()) pop();} 
	
	void push(long); 
	long pop(); 
	long top(); 
	
	long capacity(){ return n;} 
	long size(){ return s;} 
	
	bool empty(){ return s == 0;} 
	bool full(){ return s == n;} 
};

#endif
