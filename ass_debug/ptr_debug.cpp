#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

#define ERR_INVALID_PARAM   -100
#define ERR_NO_MEM          -101

#define MAX_STRING_LEN  65536
#define MIN_STRING_LEN  1

void printUsage() {
    printf("Prints random string of specified length(arg 1)\n");
}

void randFunc(char* ptr, size_t len) {
    int index = 0;
    char* base = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";
    
    for(;index < len; index++) {
        ptr[index] = base[rand() % 69];
    }
}

int main(int argc, char* argv[]) {
    int err = 0;
    int val = -1;
    char* ptr = NULL;

    if (argc != 2) {
        printUsage();
        err = ERR_INVALID_PARAM;
        goto ERR_EXIT;
    }

    errno = 0;
    val = strtol(argv[1], NULL, 0);

    if ((errno != 0) || (val < MIN_STRING_LEN) || (val > MAX_STRING_LEN)) {
        printf("Invalid string len specified\n");
        err = ERR_INVALID_PARAM;
        goto ERR_EXIT;
    }

    ptr = (char*)calloc(val + 1, 1);
    if (ptr == NULL) {
        printf("Failed to allocate memory\n");
        err = ERR_NO_MEM;
        goto ERR_EXIT;
    }
    randFunc(ptr, val);
    printf("Random string %s\n", ptr);

ERR_EXIT:
    if (ptr != NULL) {
        free(ptr);
    }

    return err;
}
