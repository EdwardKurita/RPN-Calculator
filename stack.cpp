#include "stack.h"
#include <math.h>

//stack method to initialize both tops
stack::stack(){
  top = NULL;
  head = NULL;
  print = NULL;
}

//pushing node:
//sets the first number to the head of the list and top of the list when the list is empty.
//when the list isn't empty, it adds to the list with the 'top' node.

void stack::push(float inOper){
	NODE *newNode = new NODE;
	newNode -> nums = inOper;
	newNode -> next = NULL;
	if (head == NULL){
		head = newNode;
		top = newNode;
	} else {
    top -> next = newNode;
    top = top -> next;
	}
}

//uses an end node to find the top of the list as a node buffer. 
//This buffer is used so we can easily find the node previous to the top.
//once we find the previous node to the top, we can store the top in a float buffer to return it
//set the top to the previous node to the top and delete the top (it has been popped)
float stack::pop(){
	NODE *endNode = new NODE;
	NODE *prevNode = new NODE;
	endNode = head;
	while (endNode -> next){
		prevNode = endNode;
		endNode = endNode -> next;
	}
  float buff = top -> nums;
	top = prevNode;
	prevNode -> next = NULL;
	delete endNode;
	return buff;
}

//printing method. Basically the same as the one without linked lists, just with linked lists
float stack::sPrint(){
  if (!print){
    print = head;
  }
  float buff2 = print -> nums;
  print = print -> next;
	return (buff2);
}
