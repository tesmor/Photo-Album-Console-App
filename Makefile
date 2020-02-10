#Makefile for photo console app

CC=gcc
CFLAGS=-g

all: app_main.c display_album.c
	$(CC) $(CFLAGS) -o app app_main.c display_album.c 
    
