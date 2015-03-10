#ifndef __TEST_H__
#define __TEST_H__

#define CAT(X, Y) CAT_(X, Y)
#define CAT_(X, Y) X##Y

#define FIXTURE() \
    static void fixture_body(void); \
    void (*CAT(fixture_number_, TESTID))(void) = &fixture_body; \
    static void fixture_body(void)

#endif // __TEST_H__
