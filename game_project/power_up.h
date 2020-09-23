#ifndef LOST_IN_SPACE_POWER_UP
#define LOST_IN_SPACE_POWER_UP

#include "splashkit.h"
#include <vector>

using namespace std;

enum power_up_kind
{
  FUEL,
  SHIELD,
  POWER,
  POTION,
  DIAMOND,
  STAR
};

/**
 * The power_up_data keeps track of all of the information related to the power_up.
 * 
 * @field   power_up_sprite   The power_up's sprite - used to track position and movement
 * @field   kind            Current kind of power_up 
 */
struct power_up_data
{
  sprite power_up_sprite;
  power_up_kind kind;
};

// converts power_up_kinds values to images

void load_resources();

power_up_data new_power_up();

#endif