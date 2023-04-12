#include <errno.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>

/*
 * Define count paramters to use in the tests
 */
#ifndef PARTITIONS 
#define PARTITIONS 8
#endif

#ifndef PARTSCOUNT 
#define PARTSCOUNT 5
#endif
