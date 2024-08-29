#include <stdio.h>
#include <ctype.h>

typedef enum {
    MINUS, PLUS, SLASH, STAR, NUMBER, UNKNOWN
} TokenType;

typedef struct {
    TokenType type;
    int value; 
} Token;

void printToken(Token token) {
    switch (token.type) {
        case PLUS:   printf("+\n"); break;
        case MINUS:  printf("-\n"); break;
        case SLASH:  printf("/\n"); break;
        case STAR:   printf("*\n"); break;
        case NUMBER: printf("%d\n", token.value); break;
        default:     printf("Token: UNKNOWN %c \n",token.value); break;
    }
}

int main(int argc, char const *argv[]) {
    Token token[256];
    int index = 0; 
    if(argc!=2){
        printf("No file path provided\n");
        return -1;
    }
    
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    char c;
    int num;

    while ((c = fgetc(file)) != EOF) {
        if (isspace(c)) {
            
            continue;
        } else if (isdigit(c)) {
            ungetc(c, file); 
            if (fscanf(file, "%d", &num) == 1) {
                token[index].type = NUMBER;
                token[index].value = num;
                printToken(token[index]);
                index++;
            }
        } else {
            switch (c) {
                case '+':
                    token[index].type = PLUS; 
                    break;
                case '-':
                    token[index].type = MINUS; 
                    break;
                case '/':
                    token[index].type = SLASH; 
                    break;
                case '*':
                    token[index].type = STAR; 
                    break;
                default:
                    token[index].type = UNKNOWN;
                    token[index].value = c;
                    printToken(token[index]);
                    fclose(file);
                    return -1;
            }
            printToken(token[index]);
            index++;
        }
    }

    fclose(file);
    
    return 0;
    
}
