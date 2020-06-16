// Andy Zhou 
//azhou002@citymail.cuny.edu
//rec_fun.cxx

#include <iostream>
#include <cmath>
#include <cassert>
#include "rec_fun.h"

using namespace std;

// function 1
void binary_print(ostream& outs, unsigned int n) {
    if (n < 2) {
        outs << n;
    }
    else {
        binary_print(outs, n / 2);
        outs << (n % 2);
    }
}

// function 2
void triangle(ostream& outs, unsigned int m, unsigned int n) {
    assert(m <= n);
    if (m == n) {
        for (int i = 0; i < m; i++) {
            outs << "*";
        }
        outs << endl;
        for (int i = 0; i < m; i++) {
            outs << "*";
        }
        outs << endl;
    }
    else if (m < n) {
        for (int i = 0; i < m; i++) {
            outs << "*";
        }
        outs << endl;
        triangle(outs, m + 1, n);
        for (int i = 0; i < m; i++) {
            outs << "*";
        }
        outs << endl;
    }
}

// function 3
double pow(double x, int n) {
    if (n == 0) {
        return 1;
    }
    else if (x == 0) {
        return 0;
    }
    else if (n < 0) {
        return 1 / pow(x, -n);
    }
    else {
        int first = pow(x, n / 2);
        int second = pow(x, n / 2);
        if (n % 2 == 0) {
            return first * second;
        }
        else {
            return first * second * x;
        }
    }
}

// function 4
void indentationHelper(int m) {
    for (int i = 0; i < m - 1; i++) {
        cout << " ";
    }
}

void indented_sentences(size_t m, size_t n) {
    assert(m <= n);
    if (m == n)
    {
        indentationHelper(m);
        cout << "This was written by calling number" << m << endl;
        indentationHelper(m);
        cout << "This was ALSO written by calling number" << m << endl;
    }
    else if (m < n) {
        indentationHelper(m);
        cout << "This was written by calling number" << m << endl;
        indented_sentences(m + 1, n);
        indentationHelper(m);
        cout << "This was ALSO written by calling number" << m << endl;
    }
}
// precondition: m <=n;
//postcondition: print out the above pattern by calling number from m to n
/*
int main()
{
  cout << "n = 0\t";          //First function test
  binary_print(cout, 0);
  cout << endl;
  cout << "n = 4\t";
  binary_print(cout, 4);
  cout << endl;
  cout << "n = 27\t";
  binary_print(cout, 27);
  cout << endl;

  cout << endl;
  triangle(cout, 3, 5);       //Second function test

  cout << endl;
  triangle(cout, 0, 5);       //Second function test

  cout << endl;
  cout << "100^0 is " << pow(100, 0) << endl;     //Third function test
  cout << "2^3 is " << pow(2, 3) << endl;
  cout << "2^-3 is " << pow(2, -3) << endl;
  cout << "3^-1 is " << pow(3, -1) << endl;
  cout << "4^-2 is " << pow(4, -2) << endl;
  cout << "5^5 is " << pow(5, 5) << endl;

  cout << endl;
  indented_sentences(1, 4);    //Fourth function test
  return 0;
}
*/