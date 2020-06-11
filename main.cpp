#include "tree.h"
#include "graph.h"
#include "stack.h"
#include "queue.h"

void graphinit(graph &a){
	
	a.set(1,2);
	a.set(1,4);
	a.set(2,3);
	a.set(2,5);
	a.set(2,13);
	a.set(2,15);
	a.set(3,15);
	a.set(4,5);
	a.set(4,13);
	a.set(5,11);
	a.set(6,7);
	a.set(6,15);
	a.set(7,8);
	a.set(7,9);
	a.set(7,15);
	a.set(9,10);
	a.set(10,11);
	a.set(10,12);
	a.set(11,12);
	a.set(11,14);
	a.set(1,5);
	a.set(1,3);
	a.set(2,6);
	a.set(2,11);
	a.set(3,4);
	a.set(4,10);
	a.set(5,10);
	a.set(6,10);
	a.set(7,10);
	a.set(8,10);
	a.set(11,13);
	a.set(12,13);

}			

void DFS(graph &a, long source, long tarjet, stack &stck){
	
	btree M(a.order());
	
	stck.push(source);
	
	while(!stck.empty()){
		
		long u = stck.top(), v = 0;
		
		M.insert(u);	
		for(long w = 1; w <= a.order(); w++) if(a.edge(u, w) and !M.search(w)){	
			v = w;
			w = a.order() + 1;	
		} 
	
		if(v != 0) {
				
			stck.push(v);
			if(v == tarjet) return;
		}
		else stck.pop();
		
	}
}

bool BFS(graph &a, long source, long tarjet){
	
	btree M(a.order());
	queue qu(a.order());
	
	qu.enqueue(source);
	M.insert(source);
	
	while(!qu.empty()){
		
		long u = qu.dequeue();
	
		for(long v = 1; v <= a.order(); v++) if(a.edge(u, v) and !M.search(v)){
				
			if(v == tarjet) return true;
			qu.enqueue(v);
			M.insert(v);
		}		
	}	
	
	return false;
}

void sv(graph &a, long source, long tarjet, stack &stck){
	
	btree M(a.order());
	queue qu(a.order());
	graph E(a.order());
	
	qu.enqueue(source);
	M.insert(source);
	
	while(!qu.empty()){
		
		long u = qu.dequeue();
		
		for(long v = 1; v <= a.order(); v++) if(a.edge(u, v) and !M.search(v)){
				
			E.set(u,v);
			if(v == tarjet) DFS(E, source, tarjet, stck);
			qu.enqueue(v);
			M.insert(v);
		}		
	}
}

int main(){
	
	graph a(15);
	graphinit(a);
	stack stck(15), aux(15);
	a.print();
	
	long source, tarjet;
	
	cout << "from: ";
	cin >> source;
	cout << "to: ";
	cin >> tarjet;
		
	cout << "BFS: ";
	cout << (BFS(a, source, tarjet) ? "yes\n": "no\n"); //breath-first path
	
	cout << "DFS: ";
	DFS(a, source, tarjet, stck); //deep-first path
	while(!stck.empty()) aux.push(stck.pop());
	while(!aux.empty()) cout << aux.pop() << " ";	
	cout << "\n";
	
	cout << "Shortest path: ";
	sv(a, source, tarjet, stck);   //shortest path
	while(!stck.empty()) aux.push(stck.pop());
	while(!aux.empty()) cout << aux.pop() << " ";	
	cout << "\n";
	
	return 0;
}
