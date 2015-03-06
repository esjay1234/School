/*
 * stringset.h
 *
 *      Author: Peter (cspeter@cse.ust.hk)
 *
 *      StringSet class declaration
 *
 */

// The following 2 lines and the last endif statement are compiler macro
// It avoids including the same header file for multiple times
#ifndef STRINGSET_H_
#define STRINGSET_H_

#include <iostream>
#include <string>

//
// Note:
//
// In header files, "using namespace std" should be avoided
// We should write:
//
//    std::string, std::cout, std::endl,
//    std::ifstream, std::ofstream
//
// In the cpp files, you can write "using namespace std" and
// you are not required to add prefix "std::"
//

class StringSet {
public:

	// ============================
	// Constructors and destructor
	// ============================

	// Default constructor: Create an empty set
	StringSet();

	// Destructor: Deallocate memory
	~StringSet();

	// Constructor: Create a set with a single item
	StringSet(const std::string& oneItem);

	// Constructor: Create a set using an array of string
	StringSet(const std::string inputStrArr[], int sz);

	// Copy constructor
	StringSet(const StringSet& otherSet);


	// =====================
	// Member functions
	// ====================

	// Return a string located at the given array index
	// Note: No need to do any boundary checking in this function
	std::string getItem(int index) const;

	// Return size
	int getSize() const;

	// Return capacity
	int getCapacity() const;

	// Return true if a set is an empty set. Otherwise, return false
	bool isEmpty() const;

	// Return true if an item exists in a set. Otherwise, return false
	bool exists(const std::string& item) const;


	// Return the index of an item
	// Return -1 if the item can't be found
	int searchItem(const std::string& item) const;


	// If newItem exists, don't insert the newItem and return false
	// Otherwise, insert newItem and then return true
	bool insert(const std::string& newItem);


	// If an item exists, remove that item from the set and return true
	// Otherwise, return false
	bool remove(const std::string& item);


	// Sort the items
        // The implementaton (a simple bubble sort) is given 
	void sort()  {
	   std::string tmp;
           for (int i=size-1; i>=0; i--)
                for (int j=0; j<i; j++)
                    if ( arr[j] > arr[j+1] ) {
                         tmp = arr[j];
                         arr[j] = arr[j+1];
                         arr[j+1] = tmp;
                    }
	}


	// Note: You should implement "Deep copy" as follows:
	//    (1) Deallocate the content of the current array
	//    (2) Allocate a new array with the same size and capacity as inputSet
	//    (3) Copy all items from inputSet
	//    (4) Return the reference of the current object (i.e. return *this)
	StringSet& assign(const StringSet& inputSet);


	// Check whether the current set is equal to another set
	// Note: The order is NOT important
	//    e.g. {"Hong Kong", "London"} should be the same as {"London", "Hong Kong"}
	bool equals(const StringSet& other) const;


	// Check whether the current set is not equal to another set
	bool notEquals(const StringSet& other) const;


	//  Implement the set union operation
	StringSet& setUnion(const StringSet& other);


	//  Implement the set intersect operation
	StringSet& setIntersect(const StringSet& other);


	//  Implement the set difference operation
	StringSet& setDifference(const StringSet& other);


private:


	// Private member function,
	//    deallocate arr and reset the size and capacity to 0
	void deallocateArray();


	std::string* arr;  // an array of string
	int size;     // the current number of items
	int capacity; // the number of memory location currently allocated
};



//   Implement the set union
StringSet setUnion(const StringSet& first, const StringSet& second);


//   Implement the set intersect
StringSet setIntersect(const StringSet& first, const StringSet& second);


//   Implement the set difference
StringSet setDifference(const StringSet& first, const StringSet& second);



#endif /* STRINGSET_H_ */