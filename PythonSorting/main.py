import random
import time

# Generate random numbers in an array
def generate_random_numbers(array, size, lower, upper):
    # Filling the array with random numbers
    for i in range(size):
        array.append(random.randint(lower, upper))

# Selection sort algorithm
def selection_sort(arr):
    n = len(arr)
    for i in range(n-1):
        smallest_index = i
        for j in range(i+1, n):
            if arr[j] < arr[smallest_index]:
                smallest_index = j
        if smallest_index != i:
            arr[i], arr[smallest_index] = arr[smallest_index], arr[i]

# Insertion sort algorithm
def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

# Merge sort algorithm
def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr)//2
        left_half = arr[:mid]
        right_half = arr[mid:]

        merge_sort(left_half)
        merge_sort(right_half)

        i, j, k = 0, 0, 0

        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1

# Radix sort algorithm
def radix_sort(arr):
    max_num = max(arr)
    exp = 1
    n = len(arr)

    while max_num // exp > 0:
        counting_sort(arr, exp, n)
        exp *= 10

def counting_sort(arr, exp, n):
    output = [0] * n
    count = [0] * 10

    for i in range(n):
        index = arr[i] // exp
        count[index % 10] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    i = n - 1
    while i >= 0:
        index = arr[i] // exp
        output[count[index % 10] - 1] = arr[i]
        count[index % 10] -= 1
        i -= 1

    for i in range(n):
        arr[i] = output[i]

# Main program
if __name__ == "__main__":
    size = 500000
    lower = 1
    upper = 250000
    array = []

    generate_random_numbers(array, size, lower, upper)

    # Selection sort
    start_time = time.time()
    selection_sort(array.copy())
    elapsed_time = time.time() - start_time
    print(f"Time used for selection sort: {elapsed_time} seconds")

    # Insertion sort
    start_time = time.time()
    insertion_sort(array.copy())
    elapsed_time = time.time() - start_time
    print(f"Time used for insertion sort: {elapsed_time} seconds")

    # Merge sort
    start_time = time.time()
    merge_sort(array.copy())
    elapsed_time = time.time() - start_time
    print(f"Time used for merge sort: {elapsed_time} seconds")

    # Radix sort
    start_time = time.time()
    radix_sort(array.copy())
    elapsed_time = time.time() - start_time
    print(f"Time used for radix sort: {elapsed_time} seconds")
