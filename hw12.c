#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main (int argc, char ** argv) {
	if (argc != 2) {
		fprintf(stderr, "Incorrect number of arguments.\n");
		fprintf(stderr, "Usage: ./pa11 <input file>\n");		
		return EXIT_FAILURE;
	}

	float res; //store the res of your calculation here.
	float par;
	float num1;
	float num2;

	/* Insert code here to perform the RPN calculation.
	Don't forget to free any memory you allocate once you're done with it! */

	FILE * ver = fopen(argv[1], "r");
	if(ver == NULL){
		printf("Error opening input file for reading\n");
		return EXIT_FAILURE;
	}

	int len = 0;
	while(!feof(ver)){
		fgetc(ver);
		len++;
	}
	fseek(ver, 0, SEEK_SET);

	char string[10000];
	char final[10000];
	
	secCalc * i = mechanics();
	fgets(final,len,ver);

	
	int a = 0;
	int b = 0;
	int zero = '\0';
	fclose(ver);
	char mult = '*';
	char div = '/';
	char plus = '+';
	char minus = '-';
	
	while(final[a] != zero){
		if(final[a] == mult || final[a] == div || final[a] == plus || final[a] == minus){
			if( final[a] == minus && ( ( final[a + 1] >= 48 && final[a + 1] <= 57 ) || final[a + 1] == '.' ) ){
				string[b] = final[a];
				b++;
			}
			else{
				num1 = i -> head -> part;
				parto(i);
				if(i -> head != NULL){
					num2 = i -> head -> part;
					parto(i);
				}
				else if(i -> head == NULL) {
					memfree(i);
					return EXIT_FAILURE;
				}
				
				if(final[a] == plus){
					res = num1 + num2;
				}
				else if(final[a] == minus){
					res = num2 - num1;
				}
				else if(final[a] == mult){
					res = num1 * num2;
				}
				else if(final[a] == div){
					res = num2 / num1;
				}
				
				partp(i,res);
			}
		}
		else if(final[a] != ' '){
			string[b] = final[a];
			b++;
		}
		else if(final[a - 1] != mult && final[a - 1] != div && final[a - 1] != plus && final[a - 1] != minus){
				string[b] = '\0';
				par = atof(string);
				b = 0;
				partp(i, par);
		}
		a++;
	}
	
	if(i -> head -> next == NULL){
		memfree(i);
		printf("%f\n", res);
		return EXIT_SUCCESS;
	}
	else if (i -> head -> next != NULL){
		memfree(i);
		return EXIT_FAILURE;
	}
}
