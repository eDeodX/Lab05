#include "formatter.h"

std::string formatter(const std::string& massage) {
	std::string res;
	res += "------------------------\n";
	res += massage + "\n";
	res += "------------------------\n";
	return res;
}