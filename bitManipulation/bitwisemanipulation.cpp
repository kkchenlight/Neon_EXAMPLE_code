/*
 * @Description:
 * @Author: kkchen
 * @Email: kkchen.lg@qq.com
 * @Date: 2023-02-11 11:57:35
 * @LastEditTime: 2023-02-17 20:52:41
 * @LastEditors: kkchen
 */
#include <iostream>

#include "arm_neon.h"
using namespace std;
template <typename T>
void initarray(T* src, int data_len) {
  for (int i = 0; i < data_len; i++) {
    src[i] = (T)(i);
  }
}

template <typename T>
void printarray(T* src, int data_len) {
  for (int i = 0; i < data_len; i++) {
    cout << src[i] + 0 << " ";
  }
  cout << endl;
}
int main() {
  uint8_t* a_uint8 = new uint8_t[32];
  initarray<uint8_t>(a_uint8, 32);
  cout << "Vector A is: " << endl;
  printarray<uint8_t>(a_uint8, 4);
  cout << endl;
  uint8x16_t a_neon_u8 = vld1q_u8(a_uint8);
  cout << "Vector A, vclzq_u8 test Count leading zeros" << endl;

  uint8x16_t tmp = vclzq_u8(a_neon_u8);
  std::cout << vgetq_lane_u8(tmp, 0) + 0 << " " << vgetq_lane_u8(tmp, 1) + 0
            << " " << vgetq_lane_u8(tmp, 2) + 0 << " "
            << vgetq_lane_u8(tmp, 3) + 0 << " " << std::endl;
  cout << endl;
  cout << "Vector A, vcntq_u8 test Papulation Count " << std::endl;
  tmp = vcntq_u8(a_neon_u8);
  std::cout << vgetq_lane_u8(tmp, 0) + 0 << " " << vgetq_lane_u8(tmp, 1) + 0
            << " " << vgetq_lane_u8(tmp, 2) + 0 << " "
            << vgetq_lane_u8(tmp, 3) + 0 << " " << std::endl;
  cout << endl;

  cout << "Vector A and Vector B, vbicq_u8 test Bitwise Clear " << std::endl;
  uint8_t b = 2;
  uint8x16_t tmp2 = vld1q_dup_u8(&b);
  std::cout << vgetq_lane_u8(a_neon_u8, 0) + 0 << " "
            << vgetq_lane_u8(a_neon_u8, 1) + 0 << " "
            << vgetq_lane_u8(a_neon_u8, 2) + 0 << " "
            << vgetq_lane_u8(a_neon_u8, 3) + 0 << " " << std::endl;
  printarray<uint8_t>(a_uint8, 4);
  cout << "Vecotr B is: " << endl;
  std::cout << vgetq_lane_u8(tmp2, 0) + 0 << " " << vgetq_lane_u8(tmp2, 1) + 0
            << " " << vgetq_lane_u8(tmp2, 2) + 0 << " "
            << vgetq_lane_u8(tmp2, 3) + 0 << " " << std::endl;

  tmp = vbicq_u8(a_neon_u8, tmp2);
  std::cout << " A vbicq_u8 B is:" << std::endl;
  std::cout << vgetq_lane_u8(tmp, 0) + 0 << " " << vgetq_lane_u8(tmp, 1) + 0
            << " " << vgetq_lane_u8(tmp, 2) + 0 << " "
            << vgetq_lane_u8(tmp, 3) + 0 << " " << std::endl;
  cout << endl;

  cout << "Vector A Bitwiseselect Vector B by Vector C, vbslq_u8 test Bitwise "
          "select "
       << std::endl;
  uint8_t c = 0b00001111;
  uint8_t d = 0b01010101;
  uint8_t e = 0b10101010;

  uint8x16_t tmp3 = vld1q_dup_u8(&c);
  uint8x16_t tmp4 = vld1q_dup_u8(&d);
  uint8x16_t tmp5 = vld1q_dup_u8(&e);

  cout << "Vector A is: " << endl;
  std::cout << vgetq_lane_u8(tmp4, 0) + 0 << " " << vgetq_lane_u8(tmp4, 1) + 0
            << " " << vgetq_lane_u8(tmp4, 2) + 0 << " "
            << vgetq_lane_u8(tmp4, 3) + 0 << " " << std::endl;

  cout << "Vector B is: " << endl;
  std::cout << vgetq_lane_u8(tmp5, 0) + 0 << " " << vgetq_lane_u8(tmp5, 1) + 0
            << " " << vgetq_lane_u8(tmp5, 2) + 0 << " "
            << vgetq_lane_u8(tmp5, 3) + 0 << " " << std::endl;

  cout << "Vector C is: " << endl;
  std::cout << vgetq_lane_u8(tmp3, 0) + 0 << " " << vgetq_lane_u8(tmp3, 1) + 0
            << " " << vgetq_lane_u8(tmp3, 2) + 0 << " "
            << vgetq_lane_u8(tmp3, 3) + 0 << " " << std::endl;
  uint8x16_t tmp6 = vbslq_u8(tmp3, tmp4, tmp5);

  cout << " A bitwise B by C is: " << endl;
  std::cout << vgetq_lane_u8(tmp6, 0) + 0 << " " << vgetq_lane_u8(tmp6, 1) + 0
            << " " << vgetq_lane_u8(tmp6, 2) + 0 << " "
            << vgetq_lane_u8(tmp6, 3) + 0 << " " << std::endl;

  return 0;
}