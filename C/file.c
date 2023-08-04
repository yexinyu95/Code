#include <stdio.h>
#include <stdlib.h>

int putfile(FILE *fpoint);
int putreverse(FILE *fpoint);

int main(int argc, char *argv[])
{
    FILE *fp;

    if (argc != 2)
    {
        printf("Usage: %s filename.\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "rb");

    if (fp == NULL)
    {
        printf("Can't open %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("%p.\n", fp);

    fclose(fp);

    return 0;
}

//  print each char and it's position from beginning 
int putfile(FILE *fpoint)
{
    char ch;
    unsigned long count = 0;

    while ((ch = getc(fpoint)) != EOF)
    {
        putc(ch, stdout);
        printf(": %ld,\n", ftell(fpoint));
        count ++;
    }

    printf("File has %lu characters.\n", count);

    return 0;
}

//  print each char and it's position in reverse
int putreverse(FILE *fpoint)
{
    char ch;
    long count;
    long last;

    fseek(fpoint, 0L, SEEK_END);
    last = ftell(fpoint);

    for (count = 1L; count <= last; count++)
    {
        fseek(fpoint, -count, SEEK_END);
        ch = getc(fpoint);
        putchar(ch);
        printf(": %ld,\n", count);
    }
    
    printf("File has %lu characters.\n", count);

    return 0;
}