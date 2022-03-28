#include "sdb.h"

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */
  char *vname;
  char *vp;

} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */
char* get_name(){
	return NULL;
}


WP new_wp(int i){
	WP* p = (WP*)malloc(sizeof(WP));
	wp_pool[i].vname = get_name();
	wp_pool[i].vp = &p;
		return *p;

}

void free_wp(){
}
