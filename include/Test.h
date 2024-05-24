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

int test_run(Test *test);
void test_clean(Test *test);

Test test_create(char *title, void *data, int (*evaluate)(void **));
Test* test_create_arr(int length);
void test_register(Test* arr, int index, char *title, void *data, int (*evaluate)(void **));

#endif // TEST_HEADER