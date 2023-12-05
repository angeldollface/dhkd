#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  Display *display;
  Window window;
  XEvent event;
  int s;
  
  display =XOpenDisplay(NULL);
  if (display == NULL){
    printf("Connection to an X Server instance could not be established!\n");
  }
  else {
    s = DefaultScreen(display);
    window = XCreateSimpleWindow(display, RootWindow(display,s), 10, 10, 200, 200, 1, BlackPixel(display,s), WhitePixel(display,s));
    XSelectInput(display, window, KeyPressMask | KeyReleaseMask );
    //XMapWindow(display, window);
    while (1){
      XNextEvent(display, &event);
      if (event.type == KeyPress) {
	printf("Keypress: %x\n", event.xkey.keycode);
	if (event.xkey.keycode == 0x09){
	  break;
	}
	else {}
      }
      else {}
    }
    XCloseDisplay(display);
  }
  return 0;
}
