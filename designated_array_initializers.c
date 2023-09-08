// Designated array initializers

#include <stdio.h>

void print_array(int * arr, int len)
{
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

#define ARRAY_SIZE(x)    (sizeof(x) / sizeof(x[0]))
#define PRINT(x)         (print_array(x, ARRAY_SIZE(x)))

int main()
{
    int values[10] = { [7] = 1, [2] = 2 };
    PRINT(values);
    // 0 0 2 0 0 0 0 1 0 0

    int values2[10] = { [4 ... 8] = 3, [1] = 4 };
    PRINT(values2);
    // 0 4 0 0 3 3 3 3 3 0

    int values3[10] = { 5 };
    PRINT(values3);
    // 5 0 0 0 0 0 0 0 0 0

    int values4[10] = { [0 ... 9] = 6 };
    PRINT(values4);
    // 6 6 6 6 6 6 6 6 6 6

    int values5[10] = { [4] = 1, 2 };
    PRINT(values5);
    // 0 0 0 0 1 2 0 0 0 0

    int values6[10] = { [0 ... 4] = 1, [5 ... 9] = 2 };
    PRINT(values6);
    // 1 1 1 1 1 2 2 2 2 2

    return 0;
}
