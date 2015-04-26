#include <stdlib.h>
#include "discoStyle.h"

struct DiscoGrid* initDiscoGrid(int Nx, int Nq)
{
    struct DiscoGrid *g = (struct DiscoGrid *)malloc(sizeof(struct DiscoGrid));
    g->cells = (struct DiscoCell ***)malloc(Nx * sizeof(struct DiscoCell **));
    g->Nx = Nx;
    g->Nq = Nq;

    int k,j,i,q;

    for(k=0; k<Nx; k++)
    {
        g->cells[k] = (struct DiscoCell **)malloc(Nx * sizeof(struct DiscoCell *));
        for(j=0; j<Nx; j++)
        {
            g->cells[k][j] = (struct DiscoCell *)malloc(Nx * sizeof(struct DiscoCell));
            for(i=0; i<Nx; i++)
            {
                g->cells[k][j][i].a1 = (double *)malloc(Nq * sizeof(double));
                g->cells[k][j][i].a2 = (double *)malloc(Nq * sizeof(double));
                g->cells[k][j][i].a3 = (double *)malloc(Nq * sizeof(double));
                g->cells[k][j][i].a4 = (double *)malloc(Nq * sizeof(double));
                for(q=0; q<Nq; q++)
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

double workDisco1(struct DiscoGrid *g)
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

double workDisco2(struct DiscoGrid *g)
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
void freeDiscoGrid(struct DiscoGrid *g)
{
    int i,j,k;
    int Nx = g->Nx;

    for(k=0; k<Nx; k++)
    {
        for(j=0; j<Nx; j++)
        {
            for(i=0; i<Nx; i++)
            {
                free(g->cells[k][j][i].a1);
                free(g->cells[k][j][i].a2);
                free(g->cells[k][j][i].a3);
                free(g->cells[k][j][i].a4);
            }
            free(g->cells[k][j]);
        }
        free(g->cells[k]);
    }
    free(g->cells);
    free(g);
}
