/*
 * 协议报文格式定义
 */

struct dnshead
{
    unsigned short transaction_id;
    unsigned short flags;
    unsigned short questions;
    unsigned short answer_rrs;
    unsigned short authority_rrs; /* 不支持 */
    unsigned short additional_rrs; /* 不支持 */
};

/* flags 字段含义 */
/* X... .... .... ....*/
#define QUERY    0
#define RESPONSE 1
/* .XXX X... .... ....*/
#define OPCODE_STD_QUERY 0
/* .... ..X. .... ....*/
#define TRUNCATED_NO 0
#define TRUNCATED_YES 0
/* .... ...X .... ....*/




/* 查询报文 */
struct query_seg
{
    char *name;
    unsigned short type;
    unsigned short class;
};


/* 响应报文 */
struct answer_reg; 
{
    char *name;
    unsigned short type;
    unsigned short class;
    unsigned long  ttl;
    unsigned short dlen;
    unsigned char appdata[1];
};


