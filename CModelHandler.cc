/*
 * CModelHandler.cc
 *
 *  Created on: 13 sie 2018
 *      Author: pplucinski
 */

#include "CModelHandler.h"
#include "commonrozbojdefines.h"
#include <iostream>
CModelHandler::CModelHandler(CModel *aModel):
	mModel(aModel){
	mRefTreeModel = Gtk::ListStore::create(*mModel);
	mCS = mModel->mColumnStruct;
	Gtk::TreeModel::iterator iter1 = mRefTreeModel->append();
	Gtk::TreeModel::Row row1 = *iter1;
	row1[mCS->mOperators.second] = "MyName";

	Gtk::TreeModel::iterator iter = mRefTreeModel->append();
	Gtk::TreeModel::Row row = *iter;
//	row[mModel->m_col_name] = "12";
//	row[mModel->mColumnList->at(0).second] = 0.0;

	row[mCS->mOperators.second] = "TOTAL";
}
void CModelHandler::SetData(std::string data){
	std::cout << data << std::endl;
	Gtk::TreeModel::iterator iter = mRefTreeModel->append();
	Gtk::TreeModel::Row row = *iter;
	row[mCS->mOperators.second] = data;


}

Glib::RefPtr<Gtk::ListStore> CModelHandler::getRightModel(){
	return mRefTreeModel;
}
std::vector<Gtk::TreeModelColumn<Glib::ustring> >
	CModelHandler::getColumnList(){
	return mModel->getColumnList();
}
ColumnStruct* CModelHandler::getColumnListAsStruct(){
	return mModel->getColumnListAsStruct();
}
CModelHandler::~CModelHandler() {}

