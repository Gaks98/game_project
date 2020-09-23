#include "power_up.h"
// #include "player.h"
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
bitmap power_up_bitmap(power_up_kind kind)
{
  string bitmap_name;

  switch (kind)
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

power_up_data new_power_up(double x, double y)
{
  power_up_data result;
  result.kind = static_cast<power_up_kind>(rnd(6));
  bitmap default_bitmap = power_up_bitmap(result.kind);

  // Create the sprite with 3 layers - we can turn on and off based
  // on the ship kind selected
  result.power_up_sprite = create_sprite(power_up_bitmap(result.kind));

  // sprite_add_layer(result.power_up_sprite, power_up_bitmap(GLIESE), "GLIESE");
  // sprite_add_layer(result.power_up_sprite, power_up_bitmap(PEGASI), "PEGASI");

  // Default to layer 0 = Aquarii so hide others
  // sprite_hide_layer(result.power_up_sprite, 1);
  // sprite_hide_layer(result.power_up_sprite, 2);

  // Position in the centre of the initial screen
  sprite_set_x(result.power_up_sprite, x);
  sprite_set_y(result.power_up_sprite, y);

  //start power-ups with small random velocity
  sprite_set_dx(result.power_up_sprite, rnd() * 4 -2);

  return result;
}

void draw_power_up(const power_up_data &power_up_to_draw)
{
  draw_sprite(power_up_to_draw.power_up_sprite);
}