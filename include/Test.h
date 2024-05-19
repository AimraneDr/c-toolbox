#ifndef TEST_HEADER
#define TEST_HEADER

typedef struct Test {
    char* title;
    void** data;
    int (*evaluate) (void** data);
    struct Test* subTests;
    int subTestsCount;
    int passOrFail;
}Test;

int test_run(Test* test);
Test create_test(char *title, void *data, int (*evaluate)(void **));

#endif // TEST_HEADER