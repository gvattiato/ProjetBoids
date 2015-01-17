//****************************************************************************
//
//
//
//****************************************************************************
 
 
 
 
// ===========================================================================
//                               Include Libraries
// ===========================================================================
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>




// ===========================================================================
//                             Include Project Files
// ===========================================================================

#include "Sky.h"
#include "bwindow.h"



// ===========================================================================
//                         Declare Miscellaneous Functions
// ===========================================================================




// ===========================================================================
//                                   The Main
// ===========================================================================
int main(int argc, char* argv[])
{
//______________________________________________
//    Creation of obstacles

      int n_obstacles = 2;
      Vector obstacle1(250,200);
      Vector obstacle2(450,300);

      Vector* obstacles = new Vector[n_obstacles];
      obstacles[0] = obstacle1;      
      obstacles[1] = obstacle2;      

//______________________________________________



//______________________________________________
//    Creation of a flock of preys.

      int size = 20;
      Prey* preys = new Prey[size];
      for (int i=0; i<size; i++) 
      {
      // Positions
        Vector position(100,100+8*i);  
      // Speeds
        Vector speed(10,3);
      // Creation of each prey
        float radius = 70;
        float contact = 30;

        Prey p(radius, contact, position, speed); 
 
      // Allocation of preys in table.
        preys[i] = p;
      }


      int i;
      float x_pos=0;
      float y_pos=0;
//______________________________________________
 
        Vector v1(0,0);
        Vector v2(0,0);
        Vector v3(0,0);

  
  /*for (i=0; i<size; i++)
      {
        Prey p(300, 100, position*(i+1), speed*(i+2)); // Creation of a prey with r=3, c=1, position = position*1, speed = speed.
        preys[i] = p;
        //printf(" pos = (%lg,%lg)", preys[i].getPosition().getX(), preys[i].getPosition().getY());
        //printf("   speed%d = (%lg,%lg)\n\n", i+1, preys[i].getSpeed().getX(), preys[i].getSpeed().getY());
      }
*/

    int l = 850;
    int h = 600;
    bwindow win(l,h);
    printf("%d\n",win.init());
    win.map();
    for(;;)
    {
      int ev = win.parse_event();
        switch(ev)
        {
          case BKPRESS :
            printf("keypressed\n"); 
            printf("key : %s\n",win.get_lastkey());
          break;
          case BBPRESS:
            printf("buttonpressed\n"); break;
          case BEXPOSE:
            printf("expose\n"); break;
          case BCONFIGURE:
            printf("configure\n"); break;
        }

      //win.draw_text(10,15,0x0,"Cool window",strlen("Cool window"));
      


      win.draw_fsquare(0,0,l,h, 0x99FFFF);
      for (i=0; i<size; i++)
      {
        //printf("\nFor prey n°%d\n", i);
        float dt = 0.1;
        Sky my_sky(preys, size);


        x_pos = preys[i].getPosition().getX();
        y_pos = preys[i].getPosition().getY();

        win.draw_fsquare(x_pos, y_pos, x_pos+3, y_pos+3, 0xCC0000);
        win.draw_fsquare(248, 198, 253, 203, 0x000000);
        win.draw_fsquare(445, 295, 455, 305, 0x000000);



        float O = 0.9; // The smaller O, the more birds bounce off obstacles
        float K = 2; // With K high, the movements are more organised but birds can get lost

        v1 = my_sky.alignment(i, K);
        v2 = my_sky.centerMass(i, K);
        v3 = my_sky.tooNear(i, K, O, obstacles, n_obstacles);
        
        Vector wind = my_sky.wind(i,l,h);

        preys[i].updateSpeed(dt, 0.9, 0.2, 1.7, 2.5, v1, v2, v3, wind); 
        preys[i].updatePosition(dt);

      }
      
      printf("\n\n");
      usleep(15000);
      

        

    }



  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================




