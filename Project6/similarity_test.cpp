#include <iostream>
#include "gmock/gmock.h"
#include "similarity.cpp"
TEST(SimilarityTest, TestLength) {
	Similiarity s;
	EXPECT_EQ(60, s.GetLengthSimilarity("ASD", "DSA"));
}
TEST(SimiliarityTest, TestLengthFail) {
	Similiarity s;
	EXPECT_EQ(0, s.GetLengthSimilarity("A", "BB"));
}
int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}