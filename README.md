# BAC-GAME
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include <conio.h>
#include<cstring>
#include<map>
#include<vector>
#include <algorithm>
using namespace std;
class Game
{ private :
    int di;//niveau de difficultée
   vector<string> name;// tableau dynamique de nom
   vector<int> score;//tableau dynamique de score
   multimap<int,string> Total; // une multimap formée par de clé int et de valeur string
    
    int numplayer;//nombre de joueurs
    string theme ;//nom théme
    char L;
  public :
    void InsertMap() //sert a donner le score de chaque joueurs
    {
      for (int i=0 ; i<numplayer ; i++)
      {
        Total.insert(make_pair(score[i],name[i]));
      
      }
      for (int j=0 ;j<numplayer;j++)
      {
        cout<<" PLAYER  "<<name[j]<<" YOUR SCORE IS  : "<<score[j]<<endl;

      }
    }
   
    void winner() //donne le "WINNER"
    {
      multimap<int,string>::iterator it; 
     
       it= Total.end();
     
                 vector<int>::iterator pos ;
                 pos=max_element(score.begin(),score.end());// pointeur sur le meilleur score
                 int n=*pos;//la valeur du meilleur score
                 cout<<"THE BEST SCORE IS  :"<< n <<endl ;

                 int nb=count(score.begin(), score.end(),n) ;// compter le nombre de joueurs qui ont le meme score et qui est équivalent au score maxi
                 if (nb==numplayer)
                   {
                    cout<<"WE HAVE NO WINNER HERE !! THANK YOU FOR PLAYING !! YOU CAN PLAY AGAIN !! "<<endl ; //s'il y a plusieurs personnes qui ont le meme score maxi => pas de winner
                   }
                  else if ((numplayer!=nb) &&(nb<=2))
                   { 
                    for (int i=0 ; i<numplayer ; i++)
                    { if ( (score[i]==n ))
                     {
      
                      
                      cout<<"THE WINNER IS =====>    "<<name[i]<<"  <====="<<endl;
                      cout<<"!!!!!!!!!!CONGRATULATIONS !!!!!!!!!!!"<<endl;

    
                      
                      }
                    }
                   } 
                  



    }
    
     
     
     

    
    void addscore(int i,int P=0)
    { 
      score[i]=score[i]+P;

    }
    char get_L() //retourne une lettre aléatoire (a utiliser dans le code)
    {
      const char alphabet[] = "BACDEFGHIJKLMNOPQRSTUVWXYZ";
      size_t indice;
      srand(time(NULL));
      indice = rand() % (25 + 1);
      L = alphabet[indice];
      return L ;
    }
    
    Game( int num , string nn ,int d) // constructeur initialiser par number of players ,nom du theme choisi et le niveau de difficultée
    {
      
      di=d;
      theme = nn;
      numplayer=num;
      
    
      string nor;
      for(int i=0 ; i<num ; i++)
      {
        cout<<"Give each  player a name "<<endl;
        cin>>nor;
        name.push_back(nor);
        score.push_back(0);
        
      }
    }
        ~Game();
        int verif(string , string , char); // methode verif verifie si un mot est correct et correspondant au champs choisi
        string get_theme() const//theme
        {
          return theme ;
        }
       int getnumplayer() const // numbr of players needed
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
    if (mot[0]==c)
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
void niveaudiff( double& b ,int c)
{switch(c) 
 {case 1 : b=5 ;
   break;
  case 2 : b=7;
   break;
  case 3 : b=9;
  break;
  default : b=10;
  



 }
}
int main()
{ string th;
  int n;
  int dif;
  cout<<endl;
  cout<<"HELLO DEAR PLAYERS WE ARE NOW TAKING YOU TO A NEW BRAIN CHALLENG "<<endl;
  cout<<endl;
  cout<<"---- Fill This Questions To Begin ----"<<endl;
  cout<<endl;
  cout<<"chose the numbre of players"<<endl;
  cin>>n;
  cout<<"chose your theme : pays or sport or cinema" <<endl;
  cin>>th;
  cout<<"chose your difficulty level Hard : 1 (maxtime 5 for each answer)  or medium : 2 (maxtime 7 for each answer) or easy : 3 (maxtime 9 for each answer) "<<endl;
  cin>>dif;
  cout<<"---------------------------------------------------------------------------------------------------------------" <<endl;
  Game P(n,th,dif); // le jeu commance 
  cout<< "    ---------------------     "<<endl;
  cout<<"     WELCOME TO THE BAC GAME    "<<endl;
  cout<<"     ---------------------  "<<endl;
  
  double m=10;
  int numplayer=P.getnumplayer();
  string column;
  double duration=0;
  double& maxtime=m;
  
  P.get_theme();
  string mot;
  string word;
  string kelma;
  cout<<"GAME RULES: "<<endl;

  cout<<"Dear player those are the Rules  F.E.A.I "<<endl;;

  cout<<"The first Lettre in the  entered words is Always Uppercase"<<endl;

  cout<<"Every right answer equals +2pts & each wrong equals 0pts"<<endl;
   
  cout<<"LET'S BEGIN"<<endl;
  char  L=P.get_L(); // 1er lettre aléatoire
  cout<<"------------------"<<endl;
  cout<<"THE first lettre is  : "<<L<<endl;
  cout<<"------------------"<<endl;
  cout<<"LET'S GO !!"<<endl;
  cout<<"___________________"<<endl;
  if (th=="pays")
  { 
    cout<<"chose the column you want to write in : C1: for pays_afrique | C2: for pays_amerique | C3 :for pays_asie | C4 for pays_europe | C5 for pays_oceanie"<<endl;
    for (int i=0 ; i<5 ; i++)
    {   cout<<"-----------------"<<endl;
         cout<<"what column you want to write in next ? "<<endl;
         cin>>column;
         if (column=="C1")
         { cout<<"---pays afrique---"<<endl;
           std::clock_t start; // timer gestion de temps
           start = std::clock();
           double duration;
           niveaudiff(maxtime,dif);
             
           for(int j=0; j<numplayer ; j++) 
           { duration=0;
             cout<<"Give a word"<<endl;
          
             if (duration<maxtime)
               {  
                 cin>>kelma;
                 duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC; // calcul la durée que le joueur a pris pour écrire ca réponse
                 double c=maxtime-duration;
                 cout << "temps restant: "<<c<<endl ; //temp qui le reste par rapport au durée de difficulté qu'il a choisi
                 if (c<0) //a dépassé le temps
                 {
                   cout<<" time out !!!!!!! your answer won't be accepted ,sorry  !!!!! "<<endl ; //le mot entrée est pris comme faux
                   P.addscore(j);
                   duration=0;
                 }
                 else
                 {
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
            }
         }
         if (column=="C2")
         { cout<<"---pays_amerique---"<<endl;
           std::clock_t start;
           start = std::clock();
           double duration;
           niveaudiff(maxtime,dif);
             
           for(int j=0; j<numplayer ; j++) 
           { duration=0;
             cout<<"Give a word"<<endl;
          
             if ((duration<maxtime)||(j!=numplayer))
               { 
                 cin>>kelma;
                 duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
                 double c=maxtime-duration;
                 cout << "temps restant: "<<c<<endl ;
                 if (c<0)
                 {
                   cout<<" time out !!!!!!! your answer won't be accepted ,sorry  !!!!! "<<endl ;
                   P.addscore(j);
                   duration=0;
                 }
                 else
                 {
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
            }
         }
         if (column=="C3")
         { cout<<"---pays-asie---"<<endl;
           std::clock_t start;
           start = std::clock();
           double duration;
           niveaudiff(maxtime,dif);
             
           for(int j=0; j<numplayer ; j++) 
           {
             cout<<"Give a word"<<endl;
          
             if (duration<maxtime)
               {  duration=0;
                 cin>>kelma;
                 duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
                 double c=maxtime-duration;
                 cout << "temps restant: "<<c<<endl ;
                 if (c<0)
                 {
                   cout<<" time out !!!!!!! your answer won't be accepted ,sorry  !!!!! "<<endl ;
                   P.addscore(j);
                 }
                 else
                 {
                   if ((P.verif(kelma,"Pays_asie.txt",P.get_L())==10))
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
         if (column=="C4")
         { cout<<"---pays europe--"<<endl;
           std::clock_t start;
           start = std::clock();
           double duration;
           niveaudiff(maxtime,dif);
             
           for(int j=0; j<numplayer ; j++) 
           {duration=0;
             cout<<"Give a word"<<endl;
          
             if (duration<maxtime)
               {  
                 cin>>kelma;
                 duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
                 double c=maxtime-duration;
                 cout << "temps restant: "<<c<<endl ;
                 if (c<0)
                 {
                   cout<<" time out !!!!!!! your answer won't be accepted ,sorry  !!!!! "<<endl ;
                   P.addscore(j);
                 }
                 else
                 {
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
            }
         }
         if (column=="C5")
         { cout<<"---pays oceanie---"<<endl;
           std::clock_t start;
           start = std::clock();
           double duration;
           niveaudiff(maxtime,dif);
             
           for(int j=0; j<numplayer ; j++) 
           { duration=0;
             cout<<"Give a word"<<endl;
          
             if (duration<maxtime)
               {  
                 cin>>kelma;
                 duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
                 double c=maxtime-duration;
                 cout << "temps restant: "<<c<<endl ;
                 if (c<0)
                 {
                   cout<<" time out !!!!!!! your answer won't be accepted ,sorry  !!!!! "<<endl ;
                   P.addscore(j);
                 }
                 else
                 {
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
  }
 






 }
  if (th=="cinema")
   {  
       cout<<"chose the column you want to write in :  C1: for Movies| C2: for actors |C3 :for actress |C4 for Prizes"<<endl;
       cout<<"---------------"<<endl;
       for (int i=0 ; i<4 ; i++)
       { 
         cout<<"what column you want to write in ?"<<endl;
         cin>>column;
         if (column=="C1")
         { cout<<"---MOVIES---"<<endl;
           std::clock_t start;
           start = std::clock();
           double duration;
           niveaudiff(maxtime,dif);
             
           for(int j=0; j<numplayer ; j++) 
           { duration=0;
             cout<<"Give a word"<<endl;
          
             if (duration<maxtime)
               {  
                 cin>>kelma;
                 duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
                 double c=maxtime-duration;
                 cout << "temps restant: "<<c<<endl ;
                 if (c<0)
                 {
                   cout<<" time out !!!!!!! your answer won't be accepted ,sorry  !!!!! "<<endl ;
                   P.addscore(j);
                 }
                 else
                 {
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
            }
         }
         if (column=="C2")
         { cout<<"---ACTORS---"<<endl;
           
           std::clock_t start;
           start = std::clock();
           double duration;
           niveaudiff(maxtime,dif);
           for(int j=0;j<numplayer;j++)
           { duration=0;
             cout<<"Give a word"<<endl;
             if (duration<maxtime)
              {
                 cin>>kelma;
                 duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
                 double c=maxtime-duration;
                 cout << "temps restant: "<<c<<endl ;
                 if (c<0)
                  {
                   cout<<" time out !!!!!!! your answer won't be accepted ,sorry  !!!!! "<<endl ;
                   P.addscore(j);
                  }
                  else
                  {
            
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
             }
          }
          if (column=="C3")
         {cout<<"---ACTRESS---"<<endl;
                     
           std::clock_t start;
           start = std::clock();
           double duration;
           niveaudiff(maxtime,dif);
           for(int j=0;j<numplayer;j++)
            {duration=0;
              cout<<"Give a word"<<endl;

                 if (duration<maxtime)
                 {
                    cin>>kelma;
                   duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
                    double c=maxtime-duration;
                    cout << "temps restant: "<<c<<endl ;
                   if (c<0)
                   {
                    cout<<" time out !!!!!!! your answer won't be accepted ,sorry  !!!!! "<<endl ;
                    P.addscore(j);
                    }
                   else
                   {
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
             }
         }
          
         if (column=="C4")
           { 
              cout<<"---Prizes---"<<endl;
              std::clock_t start;
              start = std::clock();
              double duration;
              niveaudiff(maxtime,dif);
             for(int j=0;j<numplayer;j++)
             { duration=0;
                cout<<"Give a word"<<endl;
                if (duration<maxtime)
                 {
                    cin>>kelma;
                   duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
                    double c=maxtime-duration;
                    cout << "temps restant: "<<c<<endl ;
                   if (c<0)
                   {
                    cout<<" time out !!!!!!! your answer won't be accepted ,sorry  !!!!! "<<endl ;
                    P.addscore(j);
                    }
                  
                    else
                   {
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
          }
        } 
   }
  

 if (th=="sport")
     {  cout <<"chose the column you want to write in  C1: for nom sport| C5: for nom machine du sport | C2 :for nom femmes sportives quebecoises |C4 for nom spotifs tunisiens | C3 femme sportives francaises:"<<endl;
       for (int i=0 ; i<5 ; i++)
       { cout<<"-----------------"<<endl;
         cout<<"what column you want to write in ? "<<endl;

         cin>>column;
         if (column=="C1")
           { 
               cout<<"---nom sport---"<<endl;
             std::clock_t start;
             start = std::clock();
             double duration;
             niveaudiff(maxtime,dif);
             
             for(int j=0; j<numplayer ; j++) 
             { duration=0;
               cout<<"Give a word"<<endl;
          
               if (duration<maxtime)
               {  
                 cin>>kelma;
                 duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
                 double c=maxtime-duration;
                 cout << "temps restant: "<<c<<endl ;
                 if (c<0)
                 {
                   cout<<" time out !!!!!!! your answer won't be accepted ,sorry  !!!!! "<<endl ;
                   P.addscore(j);
                 }
                 else
                 {
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
             }
           }
           if (column=="C2")
           { cout<<"---nom femme sportives québéquoises---"<<endl;
             std::clock_t start;
             start = std::clock();
             double duration;
              niveaudiff(maxtime,dif);
             
             for(int j=0; j<numplayer ; j++) 
             { duration=0;
               cout<<"Give a word"<<endl;
          
               if (duration<maxtime)
               {  
                 cin>>kelma;
                 duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
                 double c=maxtime-duration;
                 cout << "temps restant: "<<c<<endl ;
                 if (c<0)
                 {
                   cout<<" time out !!!!!!! your answer won't be accepted ,sorry  !!!!! "<<endl ;
                   P.addscore(j);
                 }
                 else
                 {
                   if ((P.verif(kelma,"qbc.txt",P.get_L())==10))
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
           if (column=="C3")
           { cout<<"---nom femmes sportives françaises---"<<endl;
           std::clock_t start;
           start = std::clock();
           double duration;
           niveaudiff(maxtime,dif);
             
           for(int j=0; j<numplayer ; j++) 
           {  duration=0;
             cout<<"Give a word"<<endl;
          
             if (duration<maxtime)
               {  
                 cin>>kelma;
                 duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
                 double c=maxtime-duration;
                 cout << "temps restant: "<<c<<endl ;
                 if (c<0)
                 {
                   cout<<" time out !!!!!!! your answer won't be accepted ,sorry  !!!!! "<<endl ;
                   P.addscore(j);
                 }
                 else
                 {
                   if ((P.verif(kelma,"franc.txt",P.get_L())==10))
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
           if (column=="C4")
           { cout<<"---nom spotifs tunisiens---"<<endl;
           std::clock_t start;
           start = std::clock();
           double duration;
           niveaudiff(maxtime,dif);
             
           for(int j=0; j<numplayer ; j++) 
           { duration=0;
             cout<<"Give a word"<<endl;
          
             if (duration<maxtime)
               {  
                 cin>>kelma;
                 duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
                 double c=maxtime-duration;
                 cout << "temps restant: "<<c<<endl ;
                 if (c<0)
                 {
                   cout<<" time out !!!!!!! your answer won't be accepted ,sorry  !!!!! "<<endl ;
                   P.addscore(j);
                 }
                 else
                 {
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
            }
           }
           if (column=="C5")
           { cout<<"---machine sport---"<<endl;
             std::clock_t start;
             start = std::clock();
             double duration;
             niveaudiff(maxtime,dif);
             
              for(int j=0; j<numplayer ; j++) 
             {  duration=0;
               cout<<"Give a word"<<endl;
          
               if (duration<maxtime)
               {  
                 cin>>kelma;
                 duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
                 double c=maxtime-duration;
                 cout << "temps restant: "<<c<<endl ;
                 if (c<0)
                 {
                   cout<<" time out !!!!!!! your answer won't be accepted ,sorry  !!!!! "<<endl ;
                   P.addscore(j);
                 }
                 else
                 {
                   if ((P.verif(kelma,"machine_sport.txt",P.get_L())==10))
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
     }
  
     
    cout<<"WE WILL REVEAL THE SCORES !! :"<<endl;
     P.InsertMap();
     P.winner();
     cout<<endl;
     cout<<"-------------------------------"<<endl;
     cout<<"THANK YOU FOR PLAYING OUR GAME "<<endl;
     cout<<"-------------------------------"<<endl;
     cout<<"! INFO : "<<endl;
     cout<<"The objective of the BAC GAME is to rely on the creativity of the players to solve the problems without imposing any operating mode"<<endl;
     cout<<endl;
     cout<<"SEE YOU AGAIN !!!!!"<<endl;
     cout<<" \n  "<<endl;
  return 0;

     
}
