#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

// msg 'S' stands for start
// msg 'R' stand for rounds display
// msg 'W' stands for win
// msg 'L' stands for lose
// msg 'H' stands for hint
void GameBorder(char msg, int round, char *code, int wP, int mP){
    if (msg == 'S')
        printf(" ______________________________\n|                              |\n|Will you find the secret code?|\n|______________________________|\n|                              |\n");
    if (msg == 'R' && round >= 10)
        printf("|----------Round %d------------|\n", round);
    else if (msg == 'R' && round < 10)
        printf("|-----------Round %d------------|\n", round);
    if (msg == 'W')
        printf("|______________________________|\n|                              |\n|    Congratz you've done it   |\n|                              |\n********************************\n");
    if (msg == 'L')
    {
        printf("|______________________________|\n|                              |\n|You lost :( the code was:%s |\n|                              |\n********************************\n", code);
    }
    if (msg == 'H')
        printf("|Well placed pieces: %d         |\n|Miss placed pieces: %d         |\n", wP, mP);
}

char *CheckInput(char *code, char *pieces){
    int flag = 0, ret = 5;
    do{
        flag = 0;
        for (int i = 0; code[i] != '\0'; i++)
            for (int j = 0; j < strlen(pieces); j++)if (code[i] == pieces[j]){
                    flag++;
                    break;
                }
        if (flag != 4 || strlen(code) != 5){
            printf("|Wrong Input!                  |\n");
            ret = read(0, code, 100);
            code[ret] = '\0';
        }
    } while (ret != 5 || flag != 4);
    return code;
}

int ReturnResult(char *code, char *iCode){
    int wellPlaced = 0, misPlaced = 0, count = 0;
    for (int i = 0; i < 4; i++) if (iCode[i] == code[i]) wellPlaced++;
    for (int i = 0; i < 4; i++) if (iCode[i] != code[i]) for (int j = 0; j < 4; j++){
                if (iCode[i] == code[j]){
                    for (int k = i - 1; k >= 0; k--) if (iCode[i] == iCode[k]) count++;
                    if (count == 0){
                        misPlaced++;
                        break;
                    }
                }
                count = 0;
            }
    for (int i = 0; i < 4; i++) if (iCode[i] == iCode[i + 1]) count++;
    if (count == 3) misPlaced = 0;
    if (wellPlaced == 4) return 1;
    else GameBorder('H', 0, code, wellPlaced, misPlaced);
    return 2;
}

char *GenerateRandom(char *code, char *pieces){
    time_t t;
    srand(time(&t));
    code = malloc(4*sizeof(char*));
    for (int i = 0; i < 4; i++) code[i] = pieces[rand() % (sizeof(pieces) / sizeof(*pieces))];
    return code;
}

void StartGame(char *code, int attempts, char *pieces){
    GameBorder('S', 0, code, 0, 0);
    if(code == NULL)code = GenerateRandom(code, pieces);
    char *iCode = malloc(100 * sizeof(char));
    int attemptCounter = 1, result;
    while (attemptCounter <= attempts){
        GameBorder('R', attemptCounter, code, 0, 0);
        read(0, iCode, 5);
        iCode = CheckInput(iCode, pieces);
        result = ReturnResult(code, iCode);
        if (result == 1){
            GameBorder('W', 0, code, 0, 0);
            break;
        } else if (attemptCounter == attempts){
            GameBorder('L', 0, code, 0, 0);
            break;
        } else if (result == 2) attemptCounter++;
    }
}

char *CheckCode(char *code, char *pieces){
    int numFlag = 0;
    int counter = 0;
    for (int i = 0; code[i] != '\0'; i++){
        counter++;
        if (code[i] >= '0' && code[i] <= '7') numFlag++;
    }
    if (numFlag != 4 || counter != 4)return 0;
    return code;
}

