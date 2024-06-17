#include "Moteur.h"



//Constructeur
Moteur::Moteur(){
  est_fini = false;
  jeu = new Jeu();
  menu = new Menu();        
  action = new Action(); 
 // musique = new FMUSIC_MODULE();
}	

//Destructeur
Moteur::~Moteur(){
  delete jeu;   
  delete menu;   
  delete action;          
}

//Initialisation du jeu
bool Moteur::init()
{                             
     T=true; 
     x=600;
     chapitre = 0;
     dans_menu = 1;
     raf=1;
     
     
      char doc [40][256];
  // chargement du fichier deroulemnt
      FILE* fichier;
      fichier = NULL;
      fichier = fopen("data/deroulement/droulement", "r");//lecture du deroulement

  /*  if (fichier != NULL)
   {
        fscanf(fichier,"%s %s %s %s",&lien_chapitre[0],&lien_chapitre[1],&lien_chapitre[2],&lien_chapitre[3]);
        fclose(fichier);
   }*/
     if (fichier != NULL){ 
       int i=0;
         while (fgets(doc[i], 256, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
         {       
             i++;
         }
         fclose(fichier);
     }  
     for(int i=0;i<=39;i++){
     sscanf(doc[i],"%s",&lien_chapitre[i]);
     }
       
 
        //variable interne
   
    //chargement des donnée (liste des action)
 
   // FILE* fichier = NULL;
         fichier = fopen(lien_chapitre[chapitre], "r");

     if (fichier != NULL){ 
       int i=0;
         while (fgets(doc[i], 256, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
         {       
             i++;
         }
         fclose(fichier);
     }  
     
     for(int i=0;i<=5;i++){
     sscanf(doc[i],"%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d ",&lien_map[i],&par[i][0], &par[i][1], &par[i][2], &par[i][3], &par[i][4], &par[i][5], &par[i][6],&par[i][7], &par[i][8], &par[i][9], &par[i][10], &par[i][11], &par[i][12], &par[i][13],&par[i][14], &par[i][15], &par[i][16], &par[i][17], &par[i][18], &par[i][19], &par[i][20]);
     }
     
     
     
   map=2;     
   
   //initialisation des objet
   menu->init();
   action->init();
   jeu->init(lien_map[map]);

   T=false;  
  return true;
}




//affichage du sprite 
void Moteur::affiche()
{        
     glColor3ub(255,255,255);//reglage des couleur
     
    if(dans_menu == 0)
          dessineJeu();       
    else if (dans_menu == 1)  
          dessineMenu();
    else if (dans_menu == 2)  {
           dessineAction();
           }
    else if (dans_menu == 3){
         menu->affiche(x-800,0);     
         jeu->affiche(x,0);
         menu->affiche(x-800,0);  
         
         if(x<800)
           x= x+10;
         else if(x==800)
          dans_menu=1;     
    }
    else if (dans_menu == 4){
         
         jeu->affiche(x,0);
         menu->affiche(x-800,0);     
         jeu->affiche(x,0);
         
         if(x>0)
          x= x-10;
         else if(x==0)
          dans_menu=0;   
    }
    else if (dans_menu == 5){
         
         action->affiche(x-600);
         jeu->affiche(0,x);
         action->affiche(x-600);
         
         
         
         
         if(x<600)
          x= x+5;
         else if(x==600){
          dans_menu=2;  
               action->chargement(lien_action);     
          }
    }
    else if (dans_menu == 6){
         jeu->affiche(0,x);
         action->affiche(x-600);
         jeu->affiche(0,x);
         
        
         if(x>0)
          x= x-5;
         else if(x==0)
          dans_menu=0; 
    }
        

}

void Moteur::dessineJeu(){
     jeu->affiche(0,0);//affichage du jeu
       x=0;
     
     if((jeu->get_x()>=par[map][0])&&
        (jeu->get_x()<=par[map][1])&&
        (jeu->get_y()>=par[map][2])&&
        (jeu->get_y()<=par[map][3])){
                                                       
            jeu->fix_x(par[map][4]);
            jeu->fix_y(par[map][5]);      
            map=par[map][6];     
            jeu->rafrechire(lien_map[map]);  
     }
     else if((jeu->get_x()>=par[map][7])&&
        (jeu->get_x()<=par[map][8])&&
        (jeu->get_y()>=par[map][9])&&
        (jeu->get_y()<=par[map][10])){
                                                       
            jeu->fix_x(par[map][11]);
            jeu->fix_y(par[map][12]);        
            map=par[map][13];     
            jeu->rafrechire(lien_map[map]);  
     }  
      else if((jeu->get_x()>=par[map][14])&&
        (jeu->get_x()<=par[map][15])&&
        (jeu->get_y()>=par[map][16])&&
        (jeu->get_y()<=par[map][17])){
                                                       
            jeu->fix_x(par[map][18]);
            jeu->fix_y(par[map][19]);        
            map=par[map][20];     
            jeu->rafrechire(lien_map[map]);  
     }  
     else if(raf==0){
           jeu->rafrechire(lien_map[map]);
           raf=1;
     }            
}

void Moteur::rafrechiree(int m){
     map=m;
     raf=0;
}

void Moteur::chapitre_suivant(int nvx,int nvy){
     char doc [40][256];
     
     chapitre++;
     
     FILE* fichier;
     fichier = NULL;
     fichier = fopen(lien_chapitre[chapitre], "r");

     if (fichier != NULL){ 
       int i=0;
         while (fgets(doc[i], 256, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
         {       
             i++;
         }
         fclose(fichier);
     }  
     
     for(int i=0;i<=5;i++){
    sscanf(doc[i],"%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d ",&lien_map[i],&par[i][0], &par[i][1], &par[i][2], &par[i][3], &par[i][4], &par[i][5], &par[i][6],&par[i][7], &par[i][8], &par[i][9], &par[i][10], &par[i][11], &par[i][12], &par[i][13],&par[i][14], &par[i][15], &par[i][16], &par[i][17], &par[i][18], &par[i][19], &par[i][20]);
     }
     
     
  map=0;
  jeu->fix_x(nvx);
  jeu->fix_y(nvy);    
         
  raf=0; 
}


void Moteur::chargement(){
    char doc [40][256];
    int save[4];
     
     
     FILE* fichier;
     fichier = NULL;
     
      fichier = fopen("data/deroulement/save", "r");

     if (fichier != NULL){ 
       int i=0;
         while (fgets(doc[i], 256, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
         {       
             i++;
         }
         fclose(fichier);
     }  
      
     sscanf(doc[0],"%d %d %d %d",&save[0],&save[1],&save[2],&save[3]);
     
     chapitre = save[0];
     
     fichier = fopen(lien_chapitre[chapitre], "r");

     if (fichier != NULL){ 
       int i=0;
         while (fgets(doc[i], 256, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
         {       
             i++;
         }
         fclose(fichier);
     }  
     
     for(int i=0;i<=5;i++){
    sscanf(doc[i],"%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d ",&lien_map[i],&par[i][0], &par[i][1], &par[i][2], &par[i][3], &par[i][4], &par[i][5], &par[i][6],&par[i][7], &par[i][8], &par[i][9], &par[i][10], &par[i][11], &par[i][12], &par[i][13],&par[i][14], &par[i][15], &par[i][16], &par[i][17], &par[i][18], &par[i][19], &par[i][20]);
    }
     
  map=save[1];
  jeu->fix_x(save[2]);
  jeu->fix_y(save[3]);           
  raf=0; 
}
void Moteur::nouvelle_partie(){
     
  if((chapitre==0)&&(map==2)){
                              }
                              else{ 
     char doc [40][256];
     FILE* fichier;
     fichier = NULL;
   
     chapitre = 0;
    
     fichier = fopen(lien_chapitre[chapitre], "r");

     if (fichier != NULL){ 
       int i=0;
         while (fgets(doc[i], 256, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
         {       
             i++;
         }
         fclose(fichier);
     }  
      map = 2;
     for(int i=0;i<=5;i++){sscanf(doc[i],"%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d ",&lien_map[i],&par[i][0], &par[i][1], &par[i][2], &par[i][3], &par[i][4], &par[i][5], &par[i][6],&par[i][7], &par[i][8], &par[i][9], &par[i][10], &par[i][11], &par[i][12], &par[i][13],&par[i][14], &par[i][15], &par[i][16], &par[i][17], &par[i][18], &par[i][19], &par[i][20]);
       }
             
    raf=0;   
    jeu->fix_x(350);
    jeu->fix_y(300);
    jeu->fix_sance(2);
     raf=0;
  }
 
}
 void Moteur::sauvgarder(){
      
         FILE* fichier;
         fichier = NULL;
         fichier = fopen("data/deroulement/save", "w");;//lecture du chapitre
    
         if (fichier != NULL)
         {
           fprintf(fichier,"%d %d %d %d",chapitre,map,jeu->get_x(),jeu->get_y());
           fclose(fichier);
         }     
}




void Moteur::dessineMenu(){   
    menu->affiche(0,1);      
}


void Moteur::dessineAction(){   
    action->affiche(0);      
}
void Moteur::action_start(char liens[256]){
 
 for(int i=0;i<=200;i++){
 lien_action[i] = liens[i];
 } 
 echangeFonctions(5);     
}

void Moteur::timer (){
     if(dans_menu == 0){   
     if(T==false)
     jeu->timer();
     }                        
      else if(dans_menu == 1) 
      menu->timer();
      else if(dans_menu == 2) 
      action->timer();
}   

bool Moteur::clavier_DOWN(SDLKey event){
     switch(event)
	{ 
      case SDLK_a:
           if(dans_menu ==0)
       echangeFonctions(3);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
      break;         
      case SDLK_q:
      if(dans_menu ==2)
      echangeFonctions(6);
      else if(dans_menu ==0)
       echangeFonctions(5);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
      break;        
      default:
      break;
	}    
    if(dans_menu == 0){
	if(T==false)
	jeu->clavier_DOWN(event);
    }
    else if(dans_menu == 1) 
    menu->clavier_DOWN(event);
    else if(dans_menu == 2) 
    action->clavier_DOWN(event);
}

bool Moteur::clavier_UP(SDLKey event){
    if(dans_menu == 0){
	if(T==false)
	jeu->clavier_UP(event);
    }
    else if(dans_menu == 1) 
    menu->clavier_UP(event);
    else if(dans_menu == 2) 
    action->clavier_UP(event);
}             	




  
void Moteur::echangeFonctions(int menu)
{   
     dans_menu=menu;
}

void Moteur::m_chargement(char m_lien[256])
{  
  musique = FMUSIC_LoadSong(m_lien);
}

void Moteur::m_play()
{   
    FMUSIC_SetLooping(musique, 1); // Répétition infinie
    FMUSIC_PlaySong(musique); // On joue la chanson
}

void Moteur::m_stop()
{   
      FMUSIC_StopSong(musique);
}

void Moteur::m_volume(int v)
{   
      FMUSIC_SetMasterVolume(musique, v);
}






bool Moteur::estFini()
{
    return est_fini;
}


void Moteur::fin()
{
    est_fini = true;
}




