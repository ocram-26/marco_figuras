#include "../turtlec.h"

void fractalTree(Turtle *turtle, float length, int depth){
    if(depth == 0 || length < 5)
        return;
    turtleForward(turtle, length);

    turtleLeft(turtle, 20);
    fractalTree(turtle, length * 0.6, depth - 1);
    
    turtleRight(turtle, 40);
    fractalTree(turtle, length * 0.6, depth - 1);

    turtleLeft(turtle, 20);
    turtleBackward(turtle, length);
}

int main(void){
  TurtleApp *app = turtleAppCreate(1200, 800, "Test Line");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t,300.0f, 400.0f);
  turtlePenDown(t);

  turtleSetColor(t, 255, 100, 0);
  turtleSetSpeed(t, 5.0f);

  fractalTree(t, 100, 7);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
