#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <curl/curl.h>
#include <string.h>
#include "display_album.h"


void display(char url_query[]);
int formatAlbum();
int is_substring(char line[], char target[]);

void display(char url_query[]){
	//uses curl to fetch text from given url and save it to text file
    char command[120] =  "curl --silent -o album.txt ";
    strcat(command, url_query);
    system(command);
	formatAlbum();

}

int formatAlbum(){
	FILE *album;
    char str[10000];
    char file_name[] = "album.txt";
	int maxchar = 10000;
	char line[1000];
	
	//to identify lines to print
	char id[]= "id";
	char title[]= "title";
	char album_id[] = "albumId";
	
    album = fopen(file_name, "r");
	bool first_id = true; //for making formatting look better at beginning
	char title_name[120]= " ";
	char id_name[10]= " ";
	
    if (album == NULL){
        printf("Could not open file %s\n",file_name);
        return 1;
    } 
	//while there's a line in the text file
    while (fgets(str, maxchar, album) != NULL){
	 
	bool print_id= false;

		//to make sure id and title only printed once per photo
	    if(is_substring(str, album_id)){
			print_id = true;
			
		//if "title" is in the line, prints the title 
		} else if (is_substring(str, title)){
			const char *from = str;
  			 
  			strncpy(title_name, from+13, 120);
			
			//removes comma from title
			char *comma_pointer_title = strchr(title_name, ',');
			if (comma_pointer_title != NULL){
				*comma_pointer_title = '\0';
			}
			
		}
		//if "id" is in the line, prints the id
		else if(is_substring(str, id)){
			
			const char *from = str;
  			strncpy(id_name, from+10, 10);
			
			//removes comma from id
			char *comma_pointer = strchr(id_name, ',') ;
			
			if (comma_pointer != NULL){
				*comma_pointer = '\0';
			}
		} else if(is_substring(str, album_id)){
			print_id = true;
		} 
		//check to make sure id and title only printed once per photo
		if ((print_id) && (!first_id)){
			printf("\n%s ",id_name);
			printf("%s\n",title_name);
			print_id = false;
		} else if ((print_id) && (first_id)){
			printf("%s ",id_name);
			printf("%s\n",title_name);
			print_id = false;
			first_id = false;
		} 
	}
 
	//prints the last id and title in the album
	printf("\n%s ",id_name);
	printf("%s\n",title_name);
    fclose(album);
	return 0;
}

int is_substring(char line[], char target[]){
  int i, j=0, k;
  for(i=0; line[i]; i++)
  {
    if(line[i] == target[j])
    {
      for(k=i, j=0; line[k] && target[j]; j++, k++)
        if(line[k]!=target[j])
            break;
       if(!target[j]){
        return 1;}
    }
  }
 return 0;
}

