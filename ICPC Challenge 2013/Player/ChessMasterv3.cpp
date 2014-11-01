/*
    Name: ChessMaster
    Version: 3.0
    Date: 23:06, 6 June 2013
    Creator: 3T
    Description: Based on ChessMaster v2.0, try to trap enemies first, then find gold.
    Update: max and min threat distance, threat condition, movement condition, dijsktra to nearest gold.
*/


#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <set>
#include <cstdio>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define mp make_pair
#define ff first
#define ss second
#define INF 1000111222
#define pb push_back

typedef pair<int, int> ii;
typedef pair<ii, ii> i4;
typedef pair <int, ii> iii;

// Size of the playing field.
const int FIELD_ROW_COUNT = 16;
const int FIELD_COLUMN_COUNT = 25;

// How close an enemy can be before we try to move away or trap it.
// 5/6/2013: change from 5 to 3
const int THREAT_THRESHOLD = 3;
const int THREAT_MIN = 2;

// Constants for the various directions the player can move.
enum MoveDir { LEFT, TOP, RIGHT, BOTTOM, DIG_LEFT, DIG_RIGHT };

// Names for the different directions.
string moveName[] = { "LEFT", "TOP", "RIGHT", "BOTTOM", "DIG_LEFT", "DIG_RIGHT" };

// Row and column offsets for the move directions.
int dRow[] = { 0, -1, 0, 1 };
int dCol[] = { -1, 0, 1, 0 };


string world[ FIELD_ROW_COUNT ];
int d[FIELD_ROW_COUNT][FIELD_COLUMN_COUNT];
set <iii> DSet;

/** Representation for a player or enemy position. */
struct Position {
  int r, c;

  Position() : r( 0 ), c( 0 ) {
  }
};

/** Simple interface for reading positions from standard input. */
istream &operator>>( istream &input, Position &pos ) {
  input >> pos.r >> pos.c;
  return input;
}

/** Return true if a player will fall through this map character. */
bool isAir( char ch ) {
  return !( ch == '=' || ch == 'H' );
}

// 5/6/2013: If no enemy is at a cell at the moment
bool nobodyAtPosition(int x, int y, vector< Position > v) {
    rep(i, v.size()) {
        if(v[i].r == x && v[i].c == y) return false;
    }
    return true;
}

// 6/6/2013: check empty cell
bool isEmptyLike(int x, int y, vector< Position > v) {
    if(world[x][y] == '=' || world[x][y] == 'H') return false;
    if(world[x][y] == '-' && !nobodyAtPosition(x, y, v)) return false;
    return true;
}

// 5/6/2013: check whether an enemy is a threat or not
bool isThreat(Position runn, Position enn, vector< Position > v) {
    if(world[enn.r][enn.c] == '-') return false;
    if(runn.r == enn.r) {
        for(int i = min(runn.c, enn.c); i <= max(runn.c, enn.c); i++) if(world[runn.r][i] == '=' || (runn.r + 1 < FIELD_ROW_COUNT && world[runn.r + 1][i] == '-' && nobodyAtPosition(runn.r + 1, i, v))) return false;
    }
    if(runn.c == enn.c) {
        for(int i = min(runn.r, enn.r); i <= max(runn.r, enn.r); i++) if(world[i][runn.c] != 'H') return false;
    }
    return true;
}

// 6/6/2013: check whether runner can dig right if he's at pos x, y
bool canDigRightAtPos(Position pos) {
    if(pos.c + 1 >= FIELD_COLUMN_COUNT) return false;
    if ( pos.r + 1 < FIELD_ROW_COUNT ) {
          if ( world[ pos.r ][ pos.c + 1 ] != 'H' && world[ pos.r ][ pos.c + 1 ] != '=' && world[ pos.r + 1 ][ pos.c + 1 ] == '=' &&
               ( world[ pos.r + 1 ][ pos.c ] == '=' || world[ pos.r + 1 ][ pos.c ] == 'H' ) )
            return true;
        }
    return false;
}

// 6/6/2013: check whether runner can dig left if he's at pos x, y
bool canDigLeftAtPos(Position pos) {
    if(pos.c - 1 < 0) return false;
    if ( pos.r + 1 < FIELD_ROW_COUNT ) {
          if ( world[ pos.r ][ pos.c - 1 ] != 'H' && world[ pos.r ][ pos.c - 1 ] != '=' && world[ pos.r + 1 ][ pos.c - 1 ] == '=' &&
               ( world[ pos.r + 1 ][ pos.c ] == '=' || world[ pos.r + 1 ][ pos.c ] == 'H' ) )
            return true;
        }
    return false;
}

// 6/6/2013: count how many nearby enemy (not working)
int countNearbyEnemy(int x, int y, vector< Position > v){
    int res = 0;
    return 0;
    rep(i, v.size()) {
        if(abs(v[i].r - x) + abs(v[i].c - y) <= 2) res++;
    }
    return res;
}

// 6/6/2013: check whether a position is inside the map
bool insideMap(int x, int y) {
    return (x >= 0 && x < FIELD_ROW_COUNT && y >= 0 && y < FIELD_COLUMN_COUNT);
}

// 6/6/2013: get distance to the nearest gold from pos
int getMinDistanceToGold(int x, int y, vector <Position> v, int MoveType) {
    char tmpch = world[x][y];
    if(MoveType == DIG_LEFT || MoveType == DIG_RIGHT) world[x][y] = '.';

    //initiation
    int res = INF;
    /*
    fr(i, x, FIELD_ROW_COUNT - 1) rep(j, FIELD_COLUMN_COUNT) {
        if(world[i][j] == '*')
        res = min(res, i - x + abs(j - y));
    }*/

    vector< pair<ii, int> > adj[FIELD_ROW_COUNT][FIELD_COLUMN_COUNT];
    rep(i, FIELD_ROW_COUNT) rep(j, FIELD_COLUMN_COUNT) {
        //falling
        if(world[i][j] != 'H' && i + 1 < FIELD_ROW_COUNT && isEmptyLike(i + 1, j, v)) {
            adj[i][j].pb(mp(mp(i + 1, j), 1));
            continue;
        }

        //whether we can go to 4 directions from current cell
        rep(k, 4) {
            int xx = i + dRow[k], yy = j + dCol[k];
            if(!insideMap(xx, yy)) continue;
            if(k == 0 || k == 2) {
                if(world[xx][yy] != '=') adj[i][j].pb(mp(mp(xx, yy), 1));
            }
            else if(k == 1 || k == 3) {
                if(world[i][j] == 'H' && world[xx][yy] != '=') adj[i][j].pb(mp(mp(xx, yy), 1));
            }
        }

        //whether we can dig right or dig left from current cell
        Position tmpPos; tmpPos.r = i; tmpPos.c = j;
        if(canDigLeftAtPos(tmpPos)) adj[i][j].pb(mp(mp(i + 1, j - 1), 3));
        if(canDigRightAtPos(tmpPos)) adj[i][j].pb(mp(mp(i + 1, j + 1), 3));
    }

    DSet.clear();
    rep(i, FIELD_ROW_COUNT) rep(j, FIELD_COLUMN_COUNT) d[i][j] = INF;
    d[x][y] = 0;
    DSet.insert(mp(0, mp(x, y)));

    //run dijkstra
    while(!DSet.empty()) {
        iii tmp = *DSet.begin();
        DSet.erase(tmp);

        int ux = tmp.ss.ff, uy = tmp.ss.ss;
        rep(i, adj[ux][uy].size()) {
            int vx = adj[ux][uy][i].ff.ff, vy = adj[ux][uy][i].ff.ss, cost = adj[ux][uy][i].ss;
            if(d[vx][vy] > d[ux][uy] + cost) {
                if(d[vx][vy] != INF) DSet.erase(mp(d[vx][vy], mp(vx, vy)));
                d[vx][vy] = d[ux][uy] + cost;
                DSet.insert(mp(d[vx][vy], mp(vx, vy)));
            }
        }
    }
    rep(i, FIELD_ROW_COUNT) rep(j, FIELD_COLUMN_COUNT) {
        if(world[i][j] == '*') res = min(res, d[i][j]);
    }

    world[x][y] = tmpch;
    return res;
}

// 6/6/2013: check whether enemies can reach the cell in a move
bool isAround(int x, int y, vector< Position > v) {
    rep(i, v.size()) {
        if(v[i].r < 0) continue;
        if(v[i].r == x && v[i].c == y) return true;
        if(world[v[i].r][v[i].c] == '-') continue;
        if(v[i].r == x - 1 && v[i].c == y) return true;
        if(v[i].r == x + 1 && v[i].c == y && world[v[i].r][v[i].c] == 'H') return true;
        if(v[i].r == x && (v[i].c == y + 1|| v[i].c == y - 1)) return true;
    }
    return false;
}

int main( int argc, char* argv[] ) {
  // Initial positions and current positions for each runner.
  Position initRunners[ 2 ], runners[ 2 ];

  // Current score in the game.
  int scores[ 2 ];

  // How long until each runner can dig.
  int digDelay[ 2 ];

  // How long will the game be?
  int turns;
  cin >> turns;

  // Read a picture of the map.
  // 6/6/2013: world is now a global array (line 44)
  for (int i = 0; i < FIELD_ROW_COUNT; i++)
    cin >> world[ i ];

  // Time when we last visited this space, or -1.
  vector< vector< int > > visitTime( FIELD_ROW_COUNT, vector< int >( FIELD_COLUMN_COUNT, -1 ) );

  // Read initial positions of the two runners.
  for(int i = 0; i < 2; i++)
    cin >> initRunners[i];

  // Read initial positions of all the enemies.
  int enemyCount;
  cin >> enemyCount;

  // Respawn spot for each enemy.
  vector< Position > initEnemies( enemyCount );

  // What player each enemy is afraid of (or -1), not used in this player.
  vector< int > master( enemyCount, -1 );

  // Circuit the enemy will make while patrolling.  Not useed in this player.
  vector< string > program( enemyCount );

  for(int i = 0; i < enemyCount; i++)
    cin >> initEnemies[i] >> program[ i ];

  // Current enemy positions.
  vector< Position > enemies = initEnemies;

  // Last known move direction for each enemy.
  vector< int > enemyMoveDir( enemyCount );

  // For each turn in the game.
  for ( int turnNumber = 0; turnNumber < turns; turnNumber++ ) {
    // Read the turn number (should be [ 0, turns ) unless we're late with a move.
    int turn;
    cin >> turn;

    // Read the current world description, since gold may be collected
    // and the floor may be destroyed.
    for (int i = 0; i < FIELD_ROW_COUNT; i++)
      cin >> world[ i ];

    // Read the positions of each player's runners, current scores and
    // how long until each can dig.
    for(int i = 0; i < 2; i++)
      cin >> runners[i] >> scores[ i ] >> digDelay[ i ];

    // For convenience, remember my position in some local variables.
    int myRow = runners[ 0 ].r;
    int myCol = runners[ 0 ].c;

    // Remember previous enemy positions, and read latest ones.
    vector< Position > prevEnemies = enemies;
    for ( int i = 0; i < enemyCount; i++ )
      cin >> enemies[ i ] >> master[ i ];

    // Tentative move.  See if we can do better.
    string move = "NONE";
    if ( myRow >= 0 && myCol >= 0 ) {

      // Remember when I visited this cell.
      visitTime[ myRow ][ myCol ] = turn;

      // Is there an enemy heading toward us from the left or right?
      bool approachingLeft = false, approachingRight = false;

      // Can we move left, up, right or down?
      vector< bool > canMove( 4, false );

      // Is there a nearby enemy left, up, right or down?
      vector< bool > threat( 4, false );

      for ( int i = 0; i < enemyCount; i++ ) {
        // If this enemy has moved, remember its move direction.
        if ( enemies[ i ].r > prevEnemies[ i ].r )
          enemyMoveDir[ i ] = BOTTOM;
        else if ( enemies[ i ].r < prevEnemies[ i ].r )
          enemyMoveDir[ i ] = TOP;
        else if ( enemies[ i ].c > prevEnemies[ i ].c )
          enemyMoveDir[ i ] = RIGHT;
        else if ( enemies[ i ].c < prevEnemies[ i ].c )
          enemyMoveDir[ i ] = LEFT;

        // See if there are enemies nearby
        //5/6/2013: update threat (if there's already hole, don't worry)
        if ( enemies[ i ].r == myRow && enemies[ i ].c < myCol &&
             ((myCol - enemies[ i ].c < THREAT_THRESHOLD && isThreat(runners[0], enemies[i], enemies)) || myCol - enemies[i].c <= THREAT_MIN)) {
          threat[ LEFT ] = true;

          if ( myCol - enemies[ i ].c >= 1 && enemyMoveDir[ i ] == RIGHT )
            approachingLeft = true;
        }

        if ( enemies[ i ].r == myRow && enemies[ i ].c > myCol &&
             ((enemies[ i ].c - myCol < THREAT_THRESHOLD && isThreat(runners[0], enemies[i], enemies)) || enemies[i].c - myCol <= THREAT_MIN)) {
          threat[ RIGHT ] = true;

          if ( enemies[ i ].c - myCol >= 1 && enemyMoveDir[ i ] == LEFT )
            approachingRight = true;
        }

        if ( enemies[ i ].c == myCol && enemies[ i ].r < myRow &&
             myRow - enemies[ i ].r < THREAT_THRESHOLD && isThreat(runners[0], enemies[i], enemies))
          threat[ TOP ] = true;

        if ( enemies[ i ].c == myCol && enemies[ i ].r > myRow &&
             enemies[ i ].r - myRow < THREAT_THRESHOLD && isThreat(runners[0], enemies[i], enemies))
          threat[ BOTTOM ] = true;
      }

      // Can we dig left or right?
      bool canDig = ( digDelay[ 0 ] == 0 );
      bool canDigLeft = false, canDigRight = false;

      // Look around the runner and see what it can do.
      if ( myCol > 0 && world[ myRow ][ myCol - 1 ] != '=' ) {
        canMove[ LEFT ] = true;

        //5/6/2013: don't move if you fall into a removed brick at bottom
        if(myRow + 1 == FIELD_ROW_COUNT - 1 && world[myRow + 1][myCol - 1] == '-' && nobodyAtPosition(myRow + 1, myCol - 1, enemies))
        canMove[LEFT] = false;

        if(canDigLeftAtPos(runners[0])) canDigLeft = canDig;
        }

      if ( myCol + 1 < FIELD_COLUMN_COUNT && world[ myRow ][ myCol + 1 ] != '=' ) {
        canMove[ RIGHT ] = true;

        //5/6/2013: don't move if you fall into a removed brick at bottom
        if(myRow + 1 == FIELD_ROW_COUNT - 1 && world[myRow + 1][myCol + 1] == '-' && nobodyAtPosition(myRow + 1, myCol + 1 , enemies))
        canMove[RIGHT] = false;

        if(canDigRightAtPos(runners[0])) canDigRight = canDig;
      }

      if ( myRow > 0 && world[ myRow ][ myCol ] == 'H' && world[ myRow - 1 ][ myCol ] != '=' ) {
        canMove[ TOP ] = true;
      }
      // 5/6/2013: if there's something in the hole you cannot go down
      if ( myRow + 1 < FIELD_ROW_COUNT && world[ myRow + 1 ][ myCol ] != '=' ) {
        canMove[ BOTTOM ] = true;
        if(world[ myRow + 1 ][ myCol ] == '-' && (!nobodyAtPosition(myRow + 1, myCol, enemies) || (runners[1].r == myRow + 1 && runners[1].c == myCol))) canMove[BOTTOM] = false;
      }

      // First, try to trap an enemy if we can.
      // 5/6/2013: dig when you are threaten
      //need update dig when you are threaten or opponent approaching towards
      if ( canDigLeft && approachingLeft && threat[LEFT]) {
        move = "DIG_LEFT";
      } else if ( canDigRight && approachingRight && threat[RIGHT]) {
        move = "DIG_RIGHT";
      } else {
        vector< i4 > moves;

        // First, try to select from threat-free moves.
        // 6/6/2013: count number of nearby enemy, but it seems not work
        // try to go to the nearest gold
        for ( int i = 0; i < 4; i++ )
          if ( canMove[ i ] && !threat[ i ] && !isAround(myRow + dRow[i], myCol + dCol[i], enemies)) {
            int tmp2 = countNearbyEnemy(myRow + dRow[i], myCol + dCol[i], enemies);
            int tmp1 = getMinDistanceToGold(myRow + dRow[i], myCol + dCol[i], enemies, i) + 1;
            moves.push_back( mp(mp(tmp1, tmp2), make_pair( visitTime[ myRow + dRow[ i ] ][ myCol + dCol[ i ] ], i )));
          }

        //also push DIG_LEFT and DIG_RIGHT
        if(canDigLeft) {
            int tmp2 = countNearbyEnemy(myRow + 1, myCol - 1, enemies);
            int tmp1 = getMinDistanceToGold(myRow + 1, myCol - 1, enemies, 4) + 3;
            moves.push_back( mp(mp(tmp1, tmp2), make_pair( visitTime[ myRow ][ myCol ], 4 )));
        }

        if(canDigRight) {
            int tmp2 = countNearbyEnemy(myRow + 1, myCol + 1, enemies);
            int tmp1 = getMinDistanceToGold(myRow + 1, myCol + 1, enemies, 5) + 3;
            moves.push_back( mp(mp(tmp1, tmp2), make_pair( visitTime[ myRow ][ myCol ], 5 )));
        }

        // If there are none, chose from among any other moves.
        // 5/6/2013: you should take no action if there's no good move.
        /*if ( moves.size() == 0 ) {
          for ( int i = 0; i < 4; i++ )
            if ( canMove[ i ] )
              moves.push_back( make_pair( visitTime[ myRow + dRow[ i ] ][ myCol + dCol[ i ] ], i ) );
        }*/

        if ( moves.size() ) {
          // Randomly choose among equally good moves.
          //random_shuffle( moves.begin(), moves.end() );
          sort( moves.begin(), moves.end() );

          move = moveName[ moves.front().second.ss ];

        }
      }
    }

    // Send the chosen move to the game.
    cout << move << endl;
  }
}
