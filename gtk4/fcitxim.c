/*
 * SPDX-FileCopyrightText: 2010~2020 CSSlayer <wengxt@gmail.com>
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include "config.h"
#include "fcitximcontext.h"
#include "fcitximcontext5.h"
#include <gtk/gtk.h>
#include <gtk/gtkimmodule.h>

G_MODULE_EXPORT void g_io_im_fcitx5_load(GIOModule *module) {
    g_type_module_use(G_TYPE_MODULE(module));
    fcitx_im_context_register_type(G_TYPE_MODULE(module));
    fcitx_im_context5_register_type(G_TYPE_MODULE(module));

    g_io_extension_point_implement(GTK_IM_MODULE_EXTENSION_POINT_NAME,
                                   FCITX_TYPE_IM_CONTEXT, "fcitx", 10);
    g_io_extension_point_implement(GTK_IM_MODULE_EXTENSION_POINT_NAME,
                                   FCITX_TYPE_IM_CONTEXT5, "fcitx5", 10);
}

G_MODULE_EXPORT void g_io_im_fcitx5_unload(GIOModule *module) {
    g_type_module_unuse(G_TYPE_MODULE(module));
}
