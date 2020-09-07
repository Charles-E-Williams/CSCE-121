#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include "functions.h"
using namespace std;

vector<vector<int>> readFile(string filename, int row, int col) { 

    bool read = true;
    vector<vector<int>> elevation;
    ifstream inFS(filename.c_str());

    if (!inFS.is_open()){ 
        cout << "Error: Could not open the file called " << "\"" << filename << "\"" << ".\n";
        read = false;
        exit(1); 
    }

    int numbers; 
    vector<int>temp;
    unsigned int counter = 0;
    unsigned int rho,col2;
    rho = row;
    col2 = col;
    while(inFS >> numbers) {
            temp.push_back(numbers);

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

    if (read) {
        cout << endl << filename <<" has been read successfully!\n";
    }

    return elevation;

}

void MinMax(const vector<vector<int>>& vect, int& min, int& max) {

    max = min = vect.at(0).at(0);

    for (unsigned int i = 0; i <vect.size(); i++) {
        for (unsigned int j = 0; j < vect.at(i).size(); j++) {
            if (min > vect.at(i).at(j)) 
                min = vect.at(i).at(j);
            
            if (max < vect.at(i).at(j)) 
                max = vect.at(i).at(j);
            
        }
    }
}

vector<vector<int>> shadesOfGrey(const vector<vector<int>>& mapVector, int min, int max) { 

    vector<vector<int>> RGB(mapVector.size());
    double shade; 
    for (unsigned int i = 0; i < mapVector.size(); i++) {
        for (unsigned int j = 0; j < mapVector.at(i).size(); j++) {
            double numerator = mapVector.at(i).at(j) - min;
            double denominator = max-min;
            shade = (numerator*255.0)/denominator;
            RGB.at(i).push_back(round(shade));
            //cout << "(i = " << i << " j = " << j << " ) "; 
            // cout << "(" << Red.at(i).at(j) << " " << Blue.at(i).at(j) << " " << Green.at(i).at(j) << ") "; 
        }
       // cout << endl;
    } // i corresponds to rows while j corresponds to columns

    return RGB;
}

bool outFile(string filename, const vector<vector<int>>& R, const vector<vector<int>>& G, const vector<vector<int>>& B, int row, int col) {

    ofstream outFS(filename.c_str());
    bool isOpen = true;
    if (!outFS.is_open()) {
        cout << "Error: Could not open output file for writing.\n";
        isOpen = false;
        exit(1);
    }

    outFS << "P3\n";
    outFS << col << " " << row << endl;
    outFS << "255" << endl;

    for (unsigned int i = 0; i < R.size(); i++){
        for (unsigned int j = 0; j < R.at(i).size(); j++) {
            outFS << "(" <<  R.at(i).at(j) << " " << G.at(i).at(j) << " " << B.at(i).at(j) << ") ";
        }
	    outFS << endl;
    }

    return isOpen;
}

int colorPath(
	const vector<vector<int>>& heightMap, 
	vector<vector<int>>& r, 
	vector<vector<int>>& g, 
	vector<vector<int>>& b, 
	int color_r, int color_g, int color_b, 
	int start_row) 
{
	int dist = 0;
	unsigned int row = start_row;
	//bool tie = false;
	/*initialize starting RGB values with a color value */ 
	r.at(row).at(0) = color_r; 
	g.at(row).at(0) = color_g;
 	b.at(row).at(0) = color_b;


	//col < numcolumns - 1 as to not access the last column 
	for (unsigned int col = 0; col < heightMap.at(row).size() - 1; col++) { //traverse through the columns
		//cout << row <<  " " << col << endl;
		if (row == 0) {	//if starting at the first row
			//go forward. this (should) also take care of the 'tie' requirement  
			if (abs(heightMap.at(row).at(col) - heightMap.at(row).at(col+1)) <= abs(heightMap.at(row).at(col) - heightMap.at(row+1).at(col+1)))  {
				//cout << "row\n";
				r.at(row).at(col+1) = color_r; 
				g.at(row).at(col+1) = color_g;
				b.at(row).at(col+1) = color_b;
				dist += abs(heightMap.at(row).at(col) - heightMap.at(row).at(col+1));
				}

			else { // go "southeast", one row down
				r.at(row+1).at(col+1) = color_r; 
				g.at(row+1).at(col+1) = color_g;
				b.at(row+1).at(col+1) = color_b;
				dist += abs(heightMap.at(row).at(col) - heightMap.at(row+1).at(col+1));
				row += 1;
				}
			}
		
		else if (row == heightMap.size() - 1) { //bottom row 
			//go foward, stay in the same row
			if (abs(heightMap.at(row).at(col) - heightMap.at(row).at(col+1)) <= abs(heightMap.at(row).at(col) - heightMap.at(row-1).at(col+1))) {
				r.at(row).at(col+1) = color_r; 
				g.at(row).at(col+1) = color_g;
				b.at(row).at(col+1) = color_b;
				dist += abs(heightMap.at(row).at(col) - heightMap.at(row).at(col+1)); 

			}

			else { // go "northeast" , move one row up 
				r.at(row-1).at(col+1) = color_r; 
				g.at(row-1).at(col+1) = color_g;
				b.at(row-1).at(col+1) = color_b;
				dist += abs(heightMap.at(row).at(col) - heightMap.at(row-1).at(col+1));
				row -= 1;
				}
			}

		else { // somewhere in the middle, not at the bottom or top row 

			//no tie, the NE index is strictly less than the SE index
			if (abs(heightMap.at(row).at(col) - heightMap.at(row-1).at(col+1)) < abs(heightMap.at(row).at(col) - heightMap.at(row+1).at(col+1))) {
				if (abs(heightMap.at(row).at(col) - heightMap.at(row).at(col+1)) <= abs(heightMap.at(row).at(col) - heightMap.at(row-1).at(col+1))) {
					r.at(row).at(col+1) = color_r; 
					g.at(row).at(col+1) = color_g;
					b.at(row).at(col+1) = color_b;
					dist += abs(heightMap.at(row).at(col) - heightMap.at(row).at(col+1)); //go straight 

					}

				else if (abs(heightMap.at(row).at(col) - heightMap.at(row).at(col+1)) > abs(heightMap.at(row).at(col) - heightMap.at(row-1).at(col+1))) {
					r.at(row-1).at(col+1) = color_r; 
					g.at(row-1).at(col+1) = color_g;
					b.at(row-1).at(col+1) = color_b;
					dist += abs(heightMap.at(row).at(col) - heightMap.at(row-1).at(col+1)); // go north east 
					row -= 1;

					}
				}

			//case in which there is a (potential) tie between NE and SE 
			else if (abs(heightMap.at(row).at(col) - heightMap.at(row+1).at(col+1)) <= abs(heightMap.at(row).at(col) - heightMap.at(row-1).at(col+1))) {
				if (abs(heightMap.at(row).at(col) - heightMap.at(row).at(col+1)) <= abs(heightMap.at(row).at(col) - heightMap.at(row+1).at(col+1))) {
					// go forward if less
					r.at(row).at(col+1) = color_r; 
					g.at(row).at(col+1) = color_g;
					b.at(row).at(col+1) = color_b;
					dist += abs(heightMap.at(row).at(col) - heightMap.at(row).at(col+1)); 
				}

				else if (abs(heightMap.at(row).at(col) - heightMap.at(row+1).at(col+1)) < abs(heightMap.at(row).at(col) - heightMap.at(row).at(col+1))) {
					r.at(row+1).at(col+1) = color_r; 
					g.at(row+1).at(col+1) = color_g;
					b.at(row+1).at(col+1) = color_b;
					dist += abs(heightMap.at(row).at(col) - heightMap.at(row+1).at(col+1)); 
					row += 1;
					// go SE. This (should) take care of the tie between NE and SE req.
				}
			}
		}
	}

	return dist;
}


int MinPath(const vector<vector<int>>& heightMap, 
	vector<vector<int>>& r, 
	vector<vector<int>>& g, 
	vector<vector<int>>& b) {

	int minPath = colorPath(heightMap,r,g,b,252,25,63,0);
    int index;
	
	for (unsigned int i = 0; i < heightMap.size(); i++) {
    	int comparePath = colorPath(heightMap,r,g,b,252,25,63,i);

        if (minPath == comparePath) continue;

        if (minPath > comparePath){ 
            minPath = comparePath;
            index = i;
        }
        
        
    }

	return index;
}

void print2D(const vector<vector<int>>& vect)
{
	int row = vect.size();
	int col = vect.at(0).size();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << vect.at(i).at(j) << " ";
		}
		cout << endl;
	}
}

void print1D(const vector<int>& vect)
{
	int row = vect.size();
	for (int i = 0; i < row; i++)
	{
		cout << vect.at(i) << " ";

	}
			cout << endl;

}


