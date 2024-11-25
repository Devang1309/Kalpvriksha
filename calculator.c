#include <stdio.h>
#include <ctype.h>

int calculate(char *exp){
    int current = 0, res = 0, temp = 0;
    char op = '+'; 

    int i;
    for(i = 0; exp[i] != '\0'; i++){
        char c = exp[i];

        if(isdigit(c)){
            current = current * 10 + (c - '0');  
        }

        if(!isdigit(c) && c != ' ' || exp[i + 1] == '\0'){
            if (op == '+'){
                res += temp;  
                temp = current;  
            } 
			else if (op == '-'){
                res += temp;  
                temp = -current;  
            } 
			else if (op == '*'){
                temp *= current;  
            } 
	else if (op == '/'){
            	if(current==0){
            		printf("Error: Division by Zero\n");
            		return;
				}
                temp /= current;  
            }
        else{
            printf("Error: Invalid Expression\n");
            return;
	}

            op = c;  
            current = 0;  
        }
    }

    res += temp;  
    printf("%d\n", res);
}

void main(){
    char exp[100];
    
    printf("Enter a mathematical expression: ");
    fgets(exp, sizeof(exp), stdin);

    calculate(exp);
    return 0;
}

