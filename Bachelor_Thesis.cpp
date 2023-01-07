#define _CRT_SECURE_NO_WARNINGS

#define PATIENTS 70
#define PROTEINS 16
#define DATA_FILE "data.txt"



#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE *inputfile;

float data[PATIENTS][PROTEINS];



int main()
{
	int i, j, k;
	float sum;
	float diff[PROTEINS][PATIENTS][PATIENTS];				// matrices with differences
	float max_diff[PROTEINS];								// matrix with maximum differences for every protein
	float ultimate_distance_array[PATIENTS][PATIENTS];		// final distance matrix

	// float ultimate_similarity_array[PATIENTS][PATIENTS];
	// float ultimate_max;
	


	// open and read file
	if((inputfile=fopen(DATA_FILE,"r" ))==NULL)
	{
		perror("Cannot open file");
		return 0;
	}

	for (j=0; j<PATIENTS; j++)
	{	
		for (i=0; i<PROTEINS; i++)
		{
			fscanf(inputfile, "%f", &(data[j][i]));
			//printf("%f\n", data[j][i]);

		}
	}


	// make matrices with differences
	for(i=0; i<PROTEINS; i++)
	{
		for (j=0; j<PATIENTS; j++)
		{
			for (k=0; k<PATIENTS; k++)
			{
				diff[i][j][k]=abs(data[j][i]-data[k][i]);
			}
		}




	// find maximum difference from every matrix with differences
		max_diff[i]=diff[i][0][0];

		for (j=0; j<PATIENTS; j++)
		{
			for (k=0; k<PATIENTS; k++)
			{
				if (diff[i][j][k]>max_diff[i])
				{
					max_diff[i]=diff[i][j][k];
				}

			}
		}
	
	
	//
	// print matrices with differences and maximum difference
	//
	//	for (j=0; j<PATIENTS; j++)
	//	{
	//		for (k=0; k<PATIENTS; k++)
	//		{
	//			printf("%f ", diff[i][j][k]);
	//		}
	//		printf("\n");
	//	}
	//	printf("\n");
	//
	//	printf("Maximum difference is:%f\n", max_diff[i]);
	//	printf("\n\n");


	}

	// calculate and print distance matrix

	printf("\n\nDistance Matrix\n");
	printf(   "---------------\n\n");
	printf("\t ");
	for(i=0; i<PATIENTS; i++)
	{
		printf("pat %.4d ", i+1);
	}
	printf("\n");
	printf("\t+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");


	for(i=0; i< PATIENTS; i++)
	{
		printf("pat %d\t|", i+1);
		for(j=0; j<PATIENTS; j++)
		{
			sum=0;

			for(k=0; k<PROTEINS; k++)
			{
				sum=sum+pow(diff[k][j][i],2)/pow(max_diff[k],2);
			}
			ultimate_distance_array[i][j]=sqrt(sum);
			
			if(ultimate_distance_array[i][j] == 0)
			{
				printf("0        ");
			}
			else
			{
				printf("%f ", ultimate_distance_array[i][j]);
			}
	
		}
		printf("\n");
	}

// calculate and pritn similarity matrix, which is complemetary to the matrix with differences, so either can work to calculate the distance matrix
//
//	ultimate_max=ultimate_distance_array[0][0];
//
//	for(i=0; i< PATIENTS; i++)
//	{
//		for(j=0; j<PATIENTS; j++)
//		{
//			if(ultimate_distance_array[i][j]>ultimate_max)
//			{
//				ultimate_max=ultimate_distance_array[i][j];
//			}
//		}
//	}
//
//
//	for(i=0; i< PATIENTS; i++)
//	{
//		for(j=0; j<PATIENTS; j++)
//		{
//
//			ultimate_similarity_array[i][j]=1-(ultimate_distance_array[i][j]/ultimate_max);
//			printf("%f  ", ultimate_similarity_array[i][j]);
//		}
//		printf("\n");
//	}


	return 0;


}



