#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

#define listDType unsigned short
#define sortDType unsigned char

#define listSize 32

listDType list[listSize];

unsigned long getMicrotime(){
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return currentTime.tv_sec * (unsigned int)1e6 + currentTime.tv_usec;
}

void rollOver( listDType newNumber ){
     /*
                -------------------------------------------
                !         START OF RELEVANT CODE          !
                !    Weak preference to push right,       !
                ! as noise in data is preferencially high !
                -------------------------------------------
    */
    
    // If newNumber is less than median, start at beginning.
    if ( newNumber < list[sizeof(list)/sizeof(list[0])/2] ){
        for ( sortDType i = 0; i < listSize; i++ ){
            if ( list[i] > newNumber ){
                
                //Insert newNumber, and shift list towards end.
                for ( sortDType n = listSize-1; n > i; n-- ){
                    list[n] = list[n-1];
                }
                list[i] = newNumber;
                
                break;
            }
        }
    }
    // Else, start at end and cascade.
    else {
        for ( sortDType i = listSize-1; i > 0; i-- ){
            if ( list[i] < newNumber ){
                
                //Insert newNumber, and shift list towards beginning.
                for ( sortDType n = 0; n < i; n++ ){
                    list[n] = list[n+1];
                }
                list[i] = newNumber;
                
                break;
            }
        }
    }
    
    /*
                --------------------------------------
                !!!!!!!! END OF RELEVANT CODE !!!!!!!!
                --------------------------------------
    */
}

int main()
{
    unsigned int endTime;
    unsigned int startTime;
    
    listDType input[listSize*2];
    for ( sortDType i = 0; i < listSize; i++ ){
        list[i] = 0;
    }
    
    srand((unsigned int)getMicrotime());
    for ( sortDType i = 0; i < listSize*2; i++ ){
        input[i] = 10 + rand() % 89;
    }
    
    for ( sortDType i = 0; i < listSize*2; i++ ){
        rollOver( input[i] );
        if ( 0 ){
        printf("\nNew number: %d List: ", input[i]);
            for ( sortDType i = 0; i < listSize; i++ ){
                printf("%d, ", list[i]);
            }
        }
    
    }
    
    printf("\nOld list: ");
    for ( sortDType i = 0; i < listSize; i++ ){
        printf("%d, ", list[i]);
    }
    
    startTime = getMicrotime();
    for ( sortDType i = 0; i < listSize; i++ ){
        rollOver( input[i] );
    }
    endTime = getMicrotime();
    
    printf("\nNew list: ");
    for ( sortDType i = 0; i < listSize; i++ ){
        printf("%d, ", list[i]);
    }
    
    printf("\n\nMicroseconds elapsed: %d\n", endTime-startTime);

    return 0;
}
