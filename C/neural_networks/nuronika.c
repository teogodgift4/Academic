#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float *trSet;
int *targetSet;
int numOfDimensions;
int numOfInVectors=1;
int numOfOutputs=1;
float input[];
float target[];
float trn=0.25;
float vectorError=0.00;
float a=0.08;
int layers;

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
printf("%d",numOfInVectors);



	return EXIT_SUCCESS;
}

void ConstructTrSet(){
int n,i;
		printf("How many dimensions is your target vector?\n");
		scanf("%d",&numOfDimensions);
		numOfInVectors=pow(2,numOfDimensions);
                printf("Input Vectors: %d and Dimensions of each one: %d\n",numOfInVectors,numOfDimensions);


		printf("How many hidden Layers do you want?\n");
		scanf("%d",&layers);
                printf("You choose %d layers\n",layers);


                //the 2D array is a simple 1D array now!!!
		//setting zero values to the output of matrix targetSet[]
                targetSet=malloc(numOfInVectors*numOfOutputs*sizeof(int*));
                for(i=0;i<numOfInVectors*numOfOutputs;i++)
		targetSet[i]=0;
               


		//trainning set
                //the 2D array is a simple 1D array now!!!
                trSet=malloc(numOfInVectors*numOfDimensions*sizeof(float));
		printf("Please give the trainning set\n");
                for(i=0;i<numOfInVectors*numOfDimensions;i++){
                    printf("trSet[%d]",i);
				scanf("%f",&trSet[i]);
				}
                        


//desired output
printf("Give the desired output for each vector\n");
for(n=0;n<numOfInVectors;n++)
    printf("vector %d:\n");
			scanf("%d",&target[n]);
}

float Sigmoid(float x){
	if(-x<690) return 1/(1+exp(-x));
	else
		return 1/(1+exp(690));

}

