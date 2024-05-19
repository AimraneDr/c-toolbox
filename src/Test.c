#include "Test.h"

#include <stdio.h>

/// @brief run sub tests recursivly
/// @param t
/// @param level 
/// @return

void test_title(char *msg, int level);
void test_fail(char *msg, int level);
void test_error(char *msg, int level);
void test_success(char *msg, int level);


int run_sub_test(Test *t, int level)
{
    for (int i = 0; i < t->subTestsCount; i++)
    {
        Test currentTest = t->subTests[i];
        test_title(currentTest.title, level);
        if(!currentTest.evaluate){
            run_sub_test(&currentTest, level + 1);
        }

        if (currentTest.evaluate(currentTest.data))
        {
            test_success(currentTest.title, level);
        }
        else
        {
            test_fail(t->title, level);
            if (currentTest.passOrFail)
                return 0;
        }
    }
    return 1;
}

/// @brief run the exaluate function, if not provided run sub tests
/// @param test 
/// @return 
int test_run(Test *test){
    if(!test) test_error("no test is provided", 0);

    test_title(test->title, 0);
    
    if (!test->evaluate){
        if(run_sub_test(test, 1)){
            test_success(test->title, 0);
            return 1;
        }
        test_fail(test->title, 0);
        return 0;
    }
    
    if (test->evaluate(test->data))
    {
        test_fail(test->title, 0);
        return 0;
    }
    else
    {
        test_success(test->title, 0);
    }

    return 1;
}

Test create_test(char *title, void *data, int (*evaluate)(void **))
{
    return (Test){.title = title, .data = data, .evaluate = evaluate};
}

void test_title(char *msg, int level)
{
    for (int i = 0; i < level; i++)
        printf("    ");
    printf("[TEST START] : %s\n", msg);
}

void test_fail(char *msg, int level)
{
    for (int i = 0; i < level; i++)
        printf("    ");
    printf("[FAIL] : %s\n", msg);
}

void test_success(char *msg, int level)
{
    for (int i = 0; i < level; i++)
        printf("    ");
    printf("[DONE] : %s\n", msg);
}

void test_error(char *msg, int level)
{
    for (int i = 0; i < level; i++)
        printf("    ");
    printf("[ERROR] : %s\n", msg);
}