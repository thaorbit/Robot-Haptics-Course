# HW1 - Phong Shading

Mô tả
------
Bài tập này là một chương trình C++ sử dụng OpenGL để minh họa Phong shading. Mục tiêu: build và chạy một executable hiển thị một vật thể (sphere) với ánh sáng Phong.

Yêu cầu (Prerequisites)
-----------------------
- CMake >= 3.16
- Trình biên dịch C++ hỗ trợ C++17 (MSVC / GCC / Clang)
- GPU và driver hỗ trợ OpenGL 3.3+
- Git (nếu muốn tải submodules hoặc cập nhật phụ thuộc)

Phụ thuộc (Dependencies)
-------------------------
- GLFW, GLM, glad
- Lưu ý: repo này đã bao gồm `glad.c` và thư mục include `glad/`. GLFW và GLM có thể được tải tự động qua CMake (`FetchContent`) hoặc có thể đã được cài sẵn trong thư mục `build/_deps/` khi bạn đã chạy CMake trước đó.


## Cách build & chạy

### 1. Cấu hình CMake (lần đầu sẽ tự tải GLFW & GLM, cần mạng)

```bash
cmake -S . -B build
```

Nếu dùng MSYS2 UCRT64 trên Windows, chỉ định rõ generator:

```bash
cmake -S . -B build -G "MinGW Makefiles"
```

### 2. Build

```bash
cmake --build build
```

### 3. Chạy chương trình

```bash
# Windows
.\build\HW1_PhongShader.exe

# Linux / macOS
./build/HW1_PhongShader
```

### Hướng dẫn sử dụng

- Mở chương trình sẽ hiển thị một cửa sổ OpenGL tiêu đề "Homework1 - Phong Shading" với một hình cầu (sphere) ở tâm cảnh.
- Ánh sáng mặc định được đặt tại vị trí `(5, 5, 5)` và vật liệu mặc định có thông số shininess = 32 (có thể chỉnh trong source `src/Material.cpp` hoặc `src/Light.cpp`).
- Hiện tại chương trình không có điều khiển tương tác (không có input để xoay/zooms). Đóng cửa sổ để thoát chương trình.
- Nếu muốn thay đổi màu vật liệu/ánh sáng, sửa mã trong `src/Light.cpp` và `src/Material.cpp`, rồi rebuild.
- Shader được khai báo trực tiếp trong `src/main.cpp` (không có file shader riêng).


Cấu trúc dự án (những file quan trọng)
-----------------------------------
- `CMakeLists.txt` — cấu hình build CMake
- `src/` — mã nguồn (ví dụ `main.cpp`, `Light.cpp`, `Shader.cpp`, `Sphere.cpp`, ...)
- `include/` — header (ví dụ `Light.h`, `Material.h`, `Shader.h`, ...)
- `glad.c` và `include/glad/` — loader OpenGL (đã có trong repo)
- `build/` — thư mục build (thư mục này thường được tạo bởi CMake)

Vấn đề thường gặp và cách khắc phục
----------------------------------
- Lỗi không tìm thấy GLFW/GLM: đảm bảo bạn có kết nối internet khi CMake dùng FetchContent, hoặc cài đặt GLFW/GLM trên hệ và trỏ CMake tới chúng.
- Lỗi liên quan OpenGL version: kiểm tra driver GPU và đảm bảo card hỗ trợ OpenGL 3.3+.
- Nếu executable chạy nhưng cửa sổ không hiện: kiểm tra log console để biết lỗi shader hoặc resource (file shader bị thiếu).

Ghi chú thêm
-----------
- Nếu bạn muốn thay đổi tham số build (Debug/Release), thêm `-DCMAKE_BUILD_TYPE=Release` cho generator Makefile hoặc chọn cấu hình trong Visual Studio.
- Có thể thêm file assets (textures, shaders) ở thư mục `assets/` nếu cần; nếu repo yêu cầu path cụ thể, đảm bảo copy đúng vị trí.

Tác giả
------
Tác giả: (điền tên bạn ở đây)

Nếu cần, tôi có thể giúp chỉnh README chi tiết hơn (ví dụ ghi rõ đường dẫn exe sau khi bạn cho biết generator bạn dùng). 
