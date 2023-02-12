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
  std::cout << "<<<<<<<<<<<<<<<< vaddq test >>>>>>>>>>>>>>>" << std::endl;
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

  int8x16_t a_neon_int8_tmp = vaddq_s8(a_neon_int8, a_neon_int8);
  int16x8_t a_neon_int16_tmp = vaddq_s16(a_neon_int16, a_neon_int16);
  int32x4_t a_neon_int32_tmp = vaddq_s32(a_neon_int32, a_neon_int32);
  float32x4_t a_neon_fp32_tmp = vaddq_f32(a_neon_fp32, a_neon_fp32);

  std::cout << " int8 neon: ";
  std::cout << vgetq_lane_s8(a_neon_int8_tmp, 0) + 0 << " "
            << vgetq_lane_s8(a_neon_int8_tmp, 1) + 0 << " "
            << vgetq_lane_s8(a_neon_int8_tmp, 2) + 0 << " "
            << vgetq_lane_s8(a_neon_int8_tmp, 3) + 0 << " "
            << vgetq_lane_s8(a_neon_int8_tmp, 4) + 0 << " "
            << vgetq_lane_s8(a_neon_int8_tmp, 5) + 0 << " "
            << vgetq_lane_s8(a_neon_int8_tmp, 6) + 0 << " "
            << vgetq_lane_s8(a_neon_int8_tmp, 7) + 0 << " "
            << vgetq_lane_s8(a_neon_int8_tmp, 8) + 0 << " "
            << vgetq_lane_s8(a_neon_int8_tmp, 9) + 0 << " "
            << vgetq_lane_s8(a_neon_int8_tmp, 10) + 0 << " "
            << vgetq_lane_s8(a_neon_int8_tmp, 11) + 0 << " "
            << vgetq_lane_s8(a_neon_int8_tmp, 12) + 0 << " "
            << vgetq_lane_s8(a_neon_int8_tmp, 13) + 0 << " "
            << vgetq_lane_s8(a_neon_int8_tmp, 14) + 0 << " "
            << vgetq_lane_s8(a_neon_int8_tmp, 15) + 0 << " " << std::endl;

  std::cout << "int16 neon: ";
  std::cout << vgetq_lane_s16(a_neon_int16_tmp, 0) << " "
            << vgetq_lane_s16(a_neon_int16_tmp, 1) << " "
            << vgetq_lane_s16(a_neon_int16_tmp, 2) << " "
            << vgetq_lane_s16(a_neon_int16_tmp, 3) << " "
            << vgetq_lane_s16(a_neon_int16_tmp, 4) << " "
            << vgetq_lane_s16(a_neon_int16_tmp, 5) << " "
            << vgetq_lane_s16(a_neon_int16_tmp, 6) << " "
            << vgetq_lane_s16(a_neon_int16_tmp, 7) << " " << std::endl;

  std::cout << "int32 neon: ";
  std::cout << vgetq_lane_s32(a_neon_int32_tmp, 0) << " "
            << vgetq_lane_s32(a_neon_int32_tmp, 1) << " "
            << vgetq_lane_s32(a_neon_int32_tmp, 2) << " "
            << vgetq_lane_s32(a_neon_int32_tmp, 3) << " " << std::endl;

  std::cout << " fp32 neon: ";
  std::cout << vgetq_lane_f32(a_neon_fp32, 0) << " "
            << vgetq_lane_f32(a_neon_fp32, 1) << " "
            << vgetq_lane_f32(a_neon_fp32, 2) << " "
            << vgetq_lane_f32(a_neon_fp32, 3) << " " << std::endl;

  std::cout << "<<<<<<<<<<<<<<<< vsub test >>>>>>>>>>>>>>>" << std::endl;

  a_neon_int8 = vsubq_s8(a_neon_int8_tmp, a_neon_int8);
  a_neon_int16 = vsubq_s16(a_neon_int16_tmp, a_neon_int16);
  a_neon_int32 = vsubq_s32(a_neon_int32_tmp, a_neon_int32);
  a_neon_fp32 = vsubq_f32(a_neon_fp32_tmp, a_neon_fp32);

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

  std::cout << "<<<<<<<<<<<<<<<< vmul test >>>>>>>>>>>>>>>" << std::endl;

  a_neon_int8 = vmulq_s8(a_neon_int8, a_neon_int8);
  a_neon_int16 = vmulq_s16(a_neon_int16, a_neon_int16);
  a_neon_int32 = vmulq_s32(a_neon_int32, a_neon_int32);
  a_neon_fp32 = vmulq_f32(a_neon_fp32, a_neon_fp32);

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

  std::cout << "<<<<<<<<<<<<<<<< vpadd test >>>>>>>>>>>>>>>" << std::endl;
  for (int i = 0; i < 32; i++) {
    if (i < 4) {
      a_fp32[i] = 1;
    } else {
      a_fp32[i] = 2;
    }
  }
  int32x4_t vec_1 = vld1q_f32(a_fp32);
  int32x4_t vec_2 = vld1q_f32(a_fp32 + 4);
  int32x4_t result_hadd = vpaddq_f32(vec_1, vec_2);
  std::cout << " fp32 neon: ";
  std::cout << vgetq_lane_f32(result_hadd, 0) << " "
            << vgetq_lane_f32(result_hadd, 1) << " "
            << vgetq_lane_f32(result_hadd, 2) << " "
            << vgetq_lane_f32(result_hadd, 3) << " " << std::endl;

  std::cout << "<<<<<<<<<<<<<<<<<< vector multply by scalar >>>>>>>>>>>>>>>>>> "
            << std::endl;
  std::cout << "vmulq_n_f32 : " << std::endl;
  std::cout << "vecotr A is: " << std::endl;
  printarray<float>(a_fp32, 4);
  float b = 2;
  std::cout << "Scalar b is " << b << std::endl;
  a_neon_fp32 = vld1q_f32(a_fp32);
  float32x4_t tmp = vmulq_n_f32(a_neon_fp32, b);

  std::cout << "A * b result is: ";
  std::cout << vgetq_lane_f32(tmp, 0) << " " << vgetq_lane_f32(tmp, 1) << " "
            << vgetq_lane_f32(tmp, 2) << " " << vgetq_lane_f32(tmp, 3) << " "
            << std::endl;

  std::cout << std::endl;
  std::cout << "vmulq_lane_f32 : " << std::endl;
  std::cout << "vecotr A is: " << std::endl;
  printarray<float>(a_fp32, 4);
  std::cout << "vector B is: " << std::endl;
  a_fp32[4] = 2;
  a_fp32[5] = 3;
  a_fp32[6] = 4;
  a_fp32[7] = 5;
  printarray<float>(a_fp32 + 4, 4);
  float32x4_t a_neon_fp32_2 = vld1q_f32(a_fp32 + 4);
  a_neon_fp32 = vld1q_f32(a_fp32);

  tmp = vmulq_laneq_f32(a_neon_fp32, a_neon_fp32_2, 2);
  std::cout << "A * B result is: ";
  std::cout << vgetq_lane_f32(tmp, 0) << " " << vgetq_lane_f32(tmp, 1) << " "
            << vgetq_lane_f32(tmp, 2) << " " << vgetq_lane_f32(tmp, 3) << " "
            << std::endl;
  std::cout << std::endl;
  std::cout << "vfmaq_n_f32 fused multiply accumulate" << std::endl;

  std::cout << "vector A is: " << std::endl;
  std::cout << vgetq_lane_f32(a_neon_fp32_2, 0) << " "
            << vgetq_lane_f32(a_neon_fp32_2, 1) << " "
            << vgetq_lane_f32(a_neon_fp32_2, 2) << " "
            << vgetq_lane_f32(a_neon_fp32_2, 3) << " " << std::endl;
  std::cout << "vector B is: " << std::endl;
  std::cout << vgetq_lane_f32(a_neon_fp32, 0) << " "
            << vgetq_lane_f32(a_neon_fp32, 1) << " "
            << vgetq_lane_f32(a_neon_fp32, 2) << " "
            << vgetq_lane_f32(a_neon_fp32, 3) << " " << std::endl;
  float bias = 5.0;
  std::cout << "bias is " << bias << std::endl;
  float32x4_t tmp1 = vfmaq_n_f32(a_neon_fp32_2, a_neon_fp32, bias);
  std::cout << "A mul B accumulate bias is: " << std::endl;
  std::cout << vgetq_lane_f32(tmp1, 0) << " " << vgetq_lane_f32(tmp1, 1) << " "
            << vgetq_lane_f32(tmp1, 2) << " " << vgetq_lane_f32(tmp1, 3) << " "
            << std::endl;
  std::cout << std::endl;
  std::cout << "vmla_n_f32 Vector multiply-accumulate by scalar" << std::endl;

  std::cout << "vector A is: " << std::endl;
  std::cout << vgetq_lane_f32(a_neon_fp32_2, 0) << " "
            << vgetq_lane_f32(a_neon_fp32_2, 1) << " "
            << vgetq_lane_f32(a_neon_fp32_2, 2) << " "
            << vgetq_lane_f32(a_neon_fp32_2, 3) << " " << std::endl;
  std::cout << "vector B is: " << std::endl;
  std::cout << vgetq_lane_f32(a_neon_fp32, 0) << " "
            << vgetq_lane_f32(a_neon_fp32, 1) << " "
            << vgetq_lane_f32(a_neon_fp32, 2) << " "
            << vgetq_lane_f32(a_neon_fp32, 3) << " " << std::endl;
  std::cout << "bias is " << bias << std::endl;
  tmp1 = vmlaq_n_f32(a_neon_fp32_2, a_neon_fp32, bias);
  std::cout << "A mul B accumulate bias is: " << std::endl;
  std::cout << vgetq_lane_f32(tmp1, 0) << " " << vgetq_lane_f32(tmp1, 1) << " "
            << vgetq_lane_f32(tmp1, 2) << " " << vgetq_lane_f32(tmp1, 3) << " "
            << std::endl;
  std::cout << std::endl;

  std::cout << " vabsq_f32 test " << std::endl;
  a_fp32[4] = -1;
  a_fp32[5] = -2;
  a_fp32[6] = -3;
  a_fp32[7] = -4;
  a_neon_fp32 = vld1q_f32(a_fp32 + 4);
  std::cout << "vector A is: " << std::endl;
  printarray<float>(a_fp32 + 4, 4);
  tmp = vabsq_f32(a_neon_fp32);
  std::cout << "abs(A) is: " << std::endl;
  std::cout << vgetq_lane_f32(tmp, 0) << " " << vgetq_lane_f32(tmp, 1) << " "
            << vgetq_lane_f32(tmp, 2) << " " << vgetq_lane_f32(tmp, 3) << " "
            << std::endl;
  std::cout << std::endl;

  std::cout << " vrecpe_f32 test " << std::endl;
  a_neon_fp32 = vld1q_f32(a_fp32 + 4);
  std::cout << "vector A is: " << std::endl;
  printarray<float>(a_fp32 + 4, 4);
  tmp = vrecpeq_f32(a_neon_fp32);
  std::cout << "reciprocal of A is: " << std::endl;
  std::cout << vgetq_lane_f32(tmp, 0) << " " << vgetq_lane_f32(tmp, 1) << " "
            << vgetq_lane_f32(tmp, 2) << " " << vgetq_lane_f32(tmp, 3) << " "
            << std::endl;

  std::cout << std::endl;
  std::cout << " vrecps_f32 test " << std::endl;
  a_neon_fp32_2 = vld1q_f32(a_fp32);
  a_neon_fp32 = vld1q_f32(a_fp32 + 4);
  std::cout << "vector A is: " << std::endl;
  printarray<float>(a_fp32, 4);
  std::cout << "vector B is: " << std::endl;
  printarray<float>(a_fp32 + 4, 4);
  tmp = vrecpsq_f32(a_neon_fp32, a_neon_fp32_2);
  std::cout << "Floating-point Reciprocal Step of A with B is: " << std::endl;
  std::cout << vgetq_lane_f32(tmp, 0) << " " << vgetq_lane_f32(tmp, 1) << " "
            << vgetq_lane_f32(tmp, 2) << " " << vgetq_lane_f32(tmp, 3) << " "
            << std::endl;

  std::cout << std::endl;
  std::cout << " vrsqrte_f32q test " << std::endl;

  a_fp32[4] = 1;
  a_fp32[5] = 4;
  a_fp32[6] = 9;
  a_fp32[7] = 16;
  a_neon_fp32 = vld1q_f32(a_fp32 + 4);
  std::cout << "vector A is: " << std::endl;
  printarray<float>(a_fp32 + 4, 4);
  tmp = vrsqrteq_f32(a_neon_fp32);
  std::cout << "Reciprocal Square Root Step of A is: " << std::endl;
  std::cout << vgetq_lane_f32(tmp, 0) << " " << vgetq_lane_f32(tmp, 1) << " "
            << vgetq_lane_f32(tmp, 2) << " " << vgetq_lane_f32(tmp, 3) << " "
            << std::endl;

  delete[] a_int8;
  delete[] a_int16;
  delete[] a_int32;
  delete[] a_fp32;
  return 0;
}