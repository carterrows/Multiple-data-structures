/*
 *	Code adapted from:
 *		The practice of programming/Brian W. Kernighan and Rob Pike,
 *			Addison-Wesley professional computing series, 1999.
 *			ISBN 0-201-61586-X
 *
 */

#ifndef	__LINKED_LIST_VOID_PAYLOAD_HEADER__
#define	__LINKED_LIST_VOID_PAYLOAD_HEADER__

/*
 * define our types
 */
typedef struct LLvNode LLvNode;

struct LLvNode {
	char *key;
	long value;
	struct LLvNode *next;
};

typedef struct LinkedList LinkedList;

struct LinkedList {
	LLvNode *head;
	LLvNode *tail;
};



/* llNewNode: create and initialize data */
LLvNode *llNewNode(char *key, long value);

/* llAppend: add newp to end of listp */
LLvNode * llAppend(LinkedList *listp, LLvNode *newp);

/* llApplyFn: execute fn for each element of listp */
void llApplyFn(LLvNode *listp, void (*fn)(LLvNode*, void*), void *arg);

/* llFree : free all elements of listp */
void llFree(LLvNode *listp, void (*userDeleteFn)(LLvNode*, void*), void *arg);

#endif /*	__LINKED_LIST_VOID_PAYLOAD_HEADER__ */
