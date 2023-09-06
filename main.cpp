#include"menu.h"
int main(){
	 remove_scrollbar();
	kekhung();
	initMH(MH);
	initLTC(DSLTC);
	initLop(DSL);
	DocFileDSLTC(DSLTC);
	DocFileMH(MH);
	DocFileLop(DSL);
	DocFileSV(DSL);
	DocFileDSDK(DSLTC);
 	chaymenu(mainMENU);
 	return 0;
}
