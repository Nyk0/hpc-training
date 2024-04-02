#!/bin/bash
#SBATCH --job-name=hello_ompi
#SBATCH --output=slurm.out
#SBATCH --error=slurm.err
#SBATCH --partition=COMPUTE
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=2

mpirun -n 4 ./hello_ompi
