#ifndef TAT_DISPLAY_CONTROL_H_
#define TAT_DISPLAY_CONTROL_H_

#include <inttypes.h>
#include <stdbool.h>

void tat_display_control_init(void);
int tat_display_control_sleep_ctrl(bool on);

#endif /* TAT_DISPLAY_CONTROL_H_ */