#include <stdio.h>
#include <stdio.h>




int main() {
    char alphabet[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'}; 
    char message[100];
    char character;
    char SubstituitionKey[27];
    int key, i;
    int operation;
    
    
    printf("1.Encryption of a message with a rotation cipher given the message and rotation amount\n");
    printf("2.Decryption of a message encrypted with a rotaion cipher given cipher text and rotation amount\n");
    printf("3.Encryption of a message with a substitution cipher givien message and alphabet substitutions\n");
    printf("4.Decryption of a message encrypted with a substitution cipher given chipher text and substitutions\n");
    printf("5.Decription of a message encrypted with a rotaion cipher given text only\n");
    printf("6.Decription of a message encrypted with a substitution cipher given cipher text only\n");
    printf("Enter an operation\n");
    
    scanf("%d", &operation);// reads int operation to determine which switch case to use
    
    printf("Read %d\n", operation);// prints which case is being run
    
    if(operation < 1 || operation > 6 ) {
        printf("Enter operation between 1 and 6\n");
        //scanf("%d",&operation);
    }
    
    else if(operation == 1 || operation == 2) {
        printf("Enter Message\n");//Message for Encription/Decription
        scanf("%s", message); //reads message and stores in string
        printf("Enter key\n"); //Rotation key
        scanf("%d", &key); //reads key and stores to an int for later use
        
    }
    
    if(operation == 3 || operation == 4) {
        printf("Enter Message\n");
        scanf("%s", message);
        printf("Enter Key\n");
        scanf("%s", SubstituitionKey);
    }
    switch(operation) {
        
    case 1: //operation 1 Rot Encription
        
        for(i = 0; message[i]!='\0';++i) {
            character = message[i];
		
		if(character >= 'A' && character <= 'Z'){
			character = character + key;
		}
			else if(character > 'Z') {
			    
				character = character + 'Z' + 'A' - 1 ;
			}
			
			message[i] = character ;
        }
    printf("Encrypted Message:%s", message);
    
    
        
            break;
            
    case 2: //operation 2 Rot Decriptio
        
        
        for(i = 0;message[i]!= '\0';i++) {
            character = message[i];
            
        if(character >= 'A' && character <= 'Z') {
            character = character - key;
        }
        
        else if(character <'A') {
            
            character = character + 'Z' - 'A' + 1;
        }
         
            message[i] = character;  
            
        }
        
        printf("Decrypted Message: %s", message);
        
            break;
            
            
         {
            
            
            
        }
            
    case 3: //operation 3 Sub Encription
    
    
    for(i = 0; message[i]!='\0';++i) 
    {
        character = message[i];
    
        if(character >='A' && character <= 'Z') {
            
            character = SubstituitionKey[character -'A'];
        }          
            character = message[i];
        
    } 
        printf("Encrypted Message: %s", message);
        
            break;
            
    case 4: //operation 4 Sub Decription
        
            break;
            
    case 5: //operation 5 Rot Attack
        
            break;
            
    case 6: //operation 6 Sub Attack
        
            break;
            
    default: return 0;
    }
    
    
    
   
    
    
    
    
    
    
 return 0;   
    
}