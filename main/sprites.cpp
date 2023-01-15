// compile - g++ -o xpng.out xpng.cpp -lX11 -lXpm -g

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/xpm.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    Display *display;
    Window window;
    XEvent event;
    int screen;
    XpmAttributes attribs;
    Pixmap pixmap;
    int x = 150;
    int y = 150;

    // Open a connection to the X server
    display = XOpenDisplay(NULL);
    if (display == NULL)
    {
        fprintf(stderr, "Cannot open display\n");
        return 1;
    }

    // Get the default screen of the display
    screen = DefaultScreen(display);

    // Create a simple window
    window = XCreateSimpleWindow(display, RootWindow(display, screen), x, y, 500, 500, 1, BlackPixel(display, screen), WhitePixel(display, screen));

    // Select the input events that the program is interested in receiving
    XSelectInput(display, window, ExposureMask | KeyPressMask);

    // Map the window to the screen
    XMapWindow(display, window);

    // Read image file and create a pixmap
    attribs.valuemask = XpmSize;
    XpmReadFileToPixmap(display, window, "../resources/sprites/mech100.xpm", &pixmap, NULL, &attribs);

    // Infinite loop to wait for events
    while (1)
    {
        XNextEvent(display, &event);

        // Get the image from the pixmap and draw it in the window
        XImage *image;
        image = XGetImage(display, pixmap, 0, 0, attribs.width, attribs.height, AllPlanes, ZPixmap);
        XPutImage(display, window,
        // Close the connection to the X server
        XCloseDisplay(display);
        return 0;
        }
