/*
 * CModel.h
 *
 *  Created on: 10 sie 2018
 *      Author: pplucinski
 */

#ifndef CMODEL_H_
#define CMODEL_H_
#include <gtkmm-2.4/gtkmm.h>
#include "commonrozbojdefines.h"

#include <string>
#include <vector>
using namespace std;
class CModel : public Gtk::TreeModel::ColumnRecord {
    public:
		CModel();
//		CModel(string &data1);
		~CModel();
		string Data();
		void SetData(const string &data1);
        string data;
        std::vector<Gtk::TreeModelColumn<Glib::ustring> > getColumnList();
    	sigc::signal<void> signal_update();
    	sigc::signal<void> m_signal_update;
//        Gtk::TreeModelColumn<Glib::ustring> m_col_name;

        ColumnStruct *mColumnStruct;
        std::vector<StringColumn> *mStringList;
        std::vector<DoubleColumn> *mColumnList;
        ColumnStruct *getColumnListAsStruct();
};

#endif /* CMODEL_H_ */
