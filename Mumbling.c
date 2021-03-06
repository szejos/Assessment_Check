#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/**
* Function duplicates letters based on their index. Each index means how many times the letter needs to be duplicated.
* See test cases for examples.
*/

char* accumulate(const char *word, const int length)
{
    char* returnWord = NULL;
    int sum = length, count = 0;

    // calculate the size
    for(int i = 1; i <= length; ++i)
    {
        sum += i;
    }

    returnWord = (char*)malloc(sizeof(char) * sum);

    for(int i = 0; i < length; ++i)
    {
        for(int j = 0; j < i+1; ++j)
        {
            if(j == 0)
            {
                if( word[i] >= 'a' && word[i] <= 'z' )
                    returnWord[count] =  word[i]-32;
                else
                    returnWord[count] = word[i];
            }
            else
            {
                if( word[i] >= 'A' && word[i] <= 'Z' )
                    returnWord[count] = word[i]+32;
                else
                    returnWord[count] = word[i];
            }
            count++;
        }
        if(count < sum-1)
        {
            returnWord[count] = '-';
            count++;
        }
    }
    returnWord[count] = '\0';

    return returnWord;
}

void test_cases()
{
    char* result = accumulate("abcd", strlen("abcd"));
    assert(strcmp(result, "A-Bb-Ccc-Dddd") == 0);
    free(result);

    result = accumulate("cwAt", strlen("cwAt"));
    assert(strcmp(result, "C-Ww-Aaa-Tttt") == 0);
    free(result);
}

int main(int argc, char *argv[])
{
    test_cases();
    return 0;
}

