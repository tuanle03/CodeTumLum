<?php
error_log(print_r($_SERVER, true));
error_log(print_r($_POST, true));
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Lấy dữ liệu từ biến POST
    $dataToSave = $_POST["data"];

    // Đường dẫn đến file lưu trữ
    $filePath = "data.txt";

    // Mở file để ghi
    $file = fopen($filePath, "a");

    // Kiểm tra xem file có mở thành công không
    if ($file) {
        // Ghi dữ liệu vào file
        fwrite($file, $dataToSave);

        // Đóng file
        fclose($file);

        // Trả về thông báo thành công
        echo "Dữ liệu đã được lưu trữ thành công!";
    } else {
        // Xử lý lỗi nếu không mở được file
        header("HTTP/1.1 500 Internal Server Error");
        echo "Không thể mở file để ghi!";
    }
} else {
    header("HTTP/1.1 405 Method Not Allowed");
    echo "Method Not Allowed";
}
?>
