#ifndef NIL_H
#define NIL_H

#include <limits.h>
#include <stdlib.h>
#include "priorityQueue.h"

// NIL Sentinel
static struct node nil_node = {.key = INT_MAX, .data = 0, .color = BLACK, .parent = NULL, .left = NULL, .right = NULL};
static struct node* NIL = &nil_node;

#endif