#include <stdio.h>
#include "cuda.h"

const int N=10000000;





__global__
void add(int *A, int *B,int *R)
{
	int id = blockIdx.x*blockDim.x+threadIdx.x;
    R[id] =  A[id]*B[id]*id;

}

int main()
{
	int *h_A,*h_B,*h_R;
	h_A=(int*)malloc(sizeof(int)*N);
	h_B=(int*)malloc(sizeof(int)*N);
	h_R=(int*)malloc(sizeof(int)*N);

	int i;
	for(i=0;i<N;i++){
			h_A[i]=i;
			h_B[i]=i;
			h_R[i]=88;
	}


	int *d_A,*d_B,*d_R;
	cudaMalloc(&d_A,N*sizeof(int));
	cudaMalloc(&d_B,N*sizeof(int));
	cudaMalloc(&d_R,N*sizeof(int));


	cudaMemcpy(d_A,h_A,N*sizeof(int), cudaMemcpyHostToDevice );
	cudaMemcpy(d_B,h_B,N*sizeof(int), cudaMemcpyHostToDevice );
	cudaMemcpy(d_R,h_R,N*sizeof(int), cudaMemcpyHostToDevice );

	dim3 dimBlock( 512, 1, 1 );
	dim3 dimGrid( 1000, 1000 );

	add<<<dimGrid, dimBlock>>>(d_A, d_B,d_R);
	cudaThreadSynchronize();
	cudaMemcpy(h_R,d_R,N*sizeof(int), cudaMemcpyDeviceToHost );
	cudaFree( d_R );
	cudaFree( d_A );
	cudaFree( d_A );

	for(i=0;i<10;i++)
		printf("%d\n",h_R[i]);
	free(h_A);
	free(h_B);
	free(h_R);

	return EXIT_SUCCESS;
}
