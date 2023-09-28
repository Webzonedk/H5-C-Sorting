program SortingAlgorithms;

uses
    SysUtils, DateUtils;

var
    arraySize, i: longInt;
    myArray: array of longInt;
    startTime, endTime: TDateTime;
    elapsedTime: real;

procedure generateRandomNumbers(var arr: array of longInt; size, lower, upper: longInt);
var
    i: longInt;
begin
    for i := 0 to size - 1 do
    begin
        arr[i] := Random(upper - lower + 1) + lower;
    end;
end;

procedure selectionSort(var arr: array of longInt; n: longInt);
var
    i, j, smallest, temp: longInt;
begin
    for i := 0 to n - 2 do
    begin
        smallest := i;
        for j := i + 1 to n - 1 do
        begin
            if arr[j] < arr[smallest] then
                smallest := j;
        end;
        if smallest <> i then
        begin
            temp := arr[i];
            arr[i] := arr[smallest];
            arr[smallest] := temp;
        end;
    end;
end;

procedure insertionSort(var arr: array of longInt; n: longInt);
var
    i, j, currentValue: longInt;
begin
    for i := 1 to n - 1 do
    begin
        currentValue := arr[i];
        j := i - 1;
        while (j >= 0) and (arr[j] > currentValue) do
        begin
            arr[j + 1] := arr[j];
            Dec(j);
        end;
        arr[j + 1] := currentValue;
    end;
end;

// Merges two sub-arrays of arr[].
// First sub-array is arr[left..mid]
// Second sub-array is arr[mid+1..right]
procedure mergeSortedSubarrays(var arr: array of longInt; left, mid, right: longInt);
var
    n1, n2, i, j, k: longInt;
    L, R: array of longInt;
begin
    n1 := mid - left + 1;
    n2 := right - mid;
    
    SetLength(L, n1);
    SetLength(R, n2);
    
    // Copy data to temporary arrays L[] and R[]
    for i := 0 to n1 - 1 do
        L[i] := arr[left + i];
    for j := 0 to n2 - 1 do
        R[j] := arr[mid + 1 + j];
        
    // Merge the temporary arrays back into arr[left..right]
    i := 0; // Initial index of first sub-array
    j := 0; // Initial index of second sub-array
    k := left; // Initial index of merged array
    
    while (i < n1) and (j < n2) do
    begin
        if L[i] <= R[j] then
        begin
            arr[k] := L[i];
            Inc(i);
        end
        else
        begin
            arr[k] := R[j];
            Inc(j);
        end;
        Inc(k);
    end;
    
    // Copy remaining elements of L[], if there are any
    while i < n1 do
    begin
        arr[k] := L[i];
        Inc(i);
        Inc(k);
    end;
    
    // Copy remaining elements of R[], if there are any
    while j < n2 do
    begin
        arr[k] := R[j];
        Inc(j);
        Inc(k);
    end;
end;

// Main function to sort arr[left..right] using merge sort
procedure mergeSort(var arr: array of longInt; left, right: longInt);
var
    mid: longInt;
begin
    if left < right then
    begin
        mid := (left + right) div 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Merge the sorted halves
        mergeSortedSubarrays(arr, left, mid, right);
    end;
end;


procedure radixSort(var arr: array of longInt; n: longInt);
var
    i, exp, maxVal, digit: longInt;
    count, output: array of longInt;
begin
    // Find the maximum value to get the number of digits
    maxVal := arr[0];
    for i := 1 to n - 1 do
    begin
        if arr[i] > maxVal then
            maxVal := arr[i];
    end;

    // Do counting sort for each exponent/digit
    exp := 1;
    SetLength(count, 10);
    SetLength(output, n);
    while maxVal div exp > 0 do
    begin
        // Initialize count array
        for i := 0 to 9 do
            count[i] := 0;

        // Store count of occurrences in count[]
        for i := 0 to n - 1 do
        begin
            digit := (arr[i] div exp) mod 10;
            Inc(count[digit]);
        end;

        // Update count[i] to store the position of the next occurrence
        for i := 1 to 9 do
            count[i] := count[i] + count[i - 1];

        // Build the output array
        for i := n - 1 downto 0 do
        begin
            digit := (arr[i] div exp) mod 10;
            output[count[digit] - 1] := arr[i];
            Dec(count[digit]);
        end;

        // Copy the output array to arr[] so that arr[] is now sorted
        for i := 0 to n - 1 do
            arr[i] := output[i];

        exp := exp * 10;
    end;
end;


begin
    Randomize;
    arraySize := 500000;
    SetLength(myArray, arraySize);

    // Generate random numbers
    generateRandomNumbers(myArray, arraySize, 1, 250000);

    // Perform selection sort and measure time
    Writeln('Starting selection sort...');
    startTime := Now;
    selectionSort(myArray, arraySize);
    endTime := Now;
    elapsedTime := MilliSecondsBetween(endTime, startTime) / 1000;
    Writeln('Selection sort completed in ', elapsedTime:0:6, ' seconds.');

    // Reset the array
    generateRandomNumbers(myArray, arraySize, 1, 25000);

    // Perform insertion sort and measure time
    Writeln('Starting insertion sort...');
    startTime := Now;
    insertionSort(myArray, arraySize);
    endTime := Now;
    elapsedTime := MilliSecondsBetween(endTime, startTime) / 1000;
    Writeln('Insertion sort completed in ', elapsedTime:0:6, ' seconds.');

    // Reset the array
    generateRandomNumbers(myArray, arraySize, 1, 25000);

    // Perform merge sort and measure time
    Writeln('Starting merge sort...');
    startTime := Now;
    mergeSort(myArray, 0, arraySize - 1);
    endTime := Now;
    elapsedTime := MilliSecondsBetween(endTime, startTime) / 1000;
    Writeln('Merge sort completed in ', elapsedTime:0:6, ' seconds.');

    // Reset the array
    generateRandomNumbers(myArray, arraySize, 1, 25000);

    // Perform radix sort and measure time
    Writeln('Starting radix sort...');
    startTime := Now;
    radixSort(myArray, arraySize);
    endTime := Now;
    elapsedTime := MilliSecondsBetween(endTime, startTime) / 1000;
    Writeln('Radix sort completed in ', elapsedTime:0:6, ' seconds.');
end.
