// Sets v 1.15
// Hubert Chan, May 24, 1997

#include "Sets.hpp"

static int counter;
#define DOONWHOLEARRAY(x) for(counter = 0; counter < SETELEMENTSIZE; counter++) x

Set::Set(Set& Set2) {
	DOONWHOLEARRAY(SetElements[counter] = Set2.SetElements[counter]);
}

void Set::AddElem(SetElement Element) {
	int Segment = (Element - MINELEMENT) / 8,
	    Offset  = (Element - MINELEMENT) % 8;

	SetElements[Segment] |= 1 << Offset;
}

void Set::RemoveElem(SetElement Element) {
	int Segment = (Element - MINELEMENT) / 8,
	    Offset  = (Element - MINELEMENT) % 8;

	SetElements[Segment] &= ~(1 << Offset);
}

void Set::ClearSet() {
	DOONWHOLEARRAY(SetElements[counter] = 0);
}

int Set::Card() {
	int Cardinality = 0;
	DOONWHOLEARRAY(Cardinality += (SetElements[counter] & 1) + ((SetElements[counter] >> 1) & 1)
	                     + ((SetElements[counter] >> 2) & 1) + ((SetElements[counter] >> 3) & 1)
	                     + ((SetElements[counter] >> 4) & 1) + ((SetElements[counter] >> 5) & 1)
	                     + ((SetElements[counter] >> 6) & 1) + ((SetElements[counter] >> 7) & 1));
	return Cardinality;
}

Set Set::operator=(Set Set2) {
	DOONWHOLEARRAY(SetElements[counter] = Set2.SetElements[counter]);
	return *this;
}

Set Set::operator+(Set Set2) {
	Set Result;
	DOONWHOLEARRAY(Result.SetElements[counter] = SetElements[counter] | Set2.SetElements[counter]);
	return Result;
}

Set Set::operator|(Set Set2) {
	return (*this + Set2);
}

Set Set::operator+(SetElement Element) {
	Set Result = *this;
	Result.AddElem(Element);
	return Result;
}

Set Set::operator|(SetElement Element) {
	return (*this + Element);
}

Set Set::operator+=(Set Set2) {
	DOONWHOLEARRAY(SetElements[counter] |= Set2.SetElements[counter]);
	return *this;
}

Set Set::operator|=(Set Set2) {
	return (*this += Set2);
}

Set Set::operator+=(SetElement Element) {
	AddElem(Element);
	return *this;
}

Set Set::operator|=(SetElement Element) {
	return (*this += Element);
}

Set Set::operator-() {
	Set Result;
	DOONWHOLEARRAY(Result.SetElements[counter] = ~SetElements[counter]);
	return Result;
}

Set Set::operator~() {
	return -(*this);
}

Set Set::operator*(Set Set2) {
	Set Result;
	DOONWHOLEARRAY(Result.SetElements[counter] = SetElements[counter] & Set2.SetElements[counter]);
	return Result;
}

Set Set::operator^(Set Set2) {
	return (*this * Set2);
}

Set Set::operator&(Set Set2) {
	return (*this * Set2);
}

Set Set::operator*=(Set Set2) {
	DOONWHOLEARRAY(SetElements[counter] &= Set2.SetElements[counter]);
	return *this;
}

Set Set::operator^=(Set Set2) {
	return (*this *= Set2);
}

Set Set::operator&=(Set Set2) {
	return (*this *= Set2);
}

Set Set::operator-(Set Set2) {
	Set Result;
	DOONWHOLEARRAY(Result.SetElements[counter] = SetElements[counter] & (~Set2.SetElements[counter]));
	return Result;
}

Set Set::operator-(SetElement Element) {
	Set Result = *this;
	Result.RemoveElem(Element);
	return Result;
}

Set Set::operator-=(Set Set2) {
	DOONWHOLEARRAY(SetElements[counter] &= !Set2.SetElements[counter]);
	return *this;
}

Set Set::operator-=(SetElement Element) {
	RemoveElem(Element);
	return *this;
}

int Set::operator==(Set Set2) {
	int Equivalent = -1;
	DOONWHOLEARRAY(Equivalent &= (SetElements[counter] == Set2.SetElements[counter]));
	return Equivalent;
}

int Set::operator!=(Set Set2) {
	int NotEquivalent = 0;
	DOONWHOLEARRAY(NotEquivalent |= (SetElements[counter] != Set2.SetElements[counter]));
	return (NotEquivalent != 0);
}

int Set::operator<=(Set Set2) {
	int Subset = -1;
	DOONWHOLEARRAY(Subset &= (~SetElements[counter] | Set2.SetElements[counter]));
	return (Subset == -1);
}

int Set::operator<(Set Set2) {
	int Subset = 0;
	DOONWHOLEARRAY(Subset |= (SetElements[counter] != Set2.SetElements[counter]));
	Subset = (Subset != 0 ) ? -1 : 0;
	DOONWHOLEARRAY(Subset &= (~SetElements[counter] | Set2.SetElements[counter]));
	return (Subset == -1);
}

int Set::operator>=(Set Set2) {
	int Superset = -1;
	DOONWHOLEARRAY(Superset &= (SetElements[counter] | ~Set2.SetElements[counter]));
	return (Superset == -1);
}

int Set::operator>(Set Set2) {
	int Superset = 0;
	DOONWHOLEARRAY(Superset |= (SetElements[counter] != Set2.SetElements[counter]));
	Superset = (Superset != 0) ? -1 : 0;
	DOONWHOLEARRAY(Superset &= (SetElements[counter] | ~Set2.SetElements[counter]));
	return (Superset == -1);
}

int operator<=(Set::SetElement Element, Set Set2) {
	int Segment = (Element - MINELEMENT) / 8,
	    Offset  = (Element - MINELEMENT) % 8;

	return ((Set2.SetElements[Segment] & (1 << Offset)) != 0);
}

//ostream & operator<<(ostream & s, Set & Set2) {
//	Set::SetElement counter;
//	int NotFirst = 0;
//	s << "{ ";
//	for(counter = MINELEMENT; counter <= MAXELEMENT; counter++)
//		if (counter <= Set2)
//			if (NotFirst)
//				s << form(",%d",counter);
//			else {
//				s << form("%d",counter);
//				NotFirst = !0;
//			}
//	s << " }";
//	return s;
//}

#include <stdio.h>

void PrintSet(Set &Set1) {
	Set::SetElement counter;
	int NotFirst = 0;
	printf("{ ");
	for(counter = MINELEMENT; counter <= MAXELEMENT; counter++)
		if (Set1 >= counter)
			if (NotFirst)
				printf(",%d",counter);
			else {
				printf("%d",counter);
				NotFirst = -1;
			}
	printf(" }\n");
}

