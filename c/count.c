#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int is_regular_file(const char *path)
{
        struct stat path_stat;
        stat(path, &path_stat);
        return S_ISREG(path_stat.st_mode);
}

int main(int argc, char *argv[])
{
        if (argc != 2) {
                printf("Usage:\n\t./count filename.txt\n");
                exit(1);
        }

        if (!is_regular_file(argv[1])) {
                printf("argument must be a file!\n");
                exit(1);
        }

        int fd = open(argv[1], O_RDONLY);
        char buffer[1024];
        int i;
        int count = 0;
        ssize_t ret;

        while ((ret = read(fd, buffer, 1024)) != 0) {
                if (ret == -1) {
                        printf("Read error\n");
                        exit(1);
                }

                for (i=0; i < ret; i++) {
                        if (buffer[i] == '\n')
                                count++;
                }
        }

        printf("Number of lines: %d\n", count);
        close(fd);

        exit(0);
}
