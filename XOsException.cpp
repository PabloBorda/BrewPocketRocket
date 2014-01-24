#include "XOsException.h"

XOsException::XOsException(void)
{
}

XOsException::~XOsException(void)
{
}

const char *XOsException::ShowReason(){
	return "XOsPhere Exception: \n  Reason:  ";
}