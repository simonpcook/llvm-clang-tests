// { dg-do assemble  }
// GROUPS passed visibility
class bottom
{
public:
  int b; // { dg-error "" } private
};
class middle : private bottom // { dg-error "" } private
{
public:
  void foo () { b; }
};
class top : public middle
{
public:
  void bar () { b; }// { dg-error "" } .*
};
