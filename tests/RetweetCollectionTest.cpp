#include "gmock/gmock.h"
#include "src/RetweetCollection/RetweetCollection.h"
#include "src/Tweet/Tweet.h"

using namespace ::testing;

class ARetweetCollection: public Test {
public: RetweetCollection collection;
};

MATCHER_P(HasSize, expected, ""){
    return
    arg.size() == expected &&
    arg.isEmpty() == (0 == expected);
}

TEST_F(ARetweetCollection, IsEmptyWhenCreated) {
    ASSERT_TRUE(collection.isEmpty());
}

TEST_F(ARetweetCollection, IsNoLongerEmptyAfterTweetAdded) {
    collection.add(Tweet());

    ASSERT_FALSE(collection.isEmpty());
}

TEST_F(ARetweetCollection, HasSizeZeroWhenCreated) {
ASSERT_THAT(collection.size(), Eq(0u));
}

TEST_F(ARetweetCollection, HasSizeOfOneAfterTweetAdded) {
    collection.add(Tweet());

    ASSERT_THAT(collection.size(), Eq(1u));
}