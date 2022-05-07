#include "small_utility/string/string.h"

#include <cstdio>
#include <vector>

using namespace small_utility;

int main() {
  std::vector<int> error_codes;
  string_stuff::String s1("test");
  string_stuff::String s2(s1);
  s2 = s2;
  if (s1 != s2) { error_codes.push_back(1); }
  if (s2 != s2) { error_codes.push_back(2); }
  s1 += s2;
  s1 += s2[0];
  if (s1 != "testtestt") { error_codes.push_back(3); }
  if (s1.Size() != 9) { error_codes.push_back(4); }
  string_stuff::String temp(s1);
  s1.Swap(s2);
  if (s2 != temp) { error_codes.push_back(5); }
  s1.Swap(s2);
  if (s1 != temp) { error_codes.push_back(6); }
  s1.Reserve(20);
  if (s1.Capacity() != 20) { error_codes.push_back(7); }
  s1.Resize(1, 'i');
  if (s1 != string_stuff::String("t")) { error_codes.push_back(8); }
  s1.Insert('o', 1);
  if (s1 != string_stuff::String("to")) { error_codes.push_back(9); }
  s1.Insert("pq", 2);
  if (s1 != "topq") { error_codes.push_back(10); }
  s1.Erase(1, 2);
  if (s1 != "tq") { error_codes.push_back(11); }
  s1.Clear();
  if (s1.Find('i') != -1) { error_codes.push_back(12); }
  s1 = "0123";
  temp = s1.SubStringLength(0, 4);
  if (s1 != temp) { error_codes.push_back(13); }
  string_stuff::String clear_s("123");
  clear_s.Clear();
  if (clear_s != "") { error_codes.push_back(14); }

  string_stuff::String s_replace("123456789");
  s_replace.Replace("456", "123");
  s_replace.Replace("123", "456");
  s_replace.Replace("789", "444");
  s_replace.Replace("123", "333");
  if (s_replace != "456333444") { error_codes.push_back(15); }

  string_stuff::String s_plus1("plus1"), s_plus2("plus2"),
                       s_plus3(s_plus1 + s_plus2);
  if ((s_plus1 += s_plus2) != s_plus3) { error_codes.push_back(16); }
  

  error_codes.push_back(0);
  for (auto const i : error_codes) {
    return i;
  }
}
