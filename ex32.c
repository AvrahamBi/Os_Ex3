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

    int NO_C_FILE = 1, COMPILATION_ERROR = 1, TIMEOUT = 1, WRONG = 1, SIMILAR = 1, EXCELLENT = 1;
    char *students[MAX_SIZE];
    i = 0;
    DIR *dip;
    DIR *studentDip;
    struct dirent *dit;
    struct dirent *studentDit;
    dip = opendir(lines[0]);
    char* nameOfStudent;
    char* fileName;
    char* backupFileName;
    char* grades[MAX_SIZE];
    char finalGrade[MAX_SIZE];
    int studentIndex = 0;

    // iterate over the directory
    while(dit = readdir(dip)/* != NULL*/) {
        nameOfStudent = dit->d_name;
        studentDip = opendir(nameOfStudent);
        // TODO here need to nullify the grades values
        // iterate over the files of the student
        while(studentDit  = readdir(studentDip) /* != NULL*/) {
            fileName = studentDit->d_name;
            backupFileName = studentDit->d_name;
            // if file is a .c file
            if(!strcmp(strrchr(fileName, '\0') - 2, ".c")) {
                NO_C_FILE = 0;
                // todo enter the command to execvp
                char *command = {"gcc", backupFileName, "", NULL};
                execvp(command[0], command);

            } else {
                // if no .c file found
                strcat(strcpy(finalGrade, nameOfStudent), ",0,NO_C_FILE");
                printf("%s\n", finalGrade);
                // enter the grade into the grades array
                grades[studentIndex] = finalGrade;
                break;
            }
        }
        studentIndex++;
    }
}
