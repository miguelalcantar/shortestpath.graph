#include "tree.h"

bool btree::insert(long x){
	
	if(empty()){
		root = new node(x);
		s++;
	} 
	else{
		
		if(full()){
			cout << "[tree] full\n";
			return false;
		}
		
		node *p = root, *q = NULL;
		while(p and p -> data() != x){
			q = p;
			if(x < p -> data()) p = p -> left();
			else p = p -> right();
		}
		if(!p){
			if(x < q -> data()) q -> left(new node(x));
			else q -> right(new node(x));
			s++;
		}
	}
}

void btree::postorder(node *p){
	if(p){
		postorder(p -> left());
		postorder(p -> right());
		delete p; 
	}
}

bool btree::search(long x){
	
	node *q = (node *) nsearch(x); //se hace casting ya que la funcion nsearch retorna un apuntador de tipo void y hay que convertirlo en el objeto nodo
	
	if(q) return true; 
	
	return false;
}

void* btree::nsearch(long x){
	node *p = root;
	
	while(p and p -> data() != x)
	
		(x < p -> data()) ? p = p -> left() : p = p -> right();
	
	return p;
}
