#include <stdio.h>

void show_memory_info()
{
    FILE *fp;
    char line[256];

    unsigned long memTotal = 0;
    unsigned long memAvailable = 0;
    unsigned long memFree = 0;
    unsigned long buffers = 0;
    unsigned long cached = 0;

    float memoryUsage;

    fp = fopen("/proc/meminfo", "r");

    if (fp == NULL)
    {
        printf("Error opening /proc/meminfo\n");
        return;
    }

    /* Read the entire meminfo file */
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        sscanf(line, "MemTotal: %lu", &memTotal);
        sscanf(line, "MemAvailable: %lu", &memAvailable);
        sscanf(line, "MemFree: %lu", &memFree);
        sscanf(line, "Buffers: %lu", &buffers);
        sscanf(line, "Cached: %lu", &cached);
    }

    fclose(fp);

    /* Calculate Memory Usage Percentage */
    memoryUsage = ((float)(memTotal - memAvailable) / memTotal) * 100.0;

    printf("\n========== MEMORY INFORMATION ==========\n\n");

    printf("Total Memory      : %lu kB\n", memTotal);
    printf("Free Memory       : %lu kB\n", memFree);
    printf("Available Memory  : %lu kB\n", memAvailable);
    printf("Buffers           : %lu kB\n", buffers);
    printf("Cached            : %lu kB\n", cached);

    printf("----------------------------------------\n");
    printf("Memory Usage      : %.2f %%\n", memoryUsage);
}
