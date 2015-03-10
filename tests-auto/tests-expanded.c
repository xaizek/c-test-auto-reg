#include <stdio.h>

#define STIC_ARRAY_LEN(x) (sizeof(x)/sizeof((x)[0]))

#define EVAL0(...) __VA_ARGS__
#define EVAL1(...) EVAL0 (EVAL0 (EVAL0 (__VA_ARGS__)))
#define EVAL2(...) EVAL1 (EVAL1 (EVAL1 (__VA_ARGS__)))
#define EVAL3(...) EVAL2 (EVAL2 (EVAL2 (__VA_ARGS__)))
#define EVAL4(...) EVAL3 (EVAL3 (EVAL3 (__VA_ARGS__)))
#define EVAL(...)  EVAL4 (EVAL4 (EVAL4 (__VA_ARGS__)))

#define MAP_END(...)
#define MAP_OUT

#define DELIMMAP0 , MAP0
#define DELIMMAP1 , MAP1
#define MAP_GET_END() 0, ,MAP_END 
#define MAP_NEXT0(test, d, next, ...) d ## next MAP_OUT
#define MAP_NEXT1(test, d, next) MAP_NEXT0 (test, d, next, 0)
#define MAP_NEXT(test, next)  MAP_NEXT1 (MAP_GET_END test, DELIM, next)

#define MAP0(p, x, peek, ...) p##x MAP_NEXT (peek, MAP1) (p, peek, __VA_ARGS__)
#define MAP1(p, x, peek, ...) p##x MAP_NEXT (peek, MAP0) (p, peek, __VA_ARGS__)
#define MAP(p, ...) EVAL (MAP1 (p, __VA_ARGS__, (), 0))

#define MMAP(p, f) \
MAP(p##f, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9), \
MAP(p##1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9), \
MAP(p##2, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9), \
MAP(p##3, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9), \
MAP(p##4, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9), \
MAP(p##5, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9), \
MAP(p##6, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9), \
MAP(p##7, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9), \
MAP(p##8, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9), \
MAP(p##9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9)

#define CAT(X, Y) CAT_(X, Y)
#define CAT_(X, Y) X##Y

#define CALL() \
    static void CAT(lf_impl_, __LINE__)(void); \
    static void (*CAT(lf_, __LINE__))(void) = &CAT(lf_impl_, __LINE__); \
    static void CAT(lf_impl_, __LINE__)(void)

CALL()
{
    puts("First");
}

CALL()
{
    puts("Second");
}

CALL()
{
    puts("Third");
}

typedef void (*lf)(void);
static lf MMAP(lf_,), MMAP(lf_1, 0), MMAP(lf_2, 0), MMAP(lf_3, 0),
MMAP(lf_4, 0), MMAP(lf_5, 0), MMAP(lf_6, 0), MMAP(lf_7, 0),
MMAP(lf_8, 0), MMAP(lf_9, 0);

int
main(void)
{
    lf tests[] = {
        MMAP(lf_,), MMAP(lf_1, 0), MMAP(lf_2, 0), MMAP(lf_3, 0),
        MMAP(lf_4, 0), MMAP(lf_5, 0), MMAP(lf_6, 0), MMAP(lf_7, 0),
        MMAP(lf_8, 0), MMAP(lf_9, 0),
    };

    size_t i;
    for(i = 0; i < STIC_ARRAY_LEN(tests); ++i)
    {
        if(tests[i]) tests[i]();
    }
    return 0;
}
