/* APPLE LOCAL file 7735196 */
/* { dg-do run { target *-*-darwin[1-2][0-9]* } } */
/* { dg-options "-fblocks" } */
/* { dg-skip-if "" { powerpc*-*-darwin* } { "-m64" } { "" } } */

#include <stdio.h>
#include <stdlib.h>

typedef struct bigbig {
   int array[512];
   char more[32];
} BigStruct_t;

BigStruct_t (^global)(void) = ^{ return *(BigStruct_t *)malloc(sizeof(struct bigbig)); };

const char * getBlockSignature(void *);
 
BigStruct_t foo(int param) {
   BigStruct_t x;
   BigStruct_t (^f)(int) = ^(int param) {
     BigStruct_t *result = malloc(sizeof(BigStruct_t));
     result->array[23] = param;
     return *result;
   };
   getBlockSignature(f);
   return x;
}

enum {
    BLOCK_HAS_COPY_DISPOSE =  (1 << 25),
    BLOCK_HAS_CXX_OBJ =       (1 << 26),
    BLOCK_IS_GLOBAL =         (1 << 28),
    BLOCK_USE_STRET =    (1 << 29),
    BLOCK_HAS_OBJC_TYPE  =    (1 << 30)
};

struct block_descriptor_big {
    unsigned long int reserved;
    unsigned long int size;
    void (*copy)(void *dst, void *src); // conditional on BLOCK_HAS_COPY_DISPOSE
    void (*dispose)(void *);            // conditional on BLOCK_HAS_COPY_DISPOSE
    const char *signature;                  // conditional on BLOCK_HAS_OBJC
    const char *layout;                 // conditional on BLOCK_HAS_OBJC
};
struct block_descriptor_small {
    unsigned long int reserved;
    unsigned long int size;
    const char *signature;              // conditional on BLOCK_HAS_OBJC
    const char *layout;                 // conditional on BLOCK_HAS_OBJC
};

struct block_layout_abi { // can't change
  void *isa;
  int flags;
  int reserved; 
  void (*invoke)(void *, ...);
  struct block_descriptor_big *descriptor;
};

const char *getBlockSignature(void *block) {
   struct block_layout_abi *layout = (struct block_layout_abi *)block;
   if (layout->flags & BLOCK_HAS_COPY_DISPOSE) 
      return layout->descriptor->signature;
   else
      return ((struct block_descriptor_small *)layout->descriptor)->signature;
}

int usesStruct(void *block) {
   struct block_layout_abi *layout = (struct block_layout_abi *)block;
   int want = BLOCK_USE_STRET;
   return (layout->flags & want) == want;
}
    
   
int main(int argc, char *argv[]) {
   printf("desired global flags: %d\n", BLOCK_USE_STRET | BLOCK_IS_GLOBAL  );
   printf("desired stack flags: %d\n",  BLOCK_USE_STRET );
   
   if (!usesStruct(global))
     return 1;
   BigStruct_t x;
   BigStruct_t (^local)(int) = ^(int param) {
     BigStruct_t *result = (BigStruct_t *)malloc(sizeof(BigStruct_t));
     result->array[23] = argc;
     return *result;
   };
   if (!usesStruct(global))
     return 1;
   if (usesStruct(^void(int x){ }))
     return 1;
   return 0;
}
