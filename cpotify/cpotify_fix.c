#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// cari cara biar index sblmnya bisa ilang dan ga keplay lanjut terus

int main(){
    int flag = 1;
    time_t t;
    srand((unsigned) time(&t)); // ATAU srand(time(NULL));
    int user_input, all_songs_time[20], song_ids[20], temp_song_time, index = 0;
    char all_songs_name[20][101], all_singers_name[20][101];
    char temp_take_song[101], temp_take_singer[101];
    int indicator_udah_ada_isi = 0;
    int tumbal_time_satu, hour, minute, second;
    int first_time = 0;
    while (flag == 1){
        if (indicator_udah_ada_isi == 0){
            printf("Cpotify\n=========\nCurrent played song : -\nMenu:\n1. Queue new song\n2. Show all queued songs\n3. Play next song\n4. Exit\n>> ");
        }
        scanf("%d", &user_input);
        getchar();
        switch (user_input){
            case 1:
                while (1){
                    printf("Song name [5 - 100 characters]: ");
                    scanf("%[^\n]s", temp_take_song);
                    getchar();
                    if (strlen(temp_take_song) > 4 && strlen(temp_take_song) < 101){
                        strcpy(all_songs_name[index], temp_take_song);
                        break;
                    }
                    printf("Input must be 5 - 100 characters. Try again!\n");
                }
                while (1){
                    printf("Singer name [not empty]: ");
                    scanf("%[^\n]s", temp_take_singer);
                    getchar();
                    if (temp_take_singer[0] == 'n' && temp_take_singer[1] == '\0'){
                        printf("Please input the singer name.\n");
                        continue;
                    }
                    strcpy(all_singers_name[index], temp_take_singer);
                    break;
                }
                while (1){
                    printf("Song duration [must be positive number in seconds]: ");
                    scanf("%d", &temp_song_time);
                    getchar();
                    if (temp_song_time > 0){
                        all_songs_time[index] = temp_song_time;
                        break;
                    }
                    printf("Positive number only! No 0 or negative allowed.\n");
                }
                song_ids[index] = (rand() % 1000);
                if (song_ids[index] == 0){song_ids[index] += 1;}
                index++;
                break;
            case 2:
                if (index == 0){
                    printf("No queued song...\n");
                    break;
                }
                for (int i = 0 ; i < index ; i++){
                    tumbal_time_satu = all_songs_time[i];
                    hour = tumbal_time_satu / 3600;
                    if (tumbal_time_satu > 3600){
                        tumbal_time_satu -= 3600;
                    }
                    minute = tumbal_time_satu / 60;
                    tumbal_time_satu = tumbal_time_satu - (minute * 60);
                    second = tumbal_time_satu;
                    printf("Song ID: SNG-%d-%d\nSong Name: %s\nSinger Name: %s\nSong Duration: %02d-%02d-%02d\n\n", all_songs_time[i], song_ids[i], all_songs_name[i], all_singers_name[i], hour, minute, second);
                }
                break;
            case 3:
                if (index == 0){
                    break;
                }
                indicator_udah_ada_isi = 1;
                first_time++;
                for (int j = 0 ; j < index ; j++){
                    if (first_time == 1){
                        break;
                    }
                    if (index == 1){
                        break;
                    }
                    strcpy(all_songs_name[j], all_songs_name[j+1]);
                    strcpy(all_singers_name[j], all_singers_name[j+1]);
                    all_songs_time[j] = all_songs_time[j+1];
                    song_ids[j] = song_ids[j+1];
                }
                index--;
                break;
            case 4:
                printf("Bye!\n");
                flag = 0;
                break;
            default:
                printf("Wrong input, 1 - 4 only.\n");
                break;
        }
        if (indicator_udah_ada_isi == 1){
            tumbal_time_satu = all_songs_time[0];
            hour = tumbal_time_satu / 3600;
            if (tumbal_time_satu > 3600){
                tumbal_time_satu -= 3600;
            }
            minute = tumbal_time_satu / 60;
            tumbal_time_satu = tumbal_time_satu - (minute * 60);
            second = tumbal_time_satu;
            printf("Cpotify\n=========\nCurrent played song : [SNG-%03d-%03d] %s - %s (%02d:%02d:%02d)\nMenu:\n1. Queue new song\n2. Show all queued songs\n3. Play next song\n4. Exit\n>> ", all_songs_time[0], song_ids[0], all_songs_name[0], all_singers_name[0], hour, minute, second);
        }
    }
}