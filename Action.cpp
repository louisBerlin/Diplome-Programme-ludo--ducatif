#include "Action.h"

#include "Moteur.h"






//Moteur du jeu 
extern Moteur *moteur;
 

//Constructeur
Action::Action()
{                                     
    image0 = new Sprite();
    image1 = new Sprite();
    txt = new Texte();
	
}

Action::~Action()
{
   delete image0;
   delete image1;
   delete txt; 
}

//Fonction d'initialisation
bool Action::init()
{       
    mode = 0;
    x=600;
    y=400;
    d=0;
    sence=0;   
    couleur=0;  
    ty=200;
    action=0;
    
    
    
    moteur->m_chargement("data/audio/theme2c.mid");
  
	image0->init("data/action/f.png");
	image1->init("data/action/f.png");
	
	      
    txt->init();
      
      Timer = true;     
	return true;
}


void Action::chargement(char lien[256]){
     
     
     
     Timer =false;//lancé le timer
     mode=1;
    //chargement des données (liste des action)
    char doc [40][256];
    int temp[15];
    int ligne = 0;
    char liens[9][256];
        
     FILE* fichier = NULL;
         fichier = fopen(lien, "r");

     if(fichier != NULL){ 
       int a=0;
         while (fgets(doc[a],256, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
         {       
             a++;
         }
         fclose(fichier);
     }  
     
     if(doc[0][0]=='c'){     
     
      
      sscanf(doc[ligne],"%s %s %s %d %d %d %d %d",&liens[0],&liens[1],&liens[2],&temp[0],&temp[1],&temp[2],&temp[3],&temp[4]);   
      image1->rafrechire("data/action/f.png");   
      image0->rafrechire(liens[2]);         
      moteur->m_chargement(liens[1]);            
      ligne++;                                
      depart   = temp[0];
      arrivee  = temp[1];
      depart2  = temp[2];
      arrivee2 = temp[3];
      xouy     = temp[4];;
      if(xouy==0){ 
      x= depart;
      y= depart2;}
      else{
       x= depart2;
      y= depart;}    
      
      index_text=0;
      temps=0;
      
      mode = 0;
      temps=0;
       
     while(doc[ligne][0]!='-'){
      for(int i=0;i<=256;i++){ texte[ligne-1][i]=doc[ligne][i]; }
      ligne++;                                       
      }     
      vlongueur_txt = ligne-1;                 
                       
                        
                        
     }
     else if(doc[0][0]=='e'){
          
      sscanf(doc[ligne],"%s %s %s %s %d",&liens[0],&liens[1],&liens[2],&liens[3],&temp[0]);     
      repance = temp[0];          
      moteur->m_chargement(liens[1]);            
      image0->rafrechire(liens[2]); 
      image1->rafrechire(liens[3]);     
  
      choix = 0;  
          
            FILE* fichier;
                         fichier = NULL;
                         fichier = fopen("test.txt", "w");;//lecture du chapitre
    
                         if (fichier != NULL)
                         {
                            fprintf(fichier,"%d",repance);
                            fclose(fichier);
                         }
            
      mode = 1;    
     }
     

     
     
     
     moteur->m_play();
     moteur->m_volume(100);
     
     
     couleur=255;
     Timer = true;//lancé le timer
     
}
//Fonction d'affichage
void Action::affiche(int y_jeu_action)
{    
     glColor3ub(couleur,couleur,couleur);
    
     if(mode==0){
      
     image0->affiche_selectionee(0,y_jeu_action,x,y);
     image1->affiche(6,6,0,+y_jeu_action,800,600);

         
      txt->ecrire(texte[index_text],80,500+y_jeu_action);
      txt->ecrire(texte[index_text+1],80,530+y_jeu_action);
      txt->ecrire(texte[index_text+2],80,560+y_jeu_action);
       
     }
     else if(mode==1){
      image0->affiche(6,6,0,+y_jeu_action,800,600);
      if(choix==0)
       image1->affiche(6,6,150,370+y_jeu_action,100,50);
     else if(choix==1)
       image1->affiche(6,6,150,400+y_jeu_action,100,50);
     else if(choix==2) 
       image1->affiche(6,6,150,430+y_jeu_action,100,50);       
       
         
         
     }
     // Fin de l'application de la texture.
     glDisable (GL_TEXTURE_2D);
     // Fin de la liste d'affichage.
     glEndList ();  
     glEnd();
	
	 glCallList(1);

     SDL_GL_SwapBuffers();
}

void Action::timer(){ 
 if(Timer==true){                   
   if(mode==0){
      //defillement du text
      if(index_text<vlongueur_txt){
      temps++;
      if(temps==100){     
      index_text=index_text+3;
      temps=0;
      }
      
      }
      
      
      //defillement de l'image
     if(xouy==0){            
    if(y==arrivee2){
    couleur = couleur -10;  
    if(couleur ==5){
     moteur->m_stop();
     moteur->echangeFonctions(6); 
     couleur =0;
     }             
    }
    else{
     if(x==arrivee){     
      if(depart2>arrivee2)
       y--;
      else
       y++;
      } 
     else{               
     if(depart>arrivee)
      x--;
     else
      x++;
     }
    }  
   } 
   
   
   else if(xouy==1){
    if(x==arrivee2){
    couleur = couleur -10;  
    if(couleur ==5){
     moteur->m_stop();
     moteur->echangeFonctions(6);
     couleur =0;
     }
    }
    else{
     if(y==arrivee){ 
      if(depart2>arrivee2)
       x--;
      else
       x++;
     }
     else{                
      if(depart>arrivee)
       y--;
      else
       y++;
     } 
    } 
   }   
   
   
  }
   else if(mode==1){
      
    
    
    
        
  }
 }
}

bool Action::clavier_DOWN(SDLKey event){
     switch(event)
	{
                  
                    case SDLK_UP:
                        if(mode==1){
                         if(choix==0)
                         choix=2;
                         else
                         choix--;
                         }
                         break;
                    case SDLK_DOWN:
                        if(mode==1){ 
                         if(choix==2)
                         choix=0;
                         else
                         choix++;
                        }
                         break;
                    case SDLK_RETURN:
                         if(choix==repance){
                          moteur->m_stop();
                          moteur->echangeFonctions(6);
                          couleur =0;                                  
                         }
                         else{
                              
                         }
                         break;
		                 default:
			             break;
	}   
}

bool Action::clavier_UP(SDLKey event){
     switch(event)
	{
                   case SDLK_RIGHT: 
                       
                         break;
                    case SDLK_LEFT:
                        
                         break;
                    case SDLK_UP:
                        
                         break;
                    case SDLK_DOWN:
                        
                         break;
		                 default:
			             break;
	}    
} 
