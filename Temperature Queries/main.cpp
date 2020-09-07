#include "TemperatureDatabase.h"
#include <iostream>
using namespace std;


int main(int argc, char** argv) {

	
	if (argc < 3) {
		cout << "Usage: " << argv[0] << " data_file query_file" << endl;
		return 1;
	} else {
		TemperatureDatabase database;
		database.loadData(argv[1]);
		//database.outputData(argv[1]); // comment out before submitting Part 2
		database.performQuery(argv[2]); // Will be done in Part 2
	}


	// LinkedList s;

	// s.insert("411048",2015,3,14.82);
	// s.insert("411048", 2016,4, 20.51);
	// s.insert("411048", 2015, 1, 8.58);
	// s.insert("411048",2014,2,0.5);
	// cout << s;
	// cout << endl;

	// struct TemperatureData data("411018",2015,3,14.82);
	// struct TemperatureData data2("411048",2016,4,20.51);
	// struct TemperatureData data3("410048",2015,1,8.58);

	// Node* n = new Node("411018",2015,3,14.82);
	// Node* n1 = new Node("411048",2016,4,20.51);
	// Node* n2 = new Node("410048",2015,1,8.58);

	// if (n < n2) cout << "True\n";
	// else cout << "False\n";

	// if (n2 < n) cout << "True\n";
	// else cout << "false\n";

	// if (n1 < n2) cout << "True\n";
	// else cout << "False\n";


	// if (data < data2) cout << "True\n";
	// else cout << "False\n";

	// if (data3 < data) cout << "True\n";
	// else cout << "false\n";

	// if (data2 < data3) cout << "True\n";
	// else cout << "False\n";

	// LinkedList s2;
	// s2.insert("12345",3000,12,55.6);
	// cout << s2 << endl;
	// s2 = s;
	
	// cout << s2 << endl;
	// s2.clear();
	// cout << "cleared " << endl << endl;
	// cout << s << endl << endl;

	// LinkedList s3 = s;

	// cout << s3 << endl;
	// s.clear();
	// cout << endl << s3;
	// cout << s;
	
		
}
