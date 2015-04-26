#include <stdlib.h>

#define MAXQ 16

struct DiscoStatCell
{
    double a1[MAXQ];
    double a2[MAXQ];
    double a3[MAXQ];
    double a4[MAXQ];
};

struct DiscoStatGrid
{
    struct DiscoStatCell ***cells;
    int Nx;
    int Nq;
};

struct DiscoStatGrid* initDiscoStatGrid(int Nx, int Nq);
double workDiscoStat1(struct DiscoStatGrid *g);
double workDiscoStat2(struct DiscoStatGrid *g);
void freeDiscoStatGrid(struct DiscoStatGrid *g);
