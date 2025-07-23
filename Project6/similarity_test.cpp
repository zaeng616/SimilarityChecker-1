#include <iostream>
#include "gmock/gmock.h"
#include "similarity.cpp"
TEST(SimilarityTest, TestLength) {
	Similiarity s;
	EXPECT_EQ(60, s.GetLengthSimilarity("ASD", "DSA"));
}
int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}