#include <stdio.h>
#include "../include/monitor.h"

int main()
{
    int choice;

    while(1)
    {
        printf("\n=========================\n");
        printf("Embedded Linux Monitor\n");
        printf("=========================\n");

        printf("1. CPU Information\n");
        printf("2. Memory Information\n");
        printf("3. Disk Information\n");
        printf("4. Uptime\n");
        printf("5. Load Average\n");
        printf("6. Running Processes\n");
        printf("7. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                show_cpu_info();
                break;

            case 2:
                show_memory_info();
                break;

            case 3:
                show_disk_info();
                break;
             case 4:
                   show_uptime();
                    break;
              case 5:
                   show_loadavg();
                      break;
              case 6:
                    show_processes();
                       break;
            case 7:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
