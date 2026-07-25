#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[])
{
    struct stat s;

    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if (stat(argv[1], &s) == -1)
    {
        perror("stat");
        return 1;
    }

    printf("=== File Attributes for: %s ===\n", argv[1]);

    if (S_ISREG(s.st_mode))
        printf("File Type: Regular File\n");
    else if (S_ISDIR(s.st_mode))
        printf("File Type: Directory\n");
    else
        printf("File Type: Other\n");

    printf("Permissions: %04o\n", s.st_mode & 0777);
    printf("File Size: %ld bytes\n", s.st_size);
    printf("Hard Links Count: %ld\n", s.st_nlink);
    printf("Owner (UID): %d\n", s.st_uid);
    printf("Group (GID): %d\n", s.st_gid);

    printf("Last Access Time: %s", ctime(&s.st_atime));
    printf("Last Modification: %s", ctime(&s.st_mtime));
    printf("Status Change Time: %s", ctime(&s.st_ctime));

    return 0;
}