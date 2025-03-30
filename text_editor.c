#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxwords 100  
#define maxlength 100  

char stack[maxwords][maxlength];  
int top = -1;  

void push(const char *word) {
    if (top < maxwords - 1) {  
        strcpy(stack[++top], word);  
    } else {
        printf("Stack is full!\n\n");
    }
}

void pop() {
    if (top >= 0) {  
        top--;  
    } else {
        printf("No words to undo!\n\n");
    }
}

void display() {
    if (top < 0) {
        printf("Empty Document\n\n");
        return;
    }
    for (int i = 0; i <= top; i++) {
        printf("%s ", stack[i]);
    }
    printf("\n");
}

void main() {
    int choice;
    char word[maxlength];

    while (1) {
        printf("**********   My Text Editor ! 🚀  **********");
        printf("\n1. Add Word\n2. Undo\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                printf("Enter word: ");
                fgets(word, maxlength, stdin);
                word[strcspn(word, "\n")] = 0;  
                push(word);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

}
