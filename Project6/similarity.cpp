#include <string>
#include <stdlib.h>
class Similiarity {
	const int MAX_LENGTH_SIMILARITY = 60;
public:
	int GetLengthSimilarity(std::string a, std::string b) {
		if (a.length() == b.length())
			return MAX_LENGTH_SIMILARITY;
		if (a.length() > b.length() * 2 || a.length() * 2 < b.length())
			return 0;
		return CalculatePartialLength(a.length(), b.length());
	}
	int CalculatePartialLength(int length_a, int length_b) {
		return (1 - ((double)std::abs(length_a-length_b) / std::min(length_a, length_b))) * MAX_LENGTH_SIMILARITY;
	}

};