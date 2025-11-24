#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    int n, ch, element;

    cout << "-------------Welcome to Stack Data Structure----------------" << endl;
    cout << "Enter the size of the stack: ";
    cin >> n;

    do {
        cout << "---------------Stack menu---------------" << endl;
        cout << "Press 1 : PUSH" << endl;
        cout << "Press 2 : POP" << endl;
        cout << "Press 3 : DISPLAY" << endl;
        cout << "Press 4 : Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                if (s.size() >= n) {
                    cout << "Stack overflow !!" << endl;
                } else {
                    cout << "Enter the element to push: ";
                    cin >> element;
                    s.push(element);
                    cout << element << " pushed to stack" << endl;
                }
                break;
            case 2:
                if (s.empty()) {
                    cout << "Stack underflow !!" << endl;
                } else {
                    cout << s.top() << " popped successfully !!" << endl;
                    s.pop();
                }
                break;
            case 3:
                if (s.empty()) {
                    cout << "Stack is empty !!" << endl;
                } else {
                    cout << "The elements of the stack are:" << endl;
                    stack<int> temp = s;  // Create a copy to display elements
                    while (!temp.empty()) {
                        cout << temp.top() << endl;
                        temp.pop();
                    }
                }
                break;
            case 4:
                cout << "Exiting the program !! Thank you for visiting again !!" << endl;
                break;
            default:
                cout << "Invalid choice !! Try again....." << endl;
        }
    } while (ch != 4);

    return 0;
}
