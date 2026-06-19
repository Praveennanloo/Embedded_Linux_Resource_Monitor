#include <stdio.h>
#include <stdlib.h>

void show_processes()
{
    printf("\n===== RUNNING PROCESSES =====\n\n");

    system("ps aux | head -15");
}
