//
//  SDListReverse.c
//  SDListReverse
//
//  Created by Eugene Garifullin on 16/10/2018.
//

#include <stdio.h>
#include <stdlib.h>

/// List node structure
typedef struct ListNode {
    unsigned int value;
    struct ListNode* nextNode;
} ListNode;

/// Builds single referenced list with count
ListNode* buildList(unsigned int nodesCount){
    struct ListNode *lastNode = NULL;
    struct ListNode *list = NULL;
    for (unsigned int count = 0; count < nodesCount; count++){
        if (!list){
            list = (struct ListNode *)malloc(sizeof(struct ListNode));
            if (!list) break;
            
            lastNode = list;
            lastNode->nextNode = NULL;
            lastNode->value = count;
            continue;
        }
        
        lastNode->nextNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (!lastNode->nextNode)
            break;
        lastNode->nextNode->nextNode = NULL;
        lastNode->nextNode->value = count;
        lastNode = lastNode->nextNode;
    }
    return list;
}

/// Recursively removes all of nodes in list
void freeList(struct ListNode *list){
    struct ListNode *currentNode = list;
    while (currentNode) {
        struct ListNode *nextNode = currentNode->nextNode;
        free(currentNode);
        currentNode = nextNode;
    }
}

/// Iterates all list and prints value of each node
void iterateList(struct ListNode *list){
    struct ListNode *currentNode = list;
    while (currentNode){
        struct ListNode *nextNode = currentNode->nextNode;
        printf("Iterating list: %u\n", currentNode->value);
        currentNode = nextNode;
    }
}

/// Reverses single referenced list
struct ListNode* reverseList(struct ListNode *list){
    if (!list || !list->nextNode)
        return list;
    
    struct ListNode *curr = list->nextNode;
    list->nextNode = NULL;
    
    while (curr){
        struct ListNode *feat = curr->nextNode;
        curr->nextNode = list;
        list = curr;
        curr = feat;
    }
    
    return list;
    
}

/// Application entry point
int main(int argc, const char * argv[]) {

    const int listCount = 5000000;
    
    // Building list
    struct ListNode *list = buildList(listCount);
    
    // Reversing list
    list = reverseList(list);
    
    // Dellocating memory
    freeList(list);
    
    return 0;
}
