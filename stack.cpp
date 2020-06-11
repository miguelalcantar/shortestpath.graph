#include "stack.h"

void stack::push(long x) { 
	
	if(full()){ 
		 cout << "PUSH stack is full\n";
		 return; 
	}
	
	if(empty()) init = new node(x);
	else{
		node *aux = new node(x); 
		aux -> next(init); 
		init = aux; 
	}
	s++;
}

long stack::pop() { 
		
	if(empty()){ 
		cout << "POP stuck is empty\n";
		return 0; 
	}
	
	long x = init -> data(); 
	node *aux = init; 
	init = init -> next(); 
	delete aux; 
	s--;
	
	return x;
}

long stack::top() { 
	
	if(!empty()) return init -> data();
	
	cout << "TOP stuck is empty\n";
	return 0;	
}
