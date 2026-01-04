#include <stdio.h>
#include <inttypes.h>


int main(void)
{
    int32_t value = 922337203;

    printf("Value: %" PRId32 "\n", value);
    printf("Size of int64_t: %zu bytes\n", sizeof(int32_t));
    return 0;
}
