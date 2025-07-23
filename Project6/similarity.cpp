#include <string>
#include <stdlib.h>
class Similiarity {
	const int MAX_LENGTH_SIMILARITY = 60;
public:
	int GetLengthSimilarity(std::string a, std::string b) {
		if (a.length() == b.length())
			return MAX_LENGTH_SIMILARITY;
		return 0;
	}

};