#include <stdio.h>

/* To debug with GDB:
 * run:
 * >>> gcc -g program_name.c            <-- must compile with -g flag so that gdb debugger works properly
 * >>> gdb ./program_name               <-- no args!!!
 * (gdb) break line_number/func_name    <-- to set a breakpoint at a line or at beginning of function
 * (gdb) r [args]                       <-- now input cmdline args to program_name [run]
 * (gdb) s [count]                      <-- steps "count" statements into into lines of function
 * (gdb) n [count, default: 1]          <-- steps "count" statements over function
 *                                          (does not go into each of the lines the function executes)
 * (gdb) c                              <-- continue until next breakpoint or end of program
 * (gdb) finish                         <-- same as c but ignore breakpoints
 * (gdb) l optional_ln                  <-- list next listsize lines;
 *                                          if optional_line is given, list the lines
 *                                          centered around optional_ln. [list]
 * (gdb) p expression                   <-- print value of expression
 * set listsize n                       <-- default #lines shown by list (l) command 
 */
  
int main() {
    printf("Open this file in a text editor :P\n");
}

