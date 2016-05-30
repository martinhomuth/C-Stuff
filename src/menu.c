#include <X11/Xlib.h> // Every Xlib program must include this
#include <assert.h>   // I include this to test return values the lazy way
#include <unistd.h>   // So we got the profile for 10 seconds#include <stdio.h>
#include <stdio.h>

/* child window headers */
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>

int main()
{

	/* connect to the X server */
	Display *dpy = XOpenDisplay(NULL);
	assert(dpy);

	int screen = DefaultScreen(dpy);

	/* black and white are the only asserted colors I can get on every machine */
	int blackColor = BlackPixel(dpy, DefaultScreen(dpy));
	int whiteColor = WhitePixel(dpy, DefaultScreen(dpy));

	/* parent window */
	Window w = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy), 0, 0,
				     200, 300, 1, blackColor, whiteColor);

	/* register for structure events */
	XSelectInput(dpy, w, StructureNotifyMask | ConfigureNotify);

	/* "map" the window */
	XMapWindow(dpy, w); /* this is an asynchronous call */

	/* child window */
	Window cw1 = XCreateSimpleWindow(dpy, w, 20, 20,
					 80, 50, 1, blackColor, whiteColor);

	Window cw2 = XCreateSimpleWindow(dpy, w, 110, 20,
					 80, 50, 1, blackColor, whiteColor);


	int x, y, width, height;
	Window root_window;
	Colormap colormap;
	XColor button_color;
	XColor lightgray_color, darkgray_color;
	XGCValues gcv_lightgray, gcv_darkgray;
	GC gc_lightgray, gc_darkgray;

	XSelectInput(dpy, cw1, StructureNotifyMask | ExposureMask);
	XSelectInput(dpy, cw2, StructureNotifyMask | ExposureMask);
	XMapWindow(dpy, cw1);
	XMapWindow(dpy, cw2);

	/* Create a "Graphics Context" */
	/* This is used to store drawing settings such as line thickness */
	GC gc = XCreateGC(dpy, w, 0, NULL);
	/* set the drawing color */
	XSetForeground(dpy, gc, blackColor);

	colormap = DefaultColormap(dpy, screen);
	XParseColor(dpy, colormap, "rgb:cc/cc/cc", &button_color);
	XAllocColor(dpy, colormap, &button_color);

	XParseColor(dpy, colormap, "rgb:ee/ee/ee", &lightgray_color);
	XAllocColor(dpy, colormap, &lightgray_color);
	gcv_lightgray.foreground = lightgray_color.pixel;
	gcv_lightgray.background = button_color.pixel;
	gc_lightgray = XCreateGC(dpy, RootWindow(dpy, screen),
				 GCForeground | GCBackground, &gcv_lightgray);

	XParseColor(dpy, colormap, "rgb:88/88/88", &darkgray_color);
	XAllocColor(dpy, colormap, &darkgray_color);
	gcv_darkgray.foreground = darkgray_color.pixel;
	gcv_darkgray.background = button_color.pixel;
	gc_darkgray = XCreateGC(dpy, RootWindow(dpy, screen),
				 GCForeground | GCBackground, &gcv_darkgray);

	width = 80;
	height = 30;
	Window button = XCreateSimpleWindow(dpy, w, 20, 120,
					 width, height, 1, blackColor, button_color.pixel);
	XSelectInput(dpy, button, StructureNotifyMask | ExposureMask
		     | ButtonPressMask | ButtonReleaseMask);
	XMapWindow(dpy, button);


	/* The event loop waiting for events from the server */
	for(;;) {
		XEvent e;
		XNextEvent(dpy, &e);
		if (e.xany.window == cw1) {
			printf("cw1 event\n");
			if (e.type == Expose) {
				printf("expose win 1 event\n");
				XDrawLine(dpy, cw1, DefaultGC(dpy, screen), 10, 10, 140, 40);
				XDrawArc(dpy, cw1, gc, 10, 10, 40, 40, 10, 90);
			}
		}

		if (e.xany.window == cw2) {
			printf("cw2 event\n");
			if (e.type == Expose) {
				printf("expose win 2 event\n");
				XDrawLine(dpy, cw2, DefaultGC(dpy, screen), 10, 10, 140, 40);
			}
		}

		if (e.xany.window == button && e.type == Expose) {
				XDrawLine(dpy, button, gc_lightgray,
					  0, 0, width - 1, 0);
				XDrawLine(dpy, button, gc_lightgray,
					  0, 0, 0, height - 1);
				XDrawLine(dpy, button, gc_darkgray,
					  width - 1, width - 1, width - 1, 0);
				XDrawLine(dpy, button, gc_darkgray,
					  1, height - 1, width - 1, height - 1);
		}

		if (e.type == ButtonPress) {
			if (e.xbutton.button == 1) {
				XDrawLine(dpy, button, gc_darkgray,
					  0, 0, width - 1, 0);
				XDrawLine(dpy, button, gc_darkgray,
					  0, 0, 0, height - 1);
				XDrawLine(dpy, button, gc_lightgray,
					  width - 1, width - 1, width - 1, 0);
				XDrawLine(dpy, button, gc_lightgray,
					  1, height - 1, width - 1, height - 1);
			}

		}

		if (e.type == ButtonRelease) {
			if (e.xbutton.button == 1) {
				XDrawLine(dpy, button, gc_lightgray,
					  0, 0, width - 1, 0);
				XDrawLine(dpy, button, gc_lightgray,
					  0, 0, 0, height - 1);
				XDrawLine(dpy, button, gc_darkgray,
					  width - 1, width - 1, width - 1, 0);
				XDrawLine(dpy, button, gc_darkgray,
					  1, height - 1, width - 1, height - 1);
			}
		}

		XFlush(dpy);
	}




	printf("I am totally a menu\n");
	return 0;
}
