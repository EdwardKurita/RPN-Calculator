#ifndef myMath_h
#define myMath_h
#include "stack.h"

//math class - contains all math method declarations

class myMath : public stack{
  public:
    void add();
    void subtract();
    void multiply();
    void divide();
    void sine();
    void cosine();
    void tangent();
    void logarithm();
    void power();
    void root();
};

#endif
