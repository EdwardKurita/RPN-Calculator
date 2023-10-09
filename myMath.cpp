#include "stack.h"
#include "myMath.h"
#include <math.h>

//math methods - inverse methods used in order to reduce the amount of
//buffer variables.
void myMath::add(){
  push(pop() + pop());
}

void myMath::subtract(){
  push(-pop() + pop());
}

void myMath::multiply(){
  push(pop() * pop());
}

void myMath::divide(){
  push(pow(pop(),-1) * pop());
}

void myMath::sine(){
  push(sin(pop()));
}

void myMath::cosine(){
  push(cos(pop()));
}

void myMath::tangent(){
  push(tan(pop()));
}

//natural log
void myMath::logarithm(){
  push(log(pop()));
}

//sets the most recent number entered to be the power to,
//and the number before it as the base. IE.:  4 5 pow = 4 to the power 5
void myMath::power(){
  float buff = pop();
  push(pow(pop(), buff));
}

void myMath::root(){
  push(sqrt(pop()));
}
