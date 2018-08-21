/*
 * CModel.cc
 *
 *  Created on: 10 sie 2018
 *      Author: pplucinski
 */

#include "CModel.h"
#include "commonrozbojdefines.h"
#include <string>
#include <iostream>
using namespace std;
//
//CModel::CModel(string &data1):
//		data("xx") {
//	mColumnStruct = new ColumnStruct();
//	mColumnList = new std::vector<DoubleColumn>;
//	mStringList = new std::vector<StringList>;
//
//}

CModel::CModel(): data("") {
	mStringList = new std::vector<StringColumn>;
	Gtk::TreeModelColumn<Glib::ustring> m_col_name;

	add(m_col_name);
	mColumnStruct = new ColumnStruct;
	mColumnStruct->mOperators = make_pair("name", m_col_name);
	mColumnStruct->mAsortItem = new std::vector<DoubleColumn>;
	mColumnList = new std::vector<DoubleColumn>;

	Gtk::TreeModelColumn<double> vTreeModelColumn;
	Gtk::TreeModelColumn<double> vTreeModelColumn1;
	add(vTreeModelColumn);
	add(vTreeModelColumn1);
	mColumnList->push_back(make_pair("a", vTreeModelColumn));
	mColumnList->push_back( make_pair("b", vTreeModelColumn1));
	mColumnStruct->mAsortItem = mColumnList;


}

string CModel::Data(){
          return data;
      }
std::vector<Gtk::TreeModelColumn<Glib::ustring> > CModel::getColumnList(){
	std::vector<Gtk::TreeModelColumn<Glib::ustring> > m;
//	m.push_back(m_col_name);
	return m;
}
ColumnStruct* CModel::getColumnListAsStruct(){
	return mColumnStruct;
}
void CModel::SetData(const string &data1) {
	  data = data1;
	  cout<<data1<<endl;
	  signal_update();
}

sigc::signal<void> CModel::signal_update(){
	return m_signal_update;
}

CModel::~CModel() {}

