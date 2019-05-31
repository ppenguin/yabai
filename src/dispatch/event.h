#ifndef EVENTLOOP_EVENT_H
#define EVENTLOOP_EVENT_H

#define EVENT_CALLBACK(name) int name(void *context, int param1)
typedef EVENT_CALLBACK(event_callback);

static EVENT_CALLBACK(EVENT_HANDLER_APPLICATION_LAUNCHED);
static EVENT_CALLBACK(EVENT_HANDLER_APPLICATION_TERMINATED);
static EVENT_CALLBACK(EVENT_HANDLER_APPLICATION_FRONT_SWITCHED);
static EVENT_CALLBACK(EVENT_HANDLER_APPLICATION_ACTIVATED);
static EVENT_CALLBACK(EVENT_HANDLER_APPLICATION_DEACTIVATED);
static EVENT_CALLBACK(EVENT_HANDLER_APPLICATION_VISIBLE);
static EVENT_CALLBACK(EVENT_HANDLER_APPLICATION_HIDDEN);
static EVENT_CALLBACK(EVENT_HANDLER_WINDOW_CREATED);
static EVENT_CALLBACK(EVENT_HANDLER_WINDOW_DESTROYED);
static EVENT_CALLBACK(EVENT_HANDLER_WINDOW_FOCUSED);
static EVENT_CALLBACK(EVENT_HANDLER_WINDOW_MOVED);
static EVENT_CALLBACK(EVENT_HANDLER_WINDOW_RESIZED);
static EVENT_CALLBACK(EVENT_HANDLER_WINDOW_MINIMIZED);
static EVENT_CALLBACK(EVENT_HANDLER_WINDOW_DEMINIMIZED);
static EVENT_CALLBACK(EVENT_HANDLER_WINDOW_TITLE_CHANGED);
static EVENT_CALLBACK(EVENT_HANDLER_SPACE_CHANGED);
static EVENT_CALLBACK(EVENT_HANDLER_DISPLAY_ADDED);
static EVENT_CALLBACK(EVENT_HANDLER_DISPLAY_REMOVED);
static EVENT_CALLBACK(EVENT_HANDLER_DISPLAY_MOVED);
static EVENT_CALLBACK(EVENT_HANDLER_DISPLAY_RESIZED);
static EVENT_CALLBACK(EVENT_HANDLER_DISPLAY_CHANGED);
static EVENT_CALLBACK(EVENT_HANDLER_MOUSE_DOWN);
static EVENT_CALLBACK(EVENT_HANDLER_MOUSE_UP);
static EVENT_CALLBACK(EVENT_HANDLER_MOUSE_DRAGGED);
static EVENT_CALLBACK(EVENT_HANDLER_MOUSE_MOVED);
static EVENT_CALLBACK(EVENT_HANDLER_MISSION_CONTROL_ENTER);
static EVENT_CALLBACK(EVENT_HANDLER_MISSION_CONTROL_CHECK_FOR_EXIT);
static EVENT_CALLBACK(EVENT_HANDLER_MISSION_CONTROL_EXIT);
static EVENT_CALLBACK(EVENT_HANDLER_DOCK_DID_RESTART);
static EVENT_CALLBACK(EVENT_HANDLER_MENU_OPENED);
static EVENT_CALLBACK(EVENT_HANDLER_MENU_BAR_HIDDEN_CHANGED);
static EVENT_CALLBACK(EVENT_HANDLER_SYSTEM_WOKE);
static EVENT_CALLBACK(EVENT_HANDLER_DAEMON_MESSAGE);

#define EVENT_QUEUED    0
#define EVENT_PROCESSED 1

#define EVENT_SUCCESS      0
#define EVENT_MOUSE_IGNORE 1

struct event
{
    event_callback *handler;
    void *context;
    int param1;
    volatile int *status;
    volatile int *result;
};

#define event_create(event, type, data)\
    do {\
        event = malloc(sizeof(struct event));\
        event->context = data;\
        event->handler = &EVENT_HANDLER_##type;\
        event->param1 = 0;\
        event->status = 0;\
        event->result = 0;\
    } while (0)

#define event_create_p1(event, type, data, p1)\
    do {\
        event = malloc(sizeof(struct event));\
        event->context = data;\
        event->handler = &EVENT_HANDLER_##type;\
        event->param1 = p1;\
        event->status = 0;\
        event->result = 0;\
    } while (0)

#endif
