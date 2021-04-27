#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum {FALSE, TRUE} boolean; //boolean used for the function

//This function determines if one string is an anagram of another
boolean anagram(const char*,const char*);

int main(void) {
	const char* string1 = "elvis"; //strings for demo 1
	const char* string2 = "evils";
	const char* string3 = "slingshots"; //strings for demo 2
	const char* string4 = "shotstrins";

	//first comparison
	if (anagram(string1, string2)){
		printf("%s is an anagram of %s\n", string1, string2);
	}
	else{
		printf("%s is NOT an anagram of %s\n", string1, string2);
	}

	//second comparison
	if (anagram(string3, string4)){
		printf("%s is an anagram of %s\n", string3, string4);
	}
	else{
		printf("%s is NOT an anagram of %s\n", string3, string4);
	}


	return EXIT_SUCCESS;
}

boolean anagram(const char* str1, const char* str2){
	//first, figure out the length of both strings
	unsigned int len_str1 = strlen(str1);
	unsigned int len_str2 = strlen(str2);

	//determine whether or not the strings are the same length and return false if they don't match
	if (len_str1 != len_str2)
		return FALSE;

	//logically, to find out if one string is an anagram of another, we must loop through str1 and compare each character to str2

	//we need a boolean to determine if we found the letter we're looking for
	boolean letterFound;
	//use a duplicate string as a modifiable surrogate
	char* modifiable_str2 = (char*) malloc (sizeof(char)*len_str2);
	strcpy(modifiable_str2, str2);

	//use a for loop to loop through the first string
	for (unsigned int loop_str1 = 0; loop_str1<len_str1; loop_str1++){
		//reset the letterfound bool every time we loop through the nested loop
		letterFound = FALSE;
		//nested here, loop through string 2
		for (unsigned int loop_str2 = 0; loop_str2<len_str2; loop_str2++){
			//use an if statement to determine if a looped letter matches
			if (str1[loop_str1] == modifiable_str2[loop_str2]){
				modifiable_str2[loop_str2] = '\0'; //turn the character blank if a duplicate is found
				letterFound = TRUE; //if it matches we can continue the loop
				break; //end the loop prematurely to prevent more letters from being sniped
			}
		}
		if (letterFound == FALSE){ //break out upon failure to find the letter
			break;
		}
	}
	free(modifiable_str2);
	return letterFound;
}
