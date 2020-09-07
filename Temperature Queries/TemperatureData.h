/*
 * TemperatureData.h
 *
 *  Created on: Jul 17, 2020
 *      Author: Charles Williams
 */

#ifndef TEMPERATUREDATA
#define TEMPERATUREDATA
#include <string>

struct TemperatureData {
	// Put data members here
	std::string id;
	int year;
	int month;
	double temperature;

	TemperatureData();
	TemperatureData(std::string id, int year, int month, double temperature);
	virtual ~TemperatureData();
	bool operator<(const TemperatureData& b);
};

#endif /* TEMPERATUREDATA */
