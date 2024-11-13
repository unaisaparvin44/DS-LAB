#include <stdio.h>
#include <stdlib.h>

int n, count = 0;

void insert_begin();
void insert_end();
void insert_pos();
void traversal();
void delt_begin();
void delt_end();
void delt_pos();
void search();

struct node {
    int data;
    struct node *rlink;
    struct node *llink;
};

struct node *head = NULL, *newnode, *temp, *prev;

int main() {
    int ch;
    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at a Position\n");
        printf("4. Traversal\n");
        printf("5. Deletion at Beginning\n");
        printf("6. Deletion at End\n");
        printf("7. Deletion at a Position\n");
        printf("8. Search\n");
        printf("9. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insert_begin(); break;
            case 2: insert_end(); break;
            case 3: insert_pos(); break;
            case 4: traversal(); break;
            case 5: delt_begin(); break;
            case 6: delt_end(); break;
            case 7: delt_pos(); break;
            case 8: search(); break;
            case 9: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

void insert_begin() {
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->rlink = head;
    newnode->llink = NULL;
    if (head != NULL) {
        head->llink = newnode;
    }
    head = newnode;
    count++;
}

void traversal() {
    if (head == NULL) {
        printf("No nodes present\n");
    } else {
        printf("The elements are: ");
        temp = head;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->rlink;
        }
        printf("NULL\n");
    }
}

void insert_end() {
    if (head == NULL) {
        insert_begin();
    } else {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->rlink = NULL;
        temp = head;
        while (temp->rlink != NULL) {
            temp = temp->rlink;
        }
        temp->rlink = newnode;
        newnode->llink = temp;
        count++;
    }
}

void insert_pos() {
    if (head == NULL) {
        printf("since there is no elements left we add into first position");
        insert_begin();
    } else {
        printf("Enter the position to insert: ");
        scanf("%d", &n);
        if (n > count + 1) {
            printf("Insertion not possible\n");
        } else if(n == 1) {
            insert_begin();
        } else {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter the data: ");
            scanf("%d", &newnode->data);
            int i = 1;
            temp = head;
            while (i < n - 1 && temp->rlink != NULL) {
                temp = temp->rlink;
                i++;
            }
            newnode->rlink = temp->rlink;
            if (temp->rlink != NULL) {
                temp->rlink->llink = newnode;
            }
            temp->rlink = newnode;
            newnode->llink = temp;
            count++;
        }
    }
}

void delt_begin() {
    if (head == NULL) {
        printf("No nodes found\n");
    } else {
        temp = head;
        head = head->rlink;
        if (head != NULL) {
            head->llink = NULL;
        }
        printf("Deleted element is %d\n", temp->data);
        free(temp);
        count--;
    }
}

void delt_end() {
    if (head == NULL) {
        printf("No nodes found\n");
    } else if (head->rlink == NULL) {
        printf("Deleted element is %d\n", head->data);
        free(head);
        head = NULL;
        count--;
    } else {
        temp = head;
        while (temp->rlink != NULL) {
            temp = temp->rlink;
        }
        temp->llink->rlink = NULL;
        printf("Deleted element is %d\n", temp->data);
        free(temp);
        count--;
    }
}

void delt_pos() {
    if (head == NULL) {
        printf("No nodes found\n");
    } else {
        printf("Enter the position to delete: ");
        scanf("%d", &n);
        if (n > count) {
            printf("Deletion not possible\n");
        } else {
            int i = 1;
            temp = head;
            while (i < n && temp->rlink != NULL) {
                temp = temp->rlink;
                i++;
            }
            if (temp->llink != NULL) {
                temp->llink->rlink = temp->rlink;
            } else {
                temp->llink->rlink = temp->rlink;
            }
            if (temp->rlink != NULL) {
                temp->rlink->llink = temp->llink;
            }
            printf("Deleted element is %d\n", temp->data);
            free(temp);
            count--;
        }
    }
}

void search() {
    int item, i = 1, flag = 0;
    temp = head;
    if (temp == NULL) {
        printf("Empty list\n");
    } else {
        printf("Enter item to search: ");
        scanf("%d", &item);
        while (temp != NULL) {
            if (temp->data == item) {
                printf("Item found at location %d\n", i);
                flag = 1;
                break;
            }
            temp = temp->rlink;
            i++;
        }
        if (!flag) {
            printf("Item not found\n");
        }
    }
}


