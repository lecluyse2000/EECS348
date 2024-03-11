//Author: Caden LeCluyse
//File: main.c
//Assignment: Lab5
//Class: EECS348
//Goal: Determine possible NFL football scores from a number
//      Also don't exceed three levels of indentation

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int all_digits(const char *input, const size_t size)
{
    for(size_t i = 0; i < size; ++i) {
        if(!isdigit(input[i]) && input[i] != '\n' && input[i] != '\0') {
            return 0;
        }
    }
    return 1;
}

void parse_input(char *raw_input, const size_t buffer_size)
{
    do {
        fgets(raw_input, buffer_size, stdin);
        if(strlen(raw_input) - 1 > 4 || !all_digits(raw_input, strlen(raw_input)) || atol(raw_input) > 300) {
            printf("Incorrect input! Try again: "); 
            continue;
        } else {
            break;
        }
    } while(1);
}

//Such an ugly solution, I was trying to do a recursive solution but couldn't get it to work
void print_combinations(const int score)
{
    int remaining_score = 0;
    for (int touchdown = 0; touchdown <= score / 6; ++touchdown) {
        for (int field_goal = 0; field_goal <= score / 3; ++field_goal) {
            for (int safety = 0; safety <= score / 2; ++safety) {
                for (int touchdown_2pt = 0; touchdown_2pt <= (score - (touchdown * 6 + field_goal * 3 + safety * 2)) / 8; ++touchdown_2pt) {
                    for (int touchdown_field_goal = 0; touchdown_field_goal <= (score - (touchdown * 6 + field_goal * 3 + safety * 2 + touchdown_2pt * 8)) / 7; ++touchdown_field_goal) {
                        remaining_score = score - (touchdown * 6 + field_goal * 3 + safety * 2 + touchdown_2pt * 8 + touchdown_field_goal * 7);
                        if (remaining_score == 0) {
                            printf("%d Touchdown + 2pt, %d Touchdown + fg, %d Touchdown, %d 3pt fg, %d Safety\n", touchdown_2pt, touchdown_field_goal, touchdown, field_goal, safety);
                        }
                    }
                }
            }
        }
    }
    printf("\n");
}

int main()
{
    int user_input = 3;    
    char raw_input[100];
    while(user_input > 1) {
        printf("Enter 0 or 1 to stop\nEnter the score of the game: ");
        parse_input(raw_input, sizeof(raw_input)); //Defensive programming 
        user_input = strtoul(raw_input, NULL, 10);
        if(user_input < 2) {
            printf("Exiting...\n\n");
        } else {
            print_combinations(user_input); 
        }
    }    

    return(0);
}
