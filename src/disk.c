#include <stdio.h>
#include <sys/statvfs.h>

void show_disk_info()
{
    struct statvfs disk;

    if (statvfs("/", &disk) != 0)
    {
        printf("Error reading disk information.\n");
        return;
    }

    unsigned long long total;
    unsigned long long free;
    unsigned long long available;
    unsigned long long used;

    float usage;

    total = (unsigned long long)disk.f_blocks * disk.f_frsize;
    free = (unsigned long long)disk.f_bfree * disk.f_frsize;
    available = (unsigned long long)disk.f_bavail * disk.f_frsize;
    used = total - free;

    usage = ((float)used / total) * 100.0;

    printf("\n========== DISK INFORMATION ==========\n\n");

    printf("Mount Point      : /\n");
    printf("Total Space      : %.2f GB\n", total / (1024.0 * 1024 * 1024));
    printf("Used Space       : %.2f GB\n", used / (1024.0 * 1024 * 1024));
    printf("Available Space  : %.2f GB\n", available / (1024.0 * 1024 * 1024));

    printf("--------------------------------------\n");

    printf("Disk Usage       : %.2f %%\n", usage);
}
