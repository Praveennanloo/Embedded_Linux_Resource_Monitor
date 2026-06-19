#include <stdio.h>

void show_loadavg()
{
    FILE *fp;
    char load[100];

    fp = fopen("/proc/loadavg", "r");

    if(fp == NULL)
    {
        printf("Unable to open /proc/loadavg\n");
        return;
    }

    fgets(load, sizeof(load), fp);

    printf("\nSystem Load Average:\n%s\n", load);

    fclose(fp);
}
