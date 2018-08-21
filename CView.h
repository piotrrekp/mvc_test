/*
 * CView.h
 *
 *  Created on: 10 sie 2018
 *      Author: pplucinski
 */

#ifndef CVIEW_H_
#define CVIEW_H_
#include <gtkmm-2.4/gtkmm.h>
#include <string>
#include "commonrozbojdefines.h"
#include "CModelHandler.h"
#include "CModel.h"
class CView : public Gtk::Window {
public:
	CView();
	virtual ~CView();

	sigc::signal<void, std::string> signal_something();
	sigc::signal<void, std::string> m_signal_something;
	void ManageButtonClicked();
	void setColumnModel(std::vector<Gtk::TreeModelColumn<Glib::ustring> > aList);
	void setColumnModel(ColumnStruct *aColumnStruct);

	void setRightModel(Glib::RefPtr<Gtk::ListStore> treeModel);
	void update();
protected:
	void on_cell_data_func(Gtk::CellRenderer* renderer,
			const Gtk::TreeModel::iterator& iter);
	Gtk::VBox vbox;
	Gtk::TreeView mTreeView;
	Gtk::Button mButton;
	Glib::RefPtr<Gtk::ListStore> mTreeModel;
	std::vector<Gtk::TreeViewColumn> *mColumnList;
	Gtk::CellRendererText *cell;
};

#endif /* CVIEW_H_ */
