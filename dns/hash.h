#ifndef HASH_H
#define HASH_H

typedef struct hash_node_t {
  int data;                           /* data in hash node */
  char * key;                   /* key for hash lookup */
  struct hash_node_t *next;           /* next node in hash chain */
} hash_node_t;

typedef struct hash_t 
{
  struct hash_node_t **bucket;        /* hash桶节点 */
  int size;                           /* 桶个数 */
  int entries;                        /* 数据总的个数 */
} hash_t;

#define HASH_FAIL -1

#ifdef __cplusplus
extern "C" {
#endif

void hash_init(hash_t *, int);

int hash_lookup (const hash_t *, const char *);

int hash_insert (hash_t *, const char *, int);

void hash_destroy(hash_t *);


#ifdef __cplusplus
}
#endif

#endif


