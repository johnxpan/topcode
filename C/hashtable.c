#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

//hash table array size NHASH better be prime number
enum { MULTIPLIER=31, NHASH = 53 };

struct entry{
	char *key;
	char *value; // could be integer too
	struct entry *next;
};
 
typedef struct entry Entry;
// an array of linked list
Entry *hashTab[NHASH];

//hash compute hash value of string 
//use prime multiplier like 31, or 37
unsigned int hash(char *str) {
   unsigned int h;
   unsigned char *p;
   h=0;
   for(p=(unsigned char *) str; *p!= '\0'; p++) {
      h = MULTIPLIER*h + *p;
   }
   return h%NHASH;
}
// the combination of lookup and insertation
Entry *hashLookup (char *key, int create, char *value) {
   int h;
   Entry *sym;

   h = hash(key);
   for (sym = hashTab[h]; sym != NULL; sym=sym->next) {
      if(strcmp(key, sym->key ) == 0) {
          return sym;
      }
   }
   if(create) {
      sym = (Entry *) malloc(sizeof(Entry));
      if(sym == NULL) {
          return NULL;
      }
      sym->key = (char *)malloc(strlen(key)+1);
      sym->value=(char *)malloc(strlen(value)+1);
      //sym->key = key; // assume allocated elsewhere
      strcpy(sym->key , key); // assume allocated elsewhere
      strcpy(sym->value, value);
      //sym->value = value;
      sym->next = hashTab[h];
      hashTab[h] = sym;
   }
   return sym;
}


int main( int argc, char **argv ) {
    Entry *a, *b, *c;
 
    hashLookup("jun",1, "peach");
    hashLookup("joy",2, "plum");
    hashLookup("john",3, "apple");
    hashLookup("jessica",4, "banana");
    hashLookup("jamaka",5, "kiwi");
 
	a=hashLookup( "jessica",0, NULL ) ;
	b=hashLookup( "john",0, NULL );
	c=hashLookup( "jun",0, NULL );
	printf( "%s=>%s\n", a->key, a->value );
	printf( "%s=>%s\n", b->key, b->value );
	printf( "%s=>%s\n", c->key, c->value );
 
	return 0;
}
