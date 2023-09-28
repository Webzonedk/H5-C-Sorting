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
    // Iterate through each element in the array except the last one
    for (int currentIndex = 0; currentIndex < n - 1; currentIndex++)
    {
        // Initialize the index of the smallest element to 'currentIndex'
        int smallestElementIndex = currentIndex;

        // Find the index of the smallest element in the remaining array
        for (int nextIndex = currentIndex + 1; nextIndex < n; nextIndex++)
        {
            if (array[nextIndex] < array[smallestElementIndex])
            {
                smallestElementIndex = nextIndex;
            }
        }

        // Swap the smallest element with the element at 'currentIndex' if they are different
        if (smallestElementIndex != currentIndex)
        {
            int temporaryValue = array[currentIndex];
            array[currentIndex] = array[smallestElementIndex];
            array[smallestElementIndex] = temporaryValue;
        }
    }

    //// Print array after sorting
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", array[i]);
    // }
    // printf("\n\n");
}

// Function to sort the array in ascending order using pointers
void selectionSortPointer(int *inputArrayPointer, int n)
{
    // Iterate through each element in the array except the last one
    for (int currentIndex = 0; currentIndex < n - 1; currentIndex++)
    {
        // Initialize the index of the smallest element to 'currentIndex'
        int smallestElementIndex = currentIndex;

        // Find the index of the smallest element in the remaining array
        for (int nextIndex = currentIndex + 1; nextIndex < n; nextIndex++)
        {
            if (*(inputArrayPointer + nextIndex) < *(inputArrayPointer + smallestElementIndex))
            {
                smallestElementIndex = nextIndex;
            }
        }

        // Swap the smallest element with the element at 'currentIndex' if they are different
        if (smallestElementIndex != currentIndex)
        {
            int temporaryValue = *(inputArrayPointer + currentIndex);
            *(inputArrayPointer + currentIndex) = *(inputArrayPointer + smallestElementIndex);
            *(inputArrayPointer + smallestElementIndex) = temporaryValue;
        }
    }

    //// Print array after sorting
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", array[i]);
    // }
    // printf("\n\n");
}

void insertionSort(int inputArray[], int arrayLength)
{
    int currentIndex, currentValue, previousIndex;

    // Start at index 1 as the first element is already sorted
    for (currentIndex = 1; currentIndex < arrayLength; currentIndex++)
    {
        currentValue = inputArray[currentIndex];
        previousIndex = currentIndex - 1;

        // Move elements of inputArray[0..currentIndex-1], that are greater than currentValue, one position ahead
        while (previousIndex >= 0 && inputArray[previousIndex] > currentValue)
        {
            inputArray[previousIndex + 1] = inputArray[previousIndex];
            previousIndex--;
        }

        // Insert currentValue at its correct position
        inputArray[previousIndex + 1] = currentValue;
    }

    //// Print array after sorting
    // for (int i = 0; i < arrayLength; i++)
    // {
    //     printf("%d ", inputArray[i]);
    // }
    // printf("\n\n");
}

void insertionSortPointer(int *inputArray, int arrayLength)
{
    int currentIndex, currentValue, previousIndex;

    // Start at index 1 as the first element is already sorted
    for (currentIndex = 1; currentIndex < arrayLength; currentIndex++)
    {
        currentValue = *(inputArray + currentIndex);
        previousIndex = currentIndex - 1;

        // Move elements of inputArray[0..currentIndex-1], that are greater than currentValue, one position ahead
        while (previousIndex >= 0 && *(inputArray + previousIndex) > currentValue)
        {
            *(inputArray + previousIndex + 1) = *(inputArray + previousIndex);
            previousIndex--;
        }

        // Insert currentValue at its correct position
        *(inputArray + previousIndex + 1) = currentValue;
    }

    //// Print array after sorting
    // for (int i = 0; i < arrayLength; i++)
    // {
    //     printf("%d ", *(inputArray + i));
    // }
    // printf("\n\n");
}

// Merges two sub-arrays of array[].
// First sub-array is array[left..middle]
// Second sub-array is array[middle+1..right]
void mergeSortedSubarrays(int array[], int left, int middle, int right)
{
    // Declare indices used for sub-arrays and the merged array
    int leftIndex, rightIndex, mergeIndex;

    // Calculate sizes of sub-arrays
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    // Allocate memory for temporary arrays
    int *leftArray = (int *)malloc(leftSize * sizeof(int));
    int *rightArray = (int *)malloc(rightSize * sizeof(int));

    if (leftArray == NULL || rightArray == NULL)
    {
        // Handle memory allocation failure
        return;
    }

    // Copy data to temporary arrays
    for (leftIndex = 0; leftIndex < leftSize; leftIndex++)
    {
        leftArray[leftIndex] = array[left + leftIndex];
    }

    for (rightIndex = 0; rightIndex < rightSize; rightIndex++)
    {
        rightArray[rightIndex] = array[middle + 1 + rightIndex];
    }

    // Reset indices for merging
    leftIndex = 0;
    rightIndex = 0;
    mergeIndex = left;

    // Merge the temporary arrays back into array[]
    while (leftIndex < leftSize && rightIndex < rightSize)
    {
        if (leftArray[leftIndex] <= rightArray[rightIndex])
        {
            array[mergeIndex] = leftArray[leftIndex];
            leftIndex++;
        }
        else
        {
            array[mergeIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        mergeIndex++;
    }

    // Copy remaining elements from leftArray[], if any
    while (leftIndex < leftSize)
    {
        array[mergeIndex] = leftArray[leftIndex];
        leftIndex++;
        mergeIndex++;
    }

    // Copy remaining elements from rightArray[], if any
    while (rightIndex < rightSize)
    {
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
void mergeSort(int array[], int left, int right)
{
    // Base case: the sub-array must have at least 2 elements
    if (left < right)
    {
        // Compute the middle index
        int middle = left + (right - left) / 2;

        // Recursively sort the two halves (makingthem smaller and smaller)
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        // Merge the sorted halves
        mergeSortedSubarrays(array, left, middle, right);
    }
}

// Function to find the maximum value in the array
int findMaxValue(int array[], int arraySize)
{
    int maxValue = array[0];
    for (int i = 1; i < arraySize; i++)
    {
        if (array[i] > maxValue)
        {
            maxValue = array[i];
        }
    }
    return maxValue;
}

// Counting sort function sorts the elements based on significant digits
void countingSortByDigit(int array[], int arraySize, int significantDigitPlace)
{
    const int maxDigitValue = 10; // Max digit value (0-9 as we are dealing with base 10 numbers)

    // Allocate memory for outputArray and countArray using malloc as old C does not support variable length arrays
    int* outputArray = (int*) malloc(arraySize * sizeof(int));
    int* countArray = (int*) malloc(maxDigitValue * sizeof(int));

    // Initialize count array with zeros
    for (int i = 0; i < maxDigitValue; ++i)
    {
        countArray[i] = 0;
    }

    // Store the count of elements for each digit at 'significantDigitPlace'
    for (int i = 0; i < arraySize; i++)
    {
        countArray[(array[i] / significantDigitPlace) % 10]++;
    }

    // Update count[i] to hold the position of the next occurrence of the same digit
    for (int i = 1; i < maxDigitValue; i++)
    {
        countArray[i] += countArray[i - 1];
    }

    // Build the output array using the countArray
    for (int i = arraySize - 1; i >= 0; i--)
    {
        outputArray[countArray[(array[i] / significantDigitPlace) % 10] - 1] = array[i];
        countArray[(array[i] / significantDigitPlace) % 10]--;
    }

    // Copy the sorted elements back into the original array
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = outputArray[i];
    }
    
    // Free allocated memory
    free(outputArray);
    free(countArray);
}

// Main Radix Sort function
void radixSort(int array[], int arraySize)
{
    // Find the maximum value to know the number of digits we need to sort by
    int maxValue = findMaxValue(array, arraySize);

    // Sort the array element based on each significant digit, starting from the least
    for (int significantDigitPlace = 1; maxValue / significantDigitPlace > 0; significantDigitPlace *= 10)
    {
        countingSortByDigit(array, arraySize, significantDigitPlace);
    }
}

// Main need to be in button as other methods should be initialized before main
int main()
{
    // initialize the random number generator
    srand(time(0));

    int size = 500000;
    int array[500000];
    int lower = 1, upper = 250000;
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

    //-----------------------------------------
    n = sizeof(array) / sizeof(array[0]);
    start_time = clock();
    selectionSort(array, n);
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
    insertionSortPointer(array, n);
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
    // // Print the sorted array ( can not be done within the mergeSort function)
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", array[i]);
    // }
    // printf("\n\n");
    printf("Time used for mergeSort: %f seconds\n\n", elapsed_time);
    //-----------------------------------------
    generateRandomNumbers(array, size, lower, upper);
    n = sizeof(array) / sizeof(array[0]);
    start_time = clock();
    radixSort(array, n);
    end_time = clock();

    elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    // // Print the sorted array ( can not be done within the mergeSort function)
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", array[i]);
    // }
    // printf("\n\n");
    printf("Time used for Radix sort: %f seconds\n\n", elapsed_time);
    //-----------------------------------------
    return 0;
}
