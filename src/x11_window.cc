#include "window_platform.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/Xlib.h>

#include "x11_window.h"

// TODO
void X11ToggleFullscreen() {
}

// TODO
void X11GetProgramFilename() {
}

// TODO
void X11BuildProgramPathFilename() {
}

// TODO: This should be header macro
void DEUBUG_PLATFORM_FREE_FILE_MEMORY() {
}

// TODO: This should be header macro
void DEBUG_PLATFORM_READ_ENTIRE_FILE() {
}

// TODO: This should be header macro
void DEBUG_PLATFORM_WRITE_ENTIRE_FILE() {
}

// TODO
void X11GetLastWriteTime() {
}

// TODO
void X11LoadGameCode() {
}

// TODO
void X11UnloadGameCode() {
}

// TODO: How do you do this on Linux?
void X11LoadXInput() {
}

// TODO: This is going to need a lot of research
void X11InitSound() {
}

// TODO
void X11GetWindowDimension() {
}

// TODO
void X11ResizeBlitBufferSize() {
}

// TODO
void X11DisplayBufferInWindow() {
}

// TODO
void X11ClearBuffer() {
}

// TODO
void X11FillSoundBuffer() {
}

// TODO
void X11ProcessKeyboardMessage() {
}

// TODO
void X11GetInputFileLocation() {
}

// TODO
void X11BeginRecordingInput() {
}

// TODO
void X11EndRecordingInput() {
}

// TODO
void X11BeginInputPlayBack() {
}

// TODO
void X11RecordInput() {
}

// TODO
void X11PlayBackInput() {
}

// TODO
void X11GetWallClock() {
}

// TODO
void X11GetSoundsElapsed() {
}

int main(int argc, char *argv[]) {
  Display *display;
  Visual *visual;
  int depth;
  int text_x;
  int text_y;
  XSetWindowAttributes frame_attributes;
  Window frame_window;
  XFontStruct *fontinfo;
  XGCValues gr_values;
  GC graphical_context;
  XEvent event;

  display = XOpenDisplay(NULL);
  visual = DefaultVisual(display, 0);
  depth = DefaultDepth(display, 0);

  frame_attributes.background_pixel = XWhitePixel(display, 0);
  /* create the application window */
  frame_window =
      XCreateWindow(display, XRootWindow(display, 0), 0, 0, 400, 400, 5, depth,
                    InputOutput, visual, CWBackPixel, &frame_attributes);
  XStoreName(display, frame_window, "Hello World Example");
  XSelectInput(display, frame_window, ExposureMask | StructureNotifyMask);

  fontinfo = XLoadQueryFont(display, "10x20");
  gr_values.font = fontinfo->fid;
  gr_values.foreground = XBlackPixel(display, 0);
  graphical_context =
      XCreateGC(display, frame_window, GCFont + GCForeground, &gr_values);
  XMapWindow(display, frame_window);

  for (;;) {
    XNextEvent(display, (XEvent *)&event);
    switch (event.type) {
    case Expose: {
      XWindowAttributes window_attributes;
      int font_direction, font_ascent, font_descent;
      XCharStruct text_structure;
      XGetWindowAttributes(display, frame_window, &window_attributes);
      break;
    }
    default:
      break;
    }
  }
  return (0);
}
