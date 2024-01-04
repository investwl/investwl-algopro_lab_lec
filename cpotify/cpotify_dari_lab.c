#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
int main(){
    int menu_input;
    srand(time(NULL));
    char song_names[100][101];
    char singer_names[100][101];
    int song_durations[100];
    char song_ids[100][20];
    int song_count = 0;
    char current_song[101] = "", current_singer[101] = "", current_id[20] = "";
    int current_duration = 0;
    do {
        if (strlen(current_song) == 0){printf("Current played song : -\n");}
        else{
            int hour = current_duration / 3600;
            int minute = current_duration / 60 % 60;
            int second = current_duration % 60;
            printf("Current played song : [%s] %s - %s (%02d:%02d:%02d)\n", current_id, current_song, current_singer, hour, minute, second);
        }
        printf("1. Queue new song\n2. Show all queued song\n3. Play next song\n4. Exit\n>> ");
        scanf("%d", &menu_input);
        getchar();

        if (menu_input == 1){
            char song_name[101] = "";
            char singer_name[101] = "";
            int song_duration = 0;
            do{
                printf("Song name: ");
                scanf("%[^\n]s", song_name);
                getchar();
            } while (strlen(song_name) < 5 || strlen(song_name) > 100);

            do{
                printf("Singer name: ");
                scanf("%[^\n]s", singer_name);
                getchar();
            } while (strlen(singer_name) == 0);

            do{
                printf("Song duration: ");
                scanf("%d", &song_duration);
                getchar();
            } while (song_duration <= 0);

            char song_id[20];
            bool is_duplicate;
            do{
                sprintf(song_id, "SNG-%d-%03d", song_duration, rand() % 1000);
                song_durations[song_count] = song_duration;

                for (int i = 0 ; i < song_count ; i++){
                    if (strcmp(song_id, song_ids[i]) == 0){
                        is_duplicate = true;
                        break;
                    }
                    else{
                        is_duplicate = false;
                    }
                }
            } while (is_duplicate);

            strcpy(song_names[song_count], song_name);
            strcpy(singer_names[song_count], singer_name);
            strcpy(song_ids[song_count], song_id);
            song_count++;
        }
        else if (menu_input == 2){
            if (song_count == 0){
                printf("No queued song...\n");
            }
            else{
                for (int j = 0 ; j < song_count ; j++){
                    int hour = song_durations[j] / 3600;
                    int minute = song_durations[j] / 60 % 60;
                    int second = song_durations[j] % 60;

                    printf("Song ID : %s\n", song_ids[j]);
                    printf("Song name : %s\n", song_names[j]);
                    printf("Singer name : %s\n", singer_names[j]);
                    printf("Song duration : %02d:%02d:%02d\n", hour, minute, second);
                }
            }

        }
        else if (menu_input == 3){
            if (song_count == 0){
                strcpy(current_song, "");
                strcpy(current_singer, "");
                strcpy(current_id, "");
                current_duration = 0;
            }
            
            else{
                strcpy(current_song, song_names[0]);
                strcpy(current_singer, singer_names[0]);
                strcpy(current_id, song_ids[0]);
                current_duration = song_durations[0];

                for (int k = 1 ; k < song_count ; k++){
                    strcpy(song_names[k-1], song_names[k]);
                    strcpy(singer_names[k-1], singer_names[k]);
                    strcpy(song_ids[k - 1], song_ids[k]);
                    song_durations[k-1] = song_durations[k];
                }
                song_count--;
            }

            
        }

    } while (menu_input != 4);
    
}