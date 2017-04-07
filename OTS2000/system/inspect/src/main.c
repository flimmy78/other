/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

#ifdef G_OS_WIN32
gchar *package_prefix = PACKAGE_PREFIX;
gchar *package_data_dir = PACKAGE_DATA_DIR;
gchar *package_locale_dir = PACKAGE_LOCALE_DIR;
#endif

int
main (int argc, char *argv[])
{
  GtkWidget *dialog1;

  gchar *pixmap_dir;
#ifdef G_OS_WIN32
  package_prefix = g_win32_get_package_installation_directory (NULL, NULL);
  package_data_dir = g_build_filename (package_prefix, "share", NULL);
  package_locale_dir = g_build_filename (package_prefix, "share", "locale", NULL);
#endif

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, package_locale_dir);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  pixmap_dir = g_build_filename (package_data_dir, PACKAGE, "pixmaps", NULL);
  add_pixmap_directory (pixmap_dir);
  g_free (pixmap_dir);


  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  dialog1 = create_dialog1 ();
  gtk_widget_show (dialog1);
  g_signal_connect ((gpointer) dialog1, "destroy", G_CALLBACK(gtk_main_quit),
                    NULL);

  gtk_main ();

#ifdef G_OS_WIN32
  g_free (package_prefix);
  g_free (package_data_dir);
  g_free (package_locale_dir);
#endif

  return 0;
}
#ifdef _MSC_VER
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
  return main (__argc, __argv);
}
#endif

