#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void array_traversal(int arr[], int len)
{
    for (int i = 0; i < len; ++i)
    {
        printf("%d ", arr[i]);
    }
}

void insertion_array(int arr[], int len, int index, int value)
{
    // Shift elements to the right by one
    for (int i = len - 1; i >= index; --i)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = value;
}

int find_element(int arr[], int len, int deleteElement)
{
    for (int i = 0; i < len; ++i)
    {
        if (arr[i] == deleteElement)
            return i;
    }
    return -1;
}

void delete_element(int arr[], int len, int deleteElement)
{
    int index = find_element(arr, len, deleteElement);
    printf("\nindex is : %d", index);
    if (index != -1)
    {
        for (int i = index; i < len; ++i)
        {
            if (i == len - 1)
                arr[i] = 0;
            else
                arr[i] = arr[i + 1];
        }
    }
}

/* Find a peak element which is not smaller than its neighbours
Input: array[]= {5, 10, 20, 15}
Output: 20
Explanation: The element 20 has neighbors 10 and 15, both of them are less than 20.*/

int *findAllPeakElement(int arr[], int len, int *resultSize)
{
    int *resultArray = NULL;

    if (arr[0] > arr[1])
    {
        *resultArray = arr[0];
        return resultArray;
    }
    if (arr[len - 1] > arr[len - 2])
    {
        *resultArray = arr[1];
        return resultArray;
    }
    for (int i = 1; i < len - 1; ++i)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        {
            if (resultArray == NULL)
            {
                resultArray = (int *)malloc(sizeof(int));
            }
            else
            {
                resultArray = (int *)realloc(resultArray, sizeof(int) * (*resultSize + 1));
            }
            resultArray[*resultSize] = arr[i];
            ++*resultSize;
        }
    }
    return resultArray;
}

int findPeakElement(int arr[], int n)
{
    if (n = 1)
        return 0;
    if (arr[0] >= arr[1])
        return arr[0];
    if (arr[n - 1] >= arr[n - 2])
        return arr[n - 2];

    for (int i = 1; i < n - 2; ++i)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        {
            return arr[i];
        }
    }
}

int findPeakElementUntil(int arr[], int left, int right, int len)
{
    int mid = left + (right - left) / 2;

    if ((mid == 0 || arr[mid] >= arr[mid + 1]) && (len - 1 == mid || arr[mid] >= arr[mid - 1]))
        return arr[mid];
    else if (mid > 0 && arr[mid - 1] > arr[mid])
    {
        return findPeakElementUntil(arr, left, (mid - 1), len);
    }
    else
    {
        return findPeakElementUntil(arr, (mid + 1), right, len);
    }
}

int findPeakElementRecursive(int arr[], int len)
{

    return findPeakElementUntil(arr, 0, len - 1, len);
}

/*  Given an array, write functions to find the minimum and maximum elements in it.
Input: array[]= {5, 10, 20, 15}
Output: Max: 20, Min: 5

*/

void findMinMaxElement(int arr[], int len)
{
    int min = arr[0];
    int max = arr[0];

    for (int i = 0; i < len; i++)
    {
        if (min > arr[i])
            min = arr[i];
        if (max < arr[i])
            max = arr[i];
    }
    printf("max is: %d | min is: %d", max, min);
}

int findMax(int a, int b)
{
    return a > b ? a : b;
}
int findMin(int a, int b)
{
    return a < b ? a : b;
}

int findMinMaxElement2(int arr[], int len)
{
    int min = arr[0];
    int max = arr[len - 1];

    for (int i = 0; i < len; ++i)
    {
        max = findMax(max, arr[i]);
    }
    for (int i = 0; i < len; ++i)
    {
        min = findMin(min, arr[i]);
    }
    printf("max is: %d | min is: %d", max, min);
}

int getMaxRecursive(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    else
    {
        return getMaxRecursive(arr + 1, n - 1) > arr[0] ? getMaxRecursive(arr + 1, n - 1) : arr[0];
    }
}
int getMinRecursive(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    else
    {
        return getMinRecursive(arr + 1, n - 1) < arr[0] ? getMinRecursive(arr + 1, n - 1) : arr[0];
    }
}
void findMaxMinRecursive(int arr[], int len)
{
    printf("max is: %d | min is: %d", getMaxRecursive(arr, len), getMinRecursive(arr, len));
}

/*
Array reverse or reverse a array means changing the position of each number of the given array
 to its opposite position from end.
 Input: original_array[] = {1, 2, 3}
 Output: array_reversed[] = {3, 2, 1}

 Input: original_array[] = {4, 5, 1, 2}
Output: array_reversed[] = {2, 1, 5, 4}
*/
void swapElement(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverseArray(int arr[], int len)
{
    for (int i = 0; i < len; ++i)
    {
        if (i == len / 2)
            break;
        swapElement(&arr[i], &arr[len - i - 1]);
    }
    for (int i = 0; i < len; ++i)
    {
        printf("%d ", arr[i]);
    }
}

void reverseArrayExtraArray(int arr[], int n)
{
    int arr2[n];
    for (int i = 0; i < n; ++i)
    {
        arr2[i] = arr[n - i - 1];
    }

    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr2[i]);
    }
}

void reverseArrayRecursive(int arr[], int start, int end)
{
    if (start == end)
        return;
    swapElement(&arr[start], &arr[end]);
    reverseArrayRecursive(arr, start + 1, end - 1);
}

#define MAXSIZE 100
struct Stack
{
    int top;          // position index in stack
    int arr[MAXSIZE]; // array to store value
};

void push(struct Stack *stack, int item)
{
    if (MAXSIZE - 1 == stack->top)
    {
        printf("Stack is overflow\n");
        return;
    }
    stack->top = stack->top + 1;
    stack->arr[stack->top] = item;
}

int pop(struct Stack *stack)
{
    if (-1 == stack->top)
    {
        printf("Stack is empty");
        exit(1);
    }
    int x = stack->arr[stack->top];
    stack->top = stack->top - 1;
    return x;
}

void reverseArrayUsingReverseStack(int arr[], int n)
{
    struct Stack stack;
    stack.top = -1;

    for (int i = 0; i < n; ++i)
    {
        push(&stack, arr[i]);
    }

    printf("Reverse stack is:");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", pop(&stack));
    }
}

/*  Given a sorted array arr[] of size N and a number X, you need to find the number of occurrences of X in given array.

Note: Expected time complexity is O(log(n))

Examples:

Input: N = 7, X = 2, Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4
Explanation: 2 occurs 4 times in the given array.*/

int countNumberOccurrencesUsingBinary(int arr[], int left, int right, int n, int key)
{
    int countOccurence;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] < key)
        {
            left = mid + 1;
            continue;
        }
        if (arr[mid] > key)
        {
            right = mid - 1;
            continue;
        }
        if (arr[mid] == key)
        {
            countOccurence = 1;
            for (int i = mid - 1; arr[i] == key; --i)
                ++countOccurence;
            for (int i = mid + 1; arr[i] == key; ++i)
                ++countOccurence;
            return countOccurence;
        }
    }
    return -1;
}

int findFirstOccur(int arr[], int left, int right, int key)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key && key > arr[mid - 1])
            return mid;
        else if (arr[mid] < key)
        {
            return findFirstOccur(arr, mid + 1, right, key);
        }
        else
        {
            return findFirstOccur(arr, left, mid - 1, key);
        }
    }
    return 0;
}

int findLastOccur(int arr[], int left, int right, int key)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key && key < arr[mid + 1])
            return mid;
        else if (arr[mid] > key)
        {
            return findLastOccur(arr, left, mid - 1, key);
        }
        else
        {
            return findLastOccur(arr, mid + 1, right, key);
        }
    }

    return 0;
}
int countNumberOccurrencesUsingBinaryRecursive(int arr[], int left, int right, int n, int key)
{
    int firstInx = findFirstOccur(arr, left, right, key);
    int lastInt = findLastOccur(arr, left, right, key);
    return lastInt - firstInx + 1;
}

/* Given an array A[] consisting of only 0s, 1s, and 2s. The task is to write a function that
sorts the given array. The functions should put all 0s first, then all 1s and all 2s in last.
Input: {0, 1, 2, 0, 1, 2}
Output: {0, 0, 1, 1, 2, 2}

Input: {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1}
Output: {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2}
*/

void segregate012UsingCounter(int arr[], int n)
{
    int count0;
    int count1;
    int count2;

    for (int i = 0; i < n; ++i)
    {
        switch (arr[i])
        {
        case 0:
            count0++;
            break;
        case 1:
            count1++;
            break;
        case 2:
            count2++;
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (count0 > 0)
        {
            arr[i] = 0;
            count0--;
        }
        else if (count1 > 0)
        {
            arr[i] = 1;
            count1--;
        }
        else
        {
            arr[i] = 2;
            count2--;
        }
    }
}

void segregate012(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    int mid = low;

    while (mid <= high)
    {
        switch (arr[mid])
        {
        case 0:
            swapElement(&arr[mid], &arr[low]);
            low++;
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            swapElement(&arr[mid], &arr[high]);
            high--;
            break;
        }
    }
}

void segregate012UsingPointer(int arr[], int n){
    int left = 0;
    int right = n - 1;
    for(int i = 0; i <= right;){
        if(0 == arr[i]){
            swapElement(&arr[i], &arr[left]);
            i++;
            left++;
        }else if(2 == arr[i]){
            swapElement(&arr[i], &arr[right]);
            right--;
        }else{
            i++;
        }
    }
}

void main()
{
    // Declaration

    float arrFl[20];
    char arrC[60];

    // Intialize
    int arr[] = {0, 1, 2, 0, 1, 2}; // static array
    int len = sizeof(arr) / sizeof(arr[0]);
    // int result = findPeakElementRecursive(arr, len);
    segregate012UsingPointer(arr, len);
    // printf("%d", countNumberOccurrencesUsingBinaryRecursive(arr, 0, len - 1, len, 4));
    array_traversal(arr, len);
    // printf("%d", result);
    /*{
        int *dynamicArr = (int *)malloc(sizeof(int) * 10); // dynamic array
        memcpy(dynamicArr, arr, sizeof(int) * 10);         // copy  elements from static array to dynamic array
        int resultSize = 0;
        int *result = findPeakElement(dynamicArr, len, &resultSize);
        for (int i = 0; i < resultSize; ++i)
        {
            printf("%d ", result[i]);
        }
        free(result);
            free(dynamicArr);
    }*/

    /*
    {
    printf("\nArray before: ");
    array_traversal(arr, len);
    delete_element(arr, len, 13);
    printf("\nArray after: ");
    array_traversal(arr, len);
    }
    */
}