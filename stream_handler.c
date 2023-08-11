#include "stream_handler.h"

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
    {
        char tmp[1] = {ch};
        fprintf(dst, tmp);
    }
    return 1;
}

int stremcpy(stream_handler *dst, stream_handler *src)
{

}