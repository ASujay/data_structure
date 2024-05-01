#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *start = NULL;
node *create_ll(node *);
node *display(node *);
node *insert_beg(node *);
node *insert_end(node *);
node *insert_before(node *);
node *insert_after(node *);
node *delete_beg(node *);
node *delete_end(node *);
node *delete_node(node *);
node *delete_list(node *);

int main(){
    int option;
    do {
        printf("\n\n ******** MAIN MENU ********");
        printf("\n 1:  Create a list");
        printf("\n 2:  Display the list");
        printf("\n 3:  Add a node at the beginning");
        printf("\n 4:  Add a node a the end");
        printf("\n 5:  Add a node before a given node");
        printf("\n 6:  Add a node after a given node");
        printf("\n 7:  Delete a node from the beginning");
        printf("\n 8:  Delete a node from the end");
        printf("\n 9:  Delete a given node");
        printf("\n 10: Delete the entire list");
        printf("\n 11: EXIT");
        printf("\n\n Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                start = create_ll(start);
                printf("\n LINKED LIST CREATED");
                break;
            case 2:
                start = display(start);
                break;
            case 3:
                start = insert_beg(start);
                break;
            case 4:
                start = insert_end(start);
                break;
            case 5:
                start = insert_before(start);
                break;
            case 6:
                start = insert_after(start);
                break;
            case 7:
                start = delete_beg(start);
                break;
            case 8:
                start = delete_end(start);
                break;
            case 9:
                start = delete_node(start);
                break;
            case 10:
                start = delete_list(start);
                printf("\n LINKED LIST DELETED");
                break;
            default:
                break;
        }
    }while(option != 13);
    return 0;
}


node *create_ll(node *start) {
    node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data: ");
    scanf("%d", &num);
    while(num != -1) {
        new_node = (node *)malloc(sizeof(node));
        new_node->data = num;
        if(start == NULL) {
            // list is empty
            new_node-> next = NULL;
            start = new_node;
        } else {
            // list is not empty
            ptr = start;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = NULL;
        }

        printf("\n Enter the data: ");
        scanf("%d", &num);
    }
    return start;
}

node *create_node(){
    node *new_node = (node *)malloc(sizeof(node));
    int num;
    printf("\n Enter the data: ");
    scanf("%d", &num);
    new_node->data = num;
    new_node->next = NULL;
    return new_node;
}

node *display(node *start){
    // iterator pointer
    node *ptr = start;
    while(ptr != NULL){
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
    return start;
}

node *insert_beg(node *start){
    node *new_node = create_node();
    new_node->next = start;
    start = new_node;
    return start;    
}

node *insert_end(node *){
    node *new_node = create_node();
    node *ptr = start;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    // we are at the last node
    ptr->next = new_node;
    return start;
}

node *insert_before(node *start){
    // if we are trying to insert at the beginning of the list
    // just use the insert_beg 
    // the pre_ptr points to the node before the 
    int val;
    printf("\n Enter the value before which the data has to be inserted: ");
    scanf("%d", &val);
    node *ptr = start;
    if(ptr->data == val) {
        return insert_beg(start);
    } else {
        // we are not inserting before the first node
        // iterate until we get to the node
        node *pre_ptr, *new_node;
        while(ptr->data != val){
           pre_ptr = ptr;
           ptr = ptr->next; 
        }

        // pre_ptr points to the node before the required node
        new_node = create_node();
        pre_ptr->next = new_node;
        new_node->next = ptr;
    }
    return start;
}

node *insert_after(node *start){
    node *new_node, *ptr;
    int num, val;
    printf("\n Enter the value after which the data has to be inserted: ");
    scanf("%d", &val);
    ptr = start;
    while(ptr->data != val){
        ptr = ptr->next;
    }
    node *tmp = ptr->next;
    new_node = create_node();
    ptr->next = new_node;
    new_node->next = tmp;
    return start;
}

node *delete_beg(node *start){
    node *ptr;
    ptr = start;
    start = ptr->next;
    free(ptr);
    return start;
}

node *delete_end(node *start){
    // if the list is empty
    if(start == NULL) {
        return start;
    }

    // if the list has only one element
    if(start->next == NULL){
        node *ptr = start;
        start = NULL;
        free(ptr);
        return start;
    }
    node *ptr, *last, *pre_ptr;
    ptr = start;
    while(ptr->next != NULL){
        pre_ptr = ptr;
        ptr = ptr->next; 
    }

    pre_ptr->next = NULL;
    free(ptr);
    return start;
}

node *delete_node(node *start){
    node *ptr, *pre_ptr;
    int val;
    printf("\n Enter the value of the node which has to be deleted: ");
    scanf("%d", &val);
    // check if we are at the start of the list
    if(start->data == val) {
        return delete_beg(start);        
    }
    ptr = start;
    while(ptr->data != val){
        pre_ptr = ptr;
        ptr = ptr->next;
    }
    pre_ptr->next = ptr->next;
    free(ptr);
    return start;
}

node *delete_list(node *start){
    // check if the list is empty
    node *ptr;
    if(start != NULL) {
        ptr = start;
        while(ptr != NULL) {
            start = delete_beg(ptr);
            ptr = start;
        }
    }
    return start;
}
