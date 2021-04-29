// Avraham Bar ILan 205937949

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>


// case insensitive
int isSameChar(char *c1, char *c2) {
    // if c1 and c2 are both letters
    if ((97 <= *c1 && *c1 <= 122 || 65 <= *c1 && *c1 <= 90) &&
            (97 <= *c2 && *c2 <= 122 || 65 <= *c2 && *c2 <= 90)) {
        if(abs(*c1 - *c2) == 32) {
            printf("The same");
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    char* f = argv[1];
    printf("\n%s\n", argv[1]);
    return 0;
}


