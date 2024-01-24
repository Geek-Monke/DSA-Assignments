#include<iostream>
using namespace std;
// Class with a parameterless constructor
class MyClass {
public:
    // Parameterless constructor
    MyClass() {
        cout << "Parameterless constructor called" << endl;
        // Additional initialization code can be added here
    }

    // Member function to display a message
    void displayMessage() {
        cout << "Hello from MyClass!" << endl;
    }
};

int main() {
    // Creating an object of MyClass
    MyClass myObject;

    // Calling a member function of MyClass
    myObject.displayMessage();

    return 0;
}