/* APPLE LOCAL file radar 4815061 */
/* Warn when derived class restrics accessors; i.e. readwrite->readonly. 
   But do not warn when it expands; i.e. readonly->readwrite. */
/* { dg-options "-fobjc-new-property -mmacosx-version-min=10.5" { target powerpc*-*-darwin* i?86*-*-darwin* } } */
/* { dg-options "-fobjc-new-property" { target arm*-*-darwin* } } */
/* { dg-do compile } */

__attribute__((objc_root_class)) @interface Mutable
@property(readwrite) int count;
@property(readwrite) int age;
@property(readonly)  int year;
@end

@interface Immutable:Mutable
@property(readonly) int count;
@property(readwrite) int age;
@property(readwrite) int year;
@end	/* { dg-warning "attribute \'readonly\' of property \'count\' restricts attribute \'readwrite\' of \'Mutable\' property in super class" } */


@protocol PMutable
@property(readwrite) int count;
@property(readwrite) int age;
@property(readonly)  int year;
@end

__attribute__((objc_root_class)) @interface AlsoImmutable <PMutable>
@property(readonly) int count;
@property(readwrite) int age;
@property(readwrite) int year;
@end	/* { dg-warning "attribute \'readonly\' of property \'count\' restricts attribute \'readwrite\' of \'PMutable\' property in protocol" } */

int main (void) {return 0;}

