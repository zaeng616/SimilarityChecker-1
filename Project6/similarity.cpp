#include <string>
#include <stdlib.h>
class Similiarity {
public:
	int GetLengthSimilarity(std::string a, std::string b) {
		if (a.length() == b.length())
			return 60;
	}
};