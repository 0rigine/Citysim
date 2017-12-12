#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct city {
char* nomdelaville;
char* faction;
int gold;
int bouffe;
int energy;
int nb_contrat;
int pop;
int inge;
int traders;
int fermiers;
int chomeur;
int cood_x;
int cood_y;
} city;

struct SMALL_RECT {
    SHORT Left;
    SHORT Top;
    SHORT Right;
    SHORT Bottom;
};

void color(int t,int f) // Fonction de changement de couleur
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,f*16+t);
}

void adjustWindowSize() // Reajustement de la fenêtre
{
    struct SMALL_RECT test;

    HANDLE hStdout;
    COORD coord;
    BOOL ok;

    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    coord.X = 190;
    coord.Y = 48;
    ok = SetConsoleScreenBufferSize(hStdout, coord);

    test.Left = 0;
    test.Top = 0;
    test.Right = coord.X-1;
    test.Bottom = coord.Y-1;

    SetConsoleWindowInfo(hStdout, ok, &test);

}
void Firstscreen()
{   printf("\n");
    color(2,0);
    Locate(70,15);
    printf("====> Bienvenue dans Citysim <=====");
    color(15,0);
}

void print_ville_name(city * ville)
{
    color(10,0);printf("%s",ville->nomdelaville);
    color(15,0);printf("[");
    color(11,0);printf("%s",ville->faction);
    color(15,0);printf("]");
}

void Locate(SHORT x, SHORT y)
{
    HANDLE hmenu = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(hmenu, Pos);
}


int Choix(const char* ch[],int taille,int x, int y) // Creation d'un menu
{
    int i,curseur = 0;
    Locate(x, y);
    int y_bis = y;
    for (i = 0; i < taille; i++)
    {
    ++y;
    printf("  %s\n", ch[i]);
    Locate(x,y);
    }

    while (1) // gauche 0x4B   droite 0x77 haut 0x50  bas 0x48
    {
        int touche = getch();
        Locate(x, y_bis + curseur);
        printf(" ");
        if (touche == 0x50 && curseur < taille-1)
            curseur++;
        if (touche == 0x48 && curseur > 0)
            curseur--;
        if (touche == 0x0D)
            return curseur + 1;
        Locate(x, y_bis + curseur);
        printf(">");
        Locate(189,0);
    }
    return 0;
}

void valeur(city * ville)
{
    if (ville != NULL)
    {
            Locate(130,0);printf("|");
    Locate(130,1);printf("|\t RESSOURCES DE LA VILLE : ");print_ville_name(ville);printf("\n");
    Locate(130,2);printf("|");
    Locate(130,3);printf("|");
    Locate(130,4);printf("|");color(14,0);printf(" GOLD");color(15,0);printf("   : %d",ville->gold);printf("\n");
    Locate(130,5);printf("|");
    Locate(130,6);printf("|");color(12,0);printf(" BOUFFE");color(15,0);printf(" : %d",ville->bouffe);printf("\n");
    Locate(130,7);printf("|");
    Locate(130,8);printf("|");color(9,0);printf(" ENERGIE");color(15,0);printf(" : %d",ville->energy);printf("\n");
    Locate(130,9);printf("|");
    Locate(130,10);printf("|");color(13,0);printf(" NOMBRE DE CONTRATS");color(15,0);printf(" : %d",ville->nb_contrat);printf("\n");
    Locate(130,11);printf("|");
    Locate(130,12);printf("|");color(4,0);printf(" POPULATION");color(15,0);printf(" : %d",ville->pop);printf("\n");
    Locate(130,13);printf("|");
    Locate(130,14);printf("|");color(5,0);printf(" INGENIEURS");color(15,0);printf(" : %d",ville->inge);printf("\n");
    Locate(130,15);printf("|");
    Locate(130,16);printf("|");color(2,0);printf(" TRADERS");color(15,0);printf(" : %d",ville->traders);printf("\n");
    Locate(130,17);printf("|");
    Locate(130,18);printf("|");color(1,0);printf(" FERMIERS");color(15,0);printf(" : %d",ville->fermiers);printf("\n");
    Locate(130,19);printf("|");
    Locate(130,20);printf("|");color(12,0);printf(" CHOMEUR");color(15,0);printf(" : %d",ville->chomeur);printf("\n");
    Locate(130,21);printf("|");
    }
}

void print_map(int x, int y)
{  int i,j;

    for (i=2 ; i<125 && i<(2+x*8); i+=8)
    {
        for (j=1; j<20 && j<(1+y*4); j+=4)
        {
            Locate(i,j);printf("_/-\\_");
            Locate (i,j+1);printf("| o |");
            Locate(i,j+2);printf("|_n_|");

        }
    }
}

void our_faction(int x, int y)
{
    color(12,0);
    Locate(x,y);printf("_/-\\_");
    Locate (x,y+1);printf("| o |");
    Locate(x,y+2);printf("|_n_|");
    color(15,0);
}

void choice(int * x, int * y,int taille_x, int taille_y)
{   int curseur_x=0,curseur_y=0;
      while (1) // gauche 0x4B   droite 0x77 haut 0x50  bas 0x48
    {
        int touche = getch();
        Locate(0 + curseur_x*8, 2 + curseur_y*4);
        printf(" ");

        if (touche == 0x50 && curseur_y < taille_y-1) // haut
        {
            curseur_y++;
        }
        if (touche == 0x48 && curseur_y > 0) // bas
            curseur_y--;

        if (touche == 0x4D && curseur_x < taille_x-1) // droite
        {
            curseur_x++;
        }
        if (touche == 0x4B && curseur_x > 0) // gauche
            curseur_x--;

        if (touche == 0x0D)
            {
                (*x) = 2+curseur_x*8;
                (*y) = 1+curseur_y*4;
                return;
            }

        Locate(0 + curseur_x*8, 2 + curseur_y*4);
        printf(">");
        Locate(189,0);
    }
    return;
}

void racheter_ville(int x, int y)
{
    Locate(100,26);printf("Cette ville coute 15221 gold, veux-tu la racheter?");
    const char* tab_reponse_oui_non[] = {"Oui !","Non, je prefere attendre..."};
    int d = Choix(tab_reponse_oui_non,2,105,28);
    switch (d)
    {
        case 1 : our_faction(x,y);break;

        default : break;
    }
}

void init_city_tab(city ** tab,const int taille)
{   int i;

    for (i = 0; i < taille; i++)
        (*(tab + i)) = NULL;

}

// init_city(char* nomdelaville,char* faction,int gold,int bouffe,int energy,int nb_contrat,int fermier,int pop,int inge,int traders,int chomeur,int cood_x,int cood_y)

void init_city(city * ville,char* nomdelaville,char* faction,int gold,int bouffe,int energy,int nb_contrat,int fermier,int pop,int inge,int traders,int chomeur,int cood_x,int cood_y)
{
    strcpy(ville->nomdelaville,nomdelaville);
    strcpy(ville->faction,faction);
    ville->gold = gold;
    ville->bouffe = bouffe;
    ville->energy = energy;
    ville->nb_contrat = nb_contrat;
    ville->fermiers = fermier;
    ville->pop = pop;
    ville->inge = inge;
    ville->traders = traders;
    ville->chomeur = chomeur;
    ville->cood_x = cood_x;
    ville->cood_y = cood_y;
}

void addin_city_tab(city ** tab,const int taille,city * ville)
{   int i,coord_ville;

    coord_ville = (((ville->cood_x)/8)+1) + ((ville->cood_y)/4)*16;


    for (i = 0; i < taille; i++)
        if (i == coord_ville)
            {
                *(tab +i) = ville;

            }
}

city * search_city_by_position(city ** tab, const int taille, int x, int y)
{   int i=0;
    Locate(0,0);

    for (i=0;i < taille; i++)
    {
        if ((*(tab + i) != NULL))
            {
                if (((*(tab + i))->cood_x == x) && ((*(tab + i))->cood_y == y))
                {
                    return (*(tab + i));
                }
            }
    }

    return (*(tab + i));
}

void erase(int x, int y,int x_bis,int y_bis)
{   int i,j;
    Locate(x,y);
    for (i=y; i < y_bis; i++)
    {
        for (j=0; j < x_bis; j++)
        {
            printf(" ");
        }
    }
}



int main(int argc, char *argv[])
{   adjustWindowSize();
    Firstscreen();
    const char* tab_menu_principale[] = {"Jouer","Credit","Quitter"};
    const char* tab_actions[] = {"Racheter une ville","Inspecter","Modification des ressources","Contrats","Fin du tour"};
    int c = Choix(tab_menu_principale,3,80,20);
    int d=0;
    int x_choice=0,y_choice=0;
    int x_search=0,y_search=0;
    city * tampon = NULL;
    city ** tab_city = malloc(sizeof(city) * 80);
    system("cls");           // clear de console
    /*city * Vincennes = init_city("Vincennes","GroupeD",15000,18555,8555,5,1000,333,333,333,1,23,9);
    city * Mehdi = init_city("Mehdi","EfreiChomage",5000,555,55,1,400,133,134,133,0,2,1);
    city * Landshoot = init_city("Landshoot","Enfoire",40000,2000000,4000,50,2400,1200,1100,10,80,58,17); */
    init_city_tab(tab_city,80);

    city * test = malloc(sizeof(city));
    city * test2 = malloc(sizeof(city));

    init_city(test,"Vincennes","GroupeD",15000,18555,8555,5,1000,333,333,333,1,26,9);

    addin_city_tab(tab_city,80,test);

    init_city(test2,"Mehdi","EfreiChomage",5000,555,55,1,400,133,134,133,0,2,1);
    addin_city_tab(tab_city,80,test2);

 //   addin_city_tab(tab_city,80,init_city("Vincennes","GroupeD",15000,18555,8555,5,1000,333,333,333,1,26,9));
 //   addin_city_tab(tab_city,80,init_city("Mehdi","EfreiChomage",5000,555,55,1,400,133,134,133,10,34,9));

    switch(c)
    {
        case 1 :

//        valeur(Vincennes);
        print_map(16,5); // La taille de la ville appartient à  [16;5]
        our_faction(26,9);
        Locate(0,21);printf("__________________________________________________________________________________________________________________________________");




        while (d != 5)
        {
            Locate(5,25);color(5,0);printf("\t\t --- A toi de jouer, quelles actions veux-tu realiser? ---");color(15,0);
          d = Choix(tab_actions,5,25,28);
            switch(d)
            {
                case 1 :
                        choice(&x_choice,&y_choice,16,5);
                        racheter_ville(x_choice,y_choice);
                        erase(99,25,130,35);
                        break;

                case 2 :
                        choice(&x_choice,&y_choice,16,5);

                        break;


                default : d=5;break;
            }
        }

        break;

        case 2 : Locate(40,22);printf("Merci a Marie-Anne Ferreira, Benjamin Jaulent, Malo Puissant, Julien Bonnet, et ???????????????? a+");break;

        default : exit(EXIT_FAILURE);
    }

    Locate(180,44);
return 0;
   }
