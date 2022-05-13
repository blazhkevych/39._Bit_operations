/*
	�������� ���������, ������� ������� � ������� ������
���������� ������, ������� �������� � ������ ������.
	��� ���������� ��������� ���������� ���������������
�������� API:
	DWORD WINAPI GetLogicalDrives();
	������� GetLogicalDrives ���������� ������� �����
���������� ������, ������� �������� � ������ ������. ���
���� ������ ��� ����� ������������ ����� ���������� ����.
���� ��� ����������, �� ���������� ���� ��������, � ���������
������ ��� ����� �������. ��� 0 ������������� ����� A, ��� 1 �
����� B, ��� 2 � ����� � � �.�.
*/

#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	int n, d;
	char dd[4];
	DWORD dr = GetLogicalDrives();

	cout << "Available disk drives : \n";
	for (int i = 0; i < 26; i++)
	{
		n = ((dr >> i) & 0x00000001);
		if (n == 1)
		{
			dd[0] = char(65 + i);
			dd[1] = ':';
			dd[2] = '\\';
			dd[3] = '\0';
			d = GetDriveTypeA(dd);
			if (d == DRIVE_UNKNOWN) cout << dd << " UNKNOWN" << endl;
			if (d == DRIVE_NO_ROOT_DIR) cout << dd << " DRIVE NO ROOT DIR" << endl;
			if (d == DRIVE_REMOVABLE) cout << dd << " REMOVABLE" << endl;
			if (d == DRIVE_FIXED) cout << dd << " FIXED" << endl;
			if (d == DRIVE_REMOTE) cout << dd << " REMOTE" << endl;
			if (d == DRIVE_CDROM) cout << dd << " CDROM" << endl;
			if (d == DRIVE_RAMDISK) cout << dd << " RAMDISK" << endl;
		}
	}

	cout << endl;
	system("pause");
	return 0;
}