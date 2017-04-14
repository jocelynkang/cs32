#ifndef SET_INCLUDED
#define SET_INCLUDED

#include <string>
typedef int ItemType;  // Define ItemType as the synonym for desired data type.
const int DEFAULT_MAX_ITEMS = 200;

#include <iostream>
using namespace std;

class Set 
{
	public:
		Set();
			// Create an empty set.

		bool empty() const;
			// Return true if the set if empty, otherwise false.

		int size() const;
			// Return the number of items in the set.

		bool insert(const ItemType& value);
			// Insert value into the set if it is not already present.  Return
		  // true if the value was actually inserted.  Leave the set unchanged
		 	// and return false if the value was not inserted (perhaps because it
		  // is already in the set or because the set has a fixed capacity and
		  // is full).

		bool erase(const ItemType& value);
		  // Remove the value from the set if present.  Return true if the
		  // value was removed; otherwise, leave the set unchanged and
		  // return false.

    bool contains(const ItemType& value); 
		  // Return true if the value is in the set, otherwise false.

    bool get(int i, ItemType& value) const;
		  // If 0 <= i < size(), copy into value the item in the set that is
		  // greater than exactly i items in the set and return true.  Otherwise,
		  // leave value unchanged and return false.
    
		void swap(Set& other);
		  // Exchange the contents of this set with the other one.

		void dump()
		{
			for (int i = 0; i < m_size; ++i) {
				cout << m_items[i] << endl;
			}	
		}

	private:
		int				m_size;
		ItemType	m_items[DEFAULT_MAX_ITEMS];
};

#endif	// Set.h included