/* APPLE LOCAL file radar 4947014 */
/* Check that getter not called and setter once under gc */
/* { dg-options "-fobjc-gc-only -fobjc-new-property -mmacosx-version-min=10.5 -framework Foundation -Wno-empty-body" } */
/* { dg-do run { target *-*-darwin* } } */
/* { dg-require-effective-target objc_gc } */

#import <Foundation/Foundation.h>

static int count;

void objc_setProperty(id self, SEL _sel, ptrdiff_t offset, id value, BOOL atomic, BOOL shouldCopy)  {
  if (count != 0 || !shouldCopy)
    abort ();
  ++ count;
}

id objc_getProperty(id self, SEL _sel, ptrdiff_t offset, BOOL atomic) {
     abort ();
     return nil;
}


@interface HandTested : NSObject {
    id x;
}
@property(copy) id x;
@end

@implementation HandTested
@synthesize x=x;

@end

int main(int argc, char *argv[]) {
    id pool = [NSAutoreleasePool new];
    HandTested *to = [HandTested new];
    id tmp = [@"testString" mutableCopy];
    to.x = tmp;  // setter
    if (tmp == to.x) 
      ;
    if ([tmp isEqual:to.x])
      ;
    return 0;
}
