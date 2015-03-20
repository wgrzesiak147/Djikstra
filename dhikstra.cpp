#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <time.h>

using namespace std;


struct wierzcholek {
	int wierzcholek;
	int rozpatrzony;
	int poprzednik;
};


int main() {
cout<<"liczba wierzcholkow : ";
int liczba_wierzcholkow;
int x,y;
int stopien_wypelnienia;
float ile_krawedzi;	
cin>>liczba_wierzcholkow;
cout<<"stopien wypelnienia : ";
cin>>stopien_wypelnienia;
ile_krawedzi=(stopien_wypelnienia*0.01) * ((((liczba_wierzcholkow)*(liczba_wierzcholkow))-(liczba_wierzcholkow)));
int tablica[liczba_wierzcholkow][liczba_wierzcholkow];
x=ile_krawedzi;
y=liczba_wierzcholkow;
int tablica_krawedzi[x];
srand (time(NULL));
int wypelnienie_minimalne=((2/y)*100);

///////////////////////////////////////////////////////////////////////////////////////  warunek

	if(ile_krawedzi<(liczba_wierzcholkow-1)) // Sprawdzam poprawna ilosc krawedzi
		{
		cout<<" Za male wypelnienie!!!! "<<endl;
		system("PAUSE");
		}
		else

{

////////////////////////////////////////////////////////////////////////////////////// wypelnienie

for (int i=0;i<liczba_wierzcholkow;i++)
{
for (int j=0;j<liczba_wierzcholkow;j++)
{
tablica[i][j]=0;
}
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////Diagonala



for (int i=0;i<liczba_wierzcholkow;i++)  // w diagonali ustalam znak specjalny
	{
	tablica[i][i]=-1;

		
	}
	
///////////////////////////////////////////////////////////////////////////////////////Tablica krawedzi



for (int i=0;i<x;i++)
{
	tablica_krawedzi[i]=i+1;
}



//////////////////////////////////////////////////////////////////////////////////////losowanie i wype³nianie minimalne



		for (int i=0;i<y;i++)
		
		{
			
			int e= rand() %y+0;
			if(tablica[i][e] == 0 && tablica[e][i]==0)
			{
			
			tablica[i][e]=tablica_krawedzi[i];
			}
		else{
		
			i--;
		}
		
		}
		
		

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////dope³nianie

int wierzcholki=y;
int dopelnienie= x-y;


	for (int i=0;i<dopelnienie;i++)
		{

	
			int e= rand() %y+0;
			int a= rand() %y+0;
			if(tablica[a][e] == 0 )
			{
	
			
			tablica[a][e]=tablica_krawedzi[wierzcholki+i];
			
			}
		else{
		
			i--;
			}
		
		}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	COUT
 
 
 
for (int i=0;i<liczba_wierzcholkow;i++)
	{
	for (int j=0;j<liczba_wierzcholkow;j++)
      {
      	cout<<tablica[j][i]<<"    ";;
      }	
	cout <<endl;
	}

//////////////////////////////////////////////////////////////////////////////////////Djikstra




//////////////////////////////////////////////////
  
wierzcholek wierzcholek[y];


for (int i=0;i<y;i++)
{
	wierzcholek[i].wierzcholek=x+1;
	wierzcholek[i].rozpatrzony=0;
	
}
wierzcholek[0].wierzcholek=0;
wierzcholek[0].rozpatrzony=1;
wierzcholek[0].poprzednik=0;

int wiersz=0;



////////////////////


for (int i=0;i<y;i++)
{
	for (int u=0;u<y;u++)
	{	 
	cout<<" ";
		if (wierzcholek[u].rozpatrzony==0)
		{
		
			if (tablica[wiersz][u] != 0 && tablica [wiersz][u] != -1 && tablica[wiersz][u]+wierzcholek[wiersz].wierzcholek<wierzcholek[u].wierzcholek)
			{
		
					wierzcholek[u].wierzcholek=tablica[wiersz][u]+wierzcholek[wiersz].wierzcholek;
					wierzcholek[u].poprzednik=wiersz;
			}
			
		}
	} 
/// znajduje minimum
int min=x+1;
int indeks;
	for (int a=0;a<y;a++)
		{
		if (wierzcholek[a].wierzcholek<min && wierzcholek[a].rozpatrzony==0)
			{
			min=wierzcholek[a].wierzcholek;
			indeks=a;
			}
		}
		
wierzcholek[indeks].rozpatrzony=1;
wiersz =indeks;		
		
}







//////////////////////////////////COUT






cout<<" waga przejscia : "<<endl;
	for (int b=0;b<y;b++)
	{
	
	cout<<wierzcholek[b].wierzcholek<<" ";
	}
	cout<<endl;
	
	
cout<<" przez : "<<endl;
	for (int b=0;b<y;b++)
	{
	
	cout<<wierzcholek[b].poprzednik+1<<" ";
	}
	cout<<endl;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
main();
	return 0;
	system("PAUSE");
}
}
