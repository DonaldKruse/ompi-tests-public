######################################################################
# Utilities
######################################################################
.PHONY: default help

#cc = /home/dkruse/mutrino-local/src/openmpi-4.1.2/bin/mpicc
cc = /home/dkruse/mutrino-local/bin/mpicc
MPIRUN=/home/dkruse/mutrino-local/bin/mpirun
RM=/bin/rm -f

# GCC
#CC_FLAGS=-g -O0 -Wall -Werror
CC_FLAGS=-g -O0 -Wall

# Clang
#CC_FLAGS = -g -O0 -Wall -Wshorten-64-to-32 -Werror
F90_FLAGS=
F77_FLAGS=$(F90_FLAGS)


PARTITIONS=8
PARTSCOUNT=5


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
	mpicc --version
	which mpicc

clean:
	$(RM) $(BIN) *.o 



test_init: test_init.c partscomm_common.h 
	mpicc $(CC_FLAGS) -DPARTITIONS=$(PARTITIONS) \
	-DPARTSCOUNT=$(PARTSCOUNT) -o $@ -I. test_init.c
