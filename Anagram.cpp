#include <assert.h>
#include <string>
#include <iostream>

/**
* Function returns true if word_1 and word_2 are anagrams to each other. Otherwise false.
* Case sensitivity doesn't matter.
*/
bool check_if_anagram(const std::string &word_1, const std::string &word_2)
{

    //if(word_1.length() != word_2.length() )
     //   return false;

    int occWord1[127], occWord2[127];
    for (int i = 0; i < 127; ++i)
    {
        occWord1[i] = 0;
        occWord2[i] = 0;
    }
  
    for (int i = 0; i < word_1.length(); ++i)
    {
            occWord1[word_1[i]]++;
    }
    for (int i = 0; i < word_2.length(); ++i)
    {
            occWord2[word_2[i]]++;
    }
    for (int i = 0; i < 127; ++i)
    {
            if( occWord1[i] != occWord2[i] && i != 32) //spacja nie gra
                return false;
    }
    return true;
}

void test_cases()
{
    bool answer = check_if_anagram("LordVader", "VaderLord");
    assert(answer == true);

    answer = check_if_anagram("silent", "listen");
    assert(answer == true);

    answer = check_if_anagram("funeral", "real fun");
    assert(answer == true);

    answer = check_if_anagram("Tieto", "Tietonator");
    assert(answer == false);

    answer = check_if_anagram("Football", "Basketball");
    assert(answer == false);

    answer = check_if_anagram("F", "");
    assert(answer == false);

}

int main()
{
    test_cases();

}


