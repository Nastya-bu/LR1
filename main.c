#include <stdio.h>
#include <locale.h>
#include <stdlib.h>




int main ()
{
 setlocale(LC_ALL,"Russian");
    int k;
    printf ("¬ведите натуральное число k дл€ сдвига: ");
    scanf_s ("%d", &k);
    getchar (); 
    if (k < 1) return 0;
    encrypter (k);
	decipher ();
	system("pause");
    return 0;
   
}

void encrypter (int k)
{
    FILE *fp1, *fp2;
    fopen_s(&fp1, "input.txt", "r");
    fopen_s(&fp2, "output.txt", "w");
    
    char x,y;
    x = getc(fp1);
    while (!feof(fp1))
    { 
            y = (x+k)%256;
             
			fputc(y,fp2); 
        x = getc(fp1);
    }
    printf ("Ўифрование завершено.\n");
    fclose (fp1);
    fclose (fp2);
}

void decipher ()
{
    FILE *fp1, *fp2, *fp3;
    fopen_s(&fp1, "input.txt", "r");
    fopen_s(&fp2, "output.txt", "r");
	fopen_s(&fp3, "decoutput.txt", "w"); 
    int inp[256] = {0};
    int out[256] = {0};
    
    char x = 0;
	char y = 0;   
	 
    while (!feof(fp1)) {
        x = getc(fp1);
        inp[(int)x]++;
		
		     
    }
 
     while (!feof(fp2)) {
        x = getc(fp2);
        out[(int)x]++; 
        
		    
    }
    
 		         
    fseek(fp2,0,SEEK_SET);
    
           
    int i = 0;
     
    while (!feof(fp2)) {
      x = getc(fp2);
        for ( i=0 ; i < 256; i++) {
		
            if (out[x] == inp[i] && inp[i] != 0) 
            fputc(i,fp3);      
} 

}
	printf ("„астотный анализ завершен.\n");
    fclose (fp1);
    fclose (fp2);
    fclose (fp3);

}
