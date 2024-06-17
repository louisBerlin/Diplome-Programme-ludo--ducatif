#include"Texte.h"
#include "SDL_GL_LoadTexture_Texte.h"

//Constructeur
Texte::Texte()
{     
      Image_Texte  = new SDL_Surface();  
      Image_Bois  = new SDL_Surface();  
}	

//Destructeur
Texte::~Texte()
{
                 //  delete Image_Sprite;
    delete Image_Texte; 
    delete Image_Bois;            
    glDeleteTextures(1,&texture_name_Texte); 
    glDeleteTextures(1,&texture_name_Bois); 
}

//Initialisation du jeu
bool Texte::init()
{             
    //init texture 
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();  
    
    glEnable(GL_BLEND) ;
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA) ;
    
                
    Image_Texte   = IMG_Load("data/police/font.png");
    texture_name_Texte = SDL_GL_LoadTexture_Texte(Image_Texte,texcoord_Texte);
    SDL_FreeSurface(Image_Texte);
    
    Image_Bois   = IMG_Load("data/police/bulle.png");
    texture_name_Bois = SDL_GL_LoadTexture_Texte(Image_Bois,texcoord_Bois);
    SDL_FreeSurface(Image_Bois);
                
    return true;
}

//affichage du texte
void Texte::ecrire(char text[],int xt, int yt)
{
             
        l = 0;
        n = 0;
        longeur_text=strlen(text)-1;      
        longeur_lettre=0;
        vlongeur_lettre=0;
        depart=0;
        
       glEnable(GL_TEXTURE_2D);   
       glBindTexture (GL_TEXTURE_2D, texture_name_Texte);
        
   for(int i=0;i<=longeur_text;i++){
 //ligne 1
 if(text[i]==' '){
 l=0;              
 n=2;    
  vlongeur_lettre = vlongeur_lettre -5;
 longeur_lettre = 15;                           
 }
 else if(text[i]=='_'){
 l=0;              
 n=2;    
  vlongeur_lettre = vlongeur_lettre -5;
 longeur_lettre = 15;                           
 }
 else if(text[i]=='a'){
 l=1;              
 n=6;    
 vlongeur_lettre = vlongeur_lettre -4;
 longeur_lettre = 18;                           
 }
 else if(text[i]=='b'){
 l=2;              
 n=6;
 vlongeur_lettre = vlongeur_lettre -4;
 longeur_lettre = 17;                              
 }       
 else if(text[i]=='c'){
 l=3;              
 n=6;
 vlongeur_lettre = vlongeur_lettre -5;
 longeur_lettre = 17;
 }
 else if(text[i]=='d'){
 l=4;              
 n=6;
 vlongeur_lettre = vlongeur_lettre -5;
 longeur_lettre = 18;
 }
 else if(text[i]=='e'){
 l=5;              
 n=6;                               
 vlongeur_lettre = vlongeur_lettre -4;
 longeur_lettre = 17;
 }        
 else if(text[i]=='f'){
 l=6;              
 n=6;                               
 vlongeur_lettre = vlongeur_lettre -5;
 longeur_lettre = 15;
 }      
 else if(text[i]=='g'){
 l=7;              
 n=6;                               
 vlongeur_lettre = vlongeur_lettre -5;
 longeur_lettre = 17;
 }
 else if(text[i]=='h'){
 l=8;              
 n=6;
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 15;                               
 }       
 else if(text[i]=='i'){
 l=9;              
 n=6;
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 13;
 }
 else if(text[i]=='j'){
 l=10;              
 n=6;
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 15;
 }
 else if(text[i]=='k'){
 l=11;              
 n=6;               
 vlongeur_lettre = vlongeur_lettre -5;                
 longeur_lettre = 17;
 }        
 else if(text[i]=='l'){
 l=12;              
 n=6;               
 vlongeur_lettre = vlongeur_lettre -8;                
 longeur_lettre = 14;
 }      
 else if(text[i]=='m'){
 l=13;              
 n=6;               
 vlongeur_lettre = vlongeur_lettre -1;               
 longeur_lettre = 20;
 }
  else if(text[i]=='n'){
 l=14;              
 n=6;                
 vlongeur_lettre = vlongeur_lettre -5;               
 longeur_lettre = 18;
 }        
 else if(text[i]=='o'){
 l=15;              
 n=6;               
 vlongeur_lettre = vlongeur_lettre -4;                
 longeur_lettre = 17;
 }
 //linge 2      
 else if(text[i]=='p'){
 l=0;              
 n=7;                               
 vlongeur_lettre = vlongeur_lettre -5;
 longeur_lettre = 17;
 }  

 else if(text[i]=='q'){
 l=1;              
 n=7;
 vlongeur_lettre = vlongeur_lettre -5;
 longeur_lettre = 17;                               
 }       
 else if(text[i]=='r'){
 l=2;              
 n=7;
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 16;
 }
 else if(text[i]=='s'){
 l=3;              
 n=7;
 vlongeur_lettre = vlongeur_lettre -7;
 longeur_lettre = 15;
 }
 else if(text[i]=='t'){
 l=4;              
 n=7;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 15;
 }        
 else if(text[i]=='u'){
 l=5;              
 n=7;               
 vlongeur_lettre = vlongeur_lettre -5;                
 longeur_lettre = 19;
 }      
 else if(text[i]=='v'){
 l=6;              
 n=7;    
 vlongeur_lettre = vlongeur_lettre -5;                           
 longeur_lettre = 17;
 }
 else if(text[i]=='w'){
 l=7;              
 n=7;
 vlongeur_lettre = vlongeur_lettre -2;
 longeur_lettre = 20;                               
 }       
 else if(text[i]=='x'){
 l=8;              
 n=7;
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 }
 else if(text[i]=='y'){
 l=9;              
 n=7;
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 }
 else if(text[i]=='z'){
 l=10;              
 n=7;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 }   
  else if(text[i]=='A'){
 l=1;              
 n=4;    
 vlongeur_lettre = vlongeur_lettre -4;
 longeur_lettre = 18;                           
 }
 else if(text[i]=='B'){
 l=2;              
 n=4;
 vlongeur_lettre = vlongeur_lettre -4;
 longeur_lettre = 17;                              
 }       
 else if(text[i]=='C'){
 l=3;              
 n=4;
 vlongeur_lettre = vlongeur_lettre -5;
 longeur_lettre = 17;
 }
 else if(text[i]=='D'){
 l=4;              
 n=4;
 vlongeur_lettre = vlongeur_lettre -5;
 longeur_lettre = 18;
 }
 else if(text[i]=='E'){
 l=5;              
 n=4;                               
 vlongeur_lettre = vlongeur_lettre -4;
 longeur_lettre = 17;
 }        
 else if(text[i]=='F'){
 l=6;              
 n=4;                               
 vlongeur_lettre = vlongeur_lettre -5;
 longeur_lettre = 15;
 }      
 else if(text[i]=='G'){
 l=7;              
 n=4;                               
 vlongeur_lettre = vlongeur_lettre -5;
 longeur_lettre = 17;
 }
 else if(text[i]=='H'){
 l=8;              
 n=4;
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 15;                               
 }       
 else if(text[i]=='I'){
 l=9;              
 n=4;
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 13;
 }
 else if(text[i]=='J'){
 l=10;              
 n=4;
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 15;
 }
 else if(text[i]=='K'){
 l=11;              
 n=4;               
 vlongeur_lettre = vlongeur_lettre -5;                
 longeur_lettre = 17;
 }        
 else if(text[i]=='L'){
 l=12;              
 n=4;               
 vlongeur_lettre = vlongeur_lettre -8;                
 longeur_lettre = 14;
 }      
 else if(text[i]=='M'){
 l=13;              
 n=4;               
 vlongeur_lettre = vlongeur_lettre -1;               
 longeur_lettre = 20;
 }
  else if(text[i]=='N'){
 l=14;              
 n=4;                
 vlongeur_lettre = vlongeur_lettre -5;               
 longeur_lettre = 18;
 }        
 else if(text[i]=='O'){
 l=15;              
 n=4;               
 vlongeur_lettre = vlongeur_lettre -4;                
 longeur_lettre = 17;
 }
 //linge 2      
 else if(text[i]=='P'){
 l=0;              
 n=5;                               
 vlongeur_lettre = vlongeur_lettre -5;
 longeur_lettre = 17;
 }  

 else if(text[i]=='Q'){
 l=1;              
 n=5;
 vlongeur_lettre = vlongeur_lettre -5;
 longeur_lettre = 17;                               
 }       
 else if(text[i]=='R'){
 l=2;              
 n=5;
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 16;
 }
 else if(text[i]=='S'){
 l=3;              
 n=5;
 vlongeur_lettre = vlongeur_lettre -7;
 longeur_lettre = 15;
 }
 else if(text[i]=='T'){
 l=4;              
 n=5;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 15;
 }        
 else if(text[i]=='U'){
 l=5;              
 n=5;               
 vlongeur_lettre = vlongeur_lettre -5;                
 longeur_lettre = 19;
 }      
 else if(text[i]=='V'){
 l=6;              
 n=5;    
 vlongeur_lettre = vlongeur_lettre -5;                           
 longeur_lettre = 17;
 }
 else if(text[i]=='W'){
 l=7;              
 n=5;
 vlongeur_lettre = vlongeur_lettre -2;
 longeur_lettre = 20;                               
 }       
 else if(text[i]=='X'){
 l=8;              
 n=5;
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 }
 else if(text[i]=='Y'){
 l=9;              
 n=5;
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 }
 else if(text[i]=='Z'){
 l=10;              
 n=5;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 }     
 else if(text[i]==','){
 l=12;              
 n=2;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 }     
 else if(text[i]=='.'){
 l=14;              
 n=2;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 }     
 else if(text[i]==':'){
 l=10;              
 n=3;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 }     
 else if(text[i]=='"'){
 l=2;              
 n=2;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 }   
 else if(text[i]==39){
 l=7;              
 n=2;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 }   
 else if(text[i]=='?'){
 l=15;              
 n=3;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 } 
  else if(text[i]=='!'){
 l=1;              
 n=2;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 } 
   else if(text[i]=='-'){
 l=13;              
 n=2;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 } 
    else if(text[i]=='é'){
 l=9;              
 n=14;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 } 
     else if(text[i]=='è'){
 l=8;              
 n=14;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 } 
      else if(text[i]=='ç'){
 l=7;              
 n=14;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 } 
 else if(text[i]=='à'){
 l=0;              
 n=14;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 } 
 else if(text[i]=='ê'){
 l=10;              
 n=14;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 }
 else if(text[i]=='1'){
 l=1;              
 n=3;
 vlongeur_lettre = vlongeur_lettre -2;
 longeur_lettre = 20;                               
 }       
 else if(text[i]=='2'){
 l=2;              
 n=3;
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 }
 else if(text[i]=='3'){
 l=3;              
 n=3;
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 }
 else if(text[i]=='4'){
 l=4;              
 n=3;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 }     
 else if(text[i]=='5'){
 l=5;              
 n=3;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 }     
 else if(text[i]=='6'){
 l=6;              
 n=3;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 }     
 else if(text[i]=='7'){
 l=7;              
 n=3;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 }     
 else if(text[i]=='8'){
 l=8;              
 n=3;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 }   
 else if(text[i]=='9'){
 l=9;              
 n=3;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 }   
 else if(text[i]=='0'){
 l=0;              
 n=3;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 }    
  else if(text[i]=='î'){
 l=14;              
 n=14;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 }    
   else if(text[i]=='û'){
 l=11;              
 n=15;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 }    
    else if(text[i]=='ê'){
 l=13;              
 n=14;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 } 
    else if(text[i]=='â'){
 l=2;              
 n=14;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 } 
 else if(text[i]=='à'){
 l=0;              
 n=14;                               
 vlongeur_lettre = vlongeur_lettre -6;
 longeur_lettre = 17;
 } 
 else if(text[i]=='/'){
 xt = xt+30;
 }    
    if(depart==0){
                 depart=1;
                 vlongeur_lettre=0;
                 }
    
     glBegin ( GL_QUADS ) ;
           glTexCoord2f ( l*0.0625 , n*0.0625) ;        glVertex2i ( vlongeur_lettre +0 +xt , 0 +yt ) ;
           glTexCoord2f ( l*0.0625 , (n+1)*0.0625) ;    glVertex2i ( vlongeur_lettre +0 +xt , 32+yt ) ;
           glTexCoord2f ( (l+1)*0.0625 ,(n+1)*0.0625) ; glVertex2i ( vlongeur_lettre +32+xt , 32+yt ) ;
           glTexCoord2f ( (l+1)*0.0625 , n*0.0625) ;    glVertex2i ( vlongeur_lettre +32+xt , 0 +yt ) ;
     glEnd();
     
     
     vlongeur_lettre = vlongeur_lettre + longeur_lettre;
}
     glDisable(GL_TEXTURE_2D);
    
}

//texte dans une bulle
void Texte::bulle(int bx, int by){
    
       
     glEnable(GL_TEXTURE_2D);   
       glBindTexture (GL_TEXTURE_2D, texture_name_Bois);    
    

     glBegin(GL_TRIANGLES);
      glTexCoord2f ( 0,0)    ; glVertex2i(bx+20,by);
      glTexCoord2f ( 0,1)    ; glVertex2i(100,60);
      glTexCoord2f ( 1,0)    ; glVertex2i(150,60);  
     glEnd();
     
      glBegin(GL_QUADS);    
           glTexCoord2f ( 0,0)    ; glVertex2d(50,40);
           glTexCoord2f ( 0,1)    ; glVertex2d(50,80);
           glTexCoord2f ( 1,1)    ; glVertex2d(200,80);
           glTexCoord2f ( 1,0)    ; glVertex2d(200,40);                
     glEnd();
     
        glDisable(GL_TEXTURE_2D);
     ecrire("hello",60,50);
 
}

//texte en bas de la fenetre 
void Texte::bulle_bas(int dx,int dy,char ligne1[100],char ligne2[100]){

     
     
     
       
       glEnable(GL_TEXTURE_2D);   
       glBindTexture (GL_TEXTURE_2D, texture_name_Bois);
             
     glBegin(GL_QUADS);    
           glTexCoord2f ( 0,0)    ; glVertex2d(0+dx,450+dy);
           glTexCoord2f ( 0,1)    ; glVertex2d(0+dx,550+dy);
           glTexCoord2f ( 1,1)    ; glVertex2d(800+dx,550+dy);
           glTexCoord2f ( 1,0)    ; glVertex2d(800+dx,450+dy);                
     glEnd();
     glDisable(GL_TEXTURE_2D);
     
     ecrire(ligne1,10+dx,460);
     ecrire(ligne2,10+dx,500);
     glDisable(GL_TEXTURE_2D);
   
}












//renvois x
int Texte::getx()
{ return Texte::x; }

//renvois y
int Texte::gety()
{ return Texte::y; }





