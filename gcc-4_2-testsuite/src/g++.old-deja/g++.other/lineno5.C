// { dg-do assemble  }
// 
// Copyright (C) 2001 Free Software Foundation, Inc.
// Contributed by Nathan Sidwell 25 Jul 2001 <nathan@codesourcery.com>

// Origin: johanb@DoCS.UU.SE
// Bug 3621. At the end of saved input, we'd set the lineno to
// zero. This would confusing things no end, if there was a subsequent
// error.

namespace tmp {
  typedef int B;
  B b; // { dg-warning "" }
}

class A {
  public:
  int kaka(tmp::B = b);		// { dg-error "" } no b in scope
};
