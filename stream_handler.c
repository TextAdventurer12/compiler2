#include "stream_handler.h"

size_t min(size_t a, size_t b)
{
    return a > b ? b : a;
}

stream_handler create_stream(size_t len)
{
    stream_handler rt =
    {
        fmemopen(NULL, len, "r+"),
        len,
        0
    };
    setbuf(rt.stream, NULL);
    return rt;
}

int __stremcpy(FILE *dst, FILE *src)
{
    char ch;
    while ((ch = fgetc(src)) != EOF)
        fprintf(dst, "%c", ch);
    return 0;
}

int __stremncpy(FILE *dst, FILE *src, size_t n)
{
    char ch;
    for (int i = 0; (ch = fgetc(dst)) != EOF && i < n; i++)
        fprintf(dst, "%c", ch);
    return 0;
}

int stremcpy(stream_handler *dst, stream_handler *src)
{
    size_t src_len = strmlen(src->stream);
    if (dst->len < dst->index + src_len)
        if (grow_stream(dst, dst->len - (dst->index + src_len)))
            return 1;
    if (__stremcpy(dst->stream, src->stream)) return 1;
    fseek(dst->stream, dst->index, SEEK_SET);
    fseek(src->stream, src->index, SEEK_SET);
    return 0;
}

int stremncpy(stream_handler *dst, stream_handler *src, size_t n)
{
    size_t src_len = strmlen(src->stream);
    if (dst->len < min(dst->index + src_len, n))
        if (grow_stream(dst, dst->len - (dst->index + src_len)))
            return 1;
    if (__stremncpy(dst->stream, src->stream, n)) return 1;
    fseek(dst->stream, dst->index, SEEK_SET);
    fseek(src->stream, src->index, SEEK_SET);
    return 0;
}

size_t strmlen(FILE *stream)
{
    long _ind = ftell(stream);
    size_t len;
    for (len = 0; fgetc(stream) != EOF; len++);
    fseek(stream, _ind, SEEK_SET);
    return len;
}

int grow_stream(stream_handler *stream, size_t n)
{
    FILE *new_stream = fmemopen(NULL, stream->len + n, "r+");
    if (!new_stream)
        return 1;
    fclose(stream->stream);
    stream->stream = new_stream;
    stream->len += n;
    fseek(stream->stream, stream->index, SEEK_SET);
    return 0;
}

int __stream_add(stream_handler *stream, const string content)
{
    size_t cont_len = strlen(content);
    if (stream->len < stream->index + cont_len);
}