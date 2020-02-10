#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <curl/curl.h>
#include "display_album.h"

int main();
void menu_select(char *selection);
void view_album(int album_number);
void view_all_albums();
void view_random_album();

bool DISPLAY_MENU = false;

int main() {
    DISPLAY_MENU = true;
    printf("\n\n");
    printf("Welcome to your photo album!\n");
    
    while(DISPLAY_MENU == true){
       
		printf("\nAlbums available: 1-100\n\n");
		printf("Type the number of the photo album you wish to view or select an option below: \n");
		printf("r: View a random album\n");
		printf("a: View all albums\n");
		printf("x: Exit photo album\n");

		int max_input_size = 10;
		char *selection = malloc(sizeof(char)*10);
		fgets(selection, max_input_size, stdin); //read user's selection
		printf("Your selection is: %s", selection);
        
		//test if user input is an integer
		if (atoi(selection) == 0){
			menu_select(selection);
		} else{
			//convert the album number into an int
			int album_number = atoi(selection);
			free(selection);
			view_album(album_number);
		}
   }
   return 0; 
}

void menu_select(char *selection){
    int i = strlen(selection)-1;
    if( selection[ i ] == '\n') {
        selection[i] = '\0';
    }
    if ((selection[0]== 'a') && (strlen(selection) == 1)){
        view_all_albums();
		free(selection);
    } else if((selection[0] == 'r') && (strlen(selection) == 1)){
        view_random_album();
		free(selection);
    } else if((selection[0] == 'x') && (strlen(selection) == 1)){
        DISPLAY_MENU = false;
		free(selection);
		printf("\nEXITING PHOTO ALBUM\n\n");
        exit(0);
    } else {
        printf("\nError: menu selection '%s' is not an option. \nPlease select another option or input the number of a specific album.\n\n", selection);
		free(selection);
    	}	    
    }  

void view_album(int album_number){
	if((album_number > 100 )|(album_number < 1  ) ){
		printf("Album selection %i is not in range 1-100. Please make another selection.\n", album_number );
	} 
	else{
		printf("Album %i: \n", album_number);
		char album_str[4];
		
		//convert album number into string for concatenation
		sprintf(album_str, "%d", album_number);
		char url_query[110] = "https://jsonplaceholder.typicode.com/photos?albumId=";
    	strcat(url_query, album_str);
    	display(url_query);
	}
    
}

void view_all_albums(){
    char url_query[] = "https://jsonplaceholder.typicode.com/photos";
	printf("All albums:\n");
	display(url_query);
}

void view_random_album(){
	int random_number = rand() % 100 + 1;
	view_album(random_number);
}





