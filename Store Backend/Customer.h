#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>
#include <vector>
#include "Product.h"


class Customer {


    public:
       // Customer();
        Customer(int customerID, std::string name, bool credit = false);
        int getID() const;
        std::string getName() const;
        void setName(std::string name);
        bool getCredit() const;
        void setCredit(bool hasCredit);
        double getBalance() const;
        void processPayment(double amount);
        void processPurchase(double amount, Product product);
        std::string getProductsPurchased() const;
      //  std::ostream& operator << (std::ostream &os, const Customer &cust); 


    private:
        int customerID;
        std::string name;
        bool credit;
        double balance;
        std::vector<Product> productsPurchased;

};

std::ostream& operator << (std::ostream &os, const Customer &cust); 


#endif