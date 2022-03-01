/*
	Project: Asteroid Miner
	Autor: Tymoteusz "Tymianox"
	Description: Asteroid Miner is a simple game where you have to catch all asteroids coming your way. How many can you catch? Can you save Earth from running out of resources?
*/

#include <iostream> //cout, cin
#include <conio.h> //getch
//#include <cstdlib> //system
#include <time.h> //srand
using namespace std;

//definicje zmiennych
int y=20, x=12, i=0, j=0, wspXstatku=5, wspXasteroid=(rand()%(x-2)+1), wspYasteroid, klawisz, wynik=0;
char plansza[20][12];

/*
	y - wysoko�� planszy
	x - szeroko�� planszy
	i, j - zmienne do p�tli
	wspXstatku - wsp�rz�dna x statku
	wspXasteroid - wsp�rz�dna x asteroid
	wspYasteroid - wsp�rz�dna y asteroid
	klawisz - naci�ni�ty klawisz
*/

main() {
	
	//konfiguracja generatora liczb za pomoc� czasu
	srand(time(NULL));
  
  //wst�pna konfiguracja planszy
  while (i<y) {
    j=0;
    while (j<x) {
    	plansza[i][j]='p';
      j++;
    }
    i++;
  }
  
  /////////////////////////////
  
  //drukowanie ekranu startowego
  i=0;
    while (i<=x) {
    	cout << "--";
    	i++;
		}
	cout << "\n|                        |";
	cout << "\n|                        |";
	cout << "\n|                        |";
	cout << "\n|                        |";
	cout << "\n|                        |";
	cout << "\n|                        |";
	cout << "\n|                        |";
	cout << "\n|       PRESS PLAY       |";
	cout << "\n|        TO START        |";
	cout << "\n|                        |";
	cout << "\n|           db           |";
	cout << "\n|          xXXx          |";
	cout << "\n|           ^^           |";
	cout << "\n|                        |";
	cout << "\n|                        |";
	cout << "\n|                        |";
	cout << "\n|                        |";
	cout << "\n|                        |";
	cout << "\n|                        |";
	cout << "\n|                        |\n";
	i=0;
  while (i<=x) {
    cout << "--";
    i++;
	}
  
  //wstrzymanie a� do naci�ni�cia dowolnego klawisza
  klawisz=getch();
  
  /////////////////////////////
  
  //g��wna p�tla gry
  while (wspYasteroid<y) {
  	
  	//czyszczenie ekranu
  	system("cls");
    
    //je�li naci�ni�to klawisz
    if (kbhit()) {
    	klawisz=getch(); //we� warto�� klawisza
    	if (klawisz==224)klawisz+=getch(); //poniewa� warto�� klawisza mo�e by� wi�ksza ni� 224 getch podaje drug� liczb� kt�r� trzeba doda� do pierwszej
    
    	//ruch statku w prawo/lewo w zale�no�ci od wci�ni�tego klawisza (strza�ki i wasd)
			if (klawisz==100||klawisz==301) {
    		wspXstatku=wspXstatku+1;
  		} else if (klawisz==97||klawisz==299) {
  			wspXstatku--;
			}
		}
    
    //zwi�kszanie wyniku przy "z�apaniu" asteroidy oraz generowanie nowej
    if (wspYasteroid>=y-3&&wspXasteroid==wspXstatku) {
			wynik++;
			wspXasteroid=(rand()%(x-2)+1);
			wspYasteroid=0;
		}
		
		//blokada ruchu statku poza plansz�
    if (wspXstatku==x-1) { wspXstatku=x-2; }
    if (wspXstatku==0) { wspXstatku=1; }
    
    //przypisywanie odno�nik�w do r�nych cz�ci statku i asteroidy
    plansza[y-3][wspXstatku]='g', plansza[y-2][wspXstatku-1]='t', plansza[y-2][wspXstatku]='y', plansza[y-2][wspXstatku+1]='u', plansza[y-1][wspXstatku]='b';
    plansza[wspYasteroid][wspXasteroid]='a', plansza[wspYasteroid+1][wspXasteroid]='a';
    
    //drukowanie wyniku
    cout << "\t Score: " << wynik;
    
		//drukowanie planszy
    cout << "\n";
    i=0;
    while (i<=x) {
    	cout << "--";
    	i++;
		}
		
		cout << "\n";
    i=0;
    while (i<y) {
    	j=0;
    	cout << "|";
        while (j<x) {
        	switch (plansza[i][j]) {
        		case 'a':
							cout << "OO"; //cz�� asteroidy
							break;
            case 'p':
							cout << "  "; //puste pole
							break;
						case 'g':
							cout << "db"; //dzi�b statku
							break;
						case 't':
							cout << " x"; //lewe skrzyd�o statku
							break;
						case 'y':
							cout << "XX"; //kad�ub statku
							break;
						case 'u':
							cout << "x "; //prawe skrzyd�o statku
							break;
						case 'b':
							cout << "^^"; //silniki statku
							break;
        	}
        	j++;
        }
        cout << "|\n";
        i++;
    }
    i=0;
    while (i<=x) {
    	cout << "--";
    	i++;
		}
    
    //czyszczenie p�l po statku i asteroidzie
    plansza[y-3][wspXstatku]='p', plansza[y-2][wspXstatku-1]='p', plansza[y-2][wspXstatku]='p', plansza[y-2][wspXstatku+1]='p', plansza[y-1][wspXstatku]='p';
    plansza[wspYasteroid][wspXasteroid]='p';
    
    //ruch asteroidy w d�
    wspYasteroid++;
  }
  
  ///////////////////////////////////////
  
  system("cls");
  
  //drukowanie ekranu przegranej
  cout << "\t Score: " << wynik << endl;
  i=0;
    while (i<=x) {
    	cout << "--";
    	i++;
		}
	cout << "\n|                        |";
	cout << "\n|                        |";
	cout << "\n|                        |";
	cout << "\n|                        |";
	cout << "\n|                        |";
	cout << "\n|                        |";
	cout << "\n|                        |";
	cout << "\n|       GAME  OVER       |";
	cout << "\n|       TRY AGAIN?       |";
	cout << "\n|                        |";
	cout << "\n|           db           |";
	cout << "\n|          xXXx          |";
	cout << "\n|           ^^           |";
	cout << "\n|                        |";
	cout << "\n|                        |";
	cout << "\n|                        |";
	cout << "\n|                        |";
	cout << "\n|                        |";
	cout << "\n|                        |";
	cout << "\n|                        |\n";
	i=0;
    while (i<=x) {
    	cout << "--";
    	i++;
		}
}
