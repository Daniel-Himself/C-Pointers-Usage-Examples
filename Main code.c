/* Written by Daniel Sharon and Leen Abo Zidan */
#include <stdio.h>
#define STRING_LENGTH 50 /* A macro to represent a string length of 50 */

/* Function for question 1 */
void compressedString(char *str);

/* Function for question 2 */
void getFormatedInteger(char *format, char *result, int num);


int main()
{
    /* Variables for the initial function selection, The string of question 1 and the two strings and number of question 2 */
    int selection;
    char compressedstr[STRING_LENGTH];
    char format[STRING_LENGTH], result[STRING_LENGTH];
    int num;

    /* This do-while loop repeats the main function until the users inputs '3' to exit */
    do
    {
        printf("Please select the function you want to run:\n");
        printf("1 - compressed string\n");
        printf("2 - print formmated integers\n");
        printf("3 - Exit the program\n");
        scanf("%d", &selection);

        /* The 2 'if' statements below are used to activate the corresponding function according to the user input */
        if(selection==1)
        {
            printf("\nEnter string: ");
            scanf("%s", &compressedstr);
            compressedString(compressedstr);
        }
        if(selection==2)
        {
            printf("\nEnter format and number: ");
            scanf("%s %d", &format, &num);
            printf("\n%d - > ", num);
            getFormatedInteger(format, result, num);
            printf("%s\n", result);
        }

        /* If the user selects '3' the program will end on his request */
        if(selection == 3)
            break;
    }while(selection==1 || selection==2 || selection==3);

    /* An error check that reponds with an error for any input other than 1/2/3 */
    if(selection>3 || selection<1)
    {
        printf("\nInput Error!");
        return 1;
    }

    return 0;
}


void compressedString(char *str)
{
    /* These variables represent the index number, and a counter for the repeating letters */
    int letter_counter=1, i;

    /* This is the string to be printed once the original one is compressed into it */
    char compressed[STRING_LENGTH];

    /* This variable represents an index number of the new compressed string */
    int j=0;

    /* This variable represents the current letter being checked upon, starting at the index of zero */
    char letter=*str;

    printf("\nThe compressed string is: ");

    /* This loop resets the compressed string at each function repetition */
    for(i=0;i<STRING_LENGTH;i++)
    {
        *(compressed+i)='\0';
    }

    /* This loop inserts a capital letter and the number of it's occurrences in case a letter is different than the one to follow, until we reach a null character */
    for(i=0; i<STRING_LENGTH && letter!='\0' ; i++)
    {
        letter=*(str+i);
        if(*(str+i)==*(str+i+1))
        {
            letter_counter++;
        }
        else if(letter!='\0')
        {
            letter=letter-32;
           *(compressed+j)=letter;
           *(compressed+j+1)=letter_counter+48;
           j+=2;
           letter_counter=1;
        }

    }

    /* This line prints the compressed string */
    printf("%s\n", compressed);

    return;
}


void getFormatedInteger(char *format, char *result, int num)
{
    /* Variables for indexing 2 different strings in one line, a temp number to hold a temporary value within the calculations */
    int i=0,j=0, temp;

    /* This loop resets the result string at each function repetition */
    for(i=0;i<STRING_LENGTH;i++)
    {
        *(result+i)='\0';
    }

    /* This string helps us position the characters of the 'result' strings in the right order */
    char help[STRING_LENGTH];

    /* Partial conversion of a decimal number to its hexadecimal representation */
    if(*(format+1) == 'x')
    {
        for(i=0; num>0; i++)
        {
            temp = num % 16;
            if(temp < 10)
                temp = temp + 48 ;
            else
                temp = temp + 55 ;

            *(help+i)= temp;
            num = num / 16;
        }
    }

    /* Partial conversion of a decimal number to its decimal representation */
    if(*(format+1) == 'd')
    {
        for(i = 0 ; num>0 ; i++)
        {
            *(help+i) = num%10 +'0';
            num = num / 10;
        }
    }

    /* Partial conversion of a decimal number to its octal representation */
    if(*(format+1) == 'o')
    {
        for(i = 0 ; num>0 ; i++)
        {
            *(help+i) = num%8 +'0';
            num = num / 8;
        }
    }

    /* Partial conversion of a decimal number to its binary representation */
    if(*(format+1) == 'b')
    {
        for(i=0 ; num>0 ; i++)
        {
            *(help+i) = num%2 +'0' ;
            num = num/2;
        }

    }

    /* A loop is the final part of the 4 conversions above. it positions the "reversed" 'help' string components into their proper positions inside the 'result' string */
    for(i=i-1; i>=0; i--)
    {
        *(result+j) = *(help+i);
        j++;
    }

}

