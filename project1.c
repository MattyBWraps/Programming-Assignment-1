/*================================================
 *
 *
 *
 *
 *
 *
 *
 *
 *=================================================
 */

#include <stdio.h>
#include <string.h>

// Function Prototypes
void displayMenu();     
void rotationEncryption(char *msg, int key);
void rotationEncryption(char *msg, int key);
void substitutionEncryption(char *msg, char *subkey);
void substitutionDecryption(char *msg, char *subkey);
void rotKeylessDecryption(char *msg);
void subKeylessDecryption(char *msg);
// Function Prototypes


// Start of main
int main() 
{
    char alphabet[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'}; 
    char message[1000];
    char character;
    char SubstituitionKey[27];
    int key;
    int operation;
    int loop = 0;
    int exitCondition = 0;
    
    do      // A Loop to repeat the menu if incorrect option
    {        
        if (loop == 0)
        {   
            displayMenu();    // Prints the menu
            scanf("%d", &operation);// reads int operation to determine which switch case to use
            
            printf("Read %d\n", operation);// prints which case is being run
            loop = 100;  // exits loop
        }

        if(operation < 1 || operation > 6 ) 
        {
            printf("<><><> ERROR !!! Enter operation between 1 and 6 <><><>\n");
            
            displayMenu();
            scanf("%d",&operation);
        }
        else 
        {
            exitCondition = 1;
        }
        
    } 
    while (exitCondition == 0);
    
    if(operation == 1 || operation == 2) 
    {
        printf("Enter Message\n");//Message for Encription/Decription
        scanf("%s", message); //reads message and stores in string
        printf("Enter key\n"); //Rotation key
        scanf("%d", &key); //reads key and stores to an int for later use
    }
    
    if(operation == 3 || operation == 4) 
    {
        printf("Enter Message\n");
        scanf("%s", message);
        printf("Enter Key\n");
        scanf("%s", SubstituitionKey);
    }
        
    if(operation ==5 || operation ==6)  
    {
        printf("Enter Message\n");
        scanf("%s", message);
    }
    
    switch(operation) 
    {
        
        case 1: 
            rotationEncryption(message, key);   //Operation 1 Rotation Encription
            break;
            
        case 2: 
            rotationDecryption(message, key);   //Operation 2 Rotation Decription
            break;
            
        case 3:
            substitutionEncryption(message, SubstituitionKey);  //Operation 3 Sub Encription
            break;
            
        case 4:
            substitutionDecryption(message, SubstituitionKey);  //Operation 4 Sub Decription
            break;
            
        case 5:
            rotKeylessDecryption(message);  //Operation 5 Rot Attack
            break;
            
        case 6: 
            subKeylessDecryption(message);  //Operation 6 Sub Attack
            break;
            
        default: 
            return 0;
        
    }

    return 0;  
    
} 
// End of main



// =====  Start of Functions =====



/*----------------------------
 * purpose: displays menu
 * inputs: none
 * return values: none
 * limitations: n/a
 *----------------------------
*/
void displayMenu () 
{
    printf("1.Encryption of a message with a rotation cipher given the message and rotation amount\n");
    printf("2.Decryption of a message encrypted with a rotaion cipher given cipher text and rotation amount\n");
    printf("3.Encryption of a message with a substitution cipher givien message and alphabet substitutions\n");
    printf("4.Decryption of a message encrypted with a substitution cipher given chipher text and substitutions\n");
    printf("5.Decription of a message encrypted with a rotaion cipher given text only\n");
    printf("6.Decription of a message encrypted with a substitution cipher given cipher text only\n");
    printf("Enter an operation\n");
}

/*----------------------------
 * purpose:
 * inputs:
 * return values:
 * limitations:
 *----------------------------
*/
void rotationEncryption(char *msg, int key) 
{
    int i = 0;
  
    for(i = 0; msg[i]!='\0';++i) 
    {
        char c = msg[i];
		
		if(c >= 'A' && c <= 'Z')
		{
			c = c + key;
		}
		
		if(c > 'Z') 
		{
		    c = c - 'Z' + 'A' - 1 ;
		}
		
		msg[i] = c ;
    }
    
    printf("Encrypted Message:%s", msg);

}


/*----------------------------
 * purpose:
 * inputs:
 * return values:
 * limitations:
 *----------------------------
*/
void rotationDecryption(char *msg, int key) 
{

    int i = 0;
    
    for(i = 0;msg[i]!= '\0';i++) 
    {
        char c = msg[i];
        
        if(c >= 'A' && c <= 'Z') 
        {
            c = c - key;
        }
        
        if(c <'A') 
        {
            c = c + 'Z' - 'A' + 1;
        }
         
        msg[i] = c;  
            
    }
    
    printf("Decrypted Message: %s", msg);

}



/*----------------------------
 * purpose:
 * inputs:
 * return values:
 * limitations:
 *----------------------------
*/
void substitutionEncryption(char *msg, char *subkey) 
{
    int i = 0;
    
    for(i = 0; msg[i]!='\0';++i) 
    {
        char c = msg[i];
        
        if(c >='A' && c <= 'Z') 
        {
            c = subkey[c -'A'];
        }          
        
        msg[i] = c;
            
    } 
    
    printf("Encrypted Message: %s", msg);
    
}


/*----------------------------
 * purpose:
 * inputs:
 * return values:
 * limitations:
 *----------------------------
*/
void substitutionDecryption(char *msg, char *subkey)    
{
    int i = 0;
    int m = 0;

    for(i = 0; msg[i]!='\0'; ++i) 
    {
        char c = msg[i];
        
        if(c >='A' && c <= 'Z')
        {
            for (m=0; m<27; m++)   
            {
                if (msg[i] == subkey[m])
                {
                    break;
                }
            }    
        }          
        
        msg[i] = 'A' + m;
        
    } 
    
    printf("Decrypted Message: %s", msg);

}


/*----------------------------
 * purpose:
 * inputs:
 * return values:
 * limitations:
 *----------------------------
*/
void rotKeylessDecryption(char *msg)    
{
    
    int counter = 0;
    int i = 0;
    
    for(i = 0;msg[i]!= '\0'; i++) 
    {
        char c = msg[i];
        
        while(counter < 27) 
        {    
            if(c >= 'A' && c <= 'Z') 
            {
                c = c - counter ;
            }
            
            if(c <'A') 
            {
                c = c + 'Z' - 'A' + 1;
            }
            
            msg[i] = c;  
            
            counter++;
        }
    }  
    
    printf("Decrypted Message: %s\n", msg); 
}   


/*----------------------------
 * purpose:
 * inputs:
 * return values:
 * limitations:
 *----------------------------
*/
void subKeylessDecryption(char *msg)    
{
    
    
}


// =====  END of Functions =====