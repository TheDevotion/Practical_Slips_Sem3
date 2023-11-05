#include <stdio.h>
#include <string.h>
#include <conio.h>

void bubbleSort(char names[10][20], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                char temp[20];
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

void displayNames(char names[10][20], int n) {
    printf("Sorted Names in alphabetical order:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }
}

int main() {
    int n;
    char names[10][20];

    printf("Enter the number of names (up to 10): ");
    scanf("%d", &n);
    while (getchar() != '\n'); // Clearing the input buffer

    printf("Enter the names (max 19 characters each):\n");
    for (int i = 0; i < n; i++) {
        fgets(names[i], sizeof(names[i]), stdin);
        names[i][strcspn(names[i], "\n")] = '\0'; // Remove the newline character if present
    }

    bubbleSort(names, n);

    displayNames(names, n);

    getch();
    return 0;
}
