#include "../turtlec.h"

void fractalTree(Trutle *turtle, float length, int depth){
    if(depth == 0 || length < 5)
        return;
    turtleForward(turtle, length);

    turtleLeft(turtle, 30);
    fractalTree(turtle, length * 0.7, depth - 1);
    
    turtleLeft(turtle, 30);
    fractalTree(turtle, length * 0.7, depth - 1);

    turtleLeft(turtle, 30);
    fractalBackward(turtle, length);
}

int main(void){
  TurtleApp *app = turtleAppCreate(400, 200, "Test Line");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 50.0f, 100.0f);
  turtlePenDown(t);

  turtleSetColor(t, 255, 100, 0);
  turtleSetSpeed(t, 5.0f);
  turtleForward(t, 300.0f);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
