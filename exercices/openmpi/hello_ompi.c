#include <stdio.h>
#include <mpi.h>
#include <stdio.h>
#include <unistd.h>

int main (argc, argv)
     int argc;
     char *argv[];
{
  int rank, size;
  char hostname[40];
  MPI_Init (&argc, &argv);      /* starts MPI */
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);        /* get current process id */
  MPI_Comm_size (MPI_COMM_WORLD, &size);        /* get number of processes */
  gethostname(hostname,40);
  printf( "Hello world from process %d of %d at %s\n", rank, size, hostname );
  MPI_Finalize();
  return 0;
}
