#include<iostream>
#include<string>
using namespace std;

int main() {
    string s = "Hello";
    s.append(", world!");  
    
    cout << "Appended string: " << s << endl;  // Output: Hello, world!
    return 0;
}
