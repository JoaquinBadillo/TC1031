#ifndef NIL_H
#define NIL_H

#include <limits.h>
#include <stdlib.h>
#include "priorityQueue.h"

// NIL Sentinel
struct node nil_node = {.key = INT_MAX, .data = 0, .color = BLACK, .parent = &nil_node, .left = &nil_node, .right = &nil_node};
struct node* NIL = &nil_node;

#endif