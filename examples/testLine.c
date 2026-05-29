#include <math.h>
#include "../turtlec.h"

void fractalTree(Turtle *turtle, float length, int depth){
  if(depth == 0 || length < 5)
        return;
    
  turtleForward(turtle, length);

  turtleLeft(turtle, 20);
  fractalTree(turtle, length * 0.6, depth - 1);
    
  turtleRight(turtle, 40);
  fractalTree(turtle, length * 0.6, depth - 1);

  if(depth > 5)
    turtleSetColor(turtle, 120, 70, 20);
  else
    turtleSetColor(turtle, 0, 200, 0);

  turtleLeft(turtle, 20);
  turtleBackward(turtle, length);
}

void levy(Turtle *turtle, int length, int depth){
  if(depth == 0){
    turtleForward(turtle, length);
    return;
  }

  turtleRight(turtle, 45);
  levy(turtle, length / sqrt(2), depth - 1);

  turtleLeft(turtle, 90);
  levy(turtle, length / sqrt(2), depth - 1);

  turtleRight(turtle, 45);
}

void fractalTreeR1(Turtle *turtle, float length, int depth){
  if(depth == 0 || length < 5)
        return;
    
  turtleForward(turtle, length);

  turtleLeft(turtle, 55);
  fractalTreeR1(turtle, length * 0.6, depth - 1);
    
  turtleRight(turtle, 55);
  fractalTreeR1(turtle, length * 0.6, depth - 1);
  
  turtleRight(turtle, 55);
  fractalTreeR1(turtle, length * 0.6, depth - 1);

  if(depth > 5)
    turtleSetColor(turtle, 120, 70, 20);
  else
    turtleSetColor(turtle, 0, 200, 0);

  turtleLeft(turtle, 55);
  turtleBackward(turtle, length);
}

void fractalTreeR2(Turtle *turtle, float length, int depth){
  if(depth == 0 || length < 2)
        return;
    
  turtleForward(turtle, length);

  turtleLeft(turtle, 35);
  fractalTreeR2(turtle, length * 0.4, depth - 1);
    
  turtleRight(turtle, 70);
  fractalTreeR2(turtle, length * 0.7, depth - 1); 

  turtleLeft(turtle, 35);
  turtleBackward(turtle, length);
}

int main(void){
  TurtleApp *app = turtleAppCreate(1200, 800, "Test Line");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t,500.0f, 600.0f);
  turtleLeft(t, 90);
  turtlePenDown(t);

  turtleSetColor(t, 30, 10, 210);
  turtleSetSpeed(t, 5.0f);

  //fractalTree(t, 100, 8);

  //levy(t, 200, 8);

  //fractalTreeR1(t, 150, 7);

  fractalTreeR2(t, 150, 5);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
