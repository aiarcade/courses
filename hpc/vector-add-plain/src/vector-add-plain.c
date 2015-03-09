/*
 ============================================================================
 Name        : vector-add-plain.c
 Author      : Mahesh
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//const int N = 100000000;

int main(void) {

	int *h_A,*h_B,*h_R,N;
	scanf("%d",&N);

	h_A=(int*)malloc(sizeof(int)*N);
	h_B=(int*)malloc(sizeof(int)*N);
	h_R=(int*)malloc(sizeof(int)*N);

	int i;
	for(i=0;i<N;i++){
				h_A[i]=i;
				h_B[i]=i;
				h_R[i]=0;
	}
	for(i=0;i<N;i++){

		h_R[i] =h_A[i]*h_B[i]*i;

	}
	for(i=0;i<10;i++)
			printf("%d\n",h_R[i]);
	free(h_A);
	free(h_B);
	free(h_R);
	return EXIT_SUCCESS;

}
