#pragma once
#include <iostream>
#include <chrono>
#include "PowerCalculator.h"
using namespace std;
using namespace chrono;
class PowerCalculator
{
public:
	long simplePowerCalculator(long long base, long long positivePower);
	long binaryPowerCalculator(long long base, long long positivePower);

};

long PowerCalculator::simplePowerCalculator(long long base, long long positivePower) {
	auto start = high_resolution_clock::now();
	int count = 0;
	long long answer = 1;
	 while (count < positivePower) {
		answer = answer * base;
		count++;
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by Simple Power function is : "
		<< duration.count() << " microseconds" << endl;
	return answer;
}

long PowerCalculator::binaryPowerCalculator(long long base, long long positivePower) {
	auto start = high_resolution_clock::now();
	long long result = 1;
	while (positivePower > 0) {
		if(positivePower & 1)
			result = result * base;
		base = base * base;
		positivePower >>= 1;
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by Binary Exponential function is : "
		<< duration.count() << " microseconds" << endl;
	return result;


}



