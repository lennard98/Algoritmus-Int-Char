#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char inttochar(int Dezimalzahl)
{
    long Quotient, Rest;
    int i, j=0;
    char Hexadezimal[4] = {'0','0','0','0'};

    Quotient = Dezimalzahl;

    while (Quotient !=0)
    {
        Rest = Quotient % 16;
        if (Rest<10)
            Hexadezimal[j++]= 48 + Rest;
        else
            Hexadezimal[j++]= 55 + Rest;
            Quotient = Quotient / 16;
    }
    
    //Zeige Integer als Char
    printf("Der Integer als Char ist:\n");
    for (i = 4; i>=0; i--)
    {
        printf("%c",Hexadezimal[i]);
    }
    printf("\n");

    return 0;
}
int main(int argc, char* argv[])
{

    if ( argc <2)
    {
        printf("Bitte -h nutzen \n");
        return 0;
    }

    int Dezimalzahl;
    int c;

    while ((c = getopt (argc, argv, "hf1:"))!= 1)
        switch (c)
        {
        case 'h':
            printf("Um Zahlen einzugeben nutzen Sie bitte den Schalter -f. Sie bekommen als Rückgabe die Zahl als 4 stelligen Char. \n");
            exit(0);

        case 'f':
            printf("Bitte eine Zahl von 0 bis maximal 65534 eingeben.\n");
            scanf("%d",&Dezimalzahl);


            if (Dezimalzahl < 65535)
            {
                printf("Eingegebene Zahl ist: %d \n",Dezimalzahl);
		inttochar(Dezimalzahl);
            }

            else
            {
                printf("Bitte noch einmal versuchen es sind nur Zahlen KLEINER 65535 erlaubt.\n");

                scanf("%d",&Dezimalzahl);
            }
		

		return 0;
        case '?':
            printf("Bitte -h benutzen!\n");
            exit(1);

        }
}
