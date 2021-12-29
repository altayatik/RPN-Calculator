#ifndef _CALC_H_
#define _CALC_H_
#include<stdbool.h>

typedef struct iniCalc{
	float part;
	struct iniCalc * next;
}

iniCalc;

typedef struct secCalc{
	iniCalc * head;
}

secCalc;

secCalc * mechanics();

void memfree(secCalc * i);

iniCalc * mecalc(float part);

bool partp(secCalc * i, float part);

bool parto(secCalc * i);

void printOut(secCalc * i);

#endif
