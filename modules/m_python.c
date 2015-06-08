#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "send.h"
#include "hook.h"
#include "modules.h"

#include <Python.h>
#include <string.h>

static void py_process_hook(void *hdata);

mapi_hfn_list_av1 ircd_event_handler_list[] = {
    { "burst_client", (hookfn) py_process_hook },
    { "burst_channel", (hookfn) py_process_hook },
    { "burst_finished", (hookfn) py_process_hook },
    { "server_introduced", (hookfn) py_process_hook },
    { "server_eob", (hookfn) py_process_hook },
    { "client_exit", (hookfn) py_process_hook },
    { "umode_changed", (hookfn) py_process_hook },
    { "new_local_user", (hookfn) py_process_hook },
    { "new_remote_user", (hookfn) py_process_hook },
    { "introduce_client", (hookfn) py_process_hook },
    { "can_kick", (hookfn) py_process_hook },
    { "privmsg_user", (hookfn) py_process_hook },
    { "privmsg_channel", (hookfn) py_process_hook },
    { "conf_read_start", (hookfn) py_process_hook },
    { "conf_read_end", (hookfn) py_process_hook },
    { NULL, NULL }
};

mapi_clist_av1 ircd_command_list[] = {
    NULL
};

mapi_hlist_av1 ircd_hook_register_list[] = {
    { NULL, NULL }
};

static int mod_init(void) {
    /* This is where the Python initialization 
     * will take place in the future.
     */
    
    return 0;
}

static void mod_deinit(void) {
    /* Here, we will unload all loaded Python
     * modules and then drop out the interpreter.
     */
    
    return;
}

static void py_process_hook(void *hdata) {
    /* Fire events through the Python module API.
     * Easy, right?
     */
    
    return;
}

// Declare the MAPI header.
DECLARE_MODULE_AV1(
    m_python, // name
    mod_init, // initializer
    mod_deinit, // deinitializer
    ircd_command_list, // command list
    ircd_hook_register_list, // hooks to register
    ircd_event_handler_list, // events to catch
    "$Revision: 1 $");
