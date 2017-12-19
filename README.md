# SimpleFSM
A really, really simple finite state machine framework

## Usage

#### Import SimpleFSM.h and define your states in your FSM implementation .h

```C
#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include "SimpleFSM.h"

SimpleFSM traffic_light_sm;

STATE(GREEN);
STATE(YELLOW);
STATE(RED);

#endif // TRAFFIC_LIGHT_H
```

#### In your .c file, implement the states logic

```C
#include "traffic_light.h"

STATE(GREEN) {
  if(FIRST) {
    tick_count = 0;
    set_red_light(false);
    set_green_light(true);
  }
  
  //LOGIC HERE
  
  tick_count++;
  
  if(tick_count > MAX_TICKS_IN_GREEN)
    NEXT_STATE(YELLOW);
}

STATE(YELLOW) {
  if(FIRST) {
    tick_count = 0;
    set_green_light(false);
    set_yellow_light(true);
  }
  
  tick_count++;
  
  if(tick_count > MAX_TICKS_IN_YELLOW)
    NEXT_STATE(RED);
}
```
and so on...

#### Init and exec your state machine somewhere else

```C
INIT(traffic_light_sm, GREEN);

while(1) {
  EXEC(traffic_light_sm);
  
  //YOU CAN INSERT SOME TIME DELAY HERE
  
}

```

#### You can also compare the state machine current state
```C
if(COMPARE(traffic_light_sm, RED)) {
  EXEC(another_sm, ANY_ANOTHER_SM_STATE);
}
```

# Acknoledgements

Many thanks to Professor [Afonso Miguel](http://afonsomiguel.com)
