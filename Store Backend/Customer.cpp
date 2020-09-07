#include "Customer.h"
#include <string>
#include <sstream>
using namespace std;


Customer::Customer(int customerID, string name, bool credit) : customerID(customerID), name(name), credit(credit), balance(0){

     if (name.size() == 0) {
        throw runtime_error("No customer name");
    }
}

int Customer::getID() const {return customerID;}

string Customer::getName() const {return name;}

void Customer::setName(string name) {
     if (name.size() == 0) {
        throw runtime_error("Could not find customer name");
    }

    else this->name = name;
}

bool Customer::getCredit() const {return credit;}

void Customer::setCredit (bool hasCredit){
    credit = hasCredit;
}

double Customer::getBalance() const {return balance;}

void Customer::processPayment(double amount) {

    if (amount < 0) throw runtime_error("Amount is less than zero");
    balance += amount;

}

void Customer::processPurchase(double amount, Product product) {

    if (amount < 0 ) throw runtime_error("Amount < 0 ");


    bool purchased = true;
    if (credit) {
        balance -= amount;
    }

    else if (!credit) {
        if (balance >= amount) {
            balance -= amount;
        }
        else {
            purchased = false;
            throw runtime_error("balance >= amount is not true.");
        }
    }

    if (purchased) {
        productsPurchased.push_back(product);
    }
}

string Customer::getProductsPurchased() const{

    stringstream ss;
    for (unsigned int i = 0; i < productsPurchased.size(); i++) {
        ss << "Product Name: " << productsPurchased.at(i).getName() << endl;
        ss << "Product ID: " << productsPurchased.at(i).getID() << endl;
        ss << endl;
    }

    return ss.str();
}

ostream& operator << (ostream &os, const Customer &cust) {
    os << "Customer Name: " << cust.getName() << endl;
    os << "Customer ID: " << cust.getID() << endl;

    cust.getCredit() ?  os << "Has Credit: true" << endl 
    : os << "Has Credit: false" << endl;

    os << "Balance: " << cust.getBalance() << endl;
    os << "Products Purchased --" << endl << endl;
    os << cust.getProductsPurchased();

    return os;
}
