#include <gtkmm-2.4/gtkmm.h>
#include "CView.h"
#include "CModel.h"
#include "CModelHandler.h"
#include "CController.h"
int main(int argc, char *argv[])
{
  Gtk::Main main(argc, argv, "org.gtkmm.example");
  CModel *model = new CModel();
  CModelHandler *modelHandler = new CModelHandler(model);
  CView *window = new CView;

  CController controler(modelHandler, window);
  main.run(*window);
  return 0;
}
