#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include "calc.h"

secCalc * mechanics(){
	secCalc * retval = malloc(sizeof(secCalc));
	retval -> head = NULL;
	return retval;
}

void memfree(secCalc * i){
	iniCalc * to_remove = i -> head;

	while(i -> head != NULL)
	{
		to_remove = i -> head;
		i -> head = i -> head -> next;
		free(to_remove);
	}
	
	free(i);
}

iniCalc * mecalc(float part){
	iniCalc * nodemade = malloc(sizeof(iniCalc));
	nodemade -> part = part;
	return nodemade;
}

bool partp(secCalc * i, float part){
	iniCalc * newnode = mecalc(part);
	
	if(i -> head == NULL)
	{
		i -> head = newnode;
		i -> head -> next = NULL;
		return true;
	}
	
	newnode -> next = i -> head;
	i -> head = newnode;
	return true;
}

bool parto(secCalc * i){
	iniCalc * curnode = i -> head;
	i -> head = i -> head -> next;
	free(curnode);
	return true;
}

void printOut(secCalc * i){
	iniCalc * curnode = i -> head;
	while (curnode != NULL)
	{
		printf("%f", curnode->part);
		printf("\n");
		curnode = curnode -> next;
	}
	printf("\n");
}
