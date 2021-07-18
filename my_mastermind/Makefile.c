#include "Makefile.h"

int main(int argc, char *argv[]){
    int option, attempts = 10;
    char *code = NULL, pieces[8] = {'0', '1', '2', '3', '4', '5', '6', '7'};
    while ((option = getopt(argc, argv, "c:p:t"))){
        switch (option){
        case 'c':
            code = CheckCode(optarg, pieces);
            if(code != 0)StartGame(code, attempts, pieces); else printf("Wrong Input!\n");
            return 0;
        case 'p':
            if (argc != 10) printf("Wrong Input\n");
            else{
                for (int i = 0; i < 8; i++) pieces[i] = argv[i + 2][0];
                StartGame(code, attempts, pieces);}
                return 0;
        case 't':
           for(int i = 0; argv[2][i] != '\0';i++)if(isdigit(argv[2][i]) == 0){printf("Wrong Input\n"); return 0;}
           attempts = atoi(argv[2]);   
        default:
            StartGame(code, attempts, pieces);
            return 0;
        }
    }
}
