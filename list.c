#include <stdio.h>
#include <stdlib.h>

struct node {int i; struct node *next;};

void print_list(struct node *ll) {
    if (ll) {
        printf("%d ", ll->i);
        print_list(ll->next);
    }
    else {
        printf("\n");
    }
}

struct node * insert_front(int newData, struct node *ll) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->i = newData;
    new->next = ll;
    return new;
}

struct node * free_list(struct node *ll) {
    if (ll) {
        free_list(ll->next);
        free(ll);
    }
    return ll;
}

int main() {
    struct node *test = (struct node *)malloc(sizeof(struct node));

    test->i = 3;
    test->next = 0;
    print_list(test);

    test = insert_front(2, test);
    print_list(test);
    
    test = insert_front(1, test);
    print_list(test);

    free_list(test);

    return 0;

}
