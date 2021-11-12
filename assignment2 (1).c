// This program will play the Lotto game. This program allows the user to enter their 6 selected 
// numbers and they have a set of options, each performing a specific requirement. 
// 1. Enter any 6 numbers (1–42 inclusive) from the keyboard. 
// 2. Displaying the contents of the 1-D array containing your lotto numbers that the user entered
// 3. Sorting the array in order
// 4. Comparing the user numbers with winning numbers
// 5. Displaying the frequency of the numbers entered each time

// Author: Blessing Fernando
// OS: Windows 10
// Compiler: Borland
// I use this header file to clear screen.
#include <conio.h>
#include <stdio.h>
//#include <stdlib.h>
#define OPTION 6 // This SIZE of numbers for the options
#define PRIZE 6 // This array is for function 4 for the lotto
#define SIZE 42 // Maximum amount of numbers

// PROTOTYPES

void part1(int*,int*); // First function
void part2(int*); // second function
void part3(int*); // third function
void part4(int*,int*); // fourth function
void part5(int*); // fifth function

int main()
{
    char select;
    int frequency[SIZE + 1] = {0};
    int user[OPTION]; // the array name for user input
    int win[] = {1,3,5,7,9,11,42}; 
    
    // variables used for each options to check which options the users picks in their first try.
    int optionb,optionc,optiond,optione = 0;
    
    do
    {
        // Menu for the lotto game
        printf("\n");
        printf("\n============ MENU LOTTO GAME ==============\n ");
        
        printf("A.\tEnter any six numbers from (1-42 inclusive from the keyboard)\n ");
        printf("B.\tDisplay the six numbers you entered\n");
        printf(" C.\tNumbers sorted\n");
        printf(" D.\tCompare your six numbers with winning numbers\n");
        printf(" E.\tCheck how many times you entered the same number\n");
        printf(" F.\tExit the program\n");
        printf("\nSelect an option: \t");
        scanf("%1s",&select);
        // use this to clear the screen.
        clrscr();

        if(select == 'a')
        {
            // What the user has inputted is now inserted into user array
            // two parameters being passed through part1 function
            part1(user,frequency);
            // Makes sure that the user does not pick option b,c,d or e on their first try, so now each option is being incremented so it can be opened to be executed.
            optionb++;
            optionc++;
            optiond++;
            optione++;
            
        } // end if statement
        
        else if(select == 'b')
        {
            if(optionb > 0)
            {
                part2(user); // What the user has inputted is now inserted into user array
            } // end if
            else // The user does not enter option b then else statement is used 
            {
                printf("That is an error, you cannot pick option B in your first attempt\n");
                printf("Please select Option A in order to enter your six numbers\n");
            } // end else
        } // end else if
        
        else if(select == 'c')
        {
            if(optionc > 0)
            {
                part3(user);
            } // end if statement
            else // If the user does not choose option c
            {
               printf("That is an error, you cannot pick option C in your first attempt\n");
               printf("Please select Option A in order to enter your six numbers\n");
            }// end else
        } // end else if
        
        else if(select == 'd')
        {
            if(optiond > 0)
            {
                part4(win,user);
            } // end if 
            else //If  the user does not enter option D in first attempt
            {
                printf("That is an error, you cannot pick option D in your first attempt\n");
                printf("Please select Option A in order to enter your six numbers\n");
            }// end else
        } // end else if
        
        else if(select == 'e')
        {
            if(optione > 0)
            {
                part5(frequency);
            } // end if statement
            else
            {
                printf("That is an error, you cannot pick option E in your first attempt\n");
                printf("Please select Option A in order to enter your six numbers\n");
            } // end else
        } // end else if
        
        // This will check if the user enters any other characters/symbols other than ABCDE and plus the exit number
        else if(select!= 'a' &&select!= 'b' &&select!= 'c' &&select!= 'd' &&select!= 'e' && select!= 'f')
        {
            printf("Invalid input");
        } //end else if
    }while(select != 'f');
    printf("You have exit out of the game! See ya.");
    
    flushall();
    getchar();
    return 0;
} // end main

// Function 1 will hold the six numbers the user inputted,num is the one user has selected and the pointer freq will check how many times number has been inputted
void part1(int *num,int *freq)
{
    int i,j;
    int temp; // Temporary variable to hold each number inputted
    
    printf("Enter six different numbers\n");
    
    for(i=0; i<OPTION; i++)
    {
        scanf("%d", &*(num + i));
        // This if statement will check if the number is in range (1-42)
        if (*(num + i) >= 1 && *(num+i) <= 42)
        {
            //It will check if the user entered same number in the array
            for(j=0; j<i; j++)
            {
                if(*(num + i) == *(num + j))
                {
                    printf("Cannot enter the same number twice\n");
                    printf("The game will restart\n");
                    return; // This will bring the user back to the menu
                }// end inner if
                
            }// end inner loop
        }// end if statement
        
        // The else statement is used for numbers outside of range 1_42
        else
        {
            printf("You must enter numbers between range of 1-42\n");
            printf("The program will restart \n");
            printf("\n");
            break; // The function will restart again until user has entered correct numbers
            
        } // end else
        temp = *(num + i); // What was entered (six numbers) is put into temp
        
        *(freq + temp) = *(freq + temp) +1; // This get incremented to see how many times a certain number has been inputted throughout the WHOLE game.
    }// end for loop
} // end function 1

        
// Implement function 2
// Function 2 Display the contents of the 1-D array containing your lotto numbers that you entered
void part2(int *show)
{
    int i;
    
    printf("Display the six number you have selected\n\n");
    for(i=0; i<OPTION; i++)
    {
        printf("The numbers you have entered are %d\n", *(show + i));
    } // end for
    
} // end function 2

// Implement function 3
// Sort the contents of the array in increasing order (i.e. 1st element = smallest number,2nd element = 2nd smallest number)
void part3(int *sort)
{
    int min; // used to find the smallest number
    int temp; // used as temporary variable
    int i,j;
    
    // For loop used to sort the array
    for(i=0; i<OPTION-1; i++)
    {
        min = i;
        for(j=i+1; j<OPTION; j++)
        {
            if(sort[j] < sort[min])
            {
                min = j;
            } // end if statement
        }// end for loop
        temp = sort[min];
        sort[min] = sort[min];
        sort[min] = sort[i];
        sort[i] = temp;
    } //end for
    
    printf("The sorted numbers are \n");
    for(i=0; i<OPTION; i++)
    {
        printf("%d\t", *(sort + i)); // These are the numbers thats sorted
    } // end for
}// end the function 3

// Function 4 to be implemented - This is where I will compare the chosen lotto numbers in the 1-D array with the following winning numbers
void part4(int *diff,int *num)
{
    int equal=0; // Variable for which numbers were matched
    int i,j;
    
    printf("\n");
    printf("========================\n");
    printf("Match 6 : Jackpot\n");
    printf("Match 5 : New Car\n");
    printf("Match 4 : Weekend away\n");
    printf("Match 3 : Cinema pass\n");
    printf("Match 0 : No prize\n");
    printf("=======================\n");
    
    for(i=0; i<PRIZE; i++)
    {
        for(j=0; j<PRIZE; j++)
        {
            // This will check if the numbers match the winning numbers
            if(*(diff +j) == *(num + i))
            {
                equal++;
                printf("The winning numbers are %d\n",*(diff+j));
                printf("Your number is %d\n",*(num + i));
                
            }// end if
        } // end inner for loop
    } // end outer for loop
    
    // If statement for matches
    if(equal == 6)
    {
        printf("You've received a Jackpot");
    } // end if
    else if(equal == 5)
    {
        printf("You've received a New car");
    }// end else if
    else if(equal == 4)
    {
        printf("You've received a Weekend away");
    }// end else if
    else if(equal == 3)
    {
        printf(" You've received a Cinema pass");
    }// end else if
    else if(equal == 2 || equal ==1 || equal == 0)
    {
        printf("You won nothing sorry!");
    }// end else if
    
    // Another else if for if the user didn't get any of the matching numbers
    else if(equal!=6 && equal!=5 && equal!=4 && equal!=3)
    {
        printf("You did not match any of the numbers");
    } // end else if
} // function 4 ends

// Function 5
// This will display the frequency of the numbers entered each time the user enters a new set of numbers
void part5(int *freq)
{
    int i;
    printf("E. See how many times each number was entered\n\n");
    for(i=0; i<SIZE+1; i++)
    {
        
        // This if statement will check how many times number has been inputted
        if(*(freq + i) != 0)
        {
            printf("Number %d has been inputted %d times \n", i,*(freq + i));
        }// end if
    }// end for
    
}// end function 5
        
        
    
            
                
    
    
    
    
    

            