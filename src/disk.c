#include <stdio.h>
#include <stdlib.h>

void show_disk_info()
{
    printf("\n===== DISK INFORMATION =====\n");

    system("df -h");
}
