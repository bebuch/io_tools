#ifndef _unit_test__io_tools__time_zone_offset__hpp_INCLUDED_
#define _unit_test__io_tools__time_zone_offset__hpp_INCLUDED_

#include <iomanip>
#include <sstream>
#include <string>
#include <ctime>


inline long time_zone_offset(){
	std::time_t when = std::time(nullptr);
	auto const tm = *std::localtime(&when);
	std::ostringstream os;
	os << std::put_time(&tm, "%z");
	std::string s = os.str();
	// s is in ISO 8601 format: "±HHMM"
	int h = std::stoi(s.substr(0,3), nullptr, 10);
	int m = std::stoi(s[0] + s.substr(3), nullptr, 10);

	return h * 3600 + m * 60;
}


#endif
