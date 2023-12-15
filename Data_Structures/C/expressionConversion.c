#include<stdio.h>
#include<string.h>

#define MAX 100

void push(char stack[], int *top, char val){
    if(*top != MAX - 1){
        stack[++(*top)] = val;
    }
}

void pop(char stack[], int *top){
    if(*top != -1){
        (*top)--;
    }
}

int empty(int top){
    return top == -1;
}

int operand(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return 1;
    }
    if(ch >= 'A' && ch <= 'Z'){
        return 1;
    }
    if(ch >= '0' && ch <= '9'){
        return 1;
    }
    return 0;
}

int opertr(char ch){
    switch(ch){
        case '+' : 
        case '-' : 
        case '*' : 
        case '/' : 
        case '%' : 
        case '^' : return 1;
    }
    return 0;
}

int precedence(char ch){
    switch(ch){
        case '+' : return 1;
        case '-' : return 1;
        case '*' : return 2;
        case '/' : return 2;
        case '%' : return 2;
        case '^' : return 3;
    }
    return 0;
}

void toPostfix(const char infix[], char postfix[]){
    char stack[MAX];
    int top = -1;
    // char postfix[MAX];
    int j = 0;

    for(int i = 0 ; i < strlen(infix) ; i++){

        // getting rid of useless whitespaces
        if(infix[i] == ' '){
            continue;;
        }

        // if operand then putting it in the output
        if(operand(infix[i])){
            postfix[j] = infix[i];
            j++;
        }

        // if operator
        else if(opertr(infix[i])){
            if(empty(top)){
                push(stack, &top, infix[i]);
            }else{
                while(precedence(stack[top]) >= precedence(infix[i])){
                    postfix[j] = stack[top];
                    j++;
                    pop(stack, &top);
                }
                push(stack, &top, infix[i]);
            }
        }
    }
    while(!empty(top)){
        postfix[j] = stack[top];
        j++;
        pop(stack, &top);
    }
    postfix[j] = '\0';
}

void toPrefix(char infix[], char prefix[]){
    toPostfix(strrev(infix),prefix);
    strrev(prefix);
}

int main(){
    char str[MAX];
    char postfix[MAX], prefix[MAX];
    printf("Enter Infix\t: ");
    scanf("%[^\n]s",str);
    toPostfix(str,postfix);
    toPrefix(str,prefix);
    printf("\nPostfix\t: %s",postfix);
    printf("\nPrefix\t: %s",prefix);

    return 0;
}