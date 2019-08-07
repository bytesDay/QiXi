/**
 * The Bytes Day
 * author: d_csl
 * date: 8.7.2019 
 * FunHiil,Peking
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "QiXiConfig.h"

void printUsage(const char *);

void encode(const char *);
void decode(char *);

long decimalToBinary(long n);
long binaryToDecimal(long n);

int main(int argc, char *argv[]) {

    if(argc < 2) {
    	printUsage(argv[0]);
        return '$';	
    }

    if(strcmp(argv[1],"-encode") == 0){
	encode(argv[2]);	    	
    } else if(strcmp(argv[1],"-decode") == 0) {
   	decode(argv[2]); 
    } else {
	printUsage(argv[0]);
	return '&';
    }

    return 0;
}

void encode(const char *text) {
    const char *p;
    fprintf(stdout,"%s to binary: \n",text);
    for(p = text; *p ; p++) {
	int decimal = (int)*p;
        long binary = decimalToBinary(decimal);	
	fprintf(stdout,"%ld,",binary); 
    }
    fprintf(stdout,"\n");
}

void decode(char *code) {
    char *token = strtok(code,",");
    fprintf(stdout,"Decode: \n");
    while(token != NULL) {
	long decimal = binaryToDecimal(atol(token));
	fprintf(stdout,"%c", (char)decimal);
    	token = strtok(NULL,",");
    }
    fprintf(stdout,"\n");
}

void printUsage(const char *name) {
    fprintf(stdout,"%s Version %d.%d\n",name,QiXi_VERSION_MAJOR,QiXi_VERSION_MINOR);
    fprintf(stdout,"Usage: %s -encode | -decode something\n",name);
}

long decimalToBinary(long n) {
    int remainder;
    long binary=0,i=1;
    while(n!=0) {
    	remainder = n % 2;
	n = n / 2;
	binary = binary + (remainder*i);
	i = i * 10;
    }
    return binary;
} 


long binaryToDecimal(long n) {
    int remainder;
    long decimal = 0, i = 0;
    while(n != 0){
    	remainder = n % 10;
	n = n / 10;
	decimal = decimal + (remainder * pow(2,i));
	++i;
    }
    return decimal;
}
