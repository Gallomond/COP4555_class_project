#include <stdio.h>
#include <time.h>

void bubble_sort(int my_list[], int n) {
    int i, j;
    // outer loop for passes
    for (i = n - 1; i > 0; i--) {
        // inner loop for comparisons
        for (j = 0; j < i; j++) {
            // if current element is greater than the next then swap the elements
            if (my_list[j] > my_list[j + 1]) {
                int temp = my_list[j];
                my_list[j] = my_list[j + 1];
                my_list[j + 1] = temp;
            }
        }
    }
}

int main() {
    int my_list[] = {7, 3, 6, 9, 4, 1};
    // calculate the size of the array
    int n = sizeof(my_list) / sizeof(my_list[0]);
    
    // Perform bubble sort with timer
    clock_t start = clock();
    bubble_sort(my_list, n);
    clock_t end = clock();
    double time_taken = ((double) (end - start)) * 1000.0 / CLOCKS_PER_SEC;

    // Print the sorted list
    printf("Sorted list: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", my_list[i]);
    }
    printf("\n");
    printf("Bubble sort completed in: %f ms\n", time_taken);

    return 0;
}
