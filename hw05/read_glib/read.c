#include <glib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Takes in a gchar pointer to a filename and returns a
pointer to a gchar* array containing all the words from
the file */
gchar** read_file(gchar *filename) {
	GError *err = NULL;
	gchar *text;
	gboolean result;
	result = g_file_get_contents(filename, &text, NULL, &err);
	if (err != NULL) {
		(void) fprintf(stderr, "Get contents failed");
		exit(G_FILE_ERROR);
	}
	gchar **words = NULL;
	gchar *delimit = ".,:; ";
	words = g_strsplit_set(text, delimit, -1);
}

/* Takes in pointers to a GHashTable and one of its keys,
increments the value of the key by 1, and returns 1 to
indicate a successful incrementation */
int increment(GHashTable *hash, char *key) {
	guint *value = (guint*) g_hash_table_lookup(hash, key);
	*value += 1;
	g_hash_table_insert(hash, key, value);
	return 1;
}

/* Takes in pointers to a GHashTable and one of its keys.
If the key is already in the table, it calls increment().
If not, new space is allocated for a value, and the key
with a value of 1 is added to the GHashTable */
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
		if (check == 0) {
			(void) fprintf(stderr, "Incrementing failed.");
        	exit(EXIT_FAILURE);
		}

	}
}

/* Takes in a pointer to a gchar* array of words, and builds
and returns a GHashTable from them that maps from words to
their frequencies by calling add_word() on each word */
GHashTable* make_hashtable(gchar** words) {
	int i=0;
	GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);	
	if (hash == NULL) {
        (void) fprintf(stderr, "Hash creation failed.");
        exit(EXIT_FAILURE);
    }
	while (words[i+1] != NULL) {
		if (!(*words[i] == 0)) {
			add_word(hash, words[i]);
		}
		i++;
	}
	return hash;
}

/* Takes in a pointer to a GHashTable and uses a 
GHashTableIter to iterate through its elements and print 
each word and its frequency */
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

/* Takes in a pointer to a *gchar array and frees it */
void free_array(gchar** array) {
	g_strfreev(array);
}

/* Reads the lorem.txt file, builds a GHashTable of its
words and frequencies, and then calls print_list to print
them */
int main() {
	gchar **words = read_file("lorem.txt");
	GHashTable *hash = make_hashtable(words);
	print_list(hash);
	free_array(words);
	g_hash_table_destroy(hash);
	return 0;
}