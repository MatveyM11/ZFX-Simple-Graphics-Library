#include <stdio.h>
#include <cstdio>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/Xdbe.h>
#include <unistd.h>

void draw_pixels_rectangle(Display *dpy, Window win, GC gc, int matrix_image[25][20], int x, int y)
{
    int i, j;
    XSetForeground(dpy, gc, BlackPixel(dpy, DefaultScreen(dpy)));
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 25; j++)
        {
            if (matrix_image[j][i] != 0)
            {
                XFillRectangle(dpy, win, gc, i + x, j + y, 1, 1);
            }
        }
    }
    XFlush(dpy);
}

void draw_shapes(Display *dpy, Window win, GC gc)
{
    XPoint points[4];
    points[0].x = 40;
    points[0].y = 40;
    points[1].x = 120;
    points[1].y = 120;
    points[2].x = 120;
    points[2].y = 40;
    points[3].x = 40;
    points[3].y = 40;
    // XDrawLines(dpy, win, gc, points, 4, CoordModeOrigin);                          // Set the fill color
    XFillPolygon(dpy, win, gc, points, 4, Complex, CoordModeOrigin); // Fill the triangle with the specified color

    // XFillArc(dpy, win, gc, 200, 50, 100, 100, 0, 360 * 64);
    XDrawArc(dpy, win, gc, 200, 50, 100, 100, 0, 360 * 64);
}

 int matrix_image[25][20] = {
    {1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1},
    {0 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,0 ,0},
    {0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0},
    {0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,0},
    {0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0},
    {0 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,0},
    {0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0},
    {1 ,1 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0},
    {1 ,0 ,0 ,0 ,1 ,1 ,0 ,1 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,1 ,1},
    {1 ,0 ,0 ,0 ,1 ,0 ,0 ,1 ,1 ,0 ,0 ,0 ,1 ,0 ,1 ,1 ,0 ,0 ,0 ,1},
    {1 ,1 ,0 ,0 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,1 ,1 ,0 ,0 ,1 ,0 ,0 ,0 ,1},
    {0 ,1 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,1 ,1},
    {0 ,1 ,0 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,1 ,0},
    {0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,0 ,1 ,0},
    {0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0},
    {0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0},
    {0 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0},
    {0 ,0 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,0},
    {0 ,0 ,0 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,0 ,0},
    {0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0 ,0 ,1 ,0 ,1 ,0 ,1 ,1 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0 ,0 ,1 ,0 ,1 ,0 ,1 ,1 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0 ,0 ,1 ,0 ,1 ,0 ,1 ,1 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,1 ,1 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0},
    {0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0}
};


int main(int argc, char *argv[])
{
    Display *dpy;
    Window win;
    XEvent e;
    XdbeBackBuffer back_buffer;
    XdbeSwapInfo swap_info;
    XGCValues gc_values;
    GC gc;
    int y = 50;
    bool running = true;

    dpy = XOpenDisplay(NULL);

    if (dpy == NULL)
    {
        fprintf(stderr, "Failed to open display\n");
        return -1;
    }

    int screen = DefaultScreen(dpy);
    win = XCreateSimpleWindow(dpy, RootWindow(dpy, screen), 0, 0, 300, 300, 0, WhitePixel(dpy, screen), BlackPixel(dpy, screen));
    XStoreName(dpy, win, "Rectangle Animation");
    XSelectInput(dpy, win, ExposureMask | KeyPressMask);
    XMapWindow(dpy, win);

    gc = XCreateGC(dpy, win, 0, &gc_values);

    XdbeScreenVisualInfo *vis_info;
    int num_screens;
    vis_info = XdbeGetVisualInfo(dpy, &win, &num_screens);
    if (!vis_info)
    {
        fprintf(stderr, "XdbeGetVisualInfo() failed.\n");
        return -1;
    }

    back_buffer = XdbeAllocateBackBufferName(dpy, win, XdbeBackground);
    swap_info.swap_window = win;
    swap_info.swap_action = XdbeBackground;
    usleep(1000000); // sleep for 1 second
    while (running)
    {
        if (y >= 200)
        {
            running = !running;
            break;
        }

        XSetForeground(dpy, gc, WhitePixel(dpy, screen));
        XFillRectangle(dpy, back_buffer, gc, 0, 0, 300, 300);
        XSetForeground(dpy, gc, BlackPixel(dpy, screen));
        XDrawRectangle(dpy, back_buffer, gc, 50, y, 200, 200);

        XColor red;
        XAllocNamedColor(dpy, DefaultColormap(dpy, screen), "red", &red, &red);
        XSetForeground(dpy, gc, red.pixel);
        XDrawString(dpy, back_buffer, gc, 150, 50, "Hello World!", 12);

        draw_shapes(dpy, back_buffer, gc);

         draw_pixels_rectangle(dpy, back_buffer, gc, matrix_image, 100, 100);

        XdbeSwapBuffers(dpy, &swap_info, 1);
        XFlush(dpy);
        y += 10;
        usleep(1000000); // sleep for 1 second
    }

    XFreeGC(dpy, gc);
    XdbeFreeVisualInfo(vis_info);
    XCloseDisplay(dpy);
    return 0;
}
