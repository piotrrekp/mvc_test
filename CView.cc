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
	cell = Gtk::manage(new Gtk::CellRendererSpin());
	mColumnStruct = new ColumnStruct();
}

void CView::setRightModel(Glib::RefPtr<Gtk::ListStore> treeModel) 	{
	 mTreeView.set_model(treeModel);
}

void CView::setColumnModel(
		std::vector<Gtk::TreeModelColumn<Glib::ustring> > aList) {
			mTreeView.append_column("Name", aList[0]);
}


void CView::setColumnModel(ColumnStruct *aColumnStruct){
	mColumnStruct = aColumnStruct;
	mTreeView.append_column(aColumnStruct->mOperators.first,
			aColumnStruct->mOperators.second);

	std::vector<DoubleColumn> *vAsortItem = aColumnStruct->mAsortItem;
Gtk::Adjustment vSpinAdjustment(1,0,100,1);
	for(std::vector<DoubleColumn>::iterator it = vAsortItem->begin();
			it != vAsortItem->end(); it++){

		int cols_count = mTreeView.append_column(it->first, *cell);
		Gtk::TreeViewColumn *pColumn = mTreeView.get_column(cols_count-1);
		cell = new Gtk::CellRendererSpin;
		cell->property_editable() = true;

		cell->property_adjustment() = &vSpinAdjustment;
		pColumn->pack_start(*cell, false);
		pColumn->add_attribute(cell->property_text(),it->second);
		pColumn->set_fixed_width(50);
		pColumn->set_cell_data_func(*cell,
				sigc::mem_fun(*this, &CView::on_cell_data_func));


	}
}

void CView::on_cell_data_func(Gtk::CellRenderer* renderer,
		const Gtk::TreeModel::iterator& iter) {
	Gtk::TreeModel::Row row = *iter;
	Glib::ustring name = row[mColumnStruct->mOperators.second];
	Gtk::CellRendererSpin* vSpinRenderer =
				dynamic_cast<Gtk::CellRendererSpin*>(renderer);
//tutaj załatwiamy blokowanie wiersza TOTAL !!
	if (name ==  "TOTAL") {
		vSpinRenderer->property_editable() = false;
	}
	else {
		vSpinRenderer->property_editable() = true;
	}

}

void CView::update(){

}

void CView::ManageButtonClicked(){
	std::string a("kuuuurczak");
	m_signal_something.emit(a);
}

sigc::signal<void, std::string> CView::signal_something(){
	return m_signal_something;
}

CView::~CView() {}

