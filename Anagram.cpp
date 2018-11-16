#include <assert.h>
#include <string>
#include <iostream>
#include <algorithm>

/**
* Function returns true if word_1 and word_2 are anagrams to each other. Otherwise false.
* Case sensitivity doesn't matter.
*/
void countChars(int* table, const std::string &word)
{
    for (int i = 0; i < word.length(); ++i)
    {
            table[word.at(i) - '`']++;
    }
}

bool check_if_anagram(const std::string &word_1, const std::string &word_2)
{
    const size_t sizeOfAsc = 26;
    std::string tempWord_1 = word_1;
    std::string tempWord_2 = word_2;

    int occWord1[sizeOfAsc], occWord2[sizeOfAsc];

    std::fill(occWord1, occWord1+sizeOfAsc, 0);
    std::fill(occWord2, occWord2+sizeOfAsc, 0);

    std::transform(tempWord_1.begin(), tempWord_1.end(), tempWord_1.begin(), ::tolower);
    std::transform(tempWord_2.begin(), tempWord_2.end(), tempWord_2.begin(), ::tolower);

    countChars(occWord1, tempWord_1);
    countChars(occWord2, tempWord_2);

    for (int i = 0; i < sizeOfAsc; ++i)
    {
            if( occWord1[i] != occWord2[i] && i != 32) //space
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

    answer = check_if_anagram("Buckethead", "DeathCubeK");
    assert(answer == true);
}

int main()
{
    test_cases();

}


