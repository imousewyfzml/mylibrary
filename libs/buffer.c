#include <stdlib.h>
#include <string.h>
#include "buffer.h"

int buffer_init(struct buffer *b, unsigned int size)
{
    if (!b)
        return -1;
    b->buf = (char*)malloc(size);
    if (b->buf)
        return -1;
    b->size = size;
    b->len = 0;
    b->pos = 0;

    return 0;
}

struct buffer *buffer_append(struct buffer *dst, const char*src, unsigned int len)
{
    char *buf = NULL;

    if (!dst && !dst->buf)
        return NULL;

    if (!src || len == 0)
        return dst;

    if (dst->len + len > dst->size)
    {
        buf = dst->buf;
        buf = (char*)malloc(2*dst->len + len);
        if (buf == NULL)
        {
            return NULL;
        }
        memcpy(buf, dst->buf, dst->len);
        free(dst->buf);
        dst->size = 2*dst->len + len;    
    }

    memcpy(dst->buf+dst->len, src, len);

    return dst;
}

