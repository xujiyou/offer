#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct LinkedNode{
    int key;
    struct LinkedNode *next;
    struct LinkedNode *sibling;
} Node;

Node *create_node(int key){
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->next = NULL;
    node->sibling = NULL;
    return node;
}

Node *create_linked(){
    Node *node1 = create_node(1);
    Node *node2 = create_node(2);
    Node *node3 = create_node(3);
    Node *node4 = create_node(4);
    Node *node5 = create_node(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node1->sibling = node3;
    node2->sibling = node5;
    node4->sibling = node2;
    return node1;
}

Node *copy_linked(Node *root){
    Node *node = root;
    while (node != NULL){
        Node *copy_node = create_node(node->key);
        copy_node->next = node->next;
        node->next = copy_node;
        node = copy_node->next;
    }
    Node *second_node = root;
    while (second_node != NULL) {
        if (second_node->sibling != NULL) {
            second_node->next->sibling = second_node->sibling->next;
        }
        second_node = second_node->next->next;
    }
    Node *thrid = root;
    while (thrid != NULL){
        Node *next_thrix = thrid->next->next;
        if (next_thrix != NULL) {
            thrid->next->next = next_thrix->next;
        }
        thrid = next_thrix; 
    }
    return root->next;
}

void print_link(Node *root){
    while (root != NULL){
        printf(" %d", root->key);
        if (root->sibling != NULL) {
            printf("/%d", root->sibling->key);    
        }
        root = root->next;
    }
}

int main(){
    Node *root = create_linked();
    Node *newRoot = copy_linked(root);
    print_link(newRoot);
    printf("\n");
}
