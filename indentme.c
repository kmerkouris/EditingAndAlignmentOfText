#include <stdio.h>

int main ()
{
    char last;
    int ch,whitespace = 0,start_line =1,blocks=0;
    while ((ch=getchar())!=EOF)
    {
      
        if (ch == ' '|| ch== '\t' || ch=='\n') 
        {
            whitespace=1;
            continue;
        }
        
        if (ch =='#')                   
        {
            putchar(ch);
            ch=getchar();
            while (ch != '\n')
            {   
                if (start_line!=1)
                {
                    putchar('\n');
                    start_line=1;  
                    whitespace=0;
                }
                putchar(ch);
                ch=getchar();
            }
            putchar(ch);
            continue;
        }
        

        if(ch =='}')
        {
            blocks--;           
        }
        
        if (start_line == 1)
        {
            for (int i = 0; i < blocks; i++)
            {
                putchar('\t');
            }
        }
        
    
        
        if (ch==';' || ch=='{' || ch =='}' )
        {
            if(ch== '{')            
            {
                putchar(' ');
                blocks++;
            }
            putchar(ch);
            putchar('\n'); 
            whitespace=0;
            start_line=1;
            continue;
        }
        

        
        if (whitespace==1 && start_line==0) 
        {
            putchar(' ');
        }
       
        whitespace=0;
        start_line = 0;
        putchar(ch);
    }
}