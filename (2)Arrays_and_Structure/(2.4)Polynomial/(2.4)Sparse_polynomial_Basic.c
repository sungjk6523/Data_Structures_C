#include<stdio.h>
#define MAX_TERMS 15

typedef struct {
	float coef;
	int expon;
} polynomial;

polynomial terms[MAX_TERMS];
int avail = 0;

void attach(float coef, int expon);
void polyAdd(int startA, int finishA, int startB, int finishB, int* startD, int* finishD);
void polyPrint(int start, int finish);

int main() {
	/* polynomial A */
	attach(2, 1000);
	attach(1, 0);

	/* polynomial B */
	attach(1, 4);
	attach(10, 3);
	attach(3, 2);
	attach(1, 0);

	int startD, finishD;
	polyAdd(0, 1, 2, 5, &startD, &finishD);	
	polyPrint(startD, finishD);
}

void attach(float coef, int expon) {
	if (avail >= MAX_TERMS){
		printf("Memory Over\n");
		return;
	}	
	terms[avail].coef = coef;
	terms[avail++].expon = expon;
}

void polyAdd(int startA, int finishA, int startB, int finishB, int* startD, int* finishD) {
	float coefficient;
	int offset;
	*startD = avail;

	while (startA <= finishA && startB <= finishB) {
		offset = terms[startA].expon - terms[startB].expon;

		if (offset < 0) {
			attach(terms[startB].coef, terms[startB].expon);
			startB++;
		}
		else if (offset == 0) {
			coefficient = terms[startA].coef + terms[startB].coef;
			if (coefficient) {
				attach(coefficient, terms[startA].expon);
				startA++;
				startB++;
			}
		}
		else {
			attach(terms[startA].coef, terms[startA].expon);
			startA++;
		}
	}

	for (; startA <= finishA; startA++) 
		attach(terms[startA].coef, terms[startA].expon);
	for (; startB <= finishB; startB++) 
		attach(terms[startB].coef, terms[startB].expon);

	*finishD = avail - 1;
}

void polyPrint(int start, int finish) {
	int i;
	for (i = start; start <= finish; start++) {
		printf("(%.2f)x^%d", terms[start].coef, terms[start].expon);
		if (start != finish)
			printf(" + ");
	}
}