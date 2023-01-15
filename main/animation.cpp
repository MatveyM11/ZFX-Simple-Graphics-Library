g++ -o xpng.out xpng.cpp -lX11 -lXpm -g//compile - 

#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/xpm.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    Display *display;
    Window window;
    XEvent event;
    int screen;
    XpmAttributes attribs;
    Pixmap pixmap;
    int x = 150;
    int y = 150;

    // Open the X11 display
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        printf("Cannot open display\n");
        return 1;
    }

    // Get the default screen
    screen = DefaultScreen(display);

    // Create a window
    window = XCreateSimpleWindow(display, RootWindow(display, screen), x, y, 500, 500, 1, BlackPixel(display, screen), WhitePixel(display, screen));

    // Select input events
    XSelectInput(display, window, ExposureMask | KeyPressMask);

    // Map the window to the screen
    XMapWindow(display, window);

    // Set the XpmSize attribute for the XpmReadFileToPixmap function
    attribs.valuemask = XpmSize;

    // Loop through a series of XPM image files
for (int i = 1; i <= 5; i++) {
char filename[256];
sprintf(filename, "../resources/sprites/mech%d.xpm", i);
XpmReadFileToPixmap(display, window, filename, &pixmap, NULL, &attribs);
XImage *image = XGetImage(display, pixmap, 0, 0, attribs.width, attribs.height, AllPlanes, ZPixmap);
XPutImage(display, window, DefaultGC(display, screen), image, 0, 0, x, y, attribs.width, attribs.height);
XFlush(display);
usleep(1000000);
}
//Force display to be updated
XFlush(display);

// Close the display
XCloseDisplay(display);
return 0;
}