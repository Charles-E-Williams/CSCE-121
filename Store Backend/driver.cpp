#include <iostream>
#include "Product.h"
#include "Customer.h"
#include "Store.h"

using namespace std;

int main() {
	try {
       // Customer cust(1234,""); //caught
       //Product p(1234,""); caight 

    //    Product prod(54321, "Autobiography of Robert Lightfoot");

    //    cout << "Product ID:" << prod.getID() << endl;
    //    cout << "Product Name: " << prod.getName() << endl; 
    //    prod.setDescription("You get to read the many adventures of Robert Lightfoot from his perspective!");
    //     cout << "Product Description: " << prod.getDescription() << endl; 

    //     prod.addShipment(5,3);

    //     cout << " "<<  prod.getInventoryCount() << " " << prod.getTotalPaid() << endl;

    //     prod.reduceInventory(1);

    //     cout << prod.getInventoryCount() << endl;
    //     cout << prod.getNumberSold() << endl;

    //     Customer C1(123,"Charles Williams", true);

    //     cout << C1.getBalance() << " " << C1.getName() << " " << C1.getID() << endl;
    //     //C1.processPayment(4.99);

        
    //     cout << C1.getBalance() << endl;

		
    //     Store store;
    //     store.addCustomer(C1.getID(), C1.getName(), C1.getCredit());
    //     //cout << store.getCustomer(C1.getID());
        
    //     store.takePayment(123,12);

    //     cout << C1.getBalance();

       // Store s;
// Store s2("Things to Buy");
// // Testing addProduct and getProduct
// s.addProduct(123,"towel");
// s.getProduct(123).setDescription("For drying.");
// s.addProduct(234,"mask");
// s.getProduct(234).setDescription("For hiding.");
// //s.addProduct(123,"random");
// //s.getProduct(555);

// cout << s.getProduct(123).getDescription() << endl;

//taken from mimir
// s.addCustomer(987,"Joe Blockhead",true);
// s.addProduct(123,"towel");
// s.takeShipment(123,200,400);
// s.takePayment(987,600);
// s.sellProduct(987,123,10);
// s.getCustomer(987).getID();
// s.getCustomer(987).getName();
// s.getCustomer(987).getCredit();
// s.getCustomer(987).getBalance();
// cout << s.getCustomer(987).getProductsPurchased();
//,"Product Name: towel\nProduct ID: 123\n\n"


// Product p(555,"Widget Gidget");
// Product p2(777,"Something nice");

// Customer c2(725,"Newt Salamander");
// c2.setCredit(true);
// c2.setName("Ole Sarge");
// c2.processPurchase(25,p);
// c2.processPurchase(15,p2);
// std::stringstream ss;
// ss << c2;

// cout << ss.str();

// Product p2(283,"Something");
// cout << p2.getPrice() << endl;

Store s; 
s.addProduct(123,"towel");
s.getProduct(123).setDescription("For drying.");
cout << s.getProduct(123).getID()<< endl;
cout << s.getProduct(123).getName()<< endl;
cout << s.getProduct(123).getInventoryCount()<< endl;
cout << s.getProduct(123).getTotalPaid()<< endl;
cout << s.getProduct(123).getNumberSold()<< endl;
cout << s.getProduct(123).getDescription()<< endl;

s.addProduct(234,"mask");
s.getProduct(234).setDescription("For hiding.");
cout << s.getProduct(234).getID()<< endl;
cout << s.getProduct(234).getName()<< endl;
cout << s.getProduct(234).getInventoryCount()<< endl;
cout << s.getProduct(234).getTotalPaid()<< endl;
cout << s.getProduct(234).getNumberSold()<< endl;
cout << s.getProduct(234).getDescription()<< endl;

s.addCustomer(987,"Joe Blockhead",true);
cout << s.getCustomer(987).getID()<< endl;
cout << s.getCustomer(987).getName()<< endl;
cout << s.getCustomer(987).getCredit()<< endl;
cout << s.getCustomer(987).getBalance()<< endl;
cout << s.getCustomer(987).getProductsPurchased() << endl;

s.addCustomer(789, "Jane Grooves");
cout << s.getCustomer(789).getID()<< endl;
cout << s.getCustomer(789).getName()<< endl;
cout << s.getCustomer(789).getCredit()<< endl;
cout << s.getCustomer(789).getBalance()<< endl;
cout << s.getCustomer(789).getProductsPurchased()<< endl;

s.takeShipment(123,200,400);
cout << s.getProduct(123).getID()<< endl;
cout << s.getProduct(123).getName()<< endl;
cout << s.getProduct(123).getInventoryCount()<< endl;
cout << s.getProduct(123).getTotalPaid()<< endl;
cout << s.getProduct(123).getNumberSold()<< endl;
cout << s.getProduct(123).getDescription()<< endl;

s.takePayment(987,600);
cout << s.getCustomer(987).getID()<< endl;
cout << s.getCustomer(987).getName()<< endl;
cout << s.getCustomer(987).getCredit()<< endl;
cout << s.getCustomer(987).getBalance()<< endl;
cout << s.getCustomer(987).getProductsPurchased() << endl;

s.sellProduct(987,123,10);

cout << "After sale: \n";
cout << s.getCustomer(987).getID()<< endl;
cout << s.getCustomer(987).getName()<< endl;
cout << s.getCustomer(987).getCredit()<< endl;
cout << s.getCustomer(987).getBalance()<< endl;
cout << s.getCustomer(987).getProductsPurchased() << endl;

cout << s.getProduct(123).getID()<< endl;
cout << s.getProduct(123).getName()<< endl;
cout << s.getProduct(123).getInventoryCount()<< endl;
cout << s.getProduct(123).getTotalPaid()<< endl;
cout << s.getProduct(123).getNumberSold()<< endl;
cout << s.getProduct(123).getDescription()<< endl << endl;

cout << s.listProducts();



	}


	catch (runtime_error& exc) {
		cout << "Exception caught: "<< exc.what() << endl;
	}
	
}