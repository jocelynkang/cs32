#include "newSet.h"
#include <iostream>
#include <cassert>	// Use assert for testing.
using namespace std;

void test0() 
{
	Set a(2);
	a.insert("hello");
	a.insert("hello");
	a.insert("world");
	a.insert("world");
	a.insert("insert");
	a.insert("insert");
	cout << a.size() << endl;
	a.dump();
	Set b(a);
	cout << b.size() << endl;
	b.dump();
	Set c(10);
	a = a;
	c = b = a;
	cout << c.size() << endl;
	c.dump();
}

void test1() 
{
	Set a(1000);
	Set b(5);
	ItemType v[6] = {"abc", "bcd", "cde", "cbd", "bda", "dab"};
	
	for (int k = 0; k < 5; ++k)
		assert(b.insert(v[k]));

		// Falure to insert excess item
	assert(!b.insert(v[5]));

		// When swap two Sets, their contents are swapped, their capacities are swapped as well.
 	a.insert("hello");
	a.insert("world");
	a.swap(b);
	assert(!a.insert(v[5])  &&  b.insert(v[5]));
	a.dump();
	b.dump();	
}
