#include <iostream>
#include "gmock/gmock.h"
#include "similarity.cpp"
class SimilarityFixture: public testing::Test{
public:
	Similiarity similarity;
};
TEST_F(SimilarityFixture, TestLength) {
	EXPECT_EQ(60, similarity.GetLengthSimilarity("ASD", "DSA"));
}
TEST_F(SimilarityFixture, TestLengthFail) {
	EXPECT_EQ(0, similarity.GetLengthSimilarity("A", "BB"));
}
TEST_F(SimilarityFixture, TestLengthPartial) {
	EXPECT_EQ(20, similarity.GetLengthSimilarity("AAABB", "BAA"));
}
int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}