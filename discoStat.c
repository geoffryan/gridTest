#include <stdlib.h>
#include "discoStat.h"

struct DiscoStatGrid* initDiscoStatGrid(int Nx, int Nq)
{
    struct DiscoStatGrid *g = (struct DiscoStatGrid *)malloc(sizeof(struct DiscoStatGrid));
    g->cells = (struct DiscoStatCell ***)malloc(Nx * sizeof(struct DiscoStatCell **));
    g->Nx = Nx;
    g->Nq = Nq<MAXQ ? Nq : MAXQ;

    int k,j,i,q;

    for(k=0; k<Nx; k++)
    {
        g->cells[k] = (struct DiscoStatCell **)malloc(Nx * sizeof(struct DiscoStatCell *));
        for(j=0; j<Nx; j++)
        {
            g->cells[k][j] = (struct DiscoStatCell *)malloc(Nx * sizeof(struct DiscoStatCell));
            for(i=0; i<Nx; i++)
            {
                for(q=0; q < g->Nq; q++)
                {
                    g->cells[k][j][i].a1[q] = i*j+q;
                    g->cells[k][j][i].a2[q] = i*k+q;
                    g->cells[k][j][i].a3[q] = j*i+q;
                    g->cells[k][j][i].a4[q] = i+j+k+q;
                }
            }
            
        }
    }

    return g;
}

double workDiscoStat1(struct DiscoStatGrid *g)
{
    double sum = 0.0;
    int i,j,k,q;
    int Nx = g->Nx;
    int Nq = g->Nq;

    for(k=0; k<Nx; k++) 
        for(j=0; j<Nx; j++) 
            for(i=0; i<Nx; i++) 
                for(q=0; q<Nq; q++)
                {
                    sum += g->cells[k][j][i].a1[q];
                    sum += g->cells[k][j][i].a2[q];
                    sum += g->cells[k][j][i].a3[q];
                    sum += g->cells[k][j][i].a4[q];
                }
    return sum;
}

double workDiscoStat2(struct DiscoStatGrid *g)
{
    double sum = 0.0;
    int i,j,k,q;
    int Nx = g->Nx;
    int Nq = g->Nq;

    for(k=0; k<Nx; k++) 
        for(j=0; j<Nx; j++) 
            for(i=0; i<Nx; i++) 
            {
                for(q=0; q<Nq; q++)
                    sum += g->cells[k][j][i].a1[q];
                for(q=0; q<Nq; q++)
                    sum += g->cells[k][j][i].a2[q];
                for(q=0; q<Nq; q++)
                    sum += g->cells[k][j][i].a3[q];
                for(q=0; q<Nq; q++)
                    sum += g->cells[k][j][i].a4[q];
            }
    return sum;
}
void freeDiscoStatGrid(struct DiscoStatGrid *g)
{
    int j,k;
    int Nx = g->Nx;

    for(k=0; k<Nx; k++)
    {
        for(j=0; j<Nx; j++)
            free(g->cells[k][j]);
        free(g->cells[k]);
    }
    free(g->cells);
    free(g);
}
