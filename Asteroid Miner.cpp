/*
	"Asteroid Miner"
	Autor: Tymoteusz Legiêæ
	Na podstawie https://www.youtube.com/watch?v=rMKHLz3liuk i https://www.youtube.com/watch?v=8Z1VqLd6U34
*/

#include <iostream> //cout, cin
#include <conio.h> //getch
#include <cstdlib> //system
#include <time.h> //srand
//#include <graphics.h>
using namespace std;

//definicje zmiennych
int y=20, x=12, i=0, j=0, wspXstatku=5, wspXasteroid=(rand()%(x-2)+1), wspYasteroid, klawisz, wynik=0;
char plansza[20][12];

/*
	y - wysokoœæ planszy
	x - szerokoœæ planszy
	i, j - zmienne do pêtli
	wspXstatku - wspó³rzêdna x statku
	wspXasteroid - wspó³rzêdna x asteroid
	wspYasteroid - wspó³rzêdna y asteroid
	klawisz - naciœniêty klawisz
*/

main() {
	
	//konfiguracja generatora liczb za pomoc¹ czasu
	srand(time(NULL));
  
  //wstêpna konfiguracja planszy
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
  
  //wstrzymanie a¿ do naciœniêcia dowolnego klawisza
  klawisz=getch();
  
  /////////////////////////////
  
  //g³ówna pêtla gry
  while (wspYasteroid<y) {
  	
  	//czyszczenie ekranu
  	system("cls");
    
    //jeœli naciœniêto klawisz
    if (kbhit()) {
    	klawisz=getch(); //weŸ wartoœæ klawisza
    	if (klawisz==224)klawisz+=getch(); //poniewa¿ wartoœæ klawisza mo¿e byæ wiêksza ni¿ 224 getch podaje drug¹ liczbê któr¹ trzeba dodaæ do pierwszej
    
    	//ruch statku w prawo/lewo w zale¿noœci od wciœniêtego klawisza (strza³ki i wasd)
			if (klawisz==100||klawisz==301) {
    		wspXstatku=wspXstatku+1;
  		} else if (klawisz==97||klawisz==299) {
  			wspXstatku--;
			}
		}
    
    //zwiêkszanie wyniku przy "z³apaniu" asteroidy oraz generowanie nowej
    if (wspYasteroid>=y-3&&wspXasteroid==wspXstatku) {
			wynik++;
			wspXasteroid=(rand()%(x-2)+1);
			wspYasteroid=0;
		}
		
		//blokada ruchu statku poza planszê
    if (wspXstatku==x-1) { wspXstatku=x-2; }
    if (wspXstatku==0) { wspXstatku=1; }
    
    //przypisywanie odnoœników do ró¿nych czêœci statku i asteroidy
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
							cout << "OO"; //czêœæ asteroidy
							break;
            case 'p':
							cout << "  "; //puste pole
							break;
						case 'g':
							cout << "db"; //dziób statku
							break;
						case 't':
							cout << " x"; //lewe skrzyd³o statku
							break;
						case 'y':
							cout << "XX"; //kad³ub statku
							break;
						case 'u':
							cout << "x "; //prawe skrzyd³o statku
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
    
    //czyszczenie pól po statku i asteroidzie
    plansza[y-3][wspXstatku]='p', plansza[y-2][wspXstatku-1]='p', plansza[y-2][wspXstatku]='p', plansza[y-2][wspXstatku+1]='p', plansza[y-1][wspXstatku]='p';
    plansza[wspYasteroid][wspXasteroid]='p';
    
    //ruch asteroidy w dó³
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
