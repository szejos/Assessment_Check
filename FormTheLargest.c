#include <assert.h>
#include <math.h>
/**
* Given a number, return the maximum number that could be formed with digits of the number given.
* For example: number = 7389, return 9873
*/
int form_the_largest_number(int number)
{
       int length = 0;
       int tempN = number;
       int returnNum = 0;

       // Zamieniamy int na tablice
       while (tempN != 0)
       {
          tempN /= 10;
          length++;
       }
       if(length != 0)
       {
          int *numberArray = (int*)malloc(sizeof(int) * length);
          tempN = number;
          int indeks = 0;
          while (tempN != 0){
              numberArray[indeks] = tempN % 10;
              tempN /= 10;
              indeks++;
          }

          // Sortowanie tablicy
          for (int i = 0; i < length; i++)
          {
              for (int j = 0; j < length; j++)
              {
                  if (numberArray[j] < numberArray[i])
                  {
                      int tmp = numberArray[i];
                      numberArray[i] = numberArray[j];
                      numberArray[j] = tmp;
                  }
              }
          }

          // zamiana tablicy na inta
          for(int i = 0; i < length; i++)
          {
              returnNum *=10;
              returnNum+=numberArray[i];
          }
          free(numberArray);

       }


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

    //form_the_largest_number(341264);

}

