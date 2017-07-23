#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define KB 1024
#define MB 1024 * KB

void print_usage_and_quit(char *progname) {
    printf("%s: -m <memory in MB> [-s <sleep time in seconds>]\n", progname);
    exit(EXIT_FAILURE);
}

int main (int argc, char** argv) {
    int total_mem = 0;
    int sleep_time = 0;
    int i = 0;
    char c = 0;
    char **mem = NULL;

    while ((c = getopt (argc, argv, "m:s:")) != -1) {
        switch (c) {
            case 'm':
                total_mem = atoi(optarg);
                break;
            case 's':
                sleep_time = atoi(optarg);
                break;
            default:
                print_usage_and_quit(argv[0]);
                break;
        }
    }

    if (total_mem <= 0) {
        print_usage_and_quit(argv[0]);
    }

    mem = (char**) calloc(total_mem, sizeof(char*));
    printf("Memory allocation test up to %d MB, sleeping %d seconds between allocations\n", total_mem, sleep_time);
    for (i = 0; i < total_mem; i++) {
        printf("Total allocation %d MB...", i);
        mem[i] = (char *) calloc(MB, sizeof(char));
        if (mem[i] != NULL) {
            memset(mem[i], 0xA, MB);
            printf("success!\n");
        } else {
            printf("fail.\n");
            break;
        }
        sleep(sleep_time);
    }
    printf("Successfully allocated %d MB\n", i);
    for (i = 0; i < total_mem; i++) {
        if (mem[i]) {
            free(mem[i]);
        }
    }
    free(mem);
    exit(EXIT_SUCCESS);
}

