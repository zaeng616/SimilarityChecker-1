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
TEST_F(SimilarityFixture, TestLengthPartial2) {
	EXPECT_EQ(30, similarity.GetLengthSimilarity("AA", "AAE"));
}
TEST_F(SimilarityFixture, TestLengthEdgeCase) {
	EXPECT_EQ(0, similarity.GetLengthSimilarity("A", ""));
	EXPECT_EQ(0, similarity.GetLengthSimilarity("AAABB", "AA"));
}
TEST_F(SimilarityFixture, TestSameAlpha) {
	EXPECT_EQ(40, similarity.GetAlphaSImilarity("ASD", "DSA"));
	EXPECT_EQ(40, similarity.GetAlphaSImilarity("AAABB", "BA"));
}

TEST_F(SimilarityFixture, TestDifferentAlpha) {
	EXPECT_EQ(20, similarity.GetAlphaSImilarity("A", "DA"));
	EXPECT_EQ(20, similarity.GetAlphaSImilarity("AAABBD", "BAC"));
}
int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}