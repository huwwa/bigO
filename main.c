#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define NOT_FOUND -1
#define ITERATIONS_PER_ARRAY 300

#define LIST \
    X(arr1, 10000000) \
    X(arr2, 20000000) \
    X(arr3, 50000000) \
    X(arr4, 70500000) \
    X(arr5, 100000000)

int linear_search(int *arr, int key, uint32_t n)
{
    for (uint32_t i = 0; i < n; ++i)
	if (arr[i] == key)
	    return i;
    return NOT_FOUND;
}

double get_time(void)
{
    struct timespec tp;
    if (clock_gettime(CLOCK_MONOTONIC, &tp) < 0) {
	perror("clock_gettime");
	exit(EXIT_FAILURE);
    }

    return (double) tp.tv_sec + tp.tv_nsec * 1e-9;
}

int main(void)
{
    FILE *f;
    volatile int ret;
    double begin, end, avg;

    f = fopen("data.csv", "w");
    if (!f) {
        perror("fopen");
	exit(EXIT_FAILURE);
    }

    fprintf(f, "n,T(n)\n");
    srand((unsigned int)time(NULL));
#define X(arrx, n) int32_t *arrx; \
    arrx = malloc(n * sizeof(*arrx)); \
    if (!arrx) { \
        perror("malloc"); \
       exit(EXIT_FAILURE); \
    } \
    for (uint32_t i = 0; i < n; ++i) \
	arrx[i] = rand(); \
    do { \
	begin = get_time(); \
	for (uint32_t i = 0; i < ITERATIONS_PER_ARRAY; ++i) \
	    ret = linear_search(arrx, -1, n); \
	end = get_time(); \
	avg = (end - begin) / ITERATIONS_PER_ARRAY; \
	fprintf(f, "%d,%f\n", n, avg); \
    } while (0); \
    free(arrx);

    LIST;
#undef X

    fclose(f);
    return EXIT_SUCCESS;
}
