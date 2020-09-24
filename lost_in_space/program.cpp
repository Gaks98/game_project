#include "splashkit.h"
#include "player.h"
#include "power_up.h"
#include "lost_in_space.h"

/**
 * Load the game images, sounds, etc.
 */
void load_resources()
{
    load_resource_bundle("game_bundle", "lost_in_space.txt");
}

/**
 * Entry point.
 * 
 * Manages the initialisation of data, the event loop, and quitting.
 */
int main()
{
    open_window("Lost In Space", 800, 800);
    load_resources();

    player_data player;
    player = new_player();

    vector<power_up_data> power_ups;
    power_ups.push_back(new_power_up(250,250));
    power_ups.push_back(new_power_up(150, 150));

    game_data game;
    game = new_game(player,power_ups);

    while ( not quit_requested() )
    {
        // Handle input to adjust player movement
        process_events();
        handle_input(game.player);

        // Perform movement and update the camera
        // update_player(game.player);
        update_game(game);
        // update_power_up(game.power_ups);

        // Redraw everything
        clear_screen(COLOR_BLACK);

        draw_text("SCORE: ", COLOR_WHITE, 0, 0, option_to_screen());
        draw_text("LOCATION: " + point_to_string(center_point(player.player_sprite)), COLOR_WHITE, 0, 10, option_to_screen());

        // including something stationary - it doesn't move
        // fill_rectangle(COLOR_WHITE, 400, 400, 10, 10);

        // as well as the player who can move
        // draw_player(game.player);
        draw_game(game);
        //draw_power_up(game.power_ups);

        refresh_screen(60);
    }

    return 0;
}