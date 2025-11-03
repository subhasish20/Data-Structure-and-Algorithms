#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1 = "hello ";
    cout<<"string 1 is "<<s1<<endl;
    string s2 = "world";
    cout<<"string 2 is "<<s2<<endl;

    string concate = s1 + " "+s2;
    cout<<"concat string is :"<<concate;

    return 0;
}