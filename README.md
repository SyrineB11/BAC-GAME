# BAC-GAME
it's a brain game 
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
class Player
{
    private :
       char **nom ;
       int* score;
       int numplayer;
       string theme ;
        char L;

       ;
    public :
    void addscore(int i,int P=0)
    {
        *(score+i)+=P;
       
    }
    Player( int num , string nn )
    {const char alphabet[] = "BACDEFGHIJKLMNOPQRSTUVWXYZ";
    
       size_t indice;
       srand(time(NULL));
       indice = rand() % (25 + 1);
       L = alphabet[indice];

    char n[20] ;
    theme = nn;
    int* score=new int[numplayer];
    numplayer=num;
    char  **nom;
    nom= new char*[numplayer];
    for(int i=0 ; i<numplayer ; i++)
    {
        cout<<"Give each  player a name "<<endl;
        cin>>n;
        nom[i]=new char[20];
        nom[i]=n;
    }
 
}
        ~Player();
        void  affiche();
        bool verif (string,string,char);
        string get_theme() const{
           return theme ;
       }
       int getnumplayer() const
       { return numplayer;}
       char getL() const
       {return L;}
    


};
Player::~Player()
{ 
    delete[] nom ;
    delete[] score;
  
}
bool Player::verif(string a,string b,char c)
{   
    string n;
      int ok=0;
      int k=0;
    if (c!=L)
    {k=100;}
    else{
       ifstream entree(b , ios::in);
        if(!entree)
          {
             cout<<"ouverture impossible"<<endl;
           }
        else
           {
             while (entree >> n)
               if (n==a)
                {
                    k=1;
                }
        entree.close();
           }}
    if (k==1)
    {
        return 10;}
    else 
    {
        return 100;
    }
}

main()

{  string th;
  cout<<"     WELCOME TO THE BAC GAME"<<endl;
  cout<<"   ***** Choose your Theme*****"<<endl;
  cout<<"    sport or geography or cinema"<<endl;
  cin>>th;
  if ( (th=="cinema" ) || (th=="sport") || (th=="paye"))
  {Player P(2,th);
  
   
 //get num player//getcinema

  int k=0;
  int N;
  int numplayer=P.getnumplayer();
  string attricinema;
  string attsport;
  string attripays;
  P.get_theme();
  string kelma;
  string word;

 cout<<"GAME RULES: "<<endl;
  cout<<"Dear player those are the Rules  F.E.A.I "<<endl;;
  cout<<"  *The first Lettre in the  entered words is Always Uppercase"<<endl;
  cout<<"  *Every right answer equals +2pts & each wrong equals -2pts"<<endl;
  cout<<"  *At the end of the GAME there is one winner"<<endl;
  cout<<"  *In Case the players Got equal High scores those players CAN !choose! to play other tourneys to select  one winner "<<endl;
 cout<<"LET'S BEGIN"<<endl;

 for (int i=0;i<numplayer;i++)
 {if (P.get_theme()=="cinema")
     {cout<<"****the first lettre is****    :"<<P.getL()<<endl;
      cout<<"u choosed the theme cinema"<<endl;
      cout<<"the theme cinema contains 4 colmn";
        do
          { cout<<"choose the colomn you want to write in  C1: for Movies// C2: for actors // C3 :for actress //C4 for Prizes";
            cin>> attricinema;
            if (attricinema=="C1")
              {
                  k++;
                  string* Moviesword = new string[50];
                    for(int j=0;j<numplayer;j++)
                        {cin>>kelma;
                            *(Moviesword+j)=kelma;}
                                if ((P.verif(*(Moviesword+i),"Movies.txt",P.getL())==10)) //Moviesword is an array of strings so to give'im access to the first charc we need [i][0]
                                    {P.addscore(i,2); }//si juste la condition le score augmente de 2pts sinon diminue de 2pts
                                  else
                                   P.addscore(i);
                    
                     }
            else if (attricinema=="C2")
             {
                k++;
                  string* Moviesword = new string[50];
                    for(int j=0;j<numplayer;j++)
                        {cin>>kelma;
                            *(Moviesword+j)=kelma;}
                                if ((P.verif(*(Moviesword+i),"Actors.txt",P.getL())==10)) //Moviesword is an array of strings so to give'im access to the first charc we need [i][0]
                                    {P.addscore(i,2); }//si juste la condition le score augmente de 2pts sinon diminue de 2pts
                                  else
                                   P.addscore(i);


             }
             else if (attricinema=="C3")
             {
                k++;
                  string* Moviesword = new string[50];
                    for(int j=0;j<numplayer;j++)
                        {cin>>kelma;
                            *(Moviesword+j)=kelma;}
                                if ((P.verif(*(Moviesword+i),"Actriss.txt",P.getL())==10)) //Moviesword is an array of strings so to give'im access to the first charc we need [i][0]
                                    {P.addscore(i,2); }//si juste la condition le score augmente de 2pts sinon diminue de 2pts
                                  else
                                   P.addscore(i);


             }
             else if (attricinema=="C4")
             {
                k++;
                  string* Moviesword = new string[50];
                    for(int j=0;j<numplayer;j++)
                        {cin>>kelma;
                            *(Moviesword+j)=kelma;}
                                if ((P.verif(*(Moviesword+i),"Prizes.txt",P.getL())==10)) //Moviesword is an array of strings so to give'im access to the first charc we need [i][0]
                                    {P.addscore(i,2); }//si juste la condition le score augmente de 2pts sinon diminue de 2pts
                                  else
                                   P.addscore(i);


           
          }
          
        }while (k=4); 
      }

    else if (P.get_theme()=="pays")
     {cout<<"**the first lettre is**    :"<<P.getL()<<endl;
      cout<<"u choosed the theme pays"<<endl;
      cout<<"the theme cinema contains 5 colmn";
        do
          { cout<<"choose the colomn you want to write in  C1: for pays_afrique// C2: for pays_amerique // C3 :for pays_asie //C4 for pays_europe // C5 for pays_oceanie";
            cin>> attripays;
            if (attripays=="C1")
              {
                  k++;
                  string* pays_afrique= new string[50];
                    for(int j=0;j<numplayer;j++)
                        {cin>>kelma;
                            *(pays_afrique+j)=kelma;}
                                if ((P.verif(*(pays_afrique+i),"pays_afrique.txt",P.getL())==10)) //pays_afrique is an array of strings so to give'im access to the first charc we need [i][0]
                                    {P.addscore(i,2); }//si juste la condition le score augmente de 2pts sinon diminue de 2pts
                                  else
                                   P.addscore(i);
                    
                     }
            if (attripays=="C2")
             {
                  k++;
                  string* pays_amerique= new string[50];
                    for(int j=0;j<numplayer;j++)
                        {cin>>kelma;
                            *(pays_amerique+j)=kelma;}
                                if ((P.verif(*(pays_amerique+i),"pays_amerique.txt",P.getL())==10)) //pays_afrique is an array of strings so to give'im access to the first charc we need [i][0]
                                    {P.addscore(i,2); }//si juste la condition le score augmente de 2pts sinon diminue de 2pts
                                  else
                                   P.addscore(i);
             }
            if(attripays=="C3")
            {
                 
                  k++;
                  string* pays_asie= new string[50];
                    for(int j=0;j<numplayer;j++)
                        {cin>>kelma;
                            *(pays_asie+j)=kelma;}
                                if ((P.verif(*(pays_asie+i),"pays_asie.txt",P.getL())==10)) //pays_afrique is an array of strings so to give'im access to the first charc we need [i][0]
                                    {P.addscore(i,2); }//si juste la condition le score augmente de 2pts sinon diminue de 2pts
                                  else
                                   P.addscore(i);
            }
            if (attripays=="C4")
             {
                  k++;
                  string* pays_europe= new string[50];
                    for(int j=0;j<numplayer;j++)
                        {cin>>kelma;
                            *(pays_europe+j)=kelma;}
                                if ((P.verif(*(pays_europe+i),"pays_europe.txt",P.getL())==10)) //pays_afrique is an array of strings so to give'im access to the first charc we need [i][0]
                                    {P.addscore(i,2); }//si juste la condition le score augmente de 2pts sinon diminue de 2pts
                                  else
                                   P.addscore(i);
             }
             if(attripays=="C5")
              {
                  k++;
                  string* pays_oceanie= new string[50];
                    for(int j=0;j<numplayer;j++)
                        {cin>>kelma;
                            *(pays_oceanie+j)=kelma;}
                                if ((P.verif(*(pays_oceanie+i),"pays_oceanie.txt",P.getL())==10)) //pays_afrique is an array of strings so to give'im access to the first charc we need [i][0]
                                    {P.addscore(i,2); }//si juste la condition le score augmente de 2pts sinon diminue de 2pts
                                  else
                                   P.addscore(i);
                 }      
           }while(k=5); 

 
    
     } 
   else
    {P.get_theme()=="sport";
     {cout<<"**the first lettre is**    :"<<P.getL()<<endl;
      cout<<"u choosed the theme sport"<<endl;
      cout<<"the theme sport contains 5 columns";
        do
          { cout <<"choose the column you want to write in  C1: for nom sport// C2: for nom machine du sport // C3 :for nom femmes sportives quebecoises //C4 for nom spotifs tunisiens // c5 femme sportives francaises:";
            cin>> attsport;
            if (attsport=="C1")
              {
                  k++;
                  string* nomsport = new string[50];
                    for(int j=0;j<numplayer;j++)
                        {cin>>kelma;
                            *(nomsport+j)=kelma;}
                                if ((P.verif(*(nomsport+i),"nom_sport.txt",P.getL())==10)) //nom sport is an array of strings so to give'im access to the first charc we need [i][0]
                                    {P.addscore(i,2); }//si juste la condition le score augmente de 2pts sinon diminue de 2pts
                                  else
                                   P.addscore(i);
                    
                     }
            else if (attsport=="c2")
             {
                k++;
                  string* nom_machine_du_sport = new string[50];
                    for(int j=0;j<numplayer;j++)
                        {cin>>kelma;
                            *(nom_machine_du_sport+j)=kelma;}
                                if ((P.verif(*(nom_machine_du_sport+i),"machine_sport.txt",P.getL())==10)) //nom machine du sport is an array of strings so to give'im access to the first charc we need [i][0]
                                    {P.addscore(i,2); }//si juste la condition le score augmente de 2pts sinon diminue de 2pts
                                  else
                                   P.addscore(i); 
             }
            else if(attsport=="c3")
            {
                k++;
                  string* nom_femmes_sportives_quebecoises = new string[50];
                    for(int j=0;j<numplayer;j++)
                        {cin>>kelma;
                            *(nom_femmes_sportives_quebecoises+j)=kelma;}
                                if ((P.verif(*(nom_femmes_sportives_quebecoises+i),"nom_femmes_sportives_québecoises.txt",P.getL())==10)) //nom femmes sportives québecoises is an array of strings so to give'im access to the first charc we need [i][0]
                                    {P.addscore(i,2); }//si juste la condition le score augmente de 2pts sinon diminue de 2pts
                                  else
                                   P.addscore(i);
            }
            else if (attsport=="c4")
            {
                k++;
                  string* nom_spotifs_tunisiens = new string[50];
                    for(int j=0;j<numplayer;j++)
                        {cin>>kelma;
                            *(nom_spotifs_tunisiens+j)=kelma;}
                                if ((P.verif(*(nom_spotifs_tunisiens+i),"nom_spotifs_tunisiens.txt",P.getL())==10)) //nom spotifs tunisiens is an array of strings so to give'im access to the first charc we need [i][0]
                                    {P.addscore(i,2); }//si juste la condition le score augmente de 2pts sinon diminue de 2pts
                                  else
                                   P.addscore(i);
            }
            else if (attsport=="c5")
            {
                k++;
                  string* nom_femme_sportives_francaises = new string[50];
                    for(int j=0;j<numplayer;j++)
                        {cin>>kelma;
                            *(nom_femme_sportives_francaises+j)=kelma;}
                                if ((P.verif(*(nom_femme_sportives_francaises+i),"nom_femmes_sportives_françaises.txt",P.getL()==10))) //femme sportives françaises is an array of strings so to give'im access to the first charc we need [i][0]
                                    {P.addscore(i,2); }//si juste la condition le score augmente de 2pts sinon diminue de 2pts
                                  else
                                   P.addscore(i);
          
        }while (k=4); 
     }while (k=4); 
   }
 }
 
 } }
 else
    cout<<"the theme does not exist Re-Tape"<<endl;
 } 
