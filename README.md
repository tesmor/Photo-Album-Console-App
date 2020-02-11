# Photo-Album-Console-App
LT technical showcase 

## AUTHOR
created by Tessa Newman-Heggie

## LAUNCH INSTRUCTIONS
$make  
$./app 

## LOG OF KNOWN BUGS/THINGS TO IMPROVE

### bug: some album titles are interpreted as ids (fixed as of Feb 10, 6pm)
some strings display incorrectly.
This can be fixed by using a json parser for C, instead of manually processing the strings, 
which I'm doing now. Using a json library would also make this program more generalizable to other formatting styles. 


### bug: sometimes, random characters appear before the other ids/titles
not consistent for specific albums/queries



