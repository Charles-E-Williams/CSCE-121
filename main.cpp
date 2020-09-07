#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main() {
    int row,col;
    string filename;
    vector<vector<int>> elevation;

    cout << "Enter the number of rows in the map (the height of the image to be produced): "; 
    cin >> row; 
    if (!cin) {
        cout << "Error: row is a non-integer value\n";
        exit(1); // exit program 
        }  

    if (row <= 0) {
        cout << "Error: row must be greater than 0. You entered " << row << endl;
        exit(1);
        }
    
    cout << "Enter the number of columns in the map (the width of the image to be produced): "; 
    cin >> col;
    if (!cin) {
        cout << "Error: column is a non-integer value\n";
        exit(1);
        }

    if (col <= 0) {
        cout << "Error: column must be greater than 0. You entered " << col << endl;
        exit(1);
        }

    cout << "Enter the file name: ";
    cin >> filename;

    //end of input prompts 
    ifstream inFS(filename.c_str());
    if (!inFS.is_open()) {
        cout << "Error: Could not open the file called " << "\"" << filename << "\"" << ".\n";
        exit(1); 
        }


    int numbers; 
    vector<int>temp;
    unsigned int counter = 0;
    unsigned int rho,col2;
    rho = row;
    col2 = col;
    while(inFS >> numbers) {
            temp.insert(temp.end(),numbers);

            if (temp.size() == col2) { // if at the rightmost column
                elevation.insert(elevation.end(),temp); // append the first row to the 2d elevation vector
                temp.clear(); // then delete and start over
                }

            else if (!inFS) {
                cout << "Error: read non-integer value.\n";
                exit(1);
                }
            counter++;
        }

    if (counter != rho*col2) {
        cout << "Error: Not enough (or too many) elevation values.\n";
        exit(1); 
    }


    int max,min;
    max = min = elevation.at(0).at(0);

    for (unsigned int i = 0; i < elevation.size(); i++) {
        for (unsigned int j = 0; j < elevation.at(i).size(); j++) {
            if (min > elevation.at(i).at(j)) {
                min = elevation.at(i).at(j);
            }
            if (max < elevation.at(i).at(j)) {
                max = elevation.at(i).at(j);
            }
        }
    }
    
//    for (unsigned int i = 0; i < elevation.size(); i++) {
//         for (unsigned int j = 0; j < elevation.at(i).size(); j++) {
//             cout << elevation.at(i).at(j) << " ";
//         }
//         cout << endl;
//     }cout << endl;

    vector<vector<int>> Red(elevation.size()); //needs to be initialzed with row size
    vector<vector<int>> Green(elevation.size());
    vector<vector<int>> Blue(elevation.size());
    double shade; 
    for (unsigned int i = 0; i < elevation.size(); i++) {
        for (unsigned int j = 0; j < elevation.at(i).size(); j++) {
                double numerator = elevation.at(i).at(j) - min;
                double denominator = max-min;
                shade = (numerator*255.0)/denominator;
                Red.at(i).push_back(round(shade));; 
                Blue.at(i).push_back(round(shade));
                Green.at(i).push_back(round(shade));
               //cout << "(i = " << i << " j = " << j << " ) "; 
                //cout << "(" << Red.at(i).at(j) << " " << Blue.at(i).at(j) << " " << Green.at(i).at(j) << ") "; 
        }
        //cout << endl;
    } // i corresponds to rows while j corresponds to columns

    string outputFile = filename + ".ppm"; 
    ofstream outFS(outputFile.c_str());

    if (!outFS.is_open()) {
        cout << "Error: Could not open output file\n";
        exit(1);
    }

    outFS << "P3\n";
    outFS << col << " " << row << endl;
    outFS << "255" << endl;

    for (unsigned int i = 0; i < elevation.size(); i++){
        for (unsigned int j = 0; j < elevation.at(i).size(); j++) {
            outFS << Red.at(i).at(j) << " " << Blue.at(i).at(j) << " " << Green.at(i).at(j) << " ";
            outFS << endl;
        }
    }

    return 0;
}