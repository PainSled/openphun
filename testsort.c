#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

#define listDType unsigned short
#define sortDType unsigned char

#define listSize 8

sortDType nElmInList;
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
                for ( sortDType n = listSize-i-1; n > i; n-- ){
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
    
    nElmInList = sizeof(list)/sizeof(list[0]);
    printf("\n\nnElmInList: %d\n\n", nElmInList);
    
    printf("\nOld list: ");
    for ( sortDType i = 0; i < nElmInList; i++ ){
        printf("%d, ", list[i]);
    }
    printf("\n\nnElmInList: %d\n\n", nElmInList);
    
    printf("\n\nSize of list element: %d\n", sizeof(list[0]));
    printf(    "Size of list:         %d\n", sizeof(list));
    printf(    "Elements in list:     %d\n", nElmInList);
    
    printf("\n\nnElmInList: %d\n\n", nElmInList);
    
    
    
    startTime = getMicrotime();
    
    for ( sortDType i = 0; i < listSize*2; i++ ){
        rollOver( input[i] );
        if ( 1 ){
        printf("\nNew number: %d List: ", input[i]);
            for ( sortDType i = 0; i < nElmInList; i++ ){
                printf("%d, ", list[i]);
        }
    }
    
    }
    endTime = getMicrotime();
    
    printf("\n\nnElmInList: %d\n", nElmInList);
    nElmInList = sizeof(list)/sizeof(list[0]);
    printf("\nnElmInList: %d\n", nElmInList);
    
    printf("\nNew list: ");
    for ( sortDType i = 0; i < nElmInList; i++ ){
        printf("%d, ", list[i]);
    }
    
    printf("\n\nSize of list element: %d\n", sizeof(list[0]));
    printf(    "Size of list:         %d\n", sizeof(list));
    printf(    "Elements in list:     %d\n", nElmInList);
    
    printf("\n\nMicroseconds elapsed: %d\n", endTime-startTime);

    return 0;
}
