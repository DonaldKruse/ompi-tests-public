######################################################################
# Utilities
######################################################################
.PHONY: default help

#cc = /home/dkruse/mutrino-local/src/openmpi-4.1.2/bin/mpicc
#cc = /home/dkruse/mutrino-local/bin/mpicc
cc = /ascldap/users/dkruse/manzano-local/bin/mpicc

#MPIRUN=/home/dkruse/mutrino-local/bin/mpirun
MPIRUN = /ascldap/users/dkruse/manzano-local/bin/mpirun

RM=/bin/rm -f

# GCC
#CC_FLAGS=-g -O0 -Wall -Werror
CC_FLAGS=-g -O0 -Wall

# Clang
#CC_FLAGS = -g -O0 -Wall -Wshorten-64-to-32 -Werror
F90_FLAGS=
F77_FLAGS=$(F90_FLAGS)


#PARTITIONS=8
#PARTSCOUNT=5

PARTITIONS=1
PARTSCOUNT=1


######################################################################
# Binaries
######################################################################
BINCC	= \
	test_init

BIN	= $(BINCC)



######################################################################
# Targets
######################################################################
all: $(BIN)

test:
	echo "fix this later..."
	echo "--version:"
	$(cc) --version
	echo "which $(cc):"
	which $(cc)

clean:
	$(RM) $(BIN) *.o *~
	mv slurm-*.out trash/



test_init: test_init.c partscomm_common.h 
	$(cc) $(CC_FLAGS) -DPARTITIONS=$(PARTITIONS) \
	-DPARTSCOUNT=$(PARTSCOUNT) -o $@ -I. -L /ascldap/users/dkruse/skybridge-local/lib test_init.c
