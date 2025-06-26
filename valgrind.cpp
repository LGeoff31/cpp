/*
Valgrind: Memory checking tool (sandbox environment emulating memory management)
Helps you find location of seg faults, leaks
Con: Slow down program execution run time
Can only test memory leaks that are made at run-time
Valgrind is dynamic memory analysis tool

Static analysis: Looking at program src to find issues
Dynamic analysis: Inspecting program's behavior at runtime

Pass -leak-check as an arg to see full details
When compiling use -g to enable debugging info, otherwise no included

Valgrind good for identifying where the issue occured, not WHY?

GDB helps identify why it occurs by helping you run through the code.
GDB also needs -g flag, allows you to step through the program and inspect values

run gdb ./myProgram
To stop program, break fnName
next - execute next line
print v - displays variable
step - step into function calls
backtrace - see list of fcn calls that got you there
up/down - navigate call stack, print variables outside current fn
set var - allows change values at runtime
display - print value variable automatically every step
undisplay - undo
watch - run program and break whenever variable modified
continue - continue running program until next breakpoint
finish - Takes end of function, then breaks
Run < test1.in - takes stdin from file
*/