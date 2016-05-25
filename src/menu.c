#include <X11/Xlib.h> // Every Xlib program must include this
#include <assert.h>   // I include this to test return values the lazy way
#include <unistd.h>   // So we got the profile for 10 seconds#include <stdio.h>
#include <stdio.h>

#define NIL (0)       // A name for the void pointer

int main()
{

	Display *dpy = XOpenDisplay(NIL);
	assert(dpy);

	int blackColor = BlackPixel(dpy, DefaultScreen(dpy));
	int whiteColor = WhitePixel(dpy, DefaultScreen(dpy));

	/* Create the window */
	Window w = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy), 0, 0,
				     200, 100, 0, blackColor, blackColor);
	// We want to get MapNotify events

	XSelectInput(dpy, w, StructureNotifyMask);

	// Create a "Graphics Context"

	GC gc = XCreateGC(dpy, w, 0, NIL);

	// Tell the GC we draw using the white color

	XSetForeground(dpy, gc, whiteColor);

	// "Map" the window (that is, make it appear on the screen)

	XMapWindow(dpy, w);

	// Wait for the MapNotify event

	for(;;) {
		XEvent e;
		XNextEvent(dpy, &e);
		if (e.type == MapNotify)
			printf("mapNotify event\n");

		XDrawLine(dpy, w, gc, 10, 180, 180, 20);
		XDrawLine(dpy, w, gc, 10, 20, 180, 180);
		XFlush(dpy);

	}


	printf("I am totally a menu\n");
	return 0;
}
