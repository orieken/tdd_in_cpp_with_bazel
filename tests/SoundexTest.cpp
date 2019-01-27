#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "src/Soundex/Soundex.h"

using ::testing::Eq;
using ::testing::StartsWith;

class SoundexEncoding : public testing::Test {
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, UppercasesFirstLetter) {
ASSERT_THAT(soundex.encode("abcd"), StartsWith("A"));
}

TEST_F(SoundexEncoding, ReplacesConstantsWithAppropriateDigits) {
EXPECT_THAT(soundex.encode("Ax"), Eq("A200"));
}

TEST_F(SoundexEncoding, IgnoresNonAplhabetics) {
ASSERT_THAT(soundex.encode("A#"), Eq("A000"));
}

TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithDigits) {
ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));
}

TEST_F(SoundexEncoding, LimitsLengthToFourCharacters) {
ASSERT_THAT(soundex.encode("Dcdld").length(), Eq(4u));
}

TEST_F(SoundexEncoding, IgnoresVowelLikeLEtters) {
ASSERT_THAT(soundex.encode("BaAeEiIoOuUhHyYcdl"), Eq("B234"));
}

TEST_F(SoundexEncoding, CombinesDuplicateEncodings) {
ASSERT_THAT(soundex.encodedDigit('b'), Eq(soundex.encodedDigit('f')));
ASSERT_THAT(soundex.encodedDigit('c'), Eq(soundex.encodedDigit('g')));
ASSERT_THAT(soundex.encodedDigit('d'), Eq(soundex.encodedDigit('t')));

ASSERT_THAT(soundex.encode("Abfcgdt"), Eq("A123"));
}