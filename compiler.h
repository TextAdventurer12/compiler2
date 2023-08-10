#ifndef COMPILER_H
#define COMPILER_H

#include "tokenizer.h"
#include "definitions.h"
#include <stdio.h>

int compile(FILE *src, FILE *dst, FILE *err);

#endif