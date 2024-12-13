#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data; 
    struct node *next;
};

struct node *head = NULL, *last = NULL;

struct node *get_struct(void) {
    struct node *p = NULL;
    int number;

    if ((p = (struct node *)malloc(sizeof(struct node))) == NULL) {
        printf("Ошибка при распределении памяти\n");
        exit(1);
    }

    printf("Введите число: \n");
    scanf("%d", &number);

    p->data = number;
    p->next = NULL;

    return p;
}

void spstore(void) {
    struct node *p = NULL;
    p = get_struct();
    if (head == NULL && p != NULL) {
        head = p;
        last = p;
    } else if (head != NULL && p != NULL) {
        struct node *temp;
        temp = head;
        p->next = temp;
        head = p;
    }
    return;
}

void review(struct node *first) {
    struct node *struc = first;
    if (head == NULL) {
        printf("Список пуст\n");
    }
    while (struc) {
        printf("%d -> ", struc->data);
        struc = struc->next;
    }
    return;
}


void del(int number) {
    struct node *struc = head;
    struct node *prev;
    int flag = 0;

    if (head == NULL) {
        printf("Список пуст\n");
        return;
    }

    if (struc->data == number) {
        flag = 1;
        head = struc->next;
        free(struc);
        struc = head;
    } else {
        prev = struc;
        struc = struc->next;
    }

    while (struc) {
        if (struc->data == number) {
            flag = 1;
            if (struc->next) {
                prev->next = struc->next;
                free(struc);
                struc = prev->next;
            } else {
                prev->next = NULL;
                free(struc);
                return;
            }
        } else {
            prev = struc;
            struc = struc->next;
        }
    }

    if (flag == 0) {
        printf("Элемент не найден\n");
        return;
    }
}

int main(void) {
    bool exitApp = false;

    while (!exitApp) {
        int state = 0;
        printf("1: добавить элемент\n2: удалить элемент\n3: выйти\n");
        printf("Выберите действие: ");
        scanf("%d", &state);

        switch (state) {
            case 1:
                printf("\n");
                spstore();
                printf("\n");
                review(head);
                printf("\n\n");
                break;
            case 2:
                int numToDelete;
                printf("Введите число для удаления: ");
                scanf("%d", &numToDelete);
                del(numToDelete);
                printf("\n");
                review(head);
                printf("\n\n");
                break;
            case 3:
                exitApp = true;
                break;
            default:
                printf("Введена неверная команда\n\n");
                break;
        }
    }

    return 0;
}
