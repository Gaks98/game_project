#include "power_up.h"
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

bitmap light_bitmap(const power_up_data &power_up)
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