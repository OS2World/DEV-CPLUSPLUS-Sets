// Test program for Sets by Hubert Chan
// May 24, 1997

#include "Sets.hpp"
#include <stdio.h>

#define Test(x) (x ? "is\0" : "is not\0")

void main() {
	Set::SetElement Aarray[3] = { 1,2,3 };
	Set A(3,Aarray);
	Set::SetElement Barray[3] = { 2,3,4 };
	Set B(3,Barray);
	Set::SetElement Carray[2] = { 2,3 };
	Set C(2,Carray);
	printf("****************************************\n");
	printf("* Test program for Sets by Hubert Chan *\n");
	printf("* Last modified: May 24, 1997          *\n");
	printf("****************************************\n\n");
	printf("A = "); PrintSet(A);
	printf("B = "); PrintSet(B);
	printf("C = "); PrintSet(C);
	printf("|A| = %d\n", A.Card());
	printf("|B| = %d\n", B.Card());
	printf("|C| = %d\n", C.Card());
	printf("A U B = "); PrintSet(A + B);
	printf("A ^ B = "); PrintSet(A * B);
	printf("A - B = "); PrintSet(A - B);
	printf("~A = "); PrintSet(~A);
	printf("2 %s in A\n", Test(2<=A));
	printf("5 %s in A\n", Test(5<=A));
	printf("C %s a subset of A\n", Test(C<=A));
	printf("C %s a proper subset of A\n", Test(C<A));
	printf("C %s equal to A\n", Test(C==A));
	printf("C %s not equal to A\n", Test(C!=A));
	printf("A %s a subset of A\n", Test(A<=A));
	printf("A %s a proper subset of A\n", Test(A<A));
	printf("A %s equal to A\n", Test(A==A));
	printf("A %s not equal to A\n", Test(A!=A));
	printf("A %s a superset of C\n", Test(A>=C));
	printf("A %s a proper superset of C\n", Test(A>C));
}

