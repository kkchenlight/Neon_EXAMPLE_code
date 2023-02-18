# Neon_EXAMPLE_code
this is a Neon example code for rookie。

#### Load&Store(take FP32 for example)

| 函数           | 含义                                                         | 备注 |
| -------------- | ------------------------------------------------------------ | ---- |
| vld1q_f32      | 从内存加载float数据到128位的neon寄存器，一次加载4个float     |      |
| vld1q_lane_f32 | 从内存加载一个数据到neon寄存器中，根据index替换原来寄存器对应index的数据 |      |
| vld1q_dup_f32  | 从内存加载一个数据a到neon寄存器中 ， 将该neon寄存器中所有位置的值变为a |      |
| vld1q_f32_x2   | 从内存中加载8个数据，按照顺序依次填充到2个neon寄存器中       |      |
| vld2q_f32      | 从内存加载8个数据，按照顺序交叉存储到2个neon寄存器中         |      |
| vld2q_lane_f32 | 从内存中加载两个数据，根据index，分别存储到2个Neon寄存器中索引为index的位置 |      |
| vld2q_dup_f32  | 从内存中加载两个数据，分别填充满2个Neon寄存器                |      |
| vgetq_lane_f32 | 根据index从Neon寄存器中获取对应的值                          |      |

#### 算术计算(take s8 and f32 for example)

* **vaddq_s8**
* **vmulq_s8**
* **vsubq_s8**
* **vpaddq_s8**
* **vmulq_n_f32**
* **vmulq_laneq_f32**
* **vfmaq_n_f32**
* **vrsqrteq_f32**
* **vrecpeq_f32**
* **vrecpsq_f32**

#### vectir manipulation(take u32 for example)

* **vcombine_u32**
* **vget_low_u32**
* **vget_high_u32**
* **vextq_u32**
* **vrev64q_u32**
* **vsetq_lane_u32**
* **vtrnq_u32**
* **vzipq_u32**

#### Bit Manipulation(take u8 for example)

* **vclzq_u8**
* **vcntq_u8**
* **vbicq_u8**(it makes some error)
* **vbslq_u8**

#### compare(take u8 for example)

*  **vceqq_u8**
* **vcgeq_u8**
* **vcleq_u8**
* **vcgtq_u8**
* **vcltq_u8**

#### logical(take u8 for example)

* **vnegq_s8**

* **vmvnq_u8**

* **vandq_u8**

* **vorrq_u8**

  
