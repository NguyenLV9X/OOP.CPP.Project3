#pragma once
#include<vector>
#include<map>
#include"CallCard.h"
#include"Book.h"

class CLibrary
{
private:
	map <string, CBook> cl_mBook;
	map <string, CCallCard> cl_mCard;
public:
	void createbook();
	void showallbook();
	void createcard();
	void updatecard();
	void showcard();
	bool operator ()(pair<string, CCallCard> & tP1, pair<string, CCallCard> & tP2);
	CLibrary();
	~CLibrary();
};





