#include <stdio.h>

void show_cpu_info()
{
    FILE *fp;
    char buffer[256];

    fp = fopen("/proc/stat", "r");

    if(fp == NULL)
    {
        printf("Error opening /proc/stat\n");
        return;
    }

    fgets(buffer, sizeof(buffer), fp);

    printf("\n===== CPU INFORMATION =====\n");
    printf("%s\n", buffer);

    fclose(fp);
}

