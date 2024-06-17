#include "Menu.h"
#include "Moteur.h"



//Moteur du jeu 
extern Moteur *moteur;

//Constructeur
Menu::Menu()
{
    txt = new Texte();
	image = new Sprite();

	image3 = new Sprite();
	icone = new Sprite();
}

Menu::~Menu()
{
   delete txt;
   delete image;
   
   delete image3;	
   delete icone;
}

//Fonction d'initialisation
bool Menu::init()
{    
    //initialisation des variable 
    x = 0; 
    y = 0;
    dx=800;
    dy=600;
    xf = 0;
    choix = 0;
    choix_max = 2;
    menu = 4;
    test = 0;
    couleur = 255;
    fin = 0;
    //initialisation des objet
	txt->init();
	
	icone->init("data/icons/icone.png"); 
	image->init("data/ecran_menu/menu.jpg");

	image3->init("data/ecran_menu/sauvgarder.png");
	
	musique_intro = FSOUND_Stream_Open("data/audio/06 Piste 6.mp3", 0, 0, 0); /* On ouvre la musique */
	son1 = FSOUND_Sample_Load(FSOUND_FREE, "data/audio/wind1.wav", 0, 0, 0);
	son2 = FSOUND_Sample_Load(FSOUND_FREE, "data/audio/windchimes.wav", 0, 0, 0);
	
	//lancé la musique
    FSOUND_SetVolume(FSOUND_ALL, 100);
	FSOUND_Stream_SetLoopCount(musique_intro, -1);
	FSOUND_Stream_Play(FSOUND_FREE, musique_intro);
	return true;
}





//Fonction d'affichage
void Menu::affiche(int  x_Menu,int deplacement)
{
	  glColor3ub(couleur,couleur,couleur);
  if(menu==0){ //---dans le menu_base---
  //glColor3ub(255,255,255);
     choix_max = 5; //nombre d'optin du menu              
  	 
  	 //affichage
	
	 
	 image3->affiche(6,6,x+dx+x_Menu,y+dy,800,600);
	 image->affiche(6,6,x+x_Menu,y,800,600);
	 
	 //deplacement du curseur de selection de 0 a 5 choix
	 if(choix==0){
	 icone->affiche(6,6,80+x+x_Menu,y+260,100,50);
     }
     else if(choix==1){
	 icone->affiche(6,6,80+x+x_Menu,y+320,100,50); 
     }
     else if(choix==2){
	 icone->affiche(6,6,80+x+x_Menu,y+375,100,50);
     }
     else if(choix==3){
	 icone->affiche(6,6,80+x+x_Menu,y+430,100,50);
     }
     else if(choix==4){
	 icone->affiche(6,6,80+x+x_Menu,y+500,100,50);
     }
     else if(choix==5){
	 icone->affiche(6,6,80+x+x_Menu,y+540,100,50);
     }
  }
  else if(menu==1){  //---menu cours---
    choix_max = 1;//nombre d'optin du menu
    
   //affichage
 
	 image->affiche(6,6,x+x_Menu,y,800,600);
	 image3->affiche(6,6,x+dx+x_Menu,y+dy,800,600);
  
  icone->affiche(6,6,x-15,60+y-600,100,50); 
  }
  
  else if(menu==2){  //---menu option---
    choix_max = 1;//nombre d'optin du menu
    
     //affichage
  
	 image->affiche(6,6,x+x_Menu,y,800,600);
	 image3->affiche(6,6,x+dx+x_Menu,y+dy,800,600);
	 
   icone->affiche(6,6,350+x,320+y+600,100,50);
  }
  else if(menu==3){  //---menu sauvgarder-charger---
    choix_max = 2;//nombre d'optin du menu
    
     //affichage
 
	 image->affiche(6,6,x+x_Menu,y,800,600);
	 image3->affiche(6,6,x+dx+x_Menu,y+dy,800,600);
	 
	 
 
   //deplacement du curseur de selection de 0 a 2 choix
	 if(choix==0)
	 icone->affiche(6,6,150+x-800,110+y,100,50);
     else if(choix==1)
	 icone->affiche(6,6,150+x-800,160+y,100,50);
     else if(choix==2)
	 icone->affiche(6,6,150+x-800,210+y,100,50);
     
    
  } 
  else if(menu==4){    //---menu intro---
    choix_max = 2 ;//nombre d'optin du menu
  
   //affichage
    glColor3ub(couleur,couleur,couleur);


	 image->affiche(6,6,0,0,800,600);
	
  	
  //affichage de l'icone de selection
	 if(choix==0)
     icone->affiche(6,6,5,425,100,50);
     else if(choix==1)
     icone->affiche(6,6,5,480,100,50); 
     else if(choix==2)
     icone->affiche(6,6,5,530,100,50); 
          
	 //------texte------
     	// txt->ecrire("    menu jeu",300,300);


	// txt->ecrire("   nouvelle partie",300,350);
	// txt->ecrire("   charger une partie",300,400);
	// txt->ecrire("   quitter",300,450);
	// txt->ecrire("premier teste du rpg math",10,10);
//	 txt->ecrire("louis f",650,10);
	 
  
  
  }	 
  /*else if(menu==5){    //---menu "sauvgarder-charger" intro---
	  choix_max = 0;//nombre d'optin du menu

    //affichage
	 image3->affiche(6,6,0,0,800,600);	 
      icone->affiche(6,6,150,110,100,50);
	 
	 
  }
	*/ 
 
 
SDL_GL_SwapBuffers();
    
 //---deroulement d'un menu a l'autre--- 
 if(test==1){  // passage menu base -> menu sauvgarde-chargement
 choix=0;
 dx=-800;
 dy=0;
  if(x<800)
   x= x+10;
  else if(x==800){
   test=0; 
  }
 }
 
 else if(test==2){  // passage menu base -> menu cours
  dx=0;    
 dy=-600;
 
  if(y<600)
   y= y+10;
  else if(y==600){
   test=0; 
  }
 }
 
  else if(test==3){  // passage menu base -> menu option
  dx=0;    
  dy=600;
 
  if(y>-600)
   y= y-10;
  else if(y==-600){
   test=0; 
  }
 }
 
 
  else if(test==4){   // retoure a menu base
   if(dx==-800){
  if(x>0)
   x= x-10;
  else if(x==0){
   test=0; 
  }
}
    if(dy==-600){
  if(y>0)
   y= y-10;
  else if(y==0){
   test=0; 
  }
}

  if(dy==600){
  if(y<0)
   y= y+10;
  else if(y==0)
   test=0; 
}
 
 
} 
 
if(couleur==5){ 
 moteur->echangeFonctions(0);
couleur =255;
fin=0;
image->rafrechire("data/ecran_menu/menu.png");  
menu=0;
x=0;
y=0;
} 
 
}



// Gestion du clavier
bool Menu::clavier_DOWN(SDLKey event){
 switch(event)
	{                      
                        
                         case SDLK_UP:
                               FSOUND_PlaySound(FSOUND_FREE, son1);
                          if(choix==0)
                           choix=choix_max;
                          else 
                           choix--;                            
                         break;
                         
                         
                         case SDLK_DOWN:
                               FSOUND_PlaySound(FSOUND_FREE, son1);
                         if(choix==choix_max)
                           choix=0;
                          else 
                          choix++;                                  
                         break;
                         
                         
                         case SDLK_RETURN:     // Touche enter
                    if(menu==0){                  // dans le menu base m=0
                           if(choix==0){           //1er option n=0
                            moteur->echangeFonctions(4);    
                            }                          
                           else if(choix==1){      //2er option n=1
                            if((test==0)&&(x==0)&&(y==0)){
                              image3->rafrechire("data/ecran_menu/cours.png");
                              test = 2;
                              menu=1;
                            }
                           }
                           else if(choix==2){      //3er option n=2                        
                            if((test==0)&&(x==0)&&(y==0)){
                              image3->rafrechire("data/ecran_menu/option.png");
                              test = 3;
                              menu=2;
                            }
                           }
                           else if(choix==3){      //4er sauvgarder-charger n=3
                            if((test==0)&&(x==0)&&(y==0)){
                              test = 1;
                              menu=3;
                              image3->rafrechire("data/ecran_menu/sauvgarder.png");
                              
                            }
                           }
                           else if(choix==4){      //5er option n=4
                           menu=4;  
                           choix=0;  
                           x=0;
                           y=0;
                   	       image->rafrechire("data/ecran_menu/menu.jpg");
                   	       moteur->m_stop();
           	       	       FSOUND_Stream_SetLoopCount(musique_intro, -1);
                           FSOUND_Stream_Play(FSOUND_FREE, musique_intro);
                      
                           }
                           else if(choix==5){      //4er option n=5
                            moteur->fin();
                            }
                    }   
                    else if(menu==1){             // dans le menu cours m=1
                        if(test==0)
                        test = 4;
                        menu=0;
                    }
                    else if(menu==2){             // dans le menu option m=2
                        if(test==0)
                        test = 4;
                        menu=0;
                    }
                    else if(menu==3){             // dans le menu option m=3
                             if(choix==0){              
                          moteur->chargement();                      
                          fin=1;                                                                                                                                                         
                         }        
                         else if(choix==1){ 
                         moteur->sauvgarder();
                         }	 
                         else if(choix==2){                         
                          test = 4;
                        menu=0;
                         }
                    }
                    else if(menu==4){             // dans le menu d'introduction m=4
                    
                    
                         if(choix==0){
                                  
                                                       
                           FSOUND_Stream_Stop(musique_intro); 
                           moteur->nouvelle_partie();    
                           fin=1;                                                                                                                                                        
                         }        
                         else if(choix==1){ 
                             fin=1; 
                          FSOUND_Stream_Stop(musique_intro);  
                          moteur->chargement(); 
                         }	 
                         else if(choix==2){                         
                          moteur->fin();
                           FSOUND_Stream_Stop(musique_intro);
                           }
                    }	 
                    else if(menu==5){             // dans le menu sauvgarder-charger d'introduction m=4
                    if(choix==0){              
                                                
                          fin=1; 
                          FSOUND_Stream_Stop(musique_intro);  
                          moteur->chargement();                                                                                                                                                        
                         }        
                         else if(choix==1){ 
                         moteur->sauvgarder();
                         }	 
                         else if(choix==2){                         
                          menu=4;
                         }
                      
                    }	 
                           
                            
                        
                         break;

                         case SDLK_f:
                         if(test==0)
                          test = 4;
                         break;
                         
		                 default:
			             break;
	}            
 }
 
bool Menu::clavier_UP(SDLKey event){     } 
// Timer
void Menu::timer()
{
     if(xf<=800)
   xf++;
  else
  xf=0;
  

if(fin==1)
couleur = couleur -10;    






  
}

