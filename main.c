#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"
#include "tokenizer.h"
#include "preprocess.h"
#include <string.h>

int process(FILE *src, FILE *dst, FILE *err)
{
    FILE *processed = fmemopen(NULL, , "r+")
    const token_list *input = tokenize(src, err);
    token_list *head = input;
    while (head->next)
    {
        char proc_line[BUF_SIZE];
        int line_len = 0;
        for (int i = 0; i < head->token_count; i++)
            line_len += strlen(head->line[i]);
        char line[line_len];
        for (int i = 0; i < head->token_count; i++)
            strcat(line, head->line[i]);
        preprocess()
    }
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

    stream = fmemopen(NULL, BUF_SIZE, "a+");
    fprintf(stream, "testing");
    fseek(stream, 0, SEEK_SET);
    while ((ch = fgetc(stream)) != EOF)
        printf("%c\n", ch);
    fclose(stream);
    return 0;
}