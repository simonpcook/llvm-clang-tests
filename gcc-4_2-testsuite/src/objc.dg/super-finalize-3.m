/* APPLE LOCAL file radar 5424473 */
/* Don't issue warning on lack of [super finalize] method call for a class method
   named +finalize. */
/* { dg-do compile { target *-*-darwin* } } */


__attribute__((objc_root_class)) @interface parent
{
  int data;
}
@end

@interface child : parent
{
}
+ finalize;

@end

@implementation child
+ finalize
{
}
@end

