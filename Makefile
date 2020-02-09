#Makefile for photo console app

CC=gcc
CFLAGS=-I

all: app_main.c display_album.c
	$(CC) -o app app_main.c display_album.c
    
