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
    
    // set the icon for the window
    XWMHints *wm_hints = XAllocWMHints();
    wm_hints->flags = IconPixmapHint;
    wm_hints->icon_pixmap = pixmap;
    XSetWMHints(display, window, wm_hints);
    XFree(wm_hints);
    
     // Create two more pixmaps
    Pixmap pixmap2;
    Pixmap pixmap3;
    XpmReadFileToPixmap(display, window, "../resources/sprites/mech101.xpm", &pixmap2, NULL, &attribs);
    XpmReadFileToPixmap(display, window, "../resources/sprites/mech110.xpm", &pixmap3, NULL, &attribs);


    // Infinite loop to wait for events
    while (1)
    {
        XNextEvent(display, &event);

        XImage *image;
        image = XGetImage(display, pixmap, 0, 0, attribs.width, attribs.height, AllPlanes, ZPixmap);
        XPutImage(display, window, DefaultGC(display, screen), image, 0, 0, x, y, attribs.width, attribs.height);

          // Draw the second image
        image = XGetImage(display, pixmap2, 0, 0, attribs.width, attribs.height, AllPlanes, ZPixmap);
        XPutImage(display, window, DefaultGC(display, screen), image, 0,0, 350, 50, attribs.width, attribs.height);
        
        // Draw the third image
        image = XGetImage(display, pixmap3, 0, 0, attribs.width, attribs.height, AllPlanes, ZPixmap);
        XPutImage(display, window, DefaultGC(display, screen), image, 0, 0, 350, 400, attribs.width, attribs.height);
    }
        // Close the connection to the X server
        XCloseDisplay(display);
        return 0;
        }
