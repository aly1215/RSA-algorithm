//A.M.C.O
//BSCS3A

#include<stdio.h>

long long int power(int a,int b,int mod)
{
long long int t;
if(b==1)
  return a;
t=power(a,b/2,mod);
 if(b%2==0)
  return (t*t)%mod;
 else
  return (((t*t)%mod)*a)%mod;
}

int main()
{
 int n,g,x,a,y,b;
 //n is prime number
 //g is the generator
 //x is secret key of alice
 //y is secret key of bob
 // alice answer that to be sent to bob
 //bob answer that t be send to alice

 // both the persons will be agreed upon the common n and g
 printf("Enter the value of prime number and generator : ");
 scanf("%d%d",&n,&g);

 // first person will choose the x
 printf("Enter the secret code for the first person : ");
 scanf("%d",&x);
 a=power(g,x,n);

 // second person will choose the y
 printf("Enter the secret code of the second person : ");
 scanf("%d",&y);
 b=power(g,y,n);

int secretkey1 = power(b,x,n);
int secretkey2 = power(a,y,n);

printf("The secretcode is: %d\n", secretkey1);

    FILE * fp;
   /* open the file for writing*/
   fp = fopen ("decrypted.txt","w");


    FILE *filePointer;
    char ch;
    filePointer = fopen("example.txt", "r");

    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {

        fprintf(fp,"The Encrypted Message is: ");
        printf("The Encrypted Message is: \n");

           char h;

         while ((h = fgetc(filePointer)) != EOF){
         int ans= (h^secretkey1);
            char enc = ans;
            printf("%c", enc);
            fprintf (fp, "%c",enc); //write to textfil

       }

    }
    fclose(filePointer);

   fclose (fp);


 return 0;
}



