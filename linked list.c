#include <stdlib.h>
#include <stdio.h>


struct listnode {
        int data;
        struct listnode *next;
};



struct listnode *create_listnode(int i);
void add_to_list(struct listnode *head, int i);
void print_list(struct listnode *head, FILE *out);
struct listnode *find_Nth_element(struct listnode *head, int N);

int main(int argc, char *argv[])
{
        struct listnode *head = NULL;
        add_to_list(head, 1);
        add_to_list(head, 2);
        add_to_list(head, 3);
        add_to_list(head, 4);

        print_list(head, stdout);
 
        return 0;
}

struct listnode *create_listnode(int i)
{
        struct listnode *newNode = NULL;
        
        newNode = malloc(sizeof(struct listnode));
        if (!newNode) {
                fprintf(stderr, "Could not allocate a new node\n");
                exit(EXIT_FAILURE);
        }

        newNode->data = i;
        newNode->next = NULL;

        return newNode;
}

void add_to_list(struct listnode *head, int i)
{
        if (!head) {
                struct listnode *newNode = create_listnode(i);
                if (!newNode) {
                        fprintf(stderr, "create_listnode did not return a listnode");
                        exit(EXIT_FAILURE);
                }
                head = newNode;
                return;
        }

        struct listnode *curr = NULL;
        struct listnode *next = head;

        while (next) {
                curr = next;
                next = next->next;
        }

        struct listnode *newNode = create_listnode(i);

        curr->next = newNode;

        return;
}

void print_list(struct listnode *head, FILE *out)
{
        if (!head) {
                fprintf(out, "Empty List\n");
                return;
                
        }

        struct listnode *curr = NULL;
        struct listnode *next = head;

        int count = 0;

        while (next) {
                count++;
                curr = next;
                fprintf(out, "List item %d: %d ", count, curr->data);
                next = next->next;
        }

        return;
}
struct listnode *find_Nth_element(struct listnode *head, int N)
{
        if (!head || N == 0) {
                return head;
        }

        struct listnode *curr = NULL;
        struct listnode *next = head;

        int count = 0;

        do {
                curr = next;
                next = next->next;
                count++;
        } while (next && count <= N);

        if (next) {
                return NULL;
        } else {
                return curr;
        }
}
