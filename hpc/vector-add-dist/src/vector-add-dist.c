/*
 ============================================================================
 Name        : vector-add-dist.c
 Author      : Mahesh
 Version     :
 Copyright   : 
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
  int numprocs, rank,i;
  int A,B,R;
  char processor_name[MPI_MAX_PROCESSOR_NAME];
  int *h_A,*h_B,*h_R;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  int N=numprocs;
  if(rank==0)
  {
	  h_A=(int*)malloc(sizeof(int)*N);
	  h_B=(int*)malloc(sizeof(int)*N);
	  h_R=(int*)malloc(sizeof(int)*N);
	  for(i=0;i<N;i++){
	  				h_A[i]=i;
	  				h_B[i]=i;
	  				h_R[i]=0;
	  				if(i!=0)
	  				{
	  					MPI_Send(&h_A[i], 1, MPI_INT,i, 0, MPI_COMM_WORLD);
	  					MPI_Send(&h_B[i], 1, MPI_INT,i, 1, MPI_COMM_WORLD);
	  				}


	  }
	  for(i=1;i<N;i++){
		  MPI_Recv(&h_R[i], 1, MPI_INT,i, 2,MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	  }
	  for(i=0;i<10;i++)
	  			printf("%d\n",h_R[i]);

  }
  else
  {
	  MPI_Recv(&A, 1, MPI_INT,0, 0,MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	  MPI_Recv(&B, 1, MPI_INT,0, 1,MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	  R=A*B*rank;
	  MPI_Send(&R, 1, MPI_INT,0, 2, MPI_COMM_WORLD);

  }

  MPI_Finalize();

  }
