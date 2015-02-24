#include <gtest/gtest.h>
#include <linkedlist/linkedlist.h>

class TestUsage : public ::testing::Test {

public:

    TestUsage () {}

    virtual ~TestUsage () {}

    void SetUp(){

    }
    void TearDown(){

    }

};

TEST_F(TestUsage, count) {
    LinkedList * ll = new LinkedList();

    EXPECT_EQ(LinkedList::lCount (NULL), 0);
    EXPECT_EQ(LinkedList::lCount (ll), 1);

    delete ll;
}

TEST_F(TestUsage, siblings) {
    LinkedList * ll = new LinkedList();

    EXPECT_TRUE(ll->lPrevious() == NULL);
    EXPECT_TRUE(ll->lNext() == NULL);

    delete ll;
}

