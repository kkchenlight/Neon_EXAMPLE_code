/*
 * @Description:
 * @Author: kkchen
 * @Email: kkchen.lg@qq.com
 * @Date: 2023-02-08 18:35:13
 * @LastEditTime: 2023-02-09 20:57:17
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
  std::cout << "<<<<<<<<<<<<<<<< vst1q test >>>>>>>>>>>>>>>" << std::endl;
  int8_t* a_int8 = new int8_t[32];
  int16_t* a_int16 = new int16_t[32];
  int32_t* a_int32 = new int32_t[32];
  float* a_fp32 = new float[32];

  int8_t* a_int8_result = new int8_t[32];
  int16_t* a_int16_result = new int16_t[32];
  int32_t* a_int32_result = new int32_t[32];
  float* a_fp32_result = new float[32];

  initarray<int8_t>(a_int8, 32);
  initarray<int16_t>(a_int16, 32);
  initarray<int32_t>(a_int32, 32);
  initarray<float>(a_fp32, 32);

  int8x16_t a_neon_int8 = vld1q_s8(a_int8);
  int16x8_t a_neon_int16 = vld1q_s16(a_int16);
  int32x4_t a_neon_int32 = vld1q_s32(a_int32);
  float32x4_t a_neon_fp32 = vld1q_f32(a_fp32);

  vst1q_f32(a_fp32_result, a_neon_fp32);
  vst1q_s32(a_int32_result, a_neon_int32);
  vst1q_s16(a_int16_result, a_neon_int16);
  vst1q_s8(a_int8_result, a_neon_int8);
  cout << " <<<<<<<<<<<<<<<< fp32 neon: >>>>>>>>>>>>>>>>>>>>" << endl;
  printarray<float>(a_fp32_result, 4);
  cout << " <<<<<<<<<<<<<<<< int32 neon: >>>>>>>>>>>>>>>>>>>>" << endl;
  printarray<int32_t>(a_int32_result, 4);
  cout << " <<<<<<<<<<<<<<<< int16 neon: >>>>>>>>>>>>>>>>>>>>" << endl;
  printarray<int16_t>(a_int16_result, 8);
  cout << " <<<<<<<<<<<<<<<< int8 neon: >>>>>>>>>>>>>>>>>>>>" << endl;
  printarray<int8_t>(a_int8_result, 16);

  std::cout << "<<<<<<<<<<<<<<<< vst1q_lane test >>>>>>>>>>>>>>>" << std::endl;
  vst1q_lane_f32(a_fp32_result, a_neon_fp32, 3);
  printarray<float>(a_fp32_result, 4);

  std::cout << "<<<<<<<<<<<<<<<< vst2q_ test >>>>>>>>>>>>>>>" << std::endl;
  for (int i = 0; i < 32; i++) {
    if (i < 4) {
      a_fp32[i] = 0;
    } else {
      a_fp32[i] = 1;
    }
  }
  printarray<float>(a_fp32, 8);
  float32x4x2_t a_fp32x2_vec = vld1q_f32_x2(a_fp32);
  vst2q_f32(a_fp32_result, a_fp32x2_vec);
  printarray<float>(a_fp32_result, 8);

  std::cout << "<<<<<<<<<<<<<<<< vst2q_lane test >>>>>>>>>>>>>>>" << std::endl;

  delete[] a_int8;
  delete[] a_int16;
  delete[] a_int32;
  delete[] a_fp32;

  delete[] a_int8_result;
  delete[] a_int16_result;
  delete[] a_int32_result;
  delete[] a_fp32_result;
}