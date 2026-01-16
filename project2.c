//DESIGNING THE GAME SNAKE, WATER AND GUN
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int main(){
    // WELCOME THING...
    printf("Welcome to the ultimate showdown\nSnake, Water, or Gun _ who will rule the run?\n");
    char user_consent[4];
    char str_1[4]="YES";
    char name[20],rules[2];
    char user_input[10],system_input[10];
    int sys,result;
    int user_score=0,system_score=0;
    char extra[5];
    char choice_n[3][10]={"SNAKE","WATER","GUN"};
    // ASKING FOR CONSENT TO BEGIN
    for (int i=0;;i++){
        printf("Enter YES if you want to proceed:");
        scanf("%s",user_consent);
        if(strcmp(user_consent,str_1)==0){
            break;
        }
        else{
            system("cls");
        }
    }
    //USER NAME
    printf("Enter your name:");
    scanf("%s",name);
    printf("\nSystem initialized...Connection established...Let the battle begin!\n\n");
    printf("%s v/s System: Can you outsmart the system in Snake, Water, Gun?\n",name);
    //RULES
    for (int i=0;;i++){
        printf("\nEnter '1' if you want to proceed to the rules and '0' if not:");
        scanf("%s",rules);
        if(strcmp(rules,"1")==0){
            printf("\nSnake vs. Water: Snake wins. \nThe snake drinks the water.\nWater vs. Gun: Water wins. \nThe gun sinks or is doused by the water, making it useless.\nGun vs. Snake: Gun wins. \nThe gun shoots the snake.\nSame Choice: It is a Draw.");
            break;
        }
        if(strcmp(rules,"0")==0){
            break;
        }
    }
    //NOW LET THE USER AND SYSTEM CHOOSE THEIR CHOICES
    printf("\nPick any one...\nSNAKE, WATER OR GUN\n");
    printf("\nEnter 'END' whenever whats to end the game...");
    while(1){
        printf("\nEnter your choice:");
        scanf("%s",user_input);
        // printf("\nYour choice:%s",user_input);
        sys=rand()%3+1;
        srand(time(0));
        if (sys==0){
            strcpy(system_input,choice_n[0]);
        }
        else if(sys==1){
            strcpy(system_input,choice_n[1]);
        }
        else{
            strcpy(system_input,choice_n[2]);
        }
        printf("\nSystem Selected: %s\nYou Selected:%s",system_input,user_input);
        //RESULT TIME WHO WINS...
        printf("\nResult...\n");
        result=strcmp(user_input,system_input);
        if(result==0){
            printf("DRAW");
        }
        //priority order of snake, water and gun is... GUN>>SNAKE>>WATER
        else{
            //When user input is SNAKE
            if (strcmp(user_input,choice_n[0])==0){
                if (strcmp(system_input,choice_n[1])==0){
                    user_score+=1;
                    printf("\nYour score:%d \nSystem's Score:%d\n",user_score,system_score);
                    printf("\nYou won this round!");
                }
                else{
                    system_score+=1;
                    printf("Your score:%d \nSystem's Score:%d\n",user_score,system_score);
                    printf("\nSystem won this round!");
                }
            }
            //When user input is WATER
            if (strcmp(user_input,"WATER")==0){
                if (strcmp(system_input,"GUN")==0){
                    user_score+=1;
                    printf("Your score:%d \nSystem's Score:%d\n",user_score,system_score);
                    printf("\nYou won this round!");
                }
                else{
                    system_score+=1;
                    printf("Your score:%d \nSystem's Score:%d\n",user_score,system_score);
                    printf("\nSystem won this round!");
                }
            }
            //When user input is GUN
            if (strcmp(user_input,"GUN")==0){
                if (strcmp(system_input,"SNAKE")==0){
                    user_score+=1;
                    printf("Your score:%d \nSystem's Score:%d\n",user_score,system_score);
                    printf("\nYou won this round!");
                }
                else{
                    system_score+=1;
                    printf("Your score:%d \nSystem's Score:%d\n",user_score,system_score);
                    printf("\nSystem won this round!");
                }
            }
        }
        char var[5]="STOP";
        if(strcmp(user_input,"STOP")==0){
            break;
        }
    }
    printf("\nFINAL SCORE:\n%s's Score: %d\nSystem's Score: %d",name,user_score,system_score);
    printf("\nFinal verdict...");
    if(user_score>system_score){
        printf("\nThe System has been shut down...\nVictory is yours %s!",name);
    }
    else if(user_score<system_score){
        printf("\nGame Over...\nThe System was one step ahead this time");
        printf("\nBETTER LUCK NEXT TIME DUDE...");
    }
    else{
        printf("\nIt's a DRAW");
    }
    printf("\nCleaning up resources...Game exited successfully\nGoodbye, User!");
    return 0;
}
