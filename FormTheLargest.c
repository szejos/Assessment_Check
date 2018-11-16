#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
/**
* Given a number, return the maximum number that could be formed with digits of the number given.
* For example: number = 7389, return 9873
*/
int compare (const void * a, const void * b) {
     return ( *(int*)b - *(int*)a );
}
int form_the_largest_number(int number)
{
       short length = 0;
       int tempNumber = number;
       int returnNum = 0, indeks = 0;

       // getting size for malloc
       while (tempNumber != 0)
       {
          tempNumber /= 10;
          length++;
       }

       if( length < 0 ) return 0;

       int *numberArray = (int*)malloc(sizeof(int) * length);
       tempNumber = number;


       // convert int to array
       while (tempNumber != 0){
           numberArray[indeks] = tempNumber % 10;
           tempNumber /= 10;
           indeks++;
       }


       // sorting table
       qsort(numberArray, length, sizeof(int), compare);


       // build integer
       for(int i = 0; i < length; i++)
       {
           returnNum *= 10;
           returnNum += numberArray[i];
       }

       free(numberArray);

    return returnNum;
}

void test_cases()
{
    int result = form_the_largest_number(213);
    assert(result == 321);

    result = form_the_largest_number(7389);
    assert(result == 9873);

    result = form_the_largest_number(63729);
    assert(result == 97632);

    result = form_the_largest_number(566797);
    assert(result == 977665);
}

int main()
{

    test_cases();

}

