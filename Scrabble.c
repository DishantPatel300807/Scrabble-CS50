#include <stdio.h>
#include <string.h>
#include <ctype.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char word[150]);

int main(void) {

    char word1[150], word2[150];

    printf("Player 1 : ");
    fgets(word1, sizeof(word1), stdin);
    printf("Player 2 : ");
    fgets(word2, sizeof(word2), stdin);

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 Wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 Wins!\n");
    } else {
        printf("Tie!");
    }
}

int compute_score(char word[150]) {
    int score = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        } 
        else if (islower(word[i])) {
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}