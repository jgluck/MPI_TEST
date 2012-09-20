#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
  int* buf;
  int numprocs, rank, namelen;
  char processor_name[MPI_MAX_PROCESSOR_NAME];

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Get_processor_name(processor_name, &namelen);
  
  buf = malloc(sizeof(int));
  
  if(rank == 0){
	  //if i'm the special case
	  printf("This is the beginning:\n");
	  printf("Process %d on %s out of %d\n", rank, processor_name, numprocs);

	  buf[0] = rank;
	  MPI_Bcast(buf, 1, MPI_INT, rank, MPI_COMM_WORLD);
	  }else{
		  while(1 == 1){
			  MPI_Bcast(buf, 1,MPI_INT, rank-1, MPI_COMM_WORLD);
			  if(buf[0] == rank-1){
				  printf("Process %d on %s out of %d\n", rank, processor_name, numprocs);
				  buf[0] = rank;
				  MPI_Bcast(buf, 1, MPI_INT, rank, MPI_COMM_WORLD);
				  break;
				  }else{
					  printf("Wasn't me");
				  }
		  }
	  }
	  MPI_Finalize(); 
}