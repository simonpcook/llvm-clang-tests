int *
x(void)
{
 register int *a asm("unknown_register");  /* { dg-error "unknown register" } */
 int *v[1] = {a};
 return v[0];
}
