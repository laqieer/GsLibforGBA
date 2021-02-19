
const u16 sprite_Palette[16] = {
0x0000,0x4a30,0x67bf,0x3e78,0x1d4c,0x67bf,0x737a,0x0c64,
0x5693,0x31f2,0x737a,0x531b,0x7fff,0x0000,0x0000,0x0000,
};


const u8 sprite_Char[32*64/8*64/8 + 0] = {
0x00,0x00,0x00,0x00, // 0  0
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00, // 1
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x10,

0x00,0x00,0x00,0x00, // 2
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x11,
0x00,0x00,0x11,0x66,
0x00,0x10,0xaa,0xaa,
0x10,0xa1,0xaa,0xaa,
0x61,0xaa,0xaa,0xaa,
0xaa,0xaa,0xa6,0xaa,

0x00,0x00,0x00,0x00, // 3
0x10,0x11,0x11,0x11,
0x61,0xaa,0xaa,0xaa,
0xaa,0xaa,0xaa,0xaa,
0xa6,0xaa,0xa6,0xaa,
0xaa,0xaa,0xaa,0x6a,
0xaa,0xaa,0xaa,0xaa,
0xaa,0xa6,0xaa,0xaa,

0x00,0x00,0x00,0x00, // 4
0x11,0x11,0x11,0x00,
0xaa,0xaa,0x66,0x11,
0xaa,0xaa,0xaa,0xaa,
0xaa,0xa6,0xaa,0xaa,
0xaa,0xaa,0xaa,0xaa,
0xaa,0xaa,0xaa,0x6a,
0xaa,0xaa,0xa6,0xaa,

0x00,0x00,0x00,0x00, // 5
0x00,0x00,0x00,0x00,
0x01,0x00,0x00,0x00,
0x16,0x01,0x00,0x00,
0xaa,0x16,0x01,0x00,
0xaa,0xaa,0x1a,0x00,
0xaa,0xaa,0x6a,0x11,
0xaa,0x6a,0xaa,0x6a,

0x00,0x00,0x00,0x00, // 6
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x01,0x00,0x00,0x00,

0x00,0x00,0x00,0x00, // 7
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00, // 8  1
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x61, // 9
0x00,0x00,0x10,0xa6,
0x00,0x00,0x61,0xaa,
0x00,0x10,0xa6,0xaa,
0x00,0x61,0xca,0xaa,
0x00,0xa1,0xcc,0xaa,
0x10,0xc6,0xac,0x6c,
0x10,0xca,0xc6,0xac,

0xaa,0xaa,0xaa,0x6a, // 10
0xaa,0xa6,0xaa,0xaa,
0xaa,0xaa,0xaa,0xaa,
0xaa,0xaa,0xaa,0xaa,
0x6a,0xaa,0x6a,0xa6,
0xaa,0xaa,0x18,0xa1,
0xaa,0x8a,0x18,0x13,
0xaa,0x66,0xb1,0x35,

0xaa,0xaa,0xaa,0xa6, // 11
0xaa,0xaa,0xaa,0xaa,
0xaa,0xaa,0xaa,0xaa,
0xa6,0x6a,0xaa,0xaa,
0xaa,0xaa,0xaa,0x6a,
0xaa,0xaa,0xaa,0xaa,
0xa6,0xaa,0x6a,0xaa,
0xa1,0xaa,0xaa,0xaa,

0xaa,0xaa,0xaa,0xaa, // 12
0x6a,0xaa,0xaa,0xaa,
0xaa,0xaa,0xaa,0xaa,
0xaa,0x6a,0xaa,0xa6,
0xaa,0xaa,0xaa,0xaa,
0xaa,0xa8,0xaa,0xaa,
0xaa,0x11,0xa6,0xaa,
0xaa,0x16,0x11,0xaa,

0xaa,0xaa,0xaa,0xaa, // 13
0x6a,0xaa,0xaa,0xaa,
0xaa,0xaa,0xaa,0x6a,
0xaa,0xaa,0xaa,0xaa,
0xaa,0xaa,0x6a,0xaa,
0xaa,0xa6,0xaa,0xaa,
0xaa,0xaa,0xaa,0xaa,
0xaa,0xca,0xaa,0xa6,

0x1a,0x00,0x00,0x00, // 14
0x6a,0x01,0x00,0x00,
0xaa,0x16,0x00,0x00,
0xaa,0x8a,0x01,0x00,
0xaa,0xaa,0x01,0x00,
0x6a,0xaa,0x16,0x00,
0xaa,0xaa,0x16,0x00,
0xca,0xaa,0x6c,0x01,

0x00,0x00,0x00,0x00, // 15
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00, // 16  2
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x10,
0x00,0x00,0x00,0x10,
0x00,0x00,0x00,0x10,
0x00,0x00,0x00,0x10,

0x61,0xaa,0xcc,0xaa, // 17
0x61,0xaa,0xcc,0xaa,
0xa1,0xaa,0xac,0xaa,
0xa1,0xaa,0xaa,0xa6,
0xa8,0x6a,0xaa,0xaa,
0xa8,0xaa,0xaa,0xaa,
0x68,0xaa,0xaa,0xaa,
0xa8,0xaa,0x6a,0x8a,

0xaa,0x66,0x53,0x55, // 18
0x66,0x8a,0x5b,0x55,
0x6a,0x8a,0x55,0x52,
0x8a,0x16,0x55,0x55,
0x16,0x88,0x55,0x55,
0x18,0x88,0x55,0x55,
0x31,0x11,0x55,0x55,
0x51,0x13,0x52,0x25,

0x13,0xa6,0xac,0xaa, // 19
0x35,0xa1,0xca,0x6a,
0x55,0x13,0x66,0xac,
0x55,0xb5,0x61,0xcc,
0x25,0x55,0x1b,0x56,
0x55,0x55,0xb5,0x61,
0x55,0x55,0x52,0x1b,
0x55,0x55,0x55,0x55,

0xaa,0x86,0x81,0xa8, // 20
0xaa,0x8a,0x11,0x88,
0xca,0x66,0x61,0x81,
0xaa,0xac,0x18,0x12,
0xac,0xca,0x1a,0x53,
0x66,0xaa,0x8a,0x51,
0x66,0xaa,0xaa,0x31,
0x81,0x66,0xaa,0x18,

0xa6,0xaa,0xac,0xaa, // 21
0xaa,0x6a,0xca,0xaa,
0xa8,0xaa,0xca,0x6c,
0x88,0xaa,0xaa,0xcc,
0x11,0xa8,0xaa,0xca,
0x15,0x11,0xaa,0xaa,
0x55,0x13,0xa8,0xaa,
0x52,0x35,0x81,0xaa,

0xaa,0xa5,0xcc,0x01, // 22
0xaa,0xcc,0xca,0x18,
0xaa,0xca,0x6a,0x16,
0xaa,0xaa,0xaa,0x16,
0xaa,0x6a,0xaa,0x1a,
0xa6,0xaa,0xaa,0x8a,
0xaa,0xaa,0x6a,0x8a,
0xaa,0xaa,0xaa,0x8a,

0x00,0x00,0x00,0x00, // 23
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x01,0x00,0x00,0x00,
0x01,0x00,0x00,0x00,
0x01,0x00,0x00,0x00,

0x00,0x00,0x00,0x10, // 24  3
0x00,0x00,0x00,0x10,
0x00,0x00,0x00,0x10,
0x00,0x00,0x00,0x10,
0x00,0x00,0x00,0x10,
0x00,0x00,0x00,0x10,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,

0xa8,0xaa,0xaa,0x1a, // 25
0xa8,0x6a,0xaa,0x16,
0x61,0xaa,0xaa,0x18,
0x68,0xaa,0xaa,0x68,
0x88,0xaa,0xa6,0x51,
0x88,0xa6,0xaa,0x51,
0x11,0x68,0xaa,0x51,
0x81,0x88,0x68,0x21,

0xb2,0x93,0x99,0xb3, // 26
0x9b,0x44,0x44,0x94,
0xb3,0x5b,0x56,0xb5,
0x52,0x55,0x55,0x52,
0x55,0x35,0x74,0x47,
0x55,0x09,0x47,0x74,
0x95,0x97,0xbb,0x35,
0x03,0x39,0x49,0xc2,

0x55,0x55,0x55,0x55, // 27
0x23,0x55,0x25,0x55,
0x5b,0x55,0x55,0x55,
0x55,0x55,0x55,0x55,
0x53,0x55,0x55,0x55,
0x30,0x25,0x55,0x55,
0x49,0x55,0x55,0x25,
0x33,0x55,0x25,0x55,

0x15,0x68,0x66,0x16, // 28
0x52,0x81,0x68,0x93,
0x55,0x15,0x88,0x18,
0x55,0x55,0x81,0x88,
0x55,0x52,0x15,0x31,
0x55,0x55,0x55,0x73,
0x55,0x55,0x55,0x94,
0x55,0x55,0x25,0x93,

0x99,0x39,0x13,0xa6, // 29
0x44,0x44,0x94,0x69,
0x53,0x52,0xb5,0x19,
0x51,0x55,0x55,0x15,
0x74,0x47,0x53,0x25,
0x47,0x74,0x90,0x55,
0x23,0xbb,0x79,0x59,
0x54,0x3c,0x93,0x30,

0xaa,0xaa,0xaa,0x1a, // 30
0xa6,0xaa,0xaa,0x86,
0xaa,0x6a,0xaa,0x88,
0xa8,0xaa,0x6a,0x81,
0x61,0xaa,0x8a,0x88,
0x13,0xa6,0x86,0x18,
0x1b,0x66,0x18,0x18,
0x1b,0x88,0x88,0x18,

0x01,0x00,0x00,0x00, // 31
0x01,0x00,0x00,0x00,
0x01,0x00,0x00,0x00,
0x01,0x00,0x00,0x00,
0x01,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00, // 32  4
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,

0x81,0x88,0x18,0xb1, // 33
0x81,0x81,0x88,0xb1,
0x10,0x88,0x88,0x31,
0x10,0x88,0x81,0x18,
0x00,0x81,0x88,0x18,
0x00,0x10,0x18,0x88,
0x00,0x10,0x88,0x88,
0x00,0x00,0x11,0x18,

0x49,0x9b,0x44,0x5b, // 34
0x94,0x7c,0x74,0x77,
0x94,0x0c,0x74,0x07,
0x49,0x4c,0x49,0x44,
0xbb,0x35,0x94,0x99,
0x51,0xc5,0x93,0x94,
0xb1,0x55,0x55,0x52,
0x18,0x55,0x55,0x55,

0x44,0x5b,0x55,0x55, // 35
0x74,0x2b,0x55,0x55,
0x74,0x5b,0x55,0x55,
0x49,0x5b,0x55,0x55,
0x34,0x52,0x25,0x55,
0x53,0x55,0x55,0x55,
0x55,0x55,0x55,0x55,
0x55,0x55,0x55,0x2b,

0x55,0x52,0xb5,0x44, // 36
0x55,0x55,0xb5,0x47,
0x55,0x55,0xb2,0x47,
0x52,0x55,0xb5,0x94,
0x55,0x55,0x55,0x43,
0x55,0x55,0x55,0x35,
0x55,0x55,0x52,0x55,
0x55,0x55,0x55,0x55,

0xb4,0x45,0xb9,0x94, // 37
0x77,0x47,0xc0,0x49,
0x70,0x40,0xc7,0x49,
0x44,0x94,0x54,0x94,
0x99,0x49,0xc3,0x5b,
0x49,0x39,0x5c,0xb5,
0x52,0x55,0x55,0x15,
0x55,0x55,0x25,0x1b,

0x1b,0x88,0x88,0x01, // 38
0x1b,0x81,0x88,0x01,
0x1b,0x88,0x81,0x01,
0x81,0x88,0x18,0x00,
0x81,0x88,0x18,0x00,
0x81,0x81,0x01,0x00,
0x88,0x88,0x01,0x00,
0x81,0x18,0x00,0x00,

0x00,0x00,0x00,0x00, // 39
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00, // 40  5
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,

0x00,0x00,0x10,0x88, // 41
0x00,0x00,0x00,0x11,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,

0x18,0x53,0x52,0x55, // 42
0x18,0x31,0x55,0x55,
0x11,0x11,0x53,0x55,
0x34,0x1b,0x21,0x55,
0x34,0x5b,0x55,0x55,
0x40,0x26,0x55,0x55,
0x40,0x59,0x55,0x55,
0x00,0x34,0x25,0x55,

0x25,0x55,0xb2,0x9b, // 43
0x55,0x55,0xb5,0x93,
0x55,0x55,0x55,0x33,
0x55,0x55,0x55,0x55,
0x52,0x25,0x55,0x52,
0x55,0x55,0x3b,0x5b,
0x55,0x55,0x55,0x55,
0x55,0x55,0x55,0x52,

0x25,0x55,0x55,0x55, // 44
0x55,0x55,0x25,0x55,
0x55,0x55,0x55,0x55,
0x55,0x25,0x55,0x55,
0x25,0xbb,0x55,0x55,
0x3b,0xb9,0x55,0x55,
0x55,0x55,0x55,0x52,
0x55,0x55,0x55,0x55,

0x55,0x52,0x55,0x81, // 45
0x55,0x55,0xb5,0x81,
0x55,0x55,0x15,0x81,
0x55,0x25,0x18,0x11,
0x52,0x55,0xbb,0x43,
0x55,0x55,0x55,0x04,
0x55,0x25,0x35,0x04,
0x55,0x55,0x4b,0x00,

0x88,0x01,0x00,0x00, // 46
0x18,0x00,0x00,0x00,
0x01,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00, // 47
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00, // 48  6
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00, // 49
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,

0x00,0x40,0x53,0x55, // 50
0x00,0x00,0x94,0x5b,
0x00,0x00,0x40,0x34,
0x00,0x00,0x00,0x40,
0x00,0x00,0x00,0x00,
0x00,0x44,0x44,0x44,
0x44,0x94,0x99,0x99,
0x40,0x43,0x44,0x99,

0x52,0x25,0x55,0x55, // 51
0x55,0x55,0x55,0x55,
0x55,0x55,0x55,0x55,
0x94,0x55,0x52,0x55,
0x44,0x34,0x2b,0xa5,
0x44,0x44,0x94,0xb3,
0x49,0x44,0x44,0x44,
0x49,0x93,0x44,0x44,

0x55,0x55,0x52,0x55, // 52
0x55,0x55,0x55,0x55,
0x25,0x55,0x55,0x25,
0x55,0x55,0x55,0x35,
0x55,0x25,0x9b,0x44,
0xb2,0x93,0x44,0x44,
0x44,0x44,0x44,0x49,
0x44,0x44,0x94,0x43,

0x25,0xb5,0x04,0x00, // 53
0x55,0x43,0x00,0x00,
0x9b,0x04,0x00,0x00,
0x44,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x44,0x44,0x04,0x00,
0x99,0x99,0x44,0x44,
0x99,0x44,0x94,0x49,

0x00,0x00,0x00,0x00, // 54
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00, // 55
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00, // 56  7
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00, // 57
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,

0x40,0xb2,0x93,0x44, // 58
0x40,0xb3,0x22,0x3b,
0x40,0x23,0x22,0x22,
0x40,0x29,0x2b,0x2b,
0x40,0x29,0x22,0x22,
0x00,0xb4,0x22,0x2b,
0x40,0x24,0x22,0x22,
0x94,0x23,0x22,0x22,

0x94,0xb5,0x43,0x44, // 59
0x49,0x44,0x44,0x44,
0x22,0xbb,0x33,0x99,
0x2b,0x2b,0x2b,0x2b,
0x22,0x22,0x22,0x22,
0xb2,0x22,0x2b,0xb2,
0x22,0x22,0x22,0x22,
0x22,0x22,0x22,0x22,

0x44,0x44,0xb3,0x9b, // 60
0x44,0x44,0x44,0x94,
0x99,0x39,0xb3,0x2b,
0x2b,0x2b,0x2b,0x2b,
0x22,0x22,0x22,0x22,
0x22,0x2b,0xb2,0x22,
0x22,0x22,0x22,0x22,
0x22,0x22,0x22,0x22,

0x44,0x39,0xbb,0x42, // 61
0x39,0xbb,0x22,0x42,
0x22,0x22,0xb2,0x43,
0xb2,0x22,0x22,0x43,
0x22,0x22,0xb2,0x49,
0x2b,0xb2,0x22,0x04,
0x22,0x22,0x32,0x04,
0x22,0x22,0x92,0x49,

0x00,0x00,0x00,0x00, // 62
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x04,0x00,0x00,0x00,

0x00,0x00,0x00,0x00, // 63
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,

};