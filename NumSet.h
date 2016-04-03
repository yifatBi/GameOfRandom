//
// Created by yifat biezuner on 03/04/2016.
//

#ifndef OVVERIDEOPERATORS_NUMSET_H
#define OVVERIDEOPERATORS_NUMSET_H

#include <iostream>
using namespace std;
#define NUMBERS_FOR_USER 5;

class NumSet {
private:
    int _numbers [5]{0};
public:
    NumSet();
    int _min;
    int _max;
    int _average;
    int _total;
    int _numOfFreeCells;
    const int max()const{ return _max;}
    const int min()const{ return _min;};
    const int average()const{ return _average;};
    const int freeCells()const{ return _numOfFreeCells;};
    void insert(const int num);
    void Del(const int indexToDelete);
    void replace(const int index,const int number);
    const int biggerThan(const int num)const;
    const int smallerThan(const int num)const;
    //operator overloading
    NumSet& operator+=(const NumSet& other);
    NumSet& operator+=(const int other);
    NumSet& operator++();
    NumSet& operator--();
    bool operator==(const NumSet& other) const;
    NumSet& operator=(const NumSet& other);
    NumSet& operator-(const NumSet& other);
    NumSet& operator-(const int other);
    NumSet operator+(const NumSet& other) const;
    NumSet operator+(const int other) const;
    bool operator>(const NumSet& other) const;
    bool operator>=(const NumSet& other) const;
    bool operator!=(const NumSet& other) const;
    ~NumSet();
};
    istream& operator>>(istream& in, NumSet& word);
    ostream& operator<<(ostream& out, const NumSet& word);


#endif //OVVERIDEOPERATORS_NUMSET_H
