#include <omp.h>
#include <stdio.h>
#define _GNU_SOURCE
#include <utmpx.h>
#include <sched.h>

int main (int argc, char *argv[])
{
   int nthreads, thread_id;

   #pragma omp parallel private(nthreads, thread_id)
   {
      thread_id = omp_get_thread_num();
      printf("Thread %d says: Hello World on core %i\n", thread_id,sched_getcpu());

      if (thread_id == 0)
      {
         nthreads = omp_get_num_threads();
         printf("Thread %d reports: the number of threads are %d\n",
                        thread_id, nthreads);
      }
  }
  return 0;
}
