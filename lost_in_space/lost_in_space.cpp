#include "lost_in_space.h"
#include "player.h"
#include "splashkit.h"

// bitmap game_bitmap(power_up_kind kind)
// {
// }

game_data new_game(player_data &player, vector<power_up_data> &power_ups)
{
  game_data game;

  game.player = player;
  game.power_ups = power_ups;

  // for (int i = 0; i < game.power_ups.size(); i++)
  // {
  //   power_ups.push_back(game.power_ups[i]);
  // }
  
  // game.power_ups = power_ups;

  return game;
}

void update_game(game_data &game_to_update)
{
  // game_data game;
  // vector<game_data> power_up;
  update_player(game_to_update.player);

  for (int i = 0; i < game_to_update.power_ups.size(); i++)
  {
    update_power_up(game_to_update.power_ups[i]);
    // game_to_update.power_ups.push_back(game_to_update.power_ups[i]);
  }
}

game_data add_power_up(double x, double y)
{
  game_data game;

  game.power_ups.push_back(new_power_up(x, y));

  // power_up_data power_up;
  // // power_up = new_power_up(100, 120);
  return game;
}

void draw_game(const game_data &game_to_draw)
{

  clear_screen(COLOR_BLACK);

  draw_player(game_to_draw.player);

  //looping through the power ups
  for (int i = 0; i < game_to_draw.power_ups.size(); i++)
  {

    draw_power_up(game_to_draw.power_ups[i]);

    // write_line("power ups drawn");
  }

  refresh_screen(60);
}

// void update_game(game_data &power_up_to_update)
