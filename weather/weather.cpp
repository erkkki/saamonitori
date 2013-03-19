#include "weather.h"
#include <ctime>
#include <cstdlib>

Weather::Weather(string file_loc) {
	pos = 0;

	this->file_loc = file_loc;
	this->json_file.open(this->file_loc.c_str());
	string buffer;
	if (this->json_file.is_open()) {
		while(!this->json_file.eof()) {
			this->json_file >> buffer;
			this->str += buffer;
		}
	}
	this->json_file.close();

	find_current_forecast();
	find_temperature();
	find_weather_main();
}

void Weather::find_current_forecast() {
	string str_date;
	time_t t = time(0);
	do {
		pos = str.find("\"dt\"", pos+1);
		if (pos == -1) {
			cout << "Something has failed" << endl;
			break;
		}
		str_date = str.substr(pos+5, 10);
		next_forecast_time = atoi(str_date.c_str());
	} while (t > next_forecast_time);
}

void Weather::find_temperature() {
	pos = str.find("\"temp\"", pos);
	int temp_pos = str.find(",", pos);
	temperature = str.substr(pos+7, temp_pos - (pos+7));
}

void Weather::find_weather_main() {
	pos = str.find("\"main\"", pos);
	int temp_pos = str.find(",", pos);
	weather = str.substr(pos+8, temp_pos - 1 - (pos+8)); // weather - main has quatation marks, need to get rid of them by going  
}

string Weather::get_temperature() {
	return temperature;
}

string Weather::get_weather() {
	return weather;
}

time_t Weather::get_next_forecast_time() {
	return next_forecast_time;
}


