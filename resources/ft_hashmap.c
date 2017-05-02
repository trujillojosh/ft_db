#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

/* pretty basic hash table implementation
*  probably gonna change some stuff later on but hopefully this is enough to get it working
**/

//Struct for the entry in the hash table
typedef struct	s_hash_entry
{
	char	*key; //key value, stored as a string but converted to int later on
	void	*value; //hash value to be associated with the inserted key
	struct 	s_hash_entry *next; //next pointer
}				t_hash_entry;

//struct for the hashtable
typedef struct	s_hashtable
{
	int						size; //size of the hashtable grabbed from user input maybe????
	struct	s_hash_entry	**table; //char ** for the linked list table. need to look at this more later
}				t_hashtable;

/* creates a new hashtable and returns it */
t_hashtable		ft_create_table(int size)
{
	t_hashtable	*hashtable = NULL;
	int			i = 0;
	
	if (size < 1)
		return (NULL);
	//malloc for the table
	if (!(hashtable = malloc(sizeof(t_hashtable))))
		return (NULL);
	//malloc for the head nodes in the table... not sure if needed
	if (!(hashtable->table = malloc(sizeof(t_hash_entry) * size)))
		return (NULL);
	while (i < size)
		hashtable->table[i++] = NULL; //creates an empty table to be populated later on
	hashtable->size = size; //stores the size value into the struct. maybe we can use this earlier so we dont have to do this step
	return (hashtable); //returns the created table
}

/* hashes a string being passed in and returns the hash value */
int		ft_hash(t_hashtable *hashtable, char *key)
{
	unsigned long int	hash_value = 0;
	unsigned long int	i = 0;
	while (hash_value < ULONG_MAX && i < strlen (key))
	{
		hash_val = hashval << 8; //using bitwise operators
		hash_val += key[i++];
	}
	return (hash_val % hashtable->size);
}

/* creates a new key/value pair */
t_hash_entry	*ft_newpair(t_hashtable *hashtable, char *key, void *value, int size)
{
	t_hash_entry	*newpair;
	
	if (!(newpair = malloc(sizeof(t_hash_entry))))
		return (NULL);
	if (!(newpair->key = strdup(key)))
		return (NULL);
	if (!(newpair->value = malloc(size)))
		return (NULL);
	memcpy(newpair->value, value, size);
	newpair->next = NULL;
	return (newpair);
}

/* inserts a key/value pair into the hash table */
void			ft_set_hash(t_hashtable	*hashtable, void *value, char *key, int size)
{
	int bin = ft_hash(hashtable, key);
	t_entry	*next = NULL;
	t_entry	*last = NULL;
	
	next = hashtable->table[bin];
	//iterates through and while the key is not the same as the next one in the bin it sets the pointers of last and next
	//to the appropriate spot in the bin
	while (next != NULL && next->key != NULL && strcmp(key, next->key) > 0)
	{
		last = next;
		next = next->next;
	}
	
	//if there's already a pair at that index we replace it
	if (next != NULL && next->key != NULL && strcmp(key, next->key) == 0)
	{
		free(next->value);
		next->value = malloc(size);
		memcpy(next->value, value, size);
	}
	else //if there's no pair we can insert it easily
	{
		t_entry	*newpair = NULL;
		newpair = ft_newpair(key, value, size);
		if (next == hashtable->table[bin]) //we're at the beginning of the list in this particular bin
		{
			next->next = next;
			hashtable->table[bin] = newpair;
		}
		else if (next == NULL) //we're at the end of the list
			last->next = newpair;
		else //we're somewhere in the middle
		{
			newpair->next = next;
			last->next = newpair;
		}
	}
}

/* searches and tries to find the matching pair
char	*ft_get_value(t_hashtable *hashtable, char *key)
{
	int	bin = ft_hash(hashtable, key);
	t_entry	*pair = hashtable->table[bin];

	while (pair->key != NULL && pair != NULL && strcmp(pair->key, key) > 0) //iterates through the bin looking for the value
		pair = pair->next;
	if (pair == NULL || pair->key == NULL) //if we didnt find it, return null
		return (NULL);
	else
		return (pair->value); //yay we found it, returning the value
}
