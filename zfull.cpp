#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hàm khai báo các chức năng
void quanLyDocGia();
void xemDanhSachDocGia();
void themDocGia();
void chinhSuaThongTinDocGia();
void xoaDocGia();
void timKiemDocGiaTheoCMND();
void timKiemDocGiaTheoTen();
void quanLySach();
void lapPhieuMuonSach();
void lapPhieuTraSach();
void thongKeCoBan();

int main() {
    int choice;

    do {
        printf("\n=========== MENU QUẢN LÝ THƯ VIỆN ===========\n");
        printf("1. Quản lý độc giả\n");
        printf("2. Quản lý sách\n");
        printf("3. Lập phiếu mượn sách\n");
        printf("4. Lập phiếu trả sách\n");
        printf("5. Thống kê cơ bản\n");
        printf("0. Thoát chương trình\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                quanLyDocGia();
                break;
            case 2:
                quanLySach();
                break;
            case 3:
                lapPhieuMuonSach();
                break;
            case 4:
                lapPhieuTraSach();
                break;
            case 5:
                thongKeCoBan();
                break;
            case 0:
                printf("Thoát chương trình.\n");
                exit(0);
            default:
                printf("Lựa chọn không hợp lệ, vui lòng thử lại!\n");
        }
    } while (choice != 0);

    return 0;
}

// Các hàm trống sẽ được triển khai sau
void quanLyDocGia() {
    int choice;

    do {
        printf("\n-- Quản lý độc giả --\n");
        printf("1. Xem danh sách độc giả\n");
        printf("2. Thêm độc giả\n");
        printf("3. Chỉnh sửa thông tin độc giả\n");
        printf("4. Xóa độc giả\n");
        printf("5. Tìm kiếm độc giả theo CMND\n");
        printf("6. Tìm kiếm độc giả theo tên\n");
        printf("0. Quay lại\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                xemDanhSachDocGia();
                break;
            case 2:
                themDocGia();
                break;
            case 3:
                chinhSuaThongTinDocGia();
                break;
            case 4:
                xoaDocGia();
                break;
            case 5:
                timKiemDocGiaTheoCMND();
                break;
            case 6:
                timKiemDocGiaTheoTen();
                break;
            case 0:
                return;
            default:
                printf("Lựa chọn không hợp lệ!\n");
        }
    } while (choice != 0);
}


#define MAX_DOC_GIA 100  // Giới hạn số lượng độc giả

    int maDocGia[MAX_DOC_GIA];
    char hoTen[MAX_DOC_GIA][50];
    char cmnd[MAX_DOC_GIA][15];
    char ngaySinh[MAX_DOC_GIA][11];
    char gioiTinh[MAX_DOC_GIA][10];
    char email[MAX_DOC_GIA][50];
    char diaChi[MAX_DOC_GIA][100];
    char ngayLapThe[MAX_DOC_GIA][11];
    char ngayHetHan[MAX_DOC_GIA][11];
    int soLuongDocGia = 0;  // Biến lưu số lượng độc giả hiện tại


void xemDanhSachDocGia() {
    if (soLuongDocGia == 0) {
        printf("Không có độc giả nào trong thư viện.\n");
        return;
    }

    printf("\n-- Danh sách độc giả --\n");
    for (int i = 0; i < soLuongDocGia; i++) {
        printf("Mã độc giả: %d\n", maDocGia[i]);
        printf("Họ tên: %s\n", hoTen[i]);
        printf("CMND: %s\n", cmnd[i]);
        printf("Ngày sinh: %s\n", ngaySinh[i]);
        printf("Giới tính: %s\n", gioiTinh[i]);
        printf("Email: %s\n", email[i]);
        printf("Địa chỉ: %s\n", diaChi[i]);
        printf("Ngày lập thẻ: %s\n", ngayLapThe[i]);
        printf("Ngày hết hạn: %s\n\n", ngayHetHan[i]);
    }
}



void themDocGia() 
{
    if (soLuongDocGia >= MAX_DOC_GIA) {
        printf("Không thể thêm độc giả mới, thư viện đã đầy.\n");
        return;
    }
    
    printf("\n-- Thêm độc giả mới --\n");
    printf("Nhập mã độc giả (MSSV): ");
    scanf("%d", &maDocGia[soLuongDocGia]);
    printf("Nhập họ tên: ");
    scanf(" %[^\n]%*c", hoTen[soLuongDocGia]);  // Nhập chuỗi có khoảng trắng
    printf("Nhập CMND: ");
    scanf("%s", cmnd[soLuongDocGia]);
    printf("Nhập ngày sinh (dd/mm/yyyy): ");
    scanf("%s", ngaySinh[soLuongDocGia]);
    printf("Nhập giới tính: ");
    scanf("%s", gioiTinh[soLuongDocGia]);
    printf("Nhập email: ");
    scanf("%s", email[soLuongDocGia]);
    printf("Nhập địa chỉ: ");
    scanf(" %[^\n]%*c", diaChi[soLuongDocGia]);
    printf("Nhập ngày lập thẻ (dd/mm/yyyy): ");
    scanf("%s", ngayLapThe[soLuongDocGia]);
    printf("Nhập ngày hết hạn (dd/mm/yyyy): ");
    scanf("%s", ngayHetHan[soLuongDocGia]);

    soLuongDocGia++;  // Tăng số lượng độc giả sau khi thêm thành công
    printf("Thêm độc giả thành công!\n");
}


void chinhSuaThongTinDocGia()
{
    int ma;
    printf("\n-- Chỉnh sửa thông tin độc giả --\n");
    printf("Nhập mã độc giả cần chỉnh sửa: ");
    scanf("%d", &ma);

    int found = 0;  // Biến để kiểm tra xem mã độc giả có tồn tại không
    for (int i = 0; i < soLuongDocGia; i++) 
    {
        if (maDocGia[i] == ma) 
        {
            found = 1;
            int choice;
            do
            {
                printf("\nThông tin cần chỉnh sửa: \n");
                printf("1. Mã độc giả: %d\n", maDocGia[i]);
                printf("2. Họ tên: %s\n", hoTen[i]);
                printf("3. CMND: %s\n", cmnd[i]);
                printf("4. Ngày sinh: %s\n", ngaySinh[i]);
                printf("5. Giới tính: %s\n", gioiTinh[i]);
                printf("6. Email: %s\n", email[i]);
                printf("7. Địa chỉ: %s\n", diaChi[i]);
                printf("8. Ngày lập thẻ: %s\n", ngayLapThe[i]);
                printf("9. Ngày hết hạn: %s\n", ngayHetHan[i]);
                printf("0. Quay lại\n");
                printf("Lựa chọn của bạn: ");
                scanf("%d", &choice);
                getchar();  // Bỏ qua ký tự xuống dòng

                switch (choice)
                {
                case 1:
                    printf("Nhập mã độc giả mới: ");
                    scanf("%d", &maDocGia[i]);
                    break;
                case 2:
                    printf("Nhập họ và tên mới: ");
                    fgets(hoTen[i], sizeof(hoTen[i]), stdin);
                    hoTen[i][strcspn(hoTen[i], "\n")] = '\0'; // Loại bỏ ký tự xuống dòng
                    break;
                case 3:
                    printf("Nhập CMND mới: ");
                    fgets(cmnd[i], sizeof(cmnd[i]), stdin);
                    cmnd[i][strcspn(cmnd[i], "\n")] = '\0';
                    break;
                case 4:
                    printf("Nhập ngày sinh mới: ");
                    fgets(ngaySinh[i], sizeof(ngaySinh[i]), stdin);
                    ngaySinh[i][strcspn(ngaySinh[i], "\n")] = '\0';
                    break;
                case 5:
                    printf("Nhập giới tính mới: ");
                    fgets(gioiTinh[i], sizeof(gioiTinh[i]), stdin);
                    gioiTinh[i][strcspn(gioiTinh[i], "\n")] = '\0';
                    break;
                case 6:
                    printf("Nhập email mới: ");
                    fgets(email[i], sizeof(email[i]), stdin);
                    email[i][strcspn(email[i], "\n")] = '\0';
                    break;
                case 7:
                    printf("Nhập địa chỉ mới: ");
                    fgets(diaChi[i], sizeof(diaChi[i]), stdin);
                    diaChi[i][strcspn(diaChi[i], "\n")] = '\0';
                    break;
                case 8:
                    printf("Nhập ngày lập thẻ mới (dd/mm/yyyy): ");
                    fgets(ngayLapThe[i], sizeof(ngayLapThe[i]), stdin);
                    ngayLapThe[i][strcspn(ngayLapThe[i], "\n")] = '\0';
                    break;
                case 9:
                    printf("Nhập ngày hết hạn mới (dd/mm/yyyy): ");
                    fgets(ngayHetHan[i], sizeof(ngayHetHan[i]), stdin);
                    ngayHetHan[i][strcspn(ngayHetHan[i], "\n")] = '\0';
                    break;
                case 0:
                    printf("Quay lại.\n");
                    break;

                default:
                    printf("Lựa chọn không hợp lệ, hãy chọn lại.\n");
                    break;
                }

            } while (choice != 0);
            return;  // Thoát khỏi hàm sau khi chỉnh sửa
        }
    }

    if (!found)
    {
        printf("Không tìm thấy mã độc giả.\n");
    }
}




void xoaDocGia() {
    int ma;
    printf("\n-- Xóa độc giả --\n");
    printf("Nhập mã độc giả cần xóa: ");
    scanf("%d", &ma);

    int found = 0;  // Biến để kiểm tra xem mã độc giả có tồn tại không
    for (int i = 0; i < soLuongDocGia; i++) 
    {
        if (maDocGia[i] == ma) 
        {
            found = 1;
            // Xóa độc giả bằng cách dịch chuyển các phần tử phía sau lên trước
            for (int j = i; j < soLuongDocGia - 1; j++) 
            {
                maDocGia[j] = maDocGia[j + 1];
                strcpy(hoTen[j], hoTen[j + 1]);
                strcpy(cmnd[j], cmnd[j + 1]);
                strcpy(ngaySinh[j], ngaySinh[j + 1]);
                strcpy(gioiTinh[j], gioiTinh[j + 1]);
                strcpy(email[j], email[j + 1]);
                strcpy(diaChi[j], diaChi[j + 1]);
                strcpy(ngayLapThe[j], ngayLapThe[j + 1]);
                strcpy(ngayHetHan[j], ngayHetHan[j + 1]);
            }
            soLuongDocGia--;  // Giảm số lượng độc giả sau khi xóa
            printf("Xóa độc giả thành công!\n");
            break;
        }
    }
    if (!found) 
    {
        printf("Không tìm thấy độc giả có mã %d.\n", ma);
    }
}





void timKiemDocGiaTheoCMND()
{
    char so[15];
    printf("\n-- Tìm kiếm độc giả theo CMND --\n");
    printf("Nhập số CMND cần tìm kiếm: ");
    scanf("%s", so);

    int found = 0;
    for (int i = 0; i < soLuongDocGia; i++) 
    {
        if (strcmp(cmnd[i], so) == 0) 
        {
            found = 1;
            printf("Mã độc giả: %d\n", maDocGia[i]);
            printf("Họ tên: %s\n", hoTen[i]);
            printf("CMND: %s\n", cmnd[i]);
            printf("Ngày sinh: %s\n", ngaySinh[i]);
            printf("Giới tính: %s\n", gioiTinh[i]);
            printf("Email: %s\n", email[i]);
            printf("Địa chỉ: %s\n", diaChi[i]);
            printf("Ngày lập thẻ: %s\n", ngayLapThe[i]);
            printf("Ngày hết hạn: %s\n\n", ngayHetHan[i]);
        }

    }
    if (!found) 
    {
        printf("Không tìm thấy độc giả có cmnd là %s.\n", so);
    }

}


void timKiemDocGiaTheoTen()
{
    char ten[50];
    printf("\n-- Tìm kiếm độc giả theo tên --\n");
    printf("Nhập tên độc giả cần tìm kiếm: ");
    scanf("%s", ten);

    int found = 0;
    for (int i = 0; i < soLuongDocGia; i++) 
    {
        if (strcmp(hoTen[i], ten) == 0) 
        {
            found = 1;
            printf("Mã độc giả: %d\n", maDocGia[i]);
            printf("Họ tên: %s\n", hoTen[i]);
            printf("CMND: %s\n", cmnd[i]);
            printf("Ngày sinh: %s\n", ngaySinh[i]);
            printf("Giới tính: %s\n", gioiTinh[i]);
            printf("Email: %s\n", email[i]);
            printf("Địa chỉ: %s\n", diaChi[i]);
            printf("Ngày lập thẻ: %s\n", ngayLapThe[i]);
            printf("Ngày hết hạn: %s\n\n", ngayHetHan[i]);
        }

    }
    if (!found) 
    {
        printf("Không tìm thấy độc giả có tên là %s.\n", ten);
    }

}









void quanLySach() {
    printf("\n-- Quản lý sách --\n");
    // Triển khai chức năng sau
}

void lapPhieuMuonSach() {
    printf("\n-- Lập phiếu mượn sách --\n");
    // Triển khai chức năng sau
}

void lapPhieuTraSach() {
    printf("\n-- Lập phiếu trả sách --\n");
    // Triển khai chức năng sau
}

void thongKeCoBan() {
    printf("\n-- Thống kê cơ bản --\n");
    // Triển khai chức năng sau
}
