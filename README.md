*** Grid Tests ***

Simple tests to try out different ways of structuring grid-based
PDE solvers.  The concern here is not with parallelism, but data
locality, cache misses, etc.  Particularly, I'm interested in 
grids which shear, where the topolgy can change at runtime.
