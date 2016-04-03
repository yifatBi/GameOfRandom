#include "String.h"

#define LEN 200

String::String(const char* str)
{
    if (!str)
        throw "no NULL pointers!";
    _len = strlen(str);
    _p = new char[_len + 1];
    strcpy(_p, str);
}

// Copy constructor
String::String(const String& str) : _p(NULL)
{
    *this = str; // Calls the assignment operator on this
}

// Assignment of a String object (str) to this
String& String::operator = (const String& str)
{
    if (this != &str)
    {
        delete[] _p;
        _len = str._len;
        _p = new char[_len + 1];
        strcpy(_p, str._p);
    }
    return *this;
}

// Appending a given object (str) to this
String& String::operator += (const String& str)
{
    char* newStr = new char[_len + str._len + 1];
    strcpy(newStr, _p);
    strcat(newStr, str._p);
    delete[] _p;
    _len = _len + str._len + 1;
    _p = newStr;
    return *this;
}

String String::operator + (const String& str) const
{
    String result = *this;
    result += str; // Calls the += operator on result
    return result;
}

// returns the object at index (index) for a constant object
const char& String::operator[] (int index) const
{
    if (index >= 0 && index < _len)
        return _p[index];
    throw "Invalid index";
}

// returns the object at index (index) for a non-constant object
char& String::operator[] (int index)
{
    if (index >=0 && index < _len)
        return _p[index];
    throw "Invalid index";
}

// Compares the given String object (str) with this
bool String::operator == (const String& str) const
{
    return strcmp(_p, str._p) == 0;
}

bool String::operator != (const String& str) const
{
    return !(*this == str);
}

bool String::operator > (const String& str) const
{
    return strcmp(_p, str._p) > 0;
}

bool String::operator < (const String& str) const
{
    return *this != str && !(*this > str);
}

bool String::operator >= (const String& str) const
{
    return !(*this < str);
}

bool String::operator <= (const String& str) const
{
    return !(*this > str);
}

// Outputs the given String object into the given output-stream
ostream& operator << (ostream& out, const String& str)
{
    out<<str._p; // Must be friend of class String to directly access private members!
    return out;
}

// Reads from the given input-stream and initializes a String object (str) accordingly
istream& operator >> (istream& in, String& str)
{
    char temp[LEN];
    in>>temp;
    str = String(temp); // calls String(const char*) constructor and then calls
                        // operator = on str
    return in;
}
