// stats.cxx : This file contains the 'main' function. Program execution begins and ends there.
//
#include "stats.h"
#include <assert.h>
#include <iostream>
namespace main_savitch_2C
{
    statistician::statistician() {
        reset();
    }

    void statistician::next(double r)
    {
        count++;
        total += r;
        if (count==1) {
                largest = r;
                tinyest = r;
            }
        else {
            if (r <= tinyest) {
                tinyest = r;
            }
            if (r >= largest) {
                largest = r;
            }
        }
   
        // if count==1, meaning it's the first number. Then r is both the largest and smallest DONE
    }

    void statistician::reset() { //DONE
        count = 0;
        total = 0;
        tinyest = 0;
        largest = 0;
    }

    int statistician::length() const { //DONe
        return count;
    }

    double statistician::sum() const { //DONe
        return total;
    }

    double statistician::mean() const { //DONe
        assert(total > 0);
        return total / count;
    }

    double statistician::maximum() const {//DONe
        assert(length () > 0);
        return largest;
    }

    double statistician::minimum() const { //DONE
        assert(length() > 0);
        return tinyest;
    }


    statistician operator +(const statistician& s1, const statistician& s2) {
        statistician s3; //not sure why this is wrong
        s3.count = s1.length() + s2.length();
        s3.total = s1.sum() + s2.sum();
        if (s1.length() == 0) {
            return s2; // good
        }
        if (s2.length() == 0) {
            return s1;//good
        }
        if (s1.largest > s2.largest) {
            s3.largest = s1.largest;
        }
        else {
            s3.largest = s2.largest;
        }
        if (s1.tinyest < s2.tinyest) {
            s3.tinyest = s1.tinyest;
        }
        else {
            s3.tinyest = s2.tinyest;
        }
       
    }
    statistician operator *(double scale, const statistician& s) {
        statistician s3;
   
        s3.count = s.length();
        s3.total = s.sum() * scale;
        if (scale < 0) {
            s3.tinyest = scale * s.maximum();
            s3.largest = scale * s.minimum();
        }
        else if (scale > 0) {
            s3.tinyest = scale * s.minimum();
            s3.largest = scale * s.maximum();
        }
        else {
            s3.tinyest = 0;
            s3.tinyest = 0;
        }
        return s3;
    
    }

    bool operator ==(const statistician& s1, const statistician& s2) {
        if (s1.length() == 0 && s2.length() == 0) {
            return true;
        }
        else if (s1.length() > 0 && s2.length() > 0) {
            if ((s1.length() == s2.length()) && (s1.sum() == s2.sum()) && (s1.mean() == s2.mean()) && (s1.minimum() == s2.minimum()) && (s1.maximum() == s2.maximum()))
                return true;
        }
        else
            return false;
       }


}
// class statistician
// {
// public:
//     ...
//         void next(double r);
//     double mean() const;
//     ...
// };
//         // CONSTRUCTOR
//         statistician();
//         // MODIFICATION MEMBER FUNCTIONS
//         void next(double r);
//         void reset();
//         // CONSTANT MEMBER FUNCTIONS
//         int length() const;
//         double sum() const;
//         double mean() const;
//         double minimum() const; 
//         double maximum() const;


//         // FRIEND FUNCTIONS
// void statistician::next(double r)
// {
//     double total = 0;
//     int 

// }
