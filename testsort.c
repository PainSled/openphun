#include <stdio.h>

#define listDType unsigned short
#define sortDType unsigned char

int main()
{
    listDType list[4] = {4, 6, 8, 10};
    listDType newNumber = 9;
    
    
    printf("New number: %d\nOld list: ", newNumber);
    
    sortDType nVarInList = sizeof(list)/sizeof(list[0]);
    
    for ( sortDType i = 0; i < nVarInList; i++ ){
        printf("%d, ", list[i]);
    }
    
    // If newNumber is less than median, start at beginning and cascade towards end.
    if ( newNumber < list[sizeof(list)/sizeof(list[0])/2] ){
        printf("\nBob's your uncle");
        for ( sortDType i = 0; i < nVarInList; i++ ){
            printf("\nIs %d greater than %d? ", list[i], newNumber);
            if ( list[i] > newNumber ){
                printf("YES!", i);
                //memmove(&items[k+1], &items[k], (numItems-k-1)*sizeof(double)); //LOOK UP THIS FOR POROBABLE INCREASE IN EFFICIENCY
                
                //Insert newNumber, and shift list towards end.
                for ( sortDType n = nVarInList; n > i; n-- ){
                    list[n] = list[n-1];
                }
                list[i] = newNumber;
                
                break;
            } else{
                printf("NO!", i);
            }
        }
    }
    // Else, start at end and cascade towards beginning.
    else {
        printf("\nBob's your auntie");
        for ( sortDType i = nVarInList-1; i > 0; i-- ){
            printf("\nIs %d less than %d? ", list[i], newNumber);
            if ( list[i] < newNumber ){
                printf("YES!", i);
                //memmove(&items[k+1], &items[k], (numItems-k-1)*sizeof(double)); //LOOK UP THIS FOR POROBABLE INCREASE IN EFFICIENCY
                
                //Insert newNumber, and shift list towards end.
                for ( sortDType n = 0; n < i; n++ ){
                    list[n] = list[n+1];
                }
                list[i] = newNumber;
                
                break;
            } else{
                printf("NO!", i);
            }
        }
        
    }
    
    
    printf("\nNew list: ");
    
    nVarInList = sizeof(list)/sizeof(list[0]);
    
    for ( sortDType i = 0; i < nVarInList; i++ ){
        printf("%d, ", list[i]);
    }
    
    printf("\n\n%d\n", sizeof(list[0]));
    printf("%d\n", sizeof(list));
    printf("%d\n", nVarInList);

    return 0;
}
