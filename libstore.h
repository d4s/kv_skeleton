#ifndef libstore
#define libstore

typedef enum type { STRING, NUMBER, EMPTY } type;

typedef union value value;
union value {
	int num;
	char *str;
};

typedef struct store store;
struct store {
	store *next;
	char *key;
	type type;
	value val;
};

extern store *
create_store();

extern int
remove_store(store *s);

extern int
dump_store(store *s);

extern int
add_number(store *s, char *key, int value);

extern int
add_string(store *s, char *key, char *value);

extern int
remove_key(store *s, char *key);

extern char *
get_value_by_key(store *s, char *key);

#endif
