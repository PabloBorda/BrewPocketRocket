#pragma once

#include <string>
#include <iostream>
#include <list>
#include "AEEQoSList.h"
#include "XOsPage.h"
#include "XOsException.h"


using namespace std;


class XOsApplication
{
private:	
	string applicationName;
	list<XOsPage> pages;
	XOsPage *currentPage;
//	IQoSList *list;
	

public:
	void run();
	XOsApplication(string applicationName);
	void addPage(XOsPage *page);
	string GetApplicationName();
	void setApplicationName(string applicationName); 
	XOsPage pageAt(int pageIndex);
public:
	~XOsApplication(void);
};
