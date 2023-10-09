#ifndef stack_h
#define stack_h

//stack class

struct NODE{
  float nums;
  NODE *next;
};

class stack{
  protected:
    //head for the first item of the list
    NODE *head;

    //top for the last item entered into the list
    NODE *top;

    //printing variable that will go through and print out the list
    NODE *print;
    
  public:
    //constructor
    stack();

    //printing method
    float sPrint();

    //pushing and popping methods
    void push(float inOper);
    float pop(); 
};

#endif
