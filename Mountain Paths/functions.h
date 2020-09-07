#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<vector>
#include<string>
/********************** 
*********************** 
**Part one Functions***
************************
************************/

std::vector<std::vector<int>> readFile(std::string filename, int row, int col);
void MinMax(const std::vector<std::vector<int>>& vect, int& min, int& max);
std::vector<std::vector<int>> shadesOfGrey(const std::vector<std::vector<int>>& mapVector, int min, int max);
bool outFile(std::string filename, const std::vector<std::vector<int>>& R, const std::vector<std::vector<int>>& G, const std::vector<std::vector<int>>& B, int row, int col);



/********************** 
*********************** 
**Part two Functions***
************************
************************/
int colorPath(const std::vector<std::vector<int> >& elevations, std::vector<std::vector<int> >& r, std::vector<std::vector<int> >& g, std::vector<std::vector<int> >& b, int color_r, int color_g,
int color_b, int start_row);
int MinPath(const std::vector<std::vector<int>>& heightMap, 
	std::vector<std::vector<int>>& r, 
	std::vector<std::vector<int>>& g, 
	std::vector<std::vector<int>>& b);
void print2D(const std::vector<std::vector<int>>& vect);

template <class T>
void print1D(const std::vector<int>& vect);

#endif
