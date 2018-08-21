/*
 *  commonrobojdefines.h
 *
 *  Created on: 31 lip 2018
 *      Author: pplucinski
 */

#ifndef ROZBOJ_NEXT_SRC_RANK_H_
#define ROZBOJ_NEXT_SRC_RANK_H_

#include <gtkmm.h>
#include <vector>

typedef std::vector<Glib::ustring> StringList;

typedef std::pair<Glib::ustring, Gtk::TreeModelColumn<Glib::ustring> > StringColumn;
typedef std::pair<Glib::ustring, Gtk::TreeModelColumn<double> > DoubleColumn;

typedef struct{
	StringColumn mOperators;
	std::vector<DoubleColumn> *mAsortItem;
} ColumnStruct;


typedef enum {
	LOWER_RANK,
	MEDIUM_RANK,
	HIGH_RANK
} ERank;


#endif /* ROZBOJ_NEXT_SRC_RANK_H_ */
