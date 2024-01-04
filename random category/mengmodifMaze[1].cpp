#include <stdio.h>
#include <string.h>

int maze(char map[][1001], int y, int x, int N){
	if(y==N && x==N){
		map[y][x] = 'X';
		return 1;
	}
	if(map[y][x]!='.')return 0;
	
	map[y][x] = 'X';
	if(maze(map,y+1,x,N))return 1;
	if(maze(map,y,x+1,N))return 1;
	map[y][x] = '.';
	
	return 0;
}

int main() {
	int n;
	printf("Masukkan luas (n) : ");
	scanf("%d",&n); getchar();
	char map[1001][1001];
	
	printf("Masukkan bentuk maze (\".\" / \"#\") :\n");
	for(int i=0 ; i<n ; i++){
		scanf("%s",map[i]); getchar();
	}
	
	if(maze(map, 0 , 0, n-1)){
		puts("=== Path ===\n");
		for(int i=0 ; i<n ; i++)printf("%s\n",map[i]);
	}else{
		puts("=== Path is not found :(");
	}
}
