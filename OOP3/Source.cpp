#include"Library.h"

int main()
{
	int menu_option;
	CLibrary clLibrary;
	do
	{
		try
		{
			system("cls");
			cout << "========Chuong Trinh Quan Ly Thu Vien========" << endl;
			cout << endl;
			cout << "Moi Ban chon:" << endl;
			cout << endl;
			cout << "1-Nhap thong tin sach." << endl;
			cout << endl;
			cout << "2-Danh sach thong tin sach." << endl;
			cout << endl;
			cout << "3-Muon sach." << endl;
			cout << endl;
			cout << "4-Tra sach." << endl;
			cout << endl;
			cout << "5-Danh sach phieu muon sach." << endl;
			cout << endl;
			cout << "0-Thoat." << endl;
			cout << endl;
			cout << "============================================" << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "Lua chon cua ban la : ";
			cin >> menu_option;
			if ( cin.fail() || !(cin.peek() == EOF || cin.peek() == '\n') )
			{
				cin.clear();
				cin.ignore();
				throw 1;
			}
			cin.ignore();
			system("cls");
			switch (menu_option)
			{
			case 1:
				clLibrary.createbook();
				break;
			case 2:
				clLibrary.showallbook();
				break;
			case 3:
				clLibrary.createcard();
				break;
			case 4:
				clLibrary.updatecard();
				break;
			case 5:
				clLibrary.showcard();
				break;
			default:
				break;
			}
		}
		catch (...)
		{
			menu_option = 6;
		}
		

	} while ( menu_option != 0 );

	return 0;
}