/*
ID: skyline12
PROG: castle
LANG: C++11
*/
// Xiaoyan Wang 5/5/2016
#include <fstream>
#include <vector>
using std::vector;

vector<vector<int> > module;
vector<vector<int> > mod; // processed module
vector<int> roomsize; // size of room with given no.
int M, N; // row, column

// colored the module
int process_module(); // return size of the largest room
int find_room(int roomNo); // return size of the current room
int remove_walls(int& rR, int& rC, char& d);

int main() {
  std::ifstream fin("castle.in");
  std::ofstream fout("castle.out");
  // note: i misread the question and accidentally swap these two
  // symbols, and when i realize that mistake it was too late to change
  fin >> N >> M;
  // read the modules into a vector
  module = vector<vector<int> >(M+1, vector<int>(N+1));
  for(int m = 1; m <= M; ++m)
    for(int n = 1; n <= N; ++n)
      fin >> module[m][n];
  fin.close();

  mod = vector<vector<int> >(M+1, vector<int>(N+1, 0));
  roomsize.push_back(0); // there should be no no.0 room after processed
  int max_room = process_module();
  
  int rR, rC; // the position of the module whose wall will be remove
  char d; // the direction of the wall being removed
  int max_re_room = remove_walls(rR, rC, d);

  fout << roomsize.size()-1 << '\n'
       << max_room << '\n'
       << max_re_room << '\n'
       << rR << ' ' << rC << ' ' << d << std::endl;  

  // // TEST
  // for(int m = 1; m <= M; ++m) {
  //   for(int n = 1; n <= N; ++n)
  //     fout << mod[m][n] << ' ';
  //   fout << '\n';
  // }
  // fout << '\n';
  // for(int i = 1; i < roomsize.size(); ++i)
  //   fout << "The size of room No." << i
  // 	 << " is " << roomsize[i] << '\n';
  // fout << "The largest room size is " << max_room << '\n';
  // fout << std::flush;

  fout.close();
  return 0;  
}

int process_module() {
  int maxRoom = 0;
  int roomNo = 1;
  for(int m = 1; m <= M; ++m)
    for(int n = 1; n <= N; ++n)
      if(!mod[m][n]) {
	mod[m][n] = -1;
	int currRoomsize = find_room(roomNo);
	if(currRoomsize > maxRoom)
	  maxRoom = currRoomsize;
	++roomNo;
      }
  return maxRoom;
}

int find_room(int roomNo) {
  int room_size = 0;
  while(true) {
    int num_visit = 0;
    for(int r = 1; r <= M; ++r)
      for(int c = 1; c <= N; ++c)
	if(mod[r][c] == -1) {
	  ++room_size;
	  ++num_visit;
	  mod[r][c] = roomNo;
	  // find the connected rooms
	  while(module[r][c] < 15) { // no south wall
	    if(module[r][c] <= 7) {
	      if(!mod[r+1][c])
		mod[r+1][c] = -1;
	      module[r][c] += 8;
	    }
	    else if(module[r][c] <= 11) { // no east wall
	      if(!mod[r][c+1])
		mod[r][c+1] = -1;
	      module[r][c] += 4;
	    }
	    else if(module[r][c] <= 13) { // no north wall 
	      if(!mod[r-1][c])
		mod[r-1][c] = -1;
	      module[r][c] += 2;
	    }
	    else if(module[r][c] <= 14) { // no west wall
	      if(!mod[r][c-1])
		mod[r][c-1] = -1;
	      module[r][c] += 1;
	    }
	  }
	}
    if(!num_visit) // if there is no wall to be processed
      break;
  }
  roomsize.push_back(room_size);
  return room_size;
}

int remove_walls(int& rR, int& rC, char& d) {
  // remember: the castle always have at least two walls
  int max_re_room = 0;
  // check from east to west, from north to south
  // omit the northeastmost room
  // check the eastmost column (there is no east room)
  for(int m = 2; m <= M; ++m) {
    if(mod[m][N] != mod[m-1][N]) {
      int re_room = roomsize[mod[m][N]] + roomsize[mod[m-1][N]];
      if(re_room >= max_re_room) {
	max_re_room = re_room;
	rR = m;
	rC = N;
	d = 'N';
      }
    }
  }
  for(int n = N-1; n >= 1; --n) { // check all columns except the first one
    // check the top row (seperate this from the below checking process
    // because there is no north room to check on the top row)
    if(mod[1][n] != mod[1][n+1]) {
      int re_room = roomsize[mod[1][n]] + roomsize[mod[1][n+1]];
      if(re_room >= max_re_room) {
	max_re_room = re_room;
	rR = 1;
	rC = n;
	d = 'E';
      }
    }
    for(int m = 2; m <= M; ++m) { // check all rows except the top one
      // try removing the east wall
      if(mod[m][n] != mod[m][n+1]) {
	int re_room = roomsize[mod[m][n]] + roomsize[mod[m][n+1]];
	if(re_room >= max_re_room) {
	  max_re_room = re_room;
	  rR = m;
	  rC = n;
	  d = 'E';
	}
      }
      // try removing the north wall
      if(mod[m][n] != mod[m-1][n]) {
	int re_room = roomsize[mod[m][n]] + roomsize[mod[m-1][n]];
	if(re_room >= max_re_room) {
	  max_re_room = re_room;
	  rR = m;
	  rC = n;
	  d = 'N';
	}
      }
    }
  }
  return max_re_room;
}
