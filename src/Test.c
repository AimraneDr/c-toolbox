#include "Test.h"

#include <stdio.h>

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