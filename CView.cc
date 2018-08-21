/*
 * CView.cc
 *
 *  Created on: 10 sie 2018
 *      Author: pplucinski
 */

#include "CView.h"
#include "commonrozbojdefines.h"
#include <iostream>

#include <string>
CView::CView():
	mTreeView() {
	mButton.set_label("Click me..."),
	add(vbox);
	vbox.add(mTreeView);
	vbox.add(mButton);
	mButton.signal_clicked().connect(sigc::mem_fun(*this,
			&CView::ManageButtonClicked));
	show_all_children();
	mColumnList = new std::vector<Gtk::TreeViewColumn>;
}


void CView::setRightModel(Glib::RefPtr<Gtk::ListStore> treeModel) {

	 mTreeView.set_model(treeModel);
}

void CView::setColumnModel(
		std::vector<Gtk::TreeModelColumn<Glib::ustring> > aList) {
			mTreeView.append_column("Name", aList[0]);
}


void CView::setColumnModel(ColumnStruct *aColumnStruct){
	mTreeView.append_column(aColumnStruct->mOperators.first,
			aColumnStruct->mOperators.second);

	cell = manage(new Gtk::CellRendererSpin());
	std::vector<DoubleColumn> *vAsortItem = aColumnStruct->mAsortItem;
	for(std::vector<DoubleColumn>::iterator it = vAsortItem->begin();
			it != vAsortItem->end(); it++){

//		Gtk::TreeViewColumn *vNewColumn;
//
//		vNewColumn->pack_start(*cell, false);
//		vNewColumn->set_cell_data_func(*cell,
//				sigc::mem_fun(*this, &CView::on_cell_data_func));
//		vNewColumn->set_renderer(*cell, it->second);
//		mTreeView.append_column(it->first, *cell);

			Gtk::TreeViewColumn view_column = Gtk::manage(new Gtk::TreeViewColumn(_("Name")));
			Gtk::CellRendererText cell = Gtk::manage(new Gtk::CellRendererText());

			view_column->pack_start(*cell, false);
			view_column->set_cell_data_func(*cell, sigc::mem_fun(*this, &MyTreeView::on_cell_data_name));
			append_column(view_column);
		}
}

void CView::on_cell_data_func(Gtk::CellRenderer* renderer,
		const Gtk::TreeModel::iterator& iter) {
	std::cout << "tutaj" << std::endl;

//	Gtk::TreeModel::Row row = *iter;
//	int id = row[mColumnStruct->mOperators.second];
//	Glib::ustring name = row[m_columns.m_col_name];
//	if (id ==  "TOTAL"){
//
//	}
//	Gtk::CellRendererText* text_renderer =
//			dynamic_cast<Gtk::CellRendererText*>(renderer);
//	if (text_renderer)
//		text_renderer.property_markup() = name;

}

void CView::update(){}

void CView::ManageButtonClicked(){
	std::string a("kuuuurczak");
	m_signal_something.emit(a);

}
sigc::signal<void, std::string> CView::signal_something(){
	return m_signal_something;
}
CView::~CView() {}

