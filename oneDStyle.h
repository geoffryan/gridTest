#include <stdlib.h>

struct OneDGrid
{
    double *a1;
    double *a2;
    double *a3;
    double *a4;
    int Nx;
    int Nt;
    int Nq;
};

struct OneDGrid* initOneDGrid(int Nx, int Nq);
double workOneD1(struct OneDGrid *g);
double workOneD2(struct OneDGrid *g);
double workOneD3(struct OneDGrid *g);
void freeOneDGrid(struct OneDGrid *g);
