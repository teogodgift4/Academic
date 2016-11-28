/*
 ============================================================================
 Name        : nuronika.c
 Author      : FreakSoul
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int numOfInVectors;
float input[];
float target[];
float trn=0.25;
float vectorError=0.00;
float a=0.08;

struct Layer{
	//--pinakes
	float *(*w); //disdiastatos
	float *(*oldw); // -//-
	float *net; //monodiastatos
	float *out; //-//-
	float *delta; //-//-
	float *(*prDW); //disdiastatos
	//--------
    struct Layer *nextLayerPtr; // deixnei to epomeno layer (sindedemenh lista)

};

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
