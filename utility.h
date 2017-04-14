#include "declaration.h"

void get_highscore(){
	FILE *in;
	in = fopen("highscore","rb");
	if(in==NULL){
		high_score = 0;
	}
	else{
		fread(&high_score,1,sizeof(long),in);
		fclose(in);
	}
}

void set_highscore(){
	if(game_score <= high_score)	return;
	high_score = game_score;
	FILE *out;
	out = fopen("highscore","wb");
	if(out==NULL)	return;
	fwrite(&high_score,1,sizeof(long),out);
	fclose(out);
}

//function to reset all game variables
void reset_variables(){
	//window dimensions
	windowWidth=580;
	windowHeight=580;
	GL_COX=10.0;
	GL_COY=10.0;
	FPS=60;

	//game variables
	game_state=1;
	ships_destroyed=0;
	game_score=0;
	get_highscore();

	//start screen variables
	start_screenX = -GL_COX+2.0;
	start_screenY = GL_COY-2.0;
	start_box_height = 16.0;
	start_box_width = 16.0;

	//pause screen variables
	pause_screenX = -GL_COX+5.5;
	pause_screenY = GL_COY-6.0;

	//end screen variables
	end_screenX = -GL_COX+2.0;
	end_screenY = GL_COY-2.0;
	end_box_height = 16.0;
	end_box_width = 16.0;

	//score board variables
	score_boardX = -GL_COX+0.2;
	score_boardY = GL_COY-0.2;
	score_board_height = 1.0;
	score_board_width = 3.0;

	//background variables
	BACKGROUND_REFRESH_DELAY = 200;
	k=0;
	points.clear();

	//spaceship variables
	spaceshipX = -9.0;
	spaceshipY = 0.0;

	//red alien variables
	red_pos.clear();
	rem1 = -10;
	ADD_RED_ALIENS = 70;
	num_of_red = 0;

	//blue alien variables
	blue_pos.clear();
	rem2 = -10;
	ADD_BLUE_ALIENS = 120;
	num_of_blue = 0;

	//green alien variables
	green_pos.clear();
	rem3 = -10;
	ADD_GREEN_ALIENS = 150;
	num_of_green = 0;

	//bullet variables
	bulletsL.clear(); 
	bulletsR.clear(); 
	bulletsC.clear();
}

//function to refresh background
void refresh_background(){
	points.clear();
	for( size_t i = 0; i < num_of_stars; ++i )
	{
		struct Point pt;
		pt.x = -GL_COX + (rand() % (int)(2*GL_COX));
		pt.y = -GL_COY + (rand() % (int)(2*GL_COY));
		pt.r = rand() % 255;
		pt.g = rand() % 255;
		pt.b = rand() % 255;
		pt.a = 255;
		points.push_back(pt);
	}
}

//func to draw circle
void draw_circle(float cirX, float cirY, float radius){
	glBegin(GL_LINE_LOOP);
	for(int i=-90; i<90; i++){
		float rad = i*3.14159/180;
		glVertex2f(cirX+cos(rad)*radius, cirY+sin(rad)*radius);
	}
	glEnd();
}

//func to add single bullet to screen when button is pressed
void add_bulletC(){
	struct bullet bC;
	bC.x = spaceshipX + (float)edgDistFront;
	bC.y = spaceshipY;
	bulletsC.push_back(bC);
}

//func to add double bullets to screen when button is pressed
void add_bulletLR(){
	struct bullet bL, bR;
	bL.x = spaceshipX + 0.25;
	bL.y = spaceshipY + 0.57;
	bulletsL.push_back(bL);
	bR.x = spaceshipX + 0.25;
	bR.y = spaceshipY - 0.57;
	bulletsR.push_back(bR);
}

//add red alienships to screen
void add_redaliens(){
	struct alienship red;
	num_of_red = rand() % (int)(MAX_RED_SHIPS);
	for(int i=0; i<num_of_red; i++){
		red.x = 11;
		red.y = -8.0 + rand() % (17);
		red_pos.push_back(red);
	}
}

//add blue alienships to screen
void add_bluealiens(){
	struct alienship blue;
	num_of_blue = rand() % (int)(MAX_BLUE_SHIPS);
	for(int i=0; i<num_of_blue; i++){
		blue.x = 11;
		blue.y = -8.0 + rand() % (17);
		blue_pos.push_back(blue);
	}
}

//add green alienships to screen
void add_greenaliens(){
	struct alienship green;
	num_of_green = rand() % (int)(MAX_GREEN_SHIPS);
	for(int i=0; i<num_of_green; i++){
		green.x = 11;
		green.y = -8.0 + rand() % (17);
		green_pos.push_back(green);
	}
}
