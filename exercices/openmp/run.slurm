#!/bin/bash
#SBATCH --job-name=OMP_hello
#SBATCH --output=slurm.out
#SBATCH --error=slurm.err
#SBATCH --partition=COMPUTE
#SBATCH --nodes=1

export OMP_NUM_THREADS=2
./hello_omp
