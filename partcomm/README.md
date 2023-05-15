# Part Comm Tests
[man page](https://docs.open-mpi.org/en/main/man-openmpi/man3/)


 >  example

| Test Suite                                                                                | thing | thing2 |
|-------------------------------------------------------------------------------------------|-------|--------|
| [MPI_Start](https://docs.open-mpi.org/en/main/man-openmpi/man3/MPI_Start.3.html#c-syntax) |       |        |
| [MPI_Startall](https://docs.open-mpi.org/en/main/man-openmpi/man3/MPI_Startall.3.html)    |       |        |
|                                                                                           |       |        |

 * Assumes:
   - assumption

## Building
### Mutrino (Intel)
First load appropriate modules
```
module load PrgEnv-intel; module load craype-haswell
```
Then build OpenMPI 4.
```
./configure --prefix=/home/your_home/local
make -j 16 all
make -j 16 install
```
TODO env vars/compiler/so/
```
make clean
make all
```

## Running TODO

```
mpirun --np n ./test_partcomm

.. etc
```

ouput:
```
shell$ mpirun --np n ./test_partcomm
output ....
```

## Environment variables TODO

## To Do
stuff
