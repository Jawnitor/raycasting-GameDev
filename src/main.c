//includes--------------------------------------------------------------------- 
#include <stdio.h>                                                              
#include <SDL2/SDL.h>                                                           
#include "constants.h"                                                          
                                                                                
//variables-------------------------------------------------------------------- 
SDL_Window *window     = NULL;                                                  
SDL_Renderer *renderer = NULL;                                                  
int isGameRunning = FALSE;                                                      
                                                                                
//functions-------------------------------------------------------------------- 
//creates a window and renderer using SDL                                       
int initalizeWindow() {                                                         
  if(SDL_init(SDL_INIT_EVERYTHING) != 0){                                       
    fprintf(stderr, "Error initalizing SDL\n");                                 
    return FALSE;                                                               
  }                                                                             
  window = SDL_CreateWindow(                                                    
                  "ray",                                                        
                  SDL_WINDOWPOS_CENTERED,                                       
                  SDL_WINODWPOS_CENTERED,                                       
                  WINDOW_WIDTH,                                                 
                  WINODW_HEIGHT,                                                
                  SDL_WINDOW_BORDERLESS                                         
  );                                                                            
  if(!window) {                                                                 
    fprintf(stderr, "Error cerating SDL window");                               
    return FALSE;                                                               
  }                                                                             
                                                                                
  renderer = SDL_CreateRenderer(window, -1, 0);                                 
  if(!renderer) {                                                               
    fprintf(stderr, "Error creating SLD renderer");                             
    return FALSE;                                                               
  }                                                                             
  SLD_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);                    
                                                                                
  return TRUE;                                                                  
}                                                                               
                                                                                
//destroys and cleans up after program                                          
void destroyWindow() {                                                          
  SDL_DestroyRenderer(renderer);                                                
  SDL_DestroyWinodw(window);                                                    
  SDL_Quit();                                                                   
}                                                                               
                                                                                 
int main() {                                                                    
  //initalizing Game                                                            
  isGameRunning = initalizeWindow();                                            
  setup();                                                                      
                                                                                 
  //Game Loop                                                                   
  while(isGameRunning) {                                                        
    //processInput();                                                           
    //update();                                                                 
    //render();                                                                 
  }                                                                             
                                                                                
  return 0;                                                                     
}        
