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
	char id[]= "id";
	char title[]= "title";
    album = fopen(file_name, "r");
	
    if (album == NULL){
        printf("Could not open file %s\n",file_name);
        return 1;
    }
	//while there's a line in the text file
    while (fgets(str, maxchar, album) != NULL){
		
		//if "id" is in the line, prints the id number
	    if(is_substring(str, id)){
			const char *from = str;
  			char id_name[10]; 
  			strncpy(id_name, from+10, 10);
			//removes comma from id
			*strchr(id_name, ',') = '\0';
			
			//works:
			//id_name[strlen(id_name)-1]= '\0';
			//id_name[strlen(id_name)-1]= '\0';
	
			
			
			//printf("\nstrlen(id_name_long): %lu\n",strlen(id_name_long));
			printf("\nid: %s\n",id_name);
			
		//if "title" is in the line, prints the title
		} else if(is_substring(str, title)){
			const char *from = str;
  			char title_name[100]; 
  			strncpy(title_name, from+13, 100);
			//removes comma from title
			*strchr(title_name, ',') = '\0';
			printf("title: %s\n",title_name);
		}
	}
 
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

