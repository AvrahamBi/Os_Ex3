// Avraham Bar ILan 205937949

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#define SIZE 151

// case insensitive
int isSameChar(char *c1, char *c2) {
    // if c1 and c2 are both letters
    if ((97 <= *c1 && *c1 <= 122 || 65 <= *c1 && *c1 <= 90) &&
            (97 <= *c2 && *c2 <= 122 || 65 <= *c2 && *c2 <= 90)) {
        if(abs(*c1 - *c2) == 32) {
            return 1;
        }
    }
    return 0;
}

int main( int argc, char *argv[] ) {
    int isIdentical = 1, isSimilar = 1;
    int file1Fd, file2Fd;
    char buffer1[SIZE], buffer2[SIZE];
    int numOfBytesFile1 = 0, totalBytesFile1 = 0;
    int numOfBytesFile2 = 0, totalBytesFile2 = 0;

    file1Fd = open(argv[1], O_RDONLY);
    if (file1Fd < 0) { printf("open Failed");}
    file2Fd = open(argv[2], O_RDONLY);
    if (file2Fd < 0) { printf("open Failed");}

    int x = 0;
    while (x < SIZE) {
        numOfBytesFile1 = read(file1Fd, buffer1 + totalBytesFile1, 1);
        totalBytesFile1 += numOfBytesFile1;
        numOfBytesFile2 = read(file2Fd, buffer2 + totalBytesFile2, 1);
        totalBytesFile2 += numOfBytesFile2;
        x++;
    }
    printf("%s\n", buffer1);
    printf("%s\n", buffer2);
    close(file1Fd);
    close(file2Fd);
    char char1, char2;
    int offset1 = 0, offset2 = 0;
    int i = 0;
    for (; i < SIZE; i++) {
        char1 = buffer1[i + offset1];
        char2 = buffer2[i + offset2];

        // if files end
        if (!char1 && !char2) {break;}
        // if the two chars are identical
        if (char1 == char2) {
            continue;
        } else {
            isIdentical = 0;
            // 13 is the ascii value of \n, 32 is the ascii value of space
            if ((char1 == '\r' || char1 == '\n' || char1 == 32)
                && (char2 == '\r' || char2 == '\n' || char2 == 32)) {
                continue;
            }
            if (char1 == '\r' || char1 == '\n' || char1 == 32) {
                offset2--;
                continue;
            }
            if (char2 == '\r' || char2 == '\n' || char2 == 32) {
                offset1--;
                continue;
            }
            if(isSameChar(&char1, &char2)) {
                continue;
            } else {
                isSimilar = 0;
                printf("different");
                return 2;
            }
        }
    }
    if(isIdentical) {printf("identical"); return 1;}
    if(isSimilar) {printf("same"); return 3;}
}