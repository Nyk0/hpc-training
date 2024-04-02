#!/bin/bash
#SBATCH --job-name=infinite
#SBATCH --output=slurm.out
#SBATCH --error=slurm.err
#SBATCH --partition=COMPUTE
#SBATCH --nodes=1

srun ./infinite.sh
