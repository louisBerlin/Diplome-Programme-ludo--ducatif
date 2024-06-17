#ifndef H_TEXTE
#define H_TEXTE


#include <SDL/SDL.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_opengl.h>



class Texte
{

	private:       
        
        //x et y de la texture        
        int x,y;
        int i;
        int l;
        int n;
        int longeur_text;
        int longeur_lettre;
        int vlongeur_lettre;
        int depart;
        //variable texture 
        SDL_Surface *Image_Texte;                 
        GLuint texture_name_Texte;        
        GLfloat texcoord_Texte[4];
        
        SDL_Surface *Image_Bois;
        GLuint texture_name_Bois;        
        GLfloat texcoord_Bois[4];
		
	public:

		//Constructeur et Destructeur
		Texte();
		~Texte();
		//Initialisation de la classe
		bool init();		
		//Afficher du texte
		void ecrire(char[256],int,int);
        
        void bulle(int,int);
        void bulle_bas(int,int,char[100],char[100]);       
        //renvois x et y		
        int getx();
		int gety();        
        	
};
#endif
