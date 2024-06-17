//-----include-----
#include "Main.h"



//surface principal
SDL_Surface *screen;

//objet moteur
Moteur *moteur = new Moteur();

 
//variable timer
int SDL_SetTimer(Uint32 interval, SDL_TimerCallback callback);
typedef Uint32 (*SDL_TimerCallback)(Uint32 interval);
SDL_TimerID timer; /* Variable pour stocker le numéro du Timer */

//fonction timer
Uint32 Timer(Uint32 intervalle, void* param){   
    moteur->timer();/*timer de la classe Jeu_rpg*/      
    return intervalle;
}


//-----MAIN-----
int main(int argc, char **argv)
{
    SDL_Event event;
        
    //variable       
    int done = 0;
    int fps, last,now;
    int i;
    static char titleBar[25] = {0};
    FPSmanager manager;


    //Initialisation
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER)!=0) {
        cerr << "Probleme pour initialiser SDL: " << SDL_GetError() << endl;
        return EXIT_FAILURE;
    }    
    //Mettre un titre à la fenêtre
    SDL_WM_SetCaption(".::RPG math::. | bienvenu !!  01.10.07", NULL);
    
    //Double tampon
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

    //Ouvrir une fenetre
    screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_OPENGL);
    if(screen==NULL)
       moteur->fin();



    //  ------------------------2D------------------------------
    // Mettre le systeme de coordonnees a zero avant de modifier
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Mettre la bonne perspective
   // glOrtho(0,WIDTH,HEIGHT,0,-1,1);  
   //glOrtho(0, 1000, 0, 800, -1, 1);
  glOrtho(0,800,600,0,-1,1);  
   
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();            
    
    
    
    //  ------------------------3D------------------------------
    /*glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(70,(double)WIDTH/HEIGHT,1,1000);
    
    glEnable(GL_DEPTH_TEST);
    
    //glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
    
    gluLookAt(3,4,2,0,0,0,0,0,1);
    
    //glRotated(0,0,0,1);
    */ 
    
    //initialisation de son
     FSOUND_Init(44100, 32, 0);                                
  
    //initialisation framerate 
    SDL_initFramerate(&manager);

    //Mettre le nombre d'images par secondes souhaite
    SDL_setFramerate(&manager,100);
    
    //initialisation des variables pour le calcule du fps 
    last = SDL_GetTicks()/1000;
    fps = 0;
    
    //initialisation su son
    FSOUND_Init(44100, 32, 0);
    
    //demarrer le timer
    timer = SDL_AddTimer(100, Timer, NULL );
    
   
    //initialisation moteur
    moteur->init();
  
    //-------------------------------  .:fin de la zone teste:.  ------------------------------------------
    
    //Boucle generale
    while(moteur->estFini()==false)   
    {
        //Traiter les evenements
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    moteur->fin();
                    break;
                    // evenement quand une touche est appuillée
                case SDL_KEYDOWN:
                     
                     //pleine ecran 
                    if(event.key.keysym.sym==SDLK_x){
                     screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_OPENGL|SDL_FULLSCREEN);
                     moteur->init();         
                     }
                    if(event.key.keysym.sym==SDLK_y){ 
                    SDL_SetVideoMode(event.resize.w, event.resize.h, 32, SDL_OPENGL | SDL_RESIZABLE);
                    glViewport(0, 0, (GLsizei) event.resize.w, (GLsizei) event.resize.h);
                    glMatrixMode(GL_PROJECTION);
                    glLoadIdentity();
                    glOrtho(0,700,1000,0,-1,1);  
                    glMatrixMode(GL_MODELVIEW);
                    glLoadIdentity();
                    /* screen = SDL_SetVideoMode(WIDTH+500, HEIGHT+500, 32, SDL_OPENGL);       
                     moteur->init(); */                                 
                     }                                                                                                                             
                    moteur->clavier_DOWN(event.key.keysym.sym);
                    break;
                    //evenement quand une touche est lachée
                    case SDL_KEYUP:
                    moteur->clavier_UP(event.key.keysym.sym);
                    break;
                default:
                    break;
            }    
        }
        
        
        //calcule du fps
        fps++;
        now = SDL_GetTicks()/1000;
        
        if(now!=last)
        {
                     
            sprintf(titleBar, ".::RPG math::. | FPS: %d",fps/(now-last));
            SDL_WM_SetCaption (titleBar, NULL);
            
            cout << "FPS : " <<fps/(now-last)<< endl;
            
            last = now;
            
            fps = 0;
        }
        SDL_framerateDelay(&manager);
        
        
        //affichage du jeu
        moteur->affiche();
        
        
    }

    SDL_Quit();
    FSOUND_Close();

    (void) argc;
    (void) argv;
    return EXIT_SUCCESS;
}
