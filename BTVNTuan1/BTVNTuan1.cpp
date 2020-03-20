//Bài tập về nhà - LTM - 13 / 03 / 2020
//bài tập
//Due today at 11:59 PM
//Instructions
//Yêu cầu :
//
//Dựa theo ví dụ phân giải tên miền, lập trình ứng dụng như sau :
//
//+Nhập chuỗi ký tự từ bàn phím
//
//+ Kiểm tra chuỗi ký tự có phải là 1 tên miền hay không(điều kiện kiểm tra : chỉ chứa các ký tự chữ cái, chữ số, dấu gạch ngang và dấu chấm)
//
//+ Thực hiện phân giải tên miền với chuỗi ký tự đã kiểm tra
//
//+ In ra các địa chỉ IP đã phân giải được(số lượng có thể lớn hơn 1)
//
//+ Nếu không phân giải được thì đưa ra thông báo
//
//+ Mã nguồn cần có comment đầy đủ
//
//
//
//Chú ý :
//
//Sinh viên cần tạo tài khoản github và upload code sử dụng gist.Xem hướng dẫn tại đây https ://help.github.com/en/github/writing-on-github/creating-gists
//
//Lưu lại link đến gist tạo ở trên để nộp bài.
//
//
//
//Hướng dẫn nộp bài :
//
//Sinh viên mở form và điền thông tin cần thiết.
//
//Nhấn submit để nộp bài.
//
//Nhấn close để hoàn thành.



//Chú ý : Form này chỉ được nhập 1 lần, sinh viên cần kiểm tra kỹ các thông tin trước khi submit form.
//
//My work

#include<stdio.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<winsock2.h>
#include<WS2tcpip.h>


boolean checkDomain(char* string) {
	int len = strlen(string);
	for (int i = 0; i < len; i++) {
		if ('a' <= string[i] < 'z' || 'A' <= string[i] < 'Z' || 0 <= string[i] <= 9 || string[i] == '.' || string[i] == '-') {
			return true;
		}
	}
	return false;
}

int main() {
	char string[256];
	gets_s(string);

	if (!checkDomain(string)) {
		printf("Không đúng định dạng tên miền");
		return -1;
	}

	// khai báo thư viện
	WSADATA wsa;
	WORD version = MAKEWORD(2, 2);
	WSAStartup(version, &wsa);

	addrinfo* info;
	addrinfo* head;
	int result = getaddrinfo(string, "https", NULL, &info);
	if (result == 0) {
		head = info;
		while (head != NULL) {
			SOCKADDR_IN addr;
			memcpy(&addr, info->ai_addr, info->ai_addrlen);
			printf("ip: %s\n", inet_ntoa(addr.sin_addr));
			head = head->ai_next;
		}

	}
	else {
		printf("khong co dia chi ip phu hop");
	}


	return 0;
}

