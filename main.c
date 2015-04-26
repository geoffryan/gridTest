#include <stdio.h>
#include <time.h>
#include "disco.h"
#include "discoStat.h"
#include "oneD.h"

int main(int argc, char *argv[])
{
    int nx, nq, reps;
    clock_t start, end;
    double time;
    int i;

    if(argc != 4)
    {
        fprintf(stdout, "Perform speed tests on different grid structures.\n");
        fprintf(stdout, "usage: gridTest <Nx> <Nq> <reps>\n");
        fprintf(stdout, "Version: %s\n", VERSION);
        return 0;
    }

    sscanf(argv[1], "%d", &nx);
    sscanf(argv[2], "%d", &nq);
    sscanf(argv[3], "%d", &reps);

    fprintf(stdout, "\nTesting things!\n");
    fprintf(stdout, "Version: %s\n\n", VERSION);
    
    fprintf(stdout, "Running %d reps with Nx=%d Nq=%d.\n\n", reps, nx, nq);


    // *** DISCO ***
    fprintf(stdout, "Running Disco-Style\n");
    struct DiscoGrid *g = initDiscoGrid(nx, nq);

    start = clock();
    for(i=0; i<reps; i++)
        workDisco1(g);
    end = clock();
    time = ((double)(end-start))/CLOCKS_PER_SEC;
    fprintf(stdout, "Work1: %g\n", time);
    
    start = clock();
    for(i=0; i<reps; i++)
        workDisco2(g);
    end = clock();
    time = ((double)(end-start))/CLOCKS_PER_SEC;
    fprintf(stdout, "Work2: %g\n", time);
    
    freeDiscoGrid(g);

    // *** Disco - Static ***
    fprintf(stdout, "\nRunning DiscoStat-Style\n");
    struct DiscoStatGrid *gs = initDiscoStatGrid(nx, nq);

    start = clock();
    for(i=0; i<reps; i++)
        workDiscoStat1(gs);
    end = clock();
    time = ((double)(end-start))/CLOCKS_PER_SEC;
    fprintf(stdout, "Work1: %g\n", time);
    
    start = clock();
    for(i=0; i<reps; i++)
        workDiscoStat2(gs);
    end = clock();
    time = ((double)(end-start))/CLOCKS_PER_SEC;
    fprintf(stdout, "Work2: %g\n", time);
    
    freeDiscoStatGrid(gs);

    // *** One-Dimensional ***
    fprintf(stdout, "\nRunning OneD-Style\n");
    struct OneDGrid *g1d = initOneDGrid(nx, nq);

    start = clock();
    for(i=0; i<reps; i++)
        workOneD1(g1d);
    end = clock();
    time = ((double)(end-start))/CLOCKS_PER_SEC;
    fprintf(stdout, "Work1: %g\n", time);
    
    start = clock();
    for(i=0; i<reps; i++)
        workOneD2(g1d);
    end = clock();
    time = ((double)(end-start))/CLOCKS_PER_SEC;
    fprintf(stdout, "Work2: %g\n", time);

    start = clock();
    for(i=0; i<reps; i++)
        workOneD3(g1d);
    end = clock();
    time = ((double)(end-start))/CLOCKS_PER_SEC;
    fprintf(stdout, "Work3: %g\n", time);

    freeOneDGrid(g1d);

    return 0;
}
