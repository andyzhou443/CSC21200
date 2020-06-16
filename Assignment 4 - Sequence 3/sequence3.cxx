// PROVIDED BY: Andy Zhou(your name and email address)
// azhou002@citymail.cuny.edu
// FILE: sequence3.h
// CLASS PROVIDED: sequence (a container class for a sequence of items,
// where each sequence may have a designated item called the current item)
#include "sequence3.h"
#include <assert.h>
#include <cstdlib>
using namespace std;
namespace main_savitch_5
{
	/*
	Invariants:
	node* head_ptr; //pointer for first node
	node* tail_ptr; //pointer for last node
	node* cursor; //pointer for current node
	node* precursor; //pointer for node before current node
	size_type many_nodes; //for total number of nodes
	*/

	sequence::sequence() // CONSTRUCTOR for the sequence class:
	{
		// Big-O: O(1)
		head_ptr == NULL;
		tail_ptr == NULL;
		precursor == NULL;
		cursor == NULL;
		many_nodes == 0;
	}
	//need a copy constructor
	sequence::sequence(const sequence& source) 
	{
		// Big-O: O(n)
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		many_nodes = source.many_nodes;
		cursor = source.cursor;
		precursor = source.precursor;
	}

	sequence::~sequence()
	{
		// Big-O: O(n)
		list_clear(head_ptr);
	}

	// MODIFICATION MEMBER FUNCTIONS for the sequence class:
	void sequence::start()
	{
		// Big-O: O(1)
		cursor = head_ptr;
		precursor = NULL;
	}

	void sequence::advance()
	{
		// Big-O: O(1)
		assert(is_item() == true);
		precursor = cursor;
		cursor = cursor->link();
	}

	void sequence::insert(const value_type& entry)
	{
		// Big-O: O(1)
		if (is_item() == false) //no item
		{
			list_head_insert(head_ptr, entry);
			cursor = head_ptr;
			many_nodes++;
		}
		else
		{
			if (head_ptr == cursor)
			{
				list_head_insert(head_ptr, entry);
				cursor = head_ptr;
				many_nodes++;
			}
			else
			{
				list_insert(precursor, entry);
				cursor = precursor->link();
				many_nodes++;
			}
		}
	}

	void sequence::attach(const value_type& entry) //may be wrong
	{
		// Big-O: O(1)
		if (is_item() == true) //if there is item
		{
			list_insert(cursor, entry);
			precursor = cursor;
			cursor = cursor->link();
		}
		else
		{
			if (head_ptr == NULL)
			{
				list_head_insert(head_ptr, entry);
				cursor = head_ptr;
				precursor = NULL;
			}
			else
			{
				cursor = list_locate(head_ptr, list_length(head_ptr));
				list_insert(cursor, entry);
				cursor = precursor->link();
			}
		}
		many_nodes++;
	}

	void sequence::remove_current() 
	{
		// Big-O: O(1)
		assert(is_item() == true);
		if (cursor == head_ptr)
		{
			cursor = cursor->link();
			list_remove(precursor);
		}
		else {
			list_head_remove(head_ptr);
			cursor = head_ptr;
		}
		many_nodes--;
	}

	void sequence::operator =(const sequence& source)
	{
		if (this == &source) {
			return;
		}
		// incomplete did not realized I needed to do this
	}

	size_t sequence::size() const
	{
		// Big-O: O(1)
		return many_nodes;
	}

	bool sequence::is_item() const
	{
		// Big-O: O(1)
		return (cursor != NULL && many_nodes > 0);
	}

	sequence::value_type sequence::current() const
	{
		// Big-O: O(1)
		assert(is_item() == true);
		return cursor->data();
	}
}