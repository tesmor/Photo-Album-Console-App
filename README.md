# Photo-Album-Console-App
LT technical showcase 

## AUTHOR
created by Tessa Newman-Heggie

## LAUNCH INSTRUCTIONS
$make  
$./app 

## LOG OF KNOWN BUGS/THINGS TO IMPROVE

### bug: some album titles are interpreted as ids (fixed Feb 10, 6pm)
some strings display incorrectly.
This can be fixed by using a json parser for C, instead of manually processing the strings, 
which I'm doing now. Using a json library would also make this program more generalizable to other formatting styles. 


### bug: sometimes the last id and title for an album printed is lost and shows up at the beginning of the next printed album
not consistent for specific albums/queries. 
Sometimes only certain characters of the lost album are printed at the beginning of the next album. 



