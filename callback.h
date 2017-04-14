#include "declaration.h"

void keyboard_func(unsigned char key, int x, int y){
	switch(key){
	case 97:	if(game_state==2)	spaceshipX-=MOVE_SHIP;
				break;
	case 119:	if(game_state==2)	spaceshipY+=MOVE_SHIP;
				break;
	case 100:	if(game_state==2)	spaceshipX+=MOVE_SHIP;
				break;
	case 115:	if(game_state==2)	spaceshipY-=MOVE_SHIP;
				break;
	}
}

void keyboard_up_func(unsigned char key, int x, int y){
	switch(key){
		case 98:	if(game_state==2)	add_bulletLR();
					break;
		case 32:	if(game_state==2)	add_bulletC();
					break;
		case 13:	if(game_state==1)	game_state=2;
					else if(game_state==4){
						reset_variables();
						game_state=2;
					}
					break;
		case 27:	exit(0);
					break;
		case 'P':
		case 'p':	if(game_state==2)	game_state=3;
					break;
		case 'R':
		case 'r':	if(game_state==3)	game_state=2;
					break;
	}
}

void special_func(int key, int x, int y){
	switch(key){
		case GLUT_KEY_LEFT:	if(game_state==2)	spaceshipX-=MOVE_SHIP;
							break;
		case GLUT_KEY_UP:	if(game_state==2)	spaceshipY+=MOVE_SHIP;
							break;
		case GLUT_KEY_RIGHT:if(game_state==2)	spaceshipX+=MOVE_SHIP;
							break;
		case GLUT_KEY_DOWN:	if(game_state==2)	spaceshipY-=MOVE_SHIP;
							break;
	}
}

void resize(int width, int height){
	if(height==0)	height=1;
	GLfloat ratio = (GLfloat)width/(GLfloat)height;
	glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(width >= height)
		gluOrtho2D(-GL_COX*ratio, GL_COX*ratio, -GL_COY, GL_COY);
    else
	    gluOrtho2D(-GL_COX, GL_COX, -GL_COY/ratio, GL_COY/ratio);
}

void detect_collisions(){
	if(detect_bullet_collision(red_pos, bulletsC))		return;
	if(detect_bullet_collision(blue_pos, bulletsC))		return;
	if(detect_bullet_collision(green_pos, bulletsC))	return;
	if(detect_bullet_collision(red_pos, bulletsL))		return;
	if(detect_bullet_collision(blue_pos, bulletsL))		return;
	if(detect_bullet_collision(green_pos, bulletsL))	return;
	if(detect_bullet_collision(red_pos, bulletsR))		return;
	if(detect_bullet_collision(blue_pos, bulletsR))		return;
	if(detect_bullet_collision(green_pos, bulletsR))	return;
}

void move_all(){
	move_spaceship(spaceshipX, spaceshipY);
	move_bullets(bulletsC);
	move_bullets(bulletsL);
	move_bullets(bulletsR);
	move_red_alienship();
	move_blue_alienship();
	move_green_alienship();
}

void Timer(int value){
	if(game_state==2){
		move_all();
		detect_collisions();
		if(detect_spaceship_colision(red_pos) || detect_spaceship_colision(blue_pos) || detect_spaceship_colision(green_pos)){
			game_state=4;
			set_highscore();
		}
	}
	glutPostRedisplay();
	glutTimerFunc(1000/FPS, Timer, 0);
}