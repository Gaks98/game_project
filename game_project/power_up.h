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
}


// converts power_up_kinds values to images
power_up_bitmap(const power_up_data &power_up);

#endif