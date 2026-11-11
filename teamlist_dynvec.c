#include "teamlist.h"
#include <stdlib.h>

// Implementação do TAD TeamList com VETOR DINÂMICO
struct teamlist {
    Team **teams;
    int size;
    int capacity;
};

TeamList *tl_create(void) {
    TeamList *tl = (TeamList *)malloc(sizeof(struct teamlist));
    if (tl != NULL) {
        tl->capacity = 4;
        tl->size = 0;
        tl->teams = (Team **)malloc(tl->capacity * sizeof(Team *));
    }
    return tl;
}

void tl_append(TeamList *tl, Team *t) {
    if (tl->size == tl->capacity) {
        tl->capacity *= 2;
        tl->teams = (Team **)realloc(tl->teams, tl->capacity * sizeof(Team *));
    }
    tl->teams[tl->size] = t;
    tl->size++;
}

int tl_size(TeamList *tl) {
    return tl->size;
}

Team *tl_get(TeamList *tl, int i) {
    if (i >= 0 && i < tl->size) {
        return tl->teams[i];
    }
    return NULL;
}

void tl_free(TeamList *tl) {
    if (tl != NULL) {
        for (int i = 0; i < tl->size; i++) {
            team_free(tl->teams[i]);
        }
        free(tl->teams);
        free(tl);
    }
}