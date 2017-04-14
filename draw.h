#include "declaration.h"

void draw_background(){
	k = (k+1) % BACKGROUND_REFRESH_DELAY;
	if(k==1)	refresh_background();
  
	glColor3ub( 255, 255, 255 );
    glEnableClientState( GL_VERTEX_ARRAY );
    glEnableClientState( GL_COLOR_ARRAY );
    glVertexPointer( 2, GL_FLOAT, sizeof(Point), &points[0].x );
    glColorPointer( 4, GL_UNSIGNED_BYTE, sizeof(Point), &points[0].r );
    glPointSize( 1.0 );
    glDrawArrays( GL_POINTS, 0, points.size() );
    glDisableClientState( GL_VERTEX_ARRAY );
    glDisableClientState( GL_COLOR_ARRAY );
}

void draw_spaceship(){
	glPushMatrix();
	glTranslatef(spaceshipX, spaceshipY, 0.0f);

	glBegin(GL_QUADS);
		//center body
		glColor3f(1.0f,0.5f,0.0f);
		glVertex2f(+0.0, +0.3);
		glVertex2f(+0.0, -0.3);
		glVertex2f(+0.4, -0.3);
		glVertex2f(+0.4, +0.3);
		//front body
		glColor3f(1.0f,0.5f,0.0f);
		glVertex2f(+0.4, +0.3);
		glVertex2f(+0.4, -0.3);
		glVertex2f(+1.0, -0.05);
		glVertex2f(+1.0, +0.05);
		//left engine
		glColor3f(1.0f,0.0f,0.0f);
		glVertex2f(-0.1, +0.2);
		glVertex2f(-0.1, +0.05);
		glVertex2f(+0.2, +0.05);
		glVertex2f(+0.2, +0.2);
		//right engine
		glColor3f(1.0f,0.0f,0.0f);
		glVertex2f(-0.1, -0.2);
		glVertex2f(-0.1, -0.05);
		glVertex2f(+0.2, -0.05);
		glVertex2f(+0.2, -0.2);
		//left wing
		glColor3f(0.0f,0.0f,1.0f);
		glVertex2f(-0.1, +0.6);
		glVertex2f(-0.0, +0.3);
		glVertex2f(+0.4, +0.3);
		glVertex2f(+0.1, +0.6);
		//left wing missile
		glColor3f(0.0f,0.0f,1.0f);
		glVertex2f(+0.1, +0.6);
		glVertex2f(+0.1, +0.55);
		glVertex2f(+0.3, +0.55);
		glVertex2f(+0.3, +0.6);
		//right wing
		glColor3f(0.0f,0.0f,1.0f);
		glVertex2f(-0.1, -0.6);
		glVertex2f(-0.0, -0.3);
		glVertex2f(+0.4, -0.3);
		glVertex2f(+0.1, -0.6);
		//right wing missile
		glColor3f(0.0f,0.0f,1.0f);
		glVertex2f(+0.1, -0.6);
		glVertex2f(+0.1, -0.55);
		glVertex2f(+0.3, -0.55);
		glVertex2f(+0.3, -0.6);
		//window
		glColor3f(0.0f,0.0f,0.0f);
		glVertex2f(+0.37, +0.15);
		glVertex2f(+0.37, -0.15);
		glVertex2f(+0.5, -0.15);
		glVertex2f(+0.5, +0.15);
	glEnd();

	//circle
	glColor3f(0.0f,0.0f,1.0f);
	draw_circle(0.35,0,0.2);
	//line
	glBegin(GL_LINES);
		glColor3f(1.0f,1.0f,0.0f);
		glVertex2f(+0.60, +0.0);
		glVertex2f(+1.0, +0.0);
	glEnd();

	glPopMatrix();
}

void draw_redalien(float alienX, float alienY){
	glPushMatrix();
	glTranslatef(alienX, alienY, 0.0f);

	glBegin(GL_QUADS);
		//wings
		glColor3f(0.0f,0.0f,0.8f);
		glVertex2f(0.2, 0.0);
		glVertex2f(0.67, -0.5);
		glVertex2f(0.67, 0.5);
		glVertex2f(0.2, 0.0);
		//body
		glColor3f(0.8f,0.0f,0.0f);
		glVertex2f(0.0, 0.15);
		glVertex2f(0.0, -0.15);
		glVertex2f(0.7, -0.15);
		glVertex2f(0.7, 0.15);
		//front
		glColor3f(0.8f,0.0f,0.0f);
		glVertex2f(-0.2, 0.05);
		glVertex2f(-0.2, -0.05);
		glVertex2f(0.0, -0.15);
		glVertex2f(0.0, 0.15);
		//window
		glColor3f(0.0f,0.0f,0.0f);
		glVertex2f(0.2, 0.1);
		glVertex2f(0.2, -0.1);
		glVertex2f(0.3, -0.1);
		glVertex2f(0.3, 0.1);
	glEnd();

	glPopMatrix();
}

void draw_bluealien(float alienX, float alienY){
	glPushMatrix();
	glTranslatef(alienX, alienY, 0.0f);

	glBegin(GL_QUADS);
		//wings
		glColor3f(0.8f,0.8f,0.0f);
		glVertex2f(-0.2, 0.0);
		glVertex2f(0.7, -0.5);
		glVertex2f(0.7, 0.5);
		glVertex2f(-0.2, 0.0);
		//body
		glColor3f(0.f,0.0f,0.8f);
		glVertex2f(0.0, 0.15);
		glVertex2f(0.0, -0.15);
		glVertex2f(0.7, -0.15);
		glVertex2f(0.7, 0.15);
		//front
		glColor3f(0.0f,0.0f,0.8f);
		glVertex2f(-0.2, 0.05);
		glVertex2f(-0.2, -0.05);
		glVertex2f(0.0, -0.15);
		glVertex2f(0.0, 0.15);
		//window
		glColor3f(0.0f,0.0f,0.0f);
		glVertex2f(0.2, 0.1);
		glVertex2f(0.2, -0.1);
		glVertex2f(0.3, -0.1);
		glVertex2f(0.3, 0.1);
	glEnd();

	glPopMatrix();
}

void draw_greenalien(float alienX, float alienY){
	glPushMatrix();
	glTranslatef(alienX, alienY, 0.0f);

	glBegin(GL_QUADS);
		//back wings
		glColor3f(0.8f,0.5f,0.0f);
		glVertex2f(0.4, 0.5);
		glVertex2f(0.4, -0.5);
		glVertex2f(0.7, -0.15);
		glVertex2f(0.7, 0.15);
		//front wings
		glColor3f(0.f,0.0f,0.8f);
		glVertex2f(0.0, 0.4);
		glVertex2f(0.0, -0.4);
		glVertex2f(0.15, -0.4);
		glVertex2f(0.15, 0.4);
		//front missiles
		glColor3f(0.f,0.0f,0.8f);
		glVertex2f(-0.2, 0.3);
		glVertex2f(-0.2, 0.25);
		glVertex2f(0.15, 0.25);
		glVertex2f(0.15, 0.3);

		glColor3f(0.f,0.0f,0.8f);
		glVertex2f(-0.2, -0.3);
		glVertex2f(-0.2, -0.25);
		glVertex2f(0.15, -0.25);
		glVertex2f(0.15, -0.3);
		//body
		glColor3f(0.0f,0.5f,0.0f);
		glVertex2f(0.0, +0.15);
		glVertex2f(0.0, -0.15);
		glVertex2f(0.7, -0.15);
		glVertex2f(0.7, +0.15);
		//front
		glColor3f(0.0f,0.5f,0.0f);
		glVertex2f(-0.2, 0.0);
		glVertex2f(0.0, -0.1);
		glVertex2f(0.0, 0.1);
		glVertex2f(-0.2, 0.0);
		//window
		glColor3f(0.0f,0.0f,0.0f);
		glVertex2f(0.3, 0.08);
		glVertex2f(0.3, -0.08);
		glVertex2f(0.4, -0.08);
		glVertex2f(0.4, 0.08);
	glEnd();

	glPopMatrix();
}

void draw_aliens(){
	rem1 = (rem1+1) % ADD_RED_ALIENS;
	if(rem1==0)		add_redaliens();
	rem2 = (rem2+1) % ADD_BLUE_ALIENS;
	if(rem2==1)		add_bluealiens();
	rem3 = (rem3+1) % ADD_GREEN_ALIENS;
	if(rem3==0)		add_greenaliens();

	for(int i=0; i<red_pos.size(); i++)
		draw_redalien(red_pos[i].x, red_pos[i].y);
	for(int i=0; i<blue_pos.size(); i++)
		draw_bluealien(blue_pos[i].x, blue_pos[i].y);
	for(int i=0; i<green_pos.size(); i++)
		draw_greenalien(green_pos[i].x, green_pos[i].y);
}

void draw_bulletsLR(){
	glPointSize(3.0);
	glColor3f(0.0f,0.0f,1.0f);
	glBegin(GL_POINTS);
		for(int i=0; i<bulletsL.size(); i++)
			glVertex2f(bulletsL[i].x, bulletsL[i].y);
		for(int i=0; i<bulletsR.size(); i++)
			glVertex2f(bulletsR[i].x, bulletsR[i].y);
	glEnd();
}

void draw_bulletsC(){
	glPointSize(3.0);
	glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POINTS);
		for(int i=0; i<bulletsC.size(); i++)
			glVertex2f(bulletsC[i].x, bulletsC[i].y);
	glEnd();
}

void draw_score(){
	if(game_score == 0){
		glutStrokeCharacter(GLUT_STROKE_ROMAN, '0');
		return;
	}
	int t = game_score;
	std::vector<int> v;
	while(t>0){
		v.push_back(t%10);
		t /= 10;
	}
    for(int i=v.size()-1; i>=0; i--)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, v[i]+'0');
    }
}

void draw_score_board(){
	glPushMatrix();
	glTranslatef(score_boardX, score_boardY, 0.0f);
	glBegin(GL_LINE_LOOP);
		glLineWidth(2.0);
		glColor3f(2.0,0.0,0.0);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.0f, -score_board_height);
		glVertex2f(score_board_width, -score_board_height);
		glVertex2f(score_board_width, 0.0f);
	glEnd();

	glLineWidth(2.0);
	glColor3f(0.0f,2.0f,0.0f);
	glPushMatrix();
	glTranslatef(0.2f, -0.7f, 0.0f);
	glScalef(0.005,0.005,0.005);
	draw_score();
	glPopMatrix();

	glPopMatrix();
}

void draw_start_text(){
	std::string str1 = "BATTLE GALAKTIA";
	std::string str2 = "Destroy the enemy ships";
	std::string str3 = "To play, press enter...";
	std::string str4 = "CONTROLS";
	std::string str5 = "Up : W / Arrow Key Up";
	std::string str6 = "Backward : A / Arrow Key Left";
	std::string str7 = "Down : S / Arrow Key Down";
	std::string str8 = "Forward : D / Arrow Key Right";
	std::string str9 = "Single Fire : Space Key";
	std::string str10 = "Double Fire : B";
	std::string str11 = "Pause : P";
	std::string str12 = "Resume : R        Quit : Esc";
	//title
	glLineWidth(2.0);
	glPushMatrix();
	glColor3f(0.863f,0.078f,0.235f);
	glTranslatef(2.3f, -2.0f, 0.0f);
	glScalef(0.01,0.01,0.01);
	for(int i=0; i<str1.length(); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str1[i]);
	glPopMatrix();
	glLineWidth(1.0);
	//subtitle
	glPushMatrix();
	glColor3f(0.587f,0.0f,0.827f);
	glTranslatef(3.6f, -3.5f, 0.0f);
	glScalef(0.0055, 0.0055, 0.0055);
	for(int i=0; i<str2.length(); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str2[i]);
	glPopMatrix();
	//to play
	glPushMatrix();
	glColor3f(1.0f,0.803f,0.0f);
	glTranslatef(3.8f, -5.0f, 0.0f);
	glScalef(0.006, 0.006, 0.006);
	for(int i=0; i<str3.length(); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str3[i]);
	glPopMatrix();
	//controls title
	glPushMatrix();
	glColor3f(0.184f,0.310f,0.310f);
	glTranslatef(6.0f, -7.0f, 0.0f);
	glScalef(0.005, 0.005, 0.005);
	for(int i=0; i<str4.length(); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str4[i]);
	glPopMatrix();
	//control 1
	glPushMatrix();
	glColor3f(0.184f,0.310f,0.310f);
	glTranslatef(2.0f, -8.0f, 0.0f);
	glScalef(0.005, 0.005, 0.005);
	for(int i=0; i<str5.length(); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str5[i]);
	glPopMatrix();
	//control 2
	glPushMatrix();
	glColor3f(0.184f,0.310f,0.310f);
	glTranslatef(2.0f, -9.0f, 0.0f);
	glScalef(0.005, 0.005, 0.005);
	for(int i=0; i<str6.length(); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str6[i]);
	glPopMatrix();
	//control 3
	glPushMatrix();
	glColor3f(0.184f,0.310f,0.310f);
	glTranslatef(2.0f, -10.0f, 0.0f);
	glScalef(0.005, 0.005, 0.005);
	for(int i=0; i<str7.length(); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str7[i]);
	glPopMatrix();
	//control 4
	glPushMatrix();
	glColor3f(0.184f,0.310f,0.310f);
	glTranslatef(2.0f, -11.0f, 0.0f);
	glScalef(0.005, 0.005, 0.005);
	for(int i=0; i<str8.length(); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str8[i]);
	glPopMatrix();
	//control 5
	glPushMatrix();
	glColor3f(0.184f,0.310f,0.310f);
	glTranslatef(2.0f, -12.0f, 0.0f);
	glScalef(0.005, 0.005, 0.005);
	for(int i=0; i<str9.length(); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str9[i]);
	glPopMatrix();
	//control 6
	glPushMatrix();
	glColor3f(0.184f,0.310f,0.310f);
	glTranslatef(2.0f, -13.0f, 0.0f);
	glScalef(0.005, 0.005, 0.005);
	for(int i=0; i<str10.length(); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str10[i]);
	glPopMatrix();
	//control 7
	glPushMatrix();
	glColor3f(0.184f,0.310f,0.310f);
	glTranslatef(2.0f, -14.0f, 0.0f);
	glScalef(0.005, 0.005, 0.005);
	for(int i=0; i<str11.length(); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str11[i]);
	glPopMatrix();
	//control 8
	glPushMatrix();
	glColor3f(0.184f,0.310f,0.310f);
	glTranslatef(2.0f, -15.0f, 0.0f);
	glScalef(0.005, 0.005, 0.005);
	for(int i=0; i<str12.length(); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str12[i]);
	glPopMatrix();
}

void draw_start_screen(){
	glPushMatrix();
	glTranslatef(start_screenX, start_screenY, 0.0f);
	glBegin(GL_LINE_LOOP);
		glLineWidth(2.0);
		glColor3f(0.0,0.0,2.0);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.0f, -start_box_height);
		glVertex2f(start_box_width, -start_box_height);
		glVertex2f(start_box_width, 0.0f);
	glEnd();

	draw_start_text();

	glPopMatrix();
}

void draw_highscore(){
	if(high_score == 0){
		glutStrokeCharacter(GLUT_STROKE_ROMAN, '0');
		return;
	}
	int t = high_score;
	std::vector<int> v;
	while(t>0){
		v.push_back(t%10);
		t /= 10;
	}
    for(int i=v.size()-1; i>=0; i--)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, v[i]+'0');
    }
}

void draw_end_text(){
	std::string str1 = "Game Over";
	std::string str2 = "Score : ";
	std::string str3 = "Highscore : ";
	std::string str4 = "Play Again : Press Enter";
	std::string str5 = "Quit : Press Esc";
	std::string str6 = "DEVELOPED BY";
	std::string str7 = "BIBHOR CHAUHAN";
	//game over title
	glLineWidth(2.0);
	glPushMatrix();
	glColor3f(1.0f,0.0f,0.0f);
	glTranslatef(4.5f, -2.0f, 0.0f);
	glScalef(0.01,0.01,0.01);
	for(int i=0; i<str1.length(); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str1[i]);
	glPopMatrix();
	glLineWidth(1.0);
	//score title
	glPushMatrix();
	glColor3f(0.8f,0.8f,0.0f);
	glTranslatef(3.8f, -4.0f, 0.0f);
	glScalef(0.008,0.008,0.008);
	for(int i=0; i<str2.length(); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str2[i]);
	draw_score();
	glPopMatrix();
	//highscore title
	glPushMatrix();
	glColor3f(0.8f,0.8f,0.0f);
	glTranslatef(3.8f, -6.0f, 0.0f);
	glScalef(0.008,0.008,0.008);
	for(int i=0; i<str3.length(); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str3[i]);
	draw_highscore();
	glPopMatrix();
	//play again title
	glPushMatrix();
	glColor3f(0.275f, 0.510f, 0.706f);
	glTranslatef(3.7f, -8.0f, 0.0f);
	glScalef(0.005,0.005,0.005);
	for(int i=0; i<str4.length(); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str4[i]);
	glPopMatrix();
	//quit title
	glPushMatrix();
	glColor3f(0.275f, 0.510f, 0.706f);
	glTranslatef(5.2f, -9.0f, 0.0f);
	glScalef(0.005,0.005,0.005);
	for(int i=0; i<str5.length(); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str5[i]);
	glPopMatrix();
	//made by
	glPushMatrix();
	glColor3f(0.294f,0.0f,0.510f);
	glTranslatef(5.5f, -14.0f, 0.0f);
	glScalef(0.005,0.005,0.005);
	for(int i=0; i<str6.length(); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str6[i]);
	glPopMatrix();
	//name
	glPushMatrix();
	glColor3f(0.502f,0.0f,0.502f);
	glTranslatef(4.8f, -15.0f, 0.0f);
	glScalef(0.0055,0.0055,0.0055);
	for(int i=0; i<str7.length(); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str7[i]);
	glPopMatrix();
}

void draw_end_screen(){
	glPushMatrix();
	glTranslatef(end_screenX, end_screenY, 0.0f);
	glBegin(GL_LINE_LOOP);
		glLineWidth(2.0);
		glColor3f(0.0,0.0,2.0);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.0f, -end_box_height);
		glVertex2f(end_box_width, -end_box_height);
		glVertex2f(end_box_width, 0.0f);
	glEnd();

	draw_end_text();
	glPopMatrix();
}

void draw_pause_screen(){
	std::string str1 = "Game Paused";
	std::string str2 = "Resume : R";
	std::string str3 = "Quit : Esc";
	glLineWidth(2.0);
	//game paused
	glPushMatrix();
	glTranslatef(pause_screenX, pause_screenY, 0.0f);
	glColor3f(0.824f, 0.412f, 0.118f);
	glScalef(0.01,0.01,0.01);
	for(int i=0; i<str1.length(); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str1[i]);
	glPopMatrix();
	glLineWidth(1.0);
	//resume
	glPushMatrix();
	glTranslatef(-2.0f,2.0f,0.0f);
	glColor3f(0.663f, 0.663f, 0.663f);
	glScalef(0.005,0.005,0.005);
	for(int i=0; i<str2.length(); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str2[i]);
	glPopMatrix();
	//quit
	glPushMatrix();
	glTranslatef(-1.6f,1.0f,0.0f);
	glColor3f(0.663f, 0.663f, 0.663f);
	glScalef(0.005,0.005,0.005);
	for(int i=0; i<str3.length(); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str3[i]);
	glPopMatrix();
}

void display(){
	glClearColor(0.0f,0.0f,0.0f,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	draw_background();
	if(game_state==1){
		draw_start_screen();
	}
	else if(game_state==2){
		draw_score_board();
		draw_spaceship();
		draw_aliens();
		draw_bulletsC();
		draw_bulletsLR();
	}
	else if(game_state==3){
		draw_score_board();
		draw_pause_screen();
	}
	else if(game_state==4){
		draw_end_screen();
	}
	glFlush();
	glutSwapBuffers();
}