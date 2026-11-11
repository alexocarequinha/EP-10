#include "teamlist.h"
#include <stdlib.h>

// Implementação do TAD TeamList com LISTA DUPLAMENTE ENCADEADA

struct node {
    Team *team;
    struct node *next;
    struct node *prev;
};

struct teamlist {
    struct node *head; 
    struct node *tail; 
    int size;          
};

TeamList *tl_create(void) {
    TeamList *tl = (TeamList *)malloc(sizeof(struct teamlist));
    if (tl != NULL) {
        tl->head = NULL;
        tl->tail = NULL;
        tl->size = 0;
    }
    return tl;
}

void tl_append(TeamList *tl, Team *t) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node != NULL) {
        new_node->team = t;
        new_node->next = NULL;
        new_node->prev = tl->tail;

        if (tl->tail != NULL) {
            tl->tail->next = new_node;
        } else {
            tl->head = new_node; 
        }
        tl->tail = new_node;
        tl->size++;
    }
}

int tl_size(TeamList *tl) {
    return tl->size;
}

Team *tl_get(TeamList *tl, int i) {
    if (i < 0 || i >= tl->size) return NULL;

    struct node *current = tl->head;
    for (int j = 0; j < i; j++) {
        current = current->next;
    }
    return current->team;
}

void tl_free(TeamList *tl) {
    if (tl != NULL) {
        struct node *current = tl->head;
        while (current != NULL) {
            struct node *next_node = current->next; 
            team_free(current->team);
            free(current);
            current = next_node;
        }
        free(tl);
    }
}