/*
 * TemperatureData.cpp
 *
 *  Created on: Jul 18, 2020
 *      Author: Charles Williams
 */

#include "TemperatureData.h"
using namespace std;

TemperatureData::TemperatureData(): id(""), year(0),month(0),temperature(0.0) {} //initialize everything

TemperatureData::TemperatureData(std::string id, int year, int month, double temperature)
: id(id), year(year), month(month), temperature(temperature) {} //initialize everything


TemperatureData::~TemperatureData() {} // You should not need to implement this

bool TemperatureData::operator<(const TemperatureData& b) {

	if (this->id < b.id) return true;
	
	else if ((this->id == b.id) && (this->year < b.year)) return true;

	else if ((this->id == b.id) && (this->year == b.year) && (this->month <= b.month)) return true;

	else return false;
	
}

