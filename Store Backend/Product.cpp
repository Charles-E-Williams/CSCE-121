#include "Product.h"
#include <string>
using namespace std;

Product::Product(int productID, string productName) : productID(productID), productName(productName), numSold(0), inventory(0), totalPaid(0.0){

    if (productName.size() == 0) {
        throw runtime_error("No Product Name");
    }
}

int Product::getID() const {return productID;}

string Product::getName() const {    
    return productName;
}

string Product::getDescription() const {
    return description;
}

void Product::setName(string productName) {
    if (productName.size() == 0) {
        throw runtime_error("No product name");
    }

    this-> productName = productName;
}

void Product::setDescription(string description) {

    this->description = description;
}

int Product::getNumberSold() const {return numSold;}

double Product::getTotalPaid() const {return totalPaid;}

int Product::getInventoryCount() const {return inventory;}


void Product::addShipment(int shipmentQuantity, double shipmentCost) {

    if (shipmentCost < 0) {
        throw runtime_error("Shipment cost is less than zero");
    }
    if (shipmentQuantity < 0) {
        throw runtime_error("Shipment quantity is less than zero");
    }

    inventory += shipmentQuantity;
    totalPaid += shipmentCost;

}

void Product::reduceInventory(int purchaseQuantity) {

    if (inventory - purchaseQuantity < 0) {
        throw runtime_error("Not enough inventory");
    }

    if (purchaseQuantity < 0) {
        throw runtime_error("Purchase quantity is less than zero");
    }
    

    else {
        inventory-= purchaseQuantity;
        numSold += purchaseQuantity;
    }

}


double Product::getPrice() const {
   
    //if (totalPaid == 0) throw runtime_error("Amount paid = 0");

    //if (this->inventory == 0) throw runtime_error("Inventory = 0");


    //if (numSold == 0) throw runtime_error("Numsold = 0");

    if (inventory + numSold == 0) throw runtime_error("Invalid");

    double price = (totalPaid / (inventory+numSold))*1.25;
    return price;
}


ostream& operator << (ostream &os, const Product &prod) {

    os << "Product Name: " << prod.getName() << endl;
    os << "Product ID: " << prod.getID() << endl;
    os << "Description: " << prod.getDescription() << endl;
    os << "Inventory: " << prod.getInventoryCount() << endl;
    os << "Number Sold: " << prod.getNumberSold() << endl;
    os << "Total Paid: " << prod.getTotalPaid() << endl;
    bool noError = true;

    try {
        prod.getPrice();
    }
    catch (runtime_error &e) {
        noError = false;
    }
   
    noError ? os << "Price: " << prod.getPrice() << endl: os << "Price: Unavailable" << endl;
 
    return os;
}