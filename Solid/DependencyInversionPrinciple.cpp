// Dependency Inversion Principle
// Class should depend on interfaces rather than concrete classes.

// Let’s say we have two interfaces

// KeyboardInterface is implemented by WiredKeyboard and BluetoothKeyboard classes.
// MouseInterface is implemented by WiredMouse and BluetoothMouse classes.
#include <iostream>
using namespace std;

// Class representing WiredKeyboard
class WiredKeyboard {
public:
    WiredKeyboard() {
        cout << "WiredKeyboard created." << endl;
    }

    void type() {
        cout << "Typing on WiredKeyboard." << endl;
    }
};

// Class representing WiredMouse
class WiredMouse {
public:
    WiredMouse() {
        cout << "WiredMouse created." << endl;
    }

    void click() {
        cout << "Clicking on WiredMouse." << endl;
    }
};

// Class representing MacBook
class MacBook {
private:
    WiredKeyboard keyboard;  // Member object of type WiredKeyboard
    WiredMouse mouse;        // Member object of type WiredMouse

public:
    // Constructor that creates a MacBook with a keyboard and mouse
    MacBook() {
        // The constructor of the MacBook class will automatically create the keyboard and mouse
        cout << "MacBook created." << endl;
    }

    // Methods to use the keyboard and mouse
    void useKeyboard() {
        keyboard.type();
    }

    void useMouse() {
        mouse.click();
    }
};

int main() {
    // Creating a MacBook object
    MacBook macbook;

    // Using the keyboard and mouse
    macbook.useKeyboard();  // Outputs: Typing on WiredKeyboard.
    macbook.useMouse();     // Outputs: Clicking on WiredMouse.

    return 0;
}

//Output
WiredKeyboard created.
WiredMouse created.
MacBook created.
Typing on WiredKeyboard.
Clicking on WiredMouse.


// With above implementation, we are depending on concrete classes and if we were to change
// the wired implementation to bluetooth in future we will have to change the MacBook
 // class code. This is not an ideal way of implementing if interfaces are being used.
#include <iostream>
using namespace std;

// Class representing Keyboard
class Keyboard {
public:
    void type() {
        cout << "Typing on Keyboard." << endl;
    }
};

// Class representing Mouse
class Mouse {
public:
    void click() {
        cout << "Clicking on Mouse." << endl;
    }
};

// Class representing MacBook
class MacBook {
private:
    Keyboard keyboard;  // Member object of type Keyboard
    Mouse mouse;        // Member object of type Mouse

public:
    // Constructor that accepts keyboard and mouse objects
    MacBook(Keyboard kb, Mouse ms) {
        keyboard = kb;  // Initialize keyboard with the passed object
        mouse = ms;     // Initialize mouse with the passed object
        cout << "MacBook created with a Keyboard and Mouse." << endl;
    }

    // Methods to use the keyboard and mouse
    void useKeyboard() {
        keyboard.type();
    }

    void useMouse() {
        mouse.click();
    }
};

int main() {
    // Create a Keyboard and Mouse object
    Keyboard myKeyboard;
    Mouse myMouse;

    // Create a MacBook object by passing the keyboard and mouse objects to the constructor
    MacBook macbook(myKeyboard, myMouse);

    // Using the keyboard and mouse
    macbook.useKeyboard();  // Outputs: Typing on Keyboard.
    macbook.useMouse();     // Outputs: Clicking on Mouse.

    return 0;
}

//output
MacBook created with a Keyboard and Mouse.
Typing on Keyboard.
Clicking on Mouse.

// Now, when this implementation is depending on the interface we can choose to send either
// a wired object or bluetooth object based on the requirement at hand without touching the
  //MacBook class.


