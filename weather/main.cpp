#include <iostream>
#include <ctime>
#include "weather.h"

int main() {
	Weather *w = new Weather("weather.json");
	string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", 
		"Thursday", "Friday", "Saturday"}; 
	string months[] = {"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December",};
	string ending;
	time_t ts_now = time(0);
	time_t ts_next = w->get_next_forecast_time();
	tm* time_now = localtime(&ts_now);
	tm* time_next = localtime(&ts_next);

	if (time_now->tm_mday == 1 || time_now->tm_mday == 21 || time_now->tm_mday == 31) {
		ending = "st";
	} else if (time_now->tm_mday == 2 || time_now->tm_mday == 22) {
		ending = "nd";
	} else if (time_now->tm_mday == 3 || time_now->tm_mday == 23) {
		ending = "rd";
	} else {
		ending = "th";
	}

	cout << "Today is " << days[time_now->tm_wday] << ", the ";
	cout << time_now->tm_mday << ending <<" of " << months[time_now->tm_mon] << endl;

	cout << "Temperature: " << w->get_temperature() << "C." << endl;
	cout << "Weather: " << w->get_weather() << "." << endl;
	return 0;
}
