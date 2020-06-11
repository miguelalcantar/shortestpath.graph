#include "queue.h"

void queue::enqueue(int x){
	
	if(!full()){
	
		if(empty()){ starting = new node(x);} 
		else if(s == 1) {
			
			rear = new node(x);
			starting -> next(rear);
		}else{
			
			node *aux = new node(x);
			rear -> next(aux); 
			rear = aux; 
		}
		s++;
		return;
	}
	cout << "FULLNESS queue\n";
}

int queue::dequeue(){
	if(!empty()) {
		
		int x = starting -> data();
		node *aux = starting;
		starting = starting -> next();
		delete aux;
		s--;
		return x;
	};
	cout << "EMPTYNESS queue\n";
}

