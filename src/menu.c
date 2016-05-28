#include <X11/Xlib.h> // Every Xlib program must include this
#include <assert.h>   // I include this to test return values the lazy way
#include <unistd.h>   // So we got the profile for 10 seconds#include <stdio.h>
#include <stdio.h>

int main()
{

	/* connect to the X server */
	Display *dpy = XOpenDisplay(NULL);
	assert(dpy);

	/* black and white are the only asserted colors I can get on every machine */
	int blackColor = BlackPixel(dpy, DefaultScreen(dpy));
	int whiteColor = WhitePixel(dpy, DefaultScreen(dpy));

	/* Create the window */
	Window w = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy), 0, 0,
				     200, 100, 1, whiteColor, blackColor);

	/* register for structure events */
	XSelectInput(dpy, w, StructureNotifyMask | ConfigureNotify);

	/* "map" the window */
	XMapWindow(dpy, w); /* this is an asynchronous call */

	/* Create a "Graphics Context" */
	/* This is used to store drawing settings such as line thickness */
	GC gc = XCreateGC(dpy, w, 0, NULL);

	/* set the drawing color */
	XSetForeground(dpy, gc, whiteColor);

	/* The event loop waiting for events from the server */
	for(;;) {
		XEvent e;
		XNextEvent(dpy, &e);
		if (e.type == MapNotify)
			printf("mapNotify event\n");

		if (e.type == GraphicsExpose)
			printf("GraphicsExpose event\n");

		XDrawLine(dpy, w, gc, 10, 180, 180, 20);
		XDrawLine(dpy, w, gc, 10, 20, 180, 180);
		/* tell the server what to do */
		XFlush(dpy);

	}


	printf("I am totally a menu\n");
	return 0;
}
