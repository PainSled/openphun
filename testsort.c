#include <stdio.h>
#include <sys/time.h>

#define listDType unsigned short
#define sortDType unsigned char

unsigned long getMicrotime(){
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return currentTime.tv_sec * (unsigned int)1e6 + currentTime.tv_usec;
}

int main()
{
    unsigned int endTime;
    unsigned int startTime = getMicrotime();
    listDType list[8] = {4, 6, 8, 10, 12, 14, 16, 18};
    listDType newNumber =15;
    
    
    printf("New number: %d\nOld list: ", newNumber);
    
    sortDType nVarInList = sizeof(list)/sizeof(list[0]);
    
    for ( sortDType i = 0; i < nVarInList; i++ ){
        printf("%d, ", list[i]);
    }
    
    // If newNumber is less than median, start at beginning and cascade towards end.
    if ( newNumber < list[sizeof(list)/sizeof(list[0])/2] ){
        printf("\nLess than median");
        for ( sortDType i = 0; i < nVarInList; i++ ){
            printf("\nIs %d greater than %d? ", list[i], newNumber);
            if ( list[i] > newNumber ){
                printf("YES!", i);
                //memmove(&items[k+1], &items[k], (numItems-k-1)*sizeof(double)); //LOOK UP THIS FOR POSSIBLE INCREASE IN EFFICIENCY
                
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
        printf("\nGreater than median");
        for ( sortDType i = nVarInList-1; i > 0; i-- ){
            printf("\nIs %d less than %d? ", list[i], newNumber);
            if ( list[i] < newNumber ){
                printf("YES!", i);
                
                //Insert newNumber, and shift list towards beginning.
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
    
    for ( sortDType i = 0; i < nVarInList; i++ ){
        printf("%d, ", list[i]);
    }
    
    
    endTime = getMicrotime();
    printf("\n\nMicroseconds elapsed: %d\n", endTime-startTime);
    
    printf("\n\n%d\n", sizeof(list[0]));
    printf("%d\n", sizeof(list));
    printf("%d\n", nVarInList);
    printf("%d\n", getMicrotime());

    return 0;
}
