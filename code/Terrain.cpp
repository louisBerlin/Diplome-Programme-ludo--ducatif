
/*
Un pong en SDL/OpenGL
A pong in SDL/OpenGL
Copyright (C) 2006 BEYLER Jean Christophe

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include "Terrain.h"
#include "SDL_GL_LoadTexture_Terrain.h"
#include "Define.h"

//Constructeur
Terrain::Terrain()
{    
     Image_Terrain = new SDL_Surface();           
     Image_Terrain2 = new SDL_Surface();
     Image_collision = new SDL_Surface();       
     
     
}	
//Destructeur
Terrain::~Terrain()
{
    delete Image_Terrain;           
     delete Image_Terrain2;
     delete Image_collision;
     glDeleteTextures(1,&texture_name_Terrain); 
     glDeleteTextures(1,&texture_name_Terrain2);           
}

//Initialisation du jeu
bool Terrain::init(char couche1[256],char couche2[256],char collision[256])
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();  
    
    glEnable(GL_BLEND) ;
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA) ;
    
    //glClearColor(1,1,0,1)        ;    
    Image_Terrain   = IMG_Load(couche1);
    texture_name_Terrain = SDL_GL_LoadTexture_Terrain(Image_Terrain,texcoord_Terrain);
    SDL_FreeSurface(Image_Terrain);
    
    Image_Terrain2   = IMG_Load(couche2);
    texture_name_Terrain2 = SDL_GL_LoadTexture_Terrain(Image_Terrain2,texcoord_Terrain2);
    SDL_FreeSurface(Image_Terrain2);

    Image_collision= IMG_Load(collision);       

        
    
 /*  
  	FILE* fichier = NULL;      
    fichier = fopen(file2, "r");

    if (fichier != NULL)
    {      
         for(int i=0;i<599;i++){     
          fgets(chaine[i],805, fichier);
         } 
     fclose(fichier);
    }
   */ 

    return true;
}

//rafrechire ?!?!?!
bool Terrain::rafrechire(char couche1[256],char couche2[256],char collision[256]){

     
    
     
     glDisable(GL_TEXTURE_2D);
     glDeleteTextures(1,&texture_name_Terrain); 
     glDeleteTextures(1,&texture_name_Terrain2);     
     
      
       
    Image_Terrain   = IMG_Load(couche1);
    texture_name_Terrain = SDL_GL_LoadTexture_Terrain(Image_Terrain,texcoord_Terrain);
    SDL_FreeSurface(Image_Terrain);
    
    Image_Terrain2   = IMG_Load(couche2);
    texture_name_Terrain2 = SDL_GL_LoadTexture_Terrain(Image_Terrain2,texcoord_Terrain2);
    SDL_FreeSurface(Image_Terrain2);

    SDL_FreeSurface(Image_collision);
    Image_collision= IMG_Load(collision);  
      return true;   
}

//affichage du sprite 
void Terrain::affiche(int x,int y)
{       
    glEnable(GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, texture_name_Terrain);
     glBegin ( GL_QUADS ) ;
           glTexCoord2f ( 0,0)    ; glVertex2i ( 0  +x , 0  +y) ;
           glTexCoord2f ( 0,1)    ; glVertex2i ( 0  +x , 600+y) ;
           glTexCoord2f ( 1,1)    ; glVertex2i ( 800+x , 600+y) ;
           glTexCoord2f ( 1,0)    ; glVertex2i ( 800+x , 0  +y) ;
     glEnd();
     glDisable(GL_TEXTURE_2D);
         
}
void Terrain::affiche_selectionee(int x,int y,GLdouble dx,GLdouble dy)
{       

       dx=dx/800;
       dy=dy/600;
        
    glEnable(GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, texture_name_Terrain);
     glBegin ( GL_QUADS ) ;
           glTexCoord2d ( dx+0,dy+0)    ; glVertex2i ( 0  +x , 0  +y) ;
           glTexCoord2d ( dx+0,dy+0.25)    ; glVertex2i ( 0  +x , 600+y) ;
           glTexCoord2d ( dx+0.25,dy+0.25)    ; glVertex2i ( 800+x , 600+y) ;
           glTexCoord2d ( dx+0.25,dy+0)    ; glVertex2i ( 800+x , 0  +y) ;
     glEnd();
     glDisable(GL_TEXTURE_2D);
         
}

//affichage du sprite 
void Terrain::affiche2(int x,int y)
{    
    glEnable(GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, texture_name_Terrain2);
     glBegin ( GL_QUADS ) ;
           glTexCoord2f ( 0,0)    ; glVertex2i ( 0  +x , 0  +y) ;
           glTexCoord2f ( 0,1)    ; glVertex2i ( 0  +x , 600+y) ;
           glTexCoord2f ( 1,1)    ; glVertex2i ( 800+x , 600+y) ;
           glTexCoord2f ( 1,0)    ; glVertex2i ( 800+x , 0  +y) ;
     glEnd();
    glDisable(GL_TEXTURE_2D); 
         
}
//colision entre les texture et le personnage
bool Terrain::colision(int x,int x2,int y,int y2)
{
   for(ix=0;ix<=x2;ix++){
     for(iy=0;iy<=y2;iy++){
       
     if(((x+ix)<0) || ((y+iy)<30) || ((x+ix)>800) || ((y+iy)>600) )
        return true;
            
     p = (Uint8*)Image_collision->pixels + (y+iy) * Image_collision->pitch + (x+ix) * Image_collision->format->BytesPerPixel;
     /* Récupère la valeur RGB du premier pixel (0, 0) d'une surface */
     SDL_GetRGB(*(Uint32*)p, Image_collision->format, &r, &g, &b);  
                  
     if(((int)r+(int)g+(int)b)==0)
        return true;
     else 
        return false;
     }
   }
}


/*

//renvois x
int Terrain::getx()
{ return x; }

//renvois y
int Terrain::gety()
{ return y; }
*/














