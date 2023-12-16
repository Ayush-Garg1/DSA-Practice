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

int matching(char a, char b){
    if( (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']') || (a == '<' && b == '>')){
        return 1;
    }
    return 0;
}

int valid(char str[]){
    char stack[MAX];
    int top = -1;
    for(int i = 0; i<strlen(str); i++){
        
        // if(str[i] == ' '){
        //     continue;
        // }

        if(str[i] == '(' || str[i] == '{' || str[i] == '[' || str[i] == '<'){
            push(stack, &top, str[i]);
        }
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']' || str[i] == '>'){
            if(empty(top)){
                return 0;
            }
            if(matching(stack[top], str[i])){
                pop(stack, &top);
            }
            else{
                return 0;
            }
        }
    }
    return empty(top);
}

int main(){
    char str[MAX];
    scanf("%[^\n]s",str);
    printf(valid(str) == 1 ? "Valid\n" : "Invalid\n");

    return 0;
}