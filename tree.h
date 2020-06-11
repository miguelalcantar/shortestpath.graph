/*
Miguel Angel Lopez Alcatar
<>
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class btree {
	
	class node{
		long _data;
		node *_left;
		node *_right;
		
		public:
			node(long x): _data(x), _left(NULL), _right(NULL) {}
			
			long data() const { return _data;}
			
			node *right() const { return _right;}
			node *right(node *p) { return _right = p;}
			
			node *left() const { return _left;}
			node *left(node *p){ return _left = p;}
	};
	
	long n;
	long s;
	node *root;
	
	void postorder(node *r);
	void* nsearch(long);
	
	public:
		
		btree(long size): n(size), s(0), root(NULL) {}
		~btree(){postorder(root);}
		
		bool insert(long);
		bool search(long);
		
		long capacity() const {return n;}
		long size() const { return s;}
		
		bool empty() { return s == 0;}
		bool full() { return s == n;}
};

