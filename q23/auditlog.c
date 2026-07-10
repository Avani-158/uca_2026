#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define LOGFILE "audit.log"
#define BUF_SIZE 1

int main(int argc, char *argv[])
{
    int inputFd, openFlags;
    mode_t filePerms;
    ssize_t numRead;
    char buf[BUF_SIZE];

    if (argc < 2)
    {
        printf("Usage:\n");
        printf("./auditlog --add \"message\"\n");
        printf("./auditlog --view\n");
        exit(-1);
    }

    if (strcmp(argv[1], "--add") == 0)
    {
        if (argc != 3)
        {
            printf("Please enter a message.\n");
            exit(-1);
        }

        openFlags = O_CREAT | O_WRONLY | O_APPEND;
        filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

        inputFd = open(LOGFILE, openFlags, filePerms);

        if (inputFd == -1)
        {
            printf("Error opening log file.\n");
            exit(-1);
        }

        if (write(inputFd, argv[2], strlen(argv[2])) != strlen(argv[2]))
        {
            printf("Error writing to file.\n");
            close(inputFd);
            exit(-1);
        }

        write(inputFd, "\n", 1);

        close(inputFd);

        printf("Log Added Successfully.\n");
    }

    else if (strcmp(argv[1], "--view") == 0)
    {
        int line = 1;
        int newLine = 1;

        inputFd = open(LOGFILE, O_RDONLY);

        if (inputFd == -1)
        {
            printf("Error opening log file.\n");
            exit(-1);
        }

        while ((numRead = read(inputFd, buf, BUF_SIZE)) > 0)
        {
            if (newLine)
            {
                printf("%d: ", line);
                newLine = 0;
            }

            if (write(STDOUT_FILENO, buf, numRead) != numRead)
            {
                printf("Error writing output.\n");
                close(inputFd);
                exit(-1);
            }

            if (buf[0] == '\n')
            {
                line++;
                newLine = 1;
            }
        }

        close(inputFd);
    }

    else
    {
        printf("Invalid Command.\n");
    }

    return 0;
}