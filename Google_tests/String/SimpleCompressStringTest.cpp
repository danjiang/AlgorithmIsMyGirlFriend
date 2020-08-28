//
// Created by Dan Jiang on 2020/8/20.
//

#include "gtest/gtest.h"

#include "simple_compress_string.h"

TEST(SimpleCompressString, AfterCase) {
  char output[100];

  char input1[] = "aabccccaaa";
  char expect1[] = "a2bc4a3";
  SimpleCompressString(input1, output);
  EXPECT_STREQ(output, expect1);

  char input2[] = "a";
  char expect2[] = "a";
  SimpleCompressString(input2, output);
  EXPECT_STREQ(output, expect2);

  char input3[] = "aa";
  char expect3[] = "a2";
  SimpleCompressString(input3, output);
  EXPECT_STREQ(output, expect3);

  char input4[] = "ab";
  char expect4[] = "ab";
  SimpleCompressString(input4, output);
  EXPECT_STREQ(output, expect4);

  char input5[] = "eeeeeaaaffeee";
  char expect5[] = "e5a3f2e3";
  SimpleCompressString(input5, output);
  EXPECT_STREQ(output, expect5);

  char input6[] = "eeeeeeeeeeeaaaffeee";
  char expect6[] = "e11a3f2e3";
  SimpleCompressString(input6, output);
  EXPECT_STREQ(output, expect6);
}

TEST(SimpleCompressString, BeforeCase) {
  std::string input1 = "aabcccccaaa";
  std::string output1 = "a2b1c5a3";
  EXPECT_EQ(ZipString(input1), output1);

  std::string input2 = "welcometonowcoderrrrr";
  std::string output2 = "welcometonowcoderrrrr";
  EXPECT_EQ(ZipString(input2), output2);

  std::string input3 = "jjjjjjxxxxxxxooZLLLLLLLLQQQQQQQQQLLLLLLLLECXXXXXXXIIIIIIIIIhjjyyySSooooooooommmuuEEEEEEEEEnnnnnnnffffffAAAAAllllllllbbbbkkkkkkkkkkkkKKKKKKhhhhhhhhhooooooooooYCCCCCCOOOOOOOOOMMMMMMMMMMiiiiiivvvvvvvWWWWkkkkkkwwwwwwwMmmmmmmmmLLLwwwwwwwkkkjjjjjjttttQQQQQQQQQaaaaaaaFFFFFFFlllllllllggggggggggPPPPPPuuuuuuuuaYYYYYYwQQQFFFFFFFFFFaaaaapXXXXXXXxxxxxxQQQQQQQQQsssssGGGGfffffffddddddpppQQQQQQHHHTTTaaaaaaGGGGGGddyyyyyMhhllllllllllNNNNNNNNUUUWWWWWWLLLLLLLLLYYYYYYYYYYTTKKKKKKKKiiiiiiitttttttXXXXXXXXXLLLHZZZZZZZssssjjJJJEEEEEOOOOOttttttttttBBttttttTTTTTTTTTTrrrrttttRRRRRyyooooooaaaaaaaaarrrrrrrPPPPPPPjjPPPPddddddddddHHHHnnnnnnnnnnSSSSSSSSSSzzHHHHHHHHHddddddDDDzzzhhhhhfffffffffftttttteeeeeeeeEEEEEEEEEaaaaaaccccccccccFFFFFFFF";
  std::string output3 = "j6x7o2Z1L8Q9L8E1C1X7I9h1j2y3S2o9m3u2E9n7f6A5l8b4k12K6h9o10Y1C6O9M10i6v7W4k6w7M1m8L3w7k3j6t4Q9a7F7l9g10P6u8a1Y6w1Q3F10a5p1X7x6Q9s5G4f7d6p3Q6H3T3a6G6d2y5M1h2l10N8U3W6L9Y10T2K8i7t7X9L3H1Z7s4j2J3E5O5t10B2t6T10r4t4R5y2o6a9r7P7j2P4d10H4n10S10z2H9d6D3z3h5f10t6e8E9a6c10F8";
  EXPECT_EQ(ZipString(input3), output3);
}