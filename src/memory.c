#include <stdio.h>

void show_memory_info()
{
    FILE *fp;
    char line[256];

    fp = fopen("/proc/meminfo", "r");

    if(fp == NULL)
    {
        printf("Error opening /proc/meminfo\n");
        return;
    }

    printf("\n===== MEMORY INFORMATION =====\n");

    for(int i = 0; i < 5; i++)
    {
        fgets(line, sizeof(line), fp);
        printf("%s", line);
    }

    fclose(fp);
}
