/* PR c/5044 */
/* { dg-do compile } */
/* { dg-options "-Wswitch-enum -Wno-covered-switch-default" } */

enum e { e1, e2 };

int
foo (int i, int j, enum e ei, enum e ej, enum e ek, enum e el,
     enum e em, enum e en, enum e eo, enum e ep)
{
  switch (i)
    {
    case 1: return 1;
    case 2: return 2;
    }
  switch (j)
    {
    case 3: return 4;
    case 4: return 3;
    default: break;
    }
  switch (ei) /* { dg-warning "enumeration values 'e1' and 'e2' not handled in switch" } */
    {
    }
  switch (ej) /* { dg-warning "enumeration values 'e1' and 'e2' not explicitly handled in switch" } */
    { 
      default: break;
    }
  switch (ek) /* { dg-warning "enumeration value 'e2' not handled in switch" } */
    {
    case e1: return 1;
    }
  switch (el) /* { dg-warning "enumeration value 'e2' not explicitly handled in switch" } */
    {
    case e1: return 1;
    default: break;
    }
  switch (em)
    {
    case e1: return 1;
    case e2: return 2;
    }
  switch (en)
    {
    case e1: return 1;
    case e2: return 2;
    default: break;
    }
  switch (eo)
    {
    case e1: return 1;
    case e2: return 2;
    case 3: return 3; /* { dg-warning "case value not in enumerated type" } */
    }
  switch (ep)
    {
    case e1: return 1;
    case e2: return 2;
    case 3: return 3; /* { dg-warning "case value not in enumerated type" } */
    default: break;
    }
  return 0;
}
