// Liskov Substitution Principle
// If class B is a sub-class of class A, then we should be able to replace object A with
// object B without breaking the behavior of the program. Sub class should extend the
  // capability of the parent class and not narrow it down.
#include <iostream>
using namespace std;

class Bike {
public:
    void turnOnEngine() {
        // Default behavior
    }

    void accelerate() {
        // Default behavior
    }
};

class Motorcycle : public Bike {
private:
    bool isEngineOn;
    int speed;

public:
    Motorcycle() {
        isEngineOn = false;
        speed = 0;
    }

    void turnOnEngine() {
        isEngineOn = true;
        cout << "Motorcycle engine turned on." << endl;
    }

    void accelerate() {
        speed += 10;
        cout << "Motorcycle speed: " << speed << " km/h" << endl;
    }
};

class Bicycle : public Bike {
public:
    void turnOnEngine() {
        cout << "Bicycle does not have an engine." << endl;
    }

    void accelerate() {
        cout << "Bicycle is pedaling." << endl;
    }
};

int main() {
    Motorcycle motorcycle;  // Create Motorcycle object
    motorcycle.turnOnEngine();  // Turn on engine
    motorcycle.accelerate();  // Accelerate motorcycle

    Bicycle bicycle;  // Create Bicycle object
    bicycle.turnOnEngine();  // Try turning on engine (not applicable)
    bicycle.accelerate();  // Pedal the bicycle

    return 0;
}


//OUTPUT

Motorcycle engine turned on.
Motorcycle speed: 10 km/h
Bicycle does not have an engine.
Bicycle is pedaling.


// In the above example Bike interface is implemented by both Motorcycle and Bicycle classes,
//  while we can easily replace Bike with Motorcycle we can not replace Bike with Bicycle 
//  because it will throw an exception. Therefore we need to design interfaces in such
//   a way that there are no unnecessary classes.



// Example 2
#include <iostream>
using namespace std;

class Vehicle {
public:
    int getNumberOfWheels() {
        return 2;  // Default to 2 wheels
    }

    bool hasEngine() {
        return true;  // Default to having an engine
    }
};

class Motorcycle : public Vehicle {
    // Inherit getNumberOfWheels and hasEngine from Vehicle
};

class Car : public Vehicle {
public:
    int getNumberOfWheels() {
        return 4;  // Override to 4 wheels for a car
    }
};

class Bicycle : public Vehicle {
public:
    bool hasEngine() {
        return false;  // Bicycles don't have engines
    }
};

int main() {
    // Create vehicle objects directly
    Motorcycle motorcycle;
    Car car;
    Bicycle bicycle;

    // Print whether each vehicle has an engine
    cout << (motorcycle.hasEngine() ? "true" : "false") << endl;
    cout << (car.hasEngine() ? "true" : "false") << endl;
    cout << (bicycle.hasEngine() ? "true" : "false") << endl;

    return 0;
}

//OUTPUT
true
true
false




//solution   //genric part only in parent component
#include <iostream>
#include <vector>
using namespace std;

class Vehicle {
public:
    virtual int getNumberOfWheels() {
        return 2;  // Default to 2 wheels for a vehicle
    }

    virtual bool hasEngine() {
        return false;  // Default to no engine for a vehicle
    }

    virtual ~Vehicle() {}  // Virtual destructor to handle cleanup in derived classes
};

class Bicycle : public Vehicle {
public:
    bool hasEngine() override {
        return false;  // Bicycle doesn't have an engine
    }
};

class EngineVehicle : public Vehicle {
public:
    bool hasEngine() override {
        return true;  // EngineVehicles have engines
    }
};

class Motorcycle : public EngineVehicle {
    // Inherits hasEngine from EngineVehicle (true) and getNumberOfWheels (defaults to 2)
};

class Car : public EngineVehicle {
public:
    int getNumberOfWheels() override {
        return 4;  // Override to 4 wheels for a car
    }
};

int main() {
    // Create a vector of Vehicle pointers
    vector<Vehicle*> vehicleList;

    // Add different vehicle objects to the list
    vehicleList.push_back(new Motorcycle());
    vehicleList.push_back(new Car());
    vehicleList.push_back(new Bicycle());

    // Iterate over the list and print whether each vehicle has an engine
    for (Vehicle* vehicle : vehicleList) {
        cout << (vehicle->hasEngine() ? "true" : "false") << endl;
    }

    // Clean up the memory by deleting the allocated objects
    for (Vehicle* vehicle : vehicleList) {
        delete vehicle;
    }

    return 0;
}


//OUTPUT

true
true
false
