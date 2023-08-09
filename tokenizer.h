#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "definitions.h"
#include <stdio.h>

typedef string token;

typedef struct __token_list
{
    struct __token_list *next;
    token *line;
    int token_count;
} token_list;

token_list *tokenize(FILE *src, FILE *err);
int read_next_line(FILE *src, token_list *dst, FILE *err);
token read_next_token(FILE *src, FILE *err);

#endif