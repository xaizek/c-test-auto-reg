#ifndef __TEST_H__
#define __TEST_H__

#define CAT(X, Y) CAT_(X, Y)
#define CAT_(X, Y) X##Y

#define FIXTURE() void CAT(f, TESTID)(void)

#endif // __TEST_H__
