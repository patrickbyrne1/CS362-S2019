#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
    
    // test random ASCII values by getting random int in range 
	int randoInt = rand()%(126-32) + 32;
	// cast to char and return it
	return (char)randoInt;
}

char *inputString()
{
    // TODO: rewrite this function
    int index=0;
    // create char array to build string
    char charArray[6];
    // create char pointer to return
    char *randoStr = NULL;
    // just use ASCII values between e and t (error string is 'reset')
    // ASCII 'e' is 101 and 't' is 116
	while(index < 5) {
		charArray[index] = (char)(rand()%(117-101) + 101); 
		//inputChar();
		index++;
	}
	// add null terminating character
	charArray[5] = '\0';
	// set char pointer to first address of array 
	randoStr = charArray;
    return randoStr;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
