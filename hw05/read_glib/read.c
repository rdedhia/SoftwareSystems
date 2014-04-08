#include <glib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

gchar** read_file() {
	gchar *filename = "lorem.txt";
	GError *err = NULL;
	gchar *text;
	gboolean result;
	result = g_file_get_contents(filename, &text, NULL, &err);
	gchar **words = NULL;
	gchar *delimit = ".,:; ";
	words = g_strsplit_set(text, delimit, -1);
}

int increment(GHashTable *hash, char *key) {
	guint *value = (guint*) g_hash_table_lookup(hash, key);
	*value += 1;
	g_hash_table_insert(hash, key, value);
	return 1;
}

void add_word(GHashTable *hash, char *key) {
	guint *val = g_malloc(sizeof(guint*));
	if (val == NULL) {
        (void) fprintf(stderr, "Malloc failed.");
        exit(EXIT_FAILURE);
    }
	*val = 1;
	guint flag = g_hash_table_contains(hash, key);
	if (!flag) {
		g_hash_table_insert(hash, key, val);
	} else {
		int check = increment(hash, key);
	}
}

GHashTable* make_hashtable(gchar** words) {
	int i=0;
	GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);	
	while (words[i+1] != NULL) {
		if (!(*words[i] == 0)) {
			add_word(hash, words[i]);
		}
		i++;
	}
	return hash;
}

void print_list(GHashTable *hash) {
	GHashTableIter iter; 
	gpointer key, value; 

	g_hash_table_iter_init (&iter, hash); 
	while (g_hash_table_iter_next (&iter, &key, &value)) {
	   g_print("\n%s -> %i", (gchar*) key, *((guint*) value));
	   g_free(value);
	}
	printf("\n\n");
}

void free_array(gchar** array) {
	g_strfreev(array);
}

int main() {
	gchar **words = read_file();
	GHashTable *hash = make_hashtable(words);
	print_list(hash);
	free_array(words);
	g_hash_table_destroy(hash);
	return 0;
}