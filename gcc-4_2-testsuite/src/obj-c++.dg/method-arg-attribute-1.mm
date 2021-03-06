/* APPLE LOCAL file radar 4157812 */
/* Test use of __attribute__((unused)) on method arguments. */
/* { dg-options "-Wno-objc-root-class -Wmost -Wextra" } */
/* { dg-do compile { target *-*-darwin* } } */

@interface INTF
- (void) correct_use_of_unused: (void *) notice : (id)another_arg;
- (void) will_warn_unused_arg: (void *) notice : (id)warn_unused;
- (void) unused_attr_on_decl_ignored: (void *)  __attribute__((unused)) will_warn;
@end

@implementation INTF
- (void) correct_use_of_unused: (void *)  __attribute__((unused)) notice : (id) __attribute__((unused)) newarg{
}
- (void) will_warn_unused_arg: (void *) __attribute__((unused))  notice : (id)warn_unused {} /* { dg-warning "unused parameter 'warn_unused'" } */
- (void) unused_attr_on_decl_ignored: (void *)  will_warn{} /* { dg-warning "unused parameter 'will_warn'" } */
@end

