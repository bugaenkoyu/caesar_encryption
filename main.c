#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define THE_NUMBER_OF_LETTERS_IN_THE_ALPHABET 26
#define LETTERS_IN_STRING 1000000

char* gotTextFromUser();
void encrypt(char* enteredLetters, int key);
void decipher(char* enteredLetters, int key);

int main (){
    int key;
    char enteredLetters[LETTERS_IN_STRING] = {0};
    printf ("enter the number key: ");
    scanf ("%d", &key);
    getchar ();
    if (key < 1) return 0;
        printf ("To encrypt text, type a, decipher b: ");
    char c;
        scanf ("%c", &c);
        fflush(stdin);
    char* Letters;
    Letters = gotTextFromUser();
    if (c == 'a') encrypt (Letters, key);
    if (c == 'b') decipher (Letters, key);
    free(Letters);

    getch(); return 0;
}

char* gotTextFromUser(){
    char* enteredLetters;
    enteredLetters = (char*) malloc(LETTERS_IN_STRING * sizeof(char));
    printf("enter the text for encryption: ");
    gets(enteredLetters);
    fflush(stdin);
    return enteredLetters;
}

void encrypt(char* enteredLetters, int key){
    int flag;
    int size = strlen(enteredLetters);

    for (int i = 0; i < size; i++){
        flag = 0; //Is the current character processed?

        if (enteredLetters[i] >= 'A' && enteredLetters[i] <= 'Z'){
            enteredLetters[i] = enteredLetters[i] + (key % THE_NUMBER_OF_LETTERS_IN_THE_ALPHABET);
            if (enteredLetters[i] > 'Z')
                enteredLetters[i] = 'A' + (enteredLetters[i] - 'Z') - 1;
            flag = 1;
        }

        if (enteredLetters[i] >= 'a' && enteredLetters[i] <= 'z'){
            enteredLetters[i] = enteredLetters[i] + (key % THE_NUMBER_OF_LETTERS_IN_THE_ALPHABET);
            if (enteredLetters[i] > 'z')
                enteredLetters[i] = 'a' + (enteredLetters[i] - 'z') - 1;
            flag = 1;
        }

        if (!flag){
            printf ("%c", enteredLetters[i]);
        }
            else{
                printf ("%c", enteredLetters[i]);
            }
    }
}

void decipher(char* enteredLetters,  int key){
    int flag;
    int size = strlen(enteredLetters);

    for (int i = 0; i < size; i++){
        flag = 0; //Is the current character processed?

        if (enteredLetters[i] >= 'A' && enteredLetters[i] <= 'Z'){
            enteredLetters[i] = enteredLetters[i] - (key % THE_NUMBER_OF_LETTERS_IN_THE_ALPHABET);
            if (enteredLetters[i] < 'A')
                enteredLetters[i] = 'Z' - ('A' - enteredLetters[i]) + 1;
            flag = 1;
        }

        if (enteredLetters[i] >= 'a' && enteredLetters[i] <= 'z'){
            enteredLetters[i] = enteredLetters[i] - (key % THE_NUMBER_OF_LETTERS_IN_THE_ALPHABET);
            if (enteredLetters[i] < 'a')
                enteredLetters[i] = 'z' - ('a' - enteredLetters[i]) + 1;
            flag = 1;
        }

        if (!flag){
            printf ("%c", enteredLetters[i]);
        }
            else{
                printf ("%c", enteredLetters[i]);
            }
    }
}
