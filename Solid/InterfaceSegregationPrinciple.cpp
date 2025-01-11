// Interface Segregation Principle
// Interfaces should be such that client should not implement unnecessary functions they do not need.
#include <iostream>
using namespace std;

// Interface (Abstract class in C++) for RestaurantEmployee
class RestaurantEmployee {
public:
    virtual void washDishes() = 0;  // Pure virtual function
    virtual void serveCustomers() = 0;  // Pure virtual function
    virtual void cookFood() = 0;  // Pure virtual function

    virtual ~RestaurantEmployee() {}  // Virtual Destructor
};

// Waiter class implementing the RestaurantEmployee interface
class Waiter : public RestaurantEmployee {
public:
    void washDishes() override {
        cout << "Not my job" << endl;
    }

    void serveCustomers() override {
        cout << "Is my job" << endl;
    }

    void cookFood() override {
        cout << "Not my job" << endl;
    }
};

int main() {
    // Create a Waiter object
    Waiter waiter;

    // Call methods on the Waiter object
    waiter.washDishes();  // Outputs: Not my job
    waiter.serveCustomers();  // Outputs: Is my job
    waiter.cookFood();  // Outputs: Not my job

    return 0;
}
//Output
Not my job
Is my job
Not my job



// Waiter class has to override methods which are irrelevant to the class. We need to build
// interfaces in such a way that it can be segmented well into smaller and required methods.

#include <iostream>
using namespace std;

// Abstract class representing WaiterInterface
class WaiterInterface {
public:
    virtual void serveCustomers() = 0;  // Pure virtual function
    virtual void takeOrder() = 0;  // Pure virtual function

    virtual ~WaiterInterface() {}  // Virtual destructor
};

// Abstract class representing ChefInterface
class ChefInterface {
public:
    virtual void cookFood() = 0;  // Pure virtual function
    virtual void decideMenu() = 0;  // Pure virtual function

    virtual ~ChefInterface() {}  // Virtual destructor
};

// Class implementing WaiterInterface
class Waiter : public WaiterInterface {
public:
    void serveCustomers() override {
        cout << "Serving customers" << endl;
    }

    void takeOrder() override {
        cout << "Taking order" << endl;
    }
};

// Class implementing ChefInterface
class Chef : public ChefInterface {
public:
    void cookFood() override {
        cout << "Cooking food" << endl;
    }

    void decideMenu() override {
        cout << "Deciding menu" << endl;
    }
};

int main() {
    // Create a Waiter object
    Waiter waiter;
    waiter.serveCustomers();  // Outputs: Serving customers
    waiter.takeOrder();  // Outputs: Taking order

    // Create a Chef object
    Chef chef;
    chef.cookFood();  // Outputs: Cooking food
    chef.decideMenu();  // Outputs: Deciding menu

    return 0;
}

//output
Serving customers
Taking order
Cooking food
Deciding menu


