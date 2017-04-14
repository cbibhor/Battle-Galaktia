#define MOVE_SHIP 0.20
#define MOVE_BULLET 0.15
#define MOVE_RED_ALIEN 0.06
#define MOVE_BLUE_ALIEN 0.10
#define MOVE_GREEN_ALIEN 0.08
#define edgDistBack 0.1
#define edgDistFront 1.0
#define edgDistTop 0.6
#define num_of_stars 100
#define MAX_RED_SHIPS 3
#define MAX_BLUE_SHIPS 3
#define MAX_GREEN_SHIPS 3

//window variables
extern float GL_COX, GL_COY;
extern int windowWidth, windowHeight;
extern int FPS;

//game variable
extern int game_state;
extern int ships_destroyed;
extern long game_score, high_score;

//score board variables
extern float score_boardX, score_boardY;
extern float score_board_height, score_board_width;

//start screen variables
extern float start_screenX, start_screenY;
extern float start_box_height, start_box_width;

//pause screen variables
extern float pause_screenX, pause_screenY;

//end screen variables
extern float end_screenX, end_screenY;
extern float end_box_height, end_box_width;

//spaceship variables
extern float spaceshipX, spaceshipY;

//bullets variables
extern std::vector< struct bullet> bulletsL, bulletsR, bulletsC;

//red alienship variables
extern std::vector< struct alienship > red_pos;
extern int ADD_RED_ALIENS, rem1, num_of_red;
extern std::vector<int> life_red;

//blue alienship variables
extern std::vector< struct alienship > blue_pos;
extern int ADD_BLUE_ALIENS, rem2, num_of_blue;

//green alienship variables
extern std::vector< struct alienship > green_pos;
extern int ADD_GREEN_ALIENS, rem3, num_of_green;

//background variables
extern int BACKGROUND_REFRESH_DELAY, k;
extern std::vector< struct Point > points;