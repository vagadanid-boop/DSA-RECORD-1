*Aim:*
 To write a C program to Search an element in an array using Linear Search.

*Algorithm:*
1.Start
2.Input the size of the array n.
3.Input the array elements A, A... A[n-1]
4.Input the element to Search, Say key.
5.Set i=0
6.Repeat while i<n:
   If A[i] == key, then print "Element found at position i+1" and stop.
7.If Loop Completed and element not found print "Element not found".
8.Stop.

*program:-*

#include <stdio.h>

int main() {
    int n, key, i, found = 0;  // variable declaration

    // Read size of array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int A[n];  // array declaration

    // Read array elements
    printf("Enter %d Elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Read element to search
    printf("Enter the element to Search: ");
    scanf("%d", &key);

    // Linear search
    for (i = 0; i < n; i++) {
        if (A[i] == key) {   // match found
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    // If element not found
    if (!found) {
        printf("Element not found\n");
    }

    return 0;
}


*output:*
INPUT:
Enter the size of the array: 4
Enter the elements: 1 2 3 4
Enter the element to search: 15
OUTPUT:
Element not found.

*Result:*
The program to Search an element in an array using Linear Search was successfully implemented, executed, and the output was Verified.
