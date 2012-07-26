/* APPLE LOCAL file radar 5839123 */
/* Test assignments and comparisons involving category protocols.  */
/* Author: Nicola Pero <nicola@brainstorm.co.uk>.  */
/* { dg-do compile } */

#include <objc/objc.h>

@protocol MyProtocol
- (void) method;
@end

__attribute__((objc_root_class)) @interface MyClass
@end

@interface MyClass (Addition) <MyProtocol>
- (void) method;
@end

@interface MyOtherClass : MyClass
@end

int main()
{
  id <MyProtocol> obj_p = nil;
  MyClass *obj_cp = nil;
  MyOtherClass *obj_cp2 = nil;

  obj_cp = obj_p;  /* { dg-warning "incompatible Objective-C types assigning \\'id\\', expected \\'struct MyClass \\*\\'" } */
  obj_cp2 = obj_p; /* { dg-warning "incompatible Objective-C types assigning \\'id\\', expected \\'struct MyOtherClass \\*\\'" } */
  obj_p = obj_cp;  /* Ok */
  obj_p = obj_cp2; /* Ok */

  if (obj_cp == obj_p) ; /* Ok */
  if (obj_cp2 == obj_p) ; /* Ok */
  if (obj_p == obj_cp) ; /* Ok */
  if (obj_p == obj_cp2) ; /* Ok */

  return 0;
}
