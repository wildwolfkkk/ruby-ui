#include "widget.h"
#include "push_button.h"

static void
dealloc(YPushButton *btn)
{
  widget_object_map_remove(btn);
}

VALUE
ui_wrap_push_button(YPushButton *btn)
{
  return Data_Wrap_Struct(cUIPushButton, ui_widget_mark, dealloc, btn);
}

VALUE cUIPushButton;
void init_ui_push_button()
{
  VALUE ui = rb_define_module("UI");

  VALUE klass = rb_define_class_under(ui, "PushButton", cUIWidget);
  cUIPushButton = klass;

  //rb_define_singleton_method(klass, "new", new, 1);
}

