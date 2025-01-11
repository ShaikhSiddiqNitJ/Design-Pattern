//Single Responsibility Principle
//A class should have only one reason to change.

#include <iostream>
#include <string>

class Marker {
public:
    std::string name;
    std::string color;
    int year;
    int price;

    // Simplified Constructor
    Marker(std::string name, std::string color, int year, int price) {
        this->name = name;
        this->color = color;
        this->year = year;
        this->price = price;
    }
};

class Invoice {
private:
    Marker marker;
    int quantity;

public:
    // Simplified Constructor
    Invoice(Marker marker, int quantity) {
        this->marker = marker;
        this->quantity = quantity;
    }

    // calculateTotal
    int calculateTotal() {
        return marker.price + quantity;  // Adjust logic if needed
    }

    // printInvoice
    void printInvoice() {
        std::cout << "Invoice Details:\n";
        std::cout << "Marker Name: " << marker.name << "\n";
        std::cout << "Color: " << marker.color << "\n";
        std::cout << "Year: " << marker.year << "\n";
        std::cout << "Price per unit: " << marker.price << "\n";
        std::cout << "Quantity: " << quantity << "\n";
        std::cout << "Total Price: " << calculateTotal() << "\n";
    }

    // saveToDb
    void saveToDb() {
        std::cout << "Saving invoice to the database...\n";
        // Database logic would go here
    }
};

int main() {
    // Create a Marker object
    Marker marker("Sharpie", "Blue", 2023, 50);

    // Create an Invoice object
    Invoice invoice(marker, 10);

    // Print the invoice
    invoice.printInvoice();

    // Save to database
    invoice.saveToDb();

    return 0;
}
//OUTPUT
Invoice Details:
Marker Name: Sharpie
Color: Blue
Year: 2023
Price per unit: 50
Quantity: 10
Total Price: 60
Saving invoice to the database...



// Invoice class has 3 resposibilities to calculateTotal price ,
//  print the invoice and save the invoice to DB. It has 3 reasons to change.
//   If either of the logic changes, classes change. We’ll have to refactor
//    the invoice class to provide only one responsibility to each class.
//     Invoice class below will calculateTotal, InvoiceDao will save invoice
//      to DB and InvoicePrinter will print the invoice. Each class, one responsibility.


#include <iostream>
#include <string>

class Marker {
public:
    std::string name;
    std::string color;
    int year;
    int price;

    // Simplified Constructor
    Marker(std::string name, std::string color, int year, int price) {
        this->name = name;
        this->color = color;
        this->year = year;
        this->price = price;
    }
};

class Invoice {
private:
    Marker marker;
    int quantity;

public:
    // Simplified Constructor
    Invoice(Marker marker, int quantity) {
        this->marker = marker;
        this->quantity = quantity;
    }

    // calculateTotal
    int calculateTotal() {
        return marker.price + quantity;  // Adjust logic if needed
    }

    // Getters
    Marker getMarker() {
        return marker;
    }

    int getQuantity() {
        return quantity;
    }
};

class InvoiceDao {
private:
    Invoice invoice;

public:
    // Simplified Constructor
    InvoiceDao(Invoice invoice) {
        this->invoice = invoice;
    }

    // saveToDb
    void saveToDb() {
        std::cout << "Saving invoice to the database...\n";
        std::cout << "Marker Name: " << invoice.getMarker().name << "\n";
        std::cout << "Quantity: " << invoice.getQuantity() << "\n";
        std::cout << "Saved successfully.\n";
    }
};

class InvoicePrinter {
private:
    Invoice invoice;

public:
    // Simplified Constructor
    InvoicePrinter(Invoice invoice) {
        this->invoice = invoice;
    }

    // printInvoice
    void printInvoice() {
        std::cout << "Invoice Details:\n";
        std::cout << "Marker Name: " << invoice.getMarker().name << "\n";
        std::cout << "Color: " << invoice.getMarker().color << "\n";
        std::cout << "Year: " << invoice.getMarker().year << "\n";
        std::cout << "Price per unit: " << invoice.getMarker().price << "\n";
        std::cout << "Quantity: " << invoice.getQuantity() << "\n";
        std::cout << "Total Price: " << invoice.calculateTotal() << "\n";
    }
};

int main() {
    // Create a Marker object
    Marker marker("Sharpie", "Blue", 2023, 50);

    // Create an Invoice object
    Invoice invoice(marker, 10);

    // Print the invoice using InvoicePrinter
    InvoicePrinter printer(invoice);
    printer.printInvoice();

    // Save the invoice using InvoiceDao
    InvoiceDao dao(invoice);
    dao.saveToDb();

    return 0;
}


//OUTPUT

Invoice Details:
Marker Name: Sharpie
Color: Blue
Year: 2023
Price per unit: 50
Quantity: 10
Total Price: 60
Saving invoice to the database...
Marker Name: Sharpie
Quantity: 10
Saved successfully.
