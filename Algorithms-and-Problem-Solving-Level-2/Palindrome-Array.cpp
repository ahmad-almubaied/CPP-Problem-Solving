bool IsPalindromeArray(int arr[100], int Length)
{
    // Loop through each element of the array.
    // We only need to check up to the middle of the array.
    for (int i = 0; i < Length; i++)
    {
        // Compare the element at position i with its corresponding element from the end.
        if (arr[i] != arr[Length - i - 1])
        {
            return false;  // If any pair doesn't match, the array is not a palindrome.
        }
    }
    
    // If all corresponding pairs match, the array is a palindrome.
    return true;
}
