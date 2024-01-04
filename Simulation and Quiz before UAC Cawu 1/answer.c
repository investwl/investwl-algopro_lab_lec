#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int zenn = 0;
int sword = 30, head = 0, chest = 0;

int shin_floor = 1, max_shin_floor = 15;
int list_of_chance[10] = {1,0,0,0,0,0,0,0,0,0};
int content_floor[15] = {9,0,0,0,0,9,0,0,0,0,9,0,0,0,0};

int boss_5 = 1, boss_10 = 1, boss_15 = 1; 

int check_boss(){
    if (boss_5 == 1){return 1;}
    else if (boss_10 == 1){return 1;}
    else if (boss_15 == 1){return 1;}
    return 0;
}

// void floor_info(){
//     printf("Floor | Status\n========\n");
//     for (int a = 15 ; a > 0 ; a--){
//         if ((a == 5 || a == 10 || a == 15) && content_floor[a] == 9){
//             printf("%d\t|-Boss-\n", a);
//         }

//         else if (a == shin_floor){printf("%d\t| Shin\n");}
//         else if (content_floor[a] == 0){printf("%d\t| --??--\n", a);}
//         else if (content_floor[a] == 1){printf("%d\t| Chest\n", a);}
//         else if (content_floor[a] == 2){printf("%d\t| Monster\n", a);}
//     }
// }

void menu(){
    printf("Zenn : %d\nSword : %d\nHead : %d\nChest : %d\nFloor : %d\nShin, what are you going to do?\n--\n1. Go Up\n2. Fight\n3. Shop\n4. Quit\n>> ",zenn, sword, head, chest, shin_floor);
}

void go_up(){
    if (check_boss()){
        printf("You must fight the boss before you can go up\n");
        return;
    }
    else{
        if (shin_floor == 15){
            printf("You're literally at the max floor, duh.\n");
        }
        if (shin_floor == 5 && boss_5 == 0){
            shin_floor++;
            printf("You climbed up to floor %d\n", shin_floor);
        }
        else if (shin_floor == 10 && boss_10 == 0){
            shin_floor++;
            printf("You climbed up to floor %d\n", shin_floor);
        }
        else if (shin_floor != 5){
            shin_floor++;
            printf("You climbed up to floor %d\n", shin_floor);
        }
        else if (shin_floor != 10){
            shin_floor++;
            printf("You climbed up to floor %d\n", shin_floor);
        }

    }
    printf("Enter to continue...\n");
    getchar();
    getchar();
}

int fighting(int opponent, int shin_power){
    printf("Player total attack : %d\nEnemy total attack : %d\n", shin_power, opponent);
    if (shin_power > opponent){
        printf("You win!!!\n");
        return 1;
    }
    else{
        printf("You lose!!!\nGame over!!!\n");
        exit(0);
    }
}

void chest_prize(){
    int prizenya = (shin_floor * 10) + (rand() % 30 + 1);
    printf("You found treasure!!!\nYou get %d zenn!\n", prizenya);
    zenn += prizenya;
}

void go_fight(int shin_power){
    int monster_or_chest = (rand() % 10) + 1;
    if ((shin_floor == 5 || shin_floor == 10 || shin_floor == 15) && check_boss()){
        int boss_power = shin_floor * 30;
        if (fighting(boss_power, shin_power)){
            chest_prize();
            if (shin_floor == 5){boss_5--;}
            else if (shin_floor == 10){boss_10--;}
            else if (shin_floor == 15){boss_15--;}
        }
    } 
    else{
        // panggil list of chance pake index monster or chest, kalo 1 chest
        // kalo chest --> print you found treasure!!!\nyou get x zenn
        if (list_of_chance[monster_or_chest]){
            chest_prize();
        }
        else{
            // kalo monster:
            // power player > monster --> win, go to chest
            // power player < monster --> lose, die, end of program
            int monster_power = (shin_floor * 20) + ((rand() % 10) * shin_floor);
            if (fighting(monster_power, shin_power)){
                chest_prize();
            }
        }
    }
}

void go_shop(){
    int randomize_item_list = rand() % 3;
    int power_item = shin_floor * (rand() % 50);
    int price_item = power_item / 10 * 30;
    char item_name[10];
    if (randomize_item_list == 0){strcpy(item_name, "Sword");}
    else if (randomize_item_list == 1){strcpy(item_name, "Head");}
    else if (randomize_item_list == 2){strcpy(item_name, "Chest");}
    else{strcpy(item_name, "Bug");}
    while (1){
        printf("Shin Shop\n--\nWe have a %s with power %d. It'll be %d zenn\nShould i buy?\n1. Buy\n2. Nah, im good\n>> ", item_name, power_item, price_item);
        int shin_input;
        scanf("%d", &shin_input);
        if (shin_input == 2){
            printf("Please come back again if you're interested!\n");
            return;
        }
        else if (shin_input == 1){
            if (zenn >= price_item){
                if (randomize_item_list == 0){
                    sword += power_item;
                }
                else if (randomize_item_list == 1){
                    head += power_item;
                }
                else if (randomize_item_list == 2){
                    chest += power_item;
                }
                zenn -= price_item;
                printf("Bought %s! Zenn left : %d\n", item_name, zenn);
                return;
            }
            else{
                printf("Not enough money!\n");
                return;
            }
        }
    }
}

int main(){
    srand(time(NULL));
    int upgrade[2];
    while (1){
        int shin_power = sword + head + chest;
        // floor_info();
        menu();
        int user_input;
        scanf("%d", &user_input);
        switch (user_input){
            case 4:
                printf("I quit the dungeon!\n");
                exit(0);
                break;
            case 1:
                go_up();
                break;
            case 2:
                go_fight(shin_power);
                break;
            case 3:
                go_shop();
                break;
        }
    }
}