/*
 * CController.cc
 *
 *  Created on: 10 sie 2018
 *      Author: pplucinski
 */

#include "CController.h"

CController::CController(CModelHandler *aModel, CView *aView):
mModel(aModel),
mView(aView) {
	mView->setRightModel(mModel->getRightModel());
//	mView->setColumnModel(mModel->getColumnList());
	mView->setColumnModel(mModel->getColumnListAsStruct());


	mView->signal_something().connect(
			sigc::mem_fun(mModel, &CModelHandler::SetData));
}

CController::~CController() {
}

