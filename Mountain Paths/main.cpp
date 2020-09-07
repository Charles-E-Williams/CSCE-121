#include <iostream>
#include <vector>
#include <string>
#include "functions.h"

using namespace std;

int main() {

    int row,col;
    string filename;

    cout << "Enter the number of rows in the map (the height of the image to be produced): "; 
    cin >> row; 
    if (!cin.good()) {
        cout << "Error: row is a non-integer value\n";
        exit(1); // exit program 
        }  

    if (row <= 0) {
        cout << "Error: row must be greater than 0. You entered " << row << "." << endl;
        exit(1);
        }
    
    cout << "Enter the number of columns in the map (the width of the image to be produced): "; 
    cin >> col;
    if (!cin.good()) {
        cout << "Error: column is a non-integer value\n";
        exit(1);
        }

    if (col <= 0) {
        cout << "Error: column must be greater than 0. You entered " << col << "." << endl;
        exit(1);
        }

    cout << "Enter the file name: ";
    cin >> filename;
    
    /*read data in the elevation file and store it in the vector*/
    vector<vector<int>> values = readFile(filename,row,col);

    cout << endl << "Analyzing and computing map data...\n";

    //    for (unsigned int i = 0; i < values.size(); i++) {
    //     for (unsigned int j = 0; j < values.at(i).size(); j++) {
    //         cout << values.at(i).at(j) << " ";
    //     }
    //     cout << endl;
    // }cout << endl;

    /* finds min/max at once by passing by reference*/
    int min,max;
    MinMax(values,min,max);

    vector<vector<int>> Red(values.size());
    vector<vector<int>> Green(values.size());
    vector<vector<int>> Blue(values.size());

    Red = Blue = Green = shadesOfGrey(values,min,max);


    int index = MinPath(values,Red,Green,Blue);
    colorPath(values,Red,Green,Blue,31,253,13,index);


    /* create the ppm file*/
    string outputFile = filename + ".ppm"; 
    if (outFile(outputFile,Red,Green,Blue,row,col)) {
        cout << endl << outputFile << " has been created in your directory!\n";
     }

    return 0;

}
