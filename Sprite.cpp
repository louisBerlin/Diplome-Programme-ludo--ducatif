
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

#include "Sprite.h"
#include "SDL_GL_LoadTexture_Sprite.h"

//Constructeur
Sprite::Sprite()
{ 
    Image_Sprite = new SDL_Surface();       
}	
//Destructeur
Sprite::~Sprite()
{
  //  delete Image_Sprite;
     delete Image_Sprite;            
    glDeleteTextures(1,&texture_name_Sprite); 
}
//Initialisation du jeu
bool Sprite::init(char file[256])
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();  
    
    glEnable(GL_BLEND) ;
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA) ;
    
    //glClearColor(1,1,0,1)        ; 
    
    Image_Sprite   = IMG_Load(file);
    
    texture_name_Sprite = SDL_GL_LoadTexture_Sprite(Image_Sprite,texcoord_Sprite);
    SDL_FreeSurface(Image_Sprite);
    return true;
}
//rafrechire le texture
bool Sprite::rafrechire(char file[256])
{
    glDisable(GL_TEXTURE_2D);    
    glDeleteTextures(1,&texture_name_Sprite); 
        
   // Image_Sprite = new SDL_Surface(); 

       
    Image_Sprite   = IMG_Load(file);
    texture_name_Sprite = SDL_GL_LoadTexture_Sprite(Image_Sprite,texcoord_Sprite);
    SDL_FreeSurface(Image_Sprite);
    return true;
}
//affichage du sprite 
void Sprite::affiche(int ligne,int colone,int x,int y,int tx,int ty)
{   
     if (ligne == 6 && colone == 6){
          glEnable(GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, texture_name_Sprite);

     glBegin ( GL_QUADS ) ;
           glTexCoord2f ( 0,0)    ; glVertex2i ( 0  +x , 0  +y) ;
           glTexCoord2f ( 0,1)    ; glVertex2i ( 0  +x , ty +y) ;
           glTexCoord2f ( 1,1)    ; glVertex2i ( tx+x  , ty +y) ;
           glTexCoord2f ( 1,0)    ; glVertex2i ( tx+x  , 0  +y) ;
     glEnd();
     	glDisable(GL_TEXTURE_2D);
          
          }
     else if(ligne == 5 && colone == 5){
          glEnable(GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, texture_name_Sprite);

     glBegin ( GL_QUADS ) ;
           glTexCoord2f ( 0,0)    ; glVertex2i ( 0  +x , 0  +y) ;
           glTexCoord2f ( 0,0.5)    ; glVertex2i ( 0  +x , ty +y) ;
           glTexCoord2f ( 1,0.5)    ; glVertex2i ( tx+x  , ty +y) ;
           glTexCoord2f ( 1,0)    ; glVertex2i ( tx+x  , 0  +y) ;
     glEnd();
     	glDisable(GL_TEXTURE_2D);
          }
      else if(ligne == 5 && colone == 6){
          glEnable(GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, texture_name_Sprite);

     glBegin ( GL_QUADS ) ;
           glTexCoord2f ( 0,0.5)    ; glVertex2i ( 0  +x , 0  +y) ;
           glTexCoord2f ( 0,1)    ; glVertex2i ( 0  +x , ty +y) ;
           glTexCoord2f ( 1,1)    ; glVertex2i ( tx+x  , ty +y) ;
           glTexCoord2f ( 1,0.5)    ; glVertex2i ( tx+x  , 0  +y) ;
     glEnd();
     	glDisable(GL_TEXTURE_2D);
          }
     else
     { 
     glEnable(GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, texture_name_Sprite);

     glBegin ( GL_QUADS ) ;
           glTexCoord2f ( 0.25*ligne,     0.25*colone)        ; glVertex2i ( 0  +x , 0  +y) ;
           glTexCoord2f ( 0.25*ligne,     0.25*(colone+1))    ; glVertex2i ( 0  +x , ty +y) ;
           glTexCoord2f ( 0.25*(ligne+1), 0.25*(colone+1))    ; glVertex2i ( tx +x , ty +y) ;
           glTexCoord2f ( 0.25*(ligne+1), 0.25*colone)        ; glVertex2i ( tx +x , 0  +y) ;
     glEnd();
     	glDisable(GL_TEXTURE_2D);
      }	
     Sprite::x = x;
     Sprite::y = y;
}
void Sprite::affiche_selectionee(int x,int y,GLdouble dx,GLdouble dy)
{       

       dx=dx/800;
       dy=dy/600;
        
    glEnable(GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, texture_name_Sprite);
     glBegin ( GL_QUADS ) ;
           glTexCoord2d ( dx+0,dy+0)    ; glVertex2i ( 0  +x , 0  +y) ;
           glTexCoord2d ( dx+0,dy+0.25)    ; glVertex2i ( 0  +x , 600+y) ;
           glTexCoord2d ( dx+0.25,dy+0.25)    ; glVertex2i ( 800+x , 600+y) ;
           glTexCoord2d ( dx+0.25,dy+0)    ; glVertex2i ( 800+x , 0  +y) ;
     glEnd();
     glDisable(GL_TEXTURE_2D);
         
}

// blindé la texure
void Sprite::blind(){
     
      glEnable(GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, texture_name_Sprite);
     
     }
//renvois x
int Sprite::getx()
{ return Sprite::x; }

//renvois y
int Sprite::gety()
{ return Sprite::y; }
















