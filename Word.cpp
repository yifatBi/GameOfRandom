#include "Word.h"



Word::Word():m_arr(NULL),m_size(0)
{
}

Word::Word(const Word& word):m_arr(NULL)
{
	//m_arr = NULL;
	setArr(word.m_arr);
}

Word::Word(const char * arr):m_arr(NULL)
{
	setArr(arr);
}


void Word::setArr(const char* arr)
{
	if (arr != NULL) {
		if (m_arr != NULL)
			delete[] m_arr;
		m_size = strlen(arr);
		m_arr = new char[m_size + 1];
		strcpy(m_arr, arr);//strdup
	}

}

void Word::print() const
{
	if ( m_arr !=NULL)
		cout << m_arr << endl << m_size << endl;
}

Word Word::operator+(const Word & word) const
{
	Word temp;
	//check NULLs
	temp.m_size = this->m_size + word.m_size;
	temp.m_arr = new char[temp.m_size + 1];
	strcpy(temp.m_arr, m_arr);//this
	strcat(temp.m_arr,word.m_arr);

	return temp;
}

Word& Word::operator=(const Word & other)
{
	setArr(other.m_arr);
	return *this;
}

bool Word::operator>(const Word & other) const
{
	return (strcmp(m_arr, other.m_arr) > 0);
}

bool Word::operator==(const Word & other) const
{
	return (strcmp(m_arr, other.m_arr) == 0);
}

bool Word::operator>=(const Word & other) const
{
	return (*this) > other || (*this) == other;
}

bool Word::operator!=(const Word & other) const
{
	return !((*this)==other);
}

Word & Word::operator+=(const Word & other)
{
	return ((*this) = ((*this) + other));
}

Word::~Word()
{
	if (m_arr != NULL)
		delete[] m_arr;
}


ostream& operator<<(ostream& out, const Word& word) {
	if (word.getArr() != NULL)
		out << word.getArr() << endl << word.getSize() << endl;
	return out;
}

istream& operator>>(istream& in, Word& word) {
	char buffer[MAX];
	cout << "Please enter a word" << endl;
	in >> buffer;
	word.setArr(buffer);
	cout << "Thanks" << endl;
	return in;
}