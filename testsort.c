#include <stdio.h>

#define dataType unsigned char

int main()
{
    dataType list[4] = {4, 6, 8, 10};
    dataType newNumber = 8;
    
    if ( newNumber < list[sizeof(list)/sizeof(list[0])/2] ){
        printf("Bob's your auntie\n");
    }
    
    printf("%i\n", sizeof(list[0]));
    printf("%i\n", sizeof(list));
    printf("%i\n", sizeof(list)/sizeof(list[0]));

    return 0;
}
