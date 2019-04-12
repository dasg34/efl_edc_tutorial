#include <Elementary.h>
//test
static void
_win_cb_del(void *data EINA_UNUSED, Evas_Object *obj EINA_UNUSED, void *event_info EINA_UNUSED)
{
   elm_exit();
}

int
main(int argc, char **argv)
{
   elm_init(argc, argv);

   Evas_Object *win = elm_win_add(NULL, "sample", ELM_WIN_BASIC);
   evas_object_smart_callback_add(win, "delete,request", _win_cb_del, NULL);
   elm_win_autodel_set(win, EINA_TRUE);
   elm_win_title_set(win, "Sample");
   evas_object_resize(win, 500, 400);
   evas_object_move(win, 100, 100);
   evas_object_show(win);

   Evas_Object *layout = elm_layout_add(win);
   evas_object_size_hint_weight_set(layout, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   elm_layout_file_set(layout, argv[1], "main");
   elm_win_resize_object_add(win, layout);
   evas_object_show(layout);

   elm_run();
   elm_shutdown();

   return 0;
}
