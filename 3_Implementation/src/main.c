int main()
{
    unsigned char user1[30], user2[30], winner;
    int ival, jval;

    printf("\nEnter name of user1 :");
    gets(user1);
    fflush(stdin);

    printf("Enter name of user2 :");
    gets(user2);
    fflush(stdin);

again:
    system("clear");
    printf("\n\n\n\n");
    if (!onlyOnce) {
        printMatrix(0);
        onlyOnce = 1;
    }
    else {
        printMatrix(1);
    }
    winner = isOver();

    if (winner) {
        printf("\n * Congratulations Dear %s ,\n     You have won the game . !!!!", ((winner == 'X') ? user1 : user2));
        goto end;
    }

    if (!isFull()) {
        printf("\n * Game Over .");
        goto end;
    }

repeat:
    fflush(stdin);
    printf("\n * %s , Enter value (00-22) seperated by space :", (usertern == 0x00 ? user1 : user2));
    scanf("%d%d", &ival, &jval);
    if ((ival > 2 || ival < 0) || (jval > 2 || jval < 0)) {
        printf("\n * ERROR : Invalid index, try again !!!");
        goto repeat;
    }
    if (mat[ival][jval] != '_') {
        printf("\n * ERROR : Already filled,try again !!!");
        goto repeat;
    }
    insertValue(ival, jval, usertern);
    usertern = !usertern;
    goto again;

end:
    printf("\n");
    return 0;
}
