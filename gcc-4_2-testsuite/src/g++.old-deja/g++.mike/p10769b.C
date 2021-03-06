// { dg-do assemble  }
// { dg-options "" }
// prms-id: 10769

#define PMF2PF(PMF) ((void (*)())(PMF)) // { dg-error "" } 

class A {
public:
  void f1a() { }
  void main();
} a;

class B {
public:
  void bf1() { }
} b;

void A::main() {
  void (B::*mPtrB)(B*);
  (*(void (*)(A*))PMF2PF(mPtrB))(&b);	// { dg-error "" } 
}

int main() {
  void (A::*mPtr)() = &A::f1a;
  (*(void (*)(A*))PMF2PF(mPtr))(&a);	// { dg-error "" } 
}
