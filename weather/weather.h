#ifndef DEFINE_WEATHER_H
#define DEFINE_WEATHER_H

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class Weather {
private:
	string file_loc;
	ifstream json_file;
	string str;
	time_t next_forecast_time;
	int pos;
	string temperature;
	string weather;
public:
	Weather(string file_loc);
	void find_current_forecast();
	void find_temperature();
	void find_weather_main();
	time_t get_next_forecast_time();
	string get_temperature();
	string get_weather();
};

#endif
