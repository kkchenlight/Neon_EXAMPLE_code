/*
 * @Description:
 * @Author: kkchen
 * @Email: kkchen.lg@qq.com
 * @Date: 2023-02-11 11:31:50
 * @LastEditTime: 2023-02-17 21:06:56
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
  int8_t* a_int8 = new int8_t[32];
  uint8_t* a_uint8 = new uint8_t[32];

  initarray<int8_t>(a_int8, 32);
  initarray<uint8_t>(a_uint8, 32);

  int8x16_t a_neon_s8 = vld1q_s8(a_int8);
  uint8x16_t a_neon_u8 = vld1q_u8(a_uint8);

  std::cout << "vceq_u8 bitwise equal test" << std::endl;
  std::cout << "Vector A is: " << std::endl;
  printarray<uint8_t>(a_uint8, 4);
  a_uint8[0] = 1;
  std::cout << "Vector B is: " << std::endl;
  printarray<uint8_t>(a_uint8, 4);

  uint8x16_t a_neon_u8_1 = vld1q_u8(a_uint8);
  uint8x16_t tmp = vceqq_u8(a_neon_u8_1, a_neon_u8);
  std::cout << " A bitwise equal B is: " << std::endl;
  std::cout << vgetq_lane_u8(tmp, 0) + 0 << " " << vgetq_lane_u8(tmp, 1) + 0
            << " " << vgetq_lane_u8(tmp, 2) + 0 << " "
            << vgetq_lane_u8(tmp, 3) + 0 << " " << std::endl;

  std::cout << std::endl;

  std::cout << "vcgeq_u8 test Greater than or equal to" << std::endl;
  std::cout << "Vector A is: " << std::endl;
  printarray<uint8_t>(a_uint8, 4);
  std::cout << "Vector B is: " << std::endl;
  uint8_t b = 2;
  a_neon_u8_1 = vld1q_dup_u8(&b);
  std::cout << vgetq_lane_u8(a_neon_u8_1, 0) + 0 << " "
            << vgetq_lane_u8(a_neon_u8_1, 1) + 0 << " "
            << vgetq_lane_u8(a_neon_u8_1, 2) + 0 << " "
            << vgetq_lane_u8(a_neon_u8_1, 3) + 0 << " " << std::endl;
  tmp = vcgeq_u8(a_neon_u8, a_neon_u8_1);
  std::cout << " A  Greater than or equal B is: " << std::endl;
  std::cout << vgetq_lane_u8(tmp, 0) + 0 << " " << vgetq_lane_u8(tmp, 1) + 0
            << " " << vgetq_lane_u8(tmp, 2) + 0 << " "
            << vgetq_lane_u8(tmp, 3) + 0 << " " << std::endl;

  tmp = vcleq_u8(a_neon_u8, a_neon_u8_1);
  std::cout << " A  Less than or equal B is: " << std::endl;
  std::cout << vgetq_lane_u8(tmp, 0) + 0 << " " << vgetq_lane_u8(tmp, 1) + 0
            << " " << vgetq_lane_u8(tmp, 2) + 0 << " "
            << vgetq_lane_u8(tmp, 3) + 0 << " " << std::endl;

  tmp = vcgtq_u8(a_neon_u8, a_neon_u8_1);
  std::cout << " A  Great than B is: " << std::endl;
  std::cout << vgetq_lane_u8(tmp, 0) + 0 << " " << vgetq_lane_u8(tmp, 1) + 0
            << " " << vgetq_lane_u8(tmp, 2) + 0 << " "
            << vgetq_lane_u8(tmp, 3) + 0 << " " << std::endl;

  tmp = vcltq_u8(a_neon_u8, a_neon_u8_1);
  std::cout << " A  Less than B is: " << std::endl;
  std::cout << vgetq_lane_u8(tmp, 0) + 0 << " " << vgetq_lane_u8(tmp, 1) + 0
            << " " << vgetq_lane_u8(tmp, 2) + 0 << " "
            << vgetq_lane_u8(tmp, 3) + 0 << " " << std::endl;

  return 0;
}