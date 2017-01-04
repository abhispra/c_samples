#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#define MALLOC_LEN  10
#define STRING_LEN  10

int main(int argc, char* argv[]) 
{

    int err = 0;
    uint32_t index = 0;

    uint8_t** ptr = NULL;

    ptr = (uint8_t**)malloc(MALLOC_LEN * sizeof(uint8_t*));
    assert (ptr != NULL);
    
    for (index; index < MALLOC_LEN; index++) {
        ptr[index] = (uint8_t*)calloc(STRING_LEN, 1);
        assert(ptr[index] != 0);
    }

    for (index = 0; index < MALLOC_LEN; index++) {
        free(ptr[index]);
        ptr[index] = NULL;
    }
    return err; 
}
