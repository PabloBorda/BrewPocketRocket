#include "XOsApplication.h"

/**
@author: Pablo Tomas Borda Di Berardino
@date: 200804231417

*/



XOsApplication::XOsApplication(string applicationName){
  setApplicationName(applicationName);
  
}

XOsApplication::~XOsApplication(void)
{
}

string XOsApplication::GetApplicationName(){
  return this->applicationName;
}

void XOsApplication::setApplicationName(string applicationName){
  this->applicationName = applicationName;
}

void XOsApplication::addPage(XOsPage *page){
	this->pages.push_back(*page);
}


void XOsApplication::run(){
  


}


XOsPage XOsApplication::pageAt(int pageIndex){
	list<XOsPage>::iterator i = this->pages.begin();
	XOsPage currentPage;
	int count = 0;
	if (pageIndex < this->pages.size()){
	  while ((count < (int)this->pages.size()) && (i != this->pages.end())){
	   currentPage = *i;
	   i++;
	   count++;
	  }
	  return *i;
	}
	else {
		throw XOsException();
	}
	
}
