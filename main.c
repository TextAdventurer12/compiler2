#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"
#include "tokenizer.h"
#include "preprocess.h"
#include <string.h>

int process(FILE *src, FILE *dst, FILE *err)
{
    FILE *processed = fmemopen(NULL, BUF_SIZE * 8, "r+");
    setbuf(processed, NULL);
    if (preprocess(src, processed, err))
        return 1;
    token_list *input = tokenize(processed, err);
    if (!input)
        return 2;
    if (compile(input, dst, err))
        return 3;
    return 0;
}

void print_stream(FILE *stream)
{
    fseek(stream, 0, SEEK_SET);
    char ch;
    while ((ch = fgetc(stream)) != EOF)
        printf("%c, ", ch);
    printf("\n");
}

int main(int argc, char **argv)
{
    if (argc != 4)
        return 1;
    FILE *err = fopen(argv[3], "w");
    FILE *dst = fopen(argv[2], "w");
    FILE *src = fopen(argv[1], "r");
    if (!err || !src || !dst)
        return 1;
    char ch;
    FILE *stream;

    stream = fmemopen(NULL, 6, "a+");
    setbuf(stream, NULL);   // this function invocation makes it so that if more than size bytes are written to the stream, then ftell will return the correct number of bytes are written. This allows detecting insufficient stream size
    fprintf(stream, "testing 123 this is really stupid");
    printf("%ld\n", ftell(stream));
    print_stream(stream);
    fclose(stream);
    return 0;
}