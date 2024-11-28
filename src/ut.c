#include "unity.h"
#include "./hello/hello.h"
#include <unistd.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_unity(void)
{
    TEST_ASSERT_TRUE(1);
    TEST_ASSERT_FALSE(0);
}

void test_hello(void)
{
    int _stdout = dup(1);
    freopen("/dev/null", "w", stdout); // or "nul" instead of "/dev/null"
    fclose(stdout);
    TEST_ASSERT_TRUE(hello());
    stdout = fdopen(_stdout, "w");
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_unity);
    RUN_TEST(test_hello);
    return UNITY_END();
}
