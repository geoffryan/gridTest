#include <stdlib.h>

struct DiscoCell
{
    double *a1;
    double *a2;
    double *a3;
    double *a4;
};

struct DiscoGrid
{
    struct DiscoCell ***cells;
    int Nx;
    int Nq;
};

struct DiscoGrid* initDiscoGrid(int Nx, int Nq);
double workDisco1(struct DiscoGrid *g);
double workDisco2(struct DiscoGrid *g);
void freeDiscoGrid(struct DiscoGrid *g);
