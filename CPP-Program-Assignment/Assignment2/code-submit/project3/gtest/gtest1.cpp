#include <algorithm>
#include <gtest/gtest.h>
#include "graph.h"
#include "test.h"




TEST(Add, MyAdd)
{
    EXPECT_EQ(3, add(1, 2));
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
