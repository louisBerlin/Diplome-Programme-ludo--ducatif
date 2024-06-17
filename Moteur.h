#ifndef H_MOTEUR
#define H_MOTEUR

#include "Define.h"
#include "Menu.h"
#include "Jeu.h"
#include "Action.h"

class Moteur
{

	private:       
        //------objet----
        Menu *menu;
        Jeu *jeu;
        Action *action;   
        FMUSIC_MODULE *musique;
        //variable
        char lien_chapitre[5][256];        
        char lien_map[10][256]; 
        char lien_action[256];
        
        int par[10][22];
        int chapitre;
        int map;  
        int x;
        int raf;
        int inisialise;
        //Sommes-nous dans le menu ?
        int dans_menu;
        bool est_fini;
        bool T;
        	
	public:
 
		//Constructeur et Destructeur
		Moteur();
		~Moteur();
		//Initialisation de la classe
		bool init();		
		
		void echangeFonctions(int);
		
		void rafrechiree(int);
		//Afficher le jeu
		void affiche();
		// Dessiner le menu
        void dessineJeu();
        // Dessiner le menu
        void dessineMenu();
        
        void dessineAction();
        
        void action_start(char[256]);
        void nouvelle_partie();
        //chapitre suivant
        void chapitre_suivant(int,int);
        //chargement
        void chargement();
        //sauvgarder
        void sauvgarder();
        //Est-ce que la partie est finie ?
        bool estFini();
         //Terminer la partie
        void fin();
        //fonction clavier
        bool clavier_DOWN(SDLKey event);
        bool clavier_UP(SDLKey event);  
        //fonction timer
        void timer ();    
        
        
        void m_chargement(char[256]);
        void m_play();
        void m_stop();
        void m_volume(int);          	
};
#endif
