#!/bin/bash

#SBATCH -N 2
#SBATCH -J pct
#SBATCH --account=FY140001
#SBATCH -t 24:00:00



pwd
which mpicc
which mpirun
which gcc
sofile=/home/dkruse/mutrino-local/lib/libmpi.so

mpirun -x LD_PRELOAD=$sofile -N 1 ./test_init
