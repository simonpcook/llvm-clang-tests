/* APPLE LOCAL file radar 3803157, 5556192 */
/* Test implementaion of attributes on methods. */
/* { dg-do compile } */

__attribute__((objc_root_class)) @interface INTF
- (int) foo1: (int)arg1 __attribute__((deprecated));

- (int) foo: (int)arg1;	

- (int) foo2: (int)arg1 __attribute__((deprecated)) __attribute__((unavailable)); /* { dg-error "" } */
@end

@implementation INTF
- (int) foo: (int)arg1  __attribute__((deprecated)){
		/* { dg-warning "method attribute may be specified" "" { target *-*-* } 14 } */
	return 10;
}
- (int) foo1: (int)arg1 {
	return 10;
}
- (int) foo2: (int)arg1 __attribute__((deprecated)) {
		/* { dg-warning "method attribute may be specified" "" { target *-*-* } 21 } */
	return 10;
}
@end

int main()
{
	INTF *p;
	[p foo1:2];	/* { dg-warning "\\'foo1:\\' is deprecated" } */
	[p foo2:2];	/* { dg-error "\\'foo2:\\' is unavailable" } */
	return [p foo:1];
}

