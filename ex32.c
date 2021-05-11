// Avraham Bar ILan 205937949

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <string.h>
#define MAX_SIZE 150


int main( int argc, char *argv[] ) {
    int numOfBytes;
    char buffer[MAX_SIZE];
    char *lines[MAX_SIZE];
    int confiFd = open(argv[1], O_RDONLY);
    int x = 0;
    while(x < MAX_SIZE) {
        numOfBytes = read(confiFd, buffer + x, 1);
        x++;
    }
    close(confiFd);
    // split the buffer into lines
    int i = 0;
    char *delim = "\n";
    char* ptr = strtok(buffer, delim);
    // lines[0] is the first line of the file
    lines[i] = ptr;
    while(ptr != NULL) {
        ptr = strtok(NULL, delim);
        i++;
        lines[i] = ptr;
    }
    /*printf("1: %s\n", lines[0]);
    printf("2: %s\n", lines[1]);
    printf("3: %s\n", lines[2]);*/

    char *students[MAX_SIZE];
    i = 0;
    DIR *dip;
    struct dirent *dit;
    dip = opendir(lines[0]);
    // iterate over the directory
    while(dit = readdir(dip) != NULL) {
        // todo, now need to iterate over the students directories and search for c file to compile and run

    }

}
