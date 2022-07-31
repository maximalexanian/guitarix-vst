/*
 * Copyright (C) 2009, 2010 Hermann Meyer, James Warden, Andreas Degert
 * Copyright (C) 2011 Pete Shorthose
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 * ---------------------------------------------------------------------------
 *
 *    This is the gx_head GUI main class
 *
 * ----------------------------------------------------------------------------
 */

#include "guitarix.h"         // NOLINT

#include <glibmm/i18n.h>      // NOLINT

#include <iomanip>            // NOLINT
#include <cstring>            // NOLINT
#include <string>             // NOLINT

namespace gx_gui {

/****************************************************************
 ** class SelectJackControlPgm
 */

SelectJackControlPgm::SelectJackControlPgm(BaseObjectType* cobject, Glib::RefPtr<GxBuilder> bld, gx_engine::GxMachineBase& m)
    : Gtk::Window(cobject),
      description(),
      customstarter(),
      startercombo(),
      dontask(),
      machine(m),
      close() {
    signal_delete_event().connect(sigc::mem_fun(*this, &SelectJackControlPgm::on_delete_event));
    bld->find_widget("description", description);
    bld->find_widget("customstarter", customstarter);
    customstarter->set_text(machine.get_parameter_value<string>("ui.jack_starter"));
    bld->find_widget("startercombo", startercombo);
    const char *v_id = machine.get_parameter("ui.jack_starter_idx").getValueNames()[machine.get_parameter_value<int>("ui.jack_starter_idx")].value_id;
    int n = 0;
    Glib::RefPtr<Gtk::TreeModel> model = startercombo->get_model();
    for (Gtk::TreeIter i = model->children().begin(); i; ++i, ++n) {
	Glib::ustring s;
	i->get_value(1, s);
	if (s == v_id) {
	    startercombo->set_active(n);
	}
    }
    startercombo->signal_changed().connect(sigc::mem_fun(*this, &SelectJackControlPgm::on_starter_changed));
    bld->find_widget("dontask", dontask);
    dontask->set_active(!machine.get_parameter_value<bool>("ui.ask_for_jack_starter"));
    Gtk::Button *button;
    bld->find_widget("ok_button", button);
    button->signal_clicked().connect(
	sigc::mem_fun(*this, &SelectJackControlPgm::on_ok_button));
    bld->find_widget("cancel_button", button);
    button->signal_clicked().connect(
	sigc::mem_fun(*this, &SelectJackControlPgm::on_cancel_button));
    on_starter_changed();
}

SelectJackControlPgm::~SelectJackControlPgm() {
}

//static
SelectJackControlPgm* SelectJackControlPgm::create(gx_system::CmdlineOptions& opt, gx_engine::GxMachineBase& m) {
    Glib::RefPtr<GxBuilder> bld = GxBuilder::create_from_file(opt.get_builder_filepath("jackstarter.glade"), &m);
    SelectJackControlPgm *w;
    bld->get_toplevel_derived("selectjackstarter", w,
			    sigc::bind(sigc::ptr_fun(SelectJackControlPgm::create_from_builder), bld, sigc::ref(m)));
    return w;
}

bool SelectJackControlPgm::on_key_press_event(GdkEventKey *event) {
    if (event->keyval == GDK_KEY_Escape && (event->state & Gtk::AccelGroup::get_default_mod_mask()) == 0) {
	close();
	return true;
    }
    return Gtk::Window::on_key_press_event(event);
}

bool SelectJackControlPgm::on_delete_event(GdkEventAny* event) {
    close();
    return true;
}

void SelectJackControlPgm::on_starter_changed() {
    Gtk::TreeModel::iterator i = startercombo->get_active();
    if (!i) {
	return;
    }
    Glib::ustring s;
    i->get_value(2,s);
    description->set_markup(s);
    i->get_value(1, s);
    if (s == "other") {
	customstarter->show();
    } else {
	customstarter->hide();
    }
}

void SelectJackControlPgm::on_ok_button() {
    machine.set_parameter_value("ui.jack_starter", customstarter->get_text());
    Glib::ustring s;
    startercombo->get_active()->get_value(1, s);
    int n = machine.get_parameter("ui.jack_starter_idx").getInt().idx_from_id(s);
    if (n >= 0) {
	machine.set_parameter_value("ui.jack_starter_idx", n);
    } else {
	gx_print_error("load error", "starter id not found");
    }
    machine.set_parameter_value("ui.ask_for_jack_starter", !dontask->get_active());
    close();
}

void SelectJackControlPgm::on_cancel_button() {
    close();
}

/****************************************************************
 ** Jackstart Dialog
 */

// ----- pop up a dialog for starting jack
bool gx_start_jack_dialog(Glib::RefPtr<Gdk::Pixbuf> gw_ib) {
    // --- run dialog and check response
    const guint nchoices    = 3;

    const char* labels[]    = {
            _("Start Jack"), _("Ignore Jack"), _("Exit")
        };

    const gint  responses[] = {
            GTK_RESPONSE_YES, GTK_RESPONSE_NO, GTK_RESPONSE_CANCEL
        };

    gint response =
        gx_gui::gx_nchoice_dialog_without_entry(
            _(" Jack Starter "),
            _("\n                            WARNING                    \n\n"
	      "   The jack server is not currently running\n"
	      "   You can choose to activate it or terminate gx_head   \n\n"
	      "       1) activate jack   \n"
	      "       2) ignore jack, start gx_head anyway   \n"
	      "       3) exit gx_head   \n"
	      "\n"
	      "   use options menu \"jack startup control\" to\n"
	      "   set a jack start program\n"),
            nchoices,
            labels,
            responses,
            GTK_RESPONSE_YES,
	    gw_ib);

    // we are cancelling
    bool retstat = false;

    switch (response) {
    case GTK_RESPONSE_NO:
        //set_jack_down(true); FIXME
        break;

    case GTK_RESPONSE_CANCEL:
    GxExit::get_instance().exit_program();
        break;

    case GTK_RESPONSE_YES:
        retstat = true;
        break;
    default:
        GxExit::get_instance().exit_program();
        break;
    
    }

    // start jack
    return retstat;
}
} // end namespace gx_gui

