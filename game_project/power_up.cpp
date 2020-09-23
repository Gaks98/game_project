#include "power_up.h"
#include "player.h"
#include "splashkit.h"

void load_resources()
{
  load_bitmap("fuel", "fuel.png");
  load_bitmap("shield", "shield.png");
  load_bitmap("power", "power.png");
  load_bitmap("potion", "potion-on.png");
  load_bitmap("diamond", "diamond.png");
  load_bitmap("star", "star.png");
}

// converts power_up_kinds values to images
bitmap power_up_bitmap(power_up_data power_up)
{
  string bitmap_name;

  switch (power_up.kind)
  {
  case FUEL:
    bitmap_name = "fuel";
    break;
  case SHIELD:
    bitmap_name = "shield";
    break;
  case POWER:
    bitmap_name = "power";
    break;
  case POTION:
    bitmap_name = "potion";
    break;
  case DIAMOND:
    bitmap_name = "diamond";
    break;
  default:
    bitmap_name = "star";
  }

  return bitmap_named(bitmap_name);
}

// power_up_data new_power_up()
// {
//   power_up_data result;
//   bitmap default_bitmap = ship_bitmap(AQUARII);

//   // Create the sprite with 3 layers - we can turn on and off based
//   // on the ship kind selected
//   result.power_up_sprite = create_sprite(default_bitmap);

//   sprite_add_layer(result.power_up_sprite, ship_bitmap(GLIESE), "GLIESE");
//   sprite_add_layer(result.power_up_sprite, ship_bitmap(PEGASI), "PEGASI");

//   // Default to layer 0 = Aquarii so hide others
//   sprite_hide_layer(result.power_up_sprite, 1);
//   sprite_hide_layer(result.power_up_sprite, 2);

//   result.kind = AQUARII;

//   // Position in the centre of the initial screen
//   sprite_set_x(result.power_up_sprite, 380);
//   sprite_set_y(result.power_up_sprite, 380);

//   return result;
// }