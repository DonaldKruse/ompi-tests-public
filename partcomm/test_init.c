#include "/ascldap/users/dkruse/manzano-local/include/mpi.h"
#include "partscomm_common.h"



int main(int argc, char *argv[])
{
    double message[PARTITIONS*PARTSCOUNT];
    MPI_Count partitions = PARTITIONS;
    int source = 0, dest = 1, tag = 1, flag = 0;
    int myrank, i;
    int provided;
    MPI_Request request;
    

    
    MPI_Init_thread(&argc, &argv, MPI_THREAD_SERIALIZED, &provided);
    if (provided < MPI_THREAD_SERIALIZED)
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    
    if (myrank == 0)
    {
        MPI_Psend_init(message, partitions, PARTSCOUNT, MPI_DOUBLE, dest, tag,
                       MPI_COMM_WORLD, MPI_INFO_NULL, &request);
        MPI_Start(&request);
        for(i = 0; i < partitions; ++i)
        {
            /* compute and fill partition #i, then mark ready: */
            MPI_Pready(i, request);
        }
        while(!flag)
        {
            /* do useful work #1 */
            MPI_Test(&request, &flag, MPI_STATUS_IGNORE);
            /* do useful work #2 */
        }
        MPI_Request_free(&request);
    }
    else if (myrank == 1)
    {
        MPI_Precv_init(message, partitions, PARTSCOUNT, MPI_DOUBLE, source, tag,
                       MPI_COMM_WORLD, MPI_INFO_NULL, &request);
        MPI_Start(&request);
        while(!flag)
        {
            /* do useful work #1 */
            MPI_Test(&request, &flag, MPI_STATUS_IGNORE);
            /* do useful xwork #2 */
        }
        MPI_Request_free(&request);
    }


    printf("rank[%d], before finalize\n", myrank);
    MPI_Finalize();
    printf("after finalize\n");
    return 0;
}
