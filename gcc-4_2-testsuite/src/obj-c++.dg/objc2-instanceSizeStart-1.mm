/* APPLE LOCAL file radar 5333233  - radar 6064186 */
/* { dg-do compile { target powerpc*-*-darwin* i?86*-*-darwin* } } */
/* { dg-options "-Wno-objc-root-class -mmacosx-version-min=10.6 -m64" } */

@interface Super { id isa; } @end
@implementation Super @end

@interface SubNoIvars : Super 
@end

@implementation SubNoIvars @end

int main() { return 0; }
/* { dg-final { scan-assembler "l_OBJC_CLASS_RO_\\\$_SubNoIvars:\n\t.long\t0\n\t.long\t8\n\t.long\t8" } } */
