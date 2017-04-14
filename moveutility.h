#include "declaration.h"

//move our spaceship
void move_spaceship(float &spaceshipX, float &spaceshipY){
	if(spaceshipX-(float)edgDistBack < -GL_COX)		spaceshipX+=(float)MOVE_SHIP;
	else if(spaceshipX+(float)edgDistFront > GL_COX)	spaceshipX-=(float)MOVE_SHIP;
	if(spaceshipY-(float)edgDistTop < -GL_COY+0.5)		spaceshipY+=(float)MOVE_SHIP;
	else if(spaceshipY+(float)edgDistTop > GL_COY-1.5)	spaceshipY-=(float)MOVE_SHIP;
}

//move bullets
void move_bullets(std::vector<struct bullet> &bullets){
	for(int i=0; i<bullets.size(); i++){
		bullets[i].x += MOVE_BULLET;
		if(bullets[i].x > GL_COX){
			bullets.erase(bullets.begin() + i);
			i--;
		}
	}
}

//move red alienhip
void move_red_alienship(){
	for(int i=0; i<red_pos.size(); i++){
		red_pos[i].x -= MOVE_RED_ALIEN;
		if(red_pos[i].x < -GL_COX-1){
			red_pos.erase(red_pos.begin() + i);
			i--;
		}
	}
}

//move blue alienship
void move_blue_alienship(){
	for(int i=0; i<blue_pos.size(); i++){
		blue_pos[i].x -= MOVE_BLUE_ALIEN;
		if(blue_pos[i].x < -GL_COX-1){
			blue_pos.erase(blue_pos.begin() + i);
			i--;
		}
	}
}

//move green alienship
void move_green_alienship(){
	for(int i=0; i<green_pos.size(); i++){
		green_pos[i].x -= MOVE_GREEN_ALIEN;
		if(green_pos[i].x < -GL_COX-1){
			green_pos.erase(green_pos.begin() + i);
			i--;
		}
	}
}

//function to detect collision between bullet and alienship
bool detect_bullet_collision(std::vector<struct alienship> &ship_pos, std::vector<struct bullet> &bullet_pos){
	for(int i=0; i<bullet_pos.size(); i++){
		for(int j=0; j<ship_pos.size(); j++){
			if(bullet_pos[i].y > ship_pos[j].y+0.5 || bullet_pos[i].y < ship_pos[j].y-0.5)
				continue;
			if(bullet_pos[i].x >= ship_pos[j].x-0.2 && bullet_pos[i].x <= ship_pos[j].x+0.7){
				ships_destroyed++;
				bullet_pos.erase(bullet_pos.begin() + i);
				ship_pos.erase(ship_pos.begin() + j);
				i--, j--;
				game_score++;
				return true;
			}
		}
	}
	return false;
}

//function to detect collision between our spaceship and alienship
bool detect_spaceship_colision(std::vector<struct alienship> &ship_pos){
	for(int i=0; i<ship_pos.size(); i++){
		if(spaceshipY-0.6 > ship_pos[i].y+0.5 || spaceshipY+0.6 < ship_pos[i].y-0.5)
			continue;
		if(spaceshipX+1.0 >= ship_pos[i].x-0.2 && spaceshipX+1.0 <= ship_pos[i].x+0.7)
			return true;
		else if(spaceshipX-0.1 >= ship_pos[i].x-0.2 && spaceshipX-0.1 <= ship_pos[i].x+0.7)
			return true;
	}
	return false;
}
