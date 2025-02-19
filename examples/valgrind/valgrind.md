# Valgrind

## Resources
Introduction Video:  [C++ Weekly - Ep 86 - Valgrind](https://www.youtube.com/watch?v=3l0BQs2ThTo)



User Manual with quick start guide: [Valgrind Documentation](https://valgrind.org/docs/manual/valgrind_manual.pdf)


Homepage: Valgrind: [About Valgrind](https://valgrind.org/info/)

>Note:
Valgrind uses a virtual cpu to emulate on real cpu. This can lead to significant slowdown and might not be always reasonable to use whe working on large programs.

## Example
```
# Simple usage example
# Write and compile your program as usual
# e.g g++ main.cpp # this will output ./a.out
g++ main.cpp -o a.out
valgrind ./a.out
# This shows uninitialized values and memory leaks
# Use debugging symbols i.e. compile with -g flag
g++ main.cpp -o a.out -g
valgrind ./a.out # Runs with default tool memcheck
# Same as
valgrind ./a.out --tool=memcheck 

# Memory sanitizer tool
valgrind --track-origin=yes ./a.out

# Callgrind tool
valgrind --tool=callgrind ./a.out
# Gives you call track stack trace of program
# Also useful gives number of executed instructions on CPU
# Gives output callgrind.out.pid_number file
# Use linux GUI tool kcachegrind to view the callgrind.out.pid_number file  
kcachegrind callgrind.out.pid_number
# This tool can show you the dynamically loaded libraries as well as number of times called.
```