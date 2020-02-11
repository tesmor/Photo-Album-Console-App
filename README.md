# Photo-Album-Console-App
LT technical showcase 

## AUTHOR
created by Tessa Newman-Heggie

## LAUNCH INSTRUCTIONS
$make
$./app 

## LOG OF KNOWN BUGS/THINGS TO IMPROVE
Update: February 10, 6pm
fixed the bug that incorrectly parsed the titles of some photos
now, sometimes a random id and title of a photo not in the album appear before the other ids/titles

February 10, 1:30pm
currently, there is a bug where some album titles are interpreted as ids, 
and displayed incorrectly because of that and the ways ids are formatted. 
This can be fixed by using a json parser for C, instead of manually processing the strings, 
which I'm doing now. Using a json library would also make this program more generalizable to other formatting styles. 




