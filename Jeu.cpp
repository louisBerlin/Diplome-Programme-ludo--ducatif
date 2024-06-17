 
#include"Jeu.h"
#include "Moteur.h"



//Moteur du jeu 
extern Moteur *moteur;

//Constructeur
Jeu::Jeu()
{
   txt = new Texte();            
   terrain  = new Terrain();
   sprites[0]  = new Sprite();
   sprites[1]  = new Sprite();
   sprites[2]  = new Sprite();
   sprites[3]  = new Sprite();
   sprites[4]  = new Sprite();
   sprites[5]  = new Sprite();
};

//Destructeur
Jeu::~Jeu()
{
   delete terrain;
   delete sprites[0];
   delete sprites[1];
   delete sprites[2];
   delete sprites[3];
   delete sprites[4];
   delete sprites[5];      
   delete txt;         
}  
         
//-------------------------------------------------------------initialisation de la classe-------------------------------------------------------------------------
bool Jeu::init(char ftxt[256])
{  
     
  
  Timer =false;//lancé le timer
    
       //variable interne
    char doc [40][256];
    int temp[15];
    char liens[9][256];
    //chargement des donnée (liste des action)
 
    FILE* fichier = NULL;
         fichier = fopen(ftxt, "r");

     if (fichier != NULL){ 
       int i=0;
         while (fgets(doc[i], 256, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
         {       
             i++;
         }
         fclose(fichier);
     }  
     
      //terrain
      sscanf(doc[0],"%s %s %s %d",&liens[0],&liens[1],&liens[2],&temp[0]);
      txt->init();
      terrain->init(liens[0],liens[1],liens[2]);
           
      //hero
      sscanf(doc[1],"%s %d %d %d %d %d",&liens[0],&temp[1],&temp[2],&temp[3],&temp[4],&temp[5]);
      sprites[0]->init(liens[0]);
      sprite[0].d = 0;
      sprite[0].sance = temp[5];
      sprite[0].dx = temp[1];
      sprite[0].dy = temp[2];
      sprite[0].x = temp[3];//350;
      sprite[0].y = temp[4];//300;
      
      //autre sprite   
   //   if(temp[0]>)
      for(int i=1;i<=temp[0];i++){
      sscanf(doc[1+i],"%s %d %d %d %d %d %d %d %s %s",&liens[0],&temp[1],&temp[2],&temp[3],&temp[4],&temp[5],&temp[6],&temp[7],&parole[1+(i-1)*2],&parole[2+(i-1)*2]);
      sprites[i]->init(liens[0]);        
              
        sprite[i].d = 0;
        sprite[i].dx =     temp[1];
        sprite[i].dy =     temp[2];
         
        sprite[i].xouy =   temp[3];
        sprite[i].depar =  temp[4];
        sprite[i].arrive = temp[5];  
        sprite[i].sur =    temp[6];
        sprite[i].action = temp[7];
         
        if(sprite[i].xouy==0){
         sprite[i].x = sprite[i].depar;
         sprite[i].y = sprite[i].sur;
         if(sprite[i].depar>=sprite[i].arrive)
           sprite[i].sance = 2;
          else
           sprite[i].sance = 1;
         }
         else {
          sprite[i].y = sprite[i].depar;
          sprite[i].x = sprite[i].sur;  
          if(sprite[i].depar>=sprite[i].arrive)
           sprite[i].sance = 3;
          else
           sprite[i].sance = 0;   
         }
              
              }
              
              
          
     //initialiastion de la musique 
      sscanf(doc[2+temp[0]],"%s",&liens[0]);
      moteur->m_chargement(liens[0]);
      //musique = FMUSIC_LoadSong(liens[0]);
      
      //initialiastion des action
      sscanf(doc[3+temp[0]],"%d %d",&temp[1],&mode_automatique);
      for(int i=7;i<=7+temp[1];i++)
      sscanf(doc[i],"%s",&lien_action[i-7]);
      
      


    //initialisation des variables
         T=0;
         text_bulle=0;
         action = 0;
         index_action=0;
         init_saction=1;
         init_deplacement_saction=1;
         ligne=0; 
         couleur=255;

         
    Timer = true;//lancé le timer
    
    
    
    
}

//---------------------------------------------------------------rafrechisement des donnée(d'une map a une autre)------------------------------------------------
bool Jeu::rafrechire(char ftxt[256]){
     
     
  Timer =false;//lancé le timer
    
       //variable interne
    char doc [40][256];
    int temp[15];
    char liens[9][256];
    //chargement des données (liste des action)
 
    FILE* fichier = NULL;
         fichier = fopen(ftxt, "r");

     if (fichier != NULL){ 
       int i=0;
         while (fgets(doc[i], 256, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
         {       
             i++;
         }
         fclose(fichier);
     }  
     
      //terrain
      sscanf(doc[0],"%s %s %s %d",&liens[0],&liens[1],&liens[2],&temp[0]);
      terrain->rafrechire(liens[0],liens[1],liens[2]);
           
      //hero
      sscanf(doc[1],"%s %d %d %d %d",&liens[0],&temp[1],&temp[2],&temp[3],&temp[4]);
      sprites[0]->rafrechire(liens[0]);
      sprite[0].dx = temp[1];
      sprite[0].dy = temp[2];

      
      //autre sprite   
      for(int i=1;i<=temp[0];i++){
      sscanf(doc[1+i],"%s %d %d %d %d %d %d %d %s %s",&liens[0],&temp[1],&temp[2],&temp[3],&temp[4],&temp[5],&temp[6],&temp[7],&parole[1+(i-1)*2],&parole[2+(i-1)*2]);
      sprites[i]->rafrechire(liens[0]);        
              
        sprite[i].d = 0;
        sprite[i].dx =     temp[1];
        sprite[i].dy =     temp[2];
         
        sprite[i].xouy =   temp[3];
        sprite[i].depar =  temp[4];
        sprite[i].arrive = temp[5];  
        sprite[i].sur =    temp[6];
        sprite[i].action = temp[7];
         
        if(sprite[i].xouy==0){
         sprite[i].x = sprite[i].depar;
         sprite[i].y = sprite[i].sur;
         if(sprite[i].depar>=sprite[i].arrive)
          sprite[i].sance = 2;
         else
          sprite[i].sance = 1;
        }
        else {
         sprite[i].y = sprite[i].depar;
         sprite[i].x = sprite[i].sur;  
         if(sprite[i].depar>=sprite[i].arrive)
          sprite[i].sance = 3;
         else
          sprite[i].sance = 0;   
        }        
      }
              
              
          
     //chargement musique 
      sscanf(doc[2+temp[0]],"%s",&liens[0]);
      moteur->m_chargement(liens[0]);
      moteur->m_play();
      moteur->m_volume(100);
      /*FMUSIC_StopSong(musique);
      FMUSIC_FreeSong(musique);
      musique = FMUSIC_LoadSong(liens[0]);
      FMUSIC_SetLooping(musique, 1); // Répétition infinie
      FMUSIC_PlaySong(musique); // On joue la chanson
      */
      
      
       //initialiastion des actions
      sscanf(doc[3+temp[0]],"%d %d",&temp[1],&mode_automatique);
      for(int i=7;i<=7+temp[1];i++)
      sscanf(doc[i],"%s",&lien_action[i-7]);
        
         couleur =255;
         T=0;
         text_bulle=0;
         action = 0;
         index_action=0;
         init_saction=1;
         init_deplacement_saction=1;
         ligne=0; 
      
    Timer = true;//lancé le timer
    
}

//----------------------------------------------------------affichage------------------------------------------------------------------------------------------
void Jeu::affiche(int  x_menu_jeu,int  y_menu_jeu){
       
     glColor3ub(couleur,couleur,couleur);
          
     terrain->affiche(0+x_menu_jeu,0+y_menu_jeu);//affichage tu terrain premier couche
    
     //-------------ordre d'affichage entre 4 sprite----------------------
            
     int ordre[5];
     int temps1[5];
     int temps2;
     
     for(int i=0;i<=3;i++){
      temps1[i]=sprite[i].y;
     }
        
      
     for(int j=0;j<=3;j++){ 
         temps2=10000;
      for(int i=0;i<=3;i++){      
       if(temps1[i]<=temps2){
             temps2=temps1[i];
             ordre[j]=i;
             }
             }
      temps1[ordre[j]]=100000;        
      }
      //-------------------fin affichage sprite-------------- 
        
     sprites[ordre[0]]->affiche(sprite[ordre[0]].d,sprite[ordre[0]].sance,sprite[ordre[0]].x+x_menu_jeu,sprite[ordre[0]].y+y_menu_jeu,sprite[ordre[0]].dx,sprite[ordre[0]].dy);
     sprites[ordre[1]]->affiche(sprite[ordre[1]].d,sprite[ordre[1]].sance,sprite[ordre[1]].x+x_menu_jeu,sprite[ordre[1]].y+y_menu_jeu,sprite[ordre[1]].dx,sprite[ordre[1]].dy);
     sprites[ordre[2]]->affiche(sprite[ordre[2]].d,sprite[ordre[2]].sance,sprite[ordre[2]].x+x_menu_jeu,sprite[ordre[2]].y+y_menu_jeu,sprite[ordre[2]].dx,sprite[ordre[2]].dy);
     sprites[ordre[3]]->affiche(sprite[ordre[3]].d,sprite[ordre[3]].sance,sprite[ordre[3]].x+x_menu_jeu,sprite[ordre[3]].y+y_menu_jeu,sprite[ordre[3]].dx,sprite[ordre[3]].dy);
             
     terrain->affiche2(0+x_menu_jeu,0+y_menu_jeu);//affichage du terrain dernier couche
               
     // écrire x et y          
     char tx[256];
     char ty[256];
     sprintf(tx,"%d",sprite[0].x);
     sprintf(ty,"%d",sprite[0].y);
   	 txt->ecrire(tx,650,100+y_menu_jeu);
     txt->ecrire(ty,700,100+y_menu_jeu);            
     
  
     
//-------------texte  et contact avec les sprite----------------------
 if((vcollision_sprite[0]==false)&&(vcollision_sprite[1]==false)&&(vcollision_sprite[2]==false)&&(text_bulle==0)&&(action==1)) //si "action" est actionné dans le vite il est anulé
     action=0;   
 else if(mode_automatique==1){
      for(int i=0;i<=2;i++){
       if((vcollision_sprite[i]==true)&&(action==1)){   // teste si on est prés d'une presonne et si le bouton action est actioné
        if(sprite[i+1].action==0){
                   // positionne les personnages dans le bon sens pour qu'ils se parlent
                   if((sprite[i+1].y>sprite[0].y-10)&&(sprite[i+1].y<sprite[0].y+10)){ 
                    if(sprite[i+1].x>sprite[0].x){
                     sprite[0].sance=2;
                     sprite[i+1].sance=1;          
                    }
                    else {
                     sprite[0].sance=1;
                     sprite[i+1].sance=2;                  
                    }          
                   }
                   else if(sprite[i+1].y>sprite[0].y){
                    sprite[0].sance=0;
                    sprite[i+1].sance=3;
                   }
                   else {
                    sprite[0].sance=3;
                    sprite[i+1].sance=0;
                   }
                                                     
         T=100;
         txt->bulle_bas(x_menu_jeu,y_menu_jeu,parole[1+(i*2)],parole[2+(i*2)]);  //affiche le txt     
        }
        else {
             index_action=sprite[i+1].action;
             mode_automatique=0;
             action=0;
        }    
       }
      }      
 }
 else if((text_bulle==1||text_bulle==2)&&(action==1)){
     text_bulle=0;
     ligne++;
 }
 
 if(text_bulle==1)  //texte automatique
  txt->bulle_bas(x_menu_jeu,y_menu_jeu,parole[7],parole[8]); //affiche le txt
 else if(text_bulle==2){
 glColor3ub(255,255,255);
  txt->ecrire(parole[7],250+x_menu_jeu,300+y_menu_jeu);
  txt->ecrire(parole[8],250+x_menu_jeu,330+y_menu_jeu);
  glColor3ub(couleur,couleur,couleur);
}


     SDL_GL_SwapBuffers();
}


//------------------------------------------------------------gerée automatiquement les contole---------------------------------------------------------------------
void Jeu::Saction(char txt[256]){

    //variable interne
    char doc [40][256];
    char temps[256];
    int dep[15];
    //chargement des données (liste des actions)
 if(init_saction==1){ 
    FILE* fichier = NULL;
         fichier = fopen(txt, "r");

     if (fichier != NULL){ 
       int i=0;
         while (fgets(doc[i], 256, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
         {       
             i++;
         }
         fclose(fichier);
     }  
     init_saction=0;
     init_deplacement_saction=1;
 }
    //déplacement automatique
 else if((doc[ligne][0]=='d')){
     //petite initialisation avant le deplacement
     if(init_deplacement_saction==1){                        
      sscanf(doc[ligne], "%s %d %d %d %d %d",&dep[7],&dep[0],&dep[1],&dep[2],&dep[3],&dep[4]);

     if(dep[1]==0){
         if(doc[ligne][1]!='x'){
         sprite[dep[0]].x = dep[2];
         sprite[dep[0]].y = dep[4];
         }
          if(dep[2]>=dep[3])
           sprite[dep[0]].sance = 1;
          else
           sprite[dep[0]].sance = 2;
         }
         else {
          if(doc[ligne][1]!='x'){
          sprite[dep[0]].y = dep[2];
          sprite[dep[0]].x = dep[4];  
          }
          if(dep[2]>=dep[3])
           sprite[dep[0]].sance = 3;
          else
           sprite[dep[0]].sance = 0;   
         }


     init_deplacement_saction=0;
     }
     
     deplacement(dep[0],dep[1],dep[2],dep[3],dep[4]);//deplacement 
     
     //test: si le deplacement est termier en passe a la suivante
     if(((dep[3]+5>sprite[dep[0]].y)&&(dep[3]-5<sprite[dep[0]].y)&&(dep[1]==1))||((dep[3]+5>sprite[dep[0]].x)&&(dep[3]-5<sprite[dep[0]].x)&&(dep[1]==0))){
       ligne++;
       init_deplacement_saction=1;
     }
 }
    //texte automatique
 else if((doc[ligne][0]=='t')||(doc[ligne][1 ]=='t')){         
     sscanf(doc[ligne], "%s %s %s",&dep[7],&parole[7],&parole[8]);
     text_bulle=1;
     action = 0;
 } 
     //texte automatique
 else if((doc[ligne][0]=='e')){         
     sscanf(doc[ligne], "%s %s %s",&dep[7],&parole[7],&parole[8]);
     text_bulle=2;
     action =0;
 } 
     //asonbrire l'écran
 else if((doc[ligne][0]=='c')){         
     couleur = couleur -10;  
      if(couleur ==5)
     ligne++;
 }    
    //changer de map
else if((doc[ligne][0]=='r')||(doc[ligne][1]=='r')){     
     sscanf(doc[ligne],"%s %d",&dep[7],&dep[8]);
     moteur->rafrechiree(dep[8]);
 }
    //lancé la classe action
 else if((doc[ligne][0]=='s')||(doc[ligne][1]=='s')){
     sscanf(doc[ligne],"%s %s",&dep[7],&temps);
     moteur->action_start(temps);
     ligne++;
 }
      //chapitre suivient
 else if((doc[ligne][0]=='h')||(doc[ligne][1]=='h')){
     sscanf(doc[ligne],"%s %d %d",&dep[7],&dep[13],&dep[14]);
     moteur->chapitre_suivant(dep[13],dep[14]);
          init_saction=0;
     ligne=0;
     action=0;
     mode_automatique=1;
 }
     //fin des action
 else if((doc[ligne][0]=='f')||(doc[ligne][1]=='f')){
     init_saction=0;
     ligne=0;
     action=0;
     mode_automatique=1;
 }
 


}

//---------------------------------------------------------------------------Timer--------------------------------------------------------------------------------------
void Jeu::timer(){     
 if(Timer==true){
                
 if(mode_automatique==0)// automatique ou pas 
  Saction(lien_action[index_action]);
 else{     
      
  vcollision_sprite[0] = collision_sprite(1,0,0) ;
  vcollision_sprite[1] = collision_sprite(2,0,0) ;
  vcollision_sprite[2] = collision_sprite(3,0,0) ;               
     
  if(T==1){  
                        
   if (sprite[0].d==3)
    sprite[0].d=0;
   else 
    sprite[0].d++;

   //grand teste des collision entre l'hero et la carte
   if(sprite[0].sance==2){
    if((terrain->colision(sprite[0].x+36,6,sprite[0].y+34,6)==false)/*&&(terrain->colision(sprite[0].x+36,6,sprite[0].y+40,0)==false)*/){
     if((vcollision_sprite[0]==false)&&(vcollision_sprite[1]==false)&&(vcollision_sprite[2]==false)) 
      sprite[0].x=sprite[0].x+6;                                                                                                    
     else if((vcollision_sprite[0]==true)||(vcollision_sprite[1]==true)||(vcollision_sprite[2]==true)){
      if((collision_sprite(1,sprite[1].dx,0)==false)&&(collision_sprite(2,sprite[2].dx,0)==false)&&(collision_sprite(3,sprite[3].dx,0)==false))
       sprite[0].x=sprite[0].x+6;
     }
    }
   }
   else if(sprite[0].sance ==1){
    if((terrain->colision(sprite[0].x+4,6,sprite[0].y+34,0)==false)&&(terrain->colision(sprite[0].x+4,6,sprite[0].y+40,0)==false)){
     if((vcollision_sprite[0]==false)&&(vcollision_sprite[1]==false)&&(vcollision_sprite[2]==false)) 
      sprite[0].x=sprite[0].x-6;
     else if((vcollision_sprite[0]==true)||(vcollision_sprite[1]==true)||(vcollision_sprite[2]==true)){
      if((collision_sprite(1,-sprite[1].dx,0)==false)&&(collision_sprite(2,-sprite[2].dx,0)==false)&&(collision_sprite(3,-sprite[3].dx,0)==false))
       sprite[0].x=sprite[0].x-6;
     }
    }  
   }
   else if(sprite[0].sance==3){
    if((terrain->colision(sprite[0].x+10,0,sprite[0].y+28,6)==false)&&(terrain->colision(sprite[0].x+30,0,sprite[0].y+28,6)==false)){
     if((vcollision_sprite[0]==false)&&(vcollision_sprite[1]==false)&&(vcollision_sprite[2]==false)) 
      sprite[0].y=sprite[0].y-6;
     else if((vcollision_sprite[0]==true)||(vcollision_sprite[1]==true)||(vcollision_sprite[2]==true)){
      if((collision_sprite(1,0,-sprite[1].dy*1/3)==false)&&(collision_sprite(2,0,-sprite[2].dy*1/3)==false)&&(collision_sprite(3,0,-sprite[3].dy*1/3)==false))
       sprite[0].y=sprite[0].y-6;
     }
    }  
   }
   else if(sprite[0].sance ==0){
    if((terrain->colision(sprite[0].x+10,0,sprite[0].y+45,6)==false)&&(terrain->colision(sprite[0].x+30,0,sprite[0].y+45,6)==false)){
     if((vcollision_sprite[0]==false)&&(vcollision_sprite[1]==false)&&(vcollision_sprite[2]==false)) 
      sprite[0].y=sprite[0].y+6;
     else if((vcollision_sprite[0]==true)||(vcollision_sprite[1]==true)||(vcollision_sprite[2]==true)){
      if((collision_sprite(1,0,sprite[1].dy*1/3)==false)&&(collision_sprite(2,0,sprite[2].dy*1/3)==false)&&(collision_sprite(3,0,sprite[3].dy*1/3)==false))
       sprite[0].y=sprite[0].y+6;
     }  
    }
   }
   
  }
        
if(vcollision_sprite[0]==false)
deplacement(1,sprite[1].xouy,sprite[1].depar,sprite[1].arrive,sprite[1].sur);
if(vcollision_sprite[1]==false)
deplacement(2,sprite[2].xouy,sprite[2].depar,sprite[2].arrive,sprite[2].sur);
if(vcollision_sprite[2]==false)
deplacement(3,sprite[3].xouy,sprite[3].depar,sprite[3].arrive,sprite[3].sur);
 }
 }
}

//---------------------------------------------------------------------clavier----------------------------------------------------------------------------
bool Jeu::clavier_DOWN(SDLKey event){
    
     switch(event)
	{ 
                  
                   case SDLK_RIGHT:
                         if(mode_automatique==1){ 
                         sprite[0].sance = 2; 
                         T=1;
                         }
                         break;
                    case SDLK_LEFT:
                         if(mode_automatique==1){ 
                         sprite[0].sance = 1;
                         T=1;
                         }
                         break;
                    case SDLK_UP:
                         if(mode_automatique==1){ 
                         sprite[0].sance = 3;
                         T=1;
                         }
                         break;
                    case SDLK_DOWN:
                         if(mode_automatique==1){ 
                         sprite[0].sance = 0;
                         T=1;
                         }
                         break;
                    case SDLK_e:
                         if(mode_automatique==1){ 
                         if(mode_automatique==1)
                         mode_automatique=0;
                         else
                         mode_automatique= 1;
                         }
                         break;    
                    case SDLK_s:
                         if(action==1)
                         action=0;
                         else
                         action = 1;
                         break;
                    case SDLK_t:                     
                         //---------------------------zone test---------------------------    
                         FILE* fichier;
                         fichier = NULL;
                         fichier = fopen("test.txt", "w");;//lecture du chapitre
    
                         if (fichier != NULL)
                         {
                            fprintf(fichier,"%d %s %s %s",mode_automatique,lien_action[0],lien_action[1],lien_action[2]);
                            fclose(fichier);
                         }
                         //---------------------------zone test---------------------------
                         break;
                         default:
			             break;
	}    
}
bool Jeu::clavier_UP(SDLKey event){
     if(mode_automatique==1)
     switch(event)
	{
                   case SDLK_RIGHT: 
                        if(sprite[0].sance == 2){
                           T=100;
                           sprite[0].d=0;
                         }
                         break;
                    case SDLK_LEFT:
                         if(sprite[0].sance == 1){
                           T=0;
                          sprite[0].d=0;
                         }
                         break;
                    case SDLK_UP:
                         if(sprite[0].sance == 3){
                           T=0; 
                           sprite[0].d=0;
                         }
                         break;
                    case SDLK_DOWN:
                         if(sprite[0].sance == 0){
                           T=0;
                          sprite[0].d=0;
                         }
                         break;
                    case SDLK_s:
                        // action = 0;
                         break;
                    case SDLK_b:
                      
                         break;
		                 default:
			             break;
	} 
}         

//----------------------------------------------------------------------collision entre le hero et un autre sprite----------------------------------------------------------
bool Jeu::collision_sprite(int n,int plusx,int plusy){
     if((plusx+sprite[0].x+(sprite[0].dx*1/5)<=sprite[n].x+(sprite[n].dx*4/5))
     && (plusx+sprite[0].x+(sprite[0].dx*4/5)>=sprite[n].x+(sprite[0].dx*1/5))
     && (plusy+sprite[0].y+(sprite[0].dy*2/3)<=sprite[n].y+(sprite[n].dy))
     && (plusy+sprite[0].y+(sprite[0].dy)>=sprite[n].y+(sprite[0].dy*2/3)))
     return true;
     else
     return false;
}
/* if((plusx+sprite[0].x+(sprite[0].dx*1/5)<=sprite[n].x+(sprite[n].dx*4/5))
     && (plusx+sprite[0].x+(sprite[0].dx*4/5)>=sprite[n].x+(sprite[0].dx*1/5))
     && (plusy+sprite[0].y+(sprite[0].dy*1/4)<=sprite[n].y+(sprite[n].dy*3/4))
     && (plusy+sprite[0].y+(sprite[0].dy*3/4)>=sprite[n].y+(sprite[0].dy*1/4)))
     return true;
     else
     return false;*/
//----------------------------------------------------------------------deplacement d'un sprite d'un poin a un autre--------------------------------------------------------------------------------------------
void Jeu::deplacement(int n,int xouy,int debut,int arivee,int sur){ 
        
     
 if(xouy==0){
             
              if (sprite[n].d==3)
      sprite[n].d=0;
     else 
      sprite[n].d++; 
     
     if((sprite[n].sance==0)||(sprite[n].sance==3)){
       if(debut<=arivee)
      sprite[n].sance=2;
      else
      sprite[n].sance=1;
      }
      
      if(debut<=arivee){
     if(sprite[n].sance==2){
         if(sprite[n].x<=arivee){
           sprite[n].x=sprite[n].x+6;
         }
         else{
           sprite[n].sance=1;
           sprite[n].x=sprite[n].x-6;
         }
      }
      else if(sprite[n].sance==1){ 
        if(sprite[n].x>=debut){
        sprite[n].x=sprite[n].x-6;
        } 
        else{
          sprite[n].sance=2;
          sprite[n].x=sprite[n].x+6;
        }
      } 
      }
      else{
     if(sprite[n].sance==2){
         if(sprite[n].x<=debut){
           sprite[n].x=sprite[n].x+6;
         }
         else{
           sprite[n].sance=1;
           sprite[n].x=sprite[n].x-6;
         }
      }
      else if(sprite[n].sance==1){ 
        if(sprite[n].x>=arivee){
        sprite[n].x=sprite[n].x-6;
        }
        else{
          sprite[n].sance=2;
          sprite[n].x=sprite[n].x+6;
        }
      } 
      }
     
 }
 if(xouy==1){
             
     if (sprite[n].d==3)
      sprite[n].d=0;
     else 
      sprite[n].d++; 

                
     if((sprite[n].sance==2)||(sprite[n].sance==1)){
       if(debut<=arivee)
      sprite[n].sance=0;
      else
      sprite[n].sance=3;
      }
  if(debut<=arivee){        
     if(sprite[n].sance==0){
         if(sprite[n].y<=arivee){
           sprite[n].y=sprite[n].y+6;
         }
         else{
           sprite[n].sance=3;
           sprite[n].y=sprite[n].y-6;
         }
      }
      else if(sprite[n].sance==3){ 
        if(sprite[n].y>=debut){
        sprite[n].y=sprite[n].y-6;
        }
        else{
          sprite[n].sance=0;
          sprite[n].y=sprite[n].y+6;
        }
      }      
  }
  else{
          if(sprite[n].sance==0){
         if(sprite[n].y<=debut){
           sprite[n].y=sprite[n].y+6;
         }
         else{
           sprite[n].sance=3;
           sprite[n].y=sprite[n].y-6;
         }
      }
      else if(sprite[n].sance==3){ 
        if(sprite[n].y>=arivee){
        sprite[n].y=sprite[n].y-6;
        }
        else{
          sprite[n].sance=0;
          sprite[n].y=sprite[n].y+6;
        }
      }      
  
       
       }
  
 }
  if(xouy==2){
     sprite[n].sance=arivee;
     sprite[n].x = debut;
     sprite[n].y = sur;
 }
}


//renvois x
int Jeu::get_x()
{ return (sprite[0].x);}

//renvois y
int Jeu::get_y()
{ return sprite[0].y; }

 	
//renvois x
void Jeu::fix_x(int fx)
{   sprite[0].x=fx;}
//renvois y
void Jeu::fix_y(int fy)
{   sprite[0].y=fy; }

void Jeu::fix_sance(int fsance)
{   sprite[0].sance=fsance; }
