#include "Store.h"
#include <string>
using namespace std;

Store::Store() {}

Store::Store(string name) : name(name) {

    if (name.size() == 0) throw runtime_error("No input");
}

string Store::getName() const {return name;}

void Store::setName(string name) {this->name = name;}

void Store::addProduct(int productID, string productName){

    bool isUnique = true;
    for (unsigned int i = 0; i < products.size(); i++) {
        if (productID == products.at(i).getID()) {
            isUnique = false;
            throw runtime_error("Product ID belongs to another product");
        }
    }
    if (isUnique) {
        Product newProduct(productID,productName);
        products.push_back(newProduct);
    }
}

Product& Store::getProduct(int productID) {

    bool found = false;
    int index;
    for (unsigned int i = 0; i < products.size(); i++) {
        if (productID == products.at(i).getID()) {
            found = true;
            index = i;        
            }
    }

    if (!found) {
        throw runtime_error("Product ID not found");
    }
    
    return products.at(index);
    
}


void Store::addCustomer(int customerID, string customerName, bool credit) {
    bool isUnique = true;
    for (unsigned int i = 0; i < customers.size(); i++) {
        if (customerID == customers.at(i).getID()) {
            isUnique = false;
            throw runtime_error("Customer ID belongs to another customer");
        }
    }

    if (isUnique) {
        Customer newCustomer(customerID,customerName,credit);
        customers.push_back(newCustomer);
    }

}


Customer& Store::getCustomer(int customerID) {

    int index;
    bool found = false;
    for (unsigned int i = 0; i < customers.size(); i++) {
        if (customerID == customers.at(i).getID()) {
            found = true;
            index = i;
        }
    }

    if (!found) {
        throw runtime_error("Customer ID not found");
    }

    return customers.at(index);
}


void Store::takeShipment(int productID, int quantity, double cost) {

    bool found = false;
    for (unsigned int i = 0; i < products.size(); i++) {
        if (productID == products.at(i).getID()) {
            found = true;
            products.at(i).addShipment(quantity,cost);
        }
    }


    if (!found) throw runtime_error("Product ID not found.");
}


void Store::takePayment(int customerID, double amount) {

    bool found = false;
    for (unsigned int i = 0; i < customers.size(); i++) {
        if (customerID == customers.at(i).getID()) {
            found = true;
            customers.at(i).processPayment(amount);
//            cout << "Processed\n";
        }
    }

    if (!found) throw runtime_error("Customer ID not found.");

}


void Store::sellProduct(int customerID, int productID, int quantity) {
    
    double price = getProduct(productID).getPrice() * quantity;
    Product prod = getProduct(productID);
    getCustomer(customerID).processPurchase(price,prod);
    getProduct(productID).reduceInventory(quantity);

}

string Store::listProducts() {
    stringstream ss;
    for (unsigned int i = 0; i < products.size(); i++) {
    
        ss << products.at(i) << endl;
    }

    return ss.str();
}


string Store::listCustomers(){

    stringstream ss;
    for (unsigned int i = 0; i < customers.size(); i++) {
    
        ss << customers.at(i) << endl;
    }
    
    return ss.str();


}
