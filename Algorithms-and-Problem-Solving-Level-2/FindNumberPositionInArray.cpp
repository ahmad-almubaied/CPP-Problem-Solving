short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    // Loop through the array to check for the number.
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
            return i;  // Return the index if the number is found.
    }
    // If the loop completes, the number was not found.
    return -1;
