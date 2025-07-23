#include <string>
#include <stdlib.h>
class Similiarity {
	const int MAX_LENGTH_SIMILARITY = 60;
public:
	int GetLengthSimilarity(const std::string& a, const std::string& b) {
		if (a.length() == b.length())
			return MAX_LENGTH_SIMILARITY;
		if (a.length() > b.length() * 2 || a.length() * 2 < b.length())
			return 0;
		return CalculatePartialLength(a.length(), b.length());
	}
	int GetAlphaSImilarity(const std::string& a, const std::string& b) {
		int i, j;
		int sameCnt = 0;
		for (i = 0; i < a.length(); i++) {
			for (j = 0; j < b.length(); j++) {
				if (a[i] == b[j])
					break;
			}
			if (j != b.length())
				sameCnt++;
		}
		if (sameCnt == a.length())
			return 40;
		return 0;
	}

private:
	int CalculatePartialLength(int length_a, int length_b) {
		return (1 - ((double)std::abs(length_a-length_b) / std::min(length_a, length_b))) * MAX_LENGTH_SIMILARITY;
	}
};