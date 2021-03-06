/* APPLE LOCAL file 4492976 */
/* Test if constant CFStrings get placed in the correct section.  */

/* { dg-options "-mmacosx-version-min=10.5 -fconstant-cfstrings -m64" } */
/* { dg-do compile { target powerpc*-*-darwin* i?86*-*-darwin* } } */

typedef const struct __CFString * CFStringRef;
CFStringRef appKey = (CFStringRef) @"com.apple.soundpref";

/* { dg-final { scan-assembler ".section\t__DATA,__cfstring" } } */
/* { dg-final { scan-assembler ".quad\t___CFConstantStringClassReference\n\t.long\t1992" } } */
/* { dg-final { scan-assembler ".space\t4\n\t.quad\t.*\n\t.quad\t19" } } */
