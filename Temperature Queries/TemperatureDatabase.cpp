#include "TemperatureDatabase.h"
#include <fstream>
#include <sstream>
using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	// Implement this function for part 1
	ifstream infs(filename.c_str());
	
	if(!infs.is_open())
		cout << "Error: Unable to open " << filename << endl;
	
	else if (infs.is_open())
	{
		string id;
		int year,month;
		double temperature;
		string contents;
		while (getline(infs,contents))
		{
			istringstream ss(contents);
			ss >> id >> year >> month >> temperature;
				
			if(ss.fail())
			 	cout << "Error: Other invalid input\n";
				
			if (year < 1800 || year > 2020) 
				cout << "Error: Invalid year " << year << endl;	
			
			if (month < 1 || month > 12)
				cout << "Error: Invalid month " << month << endl;
				
			if ((temperature < -50.0 || temperature > 50.0) && temperature != -99.99)
				cout << "Error: Invalid temperature " << temperature << endl;
					
			else if (temperature != -99.99)
				records.insert(id,year,month,temperature); 
			
			//cout << contents << endl;
			
		}
	}
	//file closes automatically	
}

// Do not modify
void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}
	dataout << records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
	//  Leave it blank for part 1

	ifstream infs(filename.c_str());

	if (!infs.is_open())
		cout << "Error: Unable to open " << filename << endl;

	else
	{
		ofstream ofs("result.dat");
		if (!ofs.is_open())
			cout << "Error: Unable to open " << filename << endl;
		
		else 
		{
			string id;
			string query;
			int start_year;
			int end_year;
			string contents;

			while(getline(infs,contents))
			{
				istringstream ss(contents);
				ss >> id >> query >> start_year >> end_year;

				if (ss.fail())
					cout << "Error: Other invalid query" << endl;

				else if (query != "AVG" && query != "MODE")
					cout << "Error: Unsupported query " << query << endl;

				else if (start_year > end_year)
					cout << "Error: Invalid range " << start_year << "-" << end_year << endl;

				else if (start_year < 1800 || end_year > 2020)
					cout << "Error: Invalid range " << start_year << "-" << end_year << endl;
			
				else if (start_year > 2020 || end_year < 1800)
					cout << "Error: Invalid range " << start_year << "-" << end_year << endl;
				
				else if (start_year <= end_year && query == "AVG")
				{
					double avg = records.getAVG(id,start_year,end_year);
					if (avg == -1.0)
						ofs << id << " " << start_year << " " << end_year << " AVG " << "unknown" << endl; 

					else 
						ofs << id << " " << start_year << " " << end_year << " AVG " << avg << endl; 
				}

				else if (start_year <= end_year && query == "MODE")
				{
					int mode = records.getMode(id,start_year,end_year);
					if (mode == -1)
						ofs << id << " " << start_year << " " << end_year << " MODE " << "unknown" << endl; 
					else
						ofs << id << " " << start_year << " " << end_year << " MODE " << mode << endl; 
				}
			}
		}
	}
}
