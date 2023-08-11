#ifndef STREAM_HANDLER_H
#define STREAM_HANDLER_H

#include <stdio.h>
#include "definitions.h"

typedef struct __stream_handler
{
    FILE *stream;
    size_t len;
    size_t __index;
} stream_handler;


// makes a new stream_handler of size len
// NOTE: the stream_add function will automatically resize the stream, however it is safest to pre-allocate all needed bytes
stream_handler create_stream(size_t len);
// copies the content of src to dst
int stremcpy(stream_handler *dst, stream_handler *src);
// copies the content of src to dst
// private method used by stremcpy()
// dst must be large enough to fit src
int __stremcpy(FILE *dst, FILE *src);
// appends the string content to the current index of the string
// auto resizes the stream to fit
int stream_add(stream_handler *stream, const string content);
// removes n bytes from the end of the stream
int stream_remove(stream_handler *stream, size_t n);
// auto closes stream
int delete_stream(stream_handler *stream);

#endif