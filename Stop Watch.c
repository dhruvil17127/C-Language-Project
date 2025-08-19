#include <stdio.h>
#include <time.h>

int main() {
    int choice;
    clock_t start_time, end_time;
    double elapsed_time;
    
    while (1) {
        printf("\nStopwatch Menu:\n");
        printf("1. Start Stopwatch\n");
        printf("2. Stop Stopwatch\n");
        printf("3. Reset Stopwatch\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Start the stopwatch
                start_time = clock();
                printf("Stopwatch started...\n");
                break;
                
            case 2:
                // Stop the stopwatch and calculate elapsed time
                end_time = clock();
                elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
                printf("Stopwatch stopped. Elapsed time: %.2f seconds\n", elapsed_time);
                break;
                
            case 3:
                // Reset the stopwatch
                printf("Stopwatch reset.\n");
                start_time = 0;
                break;
                
            case 4:
                // Exit the program
                printf("Exiting stopwatch.\n");
                return 0;
                
            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
    }
    
    return 0;
}
