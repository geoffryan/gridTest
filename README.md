*** Grid Tests ***

Simple tests to try out different ways of structuring grid-based
PDE solvers.  The concern here is not with parallelism, but data
locality, cache misses, etc.  Particularly, I'm interested in 
grids which shear, where the topolgy can change at runtime.

The idea here is to run simple speed tests on data structures which
emulate the structures used in codes like [Disco] and [Jet], and to
have an easy framework for testing new ideas.
