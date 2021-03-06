/* APPLE LOCAL file */
/* { dg-do compile { target powerpc*-*-darwin* } } */
/* Magic "bcl" to do PIC setup should be suppressed (commented) */
__attribute__((objc_root_class)) @interface Base {}
- (id)init;
@end
@interface Derived : Base {}
@end
@implementation Derived
- (id)init
{
  self = [super init];
  if (self) {}
  return self;
}
@end
/* { scan-assembler ";bcl" } */
