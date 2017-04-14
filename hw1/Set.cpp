#include "Set.h"
#include <string>
#include <iostream>
using namespace std;
Set::Set()
{
	m_size = 0;
}

bool Set::empty() const
{
	return (m_size == 0) ? true : false;
}

int Set::size() const
{
	return m_size;
}

bool Set::insert(const ItemType& value)
{
	// If the set is already full.
	if (m_size >= DEFAULT_MAX_ITEMS)
		return false;
	// If the set is empty.
	if (m_size == 0 && DEFAULT_MAX_ITEMS > 0) {
		m_items[0] = value;
		m_size++;
		return true;
	}

	// Find a place to insert.
	int left = 0, right = m_size - 1, mid = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		if (m_items[mid] == value) {
			return false;
		} else if (m_items[mid] < value) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	// "idx" is the place to insert
	int idx = (m_items[mid] > value) ? mid : mid + 1;
	// Move every item to right 1 block, start from idx
	for (int i = m_size - 1; i >= idx; --i)
		m_items[i + 1] = m_items[i];
	// Insert
	cout << idx << " " << value << endl;
	m_items[idx] = value;
	m_size++;

	return true;
}

bool Set::erase(const ItemType& value)
{
	// If set is empty.
	if (m_size == 0) 
		return false;

	// Find the item.
	int left = 0, right = m_size - 1, mid = 0;
	bool in = false;
	while (left <= right) {
		mid = (left + right) / 2;
		if (m_items[mid] == value) {
			in = true;
			break;	
		} else if (m_items[mid] < value) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	// If value not in
	if (!in)
		return false;

	// move every item to left 1 block
	for (int i = mid + 1; i < m_size; ++i) {
		m_items[i - 1] = m_items[i];
	}
	m_size--;
	
	return true;
}
