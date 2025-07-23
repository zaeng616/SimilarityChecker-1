#include <string>
#include <stdlib.h>
#include <unordered_set>
class Similiarity {
	const int MAX_LENGTH_SIMILARITY = 60;
	const int MAX_ALPHA_SIMILARITY = 40;
public:
	int GetLengthSimilarity(const std::string& a, const std::string& b) {
		if (a.length() == b.length())
			return MAX_LENGTH_SIMILARITY;
		if (a.length() > b.length() * 2 || a.length() * 2 < b.length())
			return 0;
		return calculatePartialLength(a.length(), b.length());
	}

	int GetAlphaSImilarity(const std::string& a, const std::string& b) {
		int totalCnt = getPureAlpha(a + b).length();	
		int sameCnt = 0;
		for (auto ch : getPureAlpha(a))
			if (b.find(ch) != std::string::npos)
				sameCnt++;
		return (double)sameCnt/totalCnt* MAX_ALPHA_SIMILARITY;
	}

private:
	int calculatePartialLength(int length_a, int length_b) {
		return (1 - ((double)std::abs(length_a-length_b) / std::min(length_a, length_b))) * MAX_LENGTH_SIMILARITY;
	}
	std::string getPureAlpha(const std::string& str) {
		std::string ret = "";
		std::unordered_set<char> pureCheck{};
		for (const auto ch : str)
			if (!pureCheck.count(ch)) {
				ret += ch;
				pureCheck.insert(ch);
			}
		return ret;
	}
};