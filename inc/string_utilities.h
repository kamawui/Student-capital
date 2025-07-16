#ifndef STRING_UTILITIES_H
#define STRING_UTILITIES_H

#include <string>

// trim from the start
inline void ltrim(std::string& s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
		return !std::isspace(ch);
		}));
}

// trim from the end (in place)
inline void rtrim(std::string& s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
		return !std::isspace(ch);
		}).base(), s.end());
}

inline void trim(std::string& s) {
	rtrim(s);
	ltrim(s);
}

#endif 


