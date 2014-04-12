// Sets v 1.15
// Hubert Chan, May 24, 1997

//#include <stream.h>

#ifndef __SETS_
#define __SETS_

#define MAXELEMENT  6   // The largest possible element
#define MINELEMENT -3   // The smallest possible element


class Set {
public:
  typedef int SetElement;
private:
	#define NUMELEMENTS MAXELEMENT - MINELEMENT + 1
	#define SETELEMENTSIZE ((NUMELEMENTS + 7) / 8)
	char SetElements[SETELEMENTSIZE];
	void AddElem(SetElement);    // add an element to the set
	void RemoveElem(SetElement); // removes an element from the set
	void ClearSet();             // creates the empty set
public:
	Set() {
		ClearSet();
	}

	Set(int size, SetElement *Elements) {
		int counter;
		ClearSet();
		for(counter = 0; counter < size; counter++) {
			AddElem(Elements[counter]);
		}
	}

	Set(SetElement Element) {
		ClearSet();
		AddElem(Element);
	}

	Set(Set& Set2);

	int Card(); // cardinality

	Set operator=(Set);  // assignment
	Set operator+(Set);  // union
	Set operator|(Set);  // union
	Set operator+(SetElement); // add an element
	Set operator|(SetElement); // add an element
	Set operator+=(Set);
	Set operator|=(Set);
	Set operator+=(SetElement);
	Set operator|=(SetElement);
	Set operator-();     // complement
	Set operator~();     // complement
	Set operator*(Set);  // intersection
	Set operator^(Set);  // intersection
	Set operator&(Set);  // intersection
	Set operator*=(Set);
	Set operator^=(Set);
	Set operator&=(Set);
	Set operator-(Set);  // intersection of complement (difference)
	Set operator-(SetElement); // remove an element
	Set operator-=(Set);
	Set operator-=(SetElement);
	int operator==(Set); // equivalence
	int operator!=(Set); // inequivalence
	int operator<=(Set); // subset
	int operator<(Set);  // proper subset
	int operator>=(Set); // superset
	int operator>(Set);  // proper superset
	friend int operator<=(SetElement, Set); // element

	friend void PrintSet(Set &);
//	friend ostream& operator<<(ostream &, Set &);

};

#endif
