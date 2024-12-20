#include <stdio.h>
#include <ctype.h>

void calculate(char *exp){
	int j; int count=0;             //This is to count the size of exp
	for(j=0; exp[j]!='\0'; j++){
	    if (exp[j] != '\n')        // Excluding the newline character from fgets
        	count++;
	}
	
    int current = 0, result = 0, temp = 0;
    char op = '+'; 

    int i; int flag=0;
    int prev=0;  int precedence = 0; int negative = 0;       //for consecutive operator
    for(i = 0; i<=count; i++){
    	if(exp[0]=='+' || exp[0]=='*' || exp[0]=='/'){
    		printf("Error: Invalid Expression\n");
    		break;	
		}
		
		if(i==count-1){
		    if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/'){
    		    printf("Error: Invalid Expression\n");
    		    break;	
		    }
		}
		
        char c = exp[i];

        if(isdigit(c)){
            current = current * 10 + (c - '0');  
        }
        
        if(precedence == 1 && prev==1 && c=='-'){
            precedence = 0; negative = 1;
            continue;
        }

        if(!isdigit(c) && c != ' ' || exp[i + 1] == '\0'){
            if (op == '+'){
                result += temp;  
                temp = current;  
            }
			else if (op == '-'){
                result += temp;  
                temp = -current;  
            } 
			else if (op == '*'){
                temp *= current;  
            } 
			else if (op == '/'){
            	if(current==0){
            		printf("Error: Division by Zero\n");
            		break;
				}
                temp /= current;  
            }
        	else{
            	printf("Error: Invalid Expression\n");
            	break;
			}

            op = c;  
            current = 0;
            if(prev == 1){
                printf("Error: Invalid Expression\n");
            	break;
            }
            prev = 1;
            if(op=='*' || op=='/'){
                precedence = 1;
            }
        }
        else if(isdigit(c)){
            prev = 0;
        }
        flag=i;
    }
    
    result += temp;
    if(flag==count && negative ==1){
        printf("%d \n", -result);
    }
    
    else if(flag==count){
    	printf("%d\n", result);
	}
}

void main(){
    char exp[100];
    
    printf("Enter a mathematical expression: ");
    fgets(exp, sizeof(exp), stdin);

    calculate(exp);
}

