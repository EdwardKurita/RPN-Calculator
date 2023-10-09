#include "myMath.h"
#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

// spam functions
bool failSafe(string user);

bool failSafe2(string user);

bool failSafe3(string user);

int main() {
  // variable to prevent spamming
  bool spamProof = false;

  // count variable for stack printing
  int count = 0;

  // input and output variables
  string uIn = " ";
  myMath out;

  // allows the calculator to run indefinitely as long as the user doesn't quit
  while (uIn != "q" || uIn != "Q") {

    // original loop to print the function and take input as long as it is a
    // reasonable input.
    if (count == 0) {

      // first loop when there is nothing is in the stack. Designed so that it's
      // impossible to enter any operator
      while (!spamProof) {
        system("clear");
        cout << " _________________________\n| Operations:             "
                "|\n|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|\n| | + | | - | | * | | / | "
                "|\n|  ‾‾‾   ‾‾‾   ‾‾‾   ‾‾‾  |\n|   |sin|  |cos|  |tan|   "
                "|\n|    ‾‾‾    ‾‾‾    ‾‾‾    |\n|  |ln |  |pow |  |root|  "
                "|\n|   ‾‾‾    ‾‾‾‾    ‾‾‾‾   |"
             << endl;
        cout << "|_________________________|\n| Stack:                  "
                "|\n|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾'"
             << endl;
        for (int i = 0; i < count; i++) {
          cout << "| " << out.sPrint() << endl;
        }
        cout << "|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾'" << endl << "' ";
        getline(cin, uIn);
        spamProof = failSafe3(uIn);
      }
    } else if (count == 1) {

      // second loop when there is only one number in the stack. We only want
      // the operators that require just one number to pass (sin, cos, tan, ln,
      // root)
      while (!spamProof) {
        system("clear");
        cout << " _________________________\n| Operations:             "
                "|\n|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|\n| | + | | - | | * | | / | "
                "|\n|  ‾‾‾   ‾‾‾   ‾‾‾   ‾‾‾  |\n|   |sin|  |cos|  |tan|   "
                "|\n|    ‾‾‾    ‾‾‾    ‾‾‾    |\n|  |ln |  |pow |  |root|  "
                "|\n|   ‾‾‾    ‾‾‾‾    ‾‾‾‾   |"
             << endl;
        cout << "|_________________________|\n| Stack:                  "
                "|\n|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾'"
             << endl;
        for (int i = 0; i < count; i++) {
          cout << "| " << out.sPrint() << endl;
        }
        cout << "|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾'" << endl << "' ";
        getline(cin, uIn);
        spamProof = failSafe2(uIn);
      }
    } else {

      // loop for when there is more than one number in the stack. Allows all
      // operators
      while (!spamProof) {
        system("clear");
        cout << " _________________________\n| Operations:             "
                "|\n|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|\n| | + | | - | | * | | / | "
                "|\n|  ‾‾‾   ‾‾‾   ‾‾‾   ‾‾‾  |\n|   |sin|  |cos|  |tan|   "
                "|\n|    ‾‾‾    ‾‾‾    ‾‾‾    |\n|  |ln |  |pow |  |root|  "
                "|\n|   ‾‾‾    ‾‾‾‾    ‾‾‾‾   |"
             << endl;
        cout << "|_________________________|\n| Stack:                  "
                "|\n|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾'"
             << endl;
        for (int i = 0; i < count; i++) {
          cout << "| " << out.sPrint() << endl;
        }
        cout << "|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾'" << endl << "' ";
        getline(cin, uIn);
        spamProof = failSafe(uIn);
      }
    }
    spamProof = false;

    // calls function according to the input being a number or an operator or
    // quit. count used to print the right amount of numbers from the stack.
    if (uIn == "+") {
      count--;
      out.add();
    } else if (uIn == "-") {
      count--;
      out.subtract();
    } else if (uIn == "*") {
      count--;
      out.multiply();
    } else if (uIn == "/") {
      count--;
      out.divide();
    } else if (uIn == "sin") {
      out.sine();
    } else if (uIn == "cos") {
      out.cosine();
    } else if (uIn == "tan") {
      out.tangent();
    } else if (uIn == "ln") {
      out.logarithm();
    } else if (uIn == "pow") {
      count--;
      out.power();
    } else if (uIn == "root") {
      out.root();
    } else if (uIn == "q" || uIn == "Q") {
      break;
    } else {
      count++;
      out.push(stof(uIn));
    }
  }
  return 0;
}

// spam proofing functions - prevent the user from saying things other than
// legal operators and operands.
// Allows for mistypes after the operand/operator i.e. "5df" is allowed. pushes
// "5" not necessary for the functionality of the calculator - just for ease of
// use.

bool failSafe(string user) {
  string allow[22] = {"1",   "2",  "3",   "4",    "5", "6", "7",   "8",
                      "9",   "0",  "+",   "-",    "*", "/", "sin", "cos",
                      "tan", "ln", "pow", "root", "Q", "q"};
  for (int i = 0; i < 22; i++) {
    int finder = user.find(allow[i]);
    if (finder == 0) {
      return true;
    }
  }
  return false;
}

bool failSafe2(string user) {
  string allow[17] = {"1", "2",   "3",   "4",   "5",  "6",    "7", "8", "9",
                      "0", "sin", "cos", "tan", "ln", "root", "Q", "q"};
  for (int i = 0; i < 17; i++) {
    int finder = user.find(allow[i]);
    if (finder == 0) {
      return true;
    }
  }
  return false;
}

bool failSafe3(string user) {
  string allow[12] = {"1", "2", "3", "4", "5", "6",
                      "7", "8", "9", "0", "Q", "q"};
  for (int i = 0; i < 12; i++) {
    int finder = user.find(allow[i]);
    if (finder == 0) {
      return true;
    }
  }
  return false;
}
