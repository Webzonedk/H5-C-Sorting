#include <stdio.h>
#include <time.h>
#include <stdlib.h>


// Using pointer to the array
void generateRandomNumbers(int *array, int size, int lower, int upper)
{
    int *ptr;
    for (ptr = array; ptr < array + size; ++ptr)
    {
        *ptr = (rand() % (upper - lower + 1)) + lower;
    }
}

// Function to sort the array in ascending order
void selectionSort(int array[], int n)
{
    // Outer loop iterates through each element one by one
    for (int i = 0; i < n - 1; i++)
    {
        // Initialize the index of the smallest element to 'i'
        int minIndex = i;

        // Inner loop finds the smallest element in the remaining array
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap the element at 'minIndex' with the element at 'i'
        if (minIndex != i)
        {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }

    // // Print the sorted array
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", array[i]);
    // }
    // printf("\n\n");
}

// Function to sort the array in ascending order using pointers
void selectionSortPointer(int *array, int n)
{
    // Outer loop iterates through each element one by one
    for (int i = 0; i < n - 1; i++)
    {
        // Initialize the index of the smallest element to 'i'
        int minIndex = i;

        // Inner loop finds the smallest element in the remaining array
        for (int j = i + 1; j < n; j++)
        {
            if (*(array + j) < *(array + minIndex))
            {
                minIndex = j;
            }
        }

        // Swap the element at 'minIndex' with the element at 'i'
        if (minIndex != i)
        {
            int temp = *(array + i);
            *(array + i) = *(array + minIndex);
            *(array + minIndex) = temp;
        }
    }

    // // Print the sorted array
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", array[i]);
    // }
    // printf("\n\n");
}

void insertionSort(int array[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) // start at 1, because the first element is already sorted
    {
        key = array[i];
        j = i - 1;

        /* Move elements of array[0..i-1], that are greater than key, to one position ahead of their current position */
        while (j >= 0 && array[j] > key) // while the element is greater than the key, move it one position ahead
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key; // insert the key in the correct position
    }

    // // Print the sorted array
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", array[i]);
    // }
    // printf("\n\n");
}

void insertionsortPointer(int *array, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) // start at 1, because the first element is already sorted
    {
        key = *(array + i);
        j = i - 1;

        /* Move elements of array[0..i-1], that are greater than key, to one position ahead of their current position */
        while (j >= 0 && *(array + j) > key) // while the element is greater than the key, move it one position ahead
        {
            *(array + j + 1) = *(array + j);
            j = j - 1;
        }
        *(array + j + 1) = key; // insert the key in the correct position
    }

    // // Print the sorted array
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", array[i]);
    // }
    // printf("\n\n");
}



// Merges two sub-arrays of array[].
// First sub-array is array[left..middle]
// Second sub-array is array[middle+1..right]
void mergeSortedSubarrays(int array[], int left, int middle, int right) {
    // Declare indices used for sub-arrays and the merged array
    int leftIndex, rightIndex, mergeIndex;

    // Calculate sizes of sub-arrays
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    // Allocate memory for temporary arrays
    int *leftArray = (int *)malloc(leftSize * sizeof(int));
    int *rightArray = (int *)malloc(rightSize * sizeof(int));
    
    if(leftArray == NULL || rightArray == NULL) {
        // Handle memory allocation failure
        return;
    }

    // Copy data to temporary arrays
    for (leftIndex = 0; leftIndex < leftSize; leftIndex++) {
        leftArray[leftIndex] = array[left + leftIndex];
    }

    for (rightIndex = 0; rightIndex < rightSize; rightIndex++) {
        rightArray[rightIndex] = array[middle + 1 + rightIndex];
    }

    // Reset indices for merging
    leftIndex = 0;
    rightIndex = 0;
    mergeIndex = left;

    // Merge the temporary arrays back into array[]
    while (leftIndex < leftSize && rightIndex < rightSize) {
        if (leftArray[leftIndex] <= rightArray[rightIndex]) {
            array[mergeIndex] = leftArray[leftIndex];
            leftIndex++;
        } else {
            array[mergeIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        mergeIndex++;
    }

    // Copy remaining elements from leftArray[], if any
    while (leftIndex < leftSize) {
        array[mergeIndex] = leftArray[leftIndex];
        leftIndex++;
        mergeIndex++;
    }

    // Copy remaining elements from rightArray[], if any
    while (rightIndex < rightSize) {
        array[mergeIndex] = rightArray[rightIndex];
        rightIndex++;
        mergeIndex++;
    }

    // Free allocated memory
    free(leftArray);
    free(rightArray);
}


// Sorts an array using the merge sort algorithm
// The function sorts the sub-array array[left..right]
void mergeSort(int array[], int left, int right) {
    // Base case: the sub-array must have at least 2 elements
    if (left < right) {
        // Compute the middle index
        int middle = left + (right - left) / 2;

        // Recursively sort the two halves (makingthem smaller and smaller)
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        // Merge the sorted halves
        mergeSortedSubarrays(array, left, middle, right);
    }
}











int main()
{
    // initialize the random number generator
    srand(time(0));

    int size = 50000;
    int array[50000];
    int lower = 1, upper = 25000;
    int n;
    clock_t start_time;
    clock_t end_time;
    double elapsed_time;

    generateRandomNumbers(array, size, lower, upper);
    // printf("Random numbers in array: ");
    // for (int i = 0; i < size; ++i)
    // {
    //     printf("%d ", array[i]);
    // }
    // printf("Random array with ", size, "numbers created\n\n");
    //-------------------------------

    n = sizeof(array) / sizeof(array[0]);

    // Start timer
    start_time = clock();

    selectionSort(array, n);

    // Stop timer
    end_time = clock();
    elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time used for selectionSort: %f seconds\n", elapsed_time);

    //-----------------------------------------
    generateRandomNumbers(array, size, lower, upper);
    n = sizeof(array) / sizeof(array[0]);
    start_time = clock();
    selectionSortPointer(array, n);
    end_time = clock();
    elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time used for selectionSortPointer: %f seconds\n\n", elapsed_time);

    //-----------------------------------------
    generateRandomNumbers(array, size, lower, upper);
    n = sizeof(array) / sizeof(array[0]);
    start_time = clock();
    insertionSort(array, n);
    end_time = clock();
    elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time used for insertionSort: %f seconds\n", elapsed_time);
    //-----------------------------------------
    generateRandomNumbers(array, size, lower, upper);
    n = sizeof(array) / sizeof(array[0]);
    start_time = clock();
    insertionsortPointer(array, n);
    end_time = clock();
    elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time used for insertionsortPointer: %f seconds\n\n", elapsed_time);
    //-----------------------------------------
    generateRandomNumbers(array, size, lower, upper);
    n = sizeof(array) / sizeof(array[0]);
    start_time = clock();
    mergeSort(array, 0, n - 1);
    end_time = clock();
    elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    // Print the sorted array ( can not be done within the mergeSort function)
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", array[i]);
    // }
    // printf("\n\n");
    printf("Time used for mergeSort: %f seconds\n\n", elapsed_time);

    return 0;
}

