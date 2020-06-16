// PROVIDED BY: Andy Zhou(your name and email address)
// azhou002@citymail.cuny.edu
// FILE: rec_fun.h

//void binary_print(ostream& outs, unsigned int n);
// Postcondition: print out the binary representation of the value of n

//void triangle(ostream& outs, unsigned int m, unsigned int n)
// Precondition: m <= n
// Postcondition: The function has printed a pattern of 2*(n-m+1) lines
// to the output stream outs. The first line contains m asterisks, the next 
// line contains m+1 asterisks, and so on up to a line with n asterisks.
// Then the pattern is repeated backwards, going n back down to m.

//double pow(double x, int n);
// Precondition: If x is zero, then n must be positive.
// Postcondition: The value returned is x raised to the power n.

//void indented_sentences(size_t m, size_t n);
// precondition: m <=n;
//postcondition: print out the above pattern by calling number from m to n
#ifndef ANDY_ZHOU_REC_FUN
#define ANDY_ZHOU_REC_FUN
#include <iostream>
#include <cstdlib> // Provides size_t
using namespace std;

class rec_fun
{
public:
    void binary_print(ostream& outs, unsigned int n);
    void triangle(ostream& outs, unsigned int m, unsigned int n);
    double pow(double x, int n);
    void indented_sentences(size_t m, size_t n);
};

#endif
