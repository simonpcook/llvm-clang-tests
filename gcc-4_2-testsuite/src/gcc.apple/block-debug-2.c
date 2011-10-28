/* APPLE LOCAL file 5939894 */
/* Verify that the desired debugging type is generated for a pointer
   to a block.  */

/* { dg-do compile } */
/* { dg-options "-g -O0 -fblocks -dA" } */
/* { dg-final { scan-assembler "\\.Lstring11\[ \\t\]+DW_AT_name" } } */
/* { dg-final { scan-assembler "\\.Lstring11:\n\[ \\t\]*\\.ascii\[ \\t\]+\"__block_descriptor\"" } } */
/* { dg-final { scan-assembler "Lstring12\[ \\t\]+DW_AT_name" } } */
/* { dg-final { scan-assembler "Lstring12:\[ \\t\]*\n\[ \\t\]*\\.ascii.*__block_literal_generic" } } */

void (^os)();

