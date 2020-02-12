#include "CallCard.h"


string CCallCard::getSTcard()
{
	return cc_strSTcard;
}

string CCallCard::getDatestart()
{
	return cc_rgDatestart;
}

string CCallCard::getCodecard()
{
	return cc_rgCodecard;
}

string CCallCard::getCodebook()
{
	return cc_rgCodebook;
}

void CCallCard::setCodecard(string t_rgValue)
{
	try
	{
		if (!checkValue6Number(t_rgValue))
			throw 1;
		cc_rgCodecard = t_rgValue;
	}
	catch (int exception)
	{
		throw exception;
	}
}

void CCallCard::setCodehuman(string t_rgValue)
{
	try
	{
		if (!checkValue6Number(t_rgValue))
			throw 2;
		cc_rgCodehuman = t_rgValue;
	}
	catch (int exception)
	{
		throw exception;
	}
}

void CCallCard::setCodebook(string t_rgValue)
{
	try
	{
		if (!checkValue6Number(t_rgValue))
			throw 3;
		cc_rgCodebook = t_rgValue;
	}
	catch (int exception)
	{
		throw exception;
	}
}

void CCallCard::setDatestart(string t_rgValue)
{
	try
	{
		if (!checkFormat(t_rgValue))
			throw 4;
		cc_rgDatestart = t_rgValue;
	}
	catch (int exception)
	{
		throw exception;
	}
}

void CCallCard::setDateend(string t_rgValue)
{
	try
	{
		if (!checkFormat(t_rgValue))
			throw 5;
		cc_rgDateend = t_rgValue;
	}
	catch (int exception)
	{
		throw exception;
	}
}

void CCallCard::importcard()
{
	do
	{
		try
		{
			string rgCodecard;
			cout << "Nhap ma phieu muon : ";
			getline(cin, rgCodecard);
			setCodecard(rgCodecard);
			string rgCodehuman;
			cout << "Nhap ma so nguoi muon : ";
			getline(cin, rgCodehuman);
			setCodehuman(rgCodehuman);
			cout << "Nhap ten nguoi muon : ";
			getline(cin, cc_strName);
			string rgCodebook;
			cout << "Nhap ma sach : ";
			getline(cin, rgCodebook);
			setCodebook(rgCodebook);
			string rgDatestart;
			cout << "Nhap ngay muon : ";
			getline(cin, rgDatestart);
			setDatestart(rgDatestart);
			cout << "Nhap trang thai sach khi muon : ";
			getline(cin, cc_strSTbookS);
			break;
		}
		catch (int exception)
		{
			switch (exception)
			{
				case 1:
					cout << "Ma phieu muon khong hop le xin nhap lai tu dau!!!" << endl;
					break;
				case 2:
					cout << "Ma so nguoi muon khong hop le xin nhap lai tu dau!!!" << endl;
					break;
				case 3:
					cout << "Ma sach khong hop le xin nhap lai tu dau!!!" << endl;
					break;
				case 4:
					cout << "Ngay muon khong dung dinh dang xin nhap lai tu dau!!!" << endl;
					break;
				default:
					break;
			}
		}

	}while(true);	
}

void CCallCard::exportcard()
{
	cout << "Ma phieu muon : " << cc_rgCodecard << endl;
	cout << "Ma so nguoi muon : " << cc_rgCodehuman << endl;
	cout << "Ten nguoi muon : " << cc_strName << endl;
	cout << "Ma sach : " << cc_rgCodebook << endl;
	cout << "Ngay muon : " << cc_rgDatestart << endl;
	cout << "Tinh trang sach khi muon : " << cc_strSTbookS << endl;
}

void CCallCard::updatecard()
{
	do
	{
		try
		{
			string rgDateend;
			cout << "Nhap ngay tra : ";
			getline(cin, rgDateend);
			setDateend(rgDateend);
			cout << "Nhap trang thai sach khi tra : ";
			getline(cin, cc_strSTbookS);
			this->cc_strSTcard = "Tra";
			break;
		}
		catch (int exception)
		{
			if (exception == 5)
				cout << "Ngay tra khong dung dinh dang xin nhap lai tu dau!!!" << endl;
		}
	} while (true);
	
}

CCallCard::CCallCard()
{
	this->cc_strSTcard = "Muon";
}

CCallCard::~CCallCard()
{

}
