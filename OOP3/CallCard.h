#pragma once
#include"Check.h"
class CCallCard : private CCheck
{
private:
	string cc_rgCodecard;
	string cc_rgCodehuman;
	string cc_strName;
	string cc_rgCodebook;
	string cc_rgDatestart;
	string cc_rgDateend;
	string cc_strSTbookS;
	string cc_strSTbookE;
	string cc_strSTcard;
public:
	string getSTcard();
	string getDatestart();
	string getCodecard();
	string getCodebook();
	void setCodecard(string t_rgValue);
	void setCodehuman(string t_rgValue);
	void setCodebook(string t_rgValue);
	void setDatestart(string t_rgValue);
	void setDateend(string t_rgValue);
	void importcard();
	void exportcard();
	void updatecard();
	CCallCard();
	~CCallCard();
};