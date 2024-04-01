#include <stdio.h>
#include <time.h>

int binary_search(int my_list[], int n, int target) {
    // Initialize low and high indices for binary search
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        // calculating middle
        int mid = (low + high) / 2;
        // check if the middle element is the target
        if (my_list[mid] == target)
            return mid;
        // if the middle element is less than the target, search the right half
        else if (my_list[mid] < target)
            low = mid + 1;
        // if the middle element is greater than the target, search the left half
        else
            high = mid - 1;
    }
    // if the loop ends without finding the target, return -1
    return -1;
}

int main() {
    int my_list[] = {2, 5, 8, 12, 16};
    // calculate the size of the array
    int n = sizeof(my_list) / sizeof(my_list[0]);
    // target for what the binary search is looking for
    int target = 8;
    
    // performing binary search with timer
    clock_t start = clock();
    int result = binary_search(my_list, n, target);
    clock_t end = clock();
    double time_taken = ((double) (end - start)) * 1000.0 / CLOCKS_PER_SEC;

    // check if target has been found
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

     printf("Binary search completed in: %f ms\n", time_taken);

    return 0;
}