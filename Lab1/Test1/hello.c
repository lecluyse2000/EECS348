/* Author: Caden LeCluyse
   ID: 2976965
   Purpose: The purpose of this lab is to get an introduction to github
   Filename: hello.c
*/

#include <stdio.h>
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len;
    printf("Enter a string: ");
    gets(str);
    len = strlen(str);
    for (i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
    printf("The capitalized string is: %s\n", str);
// Reverse the string.
    for (i = 0, len = strlen(str); i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
    printf("The reversed string is: %s\n", str);
    return 0;
}
