/*
 *	Code adapted from:
 *		The practice of programming/Brian W. Kernighan and Rob Pike,
 *			Addison-Wesley professional computing series, 1999.
 *			ISBN 0-201-61586-X
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LLvNode_Tail.h"


/*
 * llNewNode: create and initialize data
 */
LLvNode *
llNewNode(char *key, long value)
{
	LLvNode *newp;

	newp = (LLvNode *) malloc(sizeof(LLvNode));

	/* assign data within new node */
	newp->key = key;
	newp->value = value;

	/* make sure we point at nothing */
	newp->next = NULL;

	return newp;
}


/*
 * llAppend: add newp to end of listp
 *
 * as above, we always return the value that
 * should be the new head of the list 
 */
// changed to account for a tail pointer
LLvNode * llAppend(LinkedList *listp, LLvNode *newp)
{
	if(listp == NULL) {
		return newp;
	}

	if(listp->tail == NULL) {
		// list is empty, both head and tail point to new node
		listp->head = newp;
		listp->tail = newp;
	} else {
		// update tail pointer to point at newp
		listp->tail->next = newp;
		listp->tail = newp;
	}

	return listp->head;
}

/* llApplyFn: execute fn for each element of listp */
void
llApplyFn(LLvNode *listp, void (*fn)(LLvNode*, void*), void *arg)
{
	for ( ; listp != NULL; listp = listp->next)
		(*fn)(listp, arg); /* call the function */
}


/* llFree : free all elements of listp */
void
llFree(LLvNode *listp, void (*userDeleteFn)(LLvNode*, void*), void *arg)
{
	LLvNode *next;

	for ( ; listp != NULL; listp = next) {

		/** hang on to the next pointer */
		next = listp->next;

		/** call the user function, if provided */
		if (userDeleteFn != NULL)
			(*userDeleteFn)(listp, arg);

		/** free the list node itself */
		free(listp);
	}
}

