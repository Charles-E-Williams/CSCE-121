#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>
#include <sstream>

class Product {

    public:
        //Product();
        Product(int productID,std::string productName);
        int getID() const;
        std::string getName() const;
        void setName(std::string productName);
        std::string getDescription() const;
        void setDescription(std::string description);
        int getNumberSold() const;
        double getTotalPaid() const;
        int getInventoryCount() const;
        void addShipment(int shipmentQuantity, double shipmentCost);
        void reduceInventory(int purchaseQuantity);
        double getPrice() const;
//        ostream& operator << (ostream &os, const Product &prod); 


    private:
        int productID;
        std::string productName;
        int numSold;
        int inventory;
        double totalPaid;
        std::string description;

};

std::ostream& operator << (std::ostream &os, const Product &prod); 



#endif