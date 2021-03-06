/*
 * main.cpp
 *
 *      Author: Peter (cspeter@cse.ust.hk)
 *
 *      The sample test case of the StringSet class
 *
 */

#include "stringset.h"
#include <iostream>
#include <fstream>
using namespace std;

void printSetContent(const StringSet& s ) {
	cout << "Content = " ;
        int sz = s.getSize();
        cout << "{" ;
        if ( sz > 0 ) {
                for (int i=0; i<sz-1; i++ ) {
                        cout << s.getItem(i) << "," ;
                }
                cout << s.getItem(sz-1);
        }
        cout << "}" ;
        cout << endl ;
}
void printSetSizeAndCapacity(const StringSet& s ) {

	cout << "Size = " << s.getSize() << " ; " << " Capacity = " << s.getCapacity() << endl ;

}


int main() {

	const string groupCSE_EClub = "CSE Entrepreneurship Club";
	const string groupCSE_One = "CSE One" ;
	const string groupCSEAA = "CSE Alumni Association";

	const string actHackathon = "Hackathon@HKUST" ;
	const string actMentorship = "CSE Mentorship Program";
	const string actTechShare = "CSE TechShare" ;

	cout << "=== Case 1: Empty Set ===" << endl ;
	StringSet set1;
	set1.sort();
	if (set1.isEmpty() ) {
		printSetContent(set1);
		printSetSizeAndCapacity(set1);
	}
	
	cout << "=== Case 2: A set with a single item ===" << endl ;
	StringSet set2(groupCSE_EClub);
	printSetContent(set2);
	printSetSizeAndCapacity(set2);
	

	cout << "=== Case 3: Copy constructor, insert and sort operations ===" << endl ;
	StringSet set3(set2);
	printSetContent(set3);

	cout << "Insert " << groupCSE_One  << " ? " << set3.insert(groupCSE_One) << endl ;
	cout << "Insert " << groupCSEAA    << " ? " << set3.insert(groupCSEAA) << endl ;
	cout << "Insert " << actHackathon  << " ? " << set3.insert(actHackathon) << endl ;
	cout << "Insert " << actMentorship << " ? " << set3.insert(actMentorship) << endl ;
	cout << "Insert " << actTechShare  << " ? " << set3.insert(actTechShare) << endl ;
	
	set3.sort();
	printSetContent(set3);

	cout << "=== Case 4: Assignment and remove operations ===" << endl ;
	StringSet set4;    // empty set
	set4.assign(set3); // assign set3 to set4
	printSetContent(set4);
	
	cout << "Remove " << groupCSEAA      << " ? "   << set4.remove(groupCSEAA)  << endl;
	cout << "Remove " << groupCSE_One    << " ? "   << set4.remove(groupCSE_One)  << endl;
	cout << "Remove " << actHackathon    << " ? "   << set4.remove(actHackathon)  << endl;
	set4.sort();
	printSetContent(set4);
	cout << "Remove " << actTechShare    << " ? "   << set4.remove(actTechShare)  << endl;
	cout << "Remove " << groupCSE_EClub  << " ? "   << set4.remove(groupCSE_EClub)  << endl;
	set4.sort();
	printSetContent(set4);

	cout << "=== Case 5: Set comparison ===" << endl ;
	StringSet set5_empty1 ; // empty set 1
	StringSet set5_empty2 ; // empty set 2
	cout << "Two empty sets are equal? " <<  (set5_empty1.equals(set5_empty2)) << endl ;
	cout << "Two empty sets are different? " << (set5_empty1.notEquals(set5_empty2)) << endl ;

	StringSet set5_order1; // set1 = {CSE One,CSE Entrepreneurship Club}

	set5_order1.insert(groupCSE_One);
	set5_order1.insert(groupCSE_EClub);

	StringSet set5_order2; // set2 = {CSE Entrepreneurship Club,CSE One}
	set5_order2.insert(groupCSE_EClub);
	set5_order2.insert(groupCSE_One);

	cout << "Order 1 ";
	printSetContent(set5_order1);
	cout << "Order 2 ";
	printSetContent(set5_order2);

	cout << "Two sets are equal? " << (set5_order1.equals(set5_order2)) << endl ;
	cout << "Two sets are different? " << (set5_order2.notEquals(set5_order1)) << endl ;
	cout << "Insert " << groupCSEAA << " ? " << ( set5_order1.insert(groupCSEAA) ) << endl ;
	cout << "Two sets are equal? " << (set5_order1.equals(set5_order2)) << endl ;
	cout << "Two sets are different? " << (set5_order2.notEquals(set5_order1)) << endl ;


	cout << "=== Case 6: Set union, intersect and difference ===" << endl ;

	string arrayA[3] = {groupCSEAA, groupCSE_EClub, groupCSE_One};
	string arrayB[4] = {groupCSE_EClub, actHackathon, actMentorship, actTechShare};


	StringSet set6a(arrayA, 3);
	StringSet set6b(arrayB, 4);
	

	set6a.sort();
	set6b.sort();

	cout << "Set A ";
	printSetContent(set6a);
	cout << "Set B ";
	printSetContent(set6b);

	StringSet setUni, setInter, setDiff;

	setUni.assign(set6a);
	setUni.setUnion(set6b);

	setInter.assign(set6a);
	setInter.setIntersect(set6b);

	setDiff.assign(set6a);
	setDiff.setDifference(set6b);

	setUni.sort();
	setInter.sort();
	setDiff.sort();

	cout << "A union B ";
	printSetContent(setUni);
	cout << "A intersect B ";
	printSetContent(setInter);
	cout << "A difference B ";
	printSetContent(setDiff);
	
	
	cout << "=== Case 7: Binary operators for union, intersect and difference ===" << endl ;
	StringSet set7a(set6a);
	StringSet set7b(set6b);
	cout << "Set A ";
	printSetContent(set7a);
	cout << "Set B ";
	printSetContent(set7b);

	setUni.assign(  setUnion(set7b,set7a) ) ;
	setInter.assign(  setIntersect(set7b,set7a)) ;
	setDiff.assign(   setDifference(set7b,set7a)) ;

	setUni.sort();
	setInter.sort();
	setDiff.sort();

	cout << "B union A ";
	printSetContent(setUni);
	cout << "B intersect A ";
	printSetContent(setInter);
	cout << "B difference A ";
	printSetContent(setDiff);

	cout << "=== Case 8: Size and capacity ===" << endl ;
	StringSet set8;
	printSetSizeAndCapacity(set8);
	cout << "Insert " << actHackathon << " ? " << set8.insert(actHackathon)  << endl;
	printSetSizeAndCapacity(set8);
	cout << "Insert " << actTechShare << " ? " << set8.insert(actTechShare)  << endl;
	printSetSizeAndCapacity(set8);
	cout << "Insert " << actMentorship << " ? " << set8.insert(actMentorship)  << endl;
	printSetSizeAndCapacity(set8);
	cout << "Insert " << groupCSE_EClub << " ? " << set8.insert(groupCSE_EClub)  << endl;
	printSetSizeAndCapacity(set8);

	cout << "Remove " << groupCSE_EClub << " ? " << set8.remove(groupCSE_EClub)  << endl;
	printSetSizeAndCapacity(set8);
	cout << "Remove " << actHackathon << " ? " << set8.remove(actHackathon)  << endl;
	printSetSizeAndCapacity(set8);
	printSetContent(set8);
	cout << "Remove " << actTechShare << " ? " << set8.remove(actTechShare)  << endl;
	printSetSizeAndCapacity(set8);
	printSetContent(set8);

	cout << "Remove " << actMentorship << " ? " << set8.remove(actMentorship)  << endl;
	printSetSizeAndCapacity(set8);
	printSetContent(set8);
	cout << "Insert " << actHackathon << " ? " << set8.insert(actHackathon)  << endl;
	printSetSizeAndCapacity(set8);
	printSetContent(set8);



	return 0;
}
