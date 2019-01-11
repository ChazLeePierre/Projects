#include <stdio.h>
#include <string.h>

int main (void){
char string1[100];
char string2[100];
int count = 0;

printf("Enter two lines of text and it will join them together for you!\n");
scanf("%100[^\n]%*c", string1);
scanf("%100[^\n]%*c", string2);
strcat(string1, " ");
strcat(string1, string2);
printf("%s\n", string1);

return 0;
}
