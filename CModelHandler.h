/*
 * CModelHandler.h
 *
 *  Created on: 13 sie 2018
 *      Author: pplucinski
 */

#ifndef CMODELHANDLER_H_
#define CMODELHANDLER_H_

#include "CModel.h"
#include "commonrozbojdefines.h"
#include <string>

class CModelHandler {
public:
	CModelHandler(CModel *);
	virtual ~CModelHandler();
	void SetData(std::string);
	std::vector<Gtk::TreeModelColumn<Glib::ustring> > getColumnList();
	Glib::RefPtr<Gtk::ListStore> getRightModel();
	CModel *mModel;
    Glib::RefPtr<Gtk::ListStore> mRefTreeModel;
    ColumnStruct *mCS ;
	ColumnStruct *getColumnListAsStruct();
};

#endif /* CMODELHANDLER_H_ */
