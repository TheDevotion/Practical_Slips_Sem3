#include <stdio.h>
#include <string.h>
#include <conio.h>

#define MAX_CITIES 100
#define MAX_LENGTH 50

int linearSearch(char cities[MAX_CITIES][MAX_LENGTH], int n, char* city) {
    for (int i = 0; i < n; i++) {
        if (strcmp(cities[i], city) == 0) {
            return 1; // City found
        }
    }
    return 0; // City not found
}

int main() {
    int n;
    char cities[MAX_CITIES][MAX_LENGTH];
    char cityName[MAX_LENGTH];

    printf("Enter the number of cities: ");
    scanf("%d", &n);
    while (getchar() != '\n'); // Clearing the input buffer

    printf("Enter the names of cities:\n");
    for (int i = 0; i < n; i++) {
        fgets(cities[i], sizeof(cities[i]), stdin);
        cities[i][strcspn(cities[i], "\n")] = '\0'; // Remove the newline character if present
    }

    printf("Enter the city name to search: ");
    fgets(cityName, sizeof(cityName), stdin);
    cityName[strcspn(cityName, "\n")] = '\0'; // Remove the newline character if present

    if (linearSearch(cities, n, cityName)) {
        printf("%s is found in the array of cities.\n", cityName);
    } else {
        printf("%s is not found in the array of cities.\n", cityName);
    }

    getch();
    return 0;
}
