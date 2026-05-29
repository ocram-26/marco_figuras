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


int main(void){
  TurtleApp *app = turtleAppCreate(1200, 800, "Test Line");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t,400.0f, 400.0f);
  turtleLeft(t, 90);
  turtlePenDown(t);

  turtleSetColor(t, 255, 100, 0);
  turtleSetSpeed(t, 5.0f);

  //fractalTree(t, 100, 8);

  //levy(t, 200, 8);

  fractalTreeR1(t, 150, 7);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
