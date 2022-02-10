/**************************************************************
* Class:  CSC-415-02 Fall 2021
* Name: Edel Jhon Cenario
* Student ID: 921121224
* GitHub Name: kurtina09
* Project: Assignment 2 - Buffer and Structs
*
* File: cenario_edeljhon_HW2_main.c
*
* Description: This is my Assignment 2 - Buffer and Struct
*
**************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "assignment2.h"

int main(int argc, char *argv[]){

   const char *next;
   char buffer[BLOCK_SIZE];

   //Defining my object type of personalInfo -- Allocating memory to it.
   personalInfo *myInfo=(personalInfo *)malloc(sizeof(personalInfo));

   //Validating if I have an error allocating memory. 
   if(myInfo==NULL){
       printf("An error has occured allocating the memory.");
       printf("\n");
   }

   //Assigning values to my personalInfo object. 
   //Note that '->' is used to assign the values.
   //Also notice that firstName and lastNames values are being assigned thru the command line arguments. 
   //Assigning values to studentId and level by hardcoding it.
   myInfo->firstName=argv[1];
   myInfo->lastName=argv[2];
   myInfo->studentID=921121224;
   myInfo->level=SENIOR;

   //Assigning my languages to personalInfo object. 
   myInfo->languages =KNOWLEDGE_OF_C | KNOWLEDGE_OF_JAVA | KNOWLEDGE_OF_JAVASCRIPT | KNOWLEDGE_OF_PYTHON | KNOWLEDGE_OF_CPLUSPLUS | KNOWLEDGE_OF_SQL | KNOWLEDGE_OF_HTML | KNOWLEDGE_OF_PHP;

   //Using strcpy to copy message from the argument in the command line
   strcpy(myInfo->message,argv[3]);

   //Writing personal info structure by defining an int variable, then using it to call function writePersonalInfo. 
   //Note that I am using myInfo as the parameter -- the message that we got from the command line argument above.
   int ej=writePersonalInfo(myInfo);
   if(ej==1){
       printf("An error has occured while attempting to create Personal info."); //Printing out an error message to user
       printf("\n");

       return ej;
    } else{
  
    }

   int len=0;
   int i=0;
       
       
   //Using function to get the next string
   next= getNext();

    //Iterating thru until I get NULL -- 
    //Grab the length of the string input --
    //Fill the buffer with bytes received -- THEN copy a single char, one at a time. 

    //IF the buffer is filled -- commit the buffer , then EMPTY the buffer 
    //Setting index to 0 after emptying
   while(next!=NULL){  
       len=strlen(next);      
       for(int k=0;k<len;k++){          
           buffer[i++]=next[k];          
           if(i==256){              
               commitBlock(buffer);              
               strcpy(buffer,"");
               i=0;
           }
       }
            //Using function to get the next string
            next= getNext();
      
   }

   //Validating if the null is received from the input -- 
   //Make sure that last filled buffer was not commited -- IT IS NOT FULLFILLED 
   if(i!=0){
       commitBlock(buffer);
   }

   //Calling to check results -- Printing hexadecimal characters in the output 
   ej=checkIt();
  
   //FREE MEMORY!!!!!!!
   free(myInfo);
  
   return ej;
                
}