
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

#define HASH_LIMIT 0.5

/*
 *  hash() - hash算法函数
 *
 *  tptr: hash 算法
 *  key: 关键字
 */
static int hash(const hash_t *tptr, const char *key) 
{
    unsigned int hash = 0;  
   
    while (*key)  
    {   
		//hash<<5-hash: hash*31; The seed can be: 31, 131, 1313 etc...
        hash = ((hash << 5) - hash) + (*key++);  
    }  
   
    return (hash & tptr->size);  

}

/*
 *  hash_init() - 初始化hash表.
 *
 *  tptr: 指向hash结构
 *  buckets: hash中桶的个数
 */
void hash_init(hash_t *tptr, int buckets) 
{

  /* 默认16桶 */
  if (buckets==0)
    buckets=16;

  /* 初始化 */
  tptr->entries=0;
  tptr->size=2;

  /* 确认桶的个数是2的n次方 */
  while (tptr->size < buckets) {
    tptr->size<<=1;
  } /* while */

  tptr->bucket=(hash_node_t **) calloc(tptr->size, sizeof(hash_node_t *));

  return;
}


/*
 *  hash_lookup() - 查找函数, 失败返回HASH_FAIL
 *
 *  tptr:  hash table
 *  key:   关键字
 */
int hash_lookup(const hash_t *tptr, const char *key) 
{
  int h;
  hash_node_t *node;

  /* 查询key对应的值 */
  h=hash(tptr, key);
  for (node=tptr->bucket[h]; node!=NULL; node=node->next)
  {
    if (!strcmp(node->key, key))
      break;
  }

  /* 返回数据值, or HASH_FAIL */
  return(node ? node->data : HASH_FAIL);
}

/*
 *  hash_insert() - 插入到hash表中
 *
 *  tptr: hash 表
 *  key: 关键字
 *  data: 数据
 */
int hash_insert(hash_t *tptr, const char *key, int data) 
{
  int tmp;
  hash_node_t *node;
  int h;

  /* 如果存在,直接返回节点值 */
  if ((tmp=hash_lookup(tptr, key)) != HASH_FAIL)
    return(tmp);

  /* 插入到指定位置 */
  h=hash(tptr, key);
  node=(struct hash_node_t *) malloc(sizeof(hash_node_t));
  node->data=data;
  node->key=(char*)malloc(strlen(key)+1);
  strcpy(node->key, key);
  node->key[strlen(key)] = '\0';
  node->next=tptr->bucket[h];
  tptr->bucket[h]=node;
  tptr->entries++;

  return HASH_FAIL;
}


/*
 * hash_destroy() - 清空hash表
 * 
 */
void hash_destroy(hash_t *tptr) 
{
  hash_node_t *node, *last;
  int i;

  for (i=0; i<tptr->size; i++) 
  {
    node = tptr->bucket[i];
    while (node != NULL)
    { 
      last = node;   
      node = node->next;
      free(last->key);
      free(last);
    }
  }     

  /* 释放桶数据 */
  if (tptr->bucket != NULL) 
  {
    free(tptr->bucket);
    memset(tptr, 0, sizeof(hash_t));
  }
}


