#include "graph.h"

using namespace std;

graph::graph(long s): n(s), m(0){
	
	long max = n * (n - 1) / 2;
	
	array =  new bool[max];
	
	for(long i = 0; i < max; i++) array[i] = false;
	
	cout << "\n";
}

graph::~graph(){ delete [] array;}

void graph::swap(long &i, long &j){
	long aux = i;
	i = j;
	j = aux;
}

long graph::f(long i, long j){
	
	if(i < j) swap(i,j);
	
	return (i - 1) * (i - 2) / 2 + j - 1;
}

bool graph::set(long i, long j){
	
	if(!full() and i!=j and !array[f(i,j)]){
		
		array[f(i,j)] = true;
		m++;
		return true;	
	} 
	
	cout << "Fail [set].\n";
	return false;
}
void graph::unset(long i, long j){

	if(empty() or i == j){
		
		cout << "Fail unset.\n";
		return;
	}
	
	array[f(i,j)] = 0;
	m--;
}

bool graph::edge(long i, long j){
	
	if(i != j) {
		
		long aux = f(i,j);
		return array[aux];	
	}
		
	return false;
}

void graph::print(){
	
	for(long i = 1; i <= n; i ++){
		
		for(long j = 1; j <= n; j ++)
			
			cout << edge(i,j) << " ";
		
		cout << "\n";
	}
	cout << "\n";
}



