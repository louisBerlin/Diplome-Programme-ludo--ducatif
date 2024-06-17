#ifndef H_JEU
#define H_JEU


#include"Define.h"

#include"Sprite.h"
#include"Texte.h"
#include"Terrain.h"



    


class Jeu
{
  private:
          
    //objet
    Terrain *terrain ; 
    Sprite *sprites[5];
              
    Texte *txt; 
    FMUSIC_MODULE *musique;
    
	//variable
	
	 //timer
	 int T;
	 bool Timer;
	 
     //interaction joueur
	 int action;
	 
	 //mode automatique
	 int mode_automatique,ligne,init_saction,init_deplacement_saction,text_bulle,index_action;
	 char parole[15][256];
     char lien_action[10][256];
     
    
	 //autre
	 int couleur;
	
	 //gerée sprite
	 bool vcollision_sprite[2];
	 struct variable_sprite{
      int sance;      
      int d;
      int x;
      int y;
      int dx;
      int dy; 
      int xouy;
      int depar;
      int arrive;  
      int sur; 
      int action; 
     }sprite[4];
    
    
    


    
  public:
    // Le constructeur et destructeur
    Jeu();
    ~Jeu();
    
    void Saction(char[256]);
    //initialisation
    bool init(char[256]);
    bool rafrechire(char[256]);
    //affichage du jeu
    void affiche(int,int);
    //deplacement
    void deplacement(int,int,int,int,int);
    //teste collision entre sprite
    bool collision_sprite(int,int,int);
    //timer
    void timer();
    //fonction clavier
    bool clavier_DOWN(SDLKey event);
    bool clavier_UP(SDLKey event);   
    //renvois x et y		
    int get_x();
	int get_y();      
    //initialise x et y
    void fix_x(int);
    void fix_y(int);  
    void fix_sance(int);  
    
    
    




        	
};

#endif
