//Andy Zhou
//Sequence Assignment

#include "sequence1.h"
#include <assert.h>
#include <cstdlib>
namespace main_savitch_3
{
	sequence::sequence() //done
	{
		index = 0;
		value = 0;
	}

	void sequence::start() //done
	{
		index = 0;
	}

	void sequence::advance()//done
	{
		assert(is_item() == true);
			index++;
	}

	void sequence::insert(const value_type& entry) {
		assert(size() < CAPACITY);
		if (is_item() == true) {
			for (size_t temp = value; temp > index; temp--)
			{
				data[temp] = data[temp - 1];
			}
			data[index] = entry;
			value++;
		}
		else if (is_item() == false) {
			index = 0;
			for (size_t temp = value; index < temp; temp--)
			{
				data[temp] = data[temp - 1];
			
			}
			data[index] = entry;
			value++;
		}
	}

	void sequence::attach(const value_type& entry) { //done
		assert(size() < CAPACITY);
		if (is_item() == false) {
			data[value] = entry;
			value++;
		}
		else {
			for (size_t temp = value; temp > index; temp--)
			{
				data[temp] = data[temp -1];
			}
			data[++index] = entry;
			value++;
		}
	}


	void sequence::remove_current() {
			assert(is_item());
			for (size_t temp = index; temp < value; temp++)
			{
				data[temp] = data[temp + 1];
			}
			--value;
		}

	sequence::size_type sequence::size() const {
			return value;
		}

	bool sequence::is_item() const {
			return index < value;
		}

	sequence:: value_type sequence::current() const { //done
			assert(is_item());
			return data[index];
		
		}

}