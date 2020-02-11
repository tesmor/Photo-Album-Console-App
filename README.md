# Photo-Album-Console-App
LT technical showcase 

## AUTHOR
created by Tessa Newman-Heggie

## LAUNCH INSTRUCTIONS
$make  
$./app 

## LOG OF KNOWN BUGS/THINGS TO IMPROVE

### bug: (fixed) some album titles are interpreted as ids 
some strings display incorrectly.
This can be fixed by using a json parser for C, instead of manually processing the strings, 
which I'm doing now. Using a json library would also make this program more generalizable to other formatting styles. 


### bug: (fixed) the last id and title for an album printed is lost and shows up at the beginning of the next printed album
Sometimes only certain characters of the lost album are printed at the beginning of the next album. 
fixed as of Feb 11, 1pm- fixed by initializing the id_name and title_name in format_album() to empty strings, 
and by adding a print statement at the end of the function



