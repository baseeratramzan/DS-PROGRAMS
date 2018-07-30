#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OPERATORS 7

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

char precedence[OPERATORS][2] = { {'(', 0}, {'+', 1}, {'-', 1},
    {'*', 2}, {'/', 2}, {'%', 2},
    {')', 3}};


struct node* createNode(int data) {
    struct node *ptr = (struct node *) malloc(sizeof (struct node));
    ptr->data = data;
    ptr->next = NULL;
}


void push(int data) {
    struct node *ptr = createNode(data);
    if (top == NULL) {
        top = ptr;
        return;
    }
    ptr->next = top;
    top = ptr;
}


int pop() {
    struct node *ptr;
    int data;
    if (top == NULL)
        return -1;
    ptr = top;
    top = top->next;
    data = ptr->data;
    free (ptr);
    return (data);
}

int getIndex(int data) {
    int i;
    for (i = 0; i < OPERATORS; i++) {
        if (data == precedence[i][0])
            return i;
    }
}

void strrev(char str[]) {
    int i = 0, j = 0;
    char ptr[100];
    while (str[i] != '\0')
        i++;
    for (i = i-1; i >=0; i--) {
        ptr[j] = str[i];
        j++;
    }
    ptr[j] = '\0';
    strcpy(str, ptr);
}


void infix2prefix(char infix[], char postfix[]) {
    int i, j = 0, data;
    int index1, index2;
    for (i = 0; i < strlen(infix); i++) {
       
        if (tolower(infix[i]) >= 'a' && tolower(infix[i] <= 'z'))
            postfix[j++] = infix[i];
        else if (infix[i] == '(') {
           
            data = pop();
            while (data != ')' && data != -1) {
                postfix[j++] = data;
                data = pop();
            }
        } else if (infix[i] == ')') {
                       push(infix[i]);
        } else {
            data = pop();
            if (data == -1) {
                
                push(infix[i]);
                continue;
            } else if (data == ')') {
                
                push(data);
                push(infix[i]);
                continue;
            }
            index1 = getIndex(data);
            index2 = getIndex(infix[i]);
            
            
            
            while (precedence[index1][1] > precedence[index2][1]) {
                postfix[j++] = data;
                data = pop();
                if (data == -1 || data == ')') {
                    push(infix[i]);
                    break;
                }
                index1 = getIndex(data);
            }
            if (data != -1) {
                push(data);
                push(infix[i]);
            }
            
        }
    }
    
    while (1) {
        if ((data = pop()) == -1)
            break;
        postfix[j++] = data;
    }
    postfix[j] = '\0';
}

int main () {
    char str[100], output[100];
    printf("Enter ur Expression:");
    fgets(str, 100, stdin);
    str[strlen(str) - 1] = '\0';
    strrev(str);
    infix2prefix(str, output);
   
    strrev(output);
    printf("Ouput: %s\n", output);
    return 0;
}
