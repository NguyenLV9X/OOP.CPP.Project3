#include<algorithm>
#include"Library.h"


void CLibrary::createbook()
{
	CBook cbTemp;
	cout << "NHAP THONG TIN SACH" << endl;
	cbTemp.importbook();
	if ( cl_mBook.find( cbTemp.getCode() ) != cl_mBook.end())
	{
		cout << endl;
		cout << "Dau sach da ton tai!!!" << endl;
		cout << "============================================";
		cout << endl;
		cout << endl;
		cout << "Hay an phim enter de quay lai menu chinh" << endl;
		system("pause");
	}
	else
	{
		cl_mBook[cbTemp.getCode()] = cbTemp;
	}
}

void CLibrary::showallbook()
{
	if (cl_mBook.empty())
	{
		cout << "Hien tai chua co dau sach nao !" << endl;;
	}
	else
	{
		int iLenght = cl_mBook.size();
		cout << "Tong So Dau Sach: " << iLenght << endl;
		cout << endl;
		cout << endl;
		int iCount = 0;
		for (map<string, CBook>::iterator pTemp = cl_mBook.begin(); pTemp != cl_mBook.end(); ++pTemp)
		{
			cout << "============================================" << endl;
			cout << "THONG TIN DAU SACH " << iCount + 1 << endl;
			pTemp->second.exportallbook();
			++iCount;
		}
	}
	cout << "============================================";
	cout << endl;
	cout << endl;
	cout << "Hay an phim enter de quay lai menu chinh" << endl;
	system("pause");
}

void CLibrary::createcard()
{
	if (cl_mBook.empty())
	{
		cout << "Hien tai chua co dau sach nao !" << endl;
		cout << "============================================";
		cout << endl;
		cout << endl;
		cout << "Hay an phim enter de quay lai menu chinh" << endl;
		system("pause");
	}
	else
	{
		CCallCard ccTemp;
		cout << "NHAP THONG TIN PHIEU MUON" << endl;
		ccTemp.importcard();
		string tCodecard = ccTemp.getCodecard();
		string tCodebook = ccTemp.getCodebook();
		if (cl_mCard.find(tCodecard) != cl_mCard.end())
		{
			cout << endl;
			cout << "Ma phieu muon da ton tai!!!" << endl;
			cout << "============================================";
			cout << endl;
			cout << endl;
			cout << "Hay an phim enter de quay lai menu chinh" << endl;
			system("pause");
		}
		else
		{
			if (cl_mBook.find(tCodebook) == cl_mBook.end())
			{
				cout << endl;
				cout << "Dau sach khong ton tai!!!" << endl;
				cout << "============================================";
				cout << endl;
				cout << endl;
				cout << "Hay an phim enter de quay lai menu chinh" << endl;
				system("pause");
			}
			else
			{
				CBook cbTemp = cl_mBook[tCodebook];
				int tAmount = cbTemp.getAmount();
				if (tAmount == 0)
				{
					cout << endl;
					cout << "Dau sach khong du so luong!!!" << endl;
					cout << "============================================";
					cout << endl;
					cout << endl;
					cout << "Hay an phim enter de quay lai menu chinh" << endl;
					system("pause");
				}
				else
				{
					cl_mCard[tCodecard] = ccTemp;
					cl_mBook[tCodebook].setAmount(tAmount - 1);
				}
			}
		}
	}
}

void CLibrary::updatecard()
{
	if (cl_mCard.empty())
	{
		cout << "Hien tai chua co phieu muon nao !" << endl;
		cout << "============================================";
		cout << endl;
		cout << endl;
		cout << "Hay an phim enter de quay lai menu chinh" << endl;
		system("pause");
	}
	else
	{
		string tCodecard;
		cout << "Nhap ma so phieu muon : ";
		getline(cin, tCodecard);
		if (cl_mCard.find(tCodecard) == cl_mCard.end())
		{
			cout << endl;
			cout << "Phieu muon khong ton tai!!!" << endl;
			cout << "============================================";
			cout << endl;
			cout << endl;
			cout << "Hay an phim enter de quay lai menu chinh" << endl;
			system("pause");
		}
		else
		{
			cout << "CAP NHAP THONG TIN PHIEU MUON" << endl;
			cl_mCard[tCodecard].updatecard();
			string tCodebook = cl_mCard[tCodecard].getCodebook();
			int tAmount = cl_mBook[tCodebook].getAmount();
			cl_mBook[tCodebook].setAmount(tAmount + 1);
		}
	}
}

void CLibrary::showcard()
{
	if (cl_mCard.empty())
	{
		cout << "Hien tai chua co phieu muon nao !" << endl;
	}
	else
	{
		
		vector<pair<string, CCallCard> > tMapcopy(cl_mCard.begin(), cl_mCard.end());
		sort(tMapcopy.begin(), tMapcopy.end(), CLibrary());
		int iCount = 0;
		vector<pair<string, CCallCard> >::iterator pCallcard = tMapcopy.begin();
		while (pCallcard != tMapcopy.end())
		{
			if ( pCallcard->second.getSTcard() == "Muon" )
			{
				cout << "============================================" << endl;
				cout << "THONG TIN PHIEU MUON " << iCount + 1 << endl;
				(*pCallcard).second.exportcard();
				
				++iCount;
			}
			++pCallcard;
		}
		if (iCount == 0)
		{
			cout << "Khong co phieu muon o trang thai dang muon !" << endl;
		}
	}
	cout << "============================================";
	cout << endl;
	cout << endl;
	cout << "Hay an phim enter de quay lai menu chinh" << endl;
	system("pause");
}

bool CLibrary::operator()(pair<string, CCallCard>& tP1, pair<string, CCallCard>& tP2) 
{
	string tDatestart1 = tP1.second.getDatestart();
	string tDatestart2 = tP2.second.getDatestart();
	int tyear1 = tDatestart1[6] * 1000 + tDatestart1[7] * 100 + tDatestart1[8] * 10 + tDatestart1[9];
	int tyear2 = tDatestart2[6] * 1000 + tDatestart2[7] * 100 + tDatestart2[8] * 10 + tDatestart2[9];
	if (tyear1 > tyear2)
	{
		return 1;
	}
	else if (tyear1 == tyear2)
	{
		int tmonth1 = tDatestart1[3] * 10 + tDatestart1[4];
		int tmonth2 = tDatestart2[3] * 10 + tDatestart2[4];
		if (tmonth1 > tmonth2)
		{
			return 1;
		}
		else if (tmonth1 == tmonth2)
		{
			int tDate1 = tDatestart1[0] * 10 + tDatestart1[1];
			int tDate2 = tDatestart2[0] * 10 + tDatestart2[1];
			if (tDate1 >= tDate2)
			{
				return 1;
			}
		}
	}	
	return 0;
}

CLibrary::CLibrary()
{
}

CLibrary::~CLibrary()
{
}
