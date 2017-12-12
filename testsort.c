#include <stdio.h>

#define dataType unsigned char

int main()
{
    dataType list[4] = {4, 6, 8, 10};
    dataType newNumber = 5;
    
    
    printf("New number: %i\nOld list: ", newNumber);
    
    unsigned short nVarInList = sizeof(list)/sizeof(list[0]);
    
    for ( unsigned char i = 0; i < nVarInList; i++ ){
        printf("%i, ", list[i]);
    }
    
    if ( newNumber < list[sizeof(list)/sizeof(list[0])/2] ){
        
    }
    
    
    printf("\nNew list: ");
    
    nVarInList = sizeof(list)/sizeof(list[0]);
    
    for ( unsigned char i = 0; i < nVarInList; i++ ){
        printf("%i, ", list[i]);
    }
    
    printf("\n\n%i\n", sizeof(list[0]));
    printf("%i\n", sizeof(list));
    printf("%i\n", nVarInList);

    return 0;
}
