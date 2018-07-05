#include <stdlib.h>
#include <CUnit/CUnit.h>
#include "occurrency_sorter.h"

wordWithOccurrencyPtr first;
wordWithOccurrencyPtr second;
wordWithOccurrencyPtr third;
wordWithOccurrencyPtr fourth;

size_t length = 4;
wordWithOccurrencyPtr words[4];



int init_suite_occurrency_sorter(void) {
    first = create_wordWithOccurrency("first", 2);
    second = create_wordWithOccurrency("second", 5);
    third = create_wordWithOccurrency("third", 8);
    fourth = create_wordWithOccurrency("fourth", 9);
    
    words[0] = third;
    words[1] = second;
    words[2] = first;
    words[3] = fourth;


    return 0;
}

int clean_suite_occurrency_sorter(void) {
    free(first);
    free(second);
    free(third);
    free(fourth);
    return 0;
}

void test_occurency_sorting(void) {
    CU_ASSERT_STRING_EQUAL(get_word(words[0]), "third");
    CU_ASSERT_EQUAL(get_occurences(words[0]),8);
    CU_ASSERT_STRING_EQUAL(get_word(words[1]), "second");
    CU_ASSERT_EQUAL(get_occurences(words[1]),5);
    CU_ASSERT_STRING_EQUAL(get_word(words[2]), "first");
    CU_ASSERT_EQUAL(get_occurences(words[2]),2);
    CU_ASSERT_STRING_EQUAL(get_word(words[3]), "fourth");
    CU_ASSERT_EQUAL(get_occurences(words[3]),9);

    sort_words_by_occurrency(words, length);

    CU_ASSERT_STRING_EQUAL(get_word(words[0]), "first");
    CU_ASSERT_EQUAL(get_occurences(words[0]),2);
    CU_ASSERT_STRING_EQUAL(get_word(words[1]), "second");
    CU_ASSERT_EQUAL(get_occurences(words[1]),5);
    CU_ASSERT_STRING_EQUAL(get_word(words[2]), "third");
    CU_ASSERT_EQUAL(get_occurences(words[2]),8);
    CU_ASSERT_STRING_EQUAL(get_word(words[3]), "fourth");
    CU_ASSERT_EQUAL(get_occurences(words[3]),9);

}

