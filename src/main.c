#include "BasicButton.h"
#include "lvgl.h"
#include <SDL.h>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	// Unused command line arguments (required by SDL).
	(void)argc;
	(void)argv;

	// Initialize LVGL.
	lv_init();

	// Use SDL to create a display.
	lv_display_t* MyDisplay = lv_sdl_window_create(480, 320);
	lv_display_set_default(MyDisplay);

	// Create the mouse input device.
	lv_indev_t* mouse = lv_sdl_mouse_create();
	lv_indev_set_display(mouse, MyDisplay);

	// Create a default group.
	lv_group_t* MyDefaultGroup = lv_group_create();
	lv_group_set_default(MyDefaultGroup);

	// Create the GUI.
	BasicButton();

	// Periodically call the lvgl timer handler.
	while (1) {
		lv_timer_handler();
		Sleep(10);
	}

	return 0;
}
