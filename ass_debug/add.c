#include <stdio.h>

int add(int x, int y)
{
    return x+y;
}

int main(int argc, char* argv[])
{
    int index = 0, ret = 0;
    printf("Hello World\n");
    ret = printf("Argument count - %d\n", argc);
    
    for (; index < argc; index++)
    {
        printf("This is a test%s\n", *argv);
    }
    printf("Result - %d\n", add(argc, argc));
    return 0;
}
