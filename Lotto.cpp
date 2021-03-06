#include <array>
#include <iostream>
#include <algorithm>
#include <cassert>
/**
* Function returns an array of 5 elements.
* Those 5 elements are created randomly in the range 1 - 49.
* Numbers can't repeat.
*/
bool elementInArray(std::array<int, 5> T, int number)
{
    bool uniqe = false;

    std::sort(T.begin(), T.end());
    for(auto x = T.begin(); x < T.end(); ++x)
    {
        if( *x == number )
        {
            uniqe = true;
            break;
        }
     }

    return uniqe;
}

bool checkIfUniqe(std::array<int, 5> T)
{
    bool uniqe = true;

    std::sort(T.begin(), T.end());
    for(auto x = T.begin(); x < T.end() - 1; ++x)
    {
        if( *x == *(x+1) )
        {
            uniqe = false;
            break;
        }
     }

    return uniqe;
}
std::array<int, 5> Lotto_drawing()
{
    std::array<int, 5> returnArr;
    int tempNr = 0;

    for(auto x = returnArr.begin(); x < returnArr.end(); ++x)
    {
        tempNr = (1 + rand() % (( 49 + 1) - 1));
        while( elementInArray(returnArr, tempNr) )
        {
            tempNr = (1 + rand() % (( 49 + 1) - 1));
        }
        *x = tempNr;
    }
    return returnArr;

}

/* Please create test cases for this program. test_cases() function can return void, bool or int. */
bool test_cases()
{

    assert( checkIfUniqe(Lotto_drawing()) == true);

    for(int i = 0; i < 100; ++i)
    {
            assert( checkIfUniqe(Lotto_drawing()) == true);
    }
    return true;
}


int main()
{
    srand( time(NULL) );


    test_cases();
}

