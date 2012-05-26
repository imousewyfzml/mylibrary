#ifndef HASH_H
#define HASH_H

typedef struct hash_t 
{
  struct hash_node_t **bucket;        /* array of hash nodes */
  int size;                           /* size of the array */
  int entries;                        /* number of entries in table */
  int downshift;                      /* shift cound, used in hash function */
  int mask;                           /* used to select bits for hashing */
} hash_t;

#define HASH_FAIL -1

#ifdef __cplusplus
extern "C" {
#endif

void hash_init(hash_t *, int);

int hash_lookup (const hash_t *, const char *);

int hash_insert (hash_t *, const char *, int);

int hash_delete (hash_t *, const char *);

void hash_destroy(hash_t *);

char *hash_stats (hash_t *);

#ifdef __cplusplus
}
#endif

#endif


