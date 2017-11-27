#include <X11/Xlib.h>
#include <X11/Xlibint.h>
#include <X11/Xproto.h>
#include <X11/Xatom.h>
#include <X11/Xutil.h>
#include <sys/types.h>
#include <pthread.h>
#include <pwd.h>
#include <malloc.h>
#include <unistd.h>

int main()
{
  XInitThreads();

  Display* dpy = XOpenDisplay(0);
  
  XVisualInfo vi;
  XMatchVisualInfo(dpy, DefaultScreen(dpy), 32, TrueColor, &vi);

  XSetWindowAttributes wa;
  wa.colormap = XCreateColormap(dpy,
                                DefaultRootWindow(dpy),
                                vi.visual,
                                AllocNone);
  wa.border_pixel = 0;
  wa.background_pixel = 0;
  wa.override_redirect = True;
  wa.event_mask = 0;

  Window win;
  int x = 100, y = 100, width = 100, height = 100;
  int screen = DefaultScreen(dpy);

  Window root = RootWindow(dpy, screen);

  win = XCreateWindow(dpy, root, x, y, width, height, 0,
                      vi.depth, InputOutput, vi.visual,
                      CWOverrideRedirect|CWEventMask|CWColormap|CWBorderPixel|CWBackPixel
                      ,&wa);
  
  //dc->gc = XCreateGC(dc->dpy, win, 0, NULL);

  //resizedc(dc, width, height, &vinfo, &wa);
  XSelectInput(dpy, win, ExposureMask | KeyPressMask);
  XMapWindow(dpy, win);
  XMapRaised(dpy, win);
  

  XEvent e;
  
  while(1)
  {
    XNextEvent(dpy, &e);

    
  }

  XCloseDisplay(dpy);
  
  return 0;
}
