#include <iostream>
#include "String.h"
#include "Word.h"

using namespace std;

int main (void)
{
    String s1 = "Hope for "; // Calls the String(const char*) constructor
    String s2 = "the best";
    
    cout<<s1<<endl<<s2<<endl; // calls operator << (ostream&, const String&)
    cout<<s1+s2<<endl; // calls operator + (const String&)
    
    if (s1 < s2) // calls operator < (const String&)
        cout<<"s1 is lexicographically smaller than s2!"<<endl;
    
    String s3 = ", but prepare";
    
    cout<<s3<<endl;
    
    s1 += (s2 += s3); // calls operator += twice! (s2+=s3) comes first
    
    cout<<s1<<endl<<s2<<endl<<s3<<endl;
    const String s4 = s1;
    
    cout<<s4<<endl;
    
    for (int i = 0; i < s4.len(); ++i)
        cout<<s4[i]; // calls operator[] for const objects
    cout<<endl;
    
    // Intentionally causing an exception
    try
    {
        cout<<s4[100]; // Accessing a character that does not exist
    }
    catch (const char* err)
    {
        cout<<err<<endl;
    }
    
    s1[5] = 'F'; // calls operator[] for non-const objects
    cout<<s1<<endl;
    
    String s5 = s4; // Copy constructor
    if (s5 == s4)
        cout<<"s5 and s4 are lexicographically equal!"<<endl;
    
    String sIn;
    cout<<"Enter a string"<<endl;
    cin>>sIn; // calls operator >> (istream&,String&)
    cout<<"Given string:"<<sIn<<endl;
    Word a("Mor ");
    Word b(a);

    Word c = a + b;
    Word d;
    d = a + c;

    //a.print();
    //b.print();
    //c.print();
    //d.print();

    cout << d;
    cin >> a;
    cout << a;
    
    return 0;
}