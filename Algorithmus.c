#include <stdio.h>



int main()
{
	int Dezimalzahl;
	printf("Bitte einen Integer zwischen 0 und 65534 eingeben:\n");
	scanf("%d",&Dezimalzahl);

	if (Dezimalzahl < 65535)
	{
		printf("Eingegebene Zahl ist: %d \n",Dezimalzahl);

	}	
	
	else
	{	
		printf("Bitte noch einmal versuchen es sind nur Zahlen KLEINER 65535 erlaubt.\n");
	
		scanf("%d",&Dezimalzahl);
	}

	long Quotient, Rest;
	int i, j=0;
	char Hexadezimal[3];

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

	for (i = j; i>=0; i--)
	{
		printf("%c",Hexadezimal[i]);
	}
	printf("\n");	
	return 0;
}
