#!/bin/bash

#SBATCH -N 2
#SBATCH -J pct
#SBATCH --account=FY140001
#SBATCH -t 24:00:00




/ascldap/users/dkruse/manzano-local/bin/mpirun -N 1 ./test_init
