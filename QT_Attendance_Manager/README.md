# QT_Attendance_Manager

Qt Widgets 기반 출석 관리 프로그램입니다.

이 프로젝트는 교사 회원가입과 로그인, 학생 등록, 날짜별 출석 저장, 학생별 출석 조회 기능을 제공합니다. 데이터는 텍스트 파일로 저장되며, 로그인한 교사 ID를 기준으로 학생 목록과 출석 기록 파일이 분리됩니다.

## Features

- 교사 회원가입
- 교사 로그인
- 학생 등록
- 날짜별 출석 상태 저장
- 교사용 학생 출석 조회
- 학생용 출석 조회

## File Structure

- `main.cpp`: 프로그램 시작점
- `widget.cpp`, `widget.h`, `widget.ui`: 메인 화면과 출석 관리 기능
- `teachersignup.cpp`, `teachersignup.h`, `teachersignup.ui`: 교사 회원가입 화면
- `CMakeLists.txt`: CMake 빌드 설정

## Data Storage

프로그램 실행 중 아래 형식의 텍스트 파일이 생성되어 사용됩니다.

- `teachers.txt`: 교사 계정 정보 저장
- `studentslist_<teacherId>.txt`: 로그인한 교사별 학생 목록 저장
- `attendance_<teacherId>.txt`: 로그인한 교사별 출석 기록 저장

## Build

Qt Creator 또는 CMake로 빌드할 수 있습니다.

### Requirements

- Qt 5 또는 Qt 6
- CMake 3.16 이상
- C++17

### Example

```bash
cmake -S . -B build
cmake --build build
```
