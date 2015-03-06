/*stringset.cpp
*
*
*author: Hong Suk-Jin
*SID:20154003
*Lecture:L1 Lab:LA3
*
*/

#include "stringset.h"
#include <iostream>


using namespace std;

StringSet::StringSet() {
	size=0;
	capacity=0;
	arr=NULL;
}

// Destructor: Deallocate memory
StringSet::~StringSet() {
	delete []arr;
	arr=NULL;
	size=0;
	capacity=0;
}

// Constructor: Create a set with a single item
StringSet::StringSet(const string& oneItem) {
	size=1;
	capacity=2;
	arr=new string[capacity];
	arr[0]=oneItem;	
}

// Constructor: Create a set using an array of string
StringSet::StringSet(const string inputStrArr[], int sz) {
	size=sz;
	capacity=sz;
	arr=new string[capacity];
	for (int i=0;i<capacity;i++) {
		arr[i]=inputStrArr[i];
	}
}

// Copy constructor
StringSet::StringSet(const StringSet& otherSet) {
	size=otherSet.size;
	capacity=size;
	arr=new string[size];
	for (int i=0; i<capacity; i++) {
		arr[i]=otherSet.arr[i];
	}
}

string StringSet::getItem(int index) const {
	return arr[index];
}

// Return size
int StringSet::getSize() const {
	return size;
}

// Return capacity
int StringSet::getCapacity() const {
	return capacity;
}

// Return true if a set is an empty set. Otherwise, return false
bool StringSet::isEmpty() const {
	if (size==0) {
		return true;
	}
	return false; 
}

// Return true if an item exists in a set. Otherwise, return false
bool StringSet::exists(const string& item) const {
	if (searchItem(item)!=-1) {
		return true;
	}
	return false;
}

// Return the index of an item
// Return -1 if the item can't be found
int StringSet::searchItem(const string& item) const {
	for (int i=0; i<size; i++) {
		if (arr[i].compare(item)==0) {
			return  i;
		}
	}
	return -1;
}


bool StringSet::insert(const string& newItem) {
	if (searchItem(newItem)==1)
		return false;
	
	size++;

	if (size>capacity) {
		string* temp=new string[size-1];

		for (int i=0; i<size-1;i++) {
			temp[i]=arr[i];
		}
		capacity=2*capacity+2;

		delete []arr;
		arr=new string[capacity];
		for (int i=0; i<size-1; i++) {
			arr[i]=temp[i];
		}
		delete []temp;
		temp=NULL;

		arr[size-1]=newItem;

		return true;
	}

	arr[size-1]=newItem;

	return true;
}

// If an item exists, remove that item from the set and return true
// Otherwise, return false
bool StringSet::remove(const string& item) {
	if (!exists(item))
		return false;

	int a=searchItem(item);


	size--;

	if (size==0) {
		deallocateArray();
	}

	else if (size<(capacity/2)) {
		capacity/=2;
		for (int i=a; i<size; i++) {
			arr[i]=arr[i+1];
		}
		string* temp=new string[capacity];
		for (int i=0; i<size;i++) {
			temp[i]=arr[i];
		}
		delete []arr;
		arr=new string[capacity];
		for (int i=0; i<size; i++) {
			arr[i]=temp[i];
		}
		delete []temp;
		temp=NULL;
	}
	else {
		string temppp=arr[a];
		arr[a]=arr[size];
		arr[size]=temppp;
	}

	return true;

}

// Note: You should implement "Deep copy" as follows:
//    (1) Deallocate the content of the current array
//    (2) Allocate a new array with the same size and capacity as inputSet
//    (3) Copy all items from inputSet
//    (4) Return the reference of the current object (i.e. return *this)
StringSet& StringSet::assign(const StringSet& inputSet) {
	deallocateArray();
	size=inputSet.size;
	capacity=inputSet.capacity;
	arr=new string[size];
	for (int i=0; i<size;i++) {
		arr[i]=inputSet.arr[i];
	}
	return *this;
}


// Check whether the current set is equal to another set
// Note: The order is NOT important
//    e.g. {"Hong Kong", "London"} should be the same as {"London", "Hong Kong"}

bool StringSet::equals(const StringSet& other) const {
	if (size!=other.size)
		return false;
	for (int i=0; i<other.size;i++) {
		if (!exists(other.arr[i])) {
			return false;
		}
	} 
	return true;
}


// Check whether the current set is not equal to another set
bool StringSet::notEquals(const StringSet& other) const {
	if (equals(other))
		return false;
	return true;
}


//  Implement the set union operation
StringSet& StringSet::setUnion(const StringSet& other) {
	string *tempp=new string [100];
	int a=0;
	for (int i=0; i<other.size; i++) {
		if(!exists(other.arr[i])) {
			tempp[a]=other.arr[i];
			a++;
		}
	}
	for (int i=0; i<size; i++) {
		tempp[a]=arr[i];
		a++;
	}
	delete [] arr;
	arr=NULL;
	arr=new string[a];
	for (int i=0; i<a; i++) {
		arr[i]=tempp[i];
	}
	delete []tempp;
	tempp=NULL;
	size=a;
	return *this;
}


//  Implement the set intersect operation
StringSet& StringSet::setIntersect(const StringSet& other) {
	string *tempp=new string [100];
	int a=0;
	for (int i=0; i<other.size; i++) {
		if(exists(other.arr[i])) {
			tempp[a]=other.arr[i];
			a++;
		}
	}
	delete []arr;
	arr=new string [a];
	for (int i=0; i<a;i++) {
		arr[i]=tempp[i];
	}
	size=a;
	delete []tempp;
	tempp=NULL;
	return *this;
}


//  Implement the set difference operation
StringSet& StringSet::setDifference(const StringSet& other) {
	string *tempp=new string [100];
	int a=0;
	
	for (int i=0; i<size; i++) {
		if(!other.exists(arr[i])) {
			tempp[a]=arr[i];
			a++;
		}
		
	}
	delete [] arr;
	arr=NULL;
	arr=new string[a];
	for (int i=0; i<a; i++) {
		arr[i]=tempp[i];
	}
	delete []tempp;
	tempp=NULL;
	size=a;
	return *this;
}

void StringSet::deallocateArray() {
	delete [] arr;
	arr=NULL;
	size=0;
	capacity=0;
}



//   Implement the set union
StringSet setUnion(const StringSet& first, const StringSet& second) {
	StringSet a(first);
	a.setUnion(second);
	return a;
}


//   Implement the set intersect
StringSet setIntersect(const StringSet& first, const StringSet& second) {
	StringSet a(first);
	a.setIntersect(second);
	return a;
}


//   Implement the set difference
StringSet setDifference(const StringSet& first, const StringSet& second) {
	StringSet a(first);
	a.setDifference(second);
	return a;
}