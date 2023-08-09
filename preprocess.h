#ifndef PREPROCESS_H
#define PREPROCESS_H

#include "definitions.h"
#include <stdio.h>

typedef struct __macro_table
{
    struct __macro_table *next;
    string macro;
    string expansion;
    bool is_func;
} macro_table;

int preprocess(const string src, FILE *dst, FILE *err);
macro_table *gbl_tbl();
int push_gbl_tbl();

#endif