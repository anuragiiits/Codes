/*
    Anurag Gupta 201601006
    Anubhav Ujjawal 201601005

    Standard A-Star Variables:
    st --> state array used for Minheap which works as OPEN array
    visited --> puzzle array which works as CLOSED array
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <time.h>

//a structure of a puzzle
typedef struct puzzle {
  int tiles[4][4];
  int empty_position_i, empty_position_j;
} puzzle;

int mnop=0;
// a structure denoting a state
typedef struct state{
  puzzle *a;
  int total_moves;
  int moves;
  int misplaced_tiles;
  int estimated_moves;
  struct state *parent;
} state;

int parent(int i) {
  return (i-1)/2;
}

int left(int i) {
  return (2*i + 1);
}

int right(int i) {
  return (2*i + 2);
}

void print_puzzle(puzzle *p);
state *st[1000000];                     //this is the OPEN array
int heap_size;
int scount;
puzzle *visited[1000000];               //this is the CLOSED array
int visited_moves[1000000];
int visited_cnt=0;
void Minheapify(int i);

void init(){
  // st =  malloc(100000*sizeof(*state));
  for (int i=0; i < 1000000; i++) {
    st[i]=malloc(sizeof(state*));
    visited[i]=malloc(sizeof(puzzle*));
  }
  heap_size = 0;
}

state *getMin() {
  return st[0];
}

void swap(state *s1, state *s2){
  state *temp = s1;
  s1=s2;
  s2=temp;
}

void insertNodeMinheap(state *m){
  if (heap_size > 1000000) {
    printf("Overflow\n");
    return;
  }
  int i=heap_size;
  st[heap_size] = m;
  heap_size++;
  if (i==0)
    return;
  while ((st[parent(i)]->estimated_moves + st[parent(i)]->total_moves) > (st[i]->estimated_moves + st[i]->total_moves)){
     // swap(st[i], st[parent(i)]);
     state *tem = st[i];
     st[i]=st[parent(i)];
     st[parent(i)]=tem;
     i = parent(i);
  }
}

void decreaseKey(int i, int value){
  st[i]->misplaced_tiles = value;
  st[i]->estimated_moves = 0;
  while (i != 0 && (st[parent(i)]->estimated_moves + st[parent(i)]->total_moves) > (st[i]->estimated_moves + st[i]->total_moves)){
     // swap(st[i], st[parent(i)]);
     state *tem = st[i];
     st[i]=st[parent(i)];
     st[parent(i)]=tem;
     i = parent(i);
  }
}

state *extractMin(){
  if (heap_size==1) {
    heap_size--;
    return st[0];
  }
  state *root = st[0];
  st[0]=st[heap_size-1];
  heap_size--;
  Minheapify(0);
  return root;
}

void deleteKey(int i){
  decreaseKey(i,INT_MIN);
  extractMin();
}

void Minheapify(int i){
  int l=left(i);
  int r=right(i);
  int smallest=i;
  if (l<heap_size && (st[l]->estimated_moves + st[l]->total_moves) < (st[i]->estimated_moves + st[i]->total_moves)) {
    smallest = l;
  }
  if (r<heap_size && (st[r]->estimated_moves + st[r]->total_moves) < (st[smallest]->estimated_moves + st[smallest]->total_moves)) {
    smallest = r;
  }
  if (smallest!=i) {
    // swap(st[i],st[smallest]);
    state *tem = st[i];
    st[i]=st[smallest];
    st[smallest]=tem;
    Minheapify(smallest);
  }
}
//function to check if two puzzle matches
bool do_puzzle_match (puzzle *a, puzzle *b){
  for(int i=0; i<=3; i++){
    for(int j=0; j<=3; j++){
      if(a->tiles[i][j] != b->tiles[i][j])
        return false;
    }
  }
  return true;
}

int check_visited(puzzle *a){
  for(int i=0;i<visited_cnt;i++){
    if(do_puzzle_match(a,visited[i]))
      return i;
  }
  return -1;
}

bool check_answer(puzzle *a){
  for(int i=0;i<=3;i++){
    for(int j=0;j<=3;j++){
      if(a->tiles[i][j] != i*4+j+1){
        return false;
      }
    }
  }
  return true;
}
//function to count total no. of misplaced tiles
int misplaced_tiles_count (puzzle *a){
  int count = 0;
  for(int i=0; i<=3; i++){
    for(int j=0; j<=3; j++){
        if(a->tiles[i][j] != i*4 + j + 1 )
          count++;
    }
  }
  return count;
}

void swapint (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
// this function creates a new random puzzle
puzzle *create_a_new_problem(){
  puzzle *p = malloc(sizeof(puzzle));

  // int a[4][4] =  {{13, 2, 10, 3}, {1, 12, 8, 4}, {5, 16, 9, 6}, {15, 14, 11, 7}};
  // int a[4][4] =  {{6,13,7,10},{8,9,11,16},{15,2,12,5},{14,3,1,4}};
  // int a[4][4] =  {{12, 1, 10, 2},{7, 16, 4, 14},{5, 11, 9, 15},{8, 13, 6, 3}};
  // int a[4][4] = {{1,2,3,4},{5,6,8,11},{9,16,10,7},{13,14,15,12}};
  // int a[4][4] =  {{5, 1, 2, 3}, {9, 6, 7, 4}, {13, 10, 11, 8}, {14, 15, 16, 12}};

  int a[4][4];
  printf("Enter the puzzle state to be solved from 1 to 16 (16 for the blank tile) :\n");
  for (int i = 0; i < 4; ++i)
  {
    for (int j = 0; j < 4; ++j)
    {
      scanf("%d",&a[i][j]);
      if (a[i][j]==16)
      {
        p->empty_position_i = i;
        p->empty_position_j = j;
      }
    }
  }

  for (int i=0; i<=3; i++){
    for(int j=0; j<=3; j++){
      p->tiles[i][j] = a[i][j];
    }
  }
  
  printf("\n\nStart state :\n");
  print_puzzle(p);
  return p;
}

void print_puzzle(puzzle *p){
  for(int i=0; i<=3; i++){
    for(int j=0; j<=3; j++){
      if (p->tiles[i][j] == 16)
        printf("-- ");
      else
        printf("%d ", p->tiles[i][j]);
    }
    printf("\n");
  }
  return;
}

void copy_puzzle(puzzle *p, puzzle *q) {
  for (int i=0; i<=3; i++){
    for(int j=0; j<=3; j++){
        q->tiles[i][j] = p->tiles[i][j];
    }
  }
  q->empty_position_i = p->empty_position_i;
  q->empty_position_j = p->empty_position_j;
}

int estimated_no_of_moves(puzzle *p){
  int count = 0 ;
  for (int i=0; i<=3; i++){
    for(int j=0; j<=3; j++){
      // printf("i->%d  j->%d %d %d\n", i, j, abs((p->tiles[i][j])/4 - i), abs(p->tiles[i][j]%4 - j));
      count += abs((p->tiles[i][j] - 1)/4 - i) + abs((p->tiles[i][j] - 1)%4 - j);
    }
  }
  return count;
}

state *change_state(state *s , int move){
  puzzle *p = s->a;
  state *s1 = malloc(sizeof(state));
  puzzle *new_puzzle = malloc(sizeof(puzzle));
  copy_puzzle(p, new_puzzle);
  // print_puzzle(new_puzzle);

  switch (move) {
    case 2:
      new_puzzle->tiles[new_puzzle->empty_position_i][new_puzzle->empty_position_j] = new_puzzle->tiles[new_puzzle->empty_position_i + 1][new_puzzle->empty_position_j];
      new_puzzle->tiles[new_puzzle->empty_position_i + 1][new_puzzle->empty_position_j]  = 16;
      new_puzzle->empty_position_i = new_puzzle->empty_position_i + 1;
      break;
    case 8:
      new_puzzle->tiles[new_puzzle->empty_position_i][new_puzzle->empty_position_j] = new_puzzle->tiles[new_puzzle->empty_position_i - 1][new_puzzle->empty_position_j];
      new_puzzle->tiles[new_puzzle->empty_position_i - 1][new_puzzle->empty_position_j] = 16;
      new_puzzle->empty_position_i = new_puzzle->empty_position_i - 1;
      break;
    case 6:
      new_puzzle->tiles[new_puzzle->empty_position_i][new_puzzle->empty_position_j] = new_puzzle->tiles[new_puzzle->empty_position_i ][new_puzzle->empty_position_j + 1];
      new_puzzle->tiles[new_puzzle->empty_position_i ][new_puzzle->empty_position_j + 1] = 16;
      new_puzzle->empty_position_j = new_puzzle->empty_position_j + 1;
      break;
    case 4:
      new_puzzle->tiles[new_puzzle->empty_position_i][new_puzzle->empty_position_j] = new_puzzle->tiles[new_puzzle->empty_position_i ][new_puzzle->empty_position_j - 1];
      new_puzzle->tiles[new_puzzle->empty_position_i ][new_puzzle->empty_position_j - 1] = 16;
      new_puzzle->empty_position_j = new_puzzle->empty_position_j - 1;
      break;
  }
  s1->moves = s->moves+1;
  s1->total_moves = s1->total_moves+1;
  s1->total_moves = (int)round(s1->total_moves * 0.3);
  s1->misplaced_tiles = misplaced_tiles_count(new_puzzle);
  s1->estimated_moves = estimated_no_of_moves(new_puzzle);
  s1->a = new_puzzle;
  s1->parent = (state*) malloc(sizeof(state));
  s1->parent = s;
  return s1;
}
char ch;
void print_path(state *s){
  if(s->parent){
    print_path(s->parent);
    print_puzzle(s->a);
    printf("\n");
  }
}

void check_and_insert(state *s){
  int ind = check_visited(s->a);
  if (ind >= 0){
    if (s->moves < visited_moves[ind]){
      insertNodeMinheap(s);
      scount++;
    }
  }
  else{
      scount++;
      insertNodeMinheap(s);
  }
}

int main(int argc, char const *argv[]) {
  init();                                            //initialize the OPEN array, i.e, minheap
  puzzle *p = create_a_new_problem();               //initialize the puzzle  
  state *s = malloc(sizeof(state));
  s->a = p;
  s->moves = 0;
  s->total_moves = 0;
  s->misplaced_tiles = misplaced_tiles_count(p);
  s->estimated_moves = estimated_no_of_moves(p);
  // s->parent = (state*)malloc(sizeof(state));
  s->parent = NULL;
  char str;
  insertNodeMinheap(s);
  scount = 1;
  while(1){
    scount--;
    state *s1 = extractMin();
    int ind = check_visited(s1->a) ;             //checks if this state is repeated
    if(ind >= 0){
      // if (s1->total_moves >= visited_moves[ind])    //checks if the total moves is greater than previously repeated moves, then ignore it
        continue;
    }
    
    mnop++;
    visited[visited_cnt++]=s1->a;                           //maintains the CLOSED array
    visited_moves[visited_cnt++] = s1->moves;

    if ((s1->misplaced_tiles)==0) {
      //print the solution
      // print_path(s1);          //uncomment to print the path of solution
      printf("\nPuzzle is solved\n");
      printf("\nSolved State :\n");
      print_puzzle(s1->a);
      printf("\nTime taken taken to solve the puzzle = %d\n",mnop);
      printf("Space consumed to solve the puzzle = %d\n",scount);
      printf("Total number of moves from source state to destination state (distance between source and destination) = %d\n",s1->moves);
      return 0;
    }

    if(s1->a->empty_position_i > 0  && s1->a->empty_position_i < 3 && s1->a->empty_position_j < 3 && s1->a->empty_position_j > 0){
      state *s11 = change_state(s1, 2);
      state *s2 = change_state(s1, 8);
      state *s3 = change_state(s1, 6);
      state *s4 = change_state(s1, 4);

      check_and_insert(s11);                        //check if node is repeated or not and insert in the heap(open array)
      check_and_insert(s2);
      check_and_insert(s3);
      check_and_insert(s4);
      scount+=3;
    }
    else if(s1->a->empty_position_i > 0 && s1->a->empty_position_i < 3 && s1->a->empty_position_j==0){
      state *s11 = change_state(s1, 2);
      state *s2 = change_state(s1, 6);
      state *s3 = change_state(s1, 8);

      check_and_insert(s11);
      check_and_insert(s2);
      check_and_insert(s3);
      scount+=3;
    }
    else if(s1->a->empty_position_i > 0 && s1->a->empty_position_i < 3 && s1->a->empty_position_j==3){
      state *s11 = change_state(s1, 2);
      state *s2 = change_state(s1, 4);
      state *s3 = change_state(s1, 8);

      check_and_insert(s11);
      check_and_insert(s2);
      check_and_insert(s3);
      scount+=3;
    }
    else if (s1->a->empty_position_i==0) {
      if(s1->a->empty_position_j==0){
        state *s11 = change_state(s1, 6);
        state *s2 = change_state(s1, 2);

        check_and_insert(s11);
        check_and_insert(s2);
        scount+=2;
      }
      else if(s1->a->empty_position_j==3){
        state *s11 = change_state(s1, 4);
        state *s2 = change_state(s1, 2);

        check_and_insert(s11);
        check_and_insert(s2);
        scount+=2;
      }
      else{
        state *s11 = change_state(s1, 2);
        state *s2 = change_state(s1, 6);
        state *s3 = change_state(s1, 4);

        check_and_insert(s11);
        check_and_insert(s2);
        check_and_insert(s3);
        scount+=3;
      }
    }
    else if (s1->a->empty_position_i==3){
      if(s1->a->empty_position_j==3){
        state *s11 = change_state(s1, 4);
        state *s2 = change_state(s1, 8);

        check_and_insert(s11);
        check_and_insert(s2);
        scount+=2;
      }
      else if(s1->a->empty_position_j==0){
        state *s11 = change_state(s1, 6);
        state *s2 = change_state(s1, 8);

        check_and_insert(s11);
        check_and_insert(s2);
        scount+=2;
      }
      else{
        state *s11 = change_state(s1, 8);
        state *s2 = change_state(s1, 6);
        state *s3 = change_state(s1, 4);

        check_and_insert(s11);
        check_and_insert(s2);
        check_and_insert(s3);
        scount+=3;
      }
    }
    // printf("test2\n");
  }
  return 0;
}
