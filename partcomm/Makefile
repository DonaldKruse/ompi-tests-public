######################################################################
# Utilities
######################################################################
.PHONY: default help

CC	= mpicc
F77	= mpif77
F90	= mpif90
MPIRUN = mpirun
RM	= /bin/rm -f

# GCC
CC_FLAGS = -g -O0 -Wall -Werror

# Clang
#CC_FLAGS = -g -O0 -Wall -Wshorten-64-to-32 -Werror
F90_FLAGS =
F77_FLAGS = $(F90_FLAGS)


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

clean:
	$(RM) $(BIN) *.o 


#test_allgather: common.h test_allgather.c
	#$(CC) $(CC_FLAGS) -DTEST_PAYLOAD_SIZE=$(TEST_PAYLOAD_SIZE) -o $@ -I. test_allgather.c
	#$(CC) $(CC_FLAGS) -DTEST_UNIFORM_COUNT=$(TEST_UNIFORM_COUNT) -o $@_uniform_count -I. test_allgather.c

test_init: test_init.c partscomm_common.h 
	$(CC) $(CC_FLAGS) -DPARTITIONS=$(PARTITIONS) \
	-DPARTSCOUNT=$(PARTSCOUNT) -o $@ -I. test_init.c
