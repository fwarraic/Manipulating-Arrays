// a1.cpp

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : <Fazal Dad Warraich>
// St.# : <301319108>
// Email: <fwarraic@sfu.ca>
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

#include "a1.h"
#include "cmpt_error.h"
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// Functions ----------------------------------------------------------------------------------------------------

// Question1
// Returns a new str_array of size 0 and capacity cap.
str_array make_empty(int cap = 10)
{
	str_array array;

	array.size = 0;
	array.capacity = cap;
	array.arr = new string[cap];

	return array;
}

// Question2
// Deletes memory called from the heap.
void deallocate(str_array& arr)
{
	delete[] arr.arr;
	arr.arr = nullptr;
}

// Question3
// Returns the percentage of the array that is in use.
double pct_used(const str_array& arr)
{
	double percentUsed = static_cast<double>(arr.size) / arr.capacity;
	return percentUsed;
}

// Question4
// convert arr's underlying array to a string
string to_str(const str_array& arr)
{
	string nextString;
	nextString += "{";
	
	// evaluates each input from the array.
	for (int index = 0; index < arr.size; index++)
	{
		// checks for last comma to be added or not.
		if (index != arr.size - 1)
		{
			nextString += "\"" + arr.arr[index] + "\"" + ", ";
		}
		else
		{
			nextString += "\"" + arr.arr[index] + "\"";
		}// if-else
	}// for

	nextString += "}";

	// checks for no string(only brackets) and for one string(no comma).
	if (arr.size == 0)
	{
		return "{}";
	}
	else if (arr.size == 1)
	{
		return nextString;
	}// if-else
	
	// If above condition unsatisfied return the strings in the required format
	// for more than one string.
	return nextString;

}

// prints to_str(arr) to cout
void print(const str_array& arr)
{
	cout << to_str(arr);
}

// same as print, but also prints '\n' at the end
void println(const str_array& arr)
{
	cout << to_str(arr) << "\n";
}

// Question5
// Implements the get(arr, i) function, which returns the value at location i of the underlying array.
string get(const str_array& arr, int i)
{
	if (i < 0 || i >= arr.size)
	{
		cmpt::error ("Index i cannot be reached, incorrect size.");
    	throw;
	}// if
	
	string array;
	array = arr.arr[i];
	return array;
}

// Assigns s to location i of the underlying array.
// Also checks the bounds of i.
void set(str_array& arr, int i, const string& s)
{
	if (i < 0 || i >= arr.size)
	{
		cmpt::error ("Index i cannot be reached, incorrect size.");
		throw;
	}// if

    arr.arr[i] = s;
}

// Question 6
// Adds a new element to the right end of arr, re-sizing it if necessary.
void append(str_array& arr, const string& s)
{
	// if size greater than capacity, resize capacity.
	if (arr.size >= arr.capacity)
	{
		int twiceCap = arr.capacity * 2;
		string *array = new string[twiceCap];

		// adding arr pointer content into array pointer.
		for (int index = 0; index < arr.size; index++)
		{
			array[index] = arr.arr[index];
		}// for

		// deletes memory borrowed from heap.
		deallocate(arr);
		arr.capacity = arr.capacity * 2;
		arr.arr = array;

	}// if

	// increments size and adds the string to the right.
	arr.arr[arr.size] = s;
	arr.size++;

}

// Question 7
// Testing whether two str_arrays are equal or not.
bool operator==(str_array a, str_array b)
{
	// Initially size check.
	if (a.size != b.size)
	{
		return false;
	}// if

	// Then character by character check.
	for (int index = 0; index < a.size; index++)
	{
		if (a.arr[index] != b.arr[index])
		{
			return false;
		}// if
	}// for

	return true;
}

// Question 8
// The size of the array is reset to zero.
void clear(str_array& arr)
{
	arr.size = 0;
}

// Question 9
// String is added as the first element of the array 
// (and all the other elements are moved right one position).
void prepend(str_array& arr, const string& s)
{
	// if size greater than capacity, resize capacity.
	if (arr.size >= arr.capacity)
	{
		int twiceCap = arr.capacity * 2;
		string *array = new string[twiceCap];

		// adding arr pointer content into array pointer.
		for (int index = 0; index < arr.size; index++)
		{
			array[index] = arr.arr[index];
		}// for

		// deletes memory borrowed from heap in arr 
		// before modification to capacity.
		deallocate(arr);
		arr.capacity = arr.capacity * 2;
		arr.arr = array;

	}// if

	// starts from the end of the array till arr[1]
	// moves the strings one place to the right.
	for (int index = arr.size; index > 0; index++)
	{
		arr.arr[index] = arr.arr[index - 1];
	}// for

	// adds the string to the left most order.
	arr.arr[0] = s;
	arr.size++;

}

// Question 10
// make the size and capacity of arr the same
void shrink_to_fit(str_array& arr)
{
	arr.capacity = arr.size;
}

//----------------------------------------------------------------------------------------------------------------

int main() 
{

  

}