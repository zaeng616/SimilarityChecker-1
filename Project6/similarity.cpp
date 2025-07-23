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
		int totalCnt = 0;
		//total cnt
		bool total_arr[26] = {};
		bool same_arr[26] = {};
		for (int i = 0; i < a.length(); i++)
			total_arr[a[i] - 'A'] = true;
		for (int i = 0; i < b.length(); i++)
			total_arr[b[i] - 'A'] = true;
		for (int i = 0; i < sizeof(total_arr) / sizeof(bool); i++)
			if (total_arr[i]) totalCnt++;
		for (i = 0; i < a.length(); i++) {
			for (j = 0; j < b.length(); j++)
				if (a[i] == b[j]) {
					same_arr[a[i] - 'A'] = true;
					break;
				}
		}
		for (int i = 0; i < sizeof(same_arr) / sizeof(bool); i++)
			if (same_arr[i]) sameCnt++;
		return (double)sameCnt/totalCnt*40;
	}

private:
	int CalculatePartialLength(int length_a, int length_b) {
		return (1 - ((double)std::abs(length_a-length_b) / std::min(length_a, length_b))) * MAX_LENGTH_SIMILARITY;
	}
};