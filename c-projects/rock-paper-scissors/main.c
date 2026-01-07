#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    ROCK,
    PAPER,
    SCISSORS,
    INVALID
} Move;

Move get_player_move() {
    int choice;
    printf("Enter your move (0: Rock, 1: Paper, 2: Scissors): ");
    scanf("%d", &choice);
    if (choice < 0 || choice > 2) {
        return INVALID;
    }
    return (Move)choice;
}
Move get_computer_move() {
    return (Move)(rand() % 3);
}

void print_move(Move move) {
    switch (move) {
        case ROCK:     printf("Rock"); break;
        case PAPER:    printf("Paper"); break;
        case SCISSORS: printf("Scissors"); break;
        default:       printf("Invalid Move"); break;
    }
}

int determine_winner(Move player, Move computer) {
    if (player == computer) {
        return 0; // Tie
    }
    if ((player == ROCK && computer == SCISSORS) ||
        (player == PAPER && computer == ROCK) ||
        (player == SCISSORS && computer == PAPER)) {
        return 1; // Player wins
    }
    return -1; // Computer wins
}

int main() {
    srand(time(NULL));
    Move player_move = get_player_move();
    if (player_move == INVALID) {
        printf("Invalid move! Please enter 0, 1, or 2.\n");
        return 1;
    }
    Move computer_move = get_computer_move();

    printf("You chose: ");
    print_move(player_move);
    printf("\nComputer chose: ");
    print_move(computer_move);
    printf("\n");

    int result = determine_winner(player_move, computer_move);
    if (result == 0) {
        printf("It's a tie!\n");
    } else if (result == 1) {
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }

    return 0;
}
