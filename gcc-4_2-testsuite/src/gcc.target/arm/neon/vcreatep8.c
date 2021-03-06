/* APPLE LOCAL file v7 merge */
/* Test the `vcreatep8' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_neon_ok } */
/* { dg-options "-save-temps -O0 -mfpu=neon -mfloat-abi=softfp" } */

#include "arm_neon.h"

void test_vcreatep8 (void)
{
  poly8x8_t out_poly8x8_t;
  uint64_t arg0_uint64_t;

  out_poly8x8_t = vcreate_p8 (arg0_uint64_t);
}

/* { dg-final { cleanup-saved-temps } } */
