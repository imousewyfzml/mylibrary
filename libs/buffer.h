/* 封装对buffer的操作 */

struct buffer
{
    unsigned int size; /* 实际大小 */
    unsigned int len;  /* 内容长度 */
    unsigned int pos;  /* 当前引用指针位置 */
    char *buf;
};

int buffer_init(struct buffer *b, unsigned len);
struct buffer *buffer_append(struct buffer *dst, const char *src, unsigned int len);
