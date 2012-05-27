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
/* X... .... .... .... */
#define QUERY    0
#define RESPONSE 1
#define GET_OP_TYPE(flags) (flags>>15)
#define SET_OP_TYPE(flags, bit)   (flags |= bit<<15)
/* .XXX X... .... .... */
#define OPCODE_STD_QUERY 0 /* 标准查询 */
                           /* 反向查询 */
                           /* 服务器状态查询 */
#define GET_OP_CODE(flags) ((flags & 0x7800)>>11)
#define SET_OP_CODE(flags, code) (flags |= (code<<11))
/* .... .X.. .... .... */
#define ANTH_ANSWER
/* .... ..X. .... .... */ 
#define TRUNCATED_NO 0   /* 报文截断 */
#define TRUNCATED_YES 1 
/* .... ...X .... .... */
#define RECURSION_NEED 1  /* 需要递归 */
/* .... .... X... .... */
#define RECURSION_YES 1   /* 有递归 */
/* .... .... .XXX .... */
                          /* 保留 */
/* .... .... .... XXXX */ 
#define NO_ERROR   0      /* 无差错 */
#define QUERY_ERROR 1     /*  */
#define SERVER_UNAVAILABLE 2 /* 服务器无效 */
#define NAME_NO_EXISTS     3 /* 名字不存在 */
#define GET_RETCODE(flags) (flags & 0x000F)


/* 查询报文 */
struct query_seg
{
    char *name;
    unsigned short type;
    unsigned short class;
};


/* 响应报文 */
struct answer_seg 
{
    char *name;
    unsigned short type;
    unsigned short class;
    unsigned long  ttl;
    unsigned short dlen;
    unsigned char appdata[1];
};

/* quey type */
#define TYPE_A   (0x01) /* 指定计算机IP地址 */
#define TYPE_NS  (0x02) /* 指定命名区域dns服务器 */

#define CLASS_IN  (0x01) /* internet类别 */


