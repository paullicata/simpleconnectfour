#include <iostream>
#include <string>


using namespace std;

#define size_x  7
#define size_y  6

char board [size_y][size_x];
char player = '1';
bool win = false;


void init_board()
{
  int i, j;
  
  cout << "1 2 3 4 5 6 7" << endl;
  
  for(j = 0; j < size_y; j++){
    for(i = 0; i < size_x; i++){
      board[j][i] = '0';
    }
  }
  for(j = 0; j < size_y; j++){
    for(i = 0; i < size_x; i++){
      cout << board[j][i] << " ";
    }
    cout << "\n";
  }
   
}

void draw_board()
{
  int i, j;
  
  cout << "1 2 3 4 5 6 7" << endl;
  
  for(j = 0; j < size_y; j++){
    for(i = 0; i < size_x; i++){
      cout << board[j][i] << " ";
    }
    cout << "\n";
  } 
}

void player_turn(char turn, int column)
{
  int i;
 
  if(column >= 1 && column <= 7){
    for(i = 6; i > -1; i--){
      if(board[i][column-1] == '0'){
	board[i][column-1] = turn;
	break;
      }
    }
  }
  else{
    cout << "Please enter a valid column" << endl;
  }
  if(player == '1'){
    player = '2';
  }
  else{
    player = '1';
  }
  
}

void is_win()
{
  int i, j;
  for(j = 0; j < size_y; j++){
    for(i = 0; i < size_x; i++){
      if(board[j][i]=='1' && board[j+1][i]=='1' && 
	 board[j+2][i]=='1' && board[j+3][i]=='1'){
	cout << "PLAYER 1 WINS" << endl;
	win = true;
      }
      if(board[j][i]=='1' && board[j][i+1]=='1' && 
	 board[j][i+2]=='1' && board[j][i+3]=='1'){
	cout << "PLAYER 1 WINS" << endl;
	win = true;
      }
      if(board[j][i]=='2' && board[j+1][i]=='2' && 
	 board[j+2][i]=='2' && board[j+3][i]=='2'){
	cout << "PLAYER 2 WINS" << endl;
	win = true;
      }
      if(board[j][i]=='2' && board[j][i+1]=='2' && 
	 board[j][i+2]=='2' && board[j][i+3]=='2'){
	cout << "PLAYER 2 WINS" << endl;
	win = true;
      }

      if(board[j][i]=='1' && board[j+1][i+1]=='1' && 
	 board[j+2][i+2]=='1' && board[j+3][i+3]=='1'){
	cout << "PLAYER 1 WINS" << endl;
	win = true;
      }
      if(board[j][i]=='2' && board[j+1][i+1]=='2' && 
	 board[j+2][i+2]=='2' && board[j+3][i+3]=='2'){
	cout << "PLAYER 2 WINS" << endl;
	win = true;
      }

      if(board[j][i]=='1' && board[j+1][i-1]=='1' && 
	 board[j+2][i-2]=='1' && board[j+3][i-3]=='1'){
	cout << "PLAYER 1 WINS" << endl;
	win = true;
      }
      if(board[j][i]=='2' && board[j+1][i-1]=='2' && 
	 board[j+2][i-2]=='2' && board[j+3][i-3]=='2'){
	cout << "PLAYER 2 WINS" << endl;
	win = true;
      }
      
    }
  }
    
}


int main(int argc, char *argv[])
{
  int col;

  init_board();
  
 
  while(true){
    cin >> col;
    player_turn(player, col);
    draw_board();
    is_win();
    if(win == true){
      break;
    }
  } 
  
  return 0;

}
