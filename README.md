Giới thiệu

Dự án Xe dò line là một robot tự hành sử dụng cảm biến hồng ngoại để nhận biết đường đi (line) và điều khiển động cơ di chuyển theo vạch kẻ đen/trắng trên nền.
Mục tiêu của dự án:

Hiểu cách hoạt động của cảm biến dò line.

Thực hành lập trình điều khiển động cơ DC/servo.

Ứng dụng thuật toán đơn giản (if-else, PID) để điều khiển hướng đi.

Phần cứng sử dụng

Arduino Uno R3 (hoặc ESP32 / STM32 tuỳ phiên bản)

Module cảm biến dò line (TCRTCX5000 sensor)

Driver motor (L298N / L293D)

2 động cơ DC + bánh xe

Pin Li-ion hoặc 18650 + mạch sạc bảo vệ

Khung xe robot

Phần mềm

Arduino IDE (C/C++)

Cách lắp ráp

Kết nối cảm biến dò line vào Arduino (chân digital).

Kết nối động cơ qua driver L298N.

Nguồn pin cấp cho cả mạch Arduino và động cơ.

Upload code từ Arduino IDE.
