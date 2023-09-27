#include <stdio.h>
#include <stdlib.h>
#include <time.h>



// void generateRandomNumbers(int *arr, int size, int lower, int upper) {
//     for (int i = 0; i < size; ++i) {
//         arr[i] = (rand() % (upper - lower + 1)) + lower;
//     }
// }

// int main() {
//     // Initialiserer tilfældig nummergenerator
//     srand(time(0));

//     // Antallet af elementer i arrayet
//     int size = 1000;

//     // Allokerer hukommelse til arrayet
//     int *arr = malloc(size * sizeof(int));
//     if (arr == NULL) {
//         printf("Hukommelse kunne ikke allokeres.\n");
//         return 1;
//     }

//     // Definerer de nedre og øvre grænser for tilfældige tal
//     int lower = 1, upper = 1000;

//     // Genererer tilfældige tal og gemmer dem i arrayet
//     generateRandomNumbers(arr, size, lower, upper);

//     // Udskriver elementerne i arrayet
//     printf("Tilfældige tal i arrayet: ");
//     for (int i = 0; i < size; ++i) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n\n");

//     // Frigør hukommelsen
//     free(arr);

//     return 0;
// }



//I det tidligere eksempel brugte vi dynamisk hukommelsesallokering med malloc. Her er en version, der bruger en statisk array.

//Using the array directly
// void generateRandomNumbers(int arr[], int size, int lower, int upper) {
//     for (int i = 0; i < size; ++i) {
//         arr[i] = (rand() % (upper - lower + 1)) + lower;
//     }
// }

int main() {
    srand(time(0));

    int size = 1000;
    int arr[1000];
    int lower = 1, upper = 1000;

    generateRandomNumbers(arr, size, lower, upper);

    printf("Tilfældige tal i arrayet: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    return 0;
}

//Using pointer to the array
void generateRandomNumbers(int *arr, int size, int lower, int upper) {
    int *ptr;
    for (ptr = arr; ptr < arr + size; ++ptr) {
        *ptr = (rand() % (upper - lower + 1)) + lower;
    }
}



//Et andet alternativ til rand() er drand48(), som genererer float mellem [0, 1). Dette kan skaleres til det ønskede interval.

// void generateRandomNumbers(double *arr, int size, double lower, double upper) {
//     for (int i = 0; i < size; ++i) {
//         arr[i] = lower + (upper - lower) * ((double) rand() / (double) RAND_MAX);
//     }
// }

// int main() {
//     srand(time(0));

//     int size = 10;
//     double arr[10];
//     double lower = 1.0, upper = 100.0;

//     generateRandomNumbers(arr, size, lower, upper);

//     printf("Tilfældige tal i arrayet: ");
//     for (int i = 0; i < size; ++i) {
//         printf("%.2f ", arr[i]);
//     }
//     printf("\n\n");

//     return 0;
// }
