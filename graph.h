#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cstdlib>

class graph{
	
	long n; // order
	long m; // size
	//long max;
	
	bool *array;	
	
	public:
		
	graph(long);
	~graph();
	
	long order() const { return n;}
	long size() const { return m; }
	
	bool set(long, long);
	void unset(long, long);
	
	void swap(long &, long &);
	long f(long, long);
	
	bool edge(long, long);
	
	bool empty() { return m == 0;}
	bool full() { return m == (n * (n - 1) / 2);}	
	
	void print();
};

#endif
