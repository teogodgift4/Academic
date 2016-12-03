
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float **trSet;
int **targetSet;
int numOfDimensions;
int numOfInVectors=1;
int numOfOutputs=2;
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
	neurons N[layers+2];




	ConstructTrSet();
printf("%d",numOfInVectors);


	return EXIT_SUCCESS;
}

void ConstructTrSet(){
int n,i;
		printf("How many dimensions is your target vector?\n");
		scanf("%d",&numOfDimensions);
		// this is a pow function
		i=0;
		for(i=0;i<numOfDimensions;i++)
			numOfInVectors*=2;


		printf("How many hidden Layers do you want?\n");
		scanf("%d",&layers);



		//setting zero values to the output of matrix targetSet[]
		i=0;
		n=0;
		for(n=0;n<numOfInVectors;n++)
			for(i=0;i<numOfOutputs;i++)
		targetSet[n][i]=0;


		//trainning set
		/*printf("Please give the trainning set\n");
			for(n=0;n<numOfInVectors;n++)
				for(i=0;i<numOfDimensions;i++){
				scanf("%d",&trSet[n][i]);
				}*/



//desired output
printf("Give the desired output for each vector\n");
for(n=0;n<numOfInVectors;n++)
			scanf("%d",&target[n]);
}

float Sigmoid(float x){
	if(-x<690) return 1/(1+exp(-x));
	else
		return 1/(1+exp(690));

}
