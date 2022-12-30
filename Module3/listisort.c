#include <stdio.h>
#include <stdlib.h>

typedef struct Elem {
    struct Elem *prev, *next;
    int v;
} BCList;

int main() {
    // create a bidirectional circular list
    BCList* list = malloc(sizeof(BCList));
    list->next = list;
    list->prev = list;
    list->v = 2147483647;

    int n, new_element;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &new_element);
        BCList* to_insert = malloc(sizeof(BCList));
        to_insert->prev = list;
        to_insert->next = list->next;
        to_insert->v = new_element;
        list->next->prev = to_insert;
        list->next = to_insert;
    }

    BCList* t, *to_swap;
    for (BCList* i = list->next->next; i != list; i = t) {
        t = i->next;
        to_swap = i->prev;
        while ((to_swap->v > i->v) && (to_swap != list)) {
            to_swap = to_swap->prev;
        }
        i->prev->next = i->next;
        i->next->prev = i->prev;
        i->prev = to_swap;
        i->next = to_swap->next;
        to_swap->next->prev = i;
        to_swap->next = i;
        i = t;
    }

    BCList* end = list;
    for (list = list->next; list != end; list = list->next, free(list->prev)) {
        printf("%d ", list->v);
    }

    free(end);

    return 0;
}
