
#ifndef DNS_CACHE_H
#define DNS_CACHE_H 1

#include "pkt_info.h"

#include "tree.h"

/**
 * cache of dns requests
 */

#define MAX_SIZE 8000

typedef struct dns_cache_entry_s {
    tree_t* domains;
} dns_cache_entry_t;

// todo: make this a tree or dict
typedef struct {
    tree_t* entries;
} dns_cache_t;


dns_cache_entry_t* dns_cache_entry_create();
void dns_cache_entry_destroy(dns_cache_entry_t* dns_cache_entry);


dns_cache_t* dns_cache_create();
void dns_cache_destroy(dns_cache_t* dns_cache);

// note: this copies the data
void dns_cache_add(dns_cache_t* cache, dns_pkt_info_t* dns_pkt_info);
void dns_cache_clean();
void dns_cache_print(dns_cache_t* dns_cache);


#endif // DNS_CACHE_H