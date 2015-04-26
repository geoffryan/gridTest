#include <stdlib.h>
#include "oneD.h"

struct OneDGrid* initOneDGrid(int Nx, int Nq)
{
    int Nt = Nx*Nx*Nx;
    int N = Nt*Nq;

    struct OneDGrid *g = malloc(sizeof(struct OneDGrid));

    g->Nx = Nx;
    g->Nt = Nt;
    g->Nq = Nq;

    g->a1 = (double *)malloc(N * sizeof(double));
    g->a2 = (double *)malloc(N * sizeof(double));
    g->a3 = (double *)malloc(N * sizeof(double));
    g->a4 = (double *)malloc(N * sizeof(double));

    return g;
}

double workOneD1(struct OneDGrid *g)
{
    int i, q;
    int Nt = g->Nt;
    int Nq = g->Nq;
    double sum = 0.0;

    for(i=0; i<Nt; i++)
    {
        for(q=0; q<Nq; q++)
        {
            sum += g->a1[Nq*i+q];
            sum += g->a2[Nq*i+q];
            sum += g->a3[Nq*i+q];
            sum += g->a4[Nq*i+q];
        }
    }

    return sum;
}

double workOneD2(struct OneDGrid *g)
{
    int i, q;
    int Nt = g->Nt;
    int Nq = g->Nq;
    double sum = 0.0;

    for(i=0; i<Nt; i++)
    {
        for(q=0; q<Nq; q++)
            sum += g->a1[Nq*i+q];
        for(q=0; q<Nq; q++)
            sum += g->a2[Nq*i+q];
        for(q=0; q<Nq; q++)
            sum += g->a3[Nq*i+q];
        for(q=0; q<Nq; q++)
            sum += g->a4[Nq*i+q];
    }

    return sum;
}

double workOneD3(struct OneDGrid *g)
{
    int i, q;
    int Nt = g->Nt;
    int Nq = g->Nq;
    double sum = 0.0;

    for(i=0; i<Nt; i++)
        for(q=0; q<Nq; q++)
            sum += g->a1[Nq*i+q];
    for(i=0; i<Nt; i++)
        for(q=0; q<Nq; q++)
            sum += g->a2[Nq*i+q];
    for(i=0; i<Nt; i++)
        for(q=0; q<Nq; q++)
            sum += g->a3[Nq*i+q];
    for(i=0; i<Nt; i++)
        for(q=0; q<Nq; q++)
            sum += g->a4[Nq*i+q];

    return sum;
}

void freeOneDGrid(struct OneDGrid *g)
{
    free(g->a1);
    free(g->a2);
    free(g->a3);
    free(g->a4);
    free(g);
}
