#include <stdio.h>
#include <string.h>
#include <Windows.h>

long long factorial(int n) {
    if (n == 0)
        return 1;
    else
        return (n * factorial(n - 1));
}

void countFrequency(const char* str, int* freq) {
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        freq[str[i] - 'A']++;
}

int main() {
    SetConsoleCP ( 1251 );
    SetConsoleOutputCP ( 1251 );
    char word[15];
    printf("Введіть слово: ");
    scanf("%s", word);

    int freq[26] = {0};
    countFrequency(word, freq);

    long long fact = factorial(strlen(word));

    for (int i = 0; i < 26; i++) {
        if (freq[i] > 1)
            fact /= factorial(freq[i]);
    }

    printf("Кількість анаграм: %lld\n", fact);

    return 0;
}
