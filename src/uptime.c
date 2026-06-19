#include <stdio.h>

void show_uptime()
{
    FILE *fp;
    double uptime;

    fp = fopen("/proc/uptime", "r");

    if(fp == NULL)
    {
        printf("Error opening /proc/uptime\n");
        return;
    }

    fscanf(fp, "%lf", &uptime);

    printf("\n===== SYSTEM UPTIME =====\n");
    printf("Uptime: %.2f seconds\n", uptime);

    fclose(fp);
}
