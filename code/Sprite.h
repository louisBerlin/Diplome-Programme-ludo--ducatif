#ifndef H_SPRITE
#define H_SPRITE


#include <SDL/SDL.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_opengl.h>



class Sprite
{

	private:       
        
        //x et y de la texture        
        int x,y;
        
        //variable texture, objet
        SDL_Surface *Image_Sprite;                        
        GLuint texture_name_Sprite;        
        GLfloat texcoord_Sprite[4];		
	public:
		//Constructeur et Destructeur
		Sprite();
		~Sprite();
		//Initialisation de la classe
		bool init(char[]);
 		//rafrechire ?!?!?!
	    bool rafrechire(char[]);
		//Afficher le jeu
		void affiche(int,int,int,int,int,int);
		void affiche_selectionee(int,int,GLdouble,GLdouble);
        //blind
        void blind();        
        //renvois x et y		
        int getx();
		int gety();        
        	
};
#endif
