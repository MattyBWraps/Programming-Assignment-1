#include <stdio.h>, <math.h>



int main() {
    char alphabet[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}; 
    char message[100];
    int key;
    int operation;
    
    
    printf("1.Encryption of a message with a rotation cipher given the message and rotation amount\n");
    printf("2.Decryption of a message encrypted with a rotaion cipher given cipher text and rotation amount\n");
    printf("3.Encryption of a message with a substitution cipher givien message and alphabet substitutions\n");
    printf("4.Decryption of a message encrypted with a substitution cipher given chipher text and substitutions\n");
    printf("5.Decription of a message encrypted with a rotaion cipher given text only\n");
    printf("6.Decription of a message encrypted with a substitution cipher given cipher text only\n");
    
    scanf("%d", &operation);
    
    printf("Read %d\n", operation);
    
    switch(operation) {
        case 1: //operation 1
        
        
    printf("Enter Message\n");//Message for Encription/Decription
    gets(message);
    printf("Enter key\n");//Rotation key
    scanf("%d", &key);
        
            break;
            
        case 2: //operation 2
        
            break;
            
        case 3: //operation 3
        
            break;
            
        case 4: //operation 4
        
            break;
            
        case 5: //operation 5
        
            break;
            
        case 6: //operation 6
        
            break;
            
        default: return 0;
    }
    
    
    
   
    
    
    
    
    
 return 0;   
    
}