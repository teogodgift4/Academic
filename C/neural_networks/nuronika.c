#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float **trSet;
int **targetSet;
int numOfDimensions;
int numOfInVectors=1;
int numOfOutputs=1;
float *input;
float *target;
float trn=0.25;
float vectorError=0.00;
float a=0.08;
int layers;
int matrixRows;
int numOfInputs=2;

struct Layer{
	//--pinakes
	float **w; //disdiastatos
	float **oldw; // -//-
	float *net; //monodiastatos
	float *out; //-//-
	float *delta; //-//-
	float **prDW; //disdiastatos
	//--------
    struct Layer *nextLayerPtr; // deixnei to epomeno layer (sindedemenh lista)

};
typedef struct Layer neurons;
//----------------functions prototypes---------------//
void ConstructTrSet();
float Sigmoid(float);
void OperationPhase();
void TrainingPhase();
//--------------------------------------------------//

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	int i,j,epoch=0,sample;
	int n;
	FILE *fp;
	int key;
	//this is the iput and output layer and the hiddens
	//neurons N[layers+2];
        
      
	ConstructTrSet();
   
        //something like debugging




	return EXIT_SUCCESS;
}

void ConstructTrSet(){
int n,i;
		
//targetSet table memmory allocation
*targetSet=malloc(matrixRows*sizeof(int*));
for(i=0;i<matrixRows;i++)
    targetSet[i]=malloc(numOfOutputs*sizeof(int));

for(n=0;n<numOfInVectors;n++)
    for(i=0;i<numOfOutputs;i++)
        targetSet[n][i]=0.0;

//trset table memory allocation
*trSet=malloc(matrixRows*sizeof(int*));
for(i=0;i<matrixRows;i++)
    trSet[i]=malloc(numOfInputs*sizeof(int));
  
//give the desired training set
for(n=0;n<matrixRows;n++)
    for(i=0;i<numOfInputs;i++){
        printf("Give the desired input\n");
        scanf("%f",trSet[n][i]);
    }

for(n=0;n<numOfInVectors;n++)
    for(i=0;i<matrixRows;i++)
{
    printf("Give the desired output corresponding to the vector %f\n",trSet[n][i]);
    scanf("%f",trSet[n]);
}

}

float Sigmoid(float x){
	if(-x<690) return 1/(1+exp(-x));
	else
		return 1/(1+exp(690));

}
