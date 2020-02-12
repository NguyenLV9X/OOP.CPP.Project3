#include "Book.h"

int CBook::getAmount()
{
	return cb_iAmount;
}

string CBook::getCode()
{
	return cb_rgCode;
}

void CBook::setCode(string t_rgValue)
{
	try
	{
		if (!checkValue6Number(t_rgValue))
			throw 1;
		cb_rgCode = t_rgValue;
	}
	catch (int exception)
	{
		throw exception;
	}
}
void CBook::setYear(int t_nValue)
{
	try
	{
		if (!checkYearBook(t_nValue))
			throw 2;
		cb_nYear = t_nValue;
	}
	catch (int exception)
	{
		throw exception;
	}
}
void CBook::setAmount(int t_nValue)
{
	try
	{
		if (!checkNaturalNumber(t_nValue))
			throw 3;
		cb_iAmount = t_nValue;
	}
	catch (int exception)
	{
		throw exception;
	}
}
void CBook::importbook()
{
	do
	{
		try
		{
			string rgCode;
			cout << "Nhap ma sach : ";
			getline(cin, rgCode);
			setCode(rgCode);
			cout << "Nhap tieu de sach : ";
			getline(cin, cb_strTitle);
			int nYear;
			cout << "Nhap nam san xuat : ";
			cin >> nYear;
			cin.ignore();
			setYear(nYear);
			cout << "Nhap nha san xuat : ";
			getline(cin, cb_strPublisher);
			cout << "Nhap tac gia : ";
			getline(cin, cb_strAuthor);
			cout << "Nhap the loai : ";
			getline(cin, cb_strKind);
			int iAmount;
			cout << "Nhap so luong : ";
			cin >> iAmount;
			cin.ignore();
			setAmount(iAmount);
			break;
		}
		catch (int exception)
		{
			if (exception == 1)
			{
				cout << "Ma code khong hop le xin nhap lai tu dau!!!" << endl;
			}
			if (exception == 2)
			{
				cout << "Nam san xuat khong hop le xin nhap lai tu dau!!!" << endl;
			}
			if (exception == 3)
			{
				cout << "So luong khong hop le xin nhap lai tu dau!!!" << endl;
			}
		}
	} while (true);
	
}

void CBook::exportallbook()
{
	cout << "Ma sach : " << cb_rgCode << endl;
	cout << "Tieu de sach : " << cb_strTitle << endl;
	cout << "Nam san xuat : " << cb_nYear << endl;
	cout << "Nha xuat ban : " << cb_strPublisher << endl;
	cout << "Tac gia : " << cb_strAuthor << endl;
	cout << "The loai : " << cb_strKind << endl;
	cout << "So luong : " << cb_iAmount << endl;
}

CBook::CBook()
{
}

CBook::~CBook()
{
}
