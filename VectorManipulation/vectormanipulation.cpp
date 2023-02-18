/*
 * @Description:
 * @Author: kkchen
 * @Email: kkchen.lg@qq.com
 * @Date: 2023-02-11 14:11:31
 * @LastEditTime: 2023-02-17 19:59:54
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
  uint32_t* a_uint32 = new uint32_t[32];
  initarray<uint32_t>(a_uint32, 32);
  cout << "Vector A is: " << endl;
  printarray<uint32_t>(a_uint32, 2);
  cout << "Vector B is: " << endl;
  printarray<uint32_t>(a_uint32 + 2, 2);
  cout << endl;
  uint32x2_t a_neon_u32_A = vld1_u32(a_uint32);
  uint32x2_t a_neon_u32_B = vld1_u32(a_uint32 + 2);

  cout << "vcombine_u32 test, Combine vectors" << endl;
  cout << " Vector A combine B is : " << endl;
  uint32x4_t tmp = vcombine_u32(a_neon_u32_A, a_neon_u32_B);
  std::cout << vgetq_lane_u32(tmp, 0) + 0 << " " << vgetq_lane_u32(tmp, 1) + 0
            << " " << vgetq_lane_u32(tmp, 2) + 0 << " "
            << vgetq_lane_u32(tmp, 3) + 0 << " " << std::endl;
  cout << endl;

  cout << "vget_high_u32 test, split vectors " << endl;
  tmp = vld1q_u32(a_uint32 + 4);
  cout << " Vector to be splited is : " << endl;
  std::cout << vgetq_lane_u32(tmp, 0) + 0 << " " << vgetq_lane_u32(tmp, 1) + 0
            << " " << vgetq_lane_u32(tmp, 2) + 0 << " "
            << vgetq_lane_u32(tmp, 3) + 0 << " " << std::endl;
  a_neon_u32_A = vget_low_u32(tmp);
  a_neon_u32_B = vget_high_u32(tmp);
  cout << "Vecotr A , low is :" << endl;
  std::cout << vget_lane_u32(a_neon_u32_A, 0) + 0 << " "
            << vget_lane_u32(a_neon_u32_A, 1) + 0 << " " << std::endl;
  cout << "Vecotr B , high is :" << endl;
  std::cout << vget_lane_u32(a_neon_u32_B, 0) + 0 << " "
            << vget_lane_u32(a_neon_u32_B, 1) + 0 << " " << std::endl;
  cout << endl;

  cout << "vextq_u32 test, extract vector from a pair of vectors" << endl;
  uint32x4_t a_neon_u32x4_A = vld1q_u32(a_uint32);
  uint32x4_t a_neon_u32x4_B = vld1q_u32(a_uint32 + 4);
  cout << "Vector A is :" << endl;
  printarray<uint32_t>(a_uint32, 4);
  cout << "Vector B is : " << endl;
  printarray<uint32_t>(a_uint32 + 4, 4);
  const int index = 1;
  cout << "index value is " << index << endl;
  cout << "extract from A, B by index " << index << " is : " << endl;
  tmp = vextq_u32(a_neon_u32x4_A, a_neon_u32x4_B, index);
  std::cout << vgetq_lane_u32(tmp, 0) + 0 << " " << vgetq_lane_u32(tmp, 1) + 0
            << " " << vgetq_lane_u32(tmp, 2) + 0 << " "
            << vgetq_lane_u32(tmp, 3) + 0 << " " << std::endl;
  const int index2 = 3;
  cout << "index value is " << index2 << endl;
  cout << "extract from A, B by index " << index2 << " is : " << endl;
  tmp = vextq_u32(a_neon_u32x4_A, a_neon_u32x4_B, index2);
  std::cout << vgetq_lane_u32(tmp, 0) + 0 << " " << vgetq_lane_u32(tmp, 1) + 0
            << " " << vgetq_lane_u32(tmp, 2) + 0 << " "
            << vgetq_lane_u32(tmp, 3) + 0 << " " << std::endl;
  const int index3 = 0;
  cout << "index value is " << index3 << endl;
  cout << "extract from A, B by index " << index3 << " is : " << endl;
  tmp = vextq_u32(a_neon_u32x4_A, a_neon_u32x4_B, index3);
  std::cout << vgetq_lane_u32(tmp, 0) + 0 << " " << vgetq_lane_u32(tmp, 1) + 0
            << " " << vgetq_lane_u32(tmp, 2) + 0 << " "
            << vgetq_lane_u32(tmp, 3) + 0 << " " << std::endl;
  cout << endl;

  cout << "vextq_u32 test, Reverse Element" << endl;
  cout << "Vector A is: " << endl;
  printarray<uint32_t>(a_uint32, 4);
  cout << "Reverse Vector A is: " << endl;
  tmp = vrev64q_u32(a_neon_u32x4_A);
  std::cout << vgetq_lane_u32(tmp, 0) + 0 << " " << vgetq_lane_u32(tmp, 1) + 0
            << " " << vgetq_lane_u32(tmp, 2) + 0 << " "
            << vgetq_lane_u32(tmp, 3) + 0 << " " << std::endl;
  cout << endl;

  cout << "vsetq_lane test, Set vector lane" << endl;
  cout << "Vector A is: " << endl;
  printarray<uint32_t>(a_uint32, 4);
  uint32_t a = 5;
  cout << "lane value to be set is: " << a << endl;
  const int index_value = 2;
  cout << "lane index to be set is: " << index_value << endl;
  tmp = vsetq_lane_u32(a, a_neon_u32x4_A, index_value);
  cout << "Vector lane " << index_value << " to be set: " << endl;
  std::cout << vgetq_lane_u32(tmp, 0) + 0 << " " << vgetq_lane_u32(tmp, 1) + 0
            << " " << vgetq_lane_u32(tmp, 2) + 0 << " "
            << vgetq_lane_u32(tmp, 3) + 0 << " " << std::endl;
  cout << endl;

  cout << "vtrnq_u32 test, Transpose Elements" << endl;
  a_neon_u32x4_A = vld1q_u32(a_uint32);
  a_neon_u32x4_B = vld1q_u32(a_uint32 + 4);
  cout << "Vector A is :" << endl;
  printarray<uint32_t>(a_uint32, 4);
  cout << "Vector B is : " << endl;
  printarray<uint32_t>(a_uint32 + 4, 4);
  uint32x4x2_t tmp1 = vtrnq_u32(a_neon_u32x4_A, a_neon_u32x4_B);
  cout << "Transpose A and B is: " << endl;

  std::cout << vgetq_lane_u32(tmp1.val[0], 0) + 0 << " "
            << vgetq_lane_u32(tmp1.val[0], 1) + 0 << " " << std::endl
            << vgetq_lane_u32(tmp1.val[1], 0) + 0 << " "
            << vgetq_lane_u32(tmp1.val[1], 1) + 0 << " " << std::endl
            << vgetq_lane_u32(tmp1.val[0], 2) + 0 << " "
            << vgetq_lane_u32(tmp1.val[0], 3) + 0 << " " << std::endl
            << vgetq_lane_u32(tmp1.val[1], 2) + 0 << " "
            << vgetq_lane_u32(tmp1.val[1], 3) + 0 << " " << std::endl;
  cout << endl;

  cout << "vzipq_u32 test, zip elements" << endl;

  a_neon_u32x4_A = vld1q_u32(a_uint32);
  a_neon_u32x4_B = vld1q_u32(a_uint32 + 4);
  cout << "Vector A is :" << endl;
  printarray<uint32_t>(a_uint32, 4);
  cout << "Vector B is : " << endl;
  printarray<uint32_t>(a_uint32 + 4, 4);
  tmp1 = vzipq_u32(a_neon_u32x4_A, a_neon_u32x4_B);
  cout << "zip A and B is: " << endl;
  std::cout << vgetq_lane_u32(tmp1.val[0], 0) + 0 << " "
            << vgetq_lane_u32(tmp1.val[0], 1) + 0 << " "
            << vgetq_lane_u32(tmp1.val[0], 2) + 0 << " "
            << vgetq_lane_u32(tmp1.val[0], 3) + 0 << " " << std::endl
            << vgetq_lane_u32(tmp1.val[1], 0) + 0 << " "
            << vgetq_lane_u32(tmp1.val[1], 1) + 0 << " "
            << vgetq_lane_u32(tmp1.val[1], 2) + 0 << " "
            << vgetq_lane_u32(tmp1.val[1], 3) + 0 << " " << std::endl;

  return 0;
}