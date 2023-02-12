/*
 * @Description:
 * @Author: kkchen
 * @Email: kkchen.lg@qq.com
 * @Date: 2023-02-10 21:01:21
 * @LastEditTime: 2023-02-11 11:27:31
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

  std::cout << " vnegq_s8 test" << std::endl;
  std::cout << "Vector A is: " << std::endl;
  printarray<int8_t>(a_int8, 4);
  int8x16_t tmp = vnegq_s8(a_neon_s8);
  std::cout << "negtive A is: " << std::endl;
  std::cout << vgetq_lane_s8(tmp, 0) + 0 << " " << vgetq_lane_s8(tmp, 1) + 0
            << " " << vgetq_lane_s8(tmp, 2) + 0 << " "
            << vgetq_lane_s8(tmp, 3) + 0 << " " << std::endl;

  std::cout << std::endl;
  std::cout << "vmvn_u8 test >>>>>>>> bitwise not" << std::endl;
  uint8x16_t tmp1 = vmvnq_u8(a_neon_u8);
  std::cout << "Vector A is: " << std::endl;
  printarray<uint8_t>(a_uint8, 4);
  std::cout << "negtive A is: " << std::endl;
  std::cout << vgetq_lane_u8(tmp1, 0) + 0 << " " << vgetq_lane_u8(tmp1, 1) + 0
            << " " << vgetq_lane_u8(tmp1, 2) + 0 << " "
            << vgetq_lane_u8(tmp1, 3) + 0 << " " << std::endl;

  std::cout << "vandq_u8 test >>>>>>>> bitand" << std::endl;

  std::cout << " Vector A is: " << std::endl;
  printarray<uint8_t>(a_uint8, 4);
  std::cout << " Vector B is: " << std::endl;
  std::cout << vgetq_lane_u8(tmp1, 0) + 0 << " " << vgetq_lane_u8(tmp1, 1) + 0
            << " " << vgetq_lane_u8(tmp1, 2) + 0 << " "
            << vgetq_lane_u8(tmp1, 3) + 0 << " " << std::endl;
  std::cout << " A bitwise and B is: " << std::endl;
  uint8x16_t tmp2 = vandq_u8(tmp1, a_neon_u8);
  std::cout << vgetq_lane_u8(tmp2, 0) + 0 << " " << vgetq_lane_u8(tmp2, 1) + 0
            << " " << vgetq_lane_u8(tmp2, 2) + 0 << " "
            << vgetq_lane_u8(tmp2, 3) + 0 << " " << std::endl;
  std::cout << std::endl;

  std::cout << "vandq_u8 test >>>>>>>> bitor" << std::endl;
  std::cout << " Vector A is: " << std::endl;
  printarray<uint8_t>(a_uint8, 4);
  std::cout << " Vector B is: " << std::endl;
  std::cout << vgetq_lane_u8(tmp1, 0) + 0 << " " << vgetq_lane_u8(tmp1, 1) + 0
            << " " << vgetq_lane_u8(tmp1, 2) + 0 << " "
            << vgetq_lane_u8(tmp1, 3) + 0 << " " << std::endl;
  std::cout << " A bitwise and B is: " << std::endl;
  tmp2 = vorrq_u8(tmp1, a_neon_u8);
  std::cout << vgetq_lane_u8(tmp2, 0) + 0 << " " << vgetq_lane_u8(tmp2, 1) + 0
            << " " << vgetq_lane_u8(tmp2, 2) + 0 << " "
            << vgetq_lane_u8(tmp2, 3) + 0 << " " << std::endl;

  std::cout << std::endl;

    return 0;
}