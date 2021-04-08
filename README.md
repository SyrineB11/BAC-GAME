# BAC-GAME
it's a brain game 
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;
class Game
{ private :
    int score[20];
    int numplayer;
    string theme ;
    char L;
  public :
    void afficher_tableau_score()
    {
      for (int i=0 ; i<numplayer ; i++)
      {
        cout<<"le score du joueur : "<<i<<"  est :  "<< score[i]<<endl;
      }
    }
    void addscore(int i,int P=0)
    { 
      score[i]=score[i]+P;

    }
    char get_L()
    {
      const char alphabet[] = "BACDEFGHIJKLMNOPQRSTUVWXYZ";
      size_t indice;
      srand(time(NULL));
      indice = rand() % (25 + 1);
      L = alphabet[indice]; 
      return L ;
    }
    Game( int num , string nn )
    {

      
      theme = nn;
      numplayer=num;
      
    
      string name;
      for(int i=0 ; i<num ; i++)
      {
        cout<<"Give each  player a name "<<endl;
        cin>>name;
        score[i]=0;
        
      }
    }
        ~Game();
        int verif(string , string , char);
        string get_theme() const
        {
          return theme ;
        }
       int getnumplayer() const
       { 
        return numplayer;
       }

};
Game::~Game()
{
    
  
}
int Game::verif(string mot ,string nom_f,char c)
{
    string n;
    int ok=0;
    int k=0;
    if (c!=L)
    {
      k=100;
    }
    else
    {
      ifstream entree(nom_f , ios::in);
      if(!entree)
      {
        cout<<"ouverture impossible"<<endl;
      }
      else
      {
        while (entree >> n)
        if (n==mot)
        {
          k=1;
        }
      entree.close();
      }
    }
    if (k==1)
    {
      return 10;}
    else
    {
      return 100;
    }

}
int main()
{ string th;
  int n;
  cout<<"chose the numbre of players"<<endl;
  cin>>n;
  cout<<"chose your theme : pays or sport or cinema" <<endl;
  cin>>th;
  Game P(n,th); 
  cout<<"     WELCOME TO THE BAC GAME"<<endl;
  
  
  int numplayer=P.getnumplayer();
  string column;
  
  P.get_theme();
  string mot;
  string word;
  string kelma;
  cout<<"GAME RULES: "<<endl;
  cout<<"Dear player those are the Rules  F.E.A.I "<<endl;;
  cout<<"The first Lettre in the  entered words is Always Uppercase"<<endl;
  cout<<"Every right answer equals +2pts & each wrong equals 0pts"<<endl;
  cout<<"LET'S BEGIN"<<endl;
  char  L=P.get_L();
  cout<<"THE first lettre is "<<L<<endl;
  if (th=="pays")
  { 
    cout<<"chose the column you want to write in  C1: for pays_afrique// C2: for pays_amerique // C3 :for pays_asie //C4 for pays_europe // C5 for pays_oceanie"<<endl;
    for (int i=0 ; i<5 ; i++)
    {
     cout<<"what column you want to write in"<<endl;
     cin>>column;
     if (column=="C1")
     {
      for(int j=0; j<numplayer ; j++) 
      {
        cout<<"Give a word"<<endl;
        cin>>kelma;
        if ((P.verif(kelma,"pays_asie.txt",P.get_L())==10))
        {
          P.addscore(j,2);
        }
        else 
        { 
          P.addscore(j);
        } 
      }
     }
     if (column=="C2")
     {
      for(int j=0;j<numplayer;j++)
      {
        cout<<"Give a word"<<endl;
        cin>>kelma;
        if ((P.verif(kelma,"pays_afrique.txt",P.get_L())==10)) 
        {
          P.addscore(j,2); 
        }
        else
        { 
          P.addscore(j);
        }
      }
     }
     if (column=="C3")
     {
      for(int j=0;j<numplayer;j++)
      {
        cout<<"Give a word"<<endl;
        cin>>kelma;
        if ((P.verif(kelma,"pays_amerique.txt",P.get_L())==10)) 
        {
          P.addscore(j,2); 
        }
        else
        {
          P.addscore(j);
        }
      }
     }
     if (column=="C4")
     {
      for(int j=0;j<numplayer;j++)
      {
        cout<<"Give a word"<<endl;
        cin>>kelma;
        if ((P.verif(kelma,"pays_europe.txt",P.get_L())==10)) 
        {
          P.addscore(j,2);
        }
        else
        {
          P.addscore(j);
        }
      }
     }
     if (column=="C5")
     {
      for(int j=0;j<numplayer;j++)
      {
        cout<<"Give a word"<<endl;
        cin>>kelma;
        if ((P.verif(kelma,"pays_oceanie.txt",P.get_L())==10)) 
        {
          P.addscore(j,2);
        }
        else
        {
          P.addscore(j);
        }
      }
     }
  }
 






 }
  if (th=="cinema")
   {  
       cout<<"chose the column you want to write in  C1: for Movies// C2: for actors // C3 :for actress //C4 for Prizes"<<endl;
       for (int i=0 ; i<4 ; i++)
       {
         cout<<"what column you want to write in"<<endl;
         cin>>column;
         if (column=="C1")
         {
         for(int j=0; j<numplayer ; j++) 
         {
          cout<<"Give a word"<<endl;
          cin>>kelma;
           if ((P.verif(kelma,"Movies.txt",P.get_L())==10))
           {
            P.addscore(j,2);
           }
            else 
            { 
             P.addscore(j);
             } 
         }
         }
         if (column=="C2")
         {
          for(int j=0;j<numplayer;j++)
          {
           cout<<"Give a word"<<endl;
           cin>>kelma;
           if ((P.verif(kelma,"Actors.txt",P.get_L())==10)) 
          {
          P.addscore(j,2); 
          }
          else
          { 
          P.addscore(j);
         }
         }
          }
         if (column=="C3")
         {
         for(int j=0;j<numplayer;j++)
         {
          cout<<"Give a word"<<endl;
         cin>>kelma;
         if ((P.verif(kelma,"Actress.txt",P.get_L())==10)) 
         {
          P.addscore(j,2); 
         }
         else
         {
          P.addscore(j);
         }
         }
          }
         if (column=="C4")
         {
         for(int j=0;j<numplayer;j++)
         {
         cout<<"Give a word"<<endl;
         cin>>kelma;
         if ((P.verif(kelma,"Prizes.txt",P.get_L())==10)) 
         {
          P.addscore(j,2);
         }
         else
         {
          P.addscore(j);
         }
          }
          }
     }
    if (th=="sport")
    {  cout <<"chose the column you want to write in  C1: for nom sport// C5: for nom machine du sport // C2 :for nom femmes sportives quebecoises //C4 for nom spotifs tunisiens // c1 femme sportives francaises:"<<endl;
      for (int i=0 ; i<5 ; i++)
       {
         cout<<"what column you want to write in"<<endl;
         cin>>column;
         if (column=="C1")
         {
          for(int j=0; j<numplayer ; j++) 
          {   
         cout<<"Give a word"<<endl;
         cin>>kelma;
         if ((P.verif(kelma,"nom_femmes_sportives_française.txt",P.get_L())==10))
         {
          P.addscore(j,2);
         }
         else 
         { 
          P.addscore(j);
         } 
          }
           }
         if (column=="C2")
          {
          for(int j=0;j<numplayer;j++)
         {
         cout<<"Give a word"<<endl;
         cin>>kelma;
         if ((P.verif(kelma,"nom_femmes_sportives_québécoises.txt",P.get_L())==10)) 
         {
          P.addscore(j,2); 
         }
         else
         { 
          P.addscore(j);
         }
          }
          }
         if (column=="C3")
         {
          for(int j=0;j<numplayer;j++)
         {
         cout<<"Give a word"<<endl;
         cin>>kelma;
         if ((P.verif(kelma,"nom_sport.txt",P.get_L())==10)) 
         {
          P.addscore(j,2); 
         }
         else
         {
          P.addscore(j);
         }
          }
          }
         if (column=="C4")
         {
         for(int j=0;j<numplayer;j++)
         {
         cout<<"Give a word"<<endl;
         cin>>kelma;
         if ((P.verif(kelma,"nom_sportifs_tunisiens.txt",P.get_L())==10)) 
         {
          P.addscore(j,2);
         }
         else
         {
          P.addscore(j);
         }
          }
          }
         if (column=="C5")
          {
         for(int j=0;j<numplayer;j++)
         {
         cout<<"Give a word"<<endl;
         cin>>kelma;
         if ((P.verif(kelma,"machine_sports.txt",P.get_L())==10)) 
         {
          P.addscore(j,2);
         }
         else
         {
          P.addscore(j);
         }
         }
          }   
       }
   }
 }
  cout<<"WE WILL REVEAL THE SCORES !! :"<<endl;
  P.afficher_tableau_score();
  return 0;

 }
