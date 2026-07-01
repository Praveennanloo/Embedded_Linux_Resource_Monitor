#include <stdio.h>
#include <time.h>

void show_datetime()
{
    time_t rawtime;
    struct tm *timeinfo;
    char date_buffer[20];
    char time_buffer[20];

    // Get current system time
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Format Date: DD-MM-YYYY
    strftime(date_buffer, sizeof(date_buffer), "%d-%m-%Y", timeinfo);
    
    // Format Time: HH:MM:SS (24-hour format)
    strftime(time_buffer, sizeof(time_buffer), "%H:%M:%S", timeinfo);

    printf("\n========== DATE & TIME ==========\n");
    printf("Current Date : %s\n", date_buffer);
    printf("Current Time : %s\n", time_buffer);
    printf("=================================\n");
}
