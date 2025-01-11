// Open for extension, closed for modification.


#include <iostream>
#include <fstream>
#include <string>

class Invoice {
private:
    std::string markerName;
    int quantity;
    double pricePerUnit;

public:
    // Constructor
    Invoice(std::string markerName, int quantity, double pricePerUnit) {
        this->markerName = markerName;
        this->quantity = quantity;
        this->pricePerUnit = pricePerUnit;
    }

    // Getter for Marker Name
    std::string getMarkerName() const {
        return markerName;
    }

    // Getter for Quantity
    int getQuantity() const {
        return quantity;
    }

    // Getter for Price Per Unit
    double getPricePerUnit() const {
        return pricePerUnit;
    }

    // Calculate Total Price
    double calculateTotal() const {
        return quantity * pricePerUnit;
    }
};

class InvoiceDao {
private:
    Invoice invoice;

public:
    // Constructor
    InvoiceDao(Invoice invoice) {
        this->invoice = invoice;
    }

    // Save Invoice to DB (Simulated)
    void saveToDB() {
        std::cout << "Saving the following invoice to the database:\n";
        std::cout << "Marker Name: " << invoice.getMarkerName() << "\n";
        std::cout << "Quantity: " << invoice.getQuantity() << "\n";
        std::cout << "Price Per Unit: " << invoice.getPricePerUnit() << "\n";
        std::cout << "Total Price: " << invoice.calculateTotal() << "\n";
        // Simulate saving logic to DB
        std::cout << "Invoice saved successfully to the database!\n";
    }

    // Save Invoice to File
    void saveToFile(const std::string& filename) {
        std::ofstream outFile(filename);  // Open the file for writing

        if (outFile.is_open()) {
            outFile << "Invoice Details:\n";
            outFile << "Marker Name: " << invoice.getMarkerName() << "\n";
            outFile << "Quantity: " << invoice.getQuantity() << "\n";
            outFile << "Price Per Unit: " << invoice.getPricePerUnit() << "\n";
            outFile << "Total Price: " << invoice.calculateTotal() << "\n";

            outFile.close();  // Close the file
            std::cout << "Invoice saved successfully to the file: " << filename << "\n";
        } else {
            std::cout << "Error opening file for writing.\n";
        }
    }
};

int main() {
    // Create an Invoice object
    Invoice invoice("Sharpie Marker", 10, 15.5);

    // Create an InvoiceDao object
    InvoiceDao dao(invoice);

    // Save the Invoice to the database
    dao.saveToDB();

    // Save the Invoice to a file
    dao.saveToFile("invoice.txt");

    return 0;
}


//OUTPUT
Saving the following invoice to the database:
Marker Name: Sharpie Marker
Quantity: 10
Price Per Unit: 15.5
Total Price: 155
Invoice saved successfully to the database!
Invoice saved successfully to the file: invoice.txt


Invoice Details:
Marker Name: Sharpie Marker
Quantity: 10
Price Per Unit: 15.5
Total Price: 155




// Let’s say our InvoiceDao is tested and live, taking traffic and another requirement
 //comes to add a method to save invoice file to a file. Now, if we modify the same class,
  //it violates single responsibility and is not considered a good practice.
#include <iostream>
#include <fstream>
#include <string>

// Invoice class with basic details
class Invoice {
private:
    std::string markerName;
    int quantity;
    double pricePerUnit;

public:
    // Constructor
    Invoice(std::string markerName, int quantity, double pricePerUnit) {
        this->markerName = markerName;
        this->quantity = quantity;
        this->pricePerUnit = pricePerUnit;
    }

    // Getter for Marker Name
    std::string getMarkerName() const {
        return markerName;
    }

    // Getter for Quantity
    int getQuantity() const {
        return quantity;
    }

    // Getter for Price Per Unit
    double getPricePerUnit() const {
        return pricePerUnit;
    }

    // Calculate Total Price
    double calculateTotal() const {
        return quantity * pricePerUnit;
    }
};

// InvoiceDao Interface (Abstract Class in C++)
class InvoiceDao {
public:
    virtual void save(const Invoice& invoice) = 0;  // Pure virtual function (abstract method)
    virtual ~InvoiceDao() = default;  // Virtual destructor
};

// DatabaseInvoiceDao class implementing InvoiceDao interface
class DatabaseInvoiceDao : public InvoiceDao {
public:
    void save(const Invoice& invoice) override {
        // Simulating saving the invoice to a database
        std::cout << "Saving invoice to the database:\n";
        std::cout << "Marker Name: " << invoice.getMarkerName() << "\n";
        std::cout << "Quantity: " << invoice.getQuantity() << "\n";
        std::cout << "Price Per Unit: " << invoice.getPricePerUnit() << "\n";
        std::cout << "Total Price: " << invoice.calculateTotal() << "\n";
        std::cout << "Invoice saved to the database successfully!\n";
    }
};

// FileInvoiceDao class implementing InvoiceDao interface
class FileInvoiceDao : public InvoiceDao {
public:
    void save(const Invoice& invoice) override {
        std::ofstream outFile("invoice.txt");  // Open the file for writing

        if (outFile.is_open()) {
            outFile << "Invoice Details:\n";
            outFile << "Marker Name: " << invoice.getMarkerName() << "\n";
            outFile << "Quantity: " << invoice.getQuantity() << "\n";
            outFile << "Price Per Unit: " << invoice.getPricePerUnit() << "\n";
            outFile << "Total Price: " << invoice.calculateTotal() << "\n";

            outFile.close();  // Close the file
            std::cout << "Invoice saved to the file: invoice.txt\n";
        } else {
            std::cout << "Error opening file for writing.\n";
        }
    }
};

int main() {
    // Create an Invoice object
    Invoice invoice("Sharpie Marker", 10, 15.5);

    // Create DatabaseInvoiceDao object and save invoice to the database
    InvoiceDao* dbDao = new DatabaseInvoiceDao();
    dbDao->save(invoice);  // Save to DB

    // Create FileInvoiceDao object and save invoice to a file
    InvoiceDao* fileDao = new FileInvoiceDao();
    fileDao->save(invoice);  // Save to File

    // Clean up
    delete dbDao;
    delete fileDao;

    return 0;
}

//OUTPUT
Saving invoice to the database:
Marker Name: Sharpie Marker
Quantity: 10
Price Per Unit: 15.5
Total Price: 155
Invoice saved to the database successfully!
Invoice saved to the file: invoice.txt


Invoice Details:
Marker Name: Sharpie Marker
Quantity: 10
Price Per Unit: 15.5
Total Price: 155
