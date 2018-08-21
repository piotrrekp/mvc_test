#!/bin/bash

g++  CModel.cc CModelHandler.cc CView.cc CController.cc mvc.cc  `pkg-config --libs --cflags gtkmm-2.4 ` -o mvc
