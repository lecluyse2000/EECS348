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

int all_digits(char *input, size_t size)
{
    for(size_t i = 0; i < size; ++i) {
        if(input[i] == '-') {
            continue;
        } else if(!isdigit(input[i]) && input[i] != '\n') {
            return 0;
        }
    }
    return 1;
}

void parse_input(char *raw_input)
{
    while(!all_digits(raw_input, strlen(raw_input)) || atoi(raw_input) > 300) {
        if(all_digits(raw_input, strlen(raw_input)) && atoi(raw_input) > 300) {
            printf("There will never be an NFL game of that many points scored. Try again: ");
        } else {
	         printf("Invalid input! Try again: ");
        }
        fgets(raw_input, sizeof(raw_input), stdin);
    }
}

void generate_outcomes(int score)
{



}

int main(){
    int user_input = 3;    
    char raw_input[50];
    
    while(user_input > 1) {
        printf("Enter 0 or 1 to stop\nEnter the score of the game: ");
        fgets(raw_input, sizeof(raw_input), stdin); //"Defensive" programming
        parse_input(raw_input); 
	    user_input = atoi(raw_input);
        generate_outcomes(user_input);
        if(user_input < 2) {
            printf("Exiting...\n");
        }
    }

    return(0);
}
