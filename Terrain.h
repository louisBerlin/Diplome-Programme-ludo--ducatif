#ifndef H_TERRAIN
#define H_TERRAIN


#include <SDL/SDL.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_opengl.h>



class Terrain
{

	private:       
        
        //x et y de la texture      
        bool coli;
        char chaine[599][805];
		int ix;
		int iy;

                      
        //variable texture       
        SDL_Surface *Image_Terrain;           
        GLuint texture_name_Terrain;        
        GLfloat texcoord_Terrain[4];
        
        SDL_Surface *Image_Terrain2;
        GLuint texture_name_Terrain2;        
        GLfloat texcoord_Terrain2[4];
        
        
        SDL_Surface *Image_collision;       
        Uint8 r, g, b;        
        Uint8 *p;
		
	    
		
	public:
        
          

		//Constructeur et Destructeur
		Terrain();
		~Terrain();
		//Initialisation de la classe
		bool init(char couche1[],char couche2[],char collision[]);
		//rafrechire ?!?!?!
 		bool rafrechire(char couche1[],char couche2[],char collision[]);
 		//ah
 		void affiche_selectionee(int x,int y,GLdouble dx,GLdouble dy);
		//Afficher les texture
		void affiche(int,int);
		void affiche2(int,int);
        //colision entre les texture et le personnage
        bool colision(int,int,int,int);  
        //renvois x et y		
        int getx();
		int gety();        
        	
};
#endif
