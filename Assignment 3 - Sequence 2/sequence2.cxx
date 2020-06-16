// PROVIDED BY: Andy Zhou(your name and email address)
// azhou002@citymail.cuny.edu
// FILE: sequence3.h
// CLASS PROVIDED: sequence (a container class for a sequence of items,
// where each sequence may have a designated item called the current item)
#include "sequence2.h"
#include <assert.h>
#include <cstdlib>
namespace main_savitch_4
{
	sequence::sequence(sequence::size_type initial_capacity) 
	{
		CAPACITY = initial_capacity;
		current = 0;
		used = 0;
		myArray = new sequence::value_type[CAPACITY];
	}

	sequence::sequence(const sequence& source) 
	{
		if (this == &source) {
			return;
		}
		CAPACITY = source.CAPACITY;
		used = source.used;
		current = source.current;
		myArray = new sequence::value_type[CAPACITY];
		copy(source.myArray, source.myArray + source.used, myArray);
	}

	sequence::~sequence() 
	{
		delete[] myArray;
	}

	void sequence::start() 
	{
		current = 0;
	}

	void sequence::advance() 
	{
		assert(is_item());
		++current;
	}

	void sequence::insert(const value_type& entry) 
	{
		if (CAPACITY <= used) {
			resize(size() * 1.2)
		}
		if (is_item == false)
		{
			current = 0;
		}
		else
		{

		}
		used++;
	}

	void sequence::attach(const value_type& entry) // NOT DONE YET
	{
		//     Postcondition: A new copy of entry has been inserted in the sequence after
		//     the current item. If there was no current item, then the new entry has 
		//     been attached to the end of the sequence. In either case, the newly
		//     inserted item is now the current item of the sequence.
		if (CAPACITY <= used) {
			resize(size() * 1.2) //incase there isnt enough space
		}
		if (used == 0)
		{
			myArray[current] = entry;
			used++;
		}
		else
		{
			for (unsigned int i = 0; i < used; i++) {

			}
			// need to loop until the end and attach value
			used++
		}
	}

	void sequence::remove_current() 
	{
		assert(is_item() == true)
		for (unsigned int i = current; i < size(); i++) {
			myArray[i - 1] = myArray[i];
		}
		used--;
	}

	void sequence::resize(size_type new_capacity) 
	{
		if (new_capacity > CAPACITY) {
			CAPACITY = new_capacity;
			value_type* newArray = new value_type[CAPACITY];
			copy(myArray, myArray + used, newArray);
			delete[] myArray;
			myArray = newArray;
		}
	}

	void sequence::operator=(const sequence& source)
	{
		if (this == &source) {
			return;
		}
		else
		{

		}
	}

	sequence::size_type sequence::size() const
	{
		return used;
	}

	bool sequence::is_item() const
	{
		return (current_index < used);
	}

	sequence::value_type sequence::current() const
	{
		return array_ptr[current];
	}
}
