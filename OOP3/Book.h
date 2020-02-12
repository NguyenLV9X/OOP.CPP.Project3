#pragma once
#include"Check.h"
using namespace std;
class CBook : private CCheck
{
private:
	string cb_rgCode;
	string cb_strTitle;
	int cb_nYear;
	string cb_strPublisher;
	string cb_strAuthor;
	string cb_strKind;
	int cb_iAmount;
public:
	int getAmount();
	string getCode();
	void setCode(string t_rgValue);
	void setYear(int t_nValue);
	void setAmount(int t_nValue);
	void importbook();
	void exportallbook();
	CBook();
	~CBook();
};