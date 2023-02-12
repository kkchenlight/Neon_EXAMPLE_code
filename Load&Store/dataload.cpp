/*
 * @Description:
 * @Author: kkchen
 * @Email: kkchen.lg@qq.com
 * @Date: 2023-02-08 09:10:09
 * @LastEditTime: 2023-02-08 18:34:58
 * @LastEditors: kkchen
 */
#include <iostream>

#include "arm_neon.h"

template <typename T>
void initarray(T* src, int data_len) {
  for (int i = 0; i < data_len; i++) {
    src[i] = (T)(i);
  }
}

int main(int argc, char** argv) {
  // 1. different data type
  std::cout << "<<<<<<<<<<<<<<<< vld1q test >>>>>>>>>>>>>>>" << std::endl;
  int8_t* a_int8 = new int8_t[32];
  int16_t* a_int16 = new int16_t[32];
  int32_t* a_int32 = new int32_t[32];
  float* a_fp32 = new float[32];

  initarray<int8_t>(a_int8, 32);
  initarray<int16_t>(a_int16, 32);
  initarray<int32_t>(a_int32, 32);
  initarray<float>(a_fp32, 32);

  int8x16_t a_neon_int8 = vld1q_s8(a_int8);
  int16x8_t a_neon_int16 = vld1q_s16(a_int16);
  int32x4_t a_neon_int32 = vld1q_s32(a_int32);
  float32x4_t a_neon_fp32 = vld1q_f32(a_fp32);

  std::cout << " int8 neon: ";
  std::cout << vgetq_lane_s8(a_neon_int8, 0) + 0 << " "
            << vgetq_lane_s8(a_neon_int8, 1) + 0 << " "
            << vgetq_lane_s8(a_neon_int8, 2) + 0 << " "
            << vgetq_lane_s8(a_neon_int8, 3) + 0 << " "
            << vgetq_lane_s8(a_neon_int8, 4) + 0 << " "
            << vgetq_lane_s8(a_neon_int8, 5) + 0 << " "
            << vgetq_lane_s8(a_neon_int8, 6) + 0 << " "
            << vgetq_lane_s8(a_neon_int8, 7) + 0 << " "
            << vgetq_lane_s8(a_neon_int8, 8) + 0 << " "
            << vgetq_lane_s8(a_neon_int8, 9) + 0 << " "
            << vgetq_lane_s8(a_neon_int8, 10) + 0 << " "
            << vgetq_lane_s8(a_neon_int8, 11) + 0 << " "
            << vgetq_lane_s8(a_neon_int8, 12) + 0 << " "
            << vgetq_lane_s8(a_neon_int8, 13) + 0 << " "
            << vgetq_lane_s8(a_neon_int8, 14) + 0 << " "
            << vgetq_lane_s8(a_neon_int8, 15) + 0 << " " << std::endl;

  std::cout << "int16 neon: ";
  std::cout << vgetq_lane_s16(a_neon_int16, 0) << " "
            << vgetq_lane_s16(a_neon_int16, 1) << " "
            << vgetq_lane_s16(a_neon_int16, 2) << " "
            << vgetq_lane_s16(a_neon_int16, 3) << " "
            << vgetq_lane_s16(a_neon_int16, 4) << " "
            << vgetq_lane_s16(a_neon_int16, 5) << " "
            << vgetq_lane_s16(a_neon_int16, 6) << " "
            << vgetq_lane_s16(a_neon_int16, 7) << " " << std::endl;

  std::cout << "int32 neon: ";
  std::cout << vgetq_lane_s32(a_neon_int32, 0) << " "
            << vgetq_lane_s32(a_neon_int32, 1) << " "
            << vgetq_lane_s32(a_neon_int32, 2) << " "
            << vgetq_lane_s32(a_neon_int32, 3) << " " << std::endl;

  std::cout << " fp32 neon: ";
  std::cout << vgetq_lane_f32(a_neon_fp32, 0) << " "
            << vgetq_lane_f32(a_neon_fp32, 1) << " "
            << vgetq_lane_f32(a_neon_fp32, 2) << " "
            << vgetq_lane_f32(a_neon_fp32, 3) << " " << std::endl;
  std::cout << "<<<<<<<<<<<<<<<< vldq_lane_ test >>>>>>>>>>>>>>>" << std::endl;

  float a = 120;
  a_neon_fp32 = vld1q_lane_f32(&a, a_neon_fp32, 2);

  std::cout << " fp32 neon: ";
  std::cout << vgetq_lane_f32(a_neon_fp32, 0) << " "
            << vgetq_lane_f32(a_neon_fp32, 1) << " "
            << vgetq_lane_f32(a_neon_fp32, 2) << " "
            << vgetq_lane_f32(a_neon_fp32, 3) << " " << std::endl;

  std::cout << "<<<<<<<<<<<<<<<< vldq_dup_ test >>>>>>>>>>>>>>>" << std::endl;

  float b = 20;
  float32x4_t dup_vec = vld1q_dup_s32(&b);
  std::cout << " fp32 neon: ";
  std::cout << vgetq_lane_f32(dup_vec, 0) << " " << vgetq_lane_f32(dup_vec, 1)
            << " " << vgetq_lane_f32(dup_vec, 2) << " "
            << vgetq_lane_f32(dup_vec, 3) << " " << std::endl;

  std::cout << "<<<<<<<<<<<<<<<< vldq_f32_x2 test >>>>>>>>>>>>>>>" << std::endl;
  float32x4x2_t f32x2_vec = vld1q_f32_x2(a_fp32);
  std::cout << " fp32 neon: ";
  std::cout << vgetq_lane_f32(f32x2_vec.val[0], 0) << " "
            << vgetq_lane_f32(f32x2_vec.val[0], 1) << " "
            << vgetq_lane_f32(f32x2_vec.val[0], 2) << " "
            << vgetq_lane_f32(f32x2_vec.val[0], 3) << " "
            << vgetq_lane_f32(f32x2_vec.val[1], 0) << " "
            << vgetq_lane_f32(f32x2_vec.val[1], 1) << " "
            << vgetq_lane_f32(f32x2_vec.val[1], 2) << " "
            << vgetq_lane_f32(f32x2_vec.val[1], 3) << " " << std::endl;

  std::cout << "<<<<<<<<<<<<<<<< vld2q_f32 test >>>>>>>>>>>>>>>" << std::endl;
  float* tmp1 = new float[32];
  for (int i = 0; i < 32; i++) {
    tmp1[i] = i % 2;
  }
  float32x4x2_t tmp1_vec = vld2q_f32(tmp1);
  std::cout << " fp32 neon: ";
  std::cout << vgetq_lane_f32(tmp1_vec.val[0], 0) << " "
            << vgetq_lane_f32(tmp1_vec.val[0], 1) << " "
            << vgetq_lane_f32(tmp1_vec.val[0], 2) << " "
            << vgetq_lane_f32(tmp1_vec.val[0], 3) << " "
            << vgetq_lane_f32(tmp1_vec.val[1], 0) << " "
            << vgetq_lane_f32(tmp1_vec.val[1], 1) << " "
            << vgetq_lane_f32(tmp1_vec.val[1], 2) << " "
            << vgetq_lane_f32(tmp1_vec.val[1], 3) << " " << std::endl;

  std::cout << "<<<<<<<<<<<<<<<< vld2q_lane_f32 test >>>>>>>>>>>>>>>"
            << std::endl;

  float32x4x2_t tmp2_vec = vld2q_lane_f32(a_fp32 + 8, tmp1_vec, 1);
  std::cout << " fp32 neon: ";
  std::cout << vgetq_lane_f32(tmp2_vec.val[0], 0) << " "
            << vgetq_lane_f32(tmp2_vec.val[0], 1) << " "
            << vgetq_lane_f32(tmp2_vec.val[0], 2) << " "
            << vgetq_lane_f32(tmp2_vec.val[0], 3) << " "
            << vgetq_lane_f32(tmp2_vec.val[1], 0) << " "
            << vgetq_lane_f32(tmp2_vec.val[1], 1) << " "
            << vgetq_lane_f32(tmp2_vec.val[1], 2) << " "
            << vgetq_lane_f32(tmp2_vec.val[1], 3) << " " << std::endl;

  std::cout << "<<<<<<<<<<<<<<<< vld2q_dup_f32 test >>>>>>>>>>>>>>>"
            << std::endl;
  float32x4x2_t tmp3_vec = vld2q_dup_f32(a_fp32 + 8);
  std::cout << " fp32 neon: ";
  std::cout << vgetq_lane_f32(tmp3_vec.val[0], 0) << " "
            << vgetq_lane_f32(tmp3_vec.val[0], 1) << " "
            << vgetq_lane_f32(tmp3_vec.val[0], 2) << " "
            << vgetq_lane_f32(tmp3_vec.val[0], 3) << " "
            << vgetq_lane_f32(tmp3_vec.val[1], 0) << " "
            << vgetq_lane_f32(tmp3_vec.val[1], 1) << " "
            << vgetq_lane_f32(tmp3_vec.val[1], 2) << " "
            << vgetq_lane_f32(tmp3_vec.val[1], 3) << " " << std::endl;

  delete[] tmp1;
  delete[] a_fp32;
  delete[] a_int16;
  delete[] a_int32;
  delete[] a_int8;
  return 0;
}
