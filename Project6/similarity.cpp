#include <string>
#include <stdlib.h>
class Similiarity {
	const int MAX_LENGTH_SIMILARITY = 60;
public:
	int GetLengthSimilarity(std::string a, std::string b) {
		int short_length = a.length() > b.length() ? b.length() : a.length();
		int gap = a.length() - b.length();
		return (1 - ((double)std::abs(gap) / short_length)) * 60;
	}

};