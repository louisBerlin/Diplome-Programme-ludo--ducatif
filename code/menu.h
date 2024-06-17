#ifndef H_MENU
#define H_MENU

#include "Define.h"


#include"Sprite.h"
#include"Texte.h"


class Menu
{
	private:
    	//objet
   	    Sprite *icone;
    	Sprite *image;

    	Sprite *image3;
		Texte *txt;
        FSOUND_STREAM *musique_intro;
	    FSOUND_SAMPLE *son1;
	    FSOUND_SAMPLE *son2;
		//variable
		int test;
		int choix;
		int choix_max;
		int menu;
		int x;
        int y;
        int dx;
        int dy;	
        int xf;	
        int couleur;
        int fin;
	public:
    	//Constructeur
        Menu();
	    //Destructeur
	    ~Menu();
	    //Fonction d'initialisation
	    bool init();
	    //Gestion du clavier
	    bool clavier_DOWN(SDLKey event);
        bool clavier_UP(SDLKey event);   		
	    //Fonction d'affichage
	    void affiche(int,int);
	    //Timer
	    void timer();
};

#endif
