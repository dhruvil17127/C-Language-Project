#include <stdio.h>
#include <time.h>

int main() {
    // Declare a variable to store the current time
    time_t currentTime;
    
    // Get the current system time
    time(&currentTime);
    
    // Convert the current time to a readable string format
    char *timeString = ctime(&currentTime);
    
    // Print the time
    printf("Current time: %s", timeString);
    
    return 0;
}
