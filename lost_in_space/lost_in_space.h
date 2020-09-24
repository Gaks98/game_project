#ifndef LOST_IN_SPACE
#define LOST_IN_SPACE

#include "splashkit.h"
#include "player.h"
#include "power_up.h"

#include <vector>
using std::vector;

struct game_data
{
  player_data player;
  vector<power_up_data> power_ups;
  // game_timer timer;
};
// game_data new_game(player_data &player);
game_data new_game(player_data &player, vector<power_up_data> &power_ups);
void update_game(game_data &game_to_update);
void draw_game(const game_data &game_to_draw);


#endif