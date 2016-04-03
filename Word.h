#pragma once
#include <iostream>

#define MAX 100

using namespace std;


class Word
{
	char* m_arr;
	int m_size;
public:
	Word();//Default c'tor
	Word(const Word& word);
	Word(const char* arr);
	//get set
	int getSize() const { return m_size; }
	const char* getArr() const { return m_arr; }
	void setArr(const char* arr);

	void print() const;
	//operator overloading
	Word operator+(const Word& other) const;
	Word& operator=(const Word& other);
	bool operator>(const Word& other) const;
	bool operator==(const Word& other) const;
	bool operator>=(const Word& other) const;
	bool operator!=(const Word& other) const;
	Word& operator+=(const Word& other);

	friend istream& operator>>(istream& in, Word& word);

	virtual ~Word();
};

ostream& operator<<(ostream& out, const Word& word);