/*
 * CController.h
 *
 *  Created on: 10 sie 2018
 *      Author: pplucinski
 */

#ifndef CCONTROLLER_H_
#define CCONTROLLER_H_

#include "CView.h"
#include "CModelHandler.h"
#include <gtkmm-2.4/gtkmm.h>
class CController {
public:
	CController();
	explicit CController(CModelHandler *, CView *);
	virtual ~CController();
	void SetModel(CModelHandler &model);
	void SetRightModel();
	void SetView(CView &view) ;

private:
	CModelHandler *mModel;
	CView *mView;
};

#endif /* CCONTROLLER_H_ */
