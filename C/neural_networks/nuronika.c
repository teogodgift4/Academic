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


		printf("How many hidden Layers do you want?\n");
		scanf("%d",&layers);



		//setting zero values to the output of matrix targetSet[]
                targetSet=malloc(numOfInVectors*sizeof(int*));
                for(i=0;i<numOfInVectors;i++)
                targetSet[i]=malloc(numOfOutputs*sizeof(int));
                
		i=0;
		n=0;
		for(n=0;n<numOfInVectors;n++)
			for(i=0;i<numOfOutputs;i++)
		targetSet[n][i]=0;


		//trainning set
                trSet=malloc(numOfInVectors*sizeof(float*));
                for(i=0;i<numOfDimensions;i++)
                    trSet[i]=malloc(numOfDimensions*sizeof(float));
                
                
                i=0;n=0;
                
		printf("Please give the trainning set\n");
			for(n=0;n<numOfInVectors;n++)
				for(i=0;i<numOfDimensions;i++){
				scanf("%f",&trSet[n][i]);
				}



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


