#ifndef H_ACTION
#define H_ACTION

#include "Define.h"


#include"Sprite.h"
#include"Texte.h"




class Action
{
	private:
    	//objet
        Sprite *image0;
        Sprite *image1;
        Sprite *image2;
        Texte *txt; 
	    //variable
	    int mode;
	    
	    	 bool Timer;
	    
        int index_text,x,y,T,d,sence,temps,action,ty;
        
        int repance,choix;
        int vlongueur_txt,vdeplacement[4];
        int depart,arrivee,depart2,arrivee2,xouy;
        
        char texte[30][256];
        //autre
        int couleur;
	public:
		//Constructeur
		Action();
		//Destructeur
		~Action();
		//Fonction d'initialisation
			public:
		bool init();
        
        void chargement(char[256]);			
		//Fonction d'affichage
		void affiche(int);
		//timer
        void timer();
        //fonction clavier
        bool clavier_DOWN(SDLKey event);
        bool clavier_UP(SDLKey event);   
};

#endif
