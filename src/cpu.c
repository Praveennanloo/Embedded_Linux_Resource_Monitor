#include <stdio.h>
#include <string.h>
#include <unistd.h>

void show_cpu_info()
{

char line[256];
char cpuModel[256] = "";
float cpuMHz = 0.0;
int cpuCores = 0;
FILE *cpuInfo;
    FILE *fp;
    char buffer[256];

    /* First Reading Variables */
    unsigned long user1, nice1, system1, idle1;
    unsigned long iowait1, irq1, softirq1, steal1;

    /* Second Reading Variables */
    unsigned long user2, nice2, system2, idle2;
    unsigned long iowait2, irq2, softirq2, steal2;

    /* Calculation Variables */
    unsigned long total1, total2;
    unsigned long idle_total1, idle_total2;
    unsigned long total_diff, idle_diff;

    float cpu_usage;

    /* ================= FIRST READING ================= */

    fp = fopen("/proc/stat", "r");

    if (fp == NULL)
    {
        printf("Error opening /proc/stat\n");
        return;
    }

    if (fgets(buffer, sizeof(buffer), fp) == NULL)
    {
        printf("Error reading /proc/stat\n");
        fclose(fp);
        return;
    }

    printf("\nFirst Read : %s", buffer);

    sscanf(buffer,
           "cpu %lu %lu %lu %lu %lu %lu %lu %lu",
           &user1,
           &nice1,
           &system1,
           &idle1,
           &iowait1,
           &irq1,
           &softirq1,
           &steal1);

    fclose(fp);

    /* Wait 1 second */
    sleep(1);

    /* ================= SECOND READING ================= */

    fp = fopen("/proc/stat", "r");

    if (fp == NULL)
    {
        printf("Error opening /proc/stat\n");
        return;
    }

    if (fgets(buffer, sizeof(buffer), fp) == NULL)
    {
        printf("Error reading /proc/stat\n");
        fclose(fp);
        return;
    }

    printf("Second Read: %s", buffer);

    sscanf(buffer,
           "cpu %lu %lu %lu %lu %lu %lu %lu %lu",
           &user2,
           &nice2,
           &system2,
           &idle2,
           &iowait2,
           &irq2,
           &softirq2,
           &steal2);

    fclose(fp);

    /* ================= CALCULATIONS ================= */

    total1 = user1 + nice1 + system1 + idle1 +
             iowait1 + irq1 + softirq1 + steal1;

    total2 = user2 + nice2 + system2 + idle2 +
             iowait2 + irq2 + softirq2 + steal2;

    idle_total1 = idle1 + iowait1;
    idle_total2 = idle2 + iowait2;

    total_diff = total2 - total1;
    idle_diff = idle_total2 - idle_total1;

    printf("\n\n========== DEBUG ==========\n");
    printf("Total1      : %lu\n", total1);
    printf("Total2      : %lu\n", total2);
    printf("Idle1       : %lu\n", idle_total1);
    printf("Idle2       : %lu\n", idle_total2);
    printf("Total Diff  : %lu\n", total_diff);
    printf("Idle Diff   : %lu\n", idle_diff);

    printf("\n========== CPU INFORMATION ==========\n");

    if (total_diff == 0)
    {
        printf("CPU Usage : Cannot Calculate\n");
        return;
    }

    cpu_usage = ((float)(total_diff - idle_diff) * 100.0f) / (float)total_diff;

    printf("User Time   : %lu\n", user2);
    printf("System Time : %lu\n", system2);
    printf("Idle Time   : %lu\n", idle2);
    printf("IO Wait     : %lu\n", iowait2);

    printf("--------------------------------------\n");
printf("CPU Usage   : %.2f %%\n", cpu_usage);

/* Read CPU information */
cpuInfo = fopen("/proc/cpuinfo", "r");

if (cpuInfo == NULL)
{
    printf("Error opening /proc/cpuinfo\n");
    return;
}

while (fgets(line, sizeof(line), cpuInfo) != NULL)
{
    if (strncmp(line, "model name", 10) == 0)
    {
        sscanf(line, "model name : %[^\n]", cpuModel);
    }

    if (strncmp(line, "cpu MHz", 7) == 0)
    {
        sscanf(line, "cpu MHz : %f", &cpuMHz);
    }

    if (strncmp(line, "cpu cores", 9) == 0)
    {
        sscanf(line, "cpu cores : %d", &cpuCores);
    }
}

fclose(cpuInfo);

printf("\n===== CPU DETAILS =====\n");
printf("CPU Model : %s\n", cpuModel);
printf("CPU Clock : %.2f MHz\n", cpuMHz);
printf("CPU Cores : %d\n", cpuCores);
}
