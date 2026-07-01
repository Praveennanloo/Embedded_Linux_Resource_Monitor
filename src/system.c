#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

void show_system_info()
{
    struct utsname systemInfo;
    char hostname[256];

    /* Get hostname */
    gethostname(hostname, sizeof(hostname));

    /* Get system information */
    if (uname(&systemInfo) == -1)
    {
        printf("Error getting system information\n");
        return;
    }

    /* Get number of CPU cores */
    long cpuCores = sysconf(_SC_NPROCESSORS_ONLN);

    printf("\n========== SYSTEM INFORMATION ==========\n\n");

    printf("Hostname         : %s\n", hostname);
    printf("Operating System : %s\n", systemInfo.sysname);
    printf("Kernel Version   : %s\n", systemInfo.release);
    printf("Kernel Build     : %s\n", systemInfo.version);
    printf("Machine          : %s\n", systemInfo.machine);
    printf("CPU Cores        : %ld\n", cpuCores);
}
