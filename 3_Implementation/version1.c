#include <stdio.h>
#include <stdlib.h>

char matrix[3][3];            

int end = 0;                   
int moves = 0;                  

char input;                     

void startGame();
void display();
void p1();
void p2();
char check();
void intro();

int main() {
    
    char enter = ' ';           
    char rematch = ' ';        
    char result = ' ';
    
    startGame();
    
    system("clear");           
    
    printf("===========\n");
    printf("Tic-Tac-Toe\n");
    printf("===========\n\n");
    
    printf("Player 1) X\n");
    printf("Player 2) O\n\n");
    
    printf("Press [Enter] to begin!\n");
    scanf("%c", &enter);
    
    system("clear");
    
    
    while (end == 0) {
        
        display();             
        p1();                
        moves++;
        
        if (moves == 9)
            break;
        
        result = check();
        
        if (result != ' ')
            break;
        
        display();           
        p2();                   
        moves++;
        
        if (moves == 9)
            break;
        
        result = check();
        
        if (result != ' ')
            break;
        
    }
    
    // ===============================================================================
    
    char ans = check();

    display();
    
    if (ans == 'X') {
        
        printf("Player 1: X won!\n\n");
        
    }
    else if (ans == 'O') {
        
        printf("Player 2: O won!\n\n");
        
    }
    else {
        
        printf("It's a Tie Game!\n\n");
        
        printf("Want a rematch (y/n)? ");
        scanf("%c", &rematch);
        scanf("%c", &rematch);
        
        if (rematch == 'y' || rematch == 'Y') {
            
            main();
            
        }
        else {
            
            printf("\n");
        }
        
    }
    
    printf("Thanks for playing!\n\n");
    
    return 0;
    
}



void startGame() {
    
    int i, j;
    
    for (i = 0; i < 3; i++) {
        
        for (j = 0; j < 3; j++) {
            
            matrix[i][j] = ' ';
            
        }
        
    }
    
}



void display() {
    
    int i;
    
    system("clear");
    
    printf("===========\n");
    printf("Tic-Tac-Toe\n");
    printf("===========\n\n");
    
    for (i = 0; i < 3; i++) {
        
        printf(" %c | %c | %c ", matrix[i][0], matrix[i][1], matrix[i][2]);
        
        if (i != 2) {
            
            printf("\n---|---|---\n");
            
        }
        
    }
    
    printf("\n\n");
    
}

// player one

void p1() {
    
    int x, y;
    
    printf("P1) Enter coordinates: ");
    scanf("%d %d", &x, &y);
    
  
    
    x--;
    y--;
    
   
    
    if (matrix[x][y] != ' ') {
        
        printf("\nInvalid entry, try again.\n\n");
        p1();
        
    }
    else {
        
        matrix[x][y] = 'X';
        
    }
    
}

// player two

void p2() {
    
    int x, y;
    
    printf("P2) Enter coordinates: ");
    scanf("%d %d", &x, &y);
    
    x--;
    y--;
    
    if (matrix[x][y] != ' ') {
        
        printf("\nInvalid entry, try again.\n\n");
        p2();
        
    }
    else {
        
        matrix[x][y] = 'O';
        
    }
    
}



char check() {
    
    int i;
    
    for (i = 0; i < 3; i++) {
    
        
        
        if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2])
            return matrix[i][0];
        
      
        
        if (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])
            return matrix[0][i];
    
    }

   
    
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
        return matrix[0][0];
        
    
    
    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
        return matrix[0][2];
    
    
    
    return ' ';
    
}