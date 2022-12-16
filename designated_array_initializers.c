// Designated array initializers

#include <stdio.h>

void print(int * arr, int len)
{
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int values[10] = { [7] = 1, [2] = 2 };
    print(values, 10);
    // 0 0 2 0 0 0 0 1 0 0 

    int values2[10] = { [4 ... 8] = 3, [1] = 4 };
    print(values2, 10);
    // 0 4 0 0 3 3 3 3 3 0

    return 0;
}
