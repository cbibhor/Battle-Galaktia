#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

#ifdef __WIN64
    #include <windows.h>
    #include<GL/freeglut.h>
#elif __WIN32
    #include <windows.h>
    #include<GL/freeglut.h>
#elif __APPLE_CC__
    #include <GLUT/freeglut.h>
#elif __linux
    #include<GL/freeglut.h>
#elif __unix
    #include<GL/freeglut.h>
#endif

struct Point
{
	float x, y;
	unsigned char r, g, b, a;
};

struct bullet{
	float x, y;
};

struct alienship{
	float x,y;
};

struct Circle{
	float x, y;
};

#include "declaration.h"
#include "utility.h"
#include "moveutility.h"
#include "draw.h"
#include "callback.h"

//window dimensions
int windowWidth;
int windowHeight;
float GL_COX;
float GL_COY;
int FPS;

//game variables
int game_state;
int ships_destroyed;
long game_score, high_score;

//start screen variables
float start_screenX;
float start_screenY;
float start_box_height;
float start_box_width;

//pause screen variables
float pause_screenX;
float pause_screenY;

//end screen variables
float end_screenX;
float end_screenY;
float end_box_height;
float end_box_width;

//score board variables
float score_boardX;
float score_boardY;
float score_board_height;
float score_board_width;

//background variables
int BACKGROUND_REFRESH_DELAY;
int k;
std::vector<struct Point> points;

//spaceship variables
float spaceshipX;
float spaceshipY;

//red alien variables
std::vector<struct alienship> red_pos;
int rem1;
int ADD_RED_ALIENS;
int num_of_red;

//blue alien variables
std::vector<struct alienship> blue_pos;
int rem2;
int ADD_BLUE_ALIENS;
int num_of_blue;

//green alien variables
std::vector<struct alienship> green_pos;
int rem3;
int ADD_GREEN_ALIENS;
int num_of_green;

//bullet variables
std::vector<struct bullet> bulletsL, bulletsR, bulletsC;


  int main(int argc, char** argv) 
  {
	reset_variables();
    //initialise GLUT
	glutInit(&argc, argv);
    	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(windowWidth, windowHeight); 
    	glutInitWindowPosition(350, 50);
    	glutCreateWindow("Battle Galaktia");
	//register callback functions
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard_func);
	glutKeyboardUpFunc(keyboard_up_func);
	glutSpecialFunc(special_func);
	glutTimerFunc(0,Timer,0);

	//enter event processing loop
    	glutMainLoop();
  }