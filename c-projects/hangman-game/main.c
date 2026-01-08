#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 100
#define MAX_ATTEMPTS 6

const char *word_list[] = {
    "programming", "hangman", "computer", "science", "challenge", "developer",
    "function", "variable", "pointer", "array", "string", "compile", "debug",
    "algorithm", "data", "structure", "loop", "condition", "syntax", "library", "header"
};
const int word_count = sizeof(word_list) / sizeof(word_list[0]);
void display_word(const char *word, const int *guessed) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (guessed[i]) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int is_word_guessed(const char *word, const int *guessed) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (!guessed[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    const char *word_to_guess = word_list[rand() % word_count];
    int word_length = strlen(word_to_guess);
    int guessed[MAX_WORD_LENGTH] = {0};
    int attempts_left = MAX_ATTEMPTS;
    char guess;

    printf("Welcome to Hangman!\n");

    while (attempts_left > 0) {
        printf("\nWord: ");
        display_word(word_to_guess, guessed);
        printf("Attempts left: %d\n", attempts_left);
        printf("Enter your guess (a single letter): ");
        scanf(" %c", &guess);

        int correct_guess = 0;
        for (int i = 0; i < word_length; i++) {
            if (word_to_guess[i] == guess) {
                guessed[i] = 1;
                correct_guess = 1;
            }
        }

        if (!correct_guess) {
            attempts_left--;
            printf("Wrong guess!\n");
        } else {
            printf("Good guess!\n");
        }

        if (is_word_guessed(word_to_guess, guessed)) {
            printf("\nCongratulations! You've guessed the word: %s\n", word_to_guess);
            break;
        }
    }

    if (attempts_left == 0) {
        printf("\nGame Over! The word was: %s\n", word_to_guess);
    }

    return 0;
}     

